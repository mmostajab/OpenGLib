#ifndef __GLC_ERROR_FINDER__
#define __GLC_ERROR_FINDER__

#include <GL/gl.h>
#include <GL/glu.h>

class glcErrorFinder
{
	glcErrorFinder();

	void getError();

	~glcErrorFinder();
};

#endif