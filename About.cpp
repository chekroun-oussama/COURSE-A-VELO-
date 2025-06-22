#include "About.h"

About::About(char *imgBGm,char *imgrevenir)
{
     if(SDL_Init(SDL_INIT_VIDEO)==0){
                cout<<"initialisation ";

         about=SDL_CreateWindow("ABOUT",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1000,600,SDL_WINDOW_SHOWN);
           if(about){
            cout<<"create window"<<endl;
           }
         renderer=SDL_CreateRenderer(about,-1,SDL_RENDERER_ACCELERATED);
         if(renderer){
     cout<<"create render"<<endl;
            }
            rctR={0,520,100,80};
           imgAbout=IMG_LoadTexture(renderer,imgBGm);
           revenir=IMG_LoadTexture(renderer,imgrevenir);
           Running=true;
           }
           else   Running=false;
        }

About::~About()
{}

void About::Event(){
                SDL_Event e;
                while(SDL_PollEvent(&e)){
            if(e.type==SDL_QUIT){
                Running=0;
            }
           if(e.type==SDL_MOUSEBUTTONDOWN){
            int xbtn=e.button.x;
            int ybtn=e.button.y;
           if(xbtn>rctR.x && xbtn<(rctR.x+rctR.w) && ybtn>rctR.y && ybtn<(rctR.y+rctR.h)){
                isnumber=1;
                 Running=0;
            }
          }
       }
    }
void About::RunAbout(){
while(Running){
   Event();
   render();
}
clean();
}
 void About::render(){
   SDL_RenderClear(renderer);
   SDL_RenderCopy(renderer,imgAbout,NULL,NULL);
     SDL_RenderCopy(renderer,revenir,NULL,&rctR);
   SDL_RenderPresent(renderer);
 }


 void About::clean(){
SDL_DestroyWindow(about);
SDL_DestroyRenderer(renderer);
SDL_DestroyTexture(revenir);
SDL_DestroyTexture(imgAbout);
IMG_Quit();
SDL_Quit();
 }
