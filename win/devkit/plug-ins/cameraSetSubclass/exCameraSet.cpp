//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc. and/or its licensors.  All 
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors, which is protected by U.S. and Canadian federal copyright 
// law and by international treaties.
//
// The Data is provided for use exclusively by You. You have the right 
// to use, modify, and incorporate this Data into other products for 
// purposes authorized by the Autodesk software license agreement, 
// without fee.
//
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the 
// following disclaimer, must be included in all copies of the 
// Software, in whole or in part, and all derivative works of 
// the Software, unless such copies or derivative works are solely 
// in the form of machine-executable object code generated by a 
// source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR 
// PURPOSE, OR ARISING FROM A COURSE OF DEALING, USAGE, OR 
// TRADE PRACTICE. IN NO EVENT WILL AUTODESK AND/OR ITS LICENSORS 
// BE LIABLE FOR ANY LOST REVENUES, DATA, OR PROFITS, OR SPECIAL, 
// DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK 
// AND/OR ITS LICENSORS HAS BEEN ADVISED OF THE POSSIBILITY 
// OR PROBABILITY OF SUCH DAMAGES.
//
// ==========================================================================
//+

#include <string.h>
#include <maya/MIOStream.h>
#include <math.h>

#include <maya/MPxCameraSet.h>
#include <maya/MFnCompoundAttribute.h>
#include <maya/MFnEnumAttribute.h>
#include <maya/MFnPlugin.h>
#include <maya/MString.h> 
#include <maya/MTypeId.h> 
#include <maya/MPlug.h>
#include "exCameraSet.h"
#include "testExCameraSetCmd.h"

MTypeId     exCameraSet::id( 0x80024  );
MObject     exCameraSet::layerTypeAttr;        

exCameraSet::exCameraSet() {}
exCameraSet::~exCameraSet() {}

void* exCameraSet::creator()
{
	return new exCameraSet();
}

MStatus exCameraSet::initialize()
{
	MFnEnumAttribute   enumAttr;
	MStatus status;

	// Create the layerType attribute and define its enum values.
	layerTypeAttr = enumAttr.create( "layerType", "lt", 0, &status );

	if( !status ) {
		status.perror("ERROR creating layerType enum attribute");
		return status;
	}

	enumAttr.addField("Mono",  0);
	enumAttr.addField("Left",  1);
	enumAttr.addField("Right", 2);

	// Make this attribute a multi so it can store a value per camera layer.
	enumAttr.setArray(true);

	return MS::kSuccess;
}

MStatus exCameraSet::setLayerType( unsigned int index, int layerType )
{
	MStatus status;

	// Get the layerType plug for the given index.
	MPlug layerTypePlug;
	status = getLayerTypePlug(index, layerTypePlug);
	if (status != MS::kSuccess)
		return status;

	// Set the value of the plug to the new value.
	return layerTypePlug.setValue(layerType);
}

MStatus exCameraSet::getLayerType( unsigned int index, int & layerType ) const
{
	MStatus status;

	// Get the layerType plug for the given index.
	MPlug layerTypePlug;
	status = getLayerTypePlug(index, layerTypePlug);
	if (status != MS::kSuccess)
		return status;

	// Get the value of the plug to the new value.
	return layerTypePlug.getValue(layerType);
}

MStatus exCameraSet::getLayerTypePlug(unsigned int index, MPlug &layerTypePlug) const
{
	MStatus status = MS::kSuccess;

	MPlug enumPlug(thisMObject(), layerTypeAttr);
	layerTypePlug = enumPlug.elementByLogicalIndex(index, &status);

	return status;
}

MStatus initializePlugin( MObject obj )
{
	MStatus   status;
	MFnPlugin plugin( obj, PLUGIN_COMPANY, "7.0", "Any");

	status = plugin.registerNode( "exCameraSet", exCameraSet::id, exCameraSet::creator,
											   exCameraSet::initialize, MPxNode::kCameraSetNode);
	if (!status) {
		status.perror("registerNode");
		return status;
	}

	status =  plugin.registerCommand( kCmdName, testExCameraSetCmd::creator);
	if (!status) {
		status.perror("registerCommand");
		return status;
	}

	return status;
}

MStatus uninitializePlugin( MObject obj)
{
	MStatus   status;
	MFnPlugin plugin( obj );

	status = plugin.deregisterNode( exCameraSet::id );
	if (!status) {
		status.perror("deregisterNode");
		return status;
	}

	status = plugin.deregisterCommand( kCmdName );
	if (!status) {
		status.perror("deregisterCommand");
		return status;
	}

	return status;
}
