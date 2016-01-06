#include "imprime.h"

void imprime_neon(int x,int y,ALLEGRO_BITMAP* neon,bool temneon)
{
	if(temneon)
		al_draw_bitmap_region(neon,0,0,16,16,x,y,0);
	return ;
}

void imprime_char(int cx,int cy,int a,int b,int selx,int sely,ALLEGRO_BITMAP *chars)
{    // cx e cy indicam qual a posicao do char no mapa. A e B indicam qual o "boneco" deve ser imprimido pela funçao. Selx e Sely indicam qual
     // imagem do "boneco" (ex: mexendo uma perna, ou de costas, etc.)

    al_draw_bitmap_region(chars,a+selx,b+sely,32,32,cx,cy,0);   // Desenha char 1. | Obs.: Ver 96 como 32x3 e 128 como 32x4.
    return ;
}

int imprime_4_chars_for(int cont,int desx[],int desy[],int cx[],int cy[],int andou_b[],int andou_c[],int andou_d[],int andou_e[],int correr[],int energia[],int xneon[],int yneon[],char** matriz,ALLEGRO_BITMAP** neons,ALLEGRO_BITMAP *chars,int *cor,bool *temneon,int njogadores)
{
	puts("Imprimindo chars...");
	int i,j,selecx,selecy,char4;
    //ALLEGRO_FONT *font=al_load_font("Fonts/fixed_font.tga", 0, 0);
    /* Calcula a posiçao dos neons */
	for(i=0; i<njogadores; i++) {
	 	xneon[i]=cx[i]+8;
	 	yneon[i]=cy[i]+8;
	}
	/* Sobre a retirada dos neons. A ordem de prioridade de pra onde o char tah olhando eh: Cima > Direita > Esquerda > Baixo. */

    /* Faz alternar os pés do char 1 na hora de andar.
       O contador faz a alteracao soh ser a cada CONT impressoes.
       Isso evita o char de trocar muito rapido de pe. */
    if(desx[0] == 64 && cont==CONT) {
		desx[0] = 0;
    } else if(cont == CONT) {
        desx[0] = 64;
    }

    /* O valor de retorno da atribuicao eh a proprio valor atribuido. Ex: x = y = 2 equivale a  x = 2; y = 2; */
	desx[1] = desx[2] = desx[3] = desx[0];

	/* Tentativa de transformar tudo em um for */
	for(i=0; i<njogadores; i++) {
	 	pessoa[i].x = cx[i];
	 	pessoa[i].y = cy[i];
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

	 	printf("Imprimindo char %d\n", i);

	 	if(andou_b[i] == 1)
	 	{
	 		if(colidiu(matriz,cx[i]/4,cy[i]/4,0,cx,cy,i) == 1)
	 		{
	 			cy[i] -= 4*correr[i];
	 		}
		 	cy[i] += 4*correr[i];
	        desy[i]=0+128*char4;
			if(!andou_e[i] && !andou_d[i] && !andou_c[i])
				imprime_char(cx[i],cy[i],pessoa[i].desx,pessoa[i].desy,desx[i],desy[i],chars);
	    }
	    if(andou_e[i] == 1)
	    {
	        if(colidiu(matriz,cx[i]/4,cy[i]/4,1,cx,cy,i) == 1) { // O 1(um) tah ali porque eh o caso de andar pra esquerda.
				cx[i] += 4*correr[i]; // Como colidiu, ele "anda" pra trás, o que faz ele nao se mexer.
	        }
	        cx[i] -= 4*correr[i];
	        desy[i]=32+128*char4;
	        if(!andou_d[i] && !andou_c[i])
	         	imprime_char(cx[i],cy[i],pessoa[i].desx,pessoa[i].desy,desx[i],desy[i],chars);
	    }
	    if(andou_d[i] == 1)
	    {
	        if(colidiu(matriz,cx[i]/4,cy[i]/4,3,cx,cy,i) == 1) { // O 3(tres) tah ali porque eh o caso de andar pra direita.
				cx[i] -= 4*correr[i]; // Como colidiu, ele "anda" pra trás, o que faz ele nao se mexer.
			}
	        cx[i] += 4*correr[i];
	        desy[i]=64+128*char4;
	        if(!andou_c[i])
	            imprime_char(cx[i],cy[i],pessoa[i].desx,pessoa[i].desy,desx[i],desy[i],chars);
	    }
	    if(andou_c[i] == 1) {
	        if(colidiu(matriz,cx[i]/4,cy[i]/4,2,cx,cy,i) == 1) { // O 2(dois) tah ali porque eh o caso de andar pra cima.
		        cy[i] += 4*correr[i]; // Como colidiu, ele "anda" pra trás, o que faz ele nao se mexer.
	        }
	        cy[i] -= 4*correr[i];
	        desy[i]=96+128*char4;
	        imprime_char(cx[i],cy[i],pessoa[i].desx,pessoa[i].desy,desx[i],desy[i],chars);
	        if(andou_d[i] == 1 && andou_e[i]==0)
		 	    imprime_neon(xneon[i]+4*correr[i],yneon[i],neons[i],temneon[i]);
	        else if(andou_e[i] == 1 && andou_d[i]==0)
			    imprime_neon(xneon[i]-4*correr[i],yneon[i],neons[i],temneon[i]);
			else
	        	imprime_neon(xneon[i],yneon[i],neons[i],temneon[i]);
	    }
	    if(!andou_b[i] && !andou_c[i] && !andou_d[i] && !andou_e[i]) { // Nao andou.
			imprime_char(cx[i],cy[i],pessoa[i].desx,pessoa[i].desy,32,96,chars);
			imprime_neon(xneon[i],yneon[i],neons[pessoa[i].time-1],temneon[i]);
	    }
	}
	puts("Chars impressos!");
	return 1;
}
