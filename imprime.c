#include "imprime.h"

void imprime_pessoa(Pessoa p) {
/*
	int x,y,desx,desy,selx,sely,hp; // Desx e desy escolhem o char na imagem; Selx e sely escolhem qual sprite do char (olhando pra cima,esq,...)
	int xneon,yneon;
	int andou_b,andou_c,andou_d,andou_e;
	char *botao_b, *botao_c, *botao_d, *botao_e;
	char *nome,*ataque;
	char *botao_char[7];
	int energia,correr,morto,dash;
	int comp;
	int botao_char_int[7],time;
*/
	printf("Vou imprimir uma pessoa: \n");
	printf("x = %d, y = %d, desx = %d, desy = %d, selx = %d, sely = %d, hp = %d, xneon = %d, yneon = %d\n",
		   p.x, p.y, p.desx, p.desy, p.selx, p.sely, p.hp, p.xneon, p.yneon);
	printf("andou_b = %d, andou_c = %d, andou_d = %d, andou_e = %d\n",
		   p.andou_b, p.andou_c, p.andou_d, p.andou_e);
	printf("botoes: b = %s, c = %s, d = %s, e = %s\nbotao_char: ", p.botao_b, p.botao_c, p.botao_d, p.botao_e);
	printf("\nenergia: %d, correr: %d, morto: %d, dash: %d, comp: %d, time: %d\n", p.energia, p.correr, p.morto, p.dash, p.comp, p.time);
	for(int i=0; i<7; ++i) {
		printf("(%d): %d, ", i+1, p.botao_char_int[i]);
	}
	printf("\n");
}

inline void imprime_neon(int x,int y,ALLEGRO_BITMAP* neon,bool temneon)
{
	if(temneon)
		al_draw_bitmap_region(neon,0,0,16,16,x,y,0);
	return ;
}

inline void imprime_char(int cx,int cy,int a,int b,int selx,int sely,Sprite s)
{    // cx e cy indicam qual a posicao do char no mapa. A e B indicam qual o "boneco" deve ser imprimido pela funçao. Selx e Sely indicam qual
     // imagem do "boneco" (ex: mexendo uma perna, ou de costas, etc.)
	 // A deve ser 0 ou 96. B deve ser 0 ou 128. selx deve ser 0, 32 ou 64. sely deve ser 0, 32, 64 ou 96.
    al_draw_bitmap_region(s.chars,a+selx,b+sely,LARGURA_CHAR,ALTURA_CHAR,cx,cy,0);   // Desenha char 1. | Obs.: Ver 96 como 32x3 e 128 como 32x4.
    return ;
}

inline void imprime_char_congelado(int cx,int cy,int a,int b,int selx,int sely,Sprite s)
{    // cx e cy indicam qual a posicao do char no mapa. A e B indicam qual o "boneco" deve ser imprimido pela funçao. Selx e Sely indicam qual
     // imagem do "boneco" (ex: mexendo uma perna, ou de costas, etc.)
	 // A deve ser 0 ou 96. B deve ser 0 ou 128. selx deve ser 0, 32 ou 64. sely deve ser 0, 32, 64 ou 96.
    al_draw_bitmap_region(s.chars_congelados,a+selx,b+sely,LARGURA_CHAR,ALTURA_CHAR,cx,cy,0);   // Desenha char 1. | Obs.: Ver 96 como 32x3 e 128 como 32x4.
    return ;
}

int imprime_4_chars_for(int cont,char** matriz,int *cor,bool *temneon,int njogadores,Pessoa *p,Sprite s)
{
	int i,j,selecx,selecy,char4;
    /* Calcula a posiçao dos neons */
	for(i=0; i<njogadores; ++i) {
	 	p[i].xneon = p[i].x+8;
	 	p[i].yneon = p[i].y+8;
	}
	/* Sobre a retirada dos neons. A ordem de prioridade de pra onde o char tah olhando eh: Cima > Direita > Esquerda > Baixo. */

    /* Faz alternar os pés do char 1 na hora de andar.
       O contador faz a alteracao soh ser a cada CONT impressoes.
       Isso evita o char de trocar muito rapido de pe. */
    if(p[0].selx == 64 && cont==CONT) {
		p[0].selx = 0;
    } else if(cont == CONT) {
        p[0].selx = 64;
    }
    for(i=0; i<njogadores; ++i) {
    	p[i].selx = p[0].selx;
    }

	/* Tentativa de transformar tudo em um for */
	for(i=0; i<njogadores; ++i) {
	    if(p[i].hp <= 0) {
	    	al_draw_bitmap(s.dead,p[i].x,p[i].y,0);
	    	continue;
	    }
	 	/* Algumas adaptaçoes pra fazer funcionar com um For. */
	 	if(i == 0 || i == 2)
	 		selecx = 0;
	 	else
	 		selecx = 96;
	 	if(i == 0 || i == 1)
	 		selecy = 0;
	 	else
			selecy = 128;

	 	char4 = 0;
	 	/* Fim das adaptaçoes. */

	 	if((p[i].andou_b) == 1) {
	 		//if(!(colidiu(matriz,p[i].x/4,p[i].y/4,BAIXO,i,p) == 1)) {
	 		if(!(colidiu(matriz,p[i].x/4,p[i].y/4,BAIXO,i,p) == 1) && pode_andar(i, p)) {
		 		p[i].y += 4 * p[i].correr;
		 		p[i].yneon += 4 * p[i].correr;
	 		}
	        p[i].sely = 0 + 128*char4;
			if(!(p[i].andou_e) && !(p[i].andou_d) && !(p[i].andou_c))
				if(p[i].freeze <= 0) {
					imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
				} else {
					imprime_char_congelado(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
				}
	    }
	    if((p[i].andou_e) == 1) {
	        // if(!(colidiu(matriz,p[i].x/4,p[i].y/4,ESQ,i,p) == 1)) { // O 1(um) tah ali porque eh o caso de andar pra esquerda.
	        if(!(colidiu(matriz,p[i].x/4,p[i].y/4,ESQ,i,p) == 1) && pode_andar(i, p)) { // O 1(um) tah ali porque eh o caso de andar pra esquerda.
			    p[i].x -= 4 * p[i].correr;
		 		p[i].xneon -= 4 * p[i].correr;
	        }
	        p[i].sely = 32 + 128*char4;
	        if(!(p[i].andou_d) && !(p[i].andou_c))
	         	if(p[i].freeze <= 0) {
	         		imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
	         	} else {
	         		imprime_char_congelado(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
	         	}
	    }
	    if((p[i].andou_d) == 1) {
	        // if(!(colidiu(matriz,p[i].x/4,p[i].y/4,DIR,i,p) == 1)) { // O 3(tres) tah ali porque eh o caso de andar pra direita.
	        if(!(colidiu(matriz,p[i].x/4,p[i].y/4,DIR,i,p) == 1) && pode_andar(i, p)) { // O 3(tres) tah ali porque eh o caso de andar pra direita.
		        p[i].x += 4 * p[i].correr;
		 		p[i].xneon += 4 * p[i].correr;
			}
	        p[i].sely = 64 + 128*char4;
	        if(!(p[i].andou_c))
	            if(p[i].freeze <= 0) {
	            	imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
	            } else {
	            	imprime_char_congelado(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
	            }
	    }
	    if((p[i].andou_c) == 1) {
	        // if(!(colidiu(matriz,p[i].x/4,p[i].y/4,CIMA,i,p) == 1)) { // O 2(dois) tah ali porque eh o caso de andar pra cima.
	        if(!(colidiu(matriz,p[i].x/4,p[i].y/4,CIMA,i,p) == 1) && pode_andar(i, p)) { // O 2(dois) tah ali porque eh o caso de andar pra cima.
		        p[i].y -= 4 * p[i].correr;
		 		p[i].yneon -= 4 * p[i].correr;
	        }
	        p[i].sely = 96 + 128*char4;
	        if(p[i].freeze <= 0) {
	        	imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
	        } else {
	        	imprime_char_congelado(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,s);
	        }
       		imprime_neon(p[i].xneon,p[i].yneon,s.neons[i],temneon[i]);
	    }
	    if((p[i].andou_b != 1) && (p[i].andou_c != 1) && (p[i].andou_d != 1) && (p[i].andou_e != 1)) { // Nao andou.
			if(p[i].freeze <= 0) {
				imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,32,96,s);
			} else {
				imprime_char_congelado(p[i].x,p[i].y,p[i].desx,p[i].desy,32,96,s);
			}
			imprime_neon(p[i].xneon,p[i].yneon,s.neons[p[i].time-1],temneon[i]);
	    }
	}

    al_draw_bitmap(s.frente,0,0,0);
    ALLEGRO_FONT *font = al_load_font("Fonts/fixed_font.tga", 14, 0);
    /* Imprime barra de energia e de vida. Obs: Isso tem que ficar depois da impressao da frente! */
    for(i=0; i<njogadores; ++i) {
    	if(p[i].hp < 0)
    		p[i].hp = 0;
    	al_draw_bitmap_region(s.healthbar,0,0,p[i].hp*100 / MAX_HP,20,20+200*i,640,0);
    	al_draw_bitmap_region(s.energybar,0,0,p[i].energia*100 / MAX_ENERGY,20,20+200*i,665,0);
    	al_draw_bitmap(s.bar,20+200*i,640,0);
    	al_draw_bitmap(s.bar,20+200*i,665,0);
	    // al_draw_textf(font, al_map_rgb(255,0,255), 300, 600+20*i, 0, "b: %d - c: %d - d: %d - e: %d", p[i].andou_b, p[i].andou_c, p[i].andou_d, p[i].andou_e);
    }
    al_destroy_font(font);
	return 1;
}
