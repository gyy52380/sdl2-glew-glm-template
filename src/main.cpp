#define GL_DEBUG

#include "typedef.h"
#include "backend/sdl.h"
#include "renderer/gl.h"


SDL_Window *window_handle;
SDL_GLContext gl_context;

constexpr u32 SCREEN_WIDTH  = 640;
constexpr u32 SCREEN_HEIGHT = 480;

#undef main
int main(int argc, char *argv[])
{
	if ( !(backend::init(window_handle, gl_context, SCREEN_WIDTH, SCREEN_HEIGHT) && renderer::gl_init()) )
		backend::cleanup(window_handle, gl_context);

	SDL_Delay(2000);

	backend::cleanup(window_handle, gl_context);

	return 0;
}