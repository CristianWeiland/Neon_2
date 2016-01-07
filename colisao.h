#ifndef COLISAO_H
#define COLISAO_H

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

//ALLEGRO_FONT *font5;

typedef struct Pessoa {
	int x,y,desx,desy,selx,sely,hp; // Desx e desy escolhem o char na imagem; Selx e sely escolhem qual sprite do char (olhando pra cima,esq,...)
	int xneon,yneon;
	int andou_b,andou_c,andou_d,andou_e;
	char *botao_b, *botao_c, *botao_d, *botao_e;
	char *nome,*ataque;
	char *botao_char[7];
	int energia,correr,morto,dash;
	int comp;
	int botao_char_int[7],time;
} Pessoa;

typedef struct Magia {
	int dano,x,y,dist;
	bool ativa,explosao;
	ALLEGRO_BITMAP* sprite;
	int d; /* Direcao == -1 significa que nao foi calculada ainda.
				  * 0 = cima; 1 = direita; 2 = esquerda; 3 = baixo; */
} Magia;

typedef struct Sprite {
	//*tiles,*chars,*map,*frente,**neons,**fireballs,*explosion;
	ALLEGRO_BITMAP *tiles;
	//ALLEGRO_BITMAP
	//ALLEGRO_BITMAP
	//ALLEGRO_BITMAP
	//ALLEGRO_BITMAP
	ALLEGRO_BITMAP *chars;
} Sprite;

#define CONT 2
#define NEONAMARELO 1
#define NEONAZUL 2
#define NEONVERDE 3
#define NEONVERMELHO 4
#define TAM 1000
#define BAIXO 0
#define ESQ 1
#define CIMA 2
#define DIR 3

char** le_matriz(FILE *fp);
bool colisao(int,int,char**,int);
int colidiu(char** map,int x,int y,int caso,int eu, Pessoa *p);
int colisao_fireball(char** m,int x,int y,int d);
int contato_proximo(int i,int j, Pessoa *p);
int contato_proximo_direcionado(int x,int y,int i,int j,int d, Pessoa *p);

#endif
