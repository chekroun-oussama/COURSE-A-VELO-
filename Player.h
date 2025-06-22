#ifndef PLAYER_H
#define PLAYER_H
#include <SDL.h>
#include "SDL2/SDL_image.h"

class Player{
    private:

      SDL_Texture *player1;
      SDL_Texture *player2;
      SDL_Texture *switchP;
      SDL_Rect dst;

    public:

       Player(int x,int y,int w,int h) ;
       void init(SDL_Renderer* ren);
       void render(SDL_Renderer* ren);
       void Update(int click);
       SDL_Rect & getRectP();
       void switchPlayer();
       void cleanP();

};

#endif // PLAYER_H

