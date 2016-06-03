#include "keys.h"

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
#define CORRE 4
#define PUXAR 5
#define FLASH 6

void teclas_iniciais(Pessoa *p)
{
	/*
		Botoes:
		[0] --> Andar pra cima.
		[1] --> Andar pra baixo.
		[2] --> Andar pra direita.
		[3] --> Andar pra esquerda.
		[4] --> Correr.
		[5] --> Puxar.
		[6] --> Tlep.
	*/

	p[0].botao_char_int[UP] = ALLEGRO_KEY_UP;
	p[0].botao_char_int[DOWN] = ALLEGRO_KEY_DOWN;
	p[0].botao_char_int[RIGHT] = ALLEGRO_KEY_RIGHT;
	p[0].botao_char_int[LEFT] = ALLEGRO_KEY_LEFT;
	p[0].botao_char_int[CORRE] = ALLEGRO_KEY_RCTRL;
	p[0].botao_char_int[PUXAR] = ALLEGRO_KEY_ALTGR;
	//p[0].botao_char_int[FLASH] = ALLEGRO_KEY_ALTGR; // Ta comentado porque falta escolher uma tecla pra isso.

	p[1].botao_char_int[UP] = ALLEGRO_KEY_I;
	p[1].botao_char_int[DOWN] = ALLEGRO_KEY_K;
	p[1].botao_char_int[RIGHT] = ALLEGRO_KEY_L;
	p[1].botao_char_int[LEFT] = ALLEGRO_KEY_J;
	p[1].botao_char_int[CORRE] = ALLEGRO_KEY_U;
	p[1].botao_char_int[PUXAR] = ALLEGRO_KEY_O;
	//p[1].botao_char_int[FLASH] = ALLEGRO_KEY_ALTGR;

	p[2].botao_char_int[UP] = ALLEGRO_KEY_T;
	p[2].botao_char_int[DOWN] = ALLEGRO_KEY_G;
	p[2].botao_char_int[RIGHT] = ALLEGRO_KEY_H;
	p[2].botao_char_int[LEFT] = ALLEGRO_KEY_F;
	p[2].botao_char_int[CORRE] = ALLEGRO_KEY_R;
	p[2].botao_char_int[PUXAR] = ALLEGRO_KEY_Y;
	//p[2].botao_char_int[FLASH] = ALLEGRO_KEY_ALTGR;

	p[3].botao_char_int[UP] = ALLEGRO_KEY_W;
	p[3].botao_char_int[DOWN] = ALLEGRO_KEY_S;
	p[3].botao_char_int[RIGHT] = ALLEGRO_KEY_D;
	p[3].botao_char_int[LEFT] = ALLEGRO_KEY_A;
	p[3].botao_char_int[CORRE] = ALLEGRO_KEY_Q;
	p[3].botao_char_int[PUXAR] = ALLEGRO_KEY_E;
	//p[3].botao_char_int[FLASH] = ALLEGRO_KEY_ALTGR;
	return;
}


void keyboard_down(int evkeyboardkeycode,bool *puxa,int *flash, Pessoa *p, Magias *m)
// Provavelmente, quando eu achei a tecla que foi apertada, posso dar um return, e melhorar a eficiencia da função.
{
	for(int i=0; i<4; ++i) {
		//if(p[i].comp==0) {
			if(evkeyboardkeycode == p[i].botao_char_int[0]) {
				p[i].andou_c = 1;
			} else if(evkeyboardkeycode == p[i].botao_char_int[1]) {
				p[i].andou_b = 1;
			} else if(evkeyboardkeycode == p[i].botao_char_int[2]) {
				p[i].andou_d = 1;
			} else if(evkeyboardkeycode == p[i].botao_char_int[3]) {
				p[i].andou_e = 1;
			} else if(evkeyboardkeycode == p[i].botao_char_int[4]) {
				p[i].correr = 2;
			} else if(evkeyboardkeycode == p[i].botao_char_int[5]) {
				puxa[i] = true;
			} else if(evkeyboardkeycode == p[i].botao_char_int[6]) {
				flash[i] = 1;
			}
		//}
	}
	switch(evkeyboardkeycode) {
		/* Primeiro Player */
        /* Magias */
        case ALLEGRO_KEY_Z:
        	if(m->fireball[0][0].ativa == true && p[0].energia >= 50 && m->fireball[0][1].ativa == false) {
        		m->fireball[0][1].ativa = true;
        		m->fireball[0][1].x = p[0].x;
        		m->fireball[0][1].y = p[0].y;
        		m->fireball[0][1].dist = 0;
        		p[0].energia -= 50;
        	}
        	else if(p[0].energia >= 50) {
        		m->fireball[0][0].ativa = true;
        		m->fireball[0][0].x = p[0].x;
        		m->fireball[0][0].y = p[0].y;
        		m->fireball[0][0].dist = 0;
        		p[0].energia -= 50;
        	}
		/* Segundo Player */
		/* Terceiro Player */
		/* Quarto Player */
    	default: break;
    }
}


void keyboard_up(int evkeyboardkeycode,bool *puxa,bool *sair, Pessoa *p)
{
	for(int i=0; i<4; ++i) {
		if(p[i].comp == 0) {
			if(evkeyboardkeycode == p[i].botao_char_int[0]) {
				p[i].andou_c = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[1]) {
				p[i].andou_b = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[2]) {
				p[i].andou_d = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[3]) {
				p[i].andou_e = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[4]) {
				p[i].correr = 1;
			}
		}
	}
}
