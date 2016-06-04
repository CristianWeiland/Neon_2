#include "menu.h"

Window Win;
Pessoa *Pessoas;
Sprite Sprites;
ALLEGRO_FONT *Font;

void imprime_menu(Botoes *botoes, int n_botoes, int mx, int my) {
/* Imprimir o menu eh uma operacao cara. Soh imprima quando ele mudar:
o jogador passar o mouse por cima de um botao ou clicar em um botao. */
    al_clear_to_color(PRETO);
    for(int i=0; i<n_botoes; ++i) {
        botoes[i].imprime(botoes[i].hovering(mx,my));
    }
}

int comeca_jogo() {
    return 1;
}

int fecha_jogo(void) {
    graphdeinit(Win);
    exit(0);
    return 0;
}

void imprime_personagens() {
	for(int i=0; i<4; ++i) {
		imprime_char(Pessoas[i].x, Pessoas[i].y, Pessoas[i].desx, Pessoas[i].desy, Pessoas[i].selx, Pessoas[i].sely, Sprites);
	}
	// Falta imprimir o numero do time.
	// Falta imprimir textos tipo: Escolha seu personagem! Escolha seu time!
}

int char_next(int i) {
	Pessoas[i].desx = (Pessoas[i].desx + 96) % 192;
	Pessoas[i].desy = (Pessoas[i].desx == i) ? (Pessoas[i].desy + 128) % 256 : Pessoas[i].desy;
	return 0;
}
int char_prev(int i) { // Isso nao funciona. Arrumar.
	Pessoas[i].desx = (Pessoas[i].desx + 96) % 192;
	Pessoas[i].desy = (Pessoas[i].desx == i) ? (Pessoas[i].desy + 128) % 256 : Pessoas[i].desy;
	return 0;
}

int char_0_next() { return char_next(0); }
int char_1_next() { return char_next(1); }
int char_2_next() { return char_next(2); }
int char_3_next() { return char_next(3); }
int char_0_prev() { return char_prev(0); }
int char_1_prev() { return char_prev(1); }
int char_2_prev() { return char_prev(2); }
int char_3_prev() { return char_prev(3); }

int team_0_next() { Pessoas[0].time = (Pessoas[0].time + 1) % 3; return 0; }
int team_1_next() { Pessoas[1].time = (Pessoas[1].time + 1) % 3; return 0; }
int team_2_next() { Pessoas[2].time = (Pessoas[2].time + 1) % 3; return 0; }
int team_3_next() { Pessoas[3].time = (Pessoas[3].time + 1) % 3; return 0; }
int team_0_prev() { Pessoas[0].time = (Pessoas[0].time - 1) % 3; return 0; }
int team_1_prev() { Pessoas[1].time = (Pessoas[1].time - 1) % 3; return 0; }
int team_2_prev() { Pessoas[2].time = (Pessoas[2].time - 1) % 3; return 0; }
int team_3_prev() { Pessoas[3].time = (Pessoas[3].time - 1) % 3; return 0; }

int return_1() { return 1; }

int selecao_personagem(void) {
	int i, tamanho, mx = 0, my = 0, retorno = 0;
	Botoes botoes[NUM_BOTOES_SEL_PERSONAGEM];
    bool oldHovering[NUM_BOTOES_SEL_PERSONAGEM], newHovering[NUM_BOTOES_SEL_PERSONAGEM], devoImprimir = false;

    for(i=0; i<NUM_BOTOES_SEL_PERSONAGEM; ++i)
        oldHovering[i] = newHovering[i] = false;

    /* Provavelmente eu deveria mudar pra deixar os personagens lado a lado. */
    botoes[0].set_position(140,160);
    botoes[1].set_position(182,160);
    botoes[2].set_position(240,160);
    botoes[3].set_position(282,160);
    botoes[4].set_position(340,160);
    botoes[5].set_position(382,160);
    botoes[6].set_position(440,160);
    botoes[7].set_position(482,160);

    /* Ta errado, eh soh pra nao dar seg fault. */
    botoes[8].set_position(140,200);
    botoes[9].set_position(180,200);
    botoes[10].set_position(240,200);
    botoes[11].set_position(280,200);
    botoes[12].set_position(340,200);
    botoes[13].set_position(380,200);
    botoes[14].set_position(440,200);
    botoes[15].set_position(480,200);
    botoes[16].set_position(100,500);
    botoes[17].set_position(400,500);

    /* Para selecionar o personagem. */
    botoes[0].set_text("<");
    botoes[1].set_text(">");
    botoes[2].set_text("<");
    botoes[3].set_text(">");
    botoes[4].set_text("<");
    botoes[5].set_text(">");
    botoes[6].set_text("<");
    botoes[7].set_text(">");

    /* Pra selecionar a cor do neon. */
    botoes[8].set_text("<");
    botoes[9].set_text(">");
    botoes[10].set_text("<");
    botoes[11].set_text(">");
    botoes[12].set_text("<");
    botoes[13].set_text(">");
    botoes[14].set_text("<");
    botoes[15].set_text(">");
    botoes[16].set_text("Voltar");
    botoes[17].set_text("Salvar"); // Tenho que criar um backup antes de mudar td.

    for(i=0; i<4; ++i) {
    	Pessoas[i].x = 150 + (100 * i);
    	Pessoas[i].y = 150;
    	Pessoas[i].desx = 0;
    	Pessoas[i].desy = 0;
    	Pessoas[i].selx = 32;
    	Pessoas[i].sely = 0;
    }

    botoes[0].set_func(char_0_prev);
    botoes[1].set_func(char_0_next);
    botoes[2].set_func(char_1_prev);
    botoes[3].set_func(char_1_next);
    botoes[4].set_func(char_2_prev);
    botoes[5].set_func(char_2_next);
    botoes[6].set_func(char_3_prev);
    botoes[7].set_func(char_3_next);
    botoes[8].set_func(team_0_prev);
    botoes[9].set_func(team_0_next);
    botoes[10].set_func(team_1_prev);
    botoes[11].set_func(team_1_next);
    botoes[12].set_func(team_2_prev);
    botoes[13].set_func(team_2_next);
    botoes[14].set_func(team_3_prev);
    botoes[15].set_func(team_3_next);
    botoes[16].set_func(return_1);

    imprime_menu(botoes, NUM_BOTOES_SEL_PERSONAGEM, mx, my);
    imprime_personagens();
    al_flip_display();

    ALLEGRO_EVENT ev;
    do {
        al_wait_for_event(Win.event_queue, &ev);
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
			    graphdeinit(Win);
    			exit(1);
                break ;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                for(i=0; i<NUM_BOTOES_SEL_PERSONAGEM; ++i) {
                    if(botoes[i].hovering(mx,my)) {
                        retorno = botoes[i].execute();
                        imprime_menu(botoes, NUM_BOTOES_SEL_PERSONAGEM, mx, my);
    					imprime_personagens();
    					al_flip_display();
                    }
                }
                break ;
            case ALLEGRO_EVENT_MOUSE_AXES:
			    mx = ev.mouse.x;
    			my = ev.mouse.y;
                for(i=0; i<NUM_BOTOES_SEL_PERSONAGEM; ++i) {
                    newHovering[i] = botoes[i].hovering(mx,my);
                    if(oldHovering[i] != newHovering[i]) { // Se tava em cima do botao, tirou. Se tava fora, colocou em cima.
                        oldHovering[i] = newHovering[i];
                        devoImprimir = true;
                    }
                    if(devoImprimir) {
                        imprime_menu(botoes, NUM_BOTOES_SEL_PERSONAGEM, mx, my);
    					imprime_personagens();
    					al_flip_display();
                        devoImprimir = false;
                    }
                }
                break ;
        }
    } while(!retorno);
    return retorno;
}

int menu_principal(Window win,Pessoa *p,Sprite s)
{
	int i, tamanho, mx = 0, my = 0, retorno = 0;
    Botoes botoes[NUM_BOTOES];
    bool oldHovering[NUM_BOTOES], newHovering[NUM_BOTOES], devoImprimir = false;

	al_flush_event_queue(win.event_queue);

	/* Inicializa variaveis globais, para usar dentro das funcoes dos botoes. */
    Win = win;
    Pessoas = p;
    Sprites = s;
    Font = al_load_font("Fonts/fixed_font.tga",14,0);

    for(i=0; i<NUM_BOTOES; ++i)
        oldHovering[i] = newHovering[i] = false;

    botoes[0].set_position(30,50);
    botoes[1].set_position(30,90);
    botoes[2].set_position(30,130);
    botoes[3].set_position(30,170);
    botoes[4].set_position(30,210);
    botoes[0].set_text("Jogar");
    botoes[1].set_text("Carregar");
    botoes[2].set_text("Configurações");
    botoes[3].set_text("Comandos");
    botoes[4].set_text("Sair");
    botoes[0].set_func(comeca_jogo);
    botoes[2].set_func(selecao_personagem);
    botoes[4].set_func(fecha_jogo);

    imprime_menu(botoes, NUM_BOTOES, mx, my);
    al_flip_display();

    ALLEGRO_EVENT ev;
    do {
        al_wait_for_event(win.event_queue, &ev);
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
			    graphdeinit(win);
    			exit(1);
                break ;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                for(i=0; i<NUM_BOTOES; ++i) {
                    if(botoes[i].hovering(mx,my)) {
                        retorno = botoes[i].execute();
                        if(retorno == 1) { // Começa jogo
                        	return 1;
                        }
                        imprime_menu(botoes, NUM_BOTOES, mx, my);
					    al_flip_display();
                    }
                }
                break ;
            /* Se precisar fazer algo com o soltar do mouse, eh aqui.
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                break ;
            */
            case ALLEGRO_EVENT_MOUSE_AXES:
			    mx = ev.mouse.x;
    			my = ev.mouse.y;
                for(i=0; i<NUM_BOTOES; ++i) {
                    newHovering[i] = botoes[i].hovering(mx,my);
                    if(oldHovering[i] != newHovering[i]) { // Se tava em cima do botao, tirou. Se tava fora, colocou em cima.
                        oldHovering[i] = newHovering[i];
                        devoImprimir = true;
                    }
                    if(devoImprimir) {
                        imprime_menu(botoes, NUM_BOTOES, mx, my);
                        al_flip_display();
                        devoImprimir = false;
                    }
                }
                break ;
        }
    } while(!retorno);
    return retorno;
}
