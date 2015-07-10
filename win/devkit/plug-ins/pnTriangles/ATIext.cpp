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

//
// Description:
//		ATI extension binder utilties
//
//
#include "ATIext.h"
#include <maya/MIOStream.h>

#ifdef _WIN32
	// Convenience macro for declaring WGL api entries
	#define OGL_GET_PROC( _type_, _entry_, _failbit_ ) \
		_entry_ = (_type_) wglGetProcAddress( #_entry_ ); \
		if (NULL == _entry_) _failbit_=false; 
#elif LINUX
	// Convenience macro for declaring OGL api entries
	#ifdef GLX_ARB_get_proc_address
	#define OGL_GET_PROC( _type_, _entry_, _failbit_ ) \
				_entry_ = (_type_) ::glXGetProcAddressARB( #_entry_ ); \
				if (NULL == _entry_) _failbit_=false;
	#else
		#define OGL_GET_PROC( _type_, _entry_, _failbit_ )	
	#endif
#else
	#define OGL_GET_PROC( _type_, _entry_, _failbit_ )	
#endif

// Mulitexturing
//
#ifdef _BIND_MULTITEXTURE_EXTENSION_REQURIED
	PFNGLACTIVETEXTUREARBPROC glActiveTextureARB = NULL;
	PFNGLCLIENTACTIVETEXTUREARBPROC glClientActiveTextureARB = NULL;
	PFNGLMULTITEXCOORD1DARBPROC glMultiTexCoord1dARB = NULL;
	PFNGLMULTITEXCOORD1DVARBPROC glMultiTexCoord1dvARB = NULL;
	PFNGLMULTITEXCOORD1FARBPROC glMultiTexCoord1fARB = NULL;
	PFNGLMULTITEXCOORD1FVARBPROC glMultiTexCoord1fvARB = NULL;
	PFNGLMULTITEXCOORD1IARBPROC glMultiTexCoord1iARB = NULL;
	PFNGLMULTITEXCOORD1IVARBPROC glMultiTexCoord1ivARB = NULL;
	PFNGLMULTITEXCOORD1SARBPROC glMultiTexCoord1sARB = NULL;
	PFNGLMULTITEXCOORD1SVARBPROC glMultiTexCoord1svARB = NULL;
	PFNGLMULTITEXCOORD2DARBPROC glMultiTexCoord2dARB = NULL;
	PFNGLMULTITEXCOORD2DVARBPROC glMultiTexCoord2dvARB = NULL;
	PFNGLMULTITEXCOORD2FARBPROC glMultiTexCoord2fARB = NULL;
	PFNGLMULTITEXCOORD2FVARBPROC glMultiTexCoord2fvARB = NULL;
	PFNGLMULTITEXCOORD2IARBPROC glMultiTexCoord2iARB = NULL;
	PFNGLMULTITEXCOORD2IVARBPROC glMultiTexCoord2ivARB = NULL;
	PFNGLMULTITEXCOORD2SARBPROC glMultiTexCoord2sARB = NULL;
	PFNGLMULTITEXCOORD2SVARBPROC glMultiTexCoord2svARB = NULL;
	PFNGLMULTITEXCOORD3DARBPROC glMultiTexCoord3dARB = NULL;
	PFNGLMULTITEXCOORD3DVARBPROC glMultiTexCoord3dvARB = NULL;
	PFNGLMULTITEXCOORD3FARBPROC glMultiTexCoord3fARB = NULL;
	PFNGLMULTITEXCOORD3FVARBPROC glMultiTexCoord3fvARB = NULL;
	PFNGLMULTITEXCOORD3IARBPROC glMultiTexCoord3iARB = NULL;
	PFNGLMULTITEXCOORD3IVARBPROC glMultiTexCoord3ivARB = NULL;
	PFNGLMULTITEXCOORD3SARBPROC glMultiTexCoord3sARB = NULL;
	PFNGLMULTITEXCOORD3SVARBPROC glMultiTexCoord3svARB = NULL;
	PFNGLMULTITEXCOORD4DARBPROC glMultiTexCoord4dARB = NULL;
	PFNGLMULTITEXCOORD4DVARBPROC glMultiTexCoord4dvARB = NULL;
	PFNGLMULTITEXCOORD4FARBPROC glMultiTexCoord4fARB = NULL;
	PFNGLMULTITEXCOORD4FVARBPROC glMultiTexCoord4fvARB = NULL;
	PFNGLMULTITEXCOORD4IARBPROC glMultiTexCoord4iARB = NULL;
	PFNGLMULTITEXCOORD4IVARBPROC glMultiTexCoord4ivARB = NULL;
	PFNGLMULTITEXCOORD4SARBPROC glMultiTexCoord4sARB = NULL;
	PFNGLMULTITEXCOORD4SVARBPROC glMultiTexCoord4svARB = NULL;
#endif

// PN Triangles extension functions
//
#ifdef _BIND_PN_EXTENSIONS_REQUIRED
	PFNGLPNTRIANGLESIATIPROC glPNTrianglesiATI = NULL;
	PFNGLPNTRIANGLESFATIPROC glPNTrianglesfATI = NULL;
#endif

#ifdef _BIND_EXT_VERTEX_SHADER_EXTENSIONS_REQUIRED
	PFNGLBEGINVERTEXSHADEREXTPROC glBeginVertexShaderEXT = NULL;
	PFNGLENDVERTEXSHADEREXTPROC glEndVertexShaderEXT = NULL;
	PFNGLBINDVERTEXSHADEREXTPROC glBindVertexShaderEXT = NULL;
	PFNGLGENVERTEXSHADERSEXTPROC glGenVertexShadersEXT = NULL;
	PFNGLDELETEVERTEXSHADEREXTPROC glDeleteVertexShaderEXT = NULL;
	PFNGLSHADEROP1EXTPROC glShaderOp1EXT = NULL;
	PFNGLSHADEROP2EXTPROC glShaderOp2EXT = NULL;
	PFNGLSHADEROP3EXTPROC glShaderOp3EXT = NULL;
	PFNGLSWIZZLEEXTPROC glSwizzleEXT = NULL;
	PFNGLWRITEMASKEXTPROC glWriteMaskEXT = NULL;
	PFNGLINSERTCOMPONENTEXTPROC glInsertComponentEXT = NULL;
	PFNGLEXTRACTCOMPONENTEXTPROC glExtractComponentEXT = NULL;
	PFNGLGENSYMBOLSEXTPROC glGenSymbolsEXT = NULL;
	PFNGLSETINVARIANTEXTPROC glSetInvariantEXT = NULL;
	PFNGLSETLOCALCONSTANTEXTPROC glSetLocalConstantEXT = NULL;
	PFNGLVARIANTBVEXTPROC glVariantbvEXT = NULL;
	PFNGLVARIANTSVEXTPROC glVariantsvEXT = NULL;
	PFNGLVARIANTIVEXTPROC glVariantivEXT = NULL;
	PFNGLVARIANTFVEXTPROC glVariantfvEXT = NULL;
	PFNGLVARIANTDVEXTPROC glVariantdvEXT = NULL;
	PFNGLVARIANTUBVEXTPROC glVariantubvEXT = NULL;
	PFNGLVARIANTUSVEXTPROC glVariantusvEXT = NULL;
	PFNGLVARIANTUIVEXTPROC glVariantuivEXT = NULL;
	PFNGLVARIANTPOINTEREXTPROC glVariantPointerEXT = NULL;
	PFNGLENABLEVARIANTCLIENTSTATEEXTPROC glEnableVariantClientStateEXT = NULL;
	PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC glDisableVariantClientStateEXT = NULL;
	PFNGLBINDLIGHTPARAMETEREXTPROC glBindLightParameterEXT = NULL;
	PFNGLBINDMATERIALPARAMETEREXTPROC glBindMaterialParameterEXT = NULL;
	PFNGLBINDTEXGENPARAMETEREXTPROC glBindTexGenParameterEXT = NULL;
	PFNGLBINDTEXTUREUNITPARAMETEREXTPROC glBindTextureUnitParameterEXT = NULL;
	PFNGLBINDPARAMETEREXTPROC glBindParameterEXT = NULL;
	PFNGLISVARIANTENABLEDEXTPROC glIsVariantEnabledEXT = NULL;
	PFNGLGETVARIANTBOOLEANVEXTPROC glGetVariantBooleanvEXT = NULL;
	PFNGLGETVARIANTINTEGERVEXTPROC glGetVariantIntegervEXT = NULL;
	PFNGLGETVARIANTFLOATVEXTPROC glGetVariantFloatvEXT = NULL;
	PFNGLGETVARIANTPOINTERVEXTPROC glGetVariantPointervEXT = NULL;
	PFNGLGETINVARIANTBOOLEANVEXTPROC glGetInvariantBooleanvEXT = NULL;
	PFNGLGETINVARIANTINTEGERVEXTPROC glGetInvariantIntegervEXT = NULL;
	PFNGLGETINVARIANTFLOATVEXTPROC glGetInvariantFloatvEXT = NULL;
	PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC glGetLocalConstantBooleanvEXT = NULL;
	PFNGLGETLOCALCONSTANTINTEGERVEXTPROC glGetLocalConstantIntegervEXT = NULL;
	PFNGLGETLOCALCONSTANTFLOATVEXTPROC glGetLocalConstantFloatvEXT = NULL;
#endif

#ifdef _BIND_EXT_FRAGMENT_SHADER_EXTENSIONS_REQUIRED
	PFNGLGENFRAGMENTSHADERSATIPROC glGenFragmentShadersATI = NULL;
	PFNGLBINDFRAGMENTSHADERATIPROC glBindFragmentShaderATI = NULL;
	PFNGLDELETEFRAGMENTSHADERATIPROC glDeleteFragmentShaderATI = NULL;
	PFNGLBEGINFRAGMENTSHADERATIPROC glBeginFragmentShaderATI = NULL;
	PFNGLENDFRAGMENTSHADERATIPROC glEndFragmentShaderATI = NULL;
	PFNGLPASSTEXCOORDATIPROC glPassTexCoordATI = NULL;
	PFNGLSAMPLEMAPATIPROC glSampleMapATI = NULL;
	PFNGLCOLORFRAGMENTOP1ATIPROC glColorFragmentOp1ATI = NULL;
	PFNGLCOLORFRAGMENTOP2ATIPROC glColorFragmentOp2ATI = NULL;
	PFNGLCOLORFRAGMENTOP3ATIPROC glColorFragmentOp3ATI = NULL;
	PFNGLALPHAFRAGMENTOP1ATIPROC glAlphaFragmentOp1ATI = NULL;
	PFNGLALPHAFRAGMENTOP2ATIPROC glAlphaFragmentOp2ATI = NULL;
	PFNGLALPHAFRAGMENTOP3ATIPROC glAlphaFragmentOp3ATI = NULL;
	PFNGLSETFRAGMENTSHADERCONSTANTATIPROC glSetFragmentShaderConstantATI = NULL;
#endif

static GLubyte *gfx_extensions = NULL;

GLboolean initialize_ATI_Extension(char *extensionString)
{
	GLboolean success = 0;
	
	// Get all strings
	if (gfx_extensions == NULL)
		gfx_extensions = (GLubyte *) ::glGetString(GL_EXTENSIONS);
	
	// Check for a specific extension
	if (gfx_extensions)
	{
		// Found the pn triangles extension. Now bind the funcitons
		if (strstr((char *)gfx_extensions, extensionString))
		{
			if (strcmp(extensionString, "GL_ATI_pn_triangles") == 0)
			{
				success = 1;
				#ifdef _BIND_MULTITEXTURE_EXTENSION_REQURIED
				{
					OGL_GET_PROC( PFNGLACTIVETEXTUREARBPROC, glActiveTextureARB , success);
					OGL_GET_PROC( PFNGLCLIENTACTIVETEXTUREARBPROC, glClientActiveTextureARB, success );
					OGL_GET_PROC( PFNGLMULTITEXCOORD1DARBPROC, glMultiTexCoord1dARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD1DVARBPROC, glMultiTexCoord1dvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD1FARBPROC, glMultiTexCoord1fARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD1FVARBPROC, glMultiTexCoord1fvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD1IARBPROC, glMultiTexCoord1iARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD1IVARBPROC, glMultiTexCoord1ivARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD1SARBPROC, glMultiTexCoord1sARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD1SVARBPROC, glMultiTexCoord1svARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2DARBPROC, glMultiTexCoord2dARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2DVARBPROC, glMultiTexCoord2dvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2FARBPROC, glMultiTexCoord2fARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2FVARBPROC, glMultiTexCoord2fvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2IARBPROC, glMultiTexCoord2iARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2IVARBPROC, glMultiTexCoord2ivARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2SARBPROC, glMultiTexCoord2sARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD2SVARBPROC, glMultiTexCoord2svARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3DARBPROC, glMultiTexCoord3dARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3DVARBPROC, glMultiTexCoord3dvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3FARBPROC, glMultiTexCoord3fARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3FVARBPROC, glMultiTexCoord3fvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3IARBPROC, glMultiTexCoord3iARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3IVARBPROC, glMultiTexCoord3ivARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3SARBPROC, glMultiTexCoord3sARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD3SVARBPROC, glMultiTexCoord3svARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4DARBPROC, glMultiTexCoord4dARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4DVARBPROC, glMultiTexCoord4dvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4FARBPROC, glMultiTexCoord4fARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4FVARBPROC, glMultiTexCoord4fvARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4IARBPROC, glMultiTexCoord4iARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4IVARBPROC, glMultiTexCoord4ivARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4SARBPROC, glMultiTexCoord4sARB, success);
					OGL_GET_PROC( PFNGLMULTITEXCOORD4SVARBPROC, glMultiTexCoord4svARB, success);
				}
				#endif
			}
			
			// PN triangles extension check
			//
			if (strcmp(extensionString, "GL_ATI_pn_triangles") == 0)
			{
				success = 1;
				#ifdef _BIND_PN_EXTENSIONS_REQUIRED
				{
					OGL_GET_PROC( PFNGLPNTRIANGLESIATIPROC, glPNTrianglesiATI, success );
					OGL_GET_PROC( PFNGLPNTRIANGLESFATIPROC, glPNTrianglesfATI, success );
				}
				#endif
			}
			
			// Vertex shader extension check
			//
			else if (strcmp(extensionString, "GL_EXT_vertex_shader"))
			{
				success = 1;
				#ifdef _BIND_EXT_VERTEX_SHADER_EXTENSIONS_REQUIRED
				{
					OGL_GET_PROC(PFNGLBEGINVERTEXSHADEREXTPROC, glBeginVertexShaderEXT, success);
					OGL_GET_PROC(PFNGLENDVERTEXSHADEREXTPROC, glEndVertexShaderEXT, success);
					OGL_GET_PROC(PFNGLBINDVERTEXSHADEREXTPROC, glBindVertexShaderEXT, success);
					OGL_GET_PROC(PFNGLGENVERTEXSHADERSEXTPROC, glGenVertexShadersEXT, success);
					OGL_GET_PROC(PFNGLDELETEVERTEXSHADEREXTPROC, glDeleteVertexShaderEXT, success);
					OGL_GET_PROC(PFNGLSHADEROP1EXTPROC, glShaderOp1EXT, success);
					OGL_GET_PROC(PFNGLSHADEROP2EXTPROC, glShaderOp2EXT, success);
					OGL_GET_PROC(PFNGLSHADEROP3EXTPROC, glShaderOp3EXT, success);
					OGL_GET_PROC(PFNGLSWIZZLEEXTPROC, glSwizzleEXT, success);
					OGL_GET_PROC(PFNGLWRITEMASKEXTPROC, glWriteMaskEXT, success);
					OGL_GET_PROC(PFNGLINSERTCOMPONENTEXTPROC, glInsertComponentEXT, success);
					OGL_GET_PROC(PFNGLEXTRACTCOMPONENTEXTPROC, glExtractComponentEXT, success);
					OGL_GET_PROC(PFNGLGENSYMBOLSEXTPROC, glGenSymbolsEXT, success);
					OGL_GET_PROC(PFNGLSETINVARIANTEXTPROC, glSetInvariantEXT, success);
					OGL_GET_PROC(PFNGLSETLOCALCONSTANTEXTPROC, glSetLocalConstantEXT, success);
					OGL_GET_PROC(PFNGLVARIANTBVEXTPROC, glVariantbvEXT, success);
					OGL_GET_PROC(PFNGLVARIANTSVEXTPROC, glVariantsvEXT, success);
					OGL_GET_PROC(PFNGLVARIANTIVEXTPROC, glVariantivEXT, success);
					OGL_GET_PROC(PFNGLVARIANTFVEXTPROC, glVariantfvEXT, success);
					OGL_GET_PROC(PFNGLVARIANTDVEXTPROC, glVariantdvEXT, success);
					OGL_GET_PROC(PFNGLVARIANTUBVEXTPROC, glVariantubvEXT, success);
					OGL_GET_PROC(PFNGLVARIANTUSVEXTPROC, glVariantusvEXT, success);
					OGL_GET_PROC(PFNGLVARIANTUIVEXTPROC, glVariantuivEXT, success);
					OGL_GET_PROC(PFNGLVARIANTPOINTEREXTPROC, glVariantPointerEXT, success);
					OGL_GET_PROC(PFNGLENABLEVARIANTCLIENTSTATEEXTPROC, glEnableVariantClientStateEXT, success);
					OGL_GET_PROC(PFNGLDISABLEVARIANTCLIENTSTATEEXTPROC, glDisableVariantClientStateEXT, success);
					OGL_GET_PROC(PFNGLBINDLIGHTPARAMETEREXTPROC, glBindLightParameterEXT, success);
					OGL_GET_PROC(PFNGLBINDMATERIALPARAMETEREXTPROC, glBindMaterialParameterEXT, success);
					OGL_GET_PROC(PFNGLBINDTEXGENPARAMETEREXTPROC, glBindTexGenParameterEXT, success);
					OGL_GET_PROC(PFNGLBINDTEXTUREUNITPARAMETEREXTPROC, glBindTextureUnitParameterEXT, success);
					OGL_GET_PROC(PFNGLBINDPARAMETEREXTPROC, glBindParameterEXT, success);
					OGL_GET_PROC(PFNGLISVARIANTENABLEDEXTPROC, glIsVariantEnabledEXT, success);
					OGL_GET_PROC(PFNGLGETVARIANTBOOLEANVEXTPROC, glGetVariantBooleanvEXT, success);
					OGL_GET_PROC(PFNGLGETVARIANTINTEGERVEXTPROC, glGetVariantIntegervEXT, success);
					OGL_GET_PROC(PFNGLGETVARIANTFLOATVEXTPROC, glGetVariantFloatvEXT, success);
					OGL_GET_PROC(PFNGLGETVARIANTPOINTERVEXTPROC, glGetVariantPointervEXT, success);
					OGL_GET_PROC(PFNGLGETINVARIANTBOOLEANVEXTPROC, glGetInvariantBooleanvEXT, success);
					OGL_GET_PROC(PFNGLGETINVARIANTINTEGERVEXTPROC, glGetInvariantIntegervEXT, success);
					OGL_GET_PROC(PFNGLGETINVARIANTFLOATVEXTPROC, glGetInvariantFloatvEXT, success);
					OGL_GET_PROC(PFNGLGETLOCALCONSTANTBOOLEANVEXTPROC, glGetLocalConstantBooleanvEXT, success);
					OGL_GET_PROC(PFNGLGETLOCALCONSTANTINTEGERVEXTPROC, glGetLocalConstantIntegervEXT, success);
					OGL_GET_PROC(PFNGLGETLOCALCONSTANTFLOATVEXTPROC, glGetLocalConstantFloatvEXT, success);
				}
				#endif
			}
			
			// Fragment shader extension check
			//
			else if (strcmp(extensionString, "GL_ATI_fragment_shader"))
			{
				success = 1;
				#ifdef _BIND_EXT_FRAGMENT_SHADER_EXTENSIONS_REQUIRED
				{
					OGL_GET_PROC( PFNGLGENFRAGMENTSHADERSATIPROC, glGenFragmentShadersATI, success);
					OGL_GET_PROC( PFNGLBINDFRAGMENTSHADERATIPROC, glBindFragmentShaderATI, success);
					OGL_GET_PROC( PFNGLDELETEFRAGMENTSHADERATIPROC, glDeleteFragmentShaderATI, success);
					OGL_GET_PROC( PFNGLBEGINFRAGMENTSHADERATIPROC, glBeginFragmentShaderATI, success);
					OGL_GET_PROC( PFNGLENDFRAGMENTSHADERATIPROC, glEndFragmentShaderATI, success);
					OGL_GET_PROC( PFNGLPASSTEXCOORDATIPROC, glPassTexCoordATI, success);
					OGL_GET_PROC( PFNGLSAMPLEMAPATIPROC, glSampleMapATI, success);
					OGL_GET_PROC( PFNGLCOLORFRAGMENTOP1ATIPROC, glColorFragmentOp1ATI, success);
					OGL_GET_PROC( PFNGLCOLORFRAGMENTOP2ATIPROC, glColorFragmentOp2ATI, success);
					OGL_GET_PROC( PFNGLCOLORFRAGMENTOP3ATIPROC, glColorFragmentOp3ATI, success);
					OGL_GET_PROC( PFNGLALPHAFRAGMENTOP1ATIPROC, glAlphaFragmentOp1ATI, success);
					OGL_GET_PROC( PFNGLALPHAFRAGMENTOP2ATIPROC, glAlphaFragmentOp2ATI, success);
					OGL_GET_PROC( PFNGLALPHAFRAGMENTOP3ATIPROC, glAlphaFragmentOp3ATI, success);
					OGL_GET_PROC( PFNGLSETFRAGMENTSHADERCONSTANTATIPROC, glSetFragmentShaderConstantATI, success);
				}
				#endif
			}
			
			else 
			{
				cerr << extensionString << " extension is not supported by this plugin" << endl;
			}
		}
	}
	
	return success;
}

