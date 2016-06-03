#include "keys.h"


void teclas_iniciais(Pessoa *p, FILE *errext)
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

	//  Não sei exatamente o que faz isso. É bom dar uma olhada.
	for(int i=0; i<4; ++i) {
		for(int j=0; j<7; ++j) {
			p[i].botao_char[j] = (char*) malloc(30 * sizeof(char));
			if(!(p[i].botao_char[j])) {
				fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[%d]",i,j);
				fclose(errext);
				exit(1);
			}
		}
		sprintf(p[i].botao_char[0],"%c",98);
		sprintf(p[i].botao_char[1],"%c",99);
		sprintf(p[i].botao_char[2],"%c",100);
		sprintf(p[i].botao_char[3],"%c",101);
		sprintf(p[i].botao_char[4],"%c",97);
		sprintf(p[i].botao_char[5],"%c",97);
		sprintf(p[i].botao_char[6],"%c",97);
		p[i].nome = (char*) malloc(30*sizeof(char));
		if(!p[i].nome) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].nome",i);
			fclose(errext);
			exit(1);
		}
		sprintf(p[i].nome,"player %d",i+1);
	}

	sprintf(p[0].botao_char[0],"%c",'^');
	sprintf(p[0].botao_char[1],"%c",'|');
	sprintf(p[0].botao_char[2],"%c",'>');
	sprintf(p[0].botao_char[3],"%c",'<');
	sprintf(p[0].botao_char[4],"%c",ALLEGRO_KEY_RCTRL+96);
	sprintf(p[0].botao_char[5],"%c",ALLEGRO_KEY_ALTGR+96);

	sprintf(p[1].botao_char[0],"%c",ALLEGRO_KEY_I+96);
	sprintf(p[1].botao_char[1],"%c",ALLEGRO_KEY_K+96);
	sprintf(p[1].botao_char[2],"%c",ALLEGRO_KEY_L+96);
	sprintf(p[1].botao_char[3],"%c",ALLEGRO_KEY_J+96);
	sprintf(p[1].botao_char[4],"%c",ALLEGRO_KEY_U+96);
	sprintf(p[1].botao_char[5],"%c",ALLEGRO_KEY_O+96);

	sprintf(p[2].botao_char[0],"%c",ALLEGRO_KEY_T+96);
	sprintf(p[2].botao_char[1],"%c",ALLEGRO_KEY_G+96);
	sprintf(p[2].botao_char[2],"%c",ALLEGRO_KEY_H+96);
	sprintf(p[2].botao_char[3],"%c",ALLEGRO_KEY_F+96);
	sprintf(p[2].botao_char[4],"%c",ALLEGRO_KEY_R+96);
	sprintf(p[2].botao_char[5],"%c",ALLEGRO_KEY_Y+96);

	sprintf(p[3].botao_char[0],"%c",ALLEGRO_KEY_W+96);
	sprintf(p[3].botao_char[1],"%c",ALLEGRO_KEY_S+96);
	sprintf(p[3].botao_char[2],"%c",ALLEGRO_KEY_D+96);
	sprintf(p[3].botao_char[3],"%c",ALLEGRO_KEY_A+96);
	sprintf(p[3].botao_char[4],"%c",ALLEGRO_KEY_Q+96);
	sprintf(p[3].botao_char[5],"%c",ALLEGRO_KEY_E+96);

	p[0].botao_char_int[0] = ALLEGRO_KEY_UP;
	p[0].botao_char_int[1] = ALLEGRO_KEY_DOWN;
	p[0].botao_char_int[2] = ALLEGRO_KEY_RIGHT;
	p[0].botao_char_int[3] = ALLEGRO_KEY_LEFT;
	p[0].botao_char_int[4] = ALLEGRO_KEY_RCTRL;
	p[0].botao_char_int[5] = ALLEGRO_KEY_ALTGR;

	p[1].botao_char_int[0] = ALLEGRO_KEY_I;
	p[1].botao_char_int[1] = ALLEGRO_KEY_K;
	p[1].botao_char_int[2] = ALLEGRO_KEY_L;
	p[1].botao_char_int[3] = ALLEGRO_KEY_J;
	p[1].botao_char_int[4] = ALLEGRO_KEY_U;
	p[1].botao_char_int[5] = ALLEGRO_KEY_O;

	p[2].botao_char_int[0] = ALLEGRO_KEY_T;
	p[2].botao_char_int[1] = ALLEGRO_KEY_G;
	p[2].botao_char_int[2] = ALLEGRO_KEY_H;
	p[2].botao_char_int[3] = ALLEGRO_KEY_F;
	p[2].botao_char_int[4] = ALLEGRO_KEY_R;
	p[2].botao_char_int[5] = ALLEGRO_KEY_Y;

	p[3].botao_char_int[0] = ALLEGRO_KEY_W;
	p[3].botao_char_int[1] = ALLEGRO_KEY_S;
	p[3].botao_char_int[2] = ALLEGRO_KEY_D;
	p[3].botao_char_int[3] = ALLEGRO_KEY_A;
	p[3].botao_char_int[4] = ALLEGRO_KEY_Q;
	p[3].botao_char_int[5] = ALLEGRO_KEY_E;
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
	switch(evkeyboardkeycode) {   // Os casos DOWN,LEFT,RIGHT,UP sao as setas, e tem que fazer o teu carinha andar. Tah meio bugado, mas funciona um pouco.
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
