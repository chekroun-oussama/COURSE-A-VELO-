#include "Game.h"





Game::Game(const char* title ,int xpos ,int ypos ,int  width ,int height ,bool show,SDL_Rect rctP,SDL_Rect rctCol1,SDL_Rect rctCol2,Conteur C)
:joueur(rctP.x,rctP.y,rctP.w,rctP.h),pierre(rctCol1,rctCol2),conteur(C){
               int flags=0;
              //gemeover
              rctover={400,200,250,200};
              //replay
              rctReplay={0,0,100,70};
    if(show){
              flags=SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
         }
    if(SDL_Init(SDL_INIT_EVERYTHING) ==0)
         {
              cout <<"tous les sous-systèmes principaux est initilise"<<std::endl;
              window=SDL_CreateWindow(title,xpos,ypos,width,height,flags);

        if(window)
        {
              cout<<"window created "<<std::endl;
         }
             rennder=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
        if(rennder){
            pierre.init(rennder);
            joueur.init(rennder);
            SDL_SetRenderDrawColor(rennder,255,0,0,255);
            std::cout<<"render created "<<std::endl;
         }

           Running=true;
           background1=IMG_LoadTexture(rennder,"route1.png");//background
          //int roadH;
          // SDL_QueryTexture(background1,NULL,NULL,&roadwight,&roadH);
          G_over=IMG_LoadTexture(rennder,"over.png");
          btnReplay=IMG_LoadTexture(rennder,"replay.png");
          joueur.init(rennder);
          pierre.init(rennder);

     }

    else{
         Running=false;
    }
}

void  Game::handleEvents(){
       SDL_Event e;
       while(SDL_PollEvent(&e)) {
            if(e.type==SDL_QUIT){
                Running=false;
            }
            if(e.type==SDL_KEYDOWN){
                if(!overG){
                 switch(e.key.keysym.sym){
                    case SDLK_DOWN:
                      joueur.Update(SDLK_DOWN);
                      joueur.switchPlayer();

                      break;
                   case SDLK_UP:

                      joueur.Update(SDLK_UP);
                      joueur.switchPlayer();

                     break;
                    }
               }
          }

            if(e.type==SDL_MOUSEBUTTONDOWN){
                int xrep=e.button.x;
                int yrep=e.button.y;
                      if(xrep >=rctReplay.x && xrep<=rctReplay.x+rctReplay.w && yrep>=rctReplay.y && yrep <=rctReplay.y+rctReplay.h){
                           overG=false;
                           pierre.initXpos();

                       }
                     }
                  }
                }


void Game::Drawimage() {
    //1536:la largeur de votre image BG:
  if(!overG){
         roadScroll+=2;
    if(roadScroll>=1536){
        roadScroll=0;
         }
    dest1={-roadScroll,0,1536,600};
    dest2={1536-roadScroll,0,1536,600};
   }
}


void Game::update(){

if(!pierre.checkcollisse(joueur.getRectP()) && !pierre.checkcollisse(joueur.getRectP())){
      pierre.Update();
    }
else
    overG=true;
}

void Game::render(){

      SDL_RenderClear(rennder);
      SDL_RenderCopy(rennder,background1,NULL,&dest1);
      SDL_RenderCopy(rennder,background1,NULL,&dest2);
      joueur.render(rennder);
      pierre.render(rennder);
      conteur.render(rennder);
      if(overG){

        SDL_Texture* Over=IMG_LoadTexture(rennder,"over.png");
        SDL_Texture* Replaye=IMG_LoadTexture(rennder,"replay.png");
        SDL_RenderCopy(rennder,Replaye,NULL,&rctReplay);
        SDL_RenderCopy(rennder,Over,NULL,&rctover);

         }
       SDL_RenderPresent(rennder);
}

void Game::clean(){

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(rennder);
    SDL_DestroyTexture(background1);
    pierre.clean();
    joueur.cleanP();
    IMG_Quit();
    SDL_Quit();
    std::cout <<"game cleaned "<< std::endl;
}

//je utilise le FPS pour limiter la vitesse d'execution de jeux
   void Game::RunGame(){

        srand(time(NULL));
            while(Running){
               if(overG){
                    timerest=SDL_GetTicks();
                      }
                    Drawimage();
                    frameStart=SDL_GetTicks();
                    update();
                    handleEvents();
               if(!overG){
                    timeConteur=SDL_GetTicks()-timerest;
                      }
                    frameTime=SDL_GetTicks()-frameStart;
                    conteur.formater_temps(timeConteur);
                    render();//affiche
               if(frameDelay>frameTime){

                   SDL_Delay(frameDelay -frameTime);

                      }
    }
    clean();
}
Game::~Game(){};
