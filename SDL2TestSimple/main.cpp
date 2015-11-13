#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<iostream>
#include<fstream>
#include<list>

#include "Jugador.h"
#include "Enemigo.h"
#include "Giant.h"
#include "Knight.h"
#include "Alien.h"
#include "Proyectil.h"
#include "Menu.h"

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*background1, *character;
SDL_Rect rect_background,rect_background1, rect_character,wall;
Mix_Music* music = NULL;
list<Entidad*>entidades;
Menu* menus = new Menu();
Jugador* jugador = new Jugador(&entidades,renderer);
Mix_Chunk *gMedium = NULL;


using namespace std;

int main( int argc, char* args[] )
{
    bool menu = true;
    bool game = true;
    bool pause = false;
    int op = 0;
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }
    //Initialize SDL_mixer
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        cout << "SDL_Mixer could not initialize! SDL_Mixer Error: " << Mix_GetError();
    }

    //Load music
    music = Mix_LoadMUS("darkmoon.wav");
    gMedium = Mix_LoadWAV("laser.wav");

    menus->stable(renderer,background1,rect_background1);

    //Init textures
    do{
        while(SDL_PollEvent(&Event)){

            if(Event.type == SDL_KEYDOWN){
                if(Event.key.keysym.sym == SDLK_LEFT){
                    menus->start(renderer,background1,rect_background1);
                    op=1;
                }

                if(Event.key.keysym.sym == SDLK_RIGHT){
                    menus->quit(renderer,background1,rect_background1);
                    op=2;
                }
                if(Event.key.keysym.sym == SDLK_RETURN){
                    switch(op){

                    case 1:
                        menu = false;
                        break;
                    case 2:
                        SDL_Quit();
                        break;
                    }
                }
            }
        }
    }while(menu);


    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo2.jpg");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    Mix_PlayMusic(music, -1);

    list<Entidad*>entidades;
    Jugador* jg1 = new Jugador(&entidades,renderer);
    entidades.push_back(jg1);
    entidades.push_back(new Giant(&entidades, renderer));
    entidades.push_back(new Knight(&entidades, renderer));
    entidades.push_back(new Alien(&entidades, renderer));

    double last_frame=0;

    //Main Loop
    while(game)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_p){
                    if(pause == false)
                    {
                        pause = true;
                        Mix_PauseMusic();
                    }
                    else
                    {
                        pause = false;
                        Mix_ResumeMusic();
                    }
                }

                if(Event.key.keysym.sym == SDLK_F5){
                    ofstream outx("Posicionx.txt");
                    outx<<jg1->x<<endl;
                    outx.close();
                    ofstream outy("Posiciony.txt");
                    outy<<jg1->y<<endl;
                    outy.close();
                }
                if(Event.key.keysym.sym == SDLK_F9){
                    ifstream inx("Posicionx.txt");
                    double posx, posy;
                    while(inx>>posx){
                        jg1->x = posx;
                    }
                    inx.close();
                    ifstream iny("Posiciony.txt");
                    while(iny>>posy){
                        jg1->y = posy;
                    }
                    iny.close();
                }
                switch(Event.key.keysym.sym)
                {
                    case SDLK_z:
                    Mix_PlayChannel(-1, gMedium, 0);
                    break;
                }

            }
        }

        //SDL_Delay(17-(SDL_GetTicks()-last_frame));
        if(pause == false){

            double diferencia = SDL_GetTicks()-last_frame;
            double ajuste = 17 - diferencia;
            if(ajuste>0)
                SDL_Delay(ajuste);
            last_frame=SDL_GetTicks();

            for(list<Entidad*>::iterator e = entidades.begin();
                e!=entidades.end();
                e++)
                (*e)->logica();


            for(list<Entidad*>::iterator e = entidades.begin();
                e!=entidades.end();
                e++)
            {
                if((*e)->delete_flag)
                {
                    entidades.remove(*e);
                    break;
                }
            }

            SDL_RenderCopy(renderer, background, NULL, &rect_background);

            for(list<Entidad*>::iterator e = entidades.begin();
                e!=entidades.end();
                e++)
                (*e)->dibujar();

            SDL_RenderPresent(renderer);
        }
    }

	return 0;
}
