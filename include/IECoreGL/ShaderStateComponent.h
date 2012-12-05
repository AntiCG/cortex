//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2007-2012, Image Engine Design Inc. All rights reserved.
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

#ifndef IECOREGL_SHADERSTATECOMPONENT_H
#define IECOREGL_SHADERSTATECOMPONENT_H

#include "IECore/CompoundObject.h"

#include "IECoreGL/StateComponent.h"
#include "IECoreGL/ShaderManager.h"
#include "IECoreGL/Shader.h"
#include "IECoreGL/TextureLoader.h"

namespace IECoreGL
{

/// The ShaderStateComponent class represents a Shader
/// object and a set of associated parameter values. It derives
/// from StateComponent and therefore can be used to apply Shaders
/// to Primitives within a Group or Scene.
/// \todo Allow this to specify texture filtering and wrap modes.
class ShaderStateComponent : public StateComponent
{

	public :

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION( IECoreGL::ShaderStateComponent, ShaderStateComponentTypeId, StateComponent );

		/// Default constructor creates a facing ratio shader.
		ShaderStateComponent();
		/// Creates a ShaderStateComponent with the given source and parameters. The loaders are passed to
		/// allow the creation of GL resources to be deferred until shaderSetup() is called - this makes
		/// it possible to create ShaderStateComponents concurrently in multiple threads, with the actual
		/// GL resource creation deferred until the drawing thread uses shaderSetup().
		ShaderStateComponent( ShaderManagerPtr shaderManager, TextureLoaderPtr textureLoader, const std::string vertexShader, const std::string fragmentShader, IECore::ConstCompoundObjectPtr parameterValues );

		/// Implemented to do nothing - it is the responsibility of the Primitive
		/// to actually bind the shader() at an appropriate time.
		virtual void bind() const;

		/// Returns the shader object.
		/// This function can only be called from a thread 
		/// with a valid GL context.
		Shader::Setup *shaderSetup();
		const Shader::Setup *shaderSetup() const;
		//@}

	protected :

		void ensureShaderSetup() const;

		ShaderManagerPtr m_shaderManager;
		TextureLoaderPtr m_textureLoader;
		std::string m_fragmentShader;
		std::string m_vertexShader;
		IECore::CompoundObjectPtr m_parameterMap;		
		mutable Shader::SetupPtr m_shaderSetup;

		static Description<ShaderStateComponent> g_description;
		
};

IE_CORE_DECLAREPTR( ShaderStateComponent );

} // namespace IECoreGL

#endif // IECOREGL_SHADERSTATECOMPONENT_H
