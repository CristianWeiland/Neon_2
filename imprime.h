#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Allegro */
#ifndef ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#endif

#include "colisao.h"

#define CONT 2
#define NEONAMARELO 1
#define NEONAZUL 2
#define NEONVERDE 3
#define NEONVERMELHO 4
#define LARGURA_CHAR 32
#define ALTURA_CHAR 32

void imprime_pessoa(Pessoa p);
void imprime_char(int cx,int cy,int a,int b,int selx,int sely,Sprite s);
void imprime_neon(int x,int y,ALLEGRO_BITMAP* neon,bool temneon);
int imprime_4_chars_for(int cont,char** matriz,int *cor,bool *temneon,int njogadores,Pessoa *p,Sprite s);
