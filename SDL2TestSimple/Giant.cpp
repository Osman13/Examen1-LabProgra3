#include "Giant.h"

Giant::Giant(SDL_Renderer* renderer,Jugador* jugador) : Enemigo(renderer, jugador)
{
    this->renderer = renderer;
    this->jugador = jugador;
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/down1.png"));
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/down2.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/up1.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/up2.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/left1.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/left2.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/right1.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo1/right2.png"));

    SDL_QueryTexture(this->textures["down"][0], NULL, NULL, &rect.w, &rect.h);
    x = rand()%100;
    y = rand()%100;

    velocity=0.5;
    animation_velocity=20;

    current_texture=0;

    state="down";
}

Giant::~Giant()
{
    //dtor
}

void Giant::logica()
{
    if(jugador->x+5>x)
    {
        state="right";
    }
    if(jugador->x-5<x)
    {
        state="left";
    }
    if(jugador->y+5<y)
    {
        state="up";
    }
    if(jugador->y-5>y)
    {
        state="down";
    }

    if(state=="right")
    {
        x+=velocity;
    }
    if(state=="left")
    {
        x-=velocity;
    }
    if(state=="up")
    {
        y-=velocity;
    }
    if(state=="down")
    {
        y+=velocity;
    }

    if(frames%animation_velocity==0)
    {
        current_texture++;
        if(current_texture>=textures[state].size())
            current_texture=0;
    }

    frames++;
}
