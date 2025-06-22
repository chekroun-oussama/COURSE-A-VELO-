#ifndef MENU_H
#define MENU_H
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "Game.h"
#include "About.h"
#include <iostream>
using namespace std;
class Menu
{
    private:

        SDL_Window* windows1;
        SDL_Renderer* render;
        SDL_Texture* BG;
        SDL_Texture* btnplay;
        SDL_Rect P;
        SDL_Texture* btnProprie;
        SDL_Rect Prop;
        SDL_Texture* btnQuite;
        SDL_Rect Q;
        int numero=0;
        bool Running;
    public:

        Menu(const char* BGmenu,const char* imgbtnP,const char* imgbtnQ,const char* imgbtnProp);
        ~Menu();
        void Event();
        void renderer();
        void RunMenu();
        int getNumber(){return numero;}
        void clean();

};

#endif // MENU_H
