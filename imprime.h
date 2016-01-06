#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Allegro */
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#include "colisao.h"

#define CONT 2
#define NEONAMARELO 1
#define NEONAZUL 2
#define NEONVERDE 3
#define NEONVERMELHO 4

extern Pessoa pessoa[4];

void imprime_char(int cx,int cy,int a,int b,int selx,int sely,ALLEGRO_BITMAP *chars);
void imprime_neon(int x,int y,ALLEGRO_BITMAP* neon,bool temneon);
int imprime_4_chars_for(int cont,int desx[],int desy[],int cx[],int cy[],int andou_b[],int andou_c[],int andou_d[],int andou_e[],int correr[],int energia[],int xneon[],int yneon[],char** matriz,ALLEGRO_BITMAP** neons,ALLEGRO_BITMAP *chars,int *cor,bool *temneon,int njogadores);
