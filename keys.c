#include "keys.h"

/*
void teclas_iniciais()
{
	sprintf(pessoa[0].botao_char[0],"%c",'^');
	sprintf(pessoa[0].botao_char[1],"%c",'|');
	sprintf(pessoa[0].botao_char[2],"%c",'>');
	sprintf(pessoa[0].botao_char[3],"%c",'<');
	sprintf(pessoa[0].botao_char[4],"%c",ALLEGRO_KEY_RCTRL+96);
	sprintf(pessoa[0].botao_char[5],"%c",ALLEGRO_KEY_ALTGR+96);

	sprintf(pessoa[1].botao_char[0],"%c",ALLEGRO_KEY_I+96);
	sprintf(pessoa[1].botao_char[1],"%c",ALLEGRO_KEY_K+96);
	sprintf(pessoa[1].botao_char[2],"%c",ALLEGRO_KEY_L+96);
	sprintf(pessoa[1].botao_char[3],"%c",ALLEGRO_KEY_J+96);
	sprintf(pessoa[1].botao_char[4],"%c",ALLEGRO_KEY_U+96);
	sprintf(pessoa[1].botao_char[5],"%c",ALLEGRO_KEY_O+96);

	sprintf(pessoa[2].botao_char[0],"%c",ALLEGRO_KEY_T+96);
	sprintf(pessoa[2].botao_char[1],"%c",ALLEGRO_KEY_G+96);
	sprintf(pessoa[2].botao_char[2],"%c",ALLEGRO_KEY_H+96);
	sprintf(pessoa[2].botao_char[3],"%c",ALLEGRO_KEY_F+96);
	sprintf(pessoa[2].botao_char[4],"%c",ALLEGRO_KEY_R+96);
	sprintf(pessoa[2].botao_char[5],"%c",ALLEGRO_KEY_Y+96);

	sprintf(pessoa[3].botao_char[0],"%c",ALLEGRO_KEY_W+96);
	sprintf(pessoa[3].botao_char[1],"%c",ALLEGRO_KEY_S+96);
	sprintf(pessoa[3].botao_char[2],"%c",ALLEGRO_KEY_D+96);
	sprintf(pessoa[3].botao_char[3],"%c",ALLEGRO_KEY_A+96);
	sprintf(pessoa[3].botao_char[4],"%c",ALLEGRO_KEY_Q+96);
	sprintf(pessoa[3].botao_char[5],"%c",ALLEGRO_KEY_E+96);

	pessoa[0].botao_char_int[0]=ALLEGRO_KEY_UP;
	pessoa[0].botao_char_int[1]=ALLEGRO_KEY_DOWN;
	pessoa[0].botao_char_int[2]=ALLEGRO_KEY_RIGHT;
	pessoa[0].botao_char_int[3]=ALLEGRO_KEY_LEFT;
	pessoa[0].botao_char_int[4]=ALLEGRO_KEY_RCTRL;
	pessoa[0].botao_char_int[5]=ALLEGRO_KEY_ALTGR;

	pessoa[1].botao_char_int[0]=ALLEGRO_KEY_I;
	pessoa[1].botao_char_int[1]=ALLEGRO_KEY_K;
	pessoa[1].botao_char_int[2]=ALLEGRO_KEY_L;
	pessoa[1].botao_char_int[3]=ALLEGRO_KEY_J;
	pessoa[1].botao_char_int[4]=ALLEGRO_KEY_U;
	pessoa[1].botao_char_int[5]=ALLEGRO_KEY_O;

	pessoa[2].botao_char_int[0]=ALLEGRO_KEY_T;
	pessoa[2].botao_char_int[1]=ALLEGRO_KEY_G;
	pessoa[2].botao_char_int[2]=ALLEGRO_KEY_H;
	pessoa[2].botao_char_int[3]=ALLEGRO_KEY_F;
	pessoa[2].botao_char_int[4]=ALLEGRO_KEY_R;
	pessoa[2].botao_char_int[5]=ALLEGRO_KEY_Y;

	pessoa[3].botao_char_int[0]=ALLEGRO_KEY_W;
	pessoa[3].botao_char_int[1]=ALLEGRO_KEY_S;
	pessoa[3].botao_char_int[2]=ALLEGRO_KEY_D;
	pessoa[3].botao_char_int[3]=ALLEGRO_KEY_A;
	pessoa[3].botao_char_int[4]=ALLEGRO_KEY_Q;
	pessoa[3].botao_char_int[5]=ALLEGRO_KEY_E;
	return;
}
*/

void keyboard_down(int evkeyboardkeycode,int *correr,bool *puxa,int *tlep,int *cx,int *cy,Magia (*fireball)[2],int *energia, Pessoa *p)
{
	for(int i=0; i<4;i++) {
		if(p[i].comp==0) {
			if(evkeyboardkeycode == p[i].botao_char_int[0]) {
				//andou_c[i] = 1;
				p[i].andou_c = 1;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[1]) {
				//andou_b[i] = 1;
				p[i].andou_b = 1;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[2]) {
				//andou_d[i] = 1;
				p[i].andou_d = 1;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[3]) {
				//andou_e[i] = 1;
				p[i].andou_e = 1;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[4]) {
				correr[i] = 2;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[5]) {
				puxa[i] = true;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[6]) {
				tlep[i] = 1;
			}
		}
	}
	switch(evkeyboardkeycode) {   // Os casos DOWN,LEFT,RIGHT,UP sao as setas, e tem que fazer o teu carinha andar. Tah meio bugado, mas funciona um pouco.
		/* Primeiro Player */
        /* Magias */
        case ALLEGRO_KEY_Z:
        	if(fireball[0][0].ativa == true && energia[0] >= 50 && fireball[0][1].ativa == false) {
        		fireball[0][1].ativa = true;
        		fireball[0][1].x = cx[0];
        		fireball[0][1].y = cy[0];
        		fireball[0][1].dist = 0;
        		energia[0] -= 50;
        	}
        	else if(energia[0] >= 50) {
        		fireball[0][0].ativa = true;
        		fireball[0][0].x = cx[0];
        		fireball[0][0].y = cy[0];
        		fireball[0][0].dist = 0;
        		energia[0] -= 50;
        	}
    	default: break;
    }
}


void keyboard_up(int evkeyboardkeycode,int *correr,bool *puxa,bool *sair, Pessoa *p)
{
	for(int i=0; i<4;i++) {
		if(p[i].comp==0) {
			if(evkeyboardkeycode == p[i].botao_char_int[0]) {
				//andou_c[i] = 0;
				p[i].andou_c = 0;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[1]) {
				//andou_b[i] = 0;
				p[i].andou_b = 0;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[2]) {
				//andou_d[i] = 0;
				p[i].andou_d = 0;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[3]) {
				//andou_e[i] = 0;
				p[i].andou_e = 0;
			}
			if(evkeyboardkeycode == p[i].botao_char_int[4]) {
				correr[i] = 1;
			}
		}
	}
}
