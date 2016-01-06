#include "magia.h"

inline void tira_neon(bool *puxa,bool *temneon,int *cx,int *cy, Pessoa *p)
{
	int j;
	for(int i=0;i<4;i++) {
		if(puxa[i]) {
			if(j = contato_proximo(cx,cy,i,j,p) != 5)
				temneon[j] = false;
		}
	}
	return ;
}

inline void desconta_energia(Pessoa *p, int njogadores)
{
	for(int i=0; i<njogadores; ++i)
	    if((p[i].andou_b == 1 || p[i].andou_c == 1 || p[i].andou_d == 1 || p[i].andou_e == 1) && p[i].correr == 2 ) // Andou com correr ativado.
	    	p[i].energia -= 3;
}

void usa_magias(int *cx,int *cy,char **matriz,Magia (*fb)[2], Pessoa *p)
{
	int i,j,k;
	for(i=0; i<4; ++i) {
		if(fb[i][0].ativa == false && fb[i][1].ativa == false)
			break ;
		for(j=0; j<2; ++j) { // O mesmo player pode ter jogado duas fireballs.
			if(fb[i][j].d == -1)
				fb[i][j].d = calcula_direcao(p,i); /* Numeros de direçao no colisao.h */
			for(k=0; k<4; ++k) {
				if(contato_proximo_direcionado(fb[i][j].x,fb[i][j].y,cx,cy,i,k,fb[i][j].d) == k) {
					k = k; // Isso nao faz nada, tem que substituir por tirar vida de k.
					fb[i][j].ativa = false;
					fb[i][j].explosao = true;
					fb[i][j].d = -1;
				}
			}
			if(fb[i][j].ativa==true && colisao_fireball(matriz,fb[i][j].x,fb[i][j].y,fb[i][j].d) == 0) { // Nao colidiu com nenhum char, verifica se colidiu com algo do mapa. {
				/*if(andou_b[i]==1){
					fb[i][j].y -= 12;
				}else if(andou_d[i]==1){
					fb[i][j].x += 12;
				}else if(andou_e[i]==1){
					fb[i][j].x -= 12;
				}else if(andou_b[i]==1){
					fb[i][j].y += 12;
				}*/
				switch(fb[i][j].d) {
					case 0:
						fb[i][j].y -= 12;
						break;
					case 1:
						fb[i][j].x += 12;
						break;
					case 2:
						fb[i][j].x -= 12;
						break;
					case 3:
						fb[i][j].y += 12;
						break;
					default:
						break;
				}
				fb[i][j].dist += 12; // Dist eh usado pra limitar a distancia que a fireball vai. No caso, vai ser 300 pixels?
				if(fb[i][j].dist >= 300) {
					fb[i][j].ativa = false;
					fb[i][j].explosao = true;
					fb[i][j].d = -1;
				}
			}
			else if(fb[i][j].ativa==true) { // Nao tah ativa OU colidiu. Vou considerar que eh a hipotese de ter colidido, entao passa pra falso.
				fb[i][j].ativa = false;
				fb[i][j].explosao = true;
				fb[i][j].d = -1;
			}
		}
	}
	return ;
}

int calcula_direcao(Pessoa *p,int i)
{
	if(p[i].andou_c == 1 || (p[i].andou_b == 0 && p[i].andou_c == 0 && p[i].andou_d == 0 && p[i].andou_e == 0)) { // Olhando pra cima.
		al_flip_display;
		return 0;
	}
	if(p[i].andou_d == 1) { // Olhando pra direita.
		al_flip_display;
		return 1;
	}
	if(p[i].andou_e == 1) { // Olhando pra esquerda.
		al_flip_display;
		return 2;
	}
	if(p[i].andou_b == 1) { // Olhando pra baixo.
		al_flip_display;
		return 3;
	}
	return -1; // Deu erro.
}

void flash(Pessoa *p,int *cx,int *cy,int *tlep,char **matriz)
{
	int i,j;
	for(i=0;i<4;i++) {
		if(tlep[i] && p[i].energia >= 50) {
			tlep[i] = 0;
			p[i].energia -= 50;
			/* Existem 8 casos (8 direçoes possiveis de andar, 4 sentidos e 4 diagonais). */
			for(j=0;j<19;j++) {
				if((p[i].andou_c) && !(p[i].andou_b) && !(p[i].andou_d) && !(p[i].andou_e)) { // Soh pra cima ( /\ ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,2,cx,cy,i) == 1) {
					    cy[i] += 4;
		            }
		            cy[i] -= 4;
				}

				if((p[i].andou_c) && (p[i].andou_d) && !(p[i].andou_b) && !(p[i].andou_e)) { // Pra cima e pra direita ( /\ + > ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,2,cx,cy,i) == 1) {
					    cy[i] += 4;
		            }
		            cy[i] -= 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,3,cx,cy,i) == 1) {
					    cx[i] -= 4;
		            }
		            cx[i] += 4;
				}

				if((p[i].andou_d) && !(p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_e)) { // Soh pra direita ( > ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,3,cx,cy,i) == 1)
		            {
					    cx[i] -= 4;
		            }
		            cx[i] += 4;
				}

				if((p[i].andou_d) && (p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_e)) { // Pra direita e pra baixo ( > \/ ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,3,cx,cy,i) == 1) {
					    cx[i] -= 4;
		            }
		            cx[i] += 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,0,cx,cy,i) == 1) {
					    cy[i] -= 4;
		            }
		            cy[i] += 4;
				}

				if((p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_d) && !(p[i].andou_e)) { // Soh pra baixo ( \/ ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,0,cx,cy,i) == 1) {
					    cy[i] -= 4;
		            }
		            cy[i] += 4;
				}

				if((p[i].andou_b) && (p[i].andou_e) && !(p[i].andou_c) && !(p[i].andou_d)) { // Pra baixo e pra esquerda. ( < \/ ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,0,cx,cy,i) == 1) {
					    cy[i] -= 4;
		            }
		            cy[i] += 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,1,cx,cy,i) == 1) {
					    cx[i] += 4;
		            }
		            cx[i] -= 4;
				}

				if((p[i].andou_e) && !(p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_d)) { // Soh pra esquerda. ( < ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,1,cx,cy,i) == 1) {
					    cx[i] += 4;
		            }
		            cx[i] -= 4;
				}

				if((p[i].andou_e) && (p[i].andou_c) && !(p[i].andou_b) && !(p[i].andou_d)) { // Pra esquerda e pra cima. ( < /\ ).
					if(colidiu(matriz,cx[i]/4,cy[i]/4,1,cx,cy,i) == 1) {
					    cx[i] += 4;
		            }
		            cx[i] -= 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,2,cx,cy,i) == 1) {
					    cy[i] += 4;
		            }
		            cy[i] -= 4;
				}
			}
		}
	}
	return ;
}