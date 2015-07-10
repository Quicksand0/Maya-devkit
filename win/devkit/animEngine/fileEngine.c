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

#include <fileEngine.h>

/*
//	Function Name:
//		engineFileOpen
//
//	Description:
//		A helper function to open a file
//
//  Input Arguments:
//		EtFileName fileName			The name of the file to open
//
//  Return Value:
//      EtFileHandle fd				A handle for the opened file
//			kFileBadParam				fileName is NULL
//			kFileNotOpened				the file could not be opened
*/
EtFileHandle
engineFileOpen (EtFileName fileName)
{
	int fd;

	/* make sure we have a valid file name */
	if (fileName == kEngineNULL) {
		return (kFileBadParam);
	}

	/* open the file */
	fd = open (fileName, O_RDWR);
	return (fd);
}

/*
//	Function Name:
//		engineFileClose
//
//	Description:
//		A helper function to close a file
//
//  Input Arguments:
//		EtFileHandle fileHandle		The handle of an open file to close
//
//  Return Value:
//      None
*/
EtVoid
engineFileClose (EtFileHandle fileHandle)
{
	/* make sure we have a valid file handle */
	if (fileHandle < 0) {
		return;
	}

	close (fileHandle);
}

/*
//	Function Name:
//		engineFileReadByte
//
//	Description:
//		A helper function to read a byte from a file
//
//  Input Arguments:
//		EtFileHandle fileHandle		The handle to an open file
//		EtByte *byte				A pointer to where the byte should be read
//
//  Return Value:
//		EtBoolean status
//			kEngineTRUE				one byte could be read
//			kEngineFALSE			could not read a byte (most likely because
//										we are at the end of the file)
*/
EtBoolean
engineFileReadByte (EtFileHandle fileHandle, EtByte *byte)
{
	/* make sure we have a valid file handle */
	if ((fileHandle < 0) || (byte == kEngineNULL)) {
		return (kEngineFALSE);
	}

	/* read a single byte from the file */
	return (read (fileHandle, (char *)byte, 1) == 1);
}

/*
//	Function Name:
//		engineFileReadWord
//
//	Description:
//		A helper function to read a word (delimited by space or end of line)
//		from a file
//
//  Input Arguments:
//		EtFileHandle fileHandle		The handle to an open file
//
//  Return Value:
//		EtByte *					A pointer to the word just read
//			kEngineNULL				could not read a word (most likely because
//										we are at the end of the file)
//
//	Note:
//		engineFileReadWord uses a static buffer to hold the word just
//	read.  Subsequent calls to engineFileReadWord will over write this
//	buffer
*/
EtByte *
engineFileReadWord (EtFileHandle fileHandle)
{
	static EtByte string[kFileMaxWordSize];
	EtByte *c = string;
	EtBoolean continueReading;

	/* make sure we have a valid file handle */
	if (fileHandle < 0) {
		return (kEngineNULL);
	}

	/* look for the first character of the word */
	continueReading = engineFileReadByte (fileHandle, c);
	while (continueReading && (*c <= ' ')) {
		continueReading = engineFileReadByte (fileHandle, c);
	}
	if (!continueReading) return (kEngineNULL);

	/* look for the last character of the word */
	c++;
	while (engineFileReadByte (fileHandle, c) && (*c > ' ')) {
		c++;
	}

	/* strip off any trailing ';' */
	if ((c > string) && (*(c - 1) == ';')) c--;
	*c = 0x00;
	return (string);
}

/*
//	Function Name:
//		engineFileReadInt
//
//	Description:
//		A helper function to read an integer number from a file
//
//  Input Arguments:
//		EtFileHandle fileHandle		The handle to an open file
//
//  Return Value:
//		EtInt						The integer number just read
//
//	Note:
//		there is no way to detect end-of-file when reading an integer
//	number
*/
EtInt
engineFileReadInt (EtFileHandle fileHandle)
{
	EtByte *word = engineFileReadWord (fileHandle);
	return (word == kEngineNULL ? 0 : atoi ((const char *)word));
}

/*
//	Function Name:
//		engineFileReadFloat
//
//	Description:
//		A helper function to read a floating point number from a file
//
//  Input Arguments:
//		EtFileHandle fileHandle		The handle to an open file
//
//  Return Value:
//		EtFloat						The floating point number just read
//
//	Note:
//		there is no way to detect end-of-file when reading a floating
//	point number
*/
EtFloat
engineFileReadFloat (EtFileHandle fileHandle)
{
	EtByte *word = engineFileReadWord (fileHandle);
	return (word == kEngineNULL ? 0.0 : atof ((const char *)word));
}
