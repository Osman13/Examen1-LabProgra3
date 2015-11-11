#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Personaje.h"
#include "Jugador.h"
#include <stdlib.h>

class Enemigo : public Personaje
{
    public:
        Jugador* jugador;
        Enemigo(SDL_Renderer* renderer,Jugador* jugador);
        virtual ~Enemigo();
        void logica();
    protected:
    private:
};

#endif // ENEMIGO_H
