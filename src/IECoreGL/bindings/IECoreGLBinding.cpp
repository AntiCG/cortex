//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2012, Image Engine Design Inc. All rights reserved.
//  Copyright (c) 2012, John Haddon. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>

#include "IECoreGL/IECoreGL.h"

#include "IECoreGL/bindings/RendererBinding.h"
#include "IECoreGL/bindings/BindableBinding.h"
#include "IECoreGL/bindings/ShaderBinding.h"
#include "IECoreGL/bindings/TextureBinding.h"
#include "IECoreGL/bindings/WindowBinding.h"
#include "IECoreGL/bindings/StateBinding.h"
#include "IECoreGL/bindings/RenderableBinding.h"
#include "IECoreGL/bindings/SceneBinding.h"
#include "IECoreGL/bindings/SceneViewerBinding.h"
#include "IECoreGL/bindings/ShaderManagerBinding.h"
#include "IECoreGL/bindings/TextureLoaderBinding.h"
#include "IECoreGL/bindings/GroupBinding.h"
#include "IECoreGL/bindings/FrameBufferBinding.h"
#include "IECoreGL/bindings/ColorTextureBinding.h"
#include "IECoreGL/bindings/DepthTextureBinding.h"
#include "IECoreGL/bindings/CameraBinding.h"
#include "IECoreGL/bindings/OrthographicCameraBinding.h"
#include "IECoreGL/bindings/PerspectiveCameraBinding.h"
#include "IECoreGL/bindings/CameraControllerBinding.h"
#include "IECoreGL/bindings/StateComponentBinding.h"
#include "IECoreGL/bindings/TypedStateComponentBinding.h"
#include "IECoreGL/bindings/NameStateComponentBinding.h"
#include "IECoreGL/bindings/HitRecordBinding.h"
#include "IECoreGL/bindings/ToGLConverterBinding.h"
#include "IECoreGL/bindings/ToGLCameraConverterBinding.h"
#include "IECoreGL/bindings/AlphaTextureBinding.h"
#include "IECoreGL/bindings/LuminanceTextureBinding.h"
#include "IECoreGL/bindings/ToGLTextureConverterBinding.h"
#include "IECoreGL/bindings/PrimitiveBinding.h"
#include "IECoreGL/bindings/PointsPrimitiveBinding.h"
#include "IECoreGL/bindings/SelectorBinding.h"
#include "IECoreGL/bindings/FontBinding.h"
#include "IECoreGL/bindings/FontLoaderBinding.h"

using namespace IECoreGL;
using namespace boost::python;

BOOST_PYTHON_MODULE( _IECoreGL )
{
	bindRenderer();
	bindBindable();
	bindShader();
	bindTexture();
	bindWindow();
	bindState();
	bindRenderable();
	bindScene();
	bindSceneViewer();
	bindShaderManager();
	bindTextureLoader();
	bindGroup();
	bindFrameBuffer();
	bindColorTexture();
	bindDepthTexture();
	bindCamera();
	bindOrthographicCamera();
	bindPerspectiveCamera();
	bindCameraController();
	bindStateComponent();
	bindTypedStateComponents();
	bindNameStateComponent();
	bindHitRecord();
	bindToGLConverter();
	bindToGLCameraConverter();
	bindAlphaTexture();
	bindLuminanceTexture();
	bindToGLTextureConverter();
	bindPrimitive();
	bindPointsPrimitive();
	bindSelector();

#ifdef IECORE_WITH_FREETYPE

	bindFont();
	bindFontLoader();

#endif

	def( "init", &IECoreGL::init );
}
