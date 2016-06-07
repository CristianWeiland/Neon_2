#include "neon.h"
#include "menu.h"
#include "Fase1.h"
#include <math.h>

/*
Problemas:
1- Bola de fogo não explode.
2- Barra de HP / Energia - OK.
3- Cor do neon quando parado - Xunxo.
4- Neon se movendo quando colide - OK.
5- Personagens todos iguais.
6- Bola de fogo nao da dano - OK.
7- Nao armazena comandos.
8- Usa fireball quando explosao ta ativa - explosao acompanha a fireball.
*/

#define CONT 2
#define CONTEXPLO 9
#define TAM 1000
#define NJOGADORES 5

int main()
{
    /* Coisas relacionadas aos chars */
    int i,j,JOGADORES,vencedor;
	/* Coisas relacionadas as tecnicas/magias */
	Magias m;
	/* Pessoas, que contem quase todos os dados (ver colisao.h) */
	Pessoa *p;
	/* Janela */
	Window win;
	/* Arquivos */
    FILE *errext; // errext = error exit (ou saida de erros)

	/* Inicializacao do arquivo */
	errext = fopen("err.txt","w");
	if(!errext) {
		puts("Error opening file.");
		exit(1);
	}

	// Isso tem que ficar depois do abremenu.
	p = (Pessoa *) malloc(sizeof(Pessoa) * NJOGADORES);
	for(i=0; i<NJOGADORES; ++i) {
		// Inicializacoes da estrutura Pessoa
		p[i].hp = 1000;
		p[i].selx = 0;
		p[i].sely = 64;
		p[i].time = i+1;
		p[i].correr = 1;
		p[i].andou_b = 0;
		p[i].andou_c = 0;
		p[i].andou_d = 0;
		p[i].andou_e = 0;
		p[i].energia = 100;
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

    init_magias(&m);

    al_register_event_source(win.event_queue, al_get_display_event_source(win.display));

	teclas_iniciais(p);

/*
	if( access( Comandos/cmd.txt, F_OK ) != -1 ) {
		FILE *cmd = fopen("Comandos/cmd.txt","r");
		for(j=0; j<4; ++j) {
			for(i=0; i<NJOGADORES; ++i) {
				fscanf(cmd,"%s %d\n",p[j].botao_char[i],&p[j].botao_char_int[i]);
				//printf("%s %d\n",p[j].botao_char[i],p[j].botao_char_int[i]);
		    }
		}
		fclose(cmd);
	} else {
	    teclas_iniciais(p);
	}
*/
	fclose(errext);

    /* Opera o jogo */
    vencedor = -1;
    while(1) {
		if(menu_principal(win,p,s,&JOGADORES,vencedor)==1) {
			vencedor = fase1(win,p,s,m,JOGADORES);
		}
	}

	graphdeinit(win);
	exit(1);
}

// Fireball - Energy Wave - Armadilha (nao pode mudar direçao olhando - garante segurança pra retirada de neon) - Kamehameha (Tons of dmg + carregar) - Barreira de Pedra
// Duda: Achar um goku em algum lugar
