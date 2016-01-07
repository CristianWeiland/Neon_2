#include "map.h"

ALLEGRO_BITMAP* cria_mapa(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP* tiles)
{
    ALLEGRO_BITMAP *map;
    map = al_create_bitmap(2000,2000);
    int i;
    al_set_target_bitmap(map);
    for(i=0; i< mapsize+1; i++)                            // Imprime cada tile salvado no arquivo.
        al_draw_bitmap_region(tiles,xcorte[i],ycorte[i],64,32,xtile[i],ytile[i],0);
    al_set_target_bitmap(al_get_backbuffer(win.display));  // Isso evita gastar toda a memoria.
    return map;
}

ALLEGRO_BITMAP* cria_frente(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP *tiles)
{
	ALLEGRO_BITMAP *map;
	map = al_create_bitmap(2000,2000);
	int i;
	al_set_target_bitmap(map);
	for(i=0;i<mapsize+1;i++)
	{
	/*     Penultima, antepenultima e a anterior dessa.                                   */
		if( (xtile[i]==0 && (ytile[i]>=863 && ytile[i]<=961) ) || (xtile[i]==64 && (ytile[i]>=863 && ytile[i]<=961) ) || (xtile[i]==128 && (ytile[i]>=767 && ytile[i]<=961) /*&& ytile[i]!=864*/ ) ||
		    ( xtile[i]==192 && (ytile[i]>=799 && ytile[i]<=961) ) || ( (xtile[i]>=255 && xtile[i]<=385) && (ytile[i]>=895 && ytile[i]<=961) ) ||
			( (xtile[i]>=447 && xtile[i]<=577) && (ytile[i]>=863 && ytile[i]<=961) )   )
		{
	        al_draw_bitmap_region(tiles,xtile[i],ytile[i],64,32,xcorte[i],ycorte[i],0);
		}
	}
	al_set_target_bitmap(al_get_backbuffer(win.display));
	return map;
}