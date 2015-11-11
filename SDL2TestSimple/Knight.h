#ifndef KNIGHT_H
#define KNIGHT_H

#include "Enemigo.h"

class Knight : public Enemigo
{
    public:
        int width;
        Knight(SDL_Renderer* renderer,Jugador* jugador);
        virtual ~Knight();
        void logica();
    protected:
    private:
};

#endif // KNIGHT_H
