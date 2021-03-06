##########################################################################
#
#  Copyright (c) 2012, Image Engine Design Inc. All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are
#  met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#
#     * Neither the name of Image Engine Design nor the names of any
#       other contributors to this software may be used to endorse or
#       promote products derived from this software without specific prior
#       written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
#  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
#  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
#  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
#  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
##########################################################################

import unittest
import IECore
import datetime

class TimeCodeParameterTest( unittest.TestCase ) :

	def testConstructor( self ) :

		t = IECore.TimeCode( 12, 24, 12, 15, dropFrame = True, bgf1 = True, binaryGroup6 = 12 )

		p = IECore.TimeCodeParameter(
			name = "testName",
			description = "testName description",
			defaultValue = t
		)
		
		self.assertEqual( p.defaultValue, IECore.TimeCodeData( t ) )

	def testGetSetValue( self ) :
		
		t = IECore.TimeCode( 12, 24, 12, 15, dropFrame = True, bgf1 = True, binaryGroup6 = 12 )

		p = IECore.TimeCodeParameter(
			name = "testName",
			description = "testName description",
			defaultValue = t
		)
		
		self.assertEqual( p.getValue(), IECore.TimeCodeData( t ) )
		self.assertEqual( p.getTypedValue(), t )
		
		tt = IECore.TimeCode( t )
		tt.setMinutes( 10 )
		p.setTypedValue( tt )
		
		self.assertNotEqual( p.getValue(), IECore.TimeCodeData( t ) )
		self.assertNotEqual( p.getTypedValue(), t )
		self.assertEqual( p.getValue(), IECore.TimeCodeData( tt ) )
		self.assertEqual( p.getTypedValue(), tt )
		
		p.setValue( IECore.TimeCodeData( p.defaultValue.value ) )
		
		self.assertNotEqual( p.getValue(), IECore.TimeCodeData( tt ) )
		self.assertNotEqual( p.getTypedValue(), tt )
		self.assertEqual( p.getValue(), IECore.TimeCodeData( t ) )
		self.assertEqual( p.getTypedValue(), t )

if __name__ == "__main__":
    unittest.main()

