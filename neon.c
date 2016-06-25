#include "neon.h"
#include "menu.h"
#include "Fase1.h"
#include <math.h>

#define CONT 2
#define CONTEXPLO 9
#define TAM 1000

int main()
{
    /* Coisas relacionadas aos chars */
    int i,j,jogadores,vencedor;
	/* Coisas relacionadas as tecnicas/magias */
	Magias m;
	/* Pessoas, que contem quase todos os dados (ver colisao.h) */
	Pessoa *p;
	/* Janela */
	Window win;
	/* Arquivos */
    FILE *errext, *cmd; // errext = error exit (ou saida de erros)

	/* Inicializacao do arquivo */
	errext = fopen("err.txt","w");
	if(!errext) {
		puts("Error opening file.");
		exit(1);
	}

	// Isso tem que ficar depois do abremenu.
	p = (Pessoa *) malloc(sizeof(Pessoa) * PESSOAS);
	for(i=0; i<PESSOAS; ++i) {
		// Inicializacoes da estrutura Pessoa
		p[i].hp = MAX_HP;
		p[i].selx = 0;
		p[i].sely = 64;
		p[i].time = i+1;
		p[i].preso = 0;
		p[i].correr = 1;
		p[i].andou_b = 0;
		p[i].andou_c = 0;
		p[i].andou_d = 0;
		p[i].andou_e = 0;
		p[i].energia = MAX_ENERGY;
		p[i].nome = (char*) malloc(30*sizeof(char));
		if(!p[i].nome) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].nome",i);
			fclose(errext);
			exit(1);
		}
		sprintf(p[i].nome,"player %d",i+1);
	}

    /* Inicializaçoes do Allegro */
    win = graphinit(errext);

    /* Inicializacao dos Bitmaps */
    Sprite s = init_sprites(errext);

    init_magias(&m, PESSOAS);

    al_register_event_source(win.event_queue, al_get_display_event_source(win.display));

	fclose(errext);

	teclas_iniciais(p);

    /* Opera o jogo */
    vencedor = -1;
    while(1) {
		if(menu_principal(win,p,s,&jogadores,vencedor)==1) {
			vencedor = fase1(win,p,s,m,jogadores);
		}
	}

	graphdeinit(win);
	exit(1);
}

// Fireball - Energy Wave - Armadilha (nao pode mudar direçao olhando - garante segurança pra retirada de neon) - Kamehameha (Tons of dmg + carregar) - Barreira de Pedra
// Duda: Achar um goku em algum lugar
