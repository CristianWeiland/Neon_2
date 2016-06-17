#include "menu.h"

Window Win;
Pessoa *Pessoas;
Sprite Sprites;
ALLEGRO_EVENT Ev;
ALLEGRO_FONT *Font;
ALLEGRO_COLOR Color[PESSOAS]; // PESSOAS == numero jogadores
int Njogadores;

void imprime_menu(Botoes *botoes, int n_botoes, int mx, int my, int vencedor) {
/* Imprimir o menu eh uma operacao cara. Soh imprima quando ele mudar:
o jogador passar o mouse por cima de um botao ou clicar em um botao. */
    al_clear_to_color(PRETO);
    for(int i=0; i<n_botoes; ++i) {
        botoes[i].imprime(botoes[i].hovering(mx,my));
    }
    if(vencedor != -1) {
        al_draw_textf(Font, VERDE, 350, 50, 0, "O jogador %d venceu! Parabazi!", vencedor+1);
    }
}

int fecha_jogo(void *param) {
    graphdeinit(Win);
    exit(0);
    return 0;
}

int maior_texto(int index) {
    /* Essa função descobre o maior tamanho de texto dos comandos de um jogador Pessoa[i].
       Não é mais usada. Talvez podemos deletá-la. */
    int aux, maior = 0;
    for(int i=0; i<COMANDOS_POR_PERSONAGEM; ++i) {
        aux = al_get_text_width(Font, al_keycode_to_name(Pessoas[index].botao_char_int[i]));
        if(aux > maior)
            maior = aux;
    }
    return maior;
}

void imprime_configs() {
    int x_variacao = 250;
    al_draw_textf(Font, AMBAR, 350, 50, 0, "Numero de Jogadores  %d", Njogadores);
    for(int i=0; i<PESSOAS; ++i) {
        al_draw_textf(Font, AMARELO_QUEIMADO, 100+x_variacao*i, 100, 0, "Jogador %d", i+1);
        imprime_char(120+x_variacao*i, 150, Pessoas[i].desx, Pessoas[i].desy, Pessoas[i].selx, Pessoas[i].sely, Sprites);
        al_draw_textf(Font, Color[Pessoas[i].time-1], 115+x_variacao*i, 200, 0, "Time %d", Pessoas[i].time);
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 250, 0, "Cima :");
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 270, 0, "Baixo :");
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 290, 0, "Esquerda :");
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 310, 0, "Direita :");
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 330, 0, "Correr :");
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 350, 0, "Puxar :");
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 370, 0, "Flash :");
        al_draw_text(Font, CINZA_ESCURO, 50+x_variacao*i, 390, 0, "Iceball :");

        al_draw_rounded_rectangle(40+x_variacao*i, 85, 245+x_variacao*i, 415, 1, 1, CINZA_CLARO, 2);
    }

    al_draw_text(Font, AMBAR, 350, 600, 0, "Salvar mantem as configuracoes entre execucoes do jogo.");
    al_draw_text(Font, AMBAR, 340, 620, 0, "Clicar em voltar muda as configuracoes somente para essa execucao.");

	// Falta imprimir textos tipo: Escolha seu personagem! Escolha seu time!
}

int salvar_configs(void *param) {
    /* Salva as configurações no arquivo Comandos/cmd.txt */
    FILE *cmd = fopen("Comandos/cmd.txt", "w");
    if(!cmd) {
        perror("Erro ao abrir o arquivo cmd.txt na pasta Comandos.");
        exit(1);
    }
    for(int i=0; i<PESSOAS; ++i) {
        for(int j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            fprintf(cmd, "%d\n", Pessoas[i].botao_char_int[j]);
        }
    }
    fclose(cmd);
    return 0;
}

// Funcoes que retornam 0 significa que o retorno eh ignorado. Se retorno != 0, vai sair do while.

/* Funções que cuidam da seleção de personagem. */
int char_next(void *param) {
    int i = *((int*) param);
	Pessoas[i].desx = (Pessoas[i].desx + 96) % 192;
	Pessoas[i].desy = (Pessoas[i].desx == 0) ? (Pessoas[i].desy + 128) % 256 : Pessoas[i].desy;
	return 0;
}
int char_prev(void *param) {
    int i = *((int*) param);
	Pessoas[i].desx = (Pessoas[i].desx + 96) % 192;
	Pessoas[i].desy = (Pessoas[i].desx != 0) ? (Pessoas[i].desy + 128) % 256 : Pessoas[i].desy;
	return 0;
}


/* Funções que cuidam da seleção de time. */
int team_next(void *param) {
    int i = *((int*) param);
    Pessoas[i].time = (Pessoas[i].time % 4) + 1;
    return 0;
}
int team_prev(void *param) {
    int i = *((int*) param);
    Pessoas[i].time = ((Pessoas[i].time + 2) % 4) + 1;
    return 0;
}

/* Funções para selecionar as teclas para cada personagem. */
void set_buttons(Botoes botoes[BOTOES_SEL_PERSONAGEM_TOTAL]) {
/* Muda o texto dos botoes para as letras que representam as teclas dos jogadores. */
    for(int i=0; i<PESSOAS; ++i) {
        for(int j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            botoes[17+i*COMANDOS_POR_PERSONAGEM+j].set_text(al_keycode_to_name(Pessoas[i].botao_char_int[j]));
        }
    }
}
void esperaTecla() {
    al_draw_text(Font, PIXEL(169,68,66), 350, 500, 0, "Aperte alguma tecla...");
    al_flip_display();
    while(Ev.type != ALLEGRO_EVENT_KEY_DOWN)
        al_wait_for_event(Win.event_queue, &Ev); // Espera usuário apertar uma tecla.
}
int set_next_key(void *params) {
    int indice_pessoa = (int) ((int*)params)[0];
    int indice_tecla = (int) ((int*)params)[1];
    esperaTecla();
    Pessoas[indice_pessoa].botao_char_int[indice_tecla] = Ev.keyboard.keycode;
    return 0;
}

int num_jogadores_inc(void *params) { Njogadores = (Njogadores % 4) + 1; return 0; }
int num_jogadores_dec(void *params) { Njogadores = ((Njogadores + 2) % 4) + 1; return 0; }

/* Função para retornar ao menu principal. Chamada pelo botão "voltar" */
int return_int(void *params) {
    return *((int*) params);
}



/* Menu de seleção de personagens, times e teclas. */
int selecao_personagem(void *) {
	int i, j, tamanho, mx = 0, my = 0, retorno = 0;
    int x_inicial[2] = {100,170}; // Posição inicial dos "<" e ">" (botoes pra selecionar personagem e time).
    int x_variacao = 250; // Distancia entre dois "<"
    int param[2];
    Botoes botoes[BOTOES_SEL_PERSONAGEM_TOTAL];
    bool oldHovering[BOTOES_SEL_PERSONAGEM_TOTAL], newHovering[BOTOES_SEL_PERSONAGEM_TOTAL], devoImprimir = false;

    for(i=0; i<BOTOES_SEL_PERSONAGEM_TOTAL; ++i)
        oldHovering[i] = newHovering[i] = false;

    /* Inicialização da estrutura Pessoas. */
    for(i=0; i<PESSOAS; ++i) {
        Pessoas[i].desx = 0;
        Pessoas[i].desy = 0;
        Pessoas[i].selx = 32;
        Pessoas[i].sely = 0;
    }

    for(i=0; i<PESSOAS; ++i) {
        param[0] = i;
        /* Botoes para selecionar personagens. */
        botoes[2*i  ].set_button("<", x_inicial[0] + i*x_variacao, 160, char_prev, (void*) param, sizeof(int)) ;
        botoes[2*i+1].set_button(">", x_inicial[1] + i*x_variacao, 160, char_next, (void*) param, sizeof(int)) ;
        /* Botoes para selecionar times. */
        botoes[2*i+8].set_button("<", x_inicial[0] + i*x_variacao, 200, team_prev, (void*) param, sizeof(int)) ;
        botoes[2*i+9].set_button(">", x_inicial[1] + i*x_variacao, 200, team_next, (void*) param, sizeof(int)) ;
    }
    /* Botao para voltar para o menu inicial. */
    param[0] = 1;
    botoes[16].set_button("Voltar", 50, 500, return_int, (void*) param, sizeof(int));
    /* Botoes para selecionar as teclas que executam os comandos de cada personagem. */
    for(i=0; i<PESSOAS; ++i) {
        for(j=0; j<COMANDOS_POR_PERSONAGEM; ++j) {
            param[0] = i;
            param[1] = j;
            botoes[17+i*COMANDOS_POR_PERSONAGEM+j].set_button("", 145+250*i, 250+20*j, set_next_key, (void*) param, sizeof(int) * 2);
        }
    }
    /* Botoes pra selecionar numero de jogadores - se adicionar mais comandos, tem que mudar esses índices! */
    botoes[49].set_button("<", 510, 50, num_jogadores_dec, NULL, 0);
    botoes[50].set_button(">", 540, 50, num_jogadores_inc, NULL, 0);
    botoes[51].set_button("Salvar", 729, 500, salvar_configs, NULL, 0);

    set_buttons(botoes);
    imprime_menu(botoes, BOTOES_SEL_PERSONAGEM_TOTAL, mx, my, -1);
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
                        imprime_menu(botoes, BOTOES_SEL_PERSONAGEM_TOTAL, mx, my, -1);
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
                }
                if(devoImprimir) {
                    imprime_menu(botoes, BOTOES_SEL_PERSONAGEM_TOTAL, mx, my, -1);
					imprime_configs();
					al_flip_display();
                    devoImprimir = false;
                }
                break ;
        }
    } while(!retorno);

    return 0;
}

int menu_principal(Window win,Pessoa *p,Sprite s,int *num_jogadores, int vencedor)
{
    Njogadores = PESSOAS;
    *num_jogadores = PESSOAS;
	int i, tamanho, mx = 0, my = 0, retorno = 0, params[1];
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

    params[0] = 1;
    botoes[0].set_button("Jogar", 400, 300, return_int, (void*) params, sizeof(int));
    botoes[1].set_button("Configuracoes", 400, 350, selecao_personagem, NULL, 0);
    botoes[2].set_button("Sair", 400, 400, fecha_jogo, NULL, 0);

    imprime_menu(botoes, NUM_BOTOES, mx, my, vencedor);
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
                            *num_jogadores = Njogadores;
                        	return 1;
                        }
                        imprime_menu(botoes, NUM_BOTOES, mx, my, vencedor);
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
                        imprime_menu(botoes, NUM_BOTOES, mx, my, vencedor);
                        al_flip_display();
                        devoImprimir = false;
                    }
                }
                break ;
        }
    } while(!retorno);
    *num_jogadores = Njogadores;
    return retorno;
}
