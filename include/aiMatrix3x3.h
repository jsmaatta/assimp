/*
---------------------------------------------------------------------------
Open Asset Import Library (ASSIMP)
---------------------------------------------------------------------------

Copyright (c) 2006-2008, ASSIMP Development Team

All rights reserved.

Redistribution and use of this software in source and binary forms, 
with or without modification, are permitted provided that the following 
conditions are met:

* Redistributions of source code must retain the above
  copyright notice, this list of conditions and the
  following disclaimer.

* Redistributions in binary form must reproduce the above
  copyright notice, this list of conditions and the
  following disclaimer in the documentation and/or other
  materials provided with the distribution.

* Neither the name of the ASSIMP team, nor the names of its
  contributors may be used to endorse or promote products
  derived from this software without specific prior
  written permission of the ASSIMP Development Team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/

/** @file Definition of a 3x3 matrix, including operators when compiling in C++ */
#ifndef AI_MATRIX3x3_H_INC
#define AI_MATRIX3x3_H_INC

#ifdef __cplusplus
extern "C" {
#endif

struct aiMatrix4x4;

// ---------------------------------------------------------------------------
/** Represents a row-major 3x3 matrix 
*/
// ---------------------------------------------------------------------------
struct aiMatrix3x3
{
#ifdef __cplusplus
	aiMatrix3x3 () :	
		a1(1.0f), a2(0.0f), a3(0.0f), 
		b1(0.0f), b2(1.0f), b3(0.0f), 
		c1(0.0f), c2(0.0f), c3(1.0f) {}

	aiMatrix3x3 (	float _a1, float _a2, float _a3,
					float _b1, float _b2, float _b3,
					float _c1, float _c2, float _c3) :	
		a1(_a1), a2(_a2), a3(_a3), 
		b1(_b1), b2(_b2), b3(_b3), 
		c1(_c1), c2(_c2), c3(_c3)
	{}

	/** Construction from a 4x4 matrix. The remaining parts of the 
	    matrix are ignored. */
	explicit aiMatrix3x3( const aiMatrix4x4& pMatrix);

	aiMatrix3x3& operator *= (const aiMatrix3x3& m);
	aiMatrix3x3 operator* (const aiMatrix3x3& m) const;
	aiMatrix3x3& Transpose();

#endif // __cplusplus


	float a1, a2, a3;
	float b1, b2, b3;
	float c1, c2, c3;
};

#ifdef __cplusplus
} // end of extern C
#endif

#endif // AI_MATRIX3x3_H_INC