#include "imprime.h"

inline void imprime_neon(int x,int y,ALLEGRO_BITMAP* neon,bool temneon)
{
	if(temneon)
		al_draw_bitmap_region(neon,0,0,16,16,x,y,0);
	return ;
}

inline void imprime_char(int cx,int cy,int a,int b,int selx,int sely,ALLEGRO_BITMAP *chars)
{    // cx e cy indicam qual a posicao do char no mapa. A e B indicam qual o "boneco" deve ser imprimido pela funçao. Selx e Sely indicam qual
     // imagem do "boneco" (ex: mexendo uma perna, ou de costas, etc.)
    al_draw_bitmap_region(chars,a+selx,b+sely,32,32,cx,cy,0);   // Desenha char 1. | Obs.: Ver 96 como 32x3 e 128 como 32x4.
    return ;
}

int imprime_4_chars_for(int cont,char** matriz,ALLEGRO_BITMAP** neons,ALLEGRO_BITMAP *chars,int *cor,bool *temneon,int njogadores, Pessoa *p)
{
	//puts("Imprimindo chars...");
	int i,j,selecx,selecy,char4;
    //ALLEGRO_FONT *font=al_load_font("Fonts/fixed_font.tga", 0, 0);
    /* Calcula a posiçao dos neons */
	for(i=0; i<njogadores; i++) {
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
	for(i=0; i<njogadores; i++) {
	 	//p[i].x = cx[i];
	 	//p[i].y = cy[i];
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

	 	//printf("Imprimindo char %d\n", i);

	 	if((p[i].andou_b) == 1) {
	 		if(colidiu(matriz,p[i].x/4,p[i].y/4,BAIXO,i,p) == 1)
	 		{
	 			p[i].y -= 4 * p[i].correr;
	 		}
		 	p[i].y += 4 * p[i].correr;
	        p[i].sely = 0 + 128*char4;
			if(!(p[i].andou_e) && !(p[i].andou_d) && !(p[i].andou_c))
				imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,chars);
	    }
	    //printf("Primeiro if completo! ");
	    if((p[i].andou_e) == 1) {
	 		//puts("Entrei no primeiro if!");
	        if(colidiu(matriz,p[i].x/4,p[i].y/4,ESQ,i,p) == 1) { // O 1(um) tah ali porque eh o caso de andar pra esquerda.
				p[i].x += 4 * p[i].correr; // Como colidiu, ele "anda" pra trás, o que faz ele nao se mexer.
	        }
	        p[i].x -= 4 * p[i].correr;
	        p[i].sely = 32 + 128*char4;
	        if(!(p[i].andou_d) && !(p[i].andou_c))
	         	//imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,desx[i],desy[i],chars);
	         	imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,chars);
	    }
	    //printf("Segundo if completo! ");
	    if((p[i].andou_d) == 1) {
	        if(colidiu(matriz,p[i].x/4,p[i].y/4,DIR,i,p) == 1) { // O 3(tres) tah ali porque eh o caso de andar pra direita.
				p[i].x -= 4 * p[i].correr; // Como colidiu, ele "anda" pra trás, o que faz ele nao se mexer.
			}
	        p[i].x += 4 * p[i].correr;
	        p[i].sely = 64 + 128*char4;
	        if(!(p[i].andou_c))
	            imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,chars);
	    }
	    //printf("Terceiro if completo! ");
	    if((p[i].andou_c) == 1) {
	        if(colidiu(matriz,p[i].x/4,p[i].y/4,CIMA,i,p) == 1) { // O 2(dois) tah ali porque eh o caso de andar pra cima.
		        p[i].y += 4 * p[i].correr; // Como colidiu, ele "anda" pra trás, o que faz ele nao se mexer.
	        }
	        p[i].y -= 4 * p[i].correr;
	        p[i].sely = 96 + 128*char4;
	        imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,p[i].selx,p[i].sely,chars);
	        if((p[i].andou_d) == 1 && (p[i].andou_e)==0)
		 	    imprime_neon(p[i].xneon+4*p[i].correr,p[i].yneon,neons[i],temneon[i]);
	        else if((p[i].andou_e) == 1 && (p[i].andou_d)==0)
			    imprime_neon(p[i].xneon-4*p[i].correr,p[i].yneon,neons[i],temneon[i]);
			else
	        	imprime_neon(p[i].xneon,p[i].yneon,neons[i],temneon[i]);
	    }
	    //printf("Quarto if completo!\n");
	    if(!(p[i].andou_b) && !(p[i].andou_c) && !(p[i].andou_d) && !(p[i].andou_e)) { // Nao andou.
			imprime_char(p[i].x,p[i].y,p[i].desx,p[i].desy,32,96,chars);
			imprime_neon(p[i].xneon,p[i].yneon,neons[p[i].time-1],temneon[i]);
	    }
	}
	//puts("Chars impressos!");
	return 1;
}
