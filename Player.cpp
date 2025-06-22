#include "Player.h"

Player::Player(int x,int y,int w,int h){
         dst={x,y,w,h};
     }

void Player::init(SDL_Renderer* ren){
         player1=IMG_LoadTexture(ren,"imgcycle.png");
         player2=IMG_LoadTexture(ren,"imgcycle1.png");
         switchP=player1;

    }

void Player::switchPlayer(){

         switchP=(switchP==player1)?player2:player1;

    }

void Player::Update(int click){

    if(click==SDLK_DOWN){
         dst.y+=5;
         }
   if(click==SDLK_UP){
       dst.y-=5;
         }
    }

SDL_Rect& Player::getRectP(){
     return dst;
    }

void Player::render(SDL_Renderer* ren){
         SDL_RenderCopy(ren,switchP,NULL,&dst);
    }

void  Player::cleanP(){

    SDL_DestroyTexture(player1);
    SDL_DestroyTexture(player2);

    }






