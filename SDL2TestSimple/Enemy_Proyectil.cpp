#include "Enemy_Proyectil.h"

Enemy_Proyectil::Enemy_Proyectil(list<Entidad*>* entidades, SDL_Renderer* renderer, int x, int y, string state) : Proyectil(entidades, renderer, x, y, state)
{
    tipo = "Proyectil";
    this->entidades = entidades;
    this->renderer = renderer;
    this->state = state;
    texture = IMG_LoadTexture(renderer,"proyectil2.png");
    texture2 = IMG_LoadTexture(renderer,"proyectil2.png");
    rect.x=x;
    rect.y=y;
    rect.w=20;
    rect.h=10;
}

void Enemy_Proyectil::logica()
{
    int velocity = 2;
    if(state=="right")
    {
        rect.x+=velocity;
    }
    if(state=="left")
    {
        rect.x-=velocity;
    }
    if(state=="up")
    {
        rect.y-=velocity;
    }
    if(state=="down")
    {
        rect.y+=velocity;
    }

    for(list<Entidad*>::iterator e=entidades->begin();
        e!=entidades->end();
        e++)
    {
        if((*e)->tipo=="Jugador")
        {
            Jugador* jugador = (Jugador*)(*e);
            if(colision(rect,jugador->rect))
            {
                jugador->delete_flag = true;
                this->delete_flag = true;
                cout<<"Enemigo Eliminado"<<endl;
            }
        }
    }

}


Enemy_Proyectil::~Enemy_Proyectil()
{
    //dtor
}
