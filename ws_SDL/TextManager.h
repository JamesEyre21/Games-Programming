#ifndef textManagement
#define textManagement

#include "SDL.h"
#include "SDL_ttf.h"

class TextManager
{
public:
	TextManager();
	TextManager(SDL_Renderer* renderer, int textSize, int x, int y, int width, int height, const char* text);

	SDL_Surface* textSurface;
	SDL_Texture* textTexture;
	int textW;
	int textH;
	SDL_Rect textRect;

};

#endif