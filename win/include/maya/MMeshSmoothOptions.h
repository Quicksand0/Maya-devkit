#ifndef _MMeshSmoothOptions
#define _MMeshSmoothOptions
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All
// rights reserved.
//
// The coded instructions, statements, computer programs, and/or related
// material (collectively the "Data") in these files contain unpublished
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its
// licensors,  which is protected by U.S. and Canadian federal copyright law
// and by international treaties.
//
// The Data may not be disclosed or distributed to third parties or be
// copied or duplicated, in whole or in part, without the prior written
// consent of Autodesk.
//
// The copyright notices in the Software and this entire statement,
// including the above license grant, this restriction and the following
// disclaimer, must be included in all copies of the Software, in whole
// or in part, and all derivative works of the Software, unless such copies
// or derivative works are solely in the form of machine-executable object
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE,
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES.
// ==========================================================================
//+
//
// CLASS:    MMeshSmoothOptions
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MStatus.h>

// ****************************************************************************
// CLASS DECLARATION (MMeshSmoothOptions)

//! \ingroup OpenMaya
//! \brief Options for control of smooth mesh generation. 
/*!
	The MMeshSmoothOptions class  encapsulates settings that control the
	generation of smoothed version of a mesh. Meant for use with
	MFnMesh::generateSmoothMesh().
*/
class OPENMAYA_EXPORT MMeshSmoothOptions
{
public:
	MMeshSmoothOptions(void);
	virtual ~MMeshSmoothOptions(void);

	//! Specifies subdivision algorithm to use for mesh smoothing. 
    enum SubdivisionType {
		kInvalidSubdivision = -1,			//!< Invalid value.
        kCatmullClark = 0,					//!< Maya Catmull-Clark.
        kOpenSubdivCatmullClarkUniform = 2,	//!< OpenSubdiv Uniform.
        kOpenSubdivCatmullClarkAdaptive,	//!< OpenSubdiv Adaptive.
		kLastSubdivision,					//!< Last enum value.
    };

	//! Specifies how to apply boundary creasing to subd poly object. 
	enum BoundaryRule { 
		kInvalid = -1, //!< Invalid value. 
		kLegacy = 0,   //!< Uses the legacy algorithm, which performed no creasing
		kCreaseAll,  //!< Crease boundary edges & vertices with valence of exactly 2. 
		kCreaseEdge, //!< Crease boundary edges only. 
		kLast		 //!< Last enum value. 
	}; 

	//! OpenSubdiv vertex boundary rules.
	enum OpenSubdivVertexBoundary {
		kInvalidBoundary = -1, //!< Invalid value.
		kNone = 0, //!< None
		kSharpEdgesAndCorners, //!< Don't smooth edges & corners.
		kSharpEdges, //!< Don't smooth edges.
		kAlwaysSharp, //!< Use legacy boundary rules.
		kLastBoundary  //!< Last enum value.
	};

	//! OpenSubdiv crease method.
	enum OpenSubdivCreaseMethod {
		kInvalidCreaseMethod = -1, //!< Invalid value.
		kNormal = 0, //!< Normal crease method.
		kChaikin, //!< Chaikin crease method.
		kLastCreaseMethod, //!< Last enum value.
	};

	void	setDivisions( int numDivisions, MStatus* ReturnStatus=NULL );
	int		divisions( MStatus* ReturnStatus=NULL ) const;
	void	setSmoothness( float smoothness, MStatus* ReturnStatus=NULL );
	float	smoothness( MStatus* ReturnStatus=NULL ) const;
	void	setSmoothUVs( bool smoothUVs, MStatus* ReturnStatus=NULL );
	bool	smoothUVs( MStatus* ReturnStatus=NULL ) const;
	void	setPropEdgeHardness( bool propEdgeHardness, MStatus* ReturnStatus=NULL );
	bool	propEdgeHardness( MStatus* ReturnStatus=NULL ) const;
	void	setKeepBorderEdge( bool keepBorderEdge, MStatus* ReturnStatus=NULL );
	bool	keepBorderEdge( MStatus* ReturnStatus=NULL ) const;
	void	setKeepHardEdge( bool keepHardEdge, MStatus* ReturnStatus=NULL );
	bool	keepHardEdge( MStatus* ReturnStatus=NULL ) const;
	void    setBoundaryRule( BoundaryRule rule, MStatus * ReturnStatus = NULL ); 
	BoundaryRule boundaryRule( MStatus* ReturnStatus = NULL ) const; 
	void	setOpenSubdivVertexBoundary( OpenSubdivVertexBoundary rule, MStatus* ReturnStatus = NULL );
	OpenSubdivVertexBoundary openSubdivVertexBoundary( MStatus* ReturnStatus = NULL ) const;
	void	setOpenSubdivFaceVaryingBoundary(OpenSubdivVertexBoundary smoothing, MStatus* ReturnStatus = NULL );
	OpenSubdivVertexBoundary openSubdivFaceVaryingBoundary( MStatus* ReturnStatus = NULL ) const;
	void	setOpenSubdivSmoothTriangles( bool smoothTriangles, MStatus* ReturnStatus = NULL );
	bool	openSubdivSmoothTriangles( MStatus* ReturnStatus = NULL );
	void	setOpenSubdivCreaseMethod(OpenSubdivCreaseMethod method, MStatus* ReturnStatus = NULL );
	OpenSubdivCreaseMethod openSubdivCreaseMethod( MStatus* ReturnStatus = NULL ) const;
	void    setSubdivisionType( SubdivisionType subdivision, MStatus * ReturnStatus = NULL ); 
	SubdivisionType subdivisionType( MStatus* ReturnStatus = NULL ) const; 

	static const char* className();

protected:
// No protected members
private:
	friend class MFnMesh;
	void *instance;
};

#endif /* __cplusplus */
#endif /* _MMeshIntersector */
