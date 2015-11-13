#ifndef JUGADOR_H
#define JUGADOR_H

#include <list>
#include <fstream>
#include "Personaje.h"
#include "Proyectil.h"

class Jugador : public Personaje
{
    public:
        Jugador(list<Entidad*>* entidades,SDL_Renderer* renderer);
        virtual ~Jugador();
        void logica();
    protected:
    private:
};

#endif // JUGADOR_H
