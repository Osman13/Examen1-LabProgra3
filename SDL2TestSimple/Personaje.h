#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Personaje
{
    public:
        SDL_Renderer* renderer;
        map<string,vector<SDL_Texture*> >textures;
        string state;
        SDL_Rect rect;
        int current_texture;
        int frames;
        double x, y;
        double velocity;
        int animation_velocity;
        Personaje();
        virtual ~Personaje();
        virtual void dibujar();
        virtual void logica()=0;
    protected:
    private:
};

#endif // PERSONAJE_H
