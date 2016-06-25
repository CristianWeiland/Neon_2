#include "keys.h"

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
		[6] --> Flash.
		[7] --> Iceball.
	*/

	/* Checa se existe arquivo de comandos. Se sim, carrega dados dele. */
	if( access("Comandos/cmd.txt", F_OK) != -1 ) {
		FILE *cmd = fopen("Comandos/cmd.txt","r");
		for(int i=0; i<PESSOAS; ++i) {
			for(int j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
				fscanf(cmd, "%d\n", &(p[i].botao_char_int[j]));
		    }
		}
		fclose(cmd);
		return ;
	}

	/* Como não existia o arquivo, atribui valores padrão. */
	p[0].botao_char_int[UP] = ALLEGRO_KEY_UP;
	p[0].botao_char_int[DOWN] = ALLEGRO_KEY_DOWN;
	p[0].botao_char_int[RIGHT] = ALLEGRO_KEY_RIGHT;
	p[0].botao_char_int[LEFT] = ALLEGRO_KEY_LEFT;
	p[0].botao_char_int[CORRE] = ALLEGRO_KEY_INSERT;
	p[0].botao_char_int[PUXAR] = ALLEGRO_KEY_HOME;
	p[0].botao_char_int[FLASH] = ALLEGRO_KEY_PGUP;
	p[0].botao_char_int[ICEBALL] = ALLEGRO_KEY_DELETE;
	p[0].botao_char_int[TRAP] = ALLEGRO_KEY_M;

	p[1].botao_char_int[UP] = ALLEGRO_KEY_I;
	p[1].botao_char_int[DOWN] = ALLEGRO_KEY_K;
	p[1].botao_char_int[RIGHT] = ALLEGRO_KEY_L;
	p[1].botao_char_int[LEFT] = ALLEGRO_KEY_J;
	p[1].botao_char_int[CORRE] = ALLEGRO_KEY_U;
	p[1].botao_char_int[PUXAR] = ALLEGRO_KEY_9;
	p[1].botao_char_int[FLASH] = ALLEGRO_KEY_8;
	p[1].botao_char_int[ICEBALL] = ALLEGRO_KEY_7;
	p[1].botao_char_int[TRAP] = ALLEGRO_KEY_N;

	p[2].botao_char_int[UP] = ALLEGRO_KEY_T;
	p[2].botao_char_int[DOWN] = ALLEGRO_KEY_G;
	p[2].botao_char_int[RIGHT] = ALLEGRO_KEY_H;
	p[2].botao_char_int[LEFT] = ALLEGRO_KEY_F;
	p[2].botao_char_int[CORRE] = ALLEGRO_KEY_R;
	p[2].botao_char_int[PUXAR] = ALLEGRO_KEY_Y;
	p[2].botao_char_int[FLASH] = ALLEGRO_KEY_5;
	p[2].botao_char_int[ICEBALL] = ALLEGRO_KEY_4;
	p[2].botao_char_int[TRAP] = ALLEGRO_KEY_N;

	p[3].botao_char_int[UP] = ALLEGRO_KEY_W;
	p[3].botao_char_int[DOWN] = ALLEGRO_KEY_S;
	p[3].botao_char_int[RIGHT] = ALLEGRO_KEY_D;
	p[3].botao_char_int[LEFT] = ALLEGRO_KEY_A;
	p[3].botao_char_int[CORRE] = ALLEGRO_KEY_Q;
	p[3].botao_char_int[PUXAR] = ALLEGRO_KEY_3;
	p[3].botao_char_int[FLASH] = ALLEGRO_KEY_2;
	p[3].botao_char_int[ICEBALL] = ALLEGRO_KEY_1;
	p[3].botao_char_int[TRAP] = ALLEGRO_KEY_N;

	return;
}


void keyboard_down(int evkeyboardkeycode,bool *puxa,int *flash, Pessoa *p, Magias *m, int njogadores)
// Provavelmente, quando eu achei a tecla que foi apertada, posso dar um return, e melhorar a eficiencia da função.
{
	for(int i=0; i<njogadores; ++i) {
		//if(p[i].comp==0) {
		// Se estiver congelado não pode fazer nada, mas indica que quer fazer com 2..
		if(evkeyboardkeycode == p[i].botao_char_int[UP]) {
			p[i].andou_c = (p[i].freeze <= 0) ? 1 : 2;
		} else if(evkeyboardkeycode == p[i].botao_char_int[DOWN]) {
			p[i].andou_b = (p[i].freeze <= 0) ? 1 : 2;
		} else if(evkeyboardkeycode == p[i].botao_char_int[RIGHT]) {
			p[i].andou_d = (p[i].freeze <= 0) ? 1 : 2;
		} else if(evkeyboardkeycode == p[i].botao_char_int[LEFT]) {
			p[i].andou_e = (p[i].freeze <= 0) ? 1 : 2;
		} else if(evkeyboardkeycode == p[i].botao_char_int[CORRE]) {
			p[i].correr = 2;
		} else if(evkeyboardkeycode == p[i].botao_char_int[PUXAR]) {
			puxa[i] = true;
		} else if(evkeyboardkeycode == p[i].botao_char_int[FLASH]) {
			flash[i] = 1;
		} else if(evkeyboardkeycode == p[i].botao_char_int[ICEBALL]) {
			/* Pediu pra usar iceball. Vê se atende aos requisitos:
				- Não congelado.
				- Tem energia suficiente.
				- Não usou as duas iceballs possíveis ainda.
			   Depois disso, vê se é a primeira ou a segunda posição da estrutura de magias que eu ativo. */
			if(m->iceball[i][0].ativa == true && p[i].energia >= 50 && m->iceball[i][1].ativa == false && p[i].freeze <= 0) {
        		m->iceball[i][1].ativa = true;
        		m->iceball[i][1].x = p[i].x;
        		m->iceball[i][1].y = p[i].y;
        		m->iceball[i][1].dist = 0;
        		p[i].energia -= 50;
        	} else if(p[i].energia >= 50 && p[i].freeze <= 0) {
        		m->iceball[i][0].ativa = true;
        		m->iceball[i][0].x = p[i].x;
        		m->iceball[i][0].y = p[i].y;
        		m->iceball[i][0].dist = 0;
        		p[i].energia -= 50;
        	}
		}
	}/*
	switch(evkeyboardkeycode) {
		/* Primeiro Player */
        /* Magias */

        /* Fireball */
       /* case ALLEGRO_KEY_X:
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
        	break;
		/* Segundo Player */
		/* Terceiro Player */
		/* Quarto Player */
    	/*default: break;
    }*/
}


void keyboard_up(int evkeyboardkeycode,bool *puxa,bool *sair, Pessoa *p, int njogadores)
{
	for(int i=0; i<njogadores; ++i) {
		if(p[i].comp == 0) {
			if(evkeyboardkeycode == p[i].botao_char_int[UP]) {
				p[i].andou_c = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[DOWN]) {
				p[i].andou_b = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[RIGHT]) {
				p[i].andou_d = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[LEFT]) {
				p[i].andou_e = 0;
			} else if(evkeyboardkeycode == p[i].botao_char_int[CORRE]) {
				p[i].correr = 1;
			}
		}
	}
}
