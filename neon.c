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
    int i,j,x,y;
    /* Coisas relacioinadas ao mapa */
	int mapsize,xtile[TAM],ytile[TAM],xcorte[TAM],ycorte[TAM];
    /* Coisas relacionadas aos neons */
	//int xneon[NJOGADORES],yneon[NJOGADORES],direcao=0,cor[4]={1,2,3,4};
	int direcao = 0;
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

	//desx = (int*) malloc (NJOGADORES * sizeof(int)); --> Virou p.selx!
	//desy = (int*) malloc (NJOGADORES * sizeof(int)); --> Virou p.sely!

	Window win;
    FILE *mapa,*errext; // errext = error exit (ou saida de erros)
    /* Magias */
	Magia fireball[4][2];

	/* Declaracao de estrtuturas do Allegro. Obs: Neons vai ser um vetor de imagens, na ordem amarelo - azul - verde - vermelho. */
    //ALLEGRO_FONT *font;
	//font5 = al_load_font("Fonts/fixed_font.tga", 0, 0);
    //ALLEGRO_BITMAP *tiles,*chars,*map,*frente,**neons,**fireballs,*explosion;
	Sprite s;

	/* Inicializacao dos arquivos. */
	errext = fopen("lago.txt","w"); fclose(errext); errext = fopen("err.txt","w");
	if(!errext) {
		puts("Error opening file.");
		exit(1); // Se deu erro no lugar onde vao ser anotados os erros, ferrou!
	}

    /* Inicializaçoes do Allegro */
    win = graphinit(errext);
    /* Inicializacao da Fonte    */
    //font = al_load_font("Fonts/fixed_font.tga", 0, 0);
    //if(!font) {
    //	fprintf(errext,"Falha ao abrir a imagem tiles.");fclose(errext);exit(1); }

    /* Inicializacao dos Bitmaps */
	s.neons = (ALLEGRO_BITMAP**) malloc(4*sizeof(ALLEGRO_BITMAP*));
	s.fireballs = (ALLEGRO_BITMAP**) malloc(4*sizeof(ALLEGRO_BITMAP*));

    s.chars = al_load_bitmap("Imgs/chars.bmp"); // Obs: Cada imagem de cada char eh 32x32
    if(!(s.chars)) {
    	fprintf(errext,"Falha ao abrir a imagem chars.");
    	fclose(errext);
    	exit(1);
    }

    s.tiles = al_load_bitmap("Imgs/tiles.bmp");
    if(!(s.tiles)) {
	   	fprintf(errext,"Falha ao abrir a imagem tiles.");
	   	fclose(errext);
	   	exit(1);
	}

    s.bar = al_load_bitmap("Imgs/bar.bmp");
    if(!(s.bar)) {
    	printf("Falha ao abrir a imagem bar! O problema foi: %s\n",strerror(errno));
	   	exit(1);
	}

    s.healthbar = al_load_bitmap("Imgs/healthbar.bmp");
    if(!(s.healthbar)) {
    	printf("Falha ao abrir a imagem healthbar! O problema foi: %s\n",strerror(errno));
	   	exit(1);
	}

    s.energybar = al_load_bitmap("Imgs/energybar.bmp");
    if(!(s.energybar)) {
    	printf("Falha ao abrir a imagem energybar! O problema foi: %s\n",strerror(errno));
	   	exit(1);
	}

    s.dead = al_load_bitmap("Imgs/dead.bmp");
    if(!(s.dead)) {
    	printf("Falha ao abrir a imagem dead! O problema foi: %s\n",strerror(errno));
	   	exit(1);
	}

    s.explosion = al_load_bitmap("Imgs/Explo.bmp");
    if(!(s.explosion)) {
    	fprintf(errext,"Falha ao abrir a imagem explo.");
    	fclose(errext);
    	exit(1);
    }

	s.neons[0] = al_load_bitmap("Imgs/neonamarelo.bmp");
    if(!s.neons[0]) {
    	fprintf(errext,"Falha ao abrir a imagem s.neons[0].");
    	fclose(errext);
    	exit(1);
    }

	s.neons[1] = al_load_bitmap("Imgs/neonazul.bmp");
    if(!s.neons[1]) {
    	fprintf(errext,"Falha ao abrir a imagem s.neons[1].");
    	fclose(errext);
    	exit(1);
    }

	s.neons[2] = al_load_bitmap("Imgs/neonverde.bmp");
    if(!s.neons[2]) {
    	fprintf(errext,"Falha ao abrir a imagem s.neons[2].");
    	fclose(errext);
    	exit(1);
    }

	s.neons[3] = al_load_bitmap("Imgs/neonvermelho.bmp");
    if(!s.neons[3]) {
    	fprintf(errext,"Falha ao abrir a imagem s.neons[3].");
    	fclose(errext);
    	exit(1);
    }

	s.fireballs[0] = al_load_bitmap("Imgs/Fireballc.bmp");
    if(!s.fireballs[0]) {
    	fprintf(errext,"Falha ao abrir a imagem s.fireballs[0].");
    	fclose(errext);
    	exit(1);
    }

	s.fireballs[1] = al_load_bitmap("Imgs/Fireballd.bmp");
    if(!s.fireballs[1]) {
    	fprintf(errext,"Falha ao abrir a imagem s.fireballs[1].");
    	fclose(errext);
    	exit(1);
    }

	s.fireballs[2] = al_load_bitmap("Imgs/Fireballe.bmp");
    if(!s.fireballs[2]) {
    	fprintf(errext,"Falha ao abrir a imagem s.fireballs[2].");
    	fclose(errext);
    	exit(1);
    }

	s.fireballs[3] = al_load_bitmap("Imgs/Fireballb.bmp");
    if(!s.fireballs[3]) {
    	fprintf(errext,"Falha ao abrir a imagem s.fireballs[3].");
    	fclose(errext);
    	exit(1);
    }

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

	al_convert_mask_to_alpha(s.bar,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(s.dead,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(s.tiles,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(s.chars,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(s.explosion,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(s.healthbar,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(s.energybar,al_map_rgb(255,0,255));
	for(i=0;i<4;i++) {
		al_convert_mask_to_alpha(s.neons[i],al_map_rgb(255,0,255));
		al_convert_mask_to_alpha(s.fireballs[i],al_map_rgb(255,0,255));
	}

    al_register_event_source(win.event_queue, al_get_display_event_source(win.display));
/* Tentativa de otimizar - se o proximo 'for' nao for equivalente a esse, deu errado!
	for(i=0; i<4; ++i) {
        p[i].botao_char[0]=(char*) malloc(30*sizeof(char)); sprintf(p[i].botao_char[0],"%c",98);
		if(!p[i].botao_char[0]) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[0]",i);fclose(errext);exit(1);
		}
        p[i].botao_char[1]=(char*) malloc(30*sizeof(char)); sprintf(p[i].botao_char[1],"%c",99);
		if(!p[i].botao_char[1]) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[1]",i);fclose(errext);exit(1);
		}
        p[i].botao_char[2]=(char*) malloc(30*sizeof(char)); sprintf(p[i].botao_char[2],"%c",100);
		if(!p[i].botao_char[2]) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[2]",i);fclose(errext);exit(1);
		}
        p[i].botao_char[3]=(char*) malloc(30*sizeof(char)); sprintf(p[i].botao_char[3],"%c",101);
		if(!p[i].botao_char[3]) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[3]",i);fclose(errext);exit(1);
		}
        p[i].botao_char[4]=(char*) malloc(30*sizeof(char)); sprintf(p[0].botao_char[4],"%c",97);
		if(!p[i].botao_char[4]) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[4]",i);fclose(errext);exit(1);
		}
		p[i].botao_char[5]=(char*) malloc(30*sizeof(char)); sprintf(p[0].botao_char[5],"%c",97);
		if(!p[i].botao_char[5]) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[5]",i);fclose(errext);exit(1);
		}
		p[i].botao_char[6]=(char*) malloc(30*sizeof(char)); sprintf(p[0].botao_char[6],"%c",97);
		if(!p[i].botao_char[6]) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].botao_char[6]",i);fclose(errext);exit(1);
		}
		p[i].nome		  =(char*) malloc(30*sizeof(char)); sprintf(p[i].nome,"player %d",i+1);
		if(!p[i].nome) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].nome",i);fclose(errext);exit(1);
		}
		p[i].time = 1;
	}
*/
	// Comentei isso sem saber exatamente porque. Pode dar ruim.
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
		sprintf(p[0].botao_char[4],"%c",97);
		sprintf(p[0].botao_char[5],"%c",97);
		sprintf(p[0].botao_char[6],"%c",97);
		p[i].nome = (char*) malloc(30*sizeof(char));
		if(!p[i].nome) {
			fprintf(errext,"Falha ao alocar memoria para p[%d].nome",i);
			fclose(errext);
			exit(1);
		}
		sprintf(p[i].nome,"player %d",i+1);
	}

	teclas_iniciais(p);

	for(i=0;i<4;i++)
		for(j=0;j<2;j++)
			fireball[i][j].explosao = 0;

	ALLEGRO_FONT *font5;
	font5 = al_load_font("Fonts/fixed_font.tga", 0, 0);
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
		fase1(win,fireball,font5,explox,exploy,p,s);
	}
	graphdeinit(win);
	exit(1);
}

// Fireball - Energy Wave - Armadilha (nao pode mudar direçao olhando - garante segurança pra retirada de neon) - Kamehameha (Tons of dmg + carregar) - Barreira de Pedra
// Duda: Achar um goku em algum lugar
