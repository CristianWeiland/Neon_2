#include "neon.h"
#include "menu.h"
#include "Fase1.h"
#include <math.h>

#define CONT 2
#define CONTEXPLO 9
#define TAM 1000
#define NJOGADORES 5

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

	Pessoa *pessoas;
/*
	andou_b = (int*) malloc (NJOGADORES * sizeof(int));
	andou_c = (int*) malloc (NJOGADORES * sizeof(int));
	andou_d = (int*) malloc (NJOGADORES * sizeof(int));
	andou_e = (int*) malloc (NJOGADORES * sizeof(int));
*/
	pessoas = (Pessoa *) malloc(sizeof(Pessoa) * NJOGADORES);
	for(i=0; i<NJOGADORES; ++i) {
		// Inicializacoes da estrutura Pessoa
		pessoas[i].andou_b = 0;
		pessoas[i].andou_c = 0;
		pessoas[i].andou_d = 0;
		pessoas[i].andou_e = 0;
	}

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
		/*
		andou_b[i]=0;
		andou_c[i]=0;
		andou_d[i]=0;
		andou_e[i]=0;
		*/
		energia[i]=100;
	}

	Window win;
    FILE *mapa,*errext; // errext = error exit (ou saida de erros)
    bool sair = false,redraw = false,puxa[4]={false,false,false,false},temneon[4]={true,true,true,true};
    /* Magias */
	Magia fireball[4][2];

	/* Declaracao de estrtuturas do Allegro. Obs: Neons vai ser um vetor de imagens, na ordem amarelo - azul - verde - vermelho. */
    //ALLEGRO_FONT *font;
	//font5 = al_load_font("Fonts/fixed_font.tga", 0, 0);
    ALLEGRO_BITMAP *tiles,*chars,*map,*frente,**neons,**fireballs,*explosion;

	/* Inicializacao dos arquivos. */
	errext = fopen("lago.txt","w"); fclose(errext); errext = fopen("err.txt","w");
	if(!errext) {
		puts("Error opening file.");
		exit(1); // Se deu erro no lugar onde vao ser anotados os erros, ferrou!
	}

    /* Inicializa�oes do Allegro */
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
			fireball[i][j].d = 0; // Nao tem dire�ao.
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
        pessoas[i].botao_char[0]=(char*) malloc(30*sizeof(char));sprintf(pessoas[i].botao_char[0],"%c",98);
		if(!pessoas[i].botao_char[0]) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].botao_char[0]",i);fclose(errext);exit(1); }
        pessoas[i].botao_char[1]=(char*) malloc(30*sizeof(char));sprintf(pessoas[i].botao_char[1],"%c",99);
		if(!pessoas[i].botao_char[1]) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].botao_char[1]",i);fclose(errext);exit(1); }
        pessoas[i].botao_char[2]=(char*) malloc(30*sizeof(char));sprintf(pessoas[i].botao_char[2],"%c",100);
		if(!pessoas[i].botao_char[2]) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].botao_char[2]",i);fclose(errext);exit(1); }
        pessoas[i].botao_char[3]=(char*) malloc(30*sizeof(char));sprintf(pessoas[i].botao_char[3],"%c",101);
		if(!pessoas[i].botao_char[3]) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].botao_char[3]",i);fclose(errext);exit(1); }
        pessoas[i].botao_char[4]=(char*) malloc(30*sizeof(char));sprintf(pessoas[0].botao_char[4],"%c",97);
		if(!pessoas[i].botao_char[4]) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].botao_char[4]",i);fclose(errext);exit(1); }
		pessoas[i].botao_char[5]=(char*) malloc(30*sizeof(char));sprintf(pessoas[0].botao_char[5],"%c",97);
		if(!pessoas[i].botao_char[5]) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].botao_char[5]",i);fclose(errext);exit(1); }
		pessoas[i].botao_char[6]=(char*) malloc(30*sizeof(char));sprintf(pessoas[0].botao_char[6],"%c",97);
		if(!pessoas[i].botao_char[6]) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].botao_char[6]",i);fclose(errext);exit(1); }
		pessoas[i].nome		   =(char*) malloc(30*sizeof(char));sprintf(pessoas[i].nome,"player %d",i+1);
		if(!pessoas[i].nome) {
			fprintf(errext,"Falha ao alocar memoria para pessoas[%d].nome",i);fclose(errext);exit(1); }
		pessoas[i].time=1;
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
			fscanf(cmd,"%s %d\n",pessoas[j].botao_char[i],&pessoas[j].botao_char_int[i]);
			//printf("%s %d\n",pessoas[j].botao_char[i],pessoas[j].botao_char_int[i]);
	    }
	}
	fclose(cmd);
	fclose(errext);

	puts("Inicializacoes completas!");

    /* Opera o jogo */
	if(abremenu(win,chars,pessoas)==1) {
		fase1(win,sair,andou_b,andou_c,andou_d,andou_e,correr,puxa,tlep,cx,cy,fireball,energia,redraw,map,cont,i,j,temneon,desx,desy,xneon,yneon,neons,chars,cor,frente,font5,fireballs,explox,exploy,explosion,pessoas);
	}
	graphdeinit(win);
	exit(1);
}

// Fireball - Energy Wave - Armadilha (nao pode mudar dire�ao olhando - garante seguran�a pra retirada de neon) - Kamehameha (Tons of dmg + carregar) - Barreira de Pedra
// Duda: Achar um goku em algum lugar
