#include "Menu.h"
#include <iostream>
using namespace std;
Menu::Menu(const char* BGmenu,const char* imgbtnP,const char* imgbtnQ,const char* imgbtnProp)
{

if(SDL_Init(SDL_INIT_EVERYTHING)==0){
    cout <<"tous 1 ere les sous-systèmes principaux est initilise"<<std::endl;

    windows1=SDL_CreateWindow("CYCLIST DODGER",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,600,SDL_WINDOW_SHOWN |SDL_WINDOW_RESIZABLE);

   if(!windows1){
      cout<< "ERROR : "<<SDL_GetError()<<endl;
         }

render=SDL_CreateRenderer(windows1,-1,SDL_RENDERER_ACCELERATED);
    if(!render){
       cout<< "ERROR : "<<SDL_GetError()<<endl;
    }

BG=IMG_LoadTexture(render,BGmenu);
btnplay=IMG_LoadTexture(render,imgbtnP);
btnProprie=IMG_LoadTexture(render,imgbtnProp);
btnQuite=IMG_LoadTexture(render,imgbtnQ);
 P={400,100,200,150};
 Q={700,100,200,150};
 Prop={100,100,200,150};
Running=true;

}
else{
Running=false;
  }
}

 Menu::~Menu(){}

void Menu::Event(){
    SDL_Event e;
    while(SDL_PollEvent(&e)){
        if(e.type==SDL_QUIT){
            Running=false;
        }
        if(e.type==SDL_MOUSEBUTTONDOWN){
            int xbtn=e.button.x;
            int ybtn=e.button.y;
           if(xbtn>P.x && xbtn<(P.x+P.w) && ybtn>P.y && ybtn<(P.y+P.h)){
                  numero=1;
                  Running=false;
            }
            if(xbtn >Q.x && xbtn<(Q.x+Q.w) && ybtn>Q.y && ybtn<(Q.y+Q.h)){
                Running=false;
            }
             if(xbtn >Prop.x && xbtn<(Prop.x+Prop.w) && ybtn>Prop.y && ybtn<(Prop.y+Prop.h)){
                numero=2;
                Running=false;
            }
        }
      }
    }

void Menu::renderer(){
SDL_RenderClear(render);
SDL_RenderCopy(render,BG,NULL,NULL);
SDL_RenderCopy(render,btnplay,NULL,&P);
SDL_RenderCopy(render,btnProprie,NULL,&Prop);
SDL_RenderCopy(render,btnQuite,NULL,&Q);
SDL_RenderPresent(render);

}

void Menu::clean(){
    SDL_DestroyWindow(windows1);
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(btnplay);
    SDL_DestroyTexture(btnProprie);
    SDL_DestroyTexture(btnQuite);
    IMG_Quit();
    SDL_Quit();
}

void Menu::RunMenu(){
while(Running){
  Event();
  renderer();
  }
clean();
}













