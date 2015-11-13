#ifndef ENEMY_PROYECTIL_H
#define ENEMY_PROYECTIL_H

#include "Proyectil.h"


class Enemy_Proyectil : public Proyectil
{
    public:
        Enemy_Proyectil(list<Entidad*>* entidades, SDL_Renderer* renderer, int x, int y, string state);
        void logica();
        virtual ~Enemy_Proyectil();
    protected:
    private:
};

#endif // ENEMY_PROYECTIL_H
