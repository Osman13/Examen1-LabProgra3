#ifndef JUGADOR_H
#define JUGADOR_H

#include "Personaje.h"

class Jugador : public Personaje
{
    public:
        Jugador(SDL_Renderer* renderer);
        virtual ~Jugador();
        void logica();
    protected:
    private:
};

#endif // JUGADOR_H
