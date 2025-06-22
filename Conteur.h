#ifndef CONTEUR_H
#define CONTEUR_H
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Conteur
{
  private:

       SDL_Texture* texture;
       SDL_Surface* surface;
       SDL_Rect rect;
       TTF_Font *font;
       char texte[16];
       SDL_Color  couleur;
       SDL_Rect dst;

  public:

      Conteur(SDL_Rect Conteur,const char* police);
      void formater_temps(Uint32 ms);
      void   render(SDL_Renderer* ren);
      void clean();
      ~Conteur();
};

#endif // CONTEUR_H
