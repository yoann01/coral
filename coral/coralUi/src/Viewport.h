// <license>
// Copyright (C) 2011 Andrea Interguglielmi, All rights reserved.
// This file is part of the coral repository downloaded from http://code.google.com/p/coral-repo.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
// 
//    * Redistributions of source code must retain the above copyright
//      notice, this list of conditions and the following disclaimer.
// 
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
// IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// </license>


#ifndef VIEWPORT_H
#define VIEWPORT_H

#include <ImathMatrix.h>

namespace coralUi{

class Viewport{
public:
	Viewport();
	~Viewport();

	void initializeGL();
	void resizeGL(int width, int height);
	void draw();
	void orbit(int deltaSide, int deltaUp);
	void pan(int deltaSide, int deltaUp);
	void dolly(int deltaSide);
	void zoom(int deltaSide);
	void roll(int deltaSide);
	Imath::M44f modelMatrix();
	float fov();
	float zNear();
	float zFar();

private:
	void prepareForDrawing();
	void setupProjection();
	void drawGrid();
	void drawAxis();
	
	Imath::V3f _target;
	Imath::M44f _modelMatrix;
	float _projectionMatrix[16];
	float _fov, _roll, _zNear, _zFar;
	int _width, _height;
	bool _initialized;
	bool _isProjDirty;
};

}

#endif