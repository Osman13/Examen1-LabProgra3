#ifndef ALIEN_H
#define ALIEN_H

#include "Enemigo.h"
#include "Proyectil.h"
#include <stdlib.h>
#include <list>

class Alien : public Enemigo
{
    public:
        Alien(list<Entidad*>* entidades,SDL_Renderer* renderer);
        virtual ~Alien();
        void logica();
    protected:
    private:
};

#endif // ALIEN_H
