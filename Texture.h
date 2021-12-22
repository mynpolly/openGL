/*
 * Texture.h
 *
 *  Created on: 22 дек. 2021 г.
 *      Author: polly
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>


class Texture
{
protected:
	GLuint _name{};

public:
	Texture(const char *filename) ;
	virtual ~Texture();

	inline void use() { glBindTexture(GL_TEXTURE_2D, _name); }

	static void enable()  { glEnable(GL_TEXTURE_2D);  }
	static void disable() { glDisable(GL_TEXTURE_2D); }
};

#endif /* TEXTURE_H_ */
