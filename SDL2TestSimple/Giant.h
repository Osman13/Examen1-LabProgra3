#ifndef GIANT_H
#define GIANT_H

#include "Enemigo.h"
#include <stdlib.h>
#include <list>

class Giant : public Enemigo
{
    public:
        Giant(list<Entidad*>* entidades,SDL_Renderer* renderer);
        virtual ~Giant();
        void logica();
    protected:
    private:
};

#endif // GIANT_H
