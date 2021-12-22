/*
 * main.cc
 *
 *  Created on: 29 нояб. 2021 г.
 *      Author: unyuu
 */

/*
 * OpenGL
 * 		1.x-2.x		<-- рассматриваем это
 * 		3.x-4.x
 *
 *	Библиотеки:
 *		Для Windows + MinGW:
 *			mingw32
 *			SDL2main
 *			SDL2
 *			SDL2_image
 *			opengl32
 *			glu32
 *		Для большинства других ОС:
 *			SDL2
 *			SDL2_image
 *			GL
 *			GLU
 */

#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "TestWindow.h"

int main(int, char**)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	try {
		TestWindow w;

		w.main_loop();
	} catch (const std::exception &e) {
		std::cerr <<
				"Во время выполнения программы произошла ошибка:\n" <<
				e.what() <<
				std::endl;
		return 1;
	}


	return 0;
}


