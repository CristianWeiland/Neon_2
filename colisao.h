#ifndef COLISAO_H
#define COLISAO_H

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
	int freeze; // Congelado não pode usar magias nem andar. Freeze <= 0 -> não está mais congelado. Freeze > 0, congelado.
} Pessoa;

typedef struct Magia {
	int dano,x,y,dist,xexpl,yexpl;
	bool ativa,explosao;
	ALLEGRO_BITMAP* sprite;
	int d; /* Direcao == -1 significa que nao foi calculada ainda.
				  * 0 = cima; 1 = direita; 2 = esquerda; 3 = baixo; */
} Magia;

typedef struct Magias {
	int explox[4][2], exploy[4][2]; // Selecionam a posicao da explosao no bitmap explo.bmp.
	Magia fireball[4][2];
	Magia iceball[4][2];
} Magias;

typedef struct Sprite {
	ALLEGRO_BITMAP *tiles; // Usado pra coisas dos mapas.
	ALLEGRO_BITMAP **fireballs, *explosion; // Sprite da bola de fogo (cima, dir, esq, baixo) + explosao da fireball.
	ALLEGRO_BITMAP **iceballs, *gelos; // Sprite da bola de fogo (cima, dir, esq, baixo) + explosao da fireball.
	ALLEGRO_BITMAP **neons; // Todos os neons (4 cores, na sequencia: amarelo - azul - verde - vermelho)
	ALLEGRO_BITMAP *bar, *healthbar, *energybar, *frente;
	ALLEGRO_BITMAP *chars, *dead, *chars_congelados;
} Sprite;

/* Se der vontade, vou fazer depois usando uma classe.
class Fireball {
public:
    Fireball() {
        x = y = 0;
        d = -1;
        ativa = false;
        explosao = false;
        xexpl = yexpl = 0;
        dano = 200;
    }

    void set_position(int posx, int posy) {
        x = posx;
        y = posy;
    }

    void set_dir(int direction) {
        d = direction;
    }

    int execute() {
    }

    bool hovering(int mousex, int mousey) {
    }

    void imprime(Sprite s, Pessoa *p, int index) {
    // A pessoa que usou a fireball é p[index].
    	if(!ativa)
    		return;

    	int i;
    	for(i=0; i<4; ++i) {
	    	if(contato_proximo_direcionado(x,y,index,k,d,p) == k) {
				p[k].hp -= dano;
				ativa = false;
				explosao = true;
				d = -1;
			}
		}

		if(dist >= 300) {
			ativa = false;
			explosao = true; // cria_explosao(x,y);
			d = -1;
		}

		if(ativa)
        	al_draw_bitmap(s.fireballs[d],x,y,0);
    }
private:
	int dano, x, y, dist, xexpl, yexpl, d; // D significa a direcao (0 = /\, 1 = ->, 2 = <-, 3 = \/)
	bool ativa,explosao;
};
*/

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
#define PESSOAS 4
#define COMPUTADORES 1

char** le_matriz(FILE *fp);
bool colisao(int,int,char**,int);
int colidiu(char** map,int x,int y,int caso,int eu, Pessoa *p);
int colisao_fireball(char** m,int x,int y,int d);
int contato_proximo(int i,int j, Pessoa *p);
int contato_proximo_direcionado(int x,int y,int i,int j,int d, Pessoa *p);

#endif
