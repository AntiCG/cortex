//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2013, Image Engine Design Inc. All rights reserved.
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

#ifndef IECOREHOUDINI_OBJSCENECACHENODE_H
#define IECOREHOUDINI_OBJSCENECACHENODE_H

#include "OBJ/OBJ_Node.h"

#include "IECore/SceneCache.h"

#include "IECoreHoudini/SceneCacheNode.h"

namespace IECoreHoudini
{

/// Abstract base class for all OBJ SceneCacheNodes.
/// See OBJ_SceneCacheGeometry or OBJ_SceneCacheTransform for specific implementations.
template<typename BaseType>
class OBJ_SceneCacheNode : public SceneCacheNode<BaseType>
{
	public :
		
		OBJ_SceneCacheNode( OP_Network *net, const char *name, OP_Operator *op );
		virtual ~OBJ_SceneCacheNode();
		
		static OP_TemplatePair *buildParameters();
		
		static PRM_Name pBuild;
		
		static int buildButtonCallback( void *data, int index, float time, const PRM_Template *tplate );
	
		/// Derived classes should define this function to build the hierarchy contained in the SceneCache.
		virtual void buildHierarchy( const IECore::SceneInterface *scene ) = 0;
		/// Implemented to destroy all child nodes
		virtual void cleanHierarchy();
	
	protected :
		
		virtual void sceneChanged();
		virtual bool getParmTransform( OP_Context &context, UT_DMatrix4 &xform );
		
		bool m_static;
		bool m_loaded;
		SceneCacheNode<OP_Node>::Space m_space;
		UT_Matrix4D m_xform;

};

} // namespace IECoreHoudini

#endif // IECOREHOUDINI_OBJSCENECACHENODE_H
