#include "menu.h"

Window Win;
Pessoa *Pessoas;
Sprite Sprites;
ALLEGRO_FONT *Font;
ALLEGRO_COLOR Color[PESSOAS]; // PESSOAS == numero jogadores
int Desx[PESSOAS], Desy[PESSOAS], Time[PESSOAS]; // PESSOAS == numero jogadores

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

void imprime_configs() {
	for(int i=0; i<PESSOAS; ++i) {
		imprime_char(162+150*i, 150, Desx[i], Desy[i], Pessoas[i].selx, Pessoas[i].sely, Sprites);
		al_draw_textf(Font, Color[Time[i]-1], 155+150*i, 200, 0, "Time %d", Time[i]);
		// Esses montes de al_draw_text nao parecem bons (ainda mais que tao num for de 4x).
		al_draw_text(Font, CINZA_ESCURO, 155+150*i, 250, 0, "Cima :");
		al_draw_text(Font, CINZA_ESCURO, 155+150*i, 270, 0, "Baixo :");
		al_draw_text(Font, CINZA_ESCURO, 155+150*i, 290, 0, "Esquerda :");
		al_draw_text(Font, CINZA_ESCURO, 155+150*i, 310, 0, "Direita :");
		al_draw_text(Font, CINZA_ESCURO, 155+150*i, 330, 0, "Correr :");
		al_draw_text(Font, CINZA_ESCURO, 155+150*i, 350, 0, "Puxar :");
		al_draw_text(Font, CINZA_ESCURO, 155+150*i, 370, 0, "Flash :");
		// Esses textf na verdade tem que ser botoes.
		al_draw_textf(Font, CINZA_ESCURO, 250+150*i, 250, 0, "a");
		al_draw_textf(Font, CINZA_ESCURO, 250+150*i, 270, 0, "a");
		al_draw_textf(Font, CINZA_ESCURO, 250+150*i, 290, 0, "a");
		al_draw_textf(Font, CINZA_ESCURO, 250+150*i, 310, 0, "a");
		al_draw_textf(Font, CINZA_ESCURO, 250+150*i, 330, 0, "a");
		al_draw_textf(Font, CINZA_ESCURO, 250+150*i, 350, 0, "a");
		al_draw_textf(Font, CINZA_ESCURO, 250+150*i, 370, 0, "a");
	}
	// Falta imprimir textos tipo: Escolha seu personagem! Escolha seu time!
}

// Funcoes que retornam 0 significa que o retorno eh ignorado. Se retorno != 0, vai sair do while.
int char_next(int i) {
	Desx[i] = (Desx[i] + 96) % 192;
	Desy[i] = (Desx[i] == 0) ? (Desy[i] + 128) % 256 : Desy[i];
	return 0;
}
int char_prev(int i) { // Isso nao funciona. Arrumar.
	Desx[i] = (Desx[i] + 96) % 192;
	Desy[i] = (Desx[i] != 0) ? (Desy[i] + 128) % 256 : Desy[i];
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

 // Tem que ser numero entre 1 e 4.
int team_0_next() { Time[0] = (Time[0] % 4) + 1; return 0; }
int team_1_next() { Time[1] = (Time[1] % 4) + 1; return 0; }
int team_2_next() { Time[2] = (Time[2] % 4) + 1; return 0; }
int team_3_next() { Time[3] = (Time[3] % 4) + 1; return 0; }
int team_0_prev() { Time[0] = ((Time[0] + 2) % 4) + 1; return 0; }
int team_1_prev() { Time[1] = ((Time[1] + 2) % 4) + 1; return 0; }
int team_2_prev() { Time[2] = ((Time[2] + 2) % 4) + 1; return 0; }
int team_3_prev() { Time[3] = ((Time[3] + 2) % 4) + 1; return 0; }

int back_to_menu() { return 1; }

int salvar_configs() {
	for(int i=0; i<PESSOAS; ++i) {
		Pessoas[i].desx = Desx[i];
		Pessoas[i].desy = Desy[i];
		Pessoas[i].time = Time[i];
	}
	return 0;
}

int selecao_personagem(void) {
	int i, tamanho, mx = 0, my = 0, retorno = 0;
	Botoes botoes[NUM_BOTOES_SEL_PERSONAGEM];
    bool oldHovering[NUM_BOTOES_SEL_PERSONAGEM], newHovering[NUM_BOTOES_SEL_PERSONAGEM], devoImprimir = false;

    for(i=0; i<NUM_BOTOES_SEL_PERSONAGEM; ++i)
        oldHovering[i] = newHovering[i] = false;

	for(i=0; i<PESSOAS; ++i) {
		Desx[i] = Pessoas[i].desx;
		Desy[i] = Pessoas[i].desy;
		Time[i] = Pessoas[i].time;
	}

    /* Provavelmente eu deveria mudar pra deixar os personagens lado a lado. */
    botoes[0].set_position(140,160);
    botoes[1].set_position(210,160);
    botoes[2].set_position(290,160);
    botoes[3].set_position(360,160);
    botoes[4].set_position(440,160);
    botoes[5].set_position(510,160);
    botoes[6].set_position(590,160);
    botoes[7].set_position(660,160);
    botoes[8].set_position(140,200);
    botoes[9].set_position(210,200);
    botoes[10].set_position(290,200);
    botoes[11].set_position(360,200);
    botoes[12].set_position(440,200);
    botoes[13].set_position(510,200);
    botoes[14].set_position(590,200);
    botoes[15].set_position(660,200);
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

    for(i=0; i<PESSOAS; ++i) {
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
    botoes[16].set_func(back_to_menu);
    botoes[17].set_func(salvar_configs);

    imprime_menu(botoes, NUM_BOTOES_SEL_PERSONAGEM, mx, my);
    imprime_configs();
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
    					imprime_configs();
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
    					imprime_configs();
    					al_flip_display();
                        devoImprimir = false;
                    }
                }
                break ;
        }
    } while(!retorno);
    return 0;
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
	Color[0] = AMARELO;
	Color[1] = AZUL_ESCURO;
	Color[2] = VERDE;
	Color[3] = VERMELHO;

    for(i=0; i<NUM_BOTOES; ++i)
        oldHovering[i] = newHovering[i] = false;

    botoes[0].set_position(30,50);
    botoes[1].set_position(30,90);
    botoes[2].set_position(30,130);
    botoes[3].set_position(30,170);
    botoes[4].set_position(30,210);
    botoes[0].set_text("Jogar");
    botoes[1].set_text("Carregar");
    botoes[2].set_text("Configuracoes");
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
