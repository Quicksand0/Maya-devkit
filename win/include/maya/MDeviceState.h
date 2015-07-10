#ifndef _MDeviceState
#define _MDeviceState
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
// CLASS:    MDeviceState
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MTypes.h>

// ****************************************************************************
// DECLARATIONS

class MString;
class THeventInputDevice;

// ****************************************************************************
// CLASS DECLARATION (MDeviceState)

//! \ingroup OpenMayaUI
//! \brief Input device state 
/*!
MDeviceState is a generic event class for input devices.
Input device classes (such as MPxMidiInputDevice) are responsible for
converting specific event types to an MDeviceState which Maya understands.
*/
class OPENMAYAUI_EXPORT MDeviceState
{
public:
	virtual ~MDeviceState();

	int		devicePosition( const unsigned short int axis) const;
	int		devicePosition( const MString & axisName ) const;
	void	setDevicePosition( const int position,
							   const unsigned short int axis);
	void	setDevicePosition( const int position,
							   const MString & axisName );

	bool	buttonState( const unsigned short int button ) const;
	bool	buttonState( const MString & buttonName ) const;
	void	setButtonState( const bool state,
							const unsigned short int button );
	void	setButtonState( const bool state,
							const MString & buttonName );

	int		maxAxis() const;

	bool	isNull();

protected:
// No protected members

private:
	MDeviceState( void * );
	void *   data();
	void * api_stateData;
};

#endif /* __cplusplus */
#endif /* _MDeviceState */
