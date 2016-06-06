#include "menu.h"

Window Win;
Pessoa *Pessoas;
Sprite Sprites;
ALLEGRO_EVENT Ev;
ALLEGRO_FONT *Font;
ALLEGRO_COLOR Color[PESSOAS]; // PESSOAS == numero jogadores
int Desx[PESSOAS], Desy[PESSOAS], Time[PESSOAS], Botoes_int[PESSOAS][COMANDOS_POR_PERSONAGEM]; // PESSOAS == numero jogadores
bool EsperandoTecla;

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
        al_draw_textf(Font, AMARELO_QUEIMADO, 140+150*i, 100, 0, "Jogador %d", Time[i]);
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
	}
	// Falta imprimir textos tipo: Escolha seu personagem! Escolha seu time!
    /* if(EsperandoTecla) imprime(esperandoTecla); */
}

// Funcoes que retornam 0 significa que o retorno eh ignorado. Se retorno != 0, vai sair do while.

/* Funções que cuidam da seleção de personagem. */
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

/* Funções que cuidam da seleção de time. */
int team_0_next() { Time[0] = (Time[0] % 4) + 1; return 0; }
int team_1_next() { Time[1] = (Time[1] % 4) + 1; return 0; }
int team_2_next() { Time[2] = (Time[2] % 4) + 1; return 0; }
int team_3_next() { Time[3] = (Time[3] % 4) + 1; return 0; }
int team_0_prev() { Time[0] = ((Time[0] + 2) % 4) + 1; return 0; }
int team_1_prev() { Time[1] = ((Time[1] + 2) % 4) + 1; return 0; }
int team_2_prev() { Time[2] = ((Time[2] + 2) % 4) + 1; return 0; }
int team_3_prev() { Time[3] = ((Time[3] + 2) % 4) + 1; return 0; }

/* Funções para selecionar as teclas para cada personagem. */
void set_buttons(Botoes botoes[BOTOES_SEL_PERSONAGEM_TOTAL]) {
/* Muda o texto dos botoes para as letras que representam as teclas dos jogadores. */
    for(int i=0; i<PESSOAS; ++i) {
        for(int j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            botoes[18+i*COMANDOS_POR_PERSONAGEM+j].set_text(al_keycode_to_name(Botoes_int[i][j]));
        }
    }
}
int set_next_key(int indice_pessoa, int indice_tecla) {
    Botoes_int[indice_pessoa][indice_tecla] = Ev.keyboard.keycode;
    return 0;
}
void esperaTecla() {
    EsperandoTecla = true;
    while(Ev.type != ALLEGRO_EVENT_KEY_DOWN)
        al_wait_for_event(Win.event_queue, &Ev); // Espera usuário apertar uma tecla.
    EsperandoTecla = false;
}
int set_key_0_0() { esperaTecla(); return set_next_key(0,0); }
int set_key_0_1() { esperaTecla(); return set_next_key(0,1); }
int set_key_0_2() { esperaTecla(); return set_next_key(0,2); }
int set_key_0_3() { esperaTecla(); return set_next_key(0,3); }
int set_key_0_4() { esperaTecla(); return set_next_key(0,4); }
int set_key_0_5() { esperaTecla(); return set_next_key(0,5); }
int set_key_0_6() { esperaTecla(); return set_next_key(0,6); }
int set_key_1_0() { esperaTecla(); return set_next_key(1,0); }
int set_key_1_1() { esperaTecla(); return set_next_key(1,1); }
int set_key_1_2() { esperaTecla(); return set_next_key(1,2); }
int set_key_1_3() { esperaTecla(); return set_next_key(1,3); }
int set_key_1_4() { esperaTecla(); return set_next_key(1,4); }
int set_key_1_5() { esperaTecla(); return set_next_key(1,5); }
int set_key_1_6() { esperaTecla(); return set_next_key(1,6); }
int set_key_2_0() { esperaTecla(); return set_next_key(2,0); }
int set_key_2_1() { esperaTecla(); return set_next_key(2,1); }
int set_key_2_2() { esperaTecla(); return set_next_key(2,2); }
int set_key_2_3() { esperaTecla(); return set_next_key(2,3); }
int set_key_2_4() { esperaTecla(); return set_next_key(2,4); }
int set_key_2_5() { esperaTecla(); return set_next_key(2,5); }
int set_key_2_6() { esperaTecla(); return set_next_key(2,6); }
int set_key_3_0() { esperaTecla(); return set_next_key(3,0); }
int set_key_3_1() { esperaTecla(); return set_next_key(3,1); }
int set_key_3_2() { esperaTecla(); return set_next_key(3,2); }
int set_key_3_3() { esperaTecla(); return set_next_key(3,3); }
int set_key_3_4() { esperaTecla(); return set_next_key(3,4); }
int set_key_3_5() { esperaTecla(); return set_next_key(3,5); }
int set_key_3_6() { esperaTecla(); return set_next_key(3,6); }

/* Função para salvar as configurações. */
int salvar_configs() {
    for(int i=0; i<PESSOAS; ++i) {
        Pessoas[i].desx = Desx[i];
        Pessoas[i].desy = Desy[i];
        Pessoas[i].time = Time[i];
        for(int j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            Pessoas[i].botao_char_int[j] = Botoes_int[i][j];
        }
    }
    return 0;
}
bool configs_nao_salvas() {
    for(int i=0; i<PESSOAS; ++i) {
        if(Pessoas[i].desx != Desx[i]) return true;
        if(Pessoas[i].desy != Desy[i]) return true;
        if(Pessoas[i].time != Time[i]) return true;
        for(int j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            if(Pessoas[i].botao_char_int[j] != Botoes_int[i][j]) return true;
        }
    }
}

/* Função para retornar ao menu principal. Chamada pelo botão "voltar" */
int back_to_menu() {
    if(configs_nao_salvas) {
        printf("Vc provavelmente fez cagadinha.\n"); // MUDAR ISSO PELO AMOR DE DEUS
    }
    return 1;
}


/* Menu de seleção de personagens, times e teclas. */
int selecao_personagem(void) {
	int i, j, tamanho, mx = 0, my = 0, retorno = 0;
	Botoes botoes[BOTOES_SEL_PERSONAGEM_TOTAL];
    bool oldHovering[BOTOES_SEL_PERSONAGEM_TOTAL], newHovering[BOTOES_SEL_PERSONAGEM_TOTAL], devoImprimir = false;

    for(i=0; i<BOTOES_SEL_PERSONAGEM_TOTAL; ++i)
        oldHovering[i] = newHovering[i] = false;

    EsperandoTecla = false;
	for(i=0; i<PESSOAS; ++i) {
		Desx[i] = Pessoas[i].desx;
		Desy[i] = Pessoas[i].desy;
		Time[i] = Pessoas[i].time;
        for(j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            Botoes_int[i][j] = Pessoas[i].botao_char_int[j];
        }
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
    for(i=0; i<PESSOAS; ++i) {
        for(j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            botoes[18+i*COMANDOS_POR_PERSONAGEM+j].set_position(250+150*i, 250+20*j);
        }
    }

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

    botoes[18].set_func(set_key_0_0);
    botoes[19].set_func(set_key_0_1);
    botoes[20].set_func(set_key_0_2);
    botoes[21].set_func(set_key_0_3);
    botoes[22].set_func(set_key_0_4);
    botoes[23].set_func(set_key_0_5);
    botoes[24].set_func(set_key_0_6);
    botoes[25].set_func(set_key_1_0);
    botoes[26].set_func(set_key_1_1);
    botoes[27].set_func(set_key_1_2);
    botoes[28].set_func(set_key_1_3);
    botoes[29].set_func(set_key_1_4);
    botoes[30].set_func(set_key_1_5);
    botoes[31].set_func(set_key_1_6);
    botoes[32].set_func(set_key_2_0);
    botoes[33].set_func(set_key_2_1);
    botoes[34].set_func(set_key_2_2);
    botoes[35].set_func(set_key_2_3);
    botoes[36].set_func(set_key_2_4);
    botoes[37].set_func(set_key_2_5);
    botoes[38].set_func(set_key_2_6);
    botoes[39].set_func(set_key_3_0);
    botoes[40].set_func(set_key_3_1);
    botoes[41].set_func(set_key_3_2);
    botoes[42].set_func(set_key_3_3);
    botoes[43].set_func(set_key_3_4);
    botoes[44].set_func(set_key_3_5);
    botoes[45].set_func(set_key_3_6);

    set_buttons(botoes);
    imprime_menu(botoes, BOTOES_SEL_PERSONAGEM_TOTAL, mx, my);
    imprime_configs();
    al_flip_display();

    do {
        al_wait_for_event(Win.event_queue, &Ev);
        switch (Ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
			    graphdeinit(Win);
    			exit(1);
                break ;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                for(i=0; i<BOTOES_SEL_PERSONAGEM_TOTAL; ++i) {
                    if(botoes[i].hovering(mx,my)) {
                        retorno = botoes[i].execute();
                        set_buttons(botoes);
                        imprime_menu(botoes, BOTOES_SEL_PERSONAGEM_TOTAL, mx, my);
    					imprime_configs();
    					al_flip_display();
                    }
                }
                break ;
            case ALLEGRO_EVENT_MOUSE_AXES:
			    mx = Ev.mouse.x;
    			my = Ev.mouse.y;
                for(i=0; i<BOTOES_SEL_PERSONAGEM_TOTAL; ++i) {
                    newHovering[i] = botoes[i].hovering(mx,my);
                    if(oldHovering[i] != newHovering[i]) { // Se tava em cima do botao, tirou. Se tava fora, colocou em cima.
                        oldHovering[i] = newHovering[i];
                        devoImprimir = true;
                    }
                    if(devoImprimir) {
                        imprime_menu(botoes, BOTOES_SEL_PERSONAGEM_TOTAL, mx, my);
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
