#ifndef ALLEGRO
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#endif

void fase1(Window win,Magia fireball[4][2],ALLEGRO_FONT *font,int explox[4][2],int exploy[4][2],Pessoa *p,Sprite s)
{
	int njogadores = 4;

	char** matriz;
	int mapsize,xtile[TAM],ytile[TAM],xcorte[TAM],ycorte[TAM];
	FILE *mapa,*errext,*auxFile;
	ALLEGRO_BITMAP *map;
	int i, j, k, cont = 0, flash[njogadores], cor[njogadores];
	bool sair=false, puxa[njogadores], temneon[njogadores];

	for(i=0; i<njogadores; ++i) {
		p[i].x = 100 + 50*i;
		p[i].y = 200;
		puxa[i] = false;
		temneon[i] = true;
		flash[i] = 0;
		cor[i] = i+1;
	}

	errext = fopen("err.txt","w");

	mapa = fopen("Fases/f1/map.txt","r");
    if(!mapa) {
    	fprintf(errext,"Erro ao abrir mapa.txt.\n");
    	fclose(errext);
    	exit(1);
    }

    fscanf(mapa,"%i\n",&mapsize);
    for(i=0;i<mapsize+1;++i)
        fscanf(mapa,"%i %i %i %i\n",&xtile[i],&ytile[i],&xcorte[i],&ycorte[i]);

    map = cria_mapa(win,mapa,mapsize,xtile,ytile,xcorte,ycorte,s);
    s.frente = cria_frente(win,mapa,mapsize,xcorte,ycorte,xtile,ytile,s); // Obs: Confundi dentro da funçao, entao to passando invertido aqui. EH PROPOSITAL!

    auxFile = fopen("Fases/f1/matriz.txt","r");
    if(!auxFile) {
    	fprintf(errext,"Erro ao abrir matriz.txt.\n");
    	fclose(errext);
    	exit(1);
    }
	matriz = le_matriz(auxFile);

	al_flush_event_queue(win.event_queue);

	while (!sair) /* Pra sair, botoes como Esc, o X ali em cima direita,... transformam a variavel sair de false pra true, dai sai do while. */
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(win.event_queue, &ev);

        /* Trata eventos. */
	   	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // Detecta se clicaram no X.
			graphdeinit(win);
			exit(1);
		} else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) { // Detecta se apertaram alguma tecla.
			keyboard_down(ev.keyboard.keycode,puxa,flash,fireball,p);
        } else if(ev.type == ALLEGRO_EVENT_KEY_UP) { // Detecta se soltaram alguma tecla.
			keyboard_up(ev.keyboard.keycode,puxa,&sair,p);
        } else if (al_is_event_queue_empty(win.event_queue)) { // Nao ocorreu nenhum evento.
            /* Imprime */
			al_clear_to_color(PRETO);
			al_draw_bitmap(map,0,0,0);

			usa_magias(matriz,fireball,p,njogadores,s,explox,exploy,flash);

			tira_neon(puxa,temneon,p);

            calcula_energia(p,njogadores);

		  	cont = (cont + 1) % CONT;

            imprime_4_chars_for(cont,matriz,cor,temneon,njogadores,p,s);

            IA(p);

			al_flip_display();
		}
	}
}
