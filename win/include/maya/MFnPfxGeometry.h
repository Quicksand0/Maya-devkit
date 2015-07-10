#ifndef _MFnPfxGeometry
#define _MFnPfxGeometry
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
// CLASS:    MFnPfxGeometry
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES

#include <maya/MFnDagNode.h>

// ****************************************************************************
// DECLARATIONS

class MPointArray;
class MVectorArray;
class MDoubleArray;
class MRenderLineArray;

// ****************************************************************************
// CLASS DECLARATION (MFnPfxGeometry)

//! \ingroup OpenMayaFX MFn
//! \brief PfxGeometry node function set
/*!
  This is the function set for paint effects objects.

  PfxGeometry is the parent class for the stroke and pfxHair node.
  The output geometry for pfxHair and stroke nodes may be accessed
  through this class.
*/
class OPENMAYAFX_EXPORT MFnPfxGeometry : public MFnDagNode
{
	declareDagMFn(MFnPfxGeometry, MFnDagNode);

	MStatus getLineData(
			MRenderLineArray &mainLines,
			MRenderLineArray &leafLines,
			MRenderLineArray &flowerLines,
			bool doLines, bool doTwist,
			bool doWidth, bool doFlatness,
			bool doParameter, bool doColor,
			bool doIncandescence, bool doTransparency,
			bool worldSpace );

	MStatus getBoundingBox( double* min, double* max );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareDagMFnConstConstructor( MFnPfxGeometry, MFnDagNode );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

#endif /* __cplusplus */
#endif /* _MFnPfxGeometry */
