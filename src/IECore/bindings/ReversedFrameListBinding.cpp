//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2009, Image Engine Design Inc. All rights reserved.
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

#include "boost/python.hpp"

#include "IECore/bindings/IECoreBinding.h"
#include "IECore/bindings/RunTimeTypedBinding.h"
#include "IECore/bindings/IntrusivePtrPatch.h"
#include "IECore/bindings/WrapperToPython.h"
#include "IECore/bindings/FrameListBinding.h"

#include "IECore/ReversedFrameList.h"
#include "IECore/Exception.h"

using namespace boost::python;

namespace IECore 
{

template<>
std::string repr( ReversedFrameList &x )
{
	object item( x.getFrameList() );
	std::stringstream s;
	
	s << "IECore.ReversedFrameList( ";
	s << call_method< std::string >( item.ptr(), "__repr__" );
	s << " ) ";
	
	return s.str();
}

void bindReversedFrameList()
{	
	typedef class_< ReversedFrameList, ReversedFrameList::Ptr, bases< ReorderedFrameList >, boost::noncopyable > ReversedFrameListPyClass;
	ReversedFrameListPyClass ( "ReversedFrameList", no_init )
		.def( init< optional< FrameListPtr > >() )	
		.def( "__repr__", repr< ReversedFrameList > )
		.IE_COREPYTHON_DEFRUNTIMETYPEDSTATICMETHODS(ReversedFrameList)	
	;
		
	INTRUSIVE_PTR_PATCH( ReversedFrameList, ReversedFrameListPyClass );
	implicitly_convertible<ReversedFrameListPtr, ReorderedFrameListPtr>();	
}

}