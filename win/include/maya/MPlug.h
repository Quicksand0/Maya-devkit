#ifndef _MPlug
#define _MPlug
//-
// Copyright 2015 Autodesk, Inc. All rights reserved.
// 
// Use of this software is subject to the terms of the Autodesk
// license agreement provided at the time of installation or download,
// or which otherwise accompanies this software in either electronic
// or hard copy form.
//+
//
// CLASS:    MPlug
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MDGContext.h>
#include <maya/MObject.h>
#include <maya/MIntArray.h>
// ****************************************************************************
// DECLARATIONS

class MString;
class MStringArray;
class MPlugArray;
class MTime;
class MPxData;
class MAngle;
class MDistance;
class MDataHandle;
class MDataBlock;


// ****************************************************************************
// CLASS DECLARATION (MPlug)

//! \ingroup OpenMaya
//! \brief Create and Access dependency node plugs.
/*!
	MPlug provides methods for creating plugs, and accessing the plugs'
	dependency node and attributes.

	A plug is a point on a dependency node where a particular attribute can be
	connected.  In simple cases the plug and attribute are equivalent.
	When you have array attributes,  however, the plug is more specific
	in that it indicates which of the array elements is to be connected.

	There are two main types of plugs: networked plugs and non-networked plugs.
	Non-networked plugs can be considered user plugs as they are
	created by users and belong to users. Networked plugs can be considered
	dependency node plugs as they are part of the dependency graph and can
	only be referenced by users.

    In every dependency node there is a network or "tree" of plugs indicating
    connections that have been made to attributes of the node. The plugs in
	this tree are known as <b>networked</b> plugs as they belong to the
	dependency node's network.

    <b>Non-networked</b> plugs are plugs that you can create in order to
	establish a new connection to an attribute, or to get or set a value
    on an attribute.  When a connection is made using these plugs, a
	networked version of the plug is created and added to the dependency
    nodes network.

    A <b>networked</b> plug cannot be explicitly created. They are created when
    a connection is established for some attribute of the node.  Since the
	allocation of networked plugs is managed exclusively by Maya, a plugin
	should never reference a networked plug after changes are made to the DG.
	Instead, use a non-networked version of the plug, or get a new reference
	to the networked plug.

    All a <b>non-networked</b> plug knows is how to uniquely describe the
	attribute that it references, in fact the purpose of a non-networked
	plug is to specify, without ambiguity, an attribute of a dependency node.
	A non-networked plug contains an array of array indices that plot the
	path from the root plug to this plug.

    For simple attributes the plug and attribute are equivalent. Compound
    attributes are also unambiguous. A plug that refers to an array
    attribute, however, is more complex as it can refer to the <b>array
    plug</b> or an <b>element plug</b> in the array.

	Several methods are provided for navigating the plug tree. The child()
    method can be used to retrieve the <b>child plugs</b> of a <b>compound
    plug</b>. The elementByLogicalIndex() and elementByPhysicalIndex()
    methods can be used to retrieve the element plugs of an array plug. The
    parent() and array() methods traverse the tree in the opposite
    direction: parent() retrieves a compound plug from a child plug, and
    array() retrieves an array plug from an element plug.

	Since connections to arrays are sparse, element plugs have both logical
    and physical indexes. The logical indexes are used by MEL, and are sparse.
    Physical indexes, on the other hand, are not sparse. It is guaranteed that
    the physical indexes will range from 0 to numElements() - 1. Using the
    physical indexes, iterating over the element plugs in an array is easy:
     \code

       // See note below on numElements() method
       for (i = 0; i < arrayPlug.numElements (); i++)
       {
           MPlug elementPlug = arrayPlug [i];
		   unsigned int logicalIndex = elementPlug.logicalIndex();
           // ...
       }
    \endcode

	This is equivalent to calling elementByPhysicalIndex() since the
	bracket operator uses physical indexes.

	The ancestry of a plug is the tree above the plug: any parents or
	arrays which this plug belongs to. The
	selectAncestorLogicalIndex() method provides quick access to
	element plugs without walking the plug tree. A plug does not need
	to exist in the datablock or plug tree in order to be constructed
	using selectAncestorLogicalIndex(), but once a value is requested or set
	on the plug, it will be added to the datablock if it was not there
	already.  For example: 

	\code
	MPlug plug(node,attribute);
	// See note below on numElements() method
	unsigned int count = plug.numElements();
	if (0 == count) {
	    plug.selectAncestorLogicalIndex(0,attribute);
		plug.setValue(setVal);
		count = plug.numElements(); // count will now be 1 since we added a value

	    plug.selectAncestorLogicalIndex(10,attribute);
		MObject getVal;
		plug.getValue(getVal);
		count = plug.numElements(); // count will now be 2 since we asked for a value
	}
    \endcode

	Once a value has been added to an array plug, it will usually
	remain in the datablock as long as the scene is open. The
	exception is for attributes that have their disconnect behavior
	set to kDelete: data for these attributes will be deleted when
	their connection is broken. When a file is saved, only array
	values that are not at their default values will be written
	out. Therefore, the number of elements in an array plug may change
	when the file is read in again.

	\note
	The numElements() call for array plugs returns a value based
	on the information in the datablock.  It is possible to have
	un-evaluated connected items being excluded from the count since
	these items are not yet in the datablock.  In this case, the
	numElements() method will return the correct answer if the
	evaluateNumElements() call is made first.  But this cannot be
	done in the MPxNode::compute() method of a node.
*/
class OPENMAYA_EXPORT MPlug
{
public:
	MPlug();
	MPlug( const MPlug& in );
	MPlug( const MObject & node, const MObject & attribute );
	virtual	~MPlug();

	MStatus     setAttribute (MObject &attribute);
	MObject		attribute( MStatus* ReturnStatus = NULL ) const;
	MObject 	node( MStatus* ReturnStatus = NULL ) const;
	MString		name( MStatus* ReturnStatus = NULL ) const;
	MString		partialName(
					bool			includeNodeName = false,
					bool			includeNonMandatoryIndices = false,
					bool			includeInstancedIndices = false,
					bool			useAlias = false,
					bool			useFullAttributePath = false,
					bool			useLongNames = false,
					MStatus*		ReturnStatus = NULL
				) const;

	//! Which values to generate setAttr commands for.
	enum MValueSelector {
		kAll,				//!< All values
		kNonDefault,		//!< Non default values
		kChanged,			//!< Changed values
		kLastAttrSelector	//!< Last value, for counting
	};

	MStatus		getSetAttrCmds(
					MStringArray&	cmds,
					MValueSelector	valueSelector = kAll,
					bool			useLongNames = false
				);

	bool		isNetworked( MStatus* ReturnStatus = NULL ) const;
	bool        isArray( MStatus* ReturnStatus = NULL ) const;
	bool        isElement( MStatus* ReturnStatus = NULL) const;
	bool        isCompound( MStatus* ReturnStatus = NULL ) const;
	bool        isChild( MStatus* ReturnStatus = NULL ) const;
	bool        isProcedural( MStatus* ReturnStatus = NULL ) const;
	unsigned int	logicalIndex( MStatus* ReturnStatus = NULL ) const;
	MStatus	    selectAncestorLogicalIndex( unsigned int index,
											const MObject &attribute =
											MObject::kNullObj);

	unsigned int    getExistingArrayAttributeIndices( MIntArray& indices,
												  MStatus* ReturnStatus = NULL);

	unsigned int    numElements( MStatus* ReturnStatus = NULL ) const;
	unsigned int    evaluateNumElements( MStatus* ReturnStatus = NULL );
	unsigned int    numChildren( MStatus* ReturnStatus = NULL ) const;
	unsigned int    numConnectedElements( MStatus* ReturnStatus = NULL ) const;
	unsigned int    numConnectedChildren( MStatus* ReturnStatus = NULL ) const;
	MPlug		child(	MObject& attr, MStatus* ReturnStatus = NULL ) const;
	MPlug		child(	unsigned int index, MStatus* ReturnStatus = NULL ) const;
	MPlug		parent( MStatus* ReturnStatus = NULL ) const;
	MPlug       array( MStatus* ReturnStatus = NULL ) const;
	MPlug       elementByLogicalIndex( unsigned int logicalIndex,
									   MStatus* ReturnStatus = NULL)
                const;
	MPlug       elementByPhysicalIndex( unsigned int physicalIndex,
										MStatus* ReturnStatus = NULL)
                const;
	MPlug       connectionByPhysicalIndex( unsigned int physicalIndex,
										MStatus* ReturnStatus = NULL)
                const;
	bool		connectedTo( MPlugArray & array, bool asDst, bool asSrc,
							 MStatus* ReturnStatus = NULL ) const;
	bool		isConnected( MStatus* ReturnStatus = NULL ) const;

	bool        isKeyable( MStatus* ReturnStatus = NULL ) const;
	MStatus     setKeyable( bool keyable );
	bool        isLocked( MStatus* ReturnStatus = NULL ) const;
	MStatus     setLocked( bool locked );
	bool        isChannelBoxFlagSet( MStatus* ReturnStatus = NULL ) const;
	MStatus     setChannelBox( bool channelBox );
	bool        isCachingFlagSet( MStatus* ReturnStatus = NULL ) const;
	MStatus     setCaching( bool caching );
	bool		isNull( MStatus* ReturnStatus = NULL ) const;
	MString 	info( MStatus* ReturnStatus = NULL ) const;
	bool		isFromReferencedFile( MStatus* ReturnStatus = NULL ) const;
	bool		isDynamic( MStatus* ReturnStatus = NULL ) const;
	bool		isIgnoredWhenRendering( MStatus* ReturnStatus = NULL ) const;

	//! Plug state returned by isFreeToChange
	enum FreeToChangeState {		
		kFreeToChange = 0,			//!< All tested plugs are free to change
		kNotFreeToChange,			//!< Some of the tested plugs are not free to change
		kChildrenNotFreeToChange	//!< Some of the children are not free to change
	};
	MPlug::FreeToChangeState isFreeToChange(bool checkParents = true,
									   bool checkChildren = true,
									   MStatus* ReturnStatus = NULL ) const;
	MDataHandle     constructHandle(MDataBlock&) const;
	void            destructHandle(MDataHandle&) const;

BEGIN_NO_SCRIPT_SUPPORT:

	// functions to get and set attribute values
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( MObject &val, MDGContext& ctx=MDGContext::fsNormal )
				const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( MDataHandle &handle,
						  MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( double&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( float&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( MInt64&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( int&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( short&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( bool&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( MDistance&,
						  MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( MAngle&,
						  MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( MTime&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		getValue( char&, MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus     getValue( MString&,
						  MDGContext& ctx=MDGContext::fsNormal ) const;
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( MObject & val );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( MPxData * data );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( MDataHandle & handle );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( double );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( float );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( MInt64 );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( int );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( short );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( bool );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( MDistance& );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( MAngle& );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( MTime& );
	//!	NO SCRIPT SUPPORT
	MStatus		setValue( char );
	//!	NO SCRIPT SUPPORT
	MStatus     setValue( const MString& );

	//!	NO SCRIPT SUPPORT
	MStatus     setValue( const char* );
END_NO_SCRIPT_SUPPORT:

	// Python Friendly Versions

	// functions to get and set attribute values
	MObject		asMObject	( MDGContext& ctx=MDGContext::fsNormal,
							  MStatus * ReturnStatus = NULL ) const;
	MDataHandle	asMDataHandle( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	double		asDouble	( MDGContext& ctx=MDGContext::fsNormal,
							  MStatus * ReturnStatus = NULL ) const;
	float		asFloat		( MDGContext& ctx=MDGContext::fsNormal,
							  MStatus * ReturnStatus = NULL ) const;
	MInt64		asInt64		( MDGContext& ctx=MDGContext::fsNormal,
							  MStatus * ReturnStatus = NULL ) const;
	int			asInt		( MDGContext& ctx=MDGContext::fsNormal,
							  MStatus * ReturnStatus = NULL ) const;
	short		asShort		( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	bool		asBool		( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	MDistance	asMDistance	( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	MAngle		asMAngle	( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	MTime		asMTime		( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	char		asChar		( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	MString     asString	( MDGContext& ctx=MDGContext::fsNormal,
	 						  MStatus * ReturnStatus = NULL ) const;
	

	MStatus		setMObject( MObject & val );
	MStatus		setMPxData( MPxData * data );
	MStatus		setMDataHandle( MDataHandle & handle );
	MStatus		setDouble( double );
	MStatus		setFloat( float );
	MStatus		setInt64( MInt64 );
	MStatus		setInt( int );
	MStatus		setShort( short );
	MStatus		setBool( bool );
	MStatus		setMDistance( MDistance& );
	MStatus		setMAngle( MAngle& );
	MStatus		setMTime( MTime& );
	MStatus		setChar( char );
	MStatus     setString( const MString& );


	// Operators
	MPlug&		operator =( const MPlug& other );
	MPlug		operator[] ( unsigned int physicalIndex ) const;	// index(index)
	bool		operator ==( const MPlug &other ) const;
	bool        operator ==( const MObject &other ) const;
	bool        operator !=( const MPlug &other ) const;
	bool        operator !=( const MObject &other ) const;
	MStatus		setNumElements( unsigned int );

BEGIN_NO_SCRIPT_SUPPORT:

	//! NO SCRIPT SUPPORT
	MPlug		operator[] ( MObject& attr ) const; // child(attr)

	//! NO SCRIPT SUPPORT
	operator	MObject() const;					// attribute()

	//! NO SCRIPT SUPPORT
	bool		operator!() const;					// false if valid

END_NO_SCRIPT_SUPPORT:

	bool		isSource( MStatus* ReturnStatus = NULL ) const;

	bool		isDestination( MStatus* ReturnStatus = NULL ) const;

	static const char*	className();

protected:
// No protected members

private:
	MString     getStringHelper	( MDGContext& ctx=MDGContext::fsNormal,
		MStatus * ReturnStatus = NULL , bool unUsed = false) const;


	MPlug( const void*, bool );
	const void*	 fPlug;
	bool         ownPlug;
};

#endif /* __cplusplus */
#endif /* _MPlug */
