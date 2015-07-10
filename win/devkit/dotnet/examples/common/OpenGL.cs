﻿// ==================================================================
// Copyright 2012 Autodesk, Inc.  All rights reserved.
// 
// This computer source code  and related  instructions and comments are
// the unpublished confidential and proprietary information of Autodesk,
// Inc. and are  protected  under applicable  copyright and trade secret
// law. They may not  be disclosed to, copied or used by any third party
// without the prior written consent of Autodesk, Inc.
// ==================================================================


using System;
using System.Runtime.InteropServices;

namespace MayaNetPlugin
{
    class OpenGL
    { 
#region The OpenGL constant definitions.

        //   OpenGL Version Identifier
        public const uint GL_VERSION_1_1 = 1;        

        //  AccumOp
        public const uint GL_ACCUM              = 0x0100;
        public const uint GL_LOAD               = 0x0101;
        public const uint GL_RETURN             = 0x0102;
        public const uint GL_MULT               = 0x0103;
        public const uint GL_ADD                = 0x0104;

    //  Alpha functions
        public const uint GL_NEVER              = 0x0200;
        public const uint GL_LESS               = 0x0201;
        public const uint GL_EQUAL              = 0x0202;
        public const uint GL_LEQUAL             = 0x0203;
        public const uint GL_GREATER            = 0x0204;
        public const uint GL_NOTEQUAL               = 0x0205;
        public const uint GL_GEQUAL             = 0x0206;
        public const uint GL_ALWAYS             = 0x0207;

        //  AttribMask
        public const uint GL_CURRENT_BIT            = 0x00000001;
        public const uint GL_POINT_BIT              = 0x00000002;
        public const uint GL_LINE_BIT               = 0x00000004;
        public const uint GL_POLYGON_BIT            = 0x00000008;
        public const uint GL_POLYGON_STIPPLE_BIT        = 0x00000010;
        public const uint GL_PIXEL_MODE_BIT         = 0x00000020;
        public const uint GL_LIGHTING_BIT           = 0x00000040;
        public const uint GL_FOG_BIT            = 0x00000080;
        public const uint GL_DEPTH_BUFFER_BIT           = 0x00000100;
        public const uint GL_ACCUM_BUFFER_BIT           = 0x00000200;
        public const uint GL_STENCIL_BUFFER_BIT         = 0x00000400;
        public const uint GL_VIEWPORT_BIT           = 0x00000800;
        public const uint GL_TRANSFORM_BIT          = 0x00001000;
        public const uint GL_ENABLE_BIT             = 0x00002000;
        public const uint GL_COLOR_BUFFER_BIT           = 0x00004000;
        public const uint GL_HINT_BIT               = 0x00008000;
        public const uint GL_EVAL_BIT               = 0x00010000;
        public const uint GL_LIST_BIT               = 0x00020000;
        public const uint GL_TEXTURE_BIT            = 0x00040000;
        public const uint GL_SCISSOR_BIT            = 0x00080000;
        public const uint GL_ALL_ATTRIB_BITS        = 0x000fffff;

        //  BeginMode
        public const uint GL_POINTS             = 0x0000;
        public const uint GL_LINES              = 0x0001;
        public const uint GL_LINE_LOOP              = 0x0002;
        public const uint GL_LINE_STRIP             = 0x0003;
        public const uint GL_TRIANGLES              = 0x0004;
        public const uint GL_TRIANGLE_STRIP         = 0x0005;
        public const uint GL_TRIANGLE_FAN           = 0x0006;
        public const uint GL_QUADS              = 0x0007;
        public const uint GL_QUAD_STRIP             = 0x0008;
        public const uint GL_POLYGON            = 0x0009;

        //  BlendingFactorDest
        public const uint GL_ZERO               = 0;
        public const uint GL_ONE                = 1;
        public const uint GL_SRC_COLOR              = 0x0300;
        public const uint GL_ONE_MINUS_SRC_COLOR        = 0x0301;
        public const uint GL_SRC_ALPHA              = 0x0302;
        public const uint GL_ONE_MINUS_SRC_ALPHA        = 0x0303;
        public const uint GL_DST_ALPHA              = 0x0304;
        public const uint GL_ONE_MINUS_DST_ALPHA        = 0x0305;

        //  BlendingFactorSrc
        public const uint GL_DST_COLOR              = 0x0306;
        public const uint GL_ONE_MINUS_DST_COLOR        = 0x0307;
        public const uint GL_SRC_ALPHA_SATURATE         = 0x0308;

        //   Boolean
        public const uint GL_TRUE               = 1;
        public const uint GL_FALSE              = 0;

        //   ClipPlaneName
        public const uint GL_CLIP_PLANE0            = 0x3000;
        public const uint GL_CLIP_PLANE1            = 0x3001;
        public const uint GL_CLIP_PLANE2            = 0x3002;
        public const uint GL_CLIP_PLANE3            = 0x3003;
        public const uint GL_CLIP_PLANE4            = 0x3004;
        public const uint GL_CLIP_PLANE5            = 0x3005;

        //   DataType
        public const uint GL_BYTE               = 0x1400;
        public const uint GL_UNSIGNED_BYTE          = 0x1401;
        public const uint GL_SHORT              = 0x1402;
        public const uint GL_UNSIGNED_SHORT         = 0x1403;
        public const uint GL_INT                = 0x1404;
        public const uint GL_UNSIGNED_INT           = 0x1405;
        public const uint GL_FLOAT              = 0x1406;
        public const uint GL_2_BYTES            = 0x1407;
        public const uint GL_3_BYTES            = 0x1408;
        public const uint GL_4_BYTES            = 0x1409;
        public const uint GL_DOUBLE             = 0x140A;

        //   DrawBufferMode
        public const uint GL_NONE               = 0;
        public const uint GL_FRONT_LEFT             = 0x0400;
        public const uint GL_FRONT_RIGHT            = 0x0401;
        public const uint GL_BACK_LEFT              = 0x0402;
        public const uint GL_BACK_RIGHT             = 0x0403;
        public const uint GL_FRONT              = 0x0404;
        public const uint GL_BACK               = 0x0405;
        public const uint GL_LEFT               = 0x0406;
        public const uint GL_RIGHT              = 0x0407;
        public const uint GL_FRONT_AND_BACK         = 0x0408;
        public const uint GL_AUX0               = 0x0409;
        public const uint GL_AUX1               = 0x040A;
        public const uint GL_AUX2               = 0x040B;
        public const uint GL_AUX3               = 0x040C;

        //   ErrorCode
        public const uint GL_NO_ERROR               = 0;
        public const uint GL_INVALID_ENUM           = 0x0500;
        public const uint GL_INVALID_VALUE          = 0x0501;
        public const uint GL_INVALID_OPERATION          = 0x0502;
        public const uint GL_STACK_OVERFLOW         = 0x0503;
        public const uint GL_STACK_UNDERFLOW        = 0x0504;
        public const uint GL_OUT_OF_MEMORY          = 0x0505;

        //   FeedBackMode
        public const uint GL_2D                 = 0x0600;
        public const uint GL_3D                 = 0x0601;
        public const uint GL_4D_COLOR               = 0x0602;
        public const uint GL_3D_COLOR_TEXTURE           = 0x0603;
        public const uint GL_4D_COLOR_TEXTURE           = 0x0604;

        //   FeedBackToken
        public const uint GL_PASS_THROUGH_TOKEN         = 0x0700;
        public const uint GL_POINT_TOKEN            = 0x0701;
        public const uint GL_LINE_TOKEN             = 0x0702;
        public const uint GL_POLYGON_TOKEN          = 0x0703;
        public const uint GL_BITMAP_TOKEN           = 0x0704;
        public const uint GL_DRAW_PIXEL_TOKEN           = 0x0705;
        public const uint GL_COPY_PIXEL_TOKEN           = 0x0706;
        public const uint GL_LINE_RESET_TOKEN           = 0x0707;

        //   FogMode
           public const uint GL_EXP                = 0x0800;
        public const uint GL_EXP2               = 0x0801;

        //   FrontFaceDirection
        public const uint GL_CW                 = 0x0900;
        public const uint GL_CCW                = 0x0901;

        //    GetMapTarget 
        public const uint GL_COEFF              = 0x0A00;
        public const uint GL_ORDER              = 0x0A01;
        public const uint GL_DOMAIN             = 0x0A02;

        //   GetTarget
        public const uint GL_CURRENT_COLOR          = 0x0B00;
        public const uint GL_CURRENT_INDEX          = 0x0B01;
        public const uint GL_CURRENT_NORMAL         = 0x0B02;
        public const uint GL_CURRENT_TEXTURE_COORDS     = 0x0B03;
        public const uint GL_CURRENT_RASTER_COLOR       = 0x0B04;
        public const uint GL_CURRENT_RASTER_INDEX       = 0x0B05;
        public const uint GL_CURRENT_RASTER_TEXTURE_COORDS  = 0x0B06;
        public const uint GL_CURRENT_RASTER_POSITION    = 0x0B07;
        public const uint GL_CURRENT_RASTER_POSITION_VALID  = 0x0B08;
        public const uint GL_CURRENT_RASTER_DISTANCE    = 0x0B09;
        public const uint GL_POINT_SMOOTH           = 0x0B10;
        public const uint GL_POINT_SIZE             = 0x0B11;
        public const uint GL_POINT_SIZE_RANGE           = 0x0B12;
        public const uint GL_POINT_SIZE_GRANULARITY     = 0x0B13;
        public const uint GL_LINE_SMOOTH            = 0x0B20;
        public const uint GL_LINE_WIDTH             = 0x0B21;
        public const uint GL_LINE_WIDTH_RANGE           = 0x0B22;
        public const uint GL_LINE_WIDTH_GRANULARITY     = 0x0B23;
        public const uint GL_LINE_STIPPLE           = 0x0B24;
        public const uint GL_LINE_STIPPLE_PATTERN       = 0x0B25;
        public const uint GL_LINE_STIPPLE_REPEAT        = 0x0B26;
        public const uint GL_LIST_MODE              = 0x0B30;
        public const uint GL_MAX_LIST_NESTING           = 0x0B31;
        public const uint GL_LIST_BASE              = 0x0B32;
        public const uint GL_LIST_INDEX             = 0x0B33;
        public const uint GL_POLYGON_MODE           = 0x0B40;
        public const uint GL_POLYGON_SMOOTH         = 0x0B41;
        public const uint GL_POLYGON_STIPPLE        = 0x0B42;
        public const uint GL_EDGE_FLAG              = 0x0B43;
        public const uint GL_CULL_FACE              = 0x0B44;
        public const uint GL_CULL_FACE_MODE         = 0x0B45;
        public const uint GL_FRONT_FACE             = 0x0B46;
        public const uint GL_LIGHTING               = 0x0B50;
        public const uint GL_LIGHT_MODEL_LOCAL_VIEWER       = 0x0B51;
        public const uint GL_LIGHT_MODEL_TWO_SIDE       = 0x0B52;
        public const uint GL_LIGHT_MODEL_AMBIENT        = 0x0B53;
        public const uint GL_SHADE_MODEL            = 0x0B54;
        public const uint GL_COLOR_MATERIAL_FACE        = 0x0B55;
        public const uint GL_COLOR_MATERIAL_PARAMETER       = 0x0B56;
        public const uint GL_COLOR_MATERIAL         = 0x0B57;
        public const uint GL_FOG                = 0x0B60;
        public const uint GL_FOG_INDEX              = 0x0B61;
        public const uint GL_FOG_DENSITY            = 0x0B62;
        public const uint GL_FOG_START              = 0x0B63;
        public const uint GL_FOG_END            = 0x0B64;
        public const uint GL_FOG_MODE               = 0x0B65;
        public const uint GL_FOG_COLOR              = 0x0B66;
        public const uint GL_DEPTH_RANGE            = 0x0B70;
        public const uint GL_DEPTH_TEST             = 0x0B71;
        public const uint GL_DEPTH_WRITEMASK        = 0x0B72;
        public const uint GL_DEPTH_CLEAR_VALUE          = 0x0B73;
        public const uint GL_DEPTH_FUNC             = 0x0B74;
        public const uint GL_ACCUM_CLEAR_VALUE          = 0x0B80;
        public const uint GL_STENCIL_TEST           = 0x0B90;
        public const uint GL_STENCIL_CLEAR_VALUE        = 0x0B91;
        public const uint GL_STENCIL_FUNC           = 0x0B92;
        public const uint GL_STENCIL_VALUE_MASK         = 0x0B93;
        public const uint GL_STENCIL_FAIL           = 0x0B94;
        public const uint GL_STENCIL_PASS_DEPTH_FAIL    = 0x0B95;
        public const uint GL_STENCIL_PASS_DEPTH_PASS    = 0x0B96;
        public const uint GL_STENCIL_REF            = 0x0B97;
        public const uint GL_STENCIL_WRITEMASK          = 0x0B98;
        public const uint GL_MATRIX_MODE            = 0x0BA0;
        public const uint GL_NORMALIZE              = 0x0BA1;
        public const uint GL_VIEWPORT               = 0x0BA2;
        public const uint GL_MODELVIEW_STACK_DEPTH      = 0x0BA3;
        public const uint GL_PROJECTION_STACK_DEPTH     = 0x0BA4;
        public const uint GL_TEXTURE_STACK_DEPTH        = 0x0BA5;
        public const uint GL_MODELVIEW_MATRIX           = 0x0BA6;
        public const uint GL_PROJECTION_MATRIX          = 0x0BA7;
        public const uint GL_TEXTURE_MATRIX         = 0x0BA8;
        public const uint GL_ATTRIB_STACK_DEPTH         = 0x0BB0;
        public const uint GL_CLIENT_ATTRIB_STACK_DEPTH      = 0x0BB1;
        public const uint GL_ALPHA_TEST             = 0x0BC0;
        public const uint GL_ALPHA_TEST_FUNC        = 0x0BC1;
        public const uint GL_ALPHA_TEST_REF         = 0x0BC2;
        public const uint GL_DITHER             = 0x0BD0;
        public const uint GL_BLEND_DST              = 0x0BE0;
        public const uint GL_BLEND_SRC              = 0x0BE1;
        public const uint GL_BLEND              = 0x0BE2;
        public const uint GL_LOGIC_OP_MODE          = 0x0BF0;
        public const uint GL_INDEX_LOGIC_OP         = 0x0BF1;
        public const uint GL_COLOR_LOGIC_OP         = 0x0BF2;
        public const uint GL_AUX_BUFFERS            = 0x0C00;
        public const uint GL_DRAW_BUFFER            = 0x0C01;
        public const uint GL_READ_BUFFER            = 0x0C02;
        public const uint GL_SCISSOR_BOX            = 0x0C10;
        public const uint GL_SCISSOR_TEST           = 0x0C11;
        public const uint GL_INDEX_CLEAR_VALUE          = 0x0C20;
        public const uint GL_INDEX_WRITEMASK        = 0x0C21;
        public const uint GL_COLOR_CLEAR_VALUE          = 0x0C22;
        public const uint GL_COLOR_WRITEMASK        = 0x0C23;
        public const uint GL_INDEX_MODE             = 0x0C30;
        public const uint GL_RGBA_MODE              = 0x0C31;
        public const uint GL_DOUBLEBUFFER           = 0x0C32;
        public const uint GL_STEREO             = 0x0C33;
        public const uint GL_RENDER_MODE            = 0x0C40;
        public const uint GL_PERSPECTIVE_CORRECTION_HINT    = 0x0C50;
        public const uint GL_POINT_SMOOTH_HINT          = 0x0C51;
        public const uint GL_LINE_SMOOTH_HINT           = 0x0C52;
        public const uint GL_POLYGON_SMOOTH_HINT        = 0x0C53;
        public const uint GL_FOG_HINT               = 0x0C54;
        public const uint GL_TEXTURE_GEN_S          = 0x0C60;
        public const uint GL_TEXTURE_GEN_T          = 0x0C61;
        public const uint GL_TEXTURE_GEN_R          = 0x0C62;
        public const uint GL_TEXTURE_GEN_Q          = 0x0C63;
        public const uint GL_PIXEL_MAP_I_TO_I           = 0x0C70;
        public const uint GL_PIXEL_MAP_S_TO_S           = 0x0C71;
        public const uint GL_PIXEL_MAP_I_TO_R           = 0x0C72;
        public const uint GL_PIXEL_MAP_I_TO_G           = 0x0C73;
        public const uint GL_PIXEL_MAP_I_TO_B           = 0x0C74;
        public const uint GL_PIXEL_MAP_I_TO_A           = 0x0C75;
        public const uint GL_PIXEL_MAP_R_TO_R           = 0x0C76;
        public const uint GL_PIXEL_MAP_G_TO_G           = 0x0C77;
        public const uint GL_PIXEL_MAP_B_TO_B           = 0x0C78;
        public const uint GL_PIXEL_MAP_A_TO_A           = 0x0C79;
        public const uint GL_PIXEL_MAP_I_TO_I_SIZE      = 0x0CB0;
        public const uint GL_PIXEL_MAP_S_TO_S_SIZE      = 0x0CB1;
        public const uint GL_PIXEL_MAP_I_TO_R_SIZE      = 0x0CB2;
        public const uint GL_PIXEL_MAP_I_TO_G_SIZE      = 0x0CB3;
        public const uint GL_PIXEL_MAP_I_TO_B_SIZE      = 0x0CB4;
        public const uint GL_PIXEL_MAP_I_TO_A_SIZE      = 0x0CB5;
        public const uint GL_PIXEL_MAP_R_TO_R_SIZE      = 0x0CB6;
        public const uint GL_PIXEL_MAP_G_TO_G_SIZE      = 0x0CB7;
        public const uint GL_PIXEL_MAP_B_TO_B_SIZE      = 0x0CB8;
        public const uint GL_PIXEL_MAP_A_TO_A_SIZE      = 0x0CB9;
        public const uint GL_UNPACK_SWAP_BYTES          = 0x0CF0;
        public const uint GL_UNPACK_LSB_FIRST           = 0x0CF1;
        public const uint GL_UNPACK_ROW_LENGTH          = 0x0CF2;
        public const uint GL_UNPACK_SKIP_ROWS           = 0x0CF3;
        public const uint GL_UNPACK_SKIP_PIXELS         = 0x0CF4;
        public const uint GL_UNPACK_ALIGNMENT           = 0x0CF5;
        public const uint GL_PACK_SWAP_BYTES        = 0x0D00;
        public const uint GL_PACK_LSB_FIRST         = 0x0D01;
        public const uint GL_PACK_ROW_LENGTH        = 0x0D02;
        public const uint GL_PACK_SKIP_ROWS         = 0x0D03;
        public const uint GL_PACK_SKIP_PIXELS           = 0x0D04;
        public const uint GL_PACK_ALIGNMENT         = 0x0D05;
        public const uint GL_MAP_COLOR              = 0x0D10;
        public const uint GL_MAP_STENCIL            = 0x0D11;
        public const uint GL_INDEX_SHIFT            = 0x0D12;
        public const uint GL_INDEX_OFFSET           = 0x0D13;
        public const uint GL_RED_SCALE              = 0x0D14;
        public const uint GL_RED_BIAS               = 0x0D15;
        public const uint GL_ZOOM_X             = 0x0D16;
        public const uint GL_ZOOM_Y             = 0x0D17;
        public const uint GL_GREEN_SCALE            = 0x0D18;
        public const uint GL_GREEN_BIAS             = 0x0D19;
        public const uint GL_BLUE_SCALE             = 0x0D1A;
        public const uint GL_BLUE_BIAS              = 0x0D1B;
        public const uint GL_ALPHA_SCALE            = 0x0D1C;
        public const uint GL_ALPHA_BIAS             = 0x0D1D;
        public const uint GL_DEPTH_SCALE            = 0x0D1E;
        public const uint GL_DEPTH_BIAS             = 0x0D1F;
        public const uint GL_MAX_EVAL_ORDER         = 0x0D30;
        public const uint GL_MAX_LIGHTS             = 0x0D31;
        public const uint GL_MAX_CLIP_PLANES        = 0x0D32;
        public const uint GL_MAX_TEXTURE_SIZE           = 0x0D33;
        public const uint GL_MAX_PIXEL_MAP_TABLE        = 0x0D34;
        public const uint GL_MAX_ATTRIB_STACK_DEPTH     = 0x0D35;
        public const uint GL_MAX_MODELVIEW_STACK_DEPTH      = 0x0D36;
        public const uint GL_MAX_NAME_STACK_DEPTH       = 0x0D37;
        public const uint GL_MAX_PROJECTION_STACK_DEPTH     = 0x0D38;
        public const uint GL_MAX_TEXTURE_STACK_DEPTH    = 0x0D39;
        public const uint GL_MAX_VIEWPORT_DIMS          = 0x0D3A;
        public const uint GL_MAX_CLIENT_ATTRIB_STACK_DEPTH  = 0x0D3B;
        public const uint GL_SUBPIXEL_BITS          = 0x0D50;
        public const uint GL_INDEX_BITS             = 0x0D51;
        public const uint GL_RED_BITS               = 0x0D52;
        public const uint GL_GREEN_BITS             = 0x0D53;
        public const uint GL_BLUE_BITS              = 0x0D54;
        public const uint GL_ALPHA_BITS             = 0x0D55;
        public const uint GL_DEPTH_BITS             = 0x0D56;
        public const uint GL_STENCIL_BITS           = 0x0D57;
        public const uint GL_ACCUM_RED_BITS         = 0x0D58;
        public const uint GL_ACCUM_GREEN_BITS           = 0x0D59;
        public const uint GL_ACCUM_BLUE_BITS        = 0x0D5A;
        public const uint GL_ACCUM_ALPHA_BITS           = 0x0D5B;
        public const uint GL_NAME_STACK_DEPTH           = 0x0D70;
        public const uint GL_AUTO_NORMAL            = 0x0D80;
        public const uint GL_MAP1_COLOR_4           = 0x0D90;
        public const uint GL_MAP1_INDEX             = 0x0D91;
        public const uint GL_MAP1_NORMAL            = 0x0D92;
        public const uint GL_MAP1_TEXTURE_COORD_1       = 0x0D93;
        public const uint GL_MAP1_TEXTURE_COORD_2       = 0x0D94;
        public const uint GL_MAP1_TEXTURE_COORD_3       = 0x0D95;
        public const uint GL_MAP1_TEXTURE_COORD_4       = 0x0D96;
        public const uint GL_MAP1_VERTEX_3          = 0x0D97;
        public const uint GL_MAP1_VERTEX_4          = 0x0D98;
        public const uint GL_MAP2_COLOR_4           = 0x0DB0;
        public const uint GL_MAP2_INDEX             = 0x0DB1;
        public const uint GL_MAP2_NORMAL            = 0x0DB2;
        public const uint GL_MAP2_TEXTURE_COORD_1       = 0x0DB3;
        public const uint GL_MAP2_TEXTURE_COORD_2       = 0x0DB4;
        public const uint GL_MAP2_TEXTURE_COORD_3       = 0x0DB5;
        public const uint GL_MAP2_TEXTURE_COORD_4       = 0x0DB6;
        public const uint GL_MAP2_VERTEX_3          = 0x0DB7;
        public const uint GL_MAP2_VERTEX_4          = 0x0DB8;
        public const uint GL_MAP1_GRID_DOMAIN           = 0x0DD0;
        public const uint GL_MAP1_GRID_SEGMENTS         = 0x0DD1;
        public const uint GL_MAP2_GRID_DOMAIN           = 0x0DD2;
        public const uint GL_MAP2_GRID_SEGMENTS         = 0x0DD3;
        public const uint GL_TEXTURE_1D             = 0x0DE0;
        public const uint GL_TEXTURE_2D             = 0x0DE1;
        public const uint GL_FEEDBACK_BUFFER_POINTER    = 0x0DF0;
        public const uint GL_FEEDBACK_BUFFER_SIZE       = 0x0DF1;
        public const uint GL_FEEDBACK_BUFFER_TYPE       = 0x0DF2;
        public const uint GL_SELECTION_BUFFER_POINTER       = 0x0DF3;
        public const uint GL_SELECTION_BUFFER_SIZE      = 0x0DF4;

        //   GetTextureParameter
        public const uint GL_TEXTURE_WIDTH          = 0x1000;
        public const uint GL_TEXTURE_HEIGHT         = 0x1001;
        public const uint GL_TEXTURE_INTERNAL_FORMAT    = 0x1003;
        public const uint GL_TEXTURE_BORDER_COLOR       = 0x1004;
        public const uint GL_TEXTURE_BORDER         = 0x1005;

        //   HintMode
        public const uint GL_DONT_CARE              = 0x1100;
        public const uint GL_FASTEST            = 0x1101;
        public const uint GL_NICEST             = 0x1102;

        //   LightName
        public const uint GL_LIGHT0             = 0x4000;
        public const uint GL_LIGHT1             = 0x4001;
        public const uint GL_LIGHT2             = 0x4002;
        public const uint GL_LIGHT3             = 0x4003;
        public const uint GL_LIGHT4             = 0x4004;
        public const uint GL_LIGHT5             = 0x4005;
        public const uint GL_LIGHT6             = 0x4006;
        public const uint GL_LIGHT7             = 0x4007;

        //   LightParameter
        public const uint GL_AMBIENT            = 0x1200;
        public const uint GL_DIFFUSE            = 0x1201;
        public const uint GL_SPECULAR               = 0x1202;
        public const uint GL_POSITION               = 0x1203;
        public const uint GL_SPOT_DIRECTION         = 0x1204;
        public const uint GL_SPOT_EXPONENT          = 0x1205;
        public const uint GL_SPOT_CUTOFF            = 0x1206;
        public const uint GL_CONSTANT_ATTENUATION       = 0x1207;
        public const uint GL_LINEAR_ATTENUATION         = 0x1208;
        public const uint GL_QUADRATIC_ATTENUATION      = 0x1209;

        //   ListMode
        public const uint GL_COMPILE            = 0x1300;
        public const uint GL_COMPILE_AND_EXECUTE        = 0x1301;

        //   LogicOp
        public const uint GL_CLEAR              = 0x1500;
        public const uint GL_AND                = 0x1501;
        public const uint GL_AND_REVERSE            = 0x1502;
        public const uint GL_COPY               = 0x1503;
        public const uint GL_AND_INVERTED           = 0x1504;
        public const uint GL_NOOP               = 0x1505;
        public const uint GL_XOR                = 0x1506;
        public const uint GL_OR                 = 0x1507;
        public const uint GL_NOR                = 0x1508;
        public const uint GL_EQUIV              = 0x1509;
        public const uint GL_INVERT             = 0x150A;
        public const uint GL_OR_REVERSE             = 0x150B;
        public const uint GL_COPY_INVERTED          = 0x150C;
        public const uint GL_OR_INVERTED            = 0x150D;
        public const uint GL_NAND               = 0x150E;
        public const uint GL_SET                = 0x150F;

        //   MaterialParameter
        public const uint GL_EMISSION               = 0x1600;
        public const uint GL_SHININESS              = 0x1601;
        public const uint GL_AMBIENT_AND_DIFFUSE        = 0x1602;
        public const uint GL_COLOR_INDEXES          = 0x1603;

        //   MatrixMode
        public const uint GL_MODELVIEW              = 0x1700;
        public const uint GL_PROJECTION             = 0x1701;
        public const uint GL_TEXTURE            = 0x1702;

        //   PixelCopyType
        public const uint GL_COLOR              = 0x1800;
        public const uint GL_DEPTH              = 0x1801;
        public const uint GL_STENCIL            = 0x1802;

        //   PixelFormat
        public const uint GL_COLOR_INDEX            = 0x1900;
        public const uint GL_STENCIL_INDEX          = 0x1901;
        public const uint GL_DEPTH_COMPONENT        = 0x1902;
        public const uint GL_RED                = 0x1903;
        public const uint GL_GREEN              = 0x1904;
        public const uint GL_BLUE               = 0x1905;
        public const uint GL_ALPHA              = 0x1906;
        public const uint GL_RGB                = 0x1907;
        public const uint GL_RGBA               = 0x1908;
        public const uint GL_LUMINANCE              = 0x1909;
        public const uint GL_LUMINANCE_ALPHA        = 0x190A;

        //   PixelType
        public const uint GL_BITMAP             = 0x1A00;

        //   PolygonMode
        public const uint GL_POINT              = 0x1B00;
        public const uint GL_LINE               = 0x1B01;
        public const uint GL_FILL               = 0x1B02;

        //   RenderingMode 
        public const uint GL_RENDER             = 0x1C00;
        public const uint GL_FEEDBACK               = 0x1C01;
        public const uint GL_SELECT             = 0x1C02;

        //   ShadingModel
        public const uint GL_FLAT               = 0x1D00;
        public const uint GL_SMOOTH             = 0x1D01;

        //   StencilOp    
        public const uint GL_KEEP               = 0x1E00;
        public const uint GL_REPLACE            = 0x1E01;
        public const uint GL_INCR               = 0x1E02;
        public const uint GL_DECR               = 0x1E03;

        //   StringName
        public const uint GL_VENDOR             = 0x1F00;
        public const uint GL_RENDERER               = 0x1F01;
        public const uint GL_VERSION            = 0x1F02;
        public const uint GL_EXTENSIONS             = 0x1F03;

        //   TextureCoordName
        public const uint GL_S                  = 0x2000;
        public const uint GL_T                  = 0x2001;
        public const uint GL_R                  = 0x2002;
        public const uint GL_Q                  = 0x2003;

        //   TextureEnvMode
        public const uint GL_MODULATE               = 0x2100;
        public const uint GL_DECAL              = 0x2101;

        //   TextureEnvParameter
        public const uint GL_TEXTURE_ENV_MODE           = 0x2200;
        public const uint GL_TEXTURE_ENV_COLOR          = 0x2201;

        //   TextureEnvTarget
        public const uint GL_TEXTURE_ENV            = 0x2300;

        //   TextureGenMode 
        public const uint GL_EYE_LINEAR             = 0x2400;
        public const uint GL_OBJECT_LINEAR          = 0x2401;
        public const uint GL_SPHERE_MAP             = 0x2402;

        //   TextureGenParameter
        public const uint GL_TEXTURE_GEN_MODE           = 0x2500;
        public const uint GL_OBJECT_PLANE           = 0x2501;
        public const uint GL_EYE_PLANE              = 0x2502;

        //   TextureMagFilter
        public const uint GL_NEAREST            = 0x2600;
        public const uint GL_LINEAR             = 0x2601;

        //   TextureMinFilter 
        public const uint GL_NEAREST_MIPMAP_NEAREST     = 0x2700;
        public const uint GL_LINEAR_MIPMAP_NEAREST      = 0x2701;
        public const uint GL_NEAREST_MIPMAP_LINEAR      = 0x2702;
        public const uint GL_LINEAR_MIPMAP_LINEAR       = 0x2703;

        //   TextureParameterName
        public const uint GL_TEXTURE_MAG_FILTER         = 0x2800;
        public const uint GL_TEXTURE_MIN_FILTER         = 0x2801;
        public const uint GL_TEXTURE_WRAP_S         = 0x2802;
        public const uint GL_TEXTURE_WRAP_T         = 0x2803;

        //   TextureWrapMode
        public const uint GL_CLAMP              = 0x2900;
        public const uint GL_REPEAT             = 0x2901;

        //   ClientAttribMask
        public const uint GL_CLIENT_PIXEL_STORE_BIT     = 0x00000001;
        public const uint GL_CLIENT_VERTEX_ARRAY_BIT    = 0x00000002;
        public const uint GL_CLIENT_ALL_ATTRIB_BITS     = 0xffffffff;

        //   Polygon Offset
        public const uint GL_POLYGON_OFFSET_FACTOR      = 0x8038;
        public const uint GL_POLYGON_OFFSET_UNITS       = 0x2A00;
        public const uint GL_POLYGON_OFFSET_POINT       = 0x2A01;
        public const uint GL_POLYGON_OFFSET_LINE        = 0x2A02;
        public const uint GL_POLYGON_OFFSET_FILL        = 0x8037;

        //   Texture 
        public const uint GL_ALPHA4             = 0x803B;
        public const uint GL_ALPHA8             = 0x803C;
        public const uint GL_ALPHA12            = 0x803D;
        public const uint GL_ALPHA16            = 0x803E;
        public const uint GL_LUMINANCE4             = 0x803F;
        public const uint GL_LUMINANCE8             = 0x8040;
        public const uint GL_LUMINANCE12            = 0x8041;
        public const uint GL_LUMINANCE16            = 0x8042;
        public const uint GL_LUMINANCE4_ALPHA4          = 0x8043;
        public const uint GL_LUMINANCE6_ALPHA2          = 0x8044;
        public const uint GL_LUMINANCE8_ALPHA8          = 0x8045;
        public const uint GL_LUMINANCE12_ALPHA4         = 0x8046;
        public const uint GL_LUMINANCE12_ALPHA12        = 0x8047;
        public const uint GL_LUMINANCE16_ALPHA16        = 0x8048;
        public const uint GL_INTENSITY              = 0x8049;
        public const uint GL_INTENSITY4             = 0x804A;
        public const uint GL_INTENSITY8             = 0x804B;
        public const uint GL_INTENSITY12            = 0x804C;
        public const uint GL_INTENSITY16            = 0x804D;
        public const uint GL_R3_G3_B2               = 0x2A10;
        public const uint GL_RGB4               = 0x804F;
        public const uint GL_RGB5               = 0x8050;
        public const uint GL_RGB8               = 0x8051;
        public const uint GL_RGB10              = 0x8052;
        public const uint GL_RGB12              = 0x8053;
        public const uint GL_RGB16              = 0x8054;
        public const uint GL_RGBA2              = 0x8055;
        public const uint GL_RGBA4              = 0x8056;
        public const uint GL_RGB5_A1            = 0x8057;
        public const uint GL_RGBA8              = 0x8058;
        public const uint GL_RGB10_A2               = 0x8059;
        public const uint GL_RGBA12             = 0x805A;
        public const uint GL_RGBA16             = 0x805B;
        public const uint GL_TEXTURE_RED_SIZE           = 0x805C;
        public const uint GL_TEXTURE_GREEN_SIZE         = 0x805D;
        public const uint GL_TEXTURE_BLUE_SIZE          = 0x805E;
        public const uint GL_TEXTURE_ALPHA_SIZE         = 0x805F;
        public const uint GL_TEXTURE_LUMINANCE_SIZE     = 0x8060;
        public const uint GL_TEXTURE_INTENSITY_SIZE     = 0x8061;
        public const uint GL_PROXY_TEXTURE_1D           = 0x8063;
        public const uint GL_PROXY_TEXTURE_2D           = 0x8064;

        //   Texture object
        public const uint GL_TEXTURE_PRIORITY           = 0x8066;
        public const uint GL_TEXTURE_RESIDENT           = 0x8067;
        public const uint GL_TEXTURE_BINDING_1D         = 0x8068;
        public const uint GL_TEXTURE_BINDING_2D         = 0x8069;

        //   Vertex array
        public const uint GL_VERTEX_ARRAY           = 0x8074;
        public const uint GL_NORMAL_ARRAY           = 0x8075;
        public const uint GL_COLOR_ARRAY            = 0x8076;
        public const uint GL_INDEX_ARRAY            = 0x8077;
        public const uint GL_TEXTURE_COORD_ARRAY        = 0x8078;
        public const uint GL_EDGE_FLAG_ARRAY        = 0x8079;
        public const uint GL_VERTEX_ARRAY_SIZE          = 0x807A;
        public const uint GL_VERTEX_ARRAY_TYPE          = 0x807B;
        public const uint GL_VERTEX_ARRAY_STRIDE        = 0x807C;
        public const uint GL_NORMAL_ARRAY_TYPE          = 0x807E;
        public const uint GL_NORMAL_ARRAY_STRIDE        = 0x807F;
        public const uint GL_COLOR_ARRAY_SIZE           = 0x8081;
        public const uint GL_COLOR_ARRAY_TYPE           = 0x8082;
        public const uint GL_COLOR_ARRAY_STRIDE         = 0x8083;
        public const uint GL_INDEX_ARRAY_TYPE           = 0x8085;
        public const uint GL_INDEX_ARRAY_STRIDE         = 0x8086;
        public const uint GL_TEXTURE_COORD_ARRAY_SIZE       = 0x8088;
        public const uint GL_TEXTURE_COORD_ARRAY_TYPE       = 0x8089;
        public const uint GL_TEXTURE_COORD_ARRAY_STRIDE     = 0x808A;
        public const uint GL_EDGE_FLAG_ARRAY_STRIDE     = 0x808C;
        public const uint GL_VERTEX_ARRAY_POINTER       = 0x808E;
        public const uint GL_NORMAL_ARRAY_POINTER       = 0x808F;
        public const uint GL_COLOR_ARRAY_POINTER        = 0x8090;
        public const uint GL_INDEX_ARRAY_POINTER        = 0x8091;
        public const uint GL_TEXTURE_COORD_ARRAY_POINTER    = 0x8092;
        public const uint GL_EDGE_FLAG_ARRAY_POINTER    = 0x8093;
        public const uint GL_V2F                = 0x2A20;
        public const uint GL_V3F                = 0x2A21;
        public const uint GL_C4UB_V2F               = 0x2A22;
        public const uint GL_C4UB_V3F               = 0x2A23;
        public const uint GL_C3F_V3F            = 0x2A24;
        public const uint GL_N3F_V3F            = 0x2A25;
        public const uint GL_C4F_N3F_V3F            = 0x2A26;
        public const uint GL_T2F_V3F            = 0x2A27;
        public const uint GL_T4F_V4F            = 0x2A28;
        public const uint GL_T2F_C4UB_V3F           = 0x2A29;
        public const uint GL_T2F_C3F_V3F            = 0x2A2A;
        public const uint GL_T2F_N3F_V3F            = 0x2A2B;
        public const uint GL_T2F_C4F_N3F_V3F        = 0x2A2C;
        public const uint GL_T4F_C4F_N3F_V4F        = 0x2A2D;

    //   Extensions
        public const uint GL_EXT_vertex_array           = 1;
        public const uint GL_EXT_bgra               = 1;
        public const uint GL_EXT_paletted_texture       = 1;
        public const uint GL_WIN_swap_hint          = 1;
        public const uint GL_WIN_draw_range_elements    = 1;

    //   EXT_vertex_array 
        public const uint GL_VERTEX_ARRAY_EXT           = 0x8074;
        public const uint GL_NORMAL_ARRAY_EXT           = 0x8075;
        public const uint GL_COLOR_ARRAY_EXT        = 0x8076;
        public const uint GL_INDEX_ARRAY_EXT        = 0x8077;
        public const uint GL_TEXTURE_COORD_ARRAY_EXT    = 0x8078;
        public const uint GL_EDGE_FLAG_ARRAY_EXT        = 0x8079;
        public const uint GL_VERTEX_ARRAY_SIZE_EXT      = 0x807A;
        public const uint GL_VERTEX_ARRAY_TYPE_EXT      = 0x807B;
        public const uint GL_VERTEX_ARRAY_STRIDE_EXT    = 0x807C;
        public const uint GL_VERTEX_ARRAY_COUNT_EXT     = 0x807D;
        public const uint GL_NORMAL_ARRAY_TYPE_EXT      = 0x807E;
        public const uint GL_NORMAL_ARRAY_STRIDE_EXT    = 0x807F;
        public const uint GL_NORMAL_ARRAY_COUNT_EXT     = 0x8080;
        public const uint GL_COLOR_ARRAY_SIZE_EXT       = 0x8081;
        public const uint GL_COLOR_ARRAY_TYPE_EXT       = 0x8082;
        public const uint GL_COLOR_ARRAY_STRIDE_EXT     = 0x8083;
        public const uint GL_COLOR_ARRAY_COUNT_EXT      = 0x8084;
        public const uint GL_INDEX_ARRAY_TYPE_EXT       = 0x8085;
        public const uint GL_INDEX_ARRAY_STRIDE_EXT     = 0x8086;
        public const uint GL_INDEX_ARRAY_COUNT_EXT      = 0x8087;
        public const uint GL_TEXTURE_COORD_ARRAY_SIZE_EXT   = 0x8088;
        public const uint GL_TEXTURE_COORD_ARRAY_TYPE_EXT   = 0x8089;
        public const uint GL_TEXTURE_COORD_ARRAY_STRIDE_EXT = 0x808A;
        public const uint GL_TEXTURE_COORD_ARRAY_COUNT_EXT  = 0x808B;
        public const uint GL_EDGE_FLAG_ARRAY_STRIDE_EXT     = 0x808C;
        public const uint GL_EDGE_FLAG_ARRAY_COUNT_EXT      = 0x808D;
        public const uint GL_VERTEX_ARRAY_POINTER_EXT       = 0x808E;
        public const uint GL_NORMAL_ARRAY_POINTER_EXT       = 0x808F;
        public const uint GL_COLOR_ARRAY_POINTER_EXT    = 0x8090;
        public const uint GL_INDEX_ARRAY_POINTER_EXT    = 0x8091;
        public const uint GL_TEXTURE_COORD_ARRAY_POINTER_EXT = 0x8092;
        public const uint GL_EDGE_FLAG_ARRAY_POINTER_EXT    = 0x8093;
        public const uint GL_DOUBLE_EXT             =1;/*DOUBLE*/

    //   EXT_paletted_texture
        public const uint GL_COLOR_TABLE_FORMAT_EXT     = 0x80D8;
        public const uint GL_COLOR_TABLE_WIDTH_EXT      = 0x80D9;
        public const uint GL_COLOR_TABLE_RED_SIZE_EXT       = 0x80DA;
        public const uint GL_COLOR_TABLE_GREEN_SIZE_EXT     = 0x80DB;
        public const uint GL_COLOR_TABLE_BLUE_SIZE_EXT      = 0x80DC;
        public const uint GL_COLOR_TABLE_ALPHA_SIZE_EXT     = 0x80DD;
        public const uint GL_COLOR_TABLE_LUMINANCE_SIZE_EXT = 0x80DE;
        public const uint GL_COLOR_TABLE_INTENSITY_SIZE_EXT = 0x80DF;
        public const uint GL_COLOR_INDEX1_EXT           = 0x80E2;
        public const uint GL_COLOR_INDEX2_EXT           = 0x80E3;
        public const uint GL_COLOR_INDEX4_EXT           = 0x80E4;
        public const uint GL_COLOR_INDEX8_EXT           = 0x80E5;
        public const uint GL_COLOR_INDEX12_EXT          = 0x80E6;
        public const uint GL_COLOR_INDEX16_EXT          = 0x80E7;

    //   WIN_draw_range_elements
        public const uint GL_MAX_ELEMENTS_VERTICES_WIN      = 0x80E8;
        public const uint GL_MAX_ELEMENTS_INDICES_WIN       = 0x80E9;

    //   WIN_phong_shading
        public const uint GL_PHONG_WIN              = 0x80EA;
        public const uint GL_PHONG_HINT_WIN         = 0x80EB; 
    //   WIN_specular_fog 
        public  uint FOG_SPECULAR_TEXTURE_WIN       = 0x80EC;

    #endregion

#region The OpenGL DLL Functions (Exactly the same naming).

    public const string LIBRARY_OPENGL = "opengl32";

        [DllImport(LIBRARY_OPENGL)] public static extern void glAccum (uint op, float value);
        [DllImport(LIBRARY_OPENGL)] public static extern void glAlphaFunc (uint func, float ref_notkeword);
        [DllImport(LIBRARY_OPENGL)] public static extern byte glAreTexturesResident (int n,  uint []textures, byte []residences);
        [DllImport(LIBRARY_OPENGL)] public static extern void glArrayElement (int i);
        [DllImport(LIBRARY_OPENGL)] public static extern void glBegin (uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glBindTexture (uint target, uint texture);
        [DllImport(LIBRARY_OPENGL)] public static extern void glBitmap (int width, int height, float xorig, float yorig, float xmove, float ymove,  byte []bitmap);
        [DllImport(LIBRARY_OPENGL)] public static extern void glBlendFunc (uint sfactor, uint dfactor);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCallList (uint list);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCallLists (int n, uint type,  IntPtr lists);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCallLists (int n, uint type,  uint[] lists);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCallLists (int n, uint type,  byte[] lists);
        [DllImport(LIBRARY_OPENGL)] public static extern void glClear (uint mask);
        [DllImport(LIBRARY_OPENGL)] public static extern void glClearAccum (float red, float green, float blue, float alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glClearColor (float red, float green, float blue, float alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glClearDepth (double depth);
        [DllImport(LIBRARY_OPENGL)] public static extern void glClearIndex (float c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glClearStencil (int s);
        [DllImport(LIBRARY_OPENGL)] public static extern void glClipPlane (uint plane,  double []equation);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3b (byte red, byte green, byte blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3bv ( byte []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3d (double red, double green, double blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3f (float red, float green, float blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3i (int red, int green, int blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3s (short red, short green, short blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3ub (byte red, byte green, byte blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3ubv ( byte []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3ui (uint red, uint green, uint blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3uiv ( uint []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3us (ushort red, ushort green, ushort blue);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor3usv ( ushort []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4b (byte red, byte green, byte blue, byte alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4bv ( byte []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4d (double red, double green, double blue, double alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4f (float red, float green, float blue, float alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4i (int red, int green, int blue, int alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4s (short red, short green, short blue, short alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4ub (byte red, byte green, byte blue, byte alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4ubv ( byte []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4ui (uint red, uint green, uint blue, uint alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4uiv ( uint []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4us (ushort red, ushort green, ushort blue, ushort alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColor4usv ( ushort []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColorMask (byte red, byte green, byte blue, byte alpha);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColorMaterial (uint face, uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glColorPointer (int size, uint type, int stride,  int[] pointer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCopyPixels (int x, int y, int width, int height, uint type);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCopyTexImage1D (uint target, int level, uint internalFormat, int x, int y, int width, int border);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCopyTexImage2D (uint target, int level, uint internalFormat, int x, int y, int width, int height, int border);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCopyTexSubImage1D (uint target, int level, int xoffset, int x, int y, int width);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCopyTexSubImage2D (uint target, int level, int xoffset, int yoffset, int x, int y, int width, int height);
        [DllImport(LIBRARY_OPENGL)] public static extern void glCullFace (uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDeleteLists (uint list, int range);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDeleteTextures (int n,  uint []textures);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDepthFunc (uint func);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDepthMask (byte flag);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDepthRange (double zNear, double zFar);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDisable (uint cap);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDisableClientState (uint array);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDrawArrays (uint mode, int first, int count);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDrawBuffer (uint mode);
        [DllImport(LIBRARY_OPENGL)] public unsafe static extern void glDrawElements (uint mode, int count, uint type,  void* indices);
        [DllImport(LIBRARY_OPENGL)] public static extern void glDrawPixels(int width, int height, uint format, uint type,  float[] pixels);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEdgeFlag (byte flag);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEdgeFlagPointer (int stride,  int[] pointer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEdgeFlagv ( byte []flag);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEnable (uint cap);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEnableClientState (uint array);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEnd ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glEndList ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord1d (double u);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord1dv ( double []u);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord1f (float u);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord1fv ( float []u);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord2d (double u, double v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord2dv ( double []u);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord2f (float u, float v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalCoord2fv ( float []u);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalMesh1 (uint mode, int i1, int i2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalMesh2 (uint mode, int i1, int i2, int j1, int j2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalPoint1 (int i);
        [DllImport(LIBRARY_OPENGL)] public static extern void glEvalPoint2 (int i, int j);
        [DllImport(LIBRARY_OPENGL)] public static extern void glFeedbackBuffer (int size, uint type, float []buffer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glFinish ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glFlush ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glFogf (uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glFogfv (uint pname,  float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glFogi (uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glFogiv (uint pname,  int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glFrontFace (uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glFrustum (double left, double right, double bottom, double top, double zNear, double zFar);
        [DllImport(LIBRARY_OPENGL)] public static extern uint glGenLists (int range);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGenTextures (int n, uint []textures);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetBooleanv (uint pname, byte []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetClipPlane (uint plane, double []equation);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetDoublev (uint pname, double []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern uint glGetError ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetFloatv (uint pname, float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetIntegerv (uint pname, int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetLightfv (uint light, uint pname, float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetLightiv (uint light, uint pname, int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetMapdv (uint target, uint query, double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetMapfv (uint target, uint query, float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetMapiv (uint target, uint query, int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetMaterialfv (uint face, uint pname, float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetMaterialiv (uint face, uint pname, int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetPixelMapfv (uint map, float []values);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetPixelMapuiv (uint map, uint []values);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetPixelMapusv (uint map, ushort []values);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetPointerv (uint pname, int[] params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetPolygonStipple (byte []mask);
        [DllImport(LIBRARY_OPENGL)] protected unsafe static extern sbyte* glGetString (uint name);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexEnvfv (uint target, uint pname, float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexEnviv (uint target, uint pname, int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexGendv (uint coord, uint pname, double []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexGenfv (uint coord, uint pname, float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexGeniv (uint coord, uint pname, int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexImage (uint target, int level, uint format, uint type, int []pixels);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexLevelParameterfv (uint target, int level, uint pname, float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexLevelParameteriv (uint target, int level, uint pname, int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexParameterfv (uint target, uint pname, float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glGetTexParameteriv (uint target, uint pname, int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glHint (uint target, uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexMask (uint mask);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexPointer (uint type, int stride,  int[] pointer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexd (double c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexdv ( double []c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexf (float c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexfv ( float []c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexi (int c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexiv ( int []c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexs (short c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexsv ( short []c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexub (byte c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glIndexubv ( byte []c);
        [DllImport(LIBRARY_OPENGL)] public static extern void glInitNames ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glInterleavedArrays (uint format, int stride,  int[] pointer);
        [DllImport(LIBRARY_OPENGL)] public static extern byte glIsEnabled (uint cap);
        [DllImport(LIBRARY_OPENGL)] public static extern byte glIsList (uint list);
        [DllImport(LIBRARY_OPENGL)] public static extern byte glIsTexture (uint texture);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLightModelf (uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLightModelfv (uint pname,  float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLightModeli (uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLightModeliv (uint pname,  int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLightf (uint light, uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLightfv (uint light, uint pname,  float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLighti (uint light, uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLightiv (uint light, uint pname,  int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLineStipple (int factor, ushort pattern);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLineWidth (float width);
        [DllImport(LIBRARY_OPENGL)] public static extern void glListBase (uint base_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLoadIdentity ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glLoadMatrixd ( double []m);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLoadMatrixf ( float []m);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLoadName (uint name);
        [DllImport(LIBRARY_OPENGL)] public static extern void glLogicOp (uint opcode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMap1d (uint target, double u1, double u2, int stride, int order,  double []points);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMap1f (uint target, float u1, float u2, int stride, int order,  float []points);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMap2d (uint target, double u1, double u2, int ustride, int uorder, double v1, double v2, int vstride, int vorder,  double []points);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMap2f (uint target, float u1, float u2, int ustride, int uorder, float v1, float v2, int vstride, int vorder,  float []points);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMapGrid1d (int un, double u1, double u2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMapGrid1f (int un, float u1, float u2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMapGrid2d (int un, double u1, double u2, int vn, double v1, double v2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMapGrid2f (int un, float u1, float u2, int vn, float v1, float v2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMaterialf (uint face, uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMaterialfv (uint face, uint pname,  float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMateriali (uint face, uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMaterialiv (uint face, uint pname,  int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMatrixMode (uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMultMatrixd ( double []m);
        [DllImport(LIBRARY_OPENGL)] public static extern void glMultMatrixf ( float []m);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNewList (uint list, uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3b (byte nx, byte ny, byte nz);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3bv ( byte []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3d (double nx, double ny, double nz);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3f (float nx, float ny, float nz);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3i (int nx, int ny, int nz);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3s (short nx, short ny, short nz);
        [DllImport(LIBRARY_OPENGL)] public static extern void glNormal3sv ( short []v);
        //[DllImport(LIBRARY_OPENGL)] public static extern void glNormalPointer (uint type, int stride, float[] pointer);
        [DllImport(LIBRARY_OPENGL)] public unsafe static extern void glNormalPointer (uint type, int stride, void* pointer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glOrtho (double left, double right, double bottom, double top, double zNear, double zFar);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPassThrough (float token);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelMapfv (uint map, int mapsize,  float []values);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelMapuiv (uint map, int mapsize,  uint []values);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelMapusv (uint map, int mapsize,  ushort []values);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelStoref (uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelStorei (uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelTransferf (uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelTransferi (uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPixelZoom (float xfactor, float yfactor);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPointSize (float size);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPolygonMode (uint face, uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPolygonOffset (float factor, float units);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPolygonStipple ( byte []mask);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPopAttrib ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glPopClientAttrib ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glPopMatrix ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glPopName ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glPrioritizeTextures (int n,  uint []textures,  float []priorities);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPushAttrib (uint mask);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPushClientAttrib (uint mask);
        [DllImport(LIBRARY_OPENGL)] public static extern void glPushMatrix ();
        [DllImport(LIBRARY_OPENGL)] public static extern void glPushName (uint name);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2d (double x, double y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2f (float x, float y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2i (int x, int y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2s (short x, short y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos2sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3d (double x, double y, double z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3f (float x, float y, float z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3i (int x, int y, int z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3s (short x, short y, short z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos3sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4d (double x, double y, double z, double w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4f (float x, float y, float z, float w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4i (int x, int y, int z, int w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4s (short x, short y, short z, short w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRasterPos4sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glReadBuffer (uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glReadPixels(int x, int y, int width, int height, uint format, uint type, byte[] pixels);
        [DllImport(LIBRARY_OPENGL)] public static extern void glReadPixels(int x, int y, int width, int height, uint format, uint type, IntPtr pixels);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRectd (double x1, double y1, double x2, double y2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRectdv ( double []v1,  double []v2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRectf (float x1, float y1, float x2, float y2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRectfv ( float []v1,  float []v2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRecti (int x1, int y1, int x2, int y2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRectiv ( int []v1,  int []v2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRects (short x1, short y1, short x2, short y2);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRectsv ( short []v1,  short []v2);
        [DllImport(LIBRARY_OPENGL)] public static extern int glRenderMode (uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRotated (double angle, double x, double y, double z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glRotatef (float angle, float x, float y, float z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glScaled (double x, double y, double z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glScalef (float x, float y, float z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glScissor (int x, int y, int width, int height);
        [DllImport(LIBRARY_OPENGL)] public static extern void glSelectBuffer (int size, uint []buffer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glShadeModel (uint mode);
        [DllImport(LIBRARY_OPENGL)] public static extern void glStencilFunc (uint func, int ref_notkeword, uint mask);
        [DllImport(LIBRARY_OPENGL)] public static extern void glStencilMask (uint mask);
        [DllImport(LIBRARY_OPENGL)] public static extern void glStencilOp (uint fail, uint zfail, uint zpass);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1d (double s);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1f (float s);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1i (int s);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1s (short s);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord1sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2d (double s, double t);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2f (float s, float t);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2i (int s, int t);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2s (short s, short t);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord2sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3d (double s, double t, double r);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3f (float s, float t, float r);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3i (int s, int t, int r);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3s (short s, short t, short r);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord3sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4d (double s, double t, double r, double q);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4f (float s, float t, float r, float q);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4i (int s, int t, int r, int q);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4s (short s, short t, short r, short q);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexCoord4sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public unsafe static extern void glTexCoordPointer (int size, uint type, int stride,  float* pointer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexEnvf (uint target, uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexEnvfv (uint target, uint pname,  float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexEnvi (uint target, uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexEnviv (uint target, uint pname,  int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexGend (uint coord, uint pname, double param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexGendv (uint coord, uint pname,  double []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexGenf (uint coord, uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexGenfv (uint coord, uint pname,  float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexGeni (uint coord, uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexGeniv (uint coord, uint pname,  int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexImage1D (uint target, int level, int internalformat, int width, int border, uint format, uint type,  byte[] pixels);
        [DllImport(LIBRARY_OPENGL)] public unsafe static extern void glTexImage2D (uint target, int level, int internalformat, int width, int height, int border, uint format, uint type, byte* pixels);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexParameterf (uint target, uint pname, float param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexParameterfv (uint target, uint pname,  float []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexParameteri (uint target, uint pname, int param);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexParameteriv (uint target, uint pname,  int []params_notkeyword);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexSubImage1D (uint target, int level, int xoffset, int width, uint format, uint type,  int[] pixels);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTexSubImage2D (uint target, int level, int xoffset, int yoffset, int width, int height, uint format, uint type,  byte[] pixels);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTranslated (double x, double y, double z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glTranslatef (float x, float y, float z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2d (double x, double y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2f (float x, float y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2i (int x, int y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2s (short x, short y);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex2sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3d (double x, double y, double z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3f (float x, float y, float z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3i (int x, int y, int z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3s (short x, short y, short z);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex3sv ( short []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4d (double x, double y, double z, double w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4dv ( double []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4f (float x, float y, float z, float w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4fv ( float []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4i (int x, int y, int z, int w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4iv ( int []v);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4s (short x, short y, short z, short w);
        [DllImport(LIBRARY_OPENGL)] public static extern void glVertex4sv ( short []v);
        //[DllImport(LIBRARY_OPENGL)] public static extern void glVertexPointer (int size, uint type, int stride, float[] pointer);
        [DllImport(LIBRARY_OPENGL)] public unsafe static extern void glVertexPointer (int size, uint type, int stride, float* pointer);
        [DllImport(LIBRARY_OPENGL)] public static extern void glViewport (int x, int y, int width, int height);

    #endregion
	}
}
