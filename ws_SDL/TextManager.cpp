#include "textManager.h"


TextManager::TextManager()
{
	int textW = 0;
	int textH = 0;
}

TextManager::TextManager(SDL_Renderer* renderer, int textSize, int x, int y, int width, int height, const char* text)
{
	TTF_Font* textFont = TTF_OpenFont("content/arial.ttf", textSize);
	SDL_Color textColor = { 255, 255, 255 };
	textSurface = TTF_RenderText_Solid(textFont, text, textColor);
	textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);

	SDL_QueryTexture(textTexture, NULL, NULL, &textW, &textH);
	textRect = { x, y, textW+width, textH+height };
}