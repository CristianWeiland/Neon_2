#include "neon.h"
#include "menu.h"
#include "Fase1.h"
#include <math.h>

#define CONT 2
#define CONTEXPLO 9
#define TAM 1000
#define NJOGADORES 5


/* Prototipo das funçoes */
ALLEGRO_BITMAP* cria_mapa(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP *tiles);
ALLEGRO_BITMAP* cria_frente(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP *tiles);
void desconta_energia(int andou_b[],int andou_c[],int andou_d[],int andou_e[],int correr[],int energia[]);
void tira_neon(bool *puxa,bool *temneon,int *cx,int *cy,int *andou_b,int *andou_c,int *andou_d,int *andou_e);
void flash(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int *energia,int *cx,int *cy,int *tlep,char **matriz);
void usa_magias(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int *energia,int *cx,int *cy,char **matriz,Magia (*fb)[2]);
int calcula_direcao(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int i);

void IA(int *andou_b,int *andou_c,int *andou_d,int *andou_e)
{
	int menor_dist[4]={1000,1000,1000,1000};int pessoa_perto[4];
	int dist[4];
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(pessoa[i].comp==1)
			{
				if(i!=j)
				{
					dist[i]=sqrt((pessoa[j].x-pessoa[i].x)*(pessoa[j].x-pessoa[i].x)+(pessoa[j].y-pessoa[i].y)*(pessoa[j].y-pessoa[i].y));
					if(dist[i]<menor_dist[i])
					{
						menor_dist[i]=dist[i];
						pessoa_perto[i]=j;
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++) {
		if((pessoa[i].comp==1) && (pessoa[pessoa_perto[i]].time!=pessoa[i].time)) {
			if((pessoa[pessoa_perto[i]].x-pessoa[i].x==0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y>0)) {
				andou_b[i]=1;andou_e[i]=0;andou_d[i]=0;andou_c[i]=0;
			} else if((pessoa[pessoa_perto[i]].x-pessoa[i].x==0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y<0)) {
				andou_c[i]=1;andou_e[i]=0;andou_d[i]=0;andou_b[i]=0;
			} else if((pessoa[pessoa_perto[i]].x-pessoa[i].x>0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y==0)) {
				andou_d[i]=1;andou_c[i]=0;andou_b[i]=0;andou_e[i]=0;
			} else if((pessoa[pessoa_perto[i]].x-pessoa[i].x<0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y==0)) {
				andou_e[i]=1;andou_d[i]=0;andou_c[i]=0;andou_b[i]=0;
			} else if((pessoa[pessoa_perto[i]].x-pessoa[i].x>0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y>0)) {
				andou_b[i]=1;andou_e[i]=0;andou_d[i]=1;andou_c[i]=0;
			} else if((pessoa[pessoa_perto[i]].x-pessoa[i].x<0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y>0)) {
				andou_c[i]=0;andou_e[i]=1;andou_d[i]=0;andou_b[i]=1;
			} else if((pessoa[pessoa_perto[i]].x-pessoa[i].x>0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y<0)) {
				andou_d[i]=1;andou_c[i]=1;andou_b[i]=0;andou_e[i]=0;
			} else if((pessoa[pessoa_perto[i]].x-pessoa[i].x<0) && (pessoa[pessoa_perto[i]].y-pessoa[i].y<0)) {
				andou_e[i]=1;andou_d[i]=0;andou_c[i]=1;andou_b[i]=0;
			} else {
				//andou_e[i]=0;andou_d[i]=0;andou_c[i]=0;andou_b[i]=0;
			}
		}
	}
}

int main()
{
    /* Coisas relacionadas aos chars */
    int cont=0,i,j,x,y,*andou_b,*andou_c,*andou_d,*andou_e,*correr,*energia;
    int *cx,*cy,*desx,*desy;/*[4]={200,250,300,350},cy[4]={400,400,400,400},desx[4]={64,64,64,64},desy[4]={0,0,0,0}; */// cx = coordenada X, vetor de 4 pra incluir ateh 4 chars.
    /* Coisas relacioinadas ao mapa */
	int mapsize,xtile[TAM],ytile[TAM],xcorte[TAM],ycorte[TAM];
    /* Coisas relacionadas aos neons */
	int xneon[NJOGADORES],yneon[NJOGADORES],direcao=0,cor[4]={1,2,3,4};
	/* Coisas relacionadas as tecnicas/magias */
	int tlep[4]={0,0,0,0},explox[4][2],exploy[4][2];

	andou_b = (int*) malloc (NJOGADORES * sizeof(int));
	andou_c = (int*) malloc (NJOGADORES * sizeof(int));
	andou_d = (int*) malloc (NJOGADORES * sizeof(int));
	andou_e = (int*) malloc (NJOGADORES * sizeof(int));
	energia = (int*) malloc (NJOGADORES * sizeof(int));
	correr = (int*) malloc (NJOGADORES * sizeof(int));
	desx = (int*) malloc (NJOGADORES * sizeof(int));
	desy = (int*) malloc (NJOGADORES * sizeof(int));
	cx = (int*) malloc (NJOGADORES * sizeof(int));
	cy = (int*) malloc (NJOGADORES * sizeof(int));

	for(i=0;i<NJOGADORES;i++) {
		desy[i]=0;
		desx[i]=64;
		correr[i]=1;
		andou_b[i]=0;
		andou_c[i]=0;
		andou_d[i]=0;
		andou_e[i]=0;
		energia[i]=100;
	}

	Window win;
    FILE *mapa,*errext; // errext = error exit (ou saida de erros)
    bool sair = false,redraw = false,puxa[4]={false,false,false,false},temneon[4]={true,true,true,true};
    /* Magias */
	Magia fireball[4][2];

	/* Declaracao de estrtuturas do Allegro. Obs: Neons vai ser um vetor de imagens, na ordem amarelo - azul - verde - vermelho. */
    //ALLEGRO_FONT *font;
	//
	//font5 = al_load_font("Fonts/fixed_font.tga", 0, 0);
    ALLEGRO_BITMAP *tiles,*chars,*map,*frente,**neons,**fireballs,*explosion;

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
	neons = (ALLEGRO_BITMAP**) malloc(4*sizeof(ALLEGRO_BITMAP*));
	fireballs = (ALLEGRO_BITMAP**) malloc(4*sizeof(ALLEGRO_BITMAP*));
    tiles = al_load_bitmap("Imgs/tiles.bmp");
    if(!tiles) {
	   	fprintf(errext,"Falha ao abrir a imagem tiles.");fclose(errext);exit(1); }
    chars = al_load_bitmap("Imgs/chars.bmp"); // Obs: Cada imagem de cada char eh 32x32
    if(!chars) {
    	fprintf(errext,"Falha ao abrir a imagem chars.");fclose(errext);exit(1); }
    explosion = al_load_bitmap("Imgs/Explo.bmp");
    if(!explosion) {
    	fprintf(errext,"Falha ao abrir a imagem explo.");fclose(errext);exit(1); }
	neons[0] = al_load_bitmap("Imgs/neonamarelo.bmp");
    if(!neons[0]) {
    	fprintf(errext,"Falha ao abrir a imagem neons[0].");fclose(errext);exit(1); }
	neons[1] = al_load_bitmap("Imgs/neonazul.bmp");
    if(!neons[1]) {
    	fprintf(errext,"Falha ao abrir a imagem neons[1].");fclose(errext);exit(1); }
	neons[2] = al_load_bitmap("Imgs/neonverde.bmp");
    if(!neons[2]) {
    	fprintf(errext,"Falha ao abrir a imagem neons[2].");fclose(errext);exit(1); }
	neons[3] = al_load_bitmap("Imgs/neonvermelho.bmp");
    if(!neons[3]) {
    	fprintf(errext,"Falha ao abrir a imagem neons[3].");fclose(errext);exit(1); }
	fireballs[0] = al_load_bitmap("Imgs/Fireballc.bmp");
    if(!fireballs[0]) {
    	fprintf(errext,"Falha ao abrir a imagem fireballs[0].");fclose(errext);exit(1); }
	fireballs[1] = al_load_bitmap("Imgs/Fireballd.bmp");
    if(!fireballs[1]) {
    	fprintf(errext,"Falha ao abrir a imagem fireballs[1].");fclose(errext);exit(1); }
	fireballs[2] = al_load_bitmap("Imgs/Fireballe.bmp");
    if(!fireballs[2]) {
    	fprintf(errext,"Falha ao abrir a imagem fireballs[2].");fclose(errext);exit(1); }
	fireballs[3] = al_load_bitmap("Imgs/Fireballb.bmp");
    if(!fireballs[3]) {
    	fprintf(errext,"Falha ao abrir a imagem fireballs[3].");fclose(errext);exit(1); }

	for(i=0; i<4; ++i) {
		for(j=0; j<2; j++) {
			//al_convert_mask_to_alpha(fireball[i][j].sprite,al_map_rgb(255,0,255));
			fireball[i][j].ativa = false; // Nao foi usada.
			fireball[i][j].dano = 20; // Dano da tecnica.
			fireball[i][j].explosao = false; // Nao colidiu / chegou na distancia limite.
			fireball[i][j].dist = 0; // Nao percorreu nenhuma distancia.
			fireball[i][j].d = 0; // Nao tem direçao.
			explox[i][j] = 280;
			exploy[i][j] = 220;
		}
	}

	//al_convert_mask_to_alpha(tiles,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(chars,al_map_rgb(255,0,255));
	al_convert_mask_to_alpha(explosion,al_map_rgb(255,0,255));
	for(i=0;i<4;i++) {
		al_convert_mask_to_alpha(neons[i],al_map_rgb(255,0,255));
		al_convert_mask_to_alpha(fireballs[i],al_map_rgb(255,0,255));
	}
	/* Carrega o mapa */

    //fscanf(mapa,"%i\n",&mapsize);
    //for(int i=0;i<mapsize+1;i++)
     //   fscanf(mapa,"%i %i %i %i\n",&xtile[i],&ytile[i],&xcorte[i],&ycorte[i]);


    al_register_event_source(win.event_queue, al_get_display_event_source(win.display));

    //matriz = le_matriz(fopen("matriz.txt","r"));

	for(i=0; i<4; ++i) {
        pessoa[i].botao_char[0]=(char*) malloc(30*sizeof(char));sprintf(pessoa[i].botao_char[0],"%c",98);
		if(!pessoa[i].botao_char[0]) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].botao_char[0]",i);fclose(errext);exit(1); }
        pessoa[i].botao_char[1]=(char*) malloc(30*sizeof(char));sprintf(pessoa[i].botao_char[1],"%c",99);
		if(!pessoa[i].botao_char[1]) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].botao_char[1]",i);fclose(errext);exit(1); }
        pessoa[i].botao_char[2]=(char*) malloc(30*sizeof(char));sprintf(pessoa[i].botao_char[2],"%c",100);
		if(!pessoa[i].botao_char[2]) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].botao_char[2]",i);fclose(errext);exit(1); }
        pessoa[i].botao_char[3]=(char*) malloc(30*sizeof(char));sprintf(pessoa[i].botao_char[3],"%c",101);
		if(!pessoa[i].botao_char[3]) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].botao_char[3]",i);fclose(errext);exit(1); }
        pessoa[i].botao_char[4]=(char*) malloc(30*sizeof(char));sprintf(pessoa[0].botao_char[4],"%c",97);
		if(!pessoa[i].botao_char[4]) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].botao_char[4]",i);fclose(errext);exit(1); }
		pessoa[i].botao_char[5]=(char*) malloc(30*sizeof(char));sprintf(pessoa[0].botao_char[5],"%c",97);
		if(!pessoa[i].botao_char[5]) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].botao_char[5]",i);fclose(errext);exit(1); }
		pessoa[i].botao_char[6]=(char*) malloc(30*sizeof(char));sprintf(pessoa[0].botao_char[6],"%c",97);
		if(!pessoa[i].botao_char[6]) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].botao_char[6]",i);fclose(errext);exit(1); }
		pessoa[i].nome		   =(char*) malloc(30*sizeof(char));sprintf(pessoa[i].nome,"player %d",i+1);
		if(!pessoa[i].nome) {
			fprintf(errext,"Falha ao alocar memoria para pessoa[%d].nome",i);fclose(errext);exit(1); }
		pessoa[i].time=1;
	}

	//teclas_iniciais();

	for(int i=0;i<4;i++)
		for(int j=0;j<2;j++)
			fireball[i][j].explosao = 0;

	ALLEGRO_FONT *font5;
	font5 = al_load_font("Fonts/fixed_font.tga", 0, 0);

	FILE *cmd = fopen("Comandos/cmd.txt","r");
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<5;i++)
		{
			fscanf(cmd,"%s %d\n",pessoa[j].botao_char[i],&pessoa[j].botao_char_int[i]);
			//printf("%s %d\n",pessoa[j].botao_char[i],pessoa[j].botao_char_int[i]);
	    }
	}
	fclose(cmd);
	fclose(errext);

	puts("Inicializacoes completas!");

    /* Opera o jogo */
	if(abremenu(win,chars)==1) {
		fase1(win,sair,andou_b,andou_c,andou_d,andou_e,correr,puxa,tlep,cx,cy,fireball,energia,redraw,map,cont,i,j,temneon,desx,desy,xneon,yneon,neons,chars,cor,frente,font5,fireballs,explox,exploy,explosion);
	}
	graphdeinit(win);
	exit(1);
}

ALLEGRO_BITMAP* cria_mapa(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP* tiles)
{
    ALLEGRO_BITMAP *map;
    map = al_create_bitmap(2000,2000);
    int i;
    al_set_target_bitmap(map);
    for(i=0; i< mapsize+1; i++)                            // Imprime cada tile salvado no arquivo.
        al_draw_bitmap_region(tiles,xcorte[i],ycorte[i],64,32,xtile[i],ytile[i],0);
    al_set_target_bitmap(al_get_backbuffer(win.display));  // Isso evita gastar toda a memoria.
    return map;
}

ALLEGRO_BITMAP* cria_frente(Window win,FILE* mapa,int mapsize,int xtile[],int ytile[],int xcorte[],int ycorte[],ALLEGRO_BITMAP *tiles)
{
	ALLEGRO_BITMAP *map;
	map = al_create_bitmap(2000,2000);
	int i;
	al_set_target_bitmap(map);
	for(i=0;i<mapsize+1;i++)
	{
	/*     Penultima, antepenultima e a anterior dessa.                                   */
		if( (xtile[i]==0 && (ytile[i]>=863 && ytile[i]<=961) ) || (xtile[i]==64 && (ytile[i]>=863 && ytile[i]<=961) ) || (xtile[i]==128 && (ytile[i]>=767 && ytile[i]<=961) /*&& ytile[i]!=864*/ ) ||
		    ( xtile[i]==192 && (ytile[i]>=799 && ytile[i]<=961) ) || ( (xtile[i]>=255 && xtile[i]<=385) && (ytile[i]>=895 && ytile[i]<=961) ) ||
			( (xtile[i]>=447 && xtile[i]<=577) && (ytile[i]>=863 && ytile[i]<=961) )   )
		{
	        al_draw_bitmap_region(tiles,xtile[i],ytile[i],64,32,xcorte[i],ycorte[i],0);
		}
	}
	al_set_target_bitmap(al_get_backbuffer(win.display));
	return map;
}

void tira_neon(bool *puxa,bool *temneon,int *cx,int *cy,int *andou_b,int *andou_c,int *andou_d,int *andou_e)
{
	int j;
	for(int i=0;i<4;i++)
	{
		if(puxa[i])
		{
			if(j = contato_proximo(cx,cy,andou_b,andou_c,andou_d,andou_e,i,j) != 5)
				temneon[j] = false;
		}
	}
	return ;
}

void desconta_energia(int andou_b[],int andou_c[],int andou_d[],int andou_e[],int correr[],int energia[])
{
	for(int i=0;i<4;i++)
	    if((andou_b[i]==1 || andou_c[i]==1 || andou_d[i]==1 || andou_e[i]==1) && correr[i]==2 ) // Andou com correr ativado.
	    	energia[i] -= 3;
}

void usa_magias(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int *energia,int *cx,int *cy,char **matriz,Magia (*fb)[2])
{

	int i,j,k;
	for(i=0;i<4;i++)
	{
		if(fb[i][0].ativa == false && fb[i][1].ativa == false)
			break;
		for(j=0;j<2;j++) // O mesmo player pode ter jogado duas fireballs.
		{
			if(fb[i][j].d == -1)
				fb[i][j].d = calcula_direcao(andou_b,andou_c,andou_d,andou_e,i); /* Numeros de direçao no colisao.h */
			for(k=0;k<4;k++)
			{
				if(contato_proximo_direcionado(fb[i][j].x,fb[i][j].y,cx,cy,i,k,fb[i][j].d) == k)
				{
					k = k; // Isso nao faz nada, tem que substituir por tirar vida de k.
					fb[i][j].ativa = false;
					fb[i][j].explosao = true;
					fb[i][j].d = -1;
				}
			}
			if(fb[i][j].ativa==true && colisao_fireball(matriz,fb[i][j].x,fb[i][j].y,fb[i][j].d) == 0) // Nao colidiu com nenhum char, verifica se colidiu com algo do mapa.
			{
				/*if(andou_b[i]==1){
					fb[i][j].y -= 12;
				}else if(andou_d[i]==1){
					fb[i][j].x += 12;
				}else if(andou_e[i]==1){
					fb[i][j].x -= 12;
				}else if(andou_b[i]==1){
					fb[i][j].y += 12;
				}*/
				switch(fb[i][j].d)
				{
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
				if(fb[i][j].dist >= 300)
				{
					fb[i][j].ativa = false;
					fb[i][j].explosao = true;
					fb[i][j].d = -1;
				}
			}
			else if(fb[i][j].ativa==true)
			{ // Nao tah ativa OU colidiu. Vou considerar que eh a hipotese de ter colidido, entao passa pra falso.
				fb[i][j].ativa = false;
				fb[i][j].explosao = true;
				fb[i][j].d = -1;
			}
		}
	}
	return ;
}

int calcula_direcao(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int i)
{
	if(andou_c[i]==1 || (andou_b[i]==0 && andou_c[i]==0 && andou_d[i]==0 && andou_e[i]==0)) // Olhando pra cima.
	{
		al_flip_display;
		return 0;
	}
	if(andou_d[i]==1) // Olhando pra direita.
	{
		al_flip_display;
		return 1;
	}
	if(andou_e[i]==1) // Olhando pra esquerda.
	{
		al_flip_display;
		return 2;
	}
	if(andou_b[i]==1) // Olhando pra baixo.
	{
		al_flip_display;
		return 3;
	}
	return -1; // Deu erro.
}

void flash(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int *energia,int *cx,int *cy,int *tlep,char **matriz)
{
	int i,j;
	for(i=0;i<4;i++)
	{
		if(tlep[i] && energia[i] >= 50)
		{
			tlep[i] = 0;
			energia[i] -= 50;
			/* Existem 8 casos (8 direçoes possiveis de andar, 4 sentidos e 4 diagonais). */
			for(j=0;j<19;j++)
			{
				if(andou_c[i] && !andou_b[i] && !andou_d[i] && !andou_e[i]) // Soh pra cima ( /\ ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,2,cx,cy,i) == 1)
		            {
					     cy[i] += 4;
		            }
		            cy[i] -= 4;
				}

				if(andou_c[i] && andou_d[i] && !andou_b[i] && !andou_e[i]) // Pra cima e pra direita ( /\ + > ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,2,cx,cy,i) == 1)
		            {
					     cy[i] += 4;
		            }
		            cy[i] -= 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,3,cx,cy,i) == 1)
		            {
					     cx[i] -= 4;
		            }
		            cx[i] += 4;
				}

				if(andou_d[i] && !andou_b[i] && !andou_c[i] && !andou_e[i]) // Soh pra direita ( > ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,3,cx,cy,i) == 1)
		            {
					     cx[i] -= 4;
		            }
		            cx[i] += 4;
				}

				if(andou_d[i] && andou_b[i] && !andou_c[i] && !andou_e[i]) // Pra direita e pra baixo ( > \/ ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,3,cx,cy,i) == 1)
		            {
					     cx[i] -= 4;
		            }
		            cx[i] += 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,0,cx,cy,i) == 1)
		            {
					     cy[i] -= 4;
		            }
		            cy[i] += 4;
				}

				if(andou_b[i] && !andou_c[i] && !andou_d[i] && !andou_e[i]) // Soh pra baixo ( \/ ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,0,cx,cy,i) == 1)
		            {
					     cy[i] -= 4;
		            }
		            cy[i] += 4;
				}

				if(andou_b[i] && andou_e[i] && !andou_c[i] && !andou_d[i]) // Pra baixo e pra esquerda. ( < \/ ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,0,cx,cy,i) == 1)
		            {
					     cy[i] -= 4;
		            }
		            cy[i] += 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,1,cx,cy,i) == 1)
		            {
					     cx[i] += 4;
		            }
		            cx[i] -= 4;
				}

				if(andou_e[i] && !andou_b[i] && !andou_c[i] && !andou_d[i]) // Soh pra esquerda. ( < ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,1,cx,cy,i) == 1)
		            {
					     cx[i] += 4;
		            }
		            cx[i] -= 4;
				}

				if(andou_e[i] && andou_c[i] && !andou_b[i] && !andou_d[i]) // Pra esquerda e pra cima. ( < /\ ).
				{
					if(colidiu(matriz,cx[i]/4,cy[i]/4,1,cx,cy,i) == 1)
		            {
					     cx[i] += 4;
		            }
		            cx[i] -= 4;
					if(colidiu(matriz,cx[i]/4,cy[i]/4,2,cx,cy,i) == 1)
		            {
					     cy[i] += 4;
		            }
		            cy[i] -= 4;
				}
			}
		}
	}
	return ;
}

// Fireball - Energy Wave - Armadilha (nao pode mudar direçao olhando - garante segurança pra retirada de neon) - Kamehameha (Tons of dmg + carregar) - Barreira de Pedra
// Duda: Achar um goku em algum lugar
