#include "pierre.h"

pierre::pierre(SDL_Rect rct1,SDL_Rect rct2){

              Pierre1= rct1;
               Pierre2=rct2 ;
      }

void pierre::init(SDL_Renderer* ren){
           imgPierre=IMG_LoadTexture(ren,"pierre.png");

     }

void pierre::initXpos(){

          Pierre1.x=1200;
          Pierre2.x=1400;
    }

void pierre::Update(){
         cmp=4;
         Pierre1.x-=cmp;
         Pierre2.x-=cmp;
if(Pierre1.x<-40){

        Pierre1.x=1200;
        Pierre1.y=400+(rand()%100);
        Pierre1.w=30+(rand()%20);
        Pierre1.h=20+(rand()%10);
    }
if(Pierre2.x<-40){
       Pierre2.x=1350;
       Pierre2.y=300+(rand()*rand()%100);
       Pierre2.w=20+(rand()%20);
       Pierre2.h=10+(rand()%20);
    }
}

bool pierre::checkcollisse( const SDL_Rect& player){

      return (Pierre1.x<player.x+player.w &&player.x<Pierre1.x&& player.y<Pierre1.y+Pierre1.h && Pierre1.y<player.y+player.h )
           ||(Pierre2.x<player.x+player.w &&player.x<Pierre2.x&& player.y<Pierre2.y+Pierre2.h && Pierre2.y<player.y+player.h );

   }

void pierre::render(SDL_Renderer * ren){
      SDL_RenderCopy(ren,imgPierre,NULL,&Pierre1);
      SDL_RenderCopy(ren,imgPierre,NULL,&Pierre2);
  }

void pierre::clean(){
SDL_DestroyTexture(imgPierre);
   }

pierre::~pierre()
{}
