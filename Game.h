#ifndef GAME_HPP
#define GAME_HPP
#include "pierre.h"
#include "Player.h"
#include "Conteur.h"
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;


class Game{
public:
    Game(const char* title ,int xpos ,int ypos ,int  width ,int height ,bool show,SDL_Rect rctP,SDL_Rect rctCol1,SDL_Rect rctCol2,Conteur C);
    ~Game();
     void handleEvents();
     void update();
     void Drawimage() ;
     void render();
     void RunGame();
     void checkReplaye();
     bool getover();
     void clean();
private:
     Player joueur;
     pierre pierre;
     Conteur conteur;
     SDL_Window * window;
     SDL_Renderer* rennder;
     SDL_Texture* background1;
     SDL_Rect dest1;
     SDL_Rect dest2;
     SDL_Texture* btnReplay;
     SDL_Rect rctReplay;
     SDL_Texture* G_over;
     SDL_Rect rctover;
     const int FPS=90;
     const int frameDelay=1000/FPS;
     Uint32 frameStart;
     Uint32 timeConteur;
     Uint32 timerest=0;
     int frameTime;
     int roadScroll=0;
     bool Running;

     bool overG=false;
};
#endif // GAME_HPP
