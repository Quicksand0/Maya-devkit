#ifndef _MPxGeometryIterator
#define _MPxGeometryIterator
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
// CLASS:    MPxGeometryIterator
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>

// ****************************************************************************
// DECLARATIONS

class MPxSurfaceShape;
class MPoint;
class MObjectArray;
class TcomponentList;

// ****************************************************************************
// CLASS DECLARATION (MPxGeometryIterator)

//! \ingroup OpenMaya MPx
//! \brief Base class for user defined geometry iterators. 
/*!
  This is the base class for user defined geometry iterators.
  Geometry iterator allow iterating over components in geometry
  in a geometry independent manner. This base class defines
  the interface to be used by maya when a generic component iteration
  is required.

  This class is used in conjunction with MPxSurfaceShape to provide
  an iterator for components in a user defined shape. Also this method
  can is used by MPxGeometryData to provide an iterator over geometry
  that is passed through DG connections.

  The main methods to override in this class are point and setPoint.
  The reset, isDone, and next methods have a default implementation
  and should only be overridden if the component being iterator on
  is not a single indexed component type.

  The iterator works in two modes, over components or over all elements
  in some geometry. If the components passed into the constructors are
  null or empty then the iteration is meant to be over the entire object.
*/
class OPENMAYA_EXPORT MPxGeometryIterator
{
public:
	MPxGeometryIterator( void * userGeometry, MObjectArray & components );
	MPxGeometryIterator( void * userGeometry, MObject & components );
	virtual ~MPxGeometryIterator();

	// ************************************************************
	// Methods to overload

	// Item by item traversal methods
	//
	virtual bool			isDone() const;
	virtual void			next();
	virtual void			reset();

	// component for Item
	virtual void			component( MObject &component );

	// Item's point info access methods
	//
	virtual bool			hasPoints() const;
	virtual int				iteratorCount() const;
	virtual MPoint			point() const;
	virtual void			setPoint( const MPoint & ) const;
	virtual int				setPointGetNext( MPoint & );
	virtual int				index() const;


	virtual bool			hasNormals() const;

	virtual int				indexUnsimplified() const;

	// ************************************************************

	// Methods to access the iterator values.
	// These values are used when iterating over all components
	// of a shape when there are no components specified.
	int						currentPoint() const;
	void					setCurrentPoint( int );
	int						maxPoints() const;
	void					setMaxPoints( int );



	//	Method to (optionally) set object (to allow tweaking of history)
	//
	void					setObject( MPxSurfaceShape & );

	void*					geometry() const;

	static const char*	    className();

protected:

private:
	void * instance;
	TcomponentList			*compList;
};

#endif /* __cplusplus */
#endif /* _MPxGeometryIterator */
