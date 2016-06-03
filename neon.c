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
    int i,j;
	/* Coisas relacionadas as tecnicas/magias */
	int explox[4][2],exploy[4][2];
	/* Pessoas, que contem quase todos os dados (ver colisao.h) */
	Pessoa *p;

	p = (Pessoa *) malloc(sizeof(Pessoa) * NJOGADORES);
	for(i=0; i<NJOGADORES; ++i) {
		// Inicializacoes da estrutura Pessoa
		p[i].hp = 1000;
		p[i].time = i+1;
		p[i].selx = 0;
		p[i].sely = 64;
		p[i].correr = 1;
		p[i].energia = 100;
		p[i].andou_b = p[i].andou_c = p[i].andou_d = p[i].andou_e = 0;
	}

	Window win;
    FILE *mapa,*errext; // errext = error exit (ou saida de erros)
    /* Magias */
	Magia fireball[4][2];

	/* Inicializacao dos arquivos. */
	errext = fopen("lago.txt","w"); fclose(errext); errext = fopen("err.txt","w");
	if(!errext) {
		puts("Error opening file.");
		exit(1); // Se deu erro no lugar onde vao ser anotados os erros, ferrou!
	}

    /* Inicializaçoes do Allegro */
    win = graphinit(errext);

    /* Inicializacao dos Bitmaps */
    Sprite s = init_sprites(errext);

	for(i=0; i<4; ++i) {
		for(j=0; j<2; ++j) {
			//al_convert_mask_to_alpha(fireball[i][j].sprite,al_map_rgb(255,0,255));
			fireball[i][j].ativa = false; // Nao foi usada.
			fireball[i][j].dano = 200; // Dano da tecnica.
			fireball[i][j].explosao = false; // Nao colidiu / chegou na distancia limite.
			fireball[i][j].dist = 0; // Nao percorreu nenhuma distancia.
			fireball[i][j].d = 0; // Nao tem direçao.
			explox[i][j] = 280;
			exploy[i][j] = 220;
		}
	}

    al_register_event_source(win.event_queue, al_get_display_event_source(win.display));

	for(i=0; i<4; ++i) {
		for(j=0; j<7; ++j) {
			p[i].botao_char[j] = (char*) malloc(30 * sizeof(char));
			if(!(p[i].botao_char[j])) {
				fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[%d]",i,j);
				fclose(errext);
				exit(1);
			}
		}
		sprintf(p[i].botao_char[0],"%c",98);
		sprintf(p[i].botao_char[1],"%c",99);
		sprintf(p[i].botao_char[2],"%c",100);
		sprintf(p[i].botao_char[3],"%c",101);
		sprintf(p[i].botao_char[4],"%c",97);
		sprintf(p[i].botao_char[5],"%c",97);
		sprintf(p[i].botao_char[6],"%c",97);
		p[i].nome = (char*) malloc(30*sizeof(char));
		if(!p[i].nome) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].nome",i);
			fclose(errext);
			exit(1);
		}
		sprintf(p[i].nome,"player %d",i+1);
	}

	teclas_iniciais(p);

	ALLEGRO_FONT *font;
	font = al_load_font("Fonts/fixed_font.tga", 0, 0);
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
	if(abremenu(win,p,s)==1) {
		fase1(win,fireball,font,explox,exploy,p,s);
	}
	graphdeinit(win);
	exit(1);
}

// Fireball - Energy Wave - Armadilha (nao pode mudar direçao olhando - garante segurança pra retirada de neon) - Kamehameha (Tons of dmg + carregar) - Barreira de Pedra
// Duda: Achar um goku em algum lugar
