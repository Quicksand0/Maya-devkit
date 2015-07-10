#ifndef _hwRefractReflectShader_NV20
#define _hwRefractReflectShader_NV20

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

///////////////////////////////////////////////////////////////////
//
// NOTE: PLEASE READ THE README.TXT FILE FOR INSTRUCTIONS ON
// COMPILING AND USAGE REQUIREMENTS.
//
// DESCRIPTION: NV20-specific (Geforce3) sample shader.
//				<fill up later>
//
//  This shader builds on the foundation demonstrated in the 
//  hwUnlitShader.
//
//
///////////////////////////////////////////////////////////////////

#include <maya/MPxHwShaderNode.h>
#include "MTextureCache.h"


class hwRefractReflectShader_NV20 : public MPxHwShaderNode
{
public:
                    hwRefractReflectShader_NV20();
    virtual         ~hwRefractReflectShader_NV20();
	void			releaseEverything();

    virtual MStatus compute( const MPlug&, MDataBlock& );
	virtual void    postConstructor();

	virtual MStatus	geometry( const MDrawRequest& request,
							  M3dView& view,
							  int prim,
							  unsigned int writable,
							  int indexCount,
							  const unsigned int * indexArray,
							  int vertexCount,
							  const int * vertexIDs,
							  const float * vertexArray,
							  int normalCount,
							  const float ** normalArrays,
							  int colorCount,
							  const float ** colorArrays,
							  int texCoordCount,
							  const float ** texCoordArrays);

	virtual int		normalsPerVertex();
	virtual int		texCoordsPerVertex();
    static  void *  creator();
    static  MStatus initialize();
    static  MTypeId id;

	MTextureCache	*m_pTextureCache;

	void			loadVertexProgramGL( M3dView& view );
	float*			computeBinormals(int indexCount, const unsigned int * indexArray, 
									 int vertexCount, const float* vertexArray, 
									 const float* normalsArray, 
									 const float* texCoordsArray);

protected:

	void		init_ext(const char *ext);

	MStatus		loadTextures(const MDrawRequest& request, M3dView& view);
	void		initCombiners(const MDrawRequest& request, M3dView& view);

	MStatus		preDraw (const MDrawRequest& request, M3dView& view);
	MStatus		postDraw(const MDrawRequest& request, M3dView& view);

    static MObject  colorR;
	static MObject  colorG;
	static MObject  colorB;
	static MObject  color;

    static MObject  refractionIndex;
    static MObject  reflectivity;

	// Callbacks that we monitor so we can release OpenGL-dependant resources before
	// their context gets destroyed.
	MCallbackId fBeforeNewCB;
	MCallbackId fBeforeOpenCB;
	MCallbackId fBeforeRemoveReferenceCB;
	MCallbackId fMayaExitingCB;

	void attachSceneCallbacks();
	void detachSceneCallbacks();
	static void releaseCallback(void* clientData);

private:

	// Images to store the cubeMap texture names
	//
	MImage theImage_XP;
	MImage theImage_XN;
	MImage theImage_YP;
	MImage theImage_YN;
	MImage theImage_ZP;
	MImage theImage_ZN;

	GLuint	vertex_program_id;		// handle for the Vertex Program
	GLuint	fTextureName;			// texture name
	MString currentTextureNames[6];	// cubemap file texture names

	float	fRefractionIndex;
	float	fReflectivity;

	MVector	fCameraRotationAxis;
	double	fCameraRotationAngle;
};

#endif /* _hwRefractReflectShader_NV20 */
