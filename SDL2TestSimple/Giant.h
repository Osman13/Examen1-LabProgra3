#ifndef GIANT_H
#define GIANT_H

#include "Enemigo.h"

class Giant : public Enemigo
{
    public:
        Giant(SDL_Renderer* renderer,Jugador* jugador);
        virtual ~Giant();
        void logica();
    protected:
    private:
};

#endif // GIANT_H
