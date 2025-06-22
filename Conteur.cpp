#include "Conteur.h"

Conteur::Conteur(SDL_Rect rctC,const char* police)
{
     TTF_Init();
     font=TTF_OpenFont(police,48);
     couleur={255,255,255};//blache
     dst=rctC;
}

void Conteur::formater_temps(Uint32 ms){
     Uint32 s = ms / 1000;
     Uint32 m = s / 60;
     Uint32 h = m / 60;
     s %= 60;
     m %= 60;
     sprintf(texte, "%02u:%02u:%02u", h, m, s);
}
void Conteur::render(SDL_Renderer* ren){

    surface=TTF_RenderText_Solid(font,texte,couleur);
    texture=SDL_CreateTextureFromSurface(ren,surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(ren,texture,NULL,&dst);
}

void Conteur::clean(){
    SDL_DestroyTexture(texture);
    TTF_Quit();
}
Conteur::~Conteur(){}
