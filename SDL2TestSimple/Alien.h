#ifndef ALIEN_H
#define ALIEN_H

#include "Enemigo.h"

class Alien : public Enemigo
{
    public:
        Alien(SDL_Renderer* renderer,Jugador* jugador);
        virtual ~Alien();
        void logica();
    protected:
    private:
};

#endif // ALIEN_H
