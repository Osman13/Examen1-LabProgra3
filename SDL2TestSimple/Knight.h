#ifndef KNIGHT_H
#define KNIGHT_H

#include "Enemigo.h"
#include <stdlib.h>
#include <list>

class Knight : public Enemigo
{
    public:
        int width;
        Knight(list<Entidad*>* entidades,SDL_Renderer* renderer);
        virtual ~Knight();
        void logica();
    protected:
    private:
};

#endif // KNIGHT_H
