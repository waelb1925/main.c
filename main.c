#include<stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include<SDL/SDL_audio.h>
#include "coin.h"
void main()
{
int cont=1;
SDL_Surface *fond=NULL;
SDL_Surface *ecran=NULL;
SDL_Surface *coin=NULL;
SDL_Event event; 
SDL_Event even;
SDL_Rect positionfond;
SDL_Rect positioncoin;

positionfond.x=0;
positionfond.y=0;

  coin=IMG_Load("jeton.png");

positioncoin.x=50;
positioncoin.y=10;
positioncoin.h=coin->h;
positioncoin.w=coin->w;
SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO);
ecran=SDL_SetVideoMode(576,222, 32,SDL_HWSURFACE|SDL_DOUBLEBUF);
if (ecran==NULL)
printf ("Erreur");
fond=IMG_Load("level1.png");
if(!coin)
  {
     printf("Error: %s\n",SDL_GetError());

  }

 init_coin(&coin) ;
while (cont){


SDL_BlitSurface(fond,NULL,ecran,&positionfond);
SDL_BlitSurface(coin,NULL,ecran,&positioncoin);
	

	
 affiche_coin(&coin,ecran);
SDL_Flip (ecran);


}
SDL_Quit();	
}


