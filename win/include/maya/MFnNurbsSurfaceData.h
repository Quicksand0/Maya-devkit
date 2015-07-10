#ifndef _MFnNurbsSurfaceData
#define _MFnNurbsSurfaceData
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
// CLASS:    MFnNurbsSurfaceData
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnGeometryData.h>

// ****************************************************************************
// CLASS DECLARATION (MFnNurbsSurfaceData)

//! \ingroup OpenMaya MFn
//! \brief Nurbs Surface function set for dependency node data.
/*!

  MFnNurbsSurfaceData allows the creation and manipulation of
  NurbsSurface data objects for use in the dependency graph.

  If a user written dependency node either accepts or produces Nurbs
  Surfaces, then this class is used to extract or create the data that
  comes from or goes to other dependency graph nodes. The
  MDataHandle::type method will return kNurbsSurface when data of this
  type is present.

  If a node is receiving a Nurbs Surface via an input attribute, the
  asNurbsSurface method of MDataHandle can be used to access that
  input Nurbs Surface.

  If a node is to create a Nurbs Surface and send it via an output
  attribute, a new MFnNurbsSurfaceData must be instantiated and then
  the create method called to build the actual data block as an
  MObject.  This MObject should be passed to the
  MFnNurbsSurface::create method as the parentOrOwner parameter so
  that the Nurbs Surface will be constructed inside the data block.
  The MDataHandle::set routine is then used to pass the data block
  down the connection.
*/
class OPENMAYA_EXPORT MFnNurbsSurfaceData : public MFnGeometryData
{
	declareMFn(MFnNurbsSurfaceData, MFnGeometryData);

public:
	MObject		create( MStatus* ReturnStatus = NULL );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnNurbsSurfaceData, MFnGeometryData );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

#endif /* __cplusplus */
#endif /* _MFnNurbsSurfaceData */
