#include "Knight.h"
#include "Enemy_Proyectil.h"
Knight::Knight(list<Entidad*>* entidades,SDL_Renderer* renderer) : Enemigo(entidades, renderer)
{
    tipo = "Enemigo";
    this->renderer = renderer;
    this->jugador = jugador;
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/down1.png"));
    this->textures["down"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/down2.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/up1.png"));
    this->textures["up"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/up2.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/left1.png"));
    this->textures["left"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/left2.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/right1.png"));
    this->textures["right"].push_back(IMG_LoadTexture(renderer, "Enemigo/Enemigo2/right2.png"));

    SDL_QueryTexture(this->textures["down"][0], NULL, NULL, &rect.w, &rect.h);
    x = rand()%100;
    y = rand()%100;
    rect.x=x;
    rect.y=x;

    velocity=0.5;
    animation_velocity=20;

    current_texture=0;

    state="down";

    this->entidades = entidades;

    for(list<Entidad*>::iterator e=entidades->begin();
        e!=entidades->end();
        e++)
    {
        if((*e)->tipo=="Jugador")
        {
            jugador = (Jugador*)*e;
        }
    }
}

Knight::~Knight()
{
    //dtor
}

void Knight::logica()
{
    if(jugador->y+5<y)
    {
        state="up";
    }
    if(jugador->y-5>y)
    {
        state="down";
    }
    if(jugador->x+5<x)
    {
        x-=velocity;
    }
    if(jugador->x-5>x)
        x+=velocity;

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
    if( (rand() % 50)  == 0 )
    {
        Enemy_Proyectil *p = new Enemy_Proyectil(entidades,renderer,x,y,state);
        entidades->push_back(p);
    }


    frames++;
}

