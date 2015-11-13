#include "Enemy_Proyectil.h"

Enemy_Proyectil::Enemy_Proyectil()
{
    texture = IMG_LoadTexture(renderer,"proyectil2.png");
    texture2 = IMG_LoadTexture(renderer,"proyectil2.png");
}

void Proyectil::logica()
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

    /*for(list<Entidad*>::iterator e=entidades->begin();
        e!=entidades->end();
        e++)
    {
        if((*e)->tipo=="Enemigo")
        {
            Enemigo* enemigo = (Enemigo*)(*e);
            if(colision(rect,enemigo->rect))
            {
                enemigo->delete_flag = true;
                this->delete_flag = true;
                cout<<"Enemigo Eliminado"<<endl;
            }
        }
    }
    */
}


Enemy_Proyectil::~Enemy_Proyectil()
{
    //dtor
}
