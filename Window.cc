#include "Window.h"
#include <stdexcept>

Window::Window(int width, int height)
: _width(width), _height(height)
{
	_window = std::shared_ptr<SDL_Window>(
			SDL_CreateWindow(
					"OpenGL Window",
					SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED,
					width, height,
					SDL_WINDOW_OPENGL),
			SDL_DestroyWindow);
	if (not _window)
		throw std::runtime_error(
				std::string("Не могу создать окно: ") +
				std::string(SDL_GetError()));

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	_gl_context = std::shared_ptr<void>(
			SDL_GL_CreateContext(_window.get()),
			SDL_GL_DeleteContext);
	if (not _gl_context)
		throw std::runtime_error(
				std::string("Не могу создать контекст OpenGL: ") +
				std::string(SDL_GetError()));
}

void Window::main_loop()
{
	setup();

	SDL_Event event;
	auto keys = SDL_GetKeyboardState(nullptr);

	for (;;) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT)
				return;
			if (	event.type == SDL_KEYDOWN and
					event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
				return;
			handle_event(event);
		}
		handle_keys(keys);

		update();

		render();
		SDL_GL_SwapWindow(_window.get());
	}
}
