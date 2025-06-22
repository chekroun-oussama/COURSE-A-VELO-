#define SDL_MAIN_HANDLED
#include "Game.h"
#include "Menu.h"
#include "About.h"
#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
using namespace std;

// يجب أن تُسمى هذه الدالة بـ SDL_main بدلاً من main
   int main(int argc, char* argv[]) {

       SDL_Rect rctP={40,400,80,70},rctC1={1200,400,40,30},rctC2={1400,400,40,30},rctConteur{450,0,120,100};
       Conteur C(rctConteur,"C:\\Windows\\Fonts\\arial.ttf");
       Menu menu("BGmenu.png","btnPLAY.png","btnQUIT.png","ABOUT.png");
      menu.RunMenu();
   if(menu.getNumber()==2){
         About about("BGabout.png","btnReturn.png");
         about.RunAbout();
         if(about.number()){
          Menu menu("BGmenu.png","btnPLAY.png","btnQUIT.png","ABOUT.png");
          menu.RunMenu();
            if(menu.getNumber()==1){
        Game game("Obstacle Race",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,600,true,rctP,rctC1,rctC2,C);
        game.RunGame();

          }
       }
    }
       if(menu.getNumber()==1){
        Game game("Obstacle Race",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,600,true,rctP,rctC1,rctC2,C);
        game.RunGame();
       }
    return 0;
}

