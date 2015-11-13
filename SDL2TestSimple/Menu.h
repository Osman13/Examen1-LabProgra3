#ifndef MENU_H
#define MENU_H

#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>

using namespace std;

class Menu
{
    public:
        SDL_Renderer* renderer;
        SDL_Texture *background;
        SDL_Rect rect_background;
        Menu();
        void start(SDL_Renderer* renderer, SDL_Texture *background, SDL_Rect rect_background);
        void quit(SDL_Renderer* renderer, SDL_Texture *background, SDL_Rect rect_background);
        void stable(SDL_Renderer* renderer, SDL_Texture *background, SDL_Rect rect_background);
        virtual ~Menu();
    protected:
    private:
};

#endif // MENU_H
