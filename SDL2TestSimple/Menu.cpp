#include "Menu.h"

Menu::Menu()
{
    //ctor
}

Menu::~Menu()
{
    //dtor
}
void Menu::start(SDL_Renderer* renderer, SDL_Texture *background, SDL_Rect rect_background)
{
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"start.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    SDL_RenderCopy(renderer, background, NULL, &rect_background);
    SDL_RenderPresent(renderer);

}
void Menu::quit(SDL_Renderer* renderer, SDL_Texture *background, SDL_Rect rect_background)
{
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"exit.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    SDL_RenderCopy(renderer, background, NULL, &rect_background);
    SDL_RenderPresent(renderer);

}
void Menu::stable(SDL_Renderer* renderer, SDL_Texture *background, SDL_Rect rect_background)
{
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"stable.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;
    SDL_RenderCopy(renderer, background, NULL, &rect_background);
    SDL_RenderPresent(renderer);

}
