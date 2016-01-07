#ifndef MAP_H
#define MAP_H

#include "grafico.h"
#include "colisao.h"

ALLEGRO_BITMAP* cria_mapa(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP *tiles);
ALLEGRO_BITMAP* cria_frente(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP *tiles);

#endif