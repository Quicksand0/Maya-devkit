#ifndef _MFnKeyframeDeltaTangent
#define _MFnKeyframeDeltaTangent
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
//
// ****************************************************************************
//
// CLASS:    MFnKeyframeDeltaTangent
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnKeyframeDelta.h>
#include <maya/MFnAnimCurve.h>

// ****************************************************************************
// DECLARATIONS

class MTime;

// ****************************************************************************
// CLASS DECLARATION (MFnKeyframeDeltaTangent)

//! \ingroup OpenMayaAnim MFn
//! \brief Function set for changes to a key's tangent. 
/*!
A MFnKeyframeDeltaTangent function allows API programmers to read
changes in keyframe tangent values. It captures changes in tangent
type, as well as, changes in tangent time/value pair.

MFnKeyframeDeltaTangents are generated by a
MAnimMessage::addAnimKeyframeEditedCallback. Because a key's tangent
may be unbroken. It is possible to receive to MFnKeyframeDeltaTangent
values per key -- one for the incoming tangent and one for the
outgoing tangent. The API programmer should use the isInTangent method
to determine if the tangent change affects the in-bound tangent or
out-bound tangent.
*/
class OPENMAYAANIM_EXPORT MFnKeyframeDeltaTangent : public MFnKeyframeDelta
{
	declareMFn(MFnKeyframeDeltaTangent, MFnKeyframeDelta);

public:

	MFnAnimCurve::TangentType	previousTangentType( MStatus *ReturnStatus = NULL ) const;
	MFnAnimCurve::TangentType	currentTangentType( MStatus *ReturnStatus = NULL ) const;

	MStatus		getPreviousPosition( float &x, float &y ) const;
	MStatus		getCurrentPosition( float &x, float &y ) const;
	bool		isInTangent( MStatus *ReturnStatus = NULL  ) const;

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnKeyframeDeltaTangent, MFnKeyframeDelta );

END_NO_SCRIPT_SUPPORT:

protected:
	// No protected.

private:
	// No private.
};

#endif /* __cplusplus */
#endif /* _MFnKeyframeDeltaTangent */
