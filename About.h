#ifndef ABOUT_H
#define ABOUT_H
#include "SDL.h"
#include "SDL2/SDL_image.h"
#include "iostream"
using namespace std;
class About
{
    private:

       SDL_Window* about;
       SDL_Renderer* renderer;
       SDL_Texture* imgAbout;
       SDL_Texture* revenir;
       SDL_Rect rctR;
       int  isnumber=0;
    public:

      About(char*,char*);
      ~About();
      void RunAbout();
      void Event();
      void  render();
      void clean();
      int number(){return isnumber;}
      int Running=0;
};

#endif // ABOUT_H
