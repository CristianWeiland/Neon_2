#include "magia.h"

void tira_neon(bool *puxa,bool *temneon, Pessoa *p)
{
	int i,j;
	for(i=0;i<4;i++) {
		if(puxa[i]) {
			if(j = contato_proximo(i,j,p) != 5)
				temneon[j] = false;
		}
	}

	for(i=0;i<4;i++) // Pra nao contar como se estivesse sempre tentando puxar.
		puxa[i] = false;

	return ;
}

void calcula_energia(Pessoa *p, int njogadores)
{
	int i;

	// Para de correr quando acaba energia.
	for(i=0; i<njogadores; i++)
		if(p[i].energia <= 0)
			p[i].correr = 1;

	// Desconta energia
	for(i=0; i<njogadores; ++i)
	    if((p[i].andou_b == 1 || p[i].andou_c == 1 || p[i].andou_d == 1 || p[i].andou_e == 1) && p[i].correr == 2 ) // Andou com correr ativado.
	    	p[i].energia -= 3;

	// Recupera energia
  	for(i=0; i<njogadores; ++i)
  		if(p[i].energia < 100)
			p[i].energia++;

	return ;
}

void usa_fireball(char **matriz,Magia (*fb)[2], Pessoa *p) {
	int i,j,k;
	for(i=0; i<4; ++i) {
		if(fb[i][0].ativa == false && fb[i][1].ativa == false)
			break ;
		for(j=0; j<2; ++j) { // O mesmo player pode ter jogado duas fireballs.
			if(fb[i][j].d == -1)
				fb[i][j].d = calcula_direcao(p,i); /* Numeros de direçao no colisao.h */
			for(k=0; k<4; ++k) {
				if(contato_proximo_direcionado(fb[i][j].x,fb[i][j].y,i,k,fb[i][j].d,p) == k) {
					//k = k; // Isso nao faz nada, tem que substituir por tirar vida de k.
					p[k].hp -= fb[i][j].dano;
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
}

void explosao(Pessoa *p, int njogadores, Sprite s,int explox[4][2],int exploy[4][2],Magia (*fireball)[2]) {
	int i, j;
	for(i=0;i<njogadores;i++) {
		for(j=0;j<2;j++) {
			if(fireball[i][j].ativa == true) {
				al_draw_bitmap(s.fireballs[fireball[i][j].d],fireball[i][j].x,fireball[i][j].y,0);
			}
			if(fireball[i][j].explosao == true) { // Enquanto explox = 288 e exploy = 224, ele nao imprime a explosao.
							// Entao o esquema eh zerar eles e dai o programa começa a contagem e a impressao.
				explox[i][j] = exploy[i][j] = 0;
				fireball[i][j].explosao = false;
			}
			if(explox[i][j] < 280 && exploy[i][j] < 220) { // Imprime a explosao.
				al_draw_bitmap_region(s.explosion,explox[i][j],exploy[i][j],32,32,fireball[i][j].x,fireball[i][j].y,0);
				explox[i][j] += 32;
				if(explox[i][j] >= 288) {
					exploy[i][j] += 32;
					if(exploy[i][j] < 224)
						explox[i][j] = 0;
				}
			}
		}
	}
}

void usa_magias(char **matriz,Magia (*fb)[2], Pessoa *p, int njogadores, Sprite s,int explox[4][2],int exploy[4][2], int *flash)
{
	usa_flash(p,flash,matriz);
	usa_fireball(matriz, fb, p);
	explosao(p,njogadores,s,explox,exploy,fb);
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

void usa_flash(Pessoa *p,int *flash,char **matriz)
{
	/* Por favor otimizar isso aqui. O for(j=0; j<19) tem 8 ifs dentro. Nao da pra puxar o if pra fora
	   e escolher qual deles eh feito, e dai fazer as 19 iteracoes? Alem disso, se colidiu uma vez, colidiu
	   pra sempre, entao pode dar um break/return (cuidar com diagonais dai!)
	*/
	int i,j;
	for(i=0;i<4;i++) {
		if(flash[i] && p[i].energia >= 50) {
			flash[i] = 0;
			p[i].energia -= 50;
			/* Existem 8 casos (8 direçoes possiveis de andar, 4 sentidos e 4 diagonais). */
			for(j=0;j<19;j++) {
				if((p[i].andou_c) && !(p[i].andou_b) && !(p[i].andou_d) && !(p[i].andou_e)) { // Soh pra cima ( /\ ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,2,i,p) == 1) {
					    p[i].y += 4;
		            }
		            p[i].y -= 4;
				}

				if((p[i].andou_c) && (p[i].andou_d) && !(p[i].andou_b) && !(p[i].andou_e)) { // Pra cima e pra direita ( /\ + > ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,2,i,p) == 1) {
					    p[i].y += 4;
		            }
		            p[i].y -= 4;
					if(colidiu(matriz,p[i].x/4,p[i].y/4,3,i,p) == 1) {
					    p[i].x -= 4;
		            }
		            p[i].x += 4;
				}

				if((p[i].andou_d) && !(p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_e)) { // Soh pra direita ( > ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,3,i,p) == 1)
		            {
					    p[i].x -= 4;
		            }
		            p[i].x += 4;
				}

				if((p[i].andou_d) && (p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_e)) { // Pra direita e pra baixo ( > \/ ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,3,i,p) == 1) {
					    p[i].x -= 4;
		            }
		            p[i].x += 4;
					if(colidiu(matriz,p[i].x/4,p[i].y/4,0,i,p) == 1) {
					    p[i].y -= 4;
		            }
		            p[i].y += 4;
				}

				if((p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_d) && !(p[i].andou_e)) { // Soh pra baixo ( \/ ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,0,i,p) == 1) {
					    p[i].y -= 4;
		            }
		            p[i].y += 4;
				}

				if((p[i].andou_b) && (p[i].andou_e) && !(p[i].andou_c) && !(p[i].andou_d)) { // Pra baixo e pra esquerda. ( < \/ ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,0,i,p) == 1) {
					    p[i].y -= 4;
		            }
		            p[i].y += 4;
					if(colidiu(matriz,p[i].x/4,p[i].y/4,1,i,p) == 1) {
					    p[i].x += 4;
		            }
		            p[i].x -= 4;
				}

				if((p[i].andou_e) && !(p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_d)) { // Soh pra esquerda. ( < ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,1,i,p) == 1) {
					    p[i].x += 4;
		            }
		            p[i].x -= 4;
				}

				if((p[i].andou_e) && (p[i].andou_c) && !(p[i].andou_b) && !(p[i].andou_d)) { // Pra esquerda e pra cima. ( < /\ ).
					if(colidiu(matriz,p[i].x/4,p[i].y/4,1,i,p) == 1) {
					    p[i].x += 4;
		            }
		            p[i].x -= 4;
					if(colidiu(matriz,p[i].x/4,p[i].y/4,2,i,p) == 1) {
					    p[i].y += 4;
		            }
		            p[i].y -= 4;
				}
			}
		}
	}
	return ;
}