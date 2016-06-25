#include "magia.h"

void init_magias(Magias *m, int njogadores) {
	int i,j;
	if(njogadores > PESSOAS) { // Vai dar seg fault.
		printf("Njogadores (%d) maior que pessoas (%d). Abortando.", njogadores, PESSOAS);
		exit(1);
	}
	/* Inicializa fireball.
	for(i=0; i<njogadores; ++i) {
		for(j=0; j<2; ++j) {
			m->fireball[i][j].ativa = false; // Nao foi usada.
			m->fireball[i][j].dano = 200; // Dano da tecnica.
			m->fireball[i][j].explosao = false; // Nao colidiu / chegou na distancia limite.
			m->fireball[i][j].dist = 0; // Nao percorreu nenhuma distancia.
			m->fireball[i][j].d = -1; // Nao tem direçao.
			m->explox[i][j] = 280;
			m->exploy[i][j] = 220;
		}
	}
	*/
	for(i=0; i<njogadores; ++i) {
		/* Inicializa iceball. */
		for(j=0; j<ICEBALLS_P_PESSOA; ++j) {
			m->iceball[i][j].ativa = false; // Nao foi usada.
			m->iceball[i][j].dano = 25; // Dano da tecnica.
			m->iceball[i][j].explosao = false; // Nao colidiu / chegou na distancia limite.
			m->iceball[i][j].energia = 30;
			m->iceball[i][j].dist = 0; // Nao percorreu nenhuma distancia.
			m->iceball[i][j].d = -1; // Nao tem direçao.
		}
		/* Inicializa animacao do flash. */
		for(j=0; j<MAX_FLASH_POSSIVEL; ++j) {
			m->flash[i][j].ativa = false; // Nao foi usada.
			m->flash[i][j].count = 0;
			m->flash[i][j].xsprite = 88;
		}
		/* Inicializa trap. */
		for(j=0; j<TRAP_P_PESSOA; ++j) {
			m->trap[i][j].ativa = false; // Nao foi usada.
			m->trap[i][j].count = 0; // Duração
		}
	}
}

void tira_neon(bool *puxa,bool *temneon, Pessoa *p, int njogadores)
{
	int i,j,k;
	for(i=0; i<njogadores; ++i) {
		if(puxa[i] && p[i].hp > 0 && p[i].freeze <= 0) {
			for(j=0; j<njogadores; ++j) {
				if(j != i && (k = contato_proximo(i,j,p)) != 5) {
					temneon[k] = false;
					p[k].hp = 0;
				}
			}
		}
	}

	for(i=0; i<njogadores; ++i) // Pra nao contar como se estivesse sempre tentando puxar.
		puxa[i] = false;

	return ;
}

void calcula_status(Pessoa *p, int njogadores)
{
	int i;

	// Para de correr quando acaba energia.
	for(i=0; i<njogadores; ++i)
		// if(p[i].energia <= 0)
		if(p[i].energia <= 0 || p[i].freeze > 0)
			p[i].correr = 1;

	// Desconta energia
	for(i=0; i<njogadores; ++i)
	    if((p[i].andou_b == 1 || p[i].andou_c == 1 || p[i].andou_d == 1 || p[i].andou_e == 1) && p[i].correr == 2 ) // Andou com correr ativado.
	    	p[i].energia -= 3;

	// Recupera energia
  	for(i=0; i<njogadores; ++i)
  		if(p[i].energia < MAX_ENERGY && p[i].hp > 0)
			p[i].energia += 2;

	// Diminui tempo de congelamento.
	for(i=0; i<njogadores; ++i)
		if(p[i].freeze > 0) {
			--(p[i].freeze);
			if(p[i].freeze <= 0) {
				if(p[i].andou_b == 2) p[i].andou_b = 1;
				if(p[i].andou_c == 2) p[i].andou_c = 1;
				if(p[i].andou_d == 2) p[i].andou_d = 1;
				if(p[i].andou_e == 2) p[i].andou_e = 1;
			}
		}

	return ;
}

void usa_fireball(char **matriz, Pessoa *p, Magias *m, int njogadores) {
	int i,j,k;
	for(i=0; i<njogadores; ++i) {
		if(m->fireball[i][0].ativa == false && m->fireball[i][1].ativa == false)
			break ;
		for(j=0; j<2; ++j) { // O mesmo player pode ter jogado duas fireballs.
			if(m->fireball[i][j].d == -1) {
				m->fireball[i][j].d = calcula_direcao(p,i); // Numeros de direçao no colisao.h
			}
			for(k=0; k<njogadores; ++k) {
				if(contato_proximo_direcionado(m->fireball[i][j].x,m->fireball[i][j].y,i,k,m->fireball[i][j].d,p) == k) {
					p[k].hp -= m->fireball[i][j].dano;
					m->fireball[i][j].ativa = false;
					m->fireball[i][j].explosao = true;
					m->fireball[i][j].xexpl = m->fireball[i][j].x;
					m->fireball[i][j].yexpl = m->fireball[i][j].y;
					m->fireball[i][j].d = -1;
				}
			}
			// Nao colidiu com nenhum char, verifica se colidiu com algo do mapa.
			if(m->fireball[i][j].ativa==true && colisao_fireball(matriz,m->fireball[i][j].x,m->fireball[i][j].y,m->fireball[i][j].d) == 0) {
				switch(m->fireball[i][j].d) {
					case 0:
						m->fireball[i][j].y -= 12;
						break;
					case 1:
						m->fireball[i][j].x += 12;
						break;
					case 2:
						m->fireball[i][j].x -= 12;
						break;
					case 3:
						m->fireball[i][j].y += 12;
						break;
					default:
						break;
				}
				m->fireball[i][j].dist += 12; // Dist eh usado pra limitar a distancia que a fireball vai. No caso, vai ser 300 pixels?
				if(m->fireball[i][j].dist >= 300) {
					m->fireball[i][j].d = -1;
					m->fireball[i][j].ativa = false;
					m->fireball[i][j].explosao = true;
					m->fireball[i][j].xexpl = m->fireball[i][j].x;
					m->fireball[i][j].yexpl = m->fireball[i][j].y;
				}
			}
			else if(m->fireball[i][j].ativa==true) { // Nao tah ativa OU colidiu. Vou considerar que eh a hipotese de ter colidido, entao passa pra falso.
				m->fireball[i][j].d = -1;
				m->fireball[i][j].ativa = false;
				m->fireball[i][j].explosao = true;
				m->fireball[i][j].xexpl = m->fireball[i][j].x;
				m->fireball[i][j].yexpl = m->fireball[i][j].y;
			}
		}
	}
}

void explosao(Pessoa *p, int njogadores, Sprite s, Magias *m) {
	int i, j;
	for(i=0; i<njogadores; ++i) {
		for(j=0; j<2; ++j) {
			if(m->fireball[i][j].ativa == true) {
				al_draw_bitmap(s.fireballs[m->fireball[i][j].d],m->fireball[i][j].x,m->fireball[i][j].y,0);
			}
			if(m->fireball[i][j].explosao == true) { // Enquanto explox = 288 e exploy = 224, ele nao imprime a explosao.
							// Entao o esquema eh zerar eles e dai o programa começa a contagem e a impressao.
				m->explox[i][j] = m->exploy[i][j] = 0;
				m->fireball[i][j].explosao = false;
			}
			if(m->explox[i][j] < 280 && m->exploy[i][j] < 220) { // Imprime a explosao.
				//al_draw_bitmap_region(s.explosion,m->explox[i][j],m->exploy[i][j],32,32,m->fireball[i][j].x,m->fireball[i][j].y,0);
				al_draw_bitmap_region(s.explosion,m->explox[i][j],m->exploy[i][j],32,32,m->fireball[i][j].xexpl,m->fireball[i][j].yexpl,0);
				m->explox[i][j] += 32;
				if(m->explox[i][j] >= 288) {
					m->exploy[i][j] += 32;
					if(m->exploy[i][j] < 224)
						m->explox[i][j] = 0;
				}
			}
		}
	}
}

void usa_iceball(char **matriz, Pessoa *p, Magias *m, Sprite s, int njogadores) {
	int i,j,k;
	for(i=0; i<njogadores; ++i) {
		if(m->iceball[i][0].ativa == false && m->iceball[i][1].ativa == false || p[i].hp <= 0)
			continue;
		// printf("Player %d mandou uma iceball.\n", i);
		for(j=0; j<2; ++j) { // O mesmo player pode ter jogado duas iceballs.
			if(m->iceball[i][j].d == -1) {
				m->iceball[i][j].d = calcula_direcao(p,i); // Numeros de direçao no colisao.h
			}
			for(k=0; k<njogadores; ++k) {
				if(contato_proximo_direcionado(m->iceball[i][j].x,m->iceball[i][j].y,i,k,m->iceball[i][j].d,p) == k) {
					p[k].freeze = m->iceball[i][j].dano;
					m->iceball[i][j].ativa = false;
					m->iceball[i][j].d = -1;
				}
			}
			// Nao colidiu com nenhum char, verifica se colidiu com algo do mapa.
			if(m->iceball[i][j].ativa == true && colisao_fireball(matriz,m->iceball[i][j].x,m->iceball[i][j].y,m->iceball[i][j].d) == 0) {
				switch(m->iceball[i][j].d) {
					case 0:
						m->iceball[i][j].y -= 12;
						break;
					case 1:
						m->iceball[i][j].x += 12;
						break;
					case 2:
						m->iceball[i][j].x -= 12;
						break;
					case 3:
						m->iceball[i][j].y += 12;
						break;
					default:
						break;
				}
				m->iceball[i][j].dist += 12; // Dist eh usado pra limitar a distancia que a iceball vai. No caso, vai ser 300 pixels?
				if(m->iceball[i][j].dist >= 300) {
					m->iceball[i][j].d = -1;
					m->iceball[i][j].ativa = false;
				}
			} else if(m->iceball[i][j].ativa == true) { // Nao tah ativa OU colidiu. Vou considerar que eh a hipotese de ter colidido, entao passa pra falso.
				m->iceball[i][j].d = -1;
				m->iceball[i][j].ativa = false;
			}
			if(m->iceball[i][j].ativa == true) {
				al_draw_bitmap(s.iceballs[m->iceball[i][j].d],m->iceball[i][j].x,m->iceball[i][j].y,0);
			}
		}
	}
}

void animacao_flash(Pessoa *p, int njogadores, Sprite s, Magias *m) {
	int i, j;
	for(i=0; i<njogadores; ++i) {
		for(j=0; j<MAX_FLASH_POSSIVEL; ++j) {
			if(m->flash[i][j].ativa == true) { // Enquanto xsprite = 88, ele nao imprime a animacao. Quando xprite = 0, ele comeca a animacao.
				m->flash[i][j].xsprite = 0;
				m->flash[i][j].ativa = false;
				m->flash[i][j].count = 0;
			}
			if(m->flash[i][j].xsprite < 88) { // Imprime a animação.
				// printf("Imprimindo %d e %d, count = %d, xsprite = %d, x = %d, y = %d...\n", i, j, m->flash[i][j].count, m->flash[i][j].xsprite, m->flash[i][j].x, m->flash[i][j].y);
				al_draw_bitmap_region(s.animacao_flash,m->flash[i][j].xsprite,0,FLASH_SPRITE_WIDTH,FLASH_SPRITE_HEIGHT,m->flash[i][j].x,m->flash[i][j].y,0);
				if(m->flash[i][j].count == 3) {
					m->flash[i][j].xsprite += FLASH_SPRITE_WIDTH;
					m->flash[i][j].count = 0;
				}
				++(m->flash[i][j].count);
			}
		}
	}
}

void usa_trap(Pessoa *p, int njogadores, Sprite s, Magias *m) {
	int i, j, k;
	for(i=0; i<njogadores; ++i) {
		if(p[i].preso > 0) {
			--(p[i].preso);
		}
		for(j=0; j<TRAP_P_PESSOA; ++j) {
			if(m->trap[i][j].ativa == true) { // Enquanto xsprite = 88, ele nao imprime a animacao. Quando xprite = 0, ele comeca a animacao.
				m->trap[i][j].ativa = false;
				m->trap[i][j].count = TRAP_TEMPO_ARMADA;
				m->trap[i][j].x = p[i].x;
				m->trap[i][j].y = p[i].y;
				m->trap[i][j].em_acao = false;
			}
			if(m->trap[i][j].count > 0) { // Imprime a animação.
				al_draw_bitmap_region(s.trap,0,0,TRAP_SPRITE_WIDTH,TRAP_SPRITE_HEIGHT,m->trap[i][j].x,m->trap[i][j].y,0);
				--(m->trap[i][j].count);
				for(k=0; k<njogadores; ++k) {
					if(i == k)
						continue;

					// Checa se algum outro jogador pisou na trap
					if(p[i].preso <= 0 && m->trap[i][j].em_acao == false && // Confere se o jogador nao pisou em nenhum trap e se a trap nao foi pisada por outro jogador.
					   p[i].x >= m->trap[i][j].x && p[i].x <= m->trap[i][j].x + 32 && // Colidiu no eixo X
					   p[i].y >= m->trap[i][j].y && p[i].y <=  m->trap[i][j].y + 32) { // Colidiu no eixo Y
						p[i].preso = TRAP_TEMPO_PRENDENDO;
						m->trap[i][j].count = TRAP_TEMPO_PRENDENDO;
						m->trap[i][j].em_acao = true;
					}
				}
			}

		}
	}
}

void usa_magias(char **matriz, Pessoa *p, int njogadores, Sprite s, int *flash, Magias *m) {
	usa_flash(p, flash, matriz, njogadores, m);
	animacao_flash(p, njogadores, s, m);
	usa_iceball(matriz, p, m, s, njogadores);
	// usa_fireball(matriz, p, m, njogadores);
	// explosao(p, njogadores, s, m);
	return ;
}

int calcula_direcao(Pessoa *p,int i) {
	if(p[i].andou_c == 1 || (p[i].andou_b == 0 && p[i].andou_c == 0 && p[i].andou_d == 0 && p[i].andou_e == 0)) { // Olhando pra cima.
		return 0;
	}
	if(p[i].andou_d == 1) { // Olhando pra direita.
		return 1;
	}
	if(p[i].andou_e == 1) { // Olhando pra esquerda.
		return 2;
	}
	if(p[i].andou_b == 1) { // Olhando pra baixo.
		return 3;
	}
	return -1; // Deu erro.
}

void usa_flash(Pessoa *p, int *flash, char **matriz, int njogadores, Magias *m) {
	/* Por favor otimizar isso aqui. O for(j=0; j<19) tem 8 ifs dentro. Nao da pra puxar o if pra fora
	   e escolher qual deles eh feito, e dai fazer as 19 iteracoes? Alem disso, se colidiu uma vez, colidiu
	   pra sempre, entao pode dar um break/return (cuidar com diagonais dai!)
	*/
	int i,j;
	for(i=0; i<njogadores; ++i) {
		if(flash[i] && p[i].energia >= 60 && p[i].hp > 0 && p[i].freeze <= 0) {
			flash[i] = 0;
			// Ativar a animação.
			for(j=0; j<MAX_FLASH_POSSIVEL; ++j) {
				if(m->flash[i][j].xsprite >= 88) {
					// Escolhi uma instância da animação. Ativa ela e sai.
					m->flash[i][j].ativa = true;
					m->flash[i][j].x = p[i].x;
					m->flash[i][j].y = p[i].y;
					break;
				}
			}
			p[i].energia -= 60;
			/* Existem 8 casos (8 direçoes possiveis de andar, 4 sentidos e 4 diagonais). */
			for(j=0; j<19; ++j) {
				// Antes tinha if(p[i].andou_c), mas, quando ele ficar parado, ele também deve dar flash pra cima.
				if(!(p[i].andou_b) && !(p[i].andou_d) && !(p[i].andou_e)) { // Soh pra cima ( /\ ).
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