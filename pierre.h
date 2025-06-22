#ifndef PIERRE_H
#define PIERRE_H
#include <SDL.h>
#include <SDL2/SDL_image.h>

class pierre
{
   private:

      SDL_Rect Pierre1;
      SDL_Rect Pierre2;
      SDL_Texture* imgPierre;
      int cmp=0;

   public:

      pierre(SDL_Rect,SDL_Rect);
      ~pierre();
      void init(SDL_Renderer* ren);
      void initXpos();
      void Update();
      bool checkcollisse(const SDL_Rect& );
      void render(SDL_Renderer* ren);
      void clean();

};

#endif // PIERRE_H
