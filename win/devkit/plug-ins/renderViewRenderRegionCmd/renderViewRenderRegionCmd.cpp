//-
// ==========================================================================
// Copyright 1995,2006,2008 Autodesk, Inc. All rights reserved.
//
// Use of this software is subject to the terms of the Autodesk
// license agreement provided at the time of installation or download,
// or which otherwise accompanies this software in either electronic
// or hard copy form.
// ==========================================================================
//+

#include <maya/MSimple.h>
#include <maya/MIOStream.h>
#include <maya/MRenderView.h>
#include <maya/M3dView.h>
#include <math.h>
#include <maya/MSyntax.h>
#include <maya/MArgDatabase.h>

//
//	renderViewRenderRegion command declaration
//
class renderViewRenderRegion : public MPxCommand 
{							
public:					
	renderViewRenderRegion() {};
	~renderViewRenderRegion() {};

	virtual MStatus	doIt ( const MArgList& );
	
	static void*	creator();
	
	static MSyntax	newSyntax();
	MStatus parseSyntax (MArgDatabase &argData);

	static const char * cmdName;

private:
	bool doNotClearBackground;				

};													

static const char * kDoNotClearBackground		= "-b";
static const char * kDoNotClearBackgroundLong	= "-background";

const char * renderViewRenderRegion::cmdName = "renderViewRenderRegion";

void* renderViewRenderRegion::creator()					
{													
	return new renderViewRenderRegion;					
}													

MSyntax renderViewRenderRegion::newSyntax()
{
	MStatus status;
	MSyntax syntax;
	syntax.addFlag( kDoNotClearBackground, kDoNotClearBackgroundLong );
	CHECK_MSTATUS_AND_RETURN(status, syntax);
	return syntax;
}

//
// Description:
//		Read the values of the additionnal flags for this command.
//
MStatus renderViewRenderRegion::parseSyntax (MArgDatabase &argData)
{
	// Get the flag values, otherwise the default values are used.
	doNotClearBackground = argData.isFlagSet( kDoNotClearBackground );
	
	return MS::kSuccess;
}

//
// Description:
//		register the command
//
MStatus initializePlugin( MObject obj )			
{															
	MFnPlugin	plugin( obj, PLUGIN_COMPANY, "4.5" );	
	MStatus		stat;										
	stat = plugin.registerCommand(	renderViewRenderRegion::cmdName,
									renderViewRenderRegion::creator,
									renderViewRenderRegion::newSyntax);	
	if ( !stat )												
		stat.perror( "registerCommand" );							
	return stat;												
}																

//
// Description:
//		unregister the command
//
MStatus uninitializePlugin( MObject obj )						
{																
	MFnPlugin	plugin( obj );									
	MStatus		stat;											
	stat = plugin.deregisterCommand( renderViewRenderRegion::cmdName );				
	if ( !stat )									
		stat.perror( "deregisterCommand" );			
	return stat;									
}

RV_PIXEL evaluate(int x, int y)
//
//	Description:
//		Generates a simple procedural circular pattern to be sent to the 
//		Render View.
//
//	Arguments:
//		x, y - coordinates in the current tile (the pattern is centred 
//			   around (0,0) ).
//
//	Return Value:
//		An RV_PIXEL structure containing the colour of pixel (x,y).
//
{
	unsigned int distance = (unsigned int) sqrt(double((x*x) + (y*y)));

	RV_PIXEL pixel;
	// Always fully blue.
	pixel.b = 255.0f;		
	// Green and red varies according to the distance.
	pixel.g = pixel.r = 155.0f + (distance % 20) * 5;
	pixel.a = 255.0f;

	return pixel;
}

MStatus renderViewRenderRegion::doIt( const MArgList& args )
//
//	Description:
//		Implements the MEL renderViewRenderRegion command.  This command
//		fills the currently selected Render Region with a circular blue 
//		and white pattern.  It assumes that the Render View is currently
//		displaying a 640x480 image (if it isn't, then this command will
//		resize the Render View to 640x480).
//
//	Arguments:
//		args - the argument list that was passes to the command from MEL.
//				-background/-b renders the pattern without clearing the region
//
//	Return Value:
//		MS::kSuccess - command succeeded
//		MS::kFailure - command failed (returning this value will cause the 
//                     MEL script that is being run to terminate unless the
//                     error is caught using a "catch" statement.
//
{
	MStatus stat = MS::kSuccess;

	unsigned int resX = 640;
	unsigned int resY = 480;

	// Check if the render view exists. It should always exist, unless
	// Maya is running in batch mode.
	//
	if (!MRenderView::doesRenderEditorExist())
	{
		setResult( "Cannot renderViewRenderRegion in batch render mode. "
				   "Please run in interactive mode, "
				   "so that the render editor exists." );
		return MS::kFailure;
	}

	// get optional flags
	MArgDatabase	argData( syntax(), args );
	parseSyntax( argData );

	// Pick a camera, and tell the Render View that we will be rendering
	// from its point of view.  Just use the camera for the active 
	// modelling view.
	//
	M3dView curView = M3dView::active3dView();
	MDagPath camDagPath;
	curView.getCamera( camDagPath );
	cout<<"Region rendering camera"<<camDagPath.fullPathName().asChar()<<endl;

	if( MRenderView::setCurrentCamera( camDagPath ) != MS::kSuccess )
	{
		setResult( "renderViewRenderRegion: error occurred in setCurrentCamera." );
		return MS::kFailure;
	}

	// Retrieve the dimensions of the currently selected Render Region.
	//
	unsigned int regionLeft, regionRight, regionBottom, regionTop;
	stat = MRenderView::getRenderRegion( regionLeft, regionRight, 
										 regionBottom, regionTop );
	if( stat != MS::kSuccess )
	{
		setResult( "renderViewRenderRegion: error occurred in getRenderRegion." );
		return MS::kFailure;
	}


	// Assume that the full rendered image is 640x480, and tell the 
	// Render View that we're about to start rendering the given region.
	//
	stat = MRenderView::startRegionRender( resX, resY, 
										   regionLeft, regionRight, 
										   regionBottom, regionTop,
										   doNotClearBackground );
	if( stat == MS::kSuccess )
	{
		cout<<"Rendering Region ("<<regionLeft<<","<<regionBottom
			<<") -> ("<<regionRight<<","<<regionTop<<")"<<endl;

		unsigned int width = regionRight - regionLeft + 1;
		unsigned int height = regionTop - regionBottom + 1;
		unsigned int numPixels = width * height;
		unsigned int middleX = width / 2;
		unsigned int middleY = height / 2;

		// Allocate buffer to store the region
		//
		RV_PIXEL* pixels = new RV_PIXEL[numPixels];

		// Fill the region buffer with a circular blue/white pattern centred on 
		// the middle of the region
		//
		for( unsigned int x = 0; x < width; x++ )
		{
			for( unsigned int y = 0; y < height; y++ )
			{
				int index = y*width + x;
				int xCoord = x - middleX;
				int yCoord = y - middleY;

				pixels[index] = evaluate( xCoord, yCoord );
			}
		}
	
		// Send the pixel data to the Render View.
		//
		stat = MRenderView::updatePixels( regionLeft, regionRight, 
										  regionBottom, regionTop, 
										  pixels );

		if( stat != MS::kSuccess )
		{
			setResult( "renderViewRenderRegion: error occurred in updatePixels." );
			return MS::kFailure;
		}

		// Force a refresh of the region in the Render View window.
		//
		stat = MRenderView::refresh( regionLeft, regionRight, 
									 regionBottom, regionTop );
		if( stat != MS::kSuccess )
		{
			setResult( "renderViewRenderRegion: error occurred in refresh." );
			return MS::kFailure;
		}
	}
	else
	{
		setResult( "renderViewRenderRegion: error occurred in startRegionRender." );
		return MS::kFailure;
	}

	// Notify the Render View that we are done rendering the region.
	//
	stat = MRenderView::endRender();
	if( stat != MS::kSuccess )
	{
		setResult( "renderViewRenderRegion: error occurred in endRender." );
		return MS::kFailure;
	}

	setResult( "renderViewRenderRegion completed." );
	return stat;
}




