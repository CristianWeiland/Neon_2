#include <stdio.h>
#include "faz_isom.h"

#define n 10000
#define XMENU 850
#define YMENU 450
#define MIN_X_CORTE 0
#define MAX_X_CORTE 576
#define MIN_Y_CORTE 32
#define MAX_Y_CORTE 992

Window graphinit() {
    Window win = {NULL, NULL, NULL, {0, 0, 0, 0}};
    FILE *errext = fopen("err.ext", "w");
  
    if(!al_init()) {
        fprintf(errext,"Erro ao abrir al_init");
        fclose(errext);
        exit(1);
    }

    if(!al_init_image_addon()) {
        fprintf(errext,"Erro ao abrir al_init_image_addon");
        fclose(errext);
        exit(1);
    }

    if(!al_init_primitives_addon()) {
        fprintf(errext,"Erro ao abrir al_init_primitives_addon");
        fclose(errext);
        exit(1);
    }

    if(!al_init_native_dialog_addon()) {
        fprintf(errext,"Erro ao abrir al_init_native_dialog_addon");
        fclose(errext);
        exit(1);
    }

    al_init_font_addon();

    win.disp_data.width = 1024;
    win.disp_data.height = 700;
    win.disp_data.refresh_rate = 60;
    win.display = al_create_display(win.disp_data.width, win.disp_data.height);
    if(!win.display) {
        fprintf(errext,"Erro ao abrir display");fclose(errext);exit(1); }
  
    al_install_mouse();
    al_install_keyboard();

    win.timer = al_create_timer(1.0 / win.disp_data.refresh_rate);
    win.event_queue = al_create_event_queue();
  
    al_register_event_source(win.event_queue, al_get_display_event_source(win.display));
    al_register_event_source(win.event_queue, al_get_mouse_event_source());
    al_register_event_source(win.event_queue, al_get_keyboard_event_source());
    al_register_event_source(win.event_queue, al_get_timer_event_source(win.timer));
  
    al_clear_to_color(PRETO);
    al_flip_display();
    al_start_timer(win.timer);

    fclose(errext);
  
    return (win);
}

void graphdeinit(Window win) {
    al_destroy_timer(win.timer);
    al_destroy_event_queue(win.event_queue);
    al_destroy_display(win.display);
}

int main() {
    Window win = graphinit();
    ALLEGRO_BITMAP *tileiso = al_load_bitmap("tile_iso.bmp");
    ALLEGRO_BITMAP *tilemenu = al_load_bitmap("menu_iso.bmp");
    ALLEGRO_FONT *font = al_load_font("font.tga", 12, 0);
    int i, j, largura_pincel = 1, largura_sel = 1, altura_sel = 1;
    int xtile[n], ytile[n], xcorte[n], ycorte[n];
    int xcorte_aux = 0, ycorte_aux = 32;
    int aux = -1, pos = 0;
    int pos_x, pos_y, index = 0, old_pos_x = 0, old_pos_y = 0;
    int mouse_x, mouse_y;
    unsigned int mouse_b = 0;
    FILE *arquivo;
    bool redraw = true, sair = false, salvo = true;

    if(!tileiso) {
        puts("Nao consegui abrir tileiso.");
        exit(1);
    }
    if(!tilemenu) {
        puts("Nao consegui abrir tileiso.");
        exit(1);
    }

    for(i=0; i<n; ++i) {
        xtile[i] = -100;
        ytile[i] = -100;                          
    }

    al_convert_mask_to_alpha(tileiso, al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(tilemenu, al_map_rgb(255,0,255));

    ALLEGRO_EVENT ev;
    while(!sair) {
        al_wait_for_event(win.event_queue, &ev);
        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // Detecta se clicaram no X.
            graphdeinit(win);
            exit(1);
        } else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            if(ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
                for(j=0; j<n; ++j) {
                    xtile[j] += 32;
                }   
                ++pos;
                redraw = true;
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
                for(j=0; j<n; ++j) {
                    xtile[j] -= 32;
                }
                --pos;
                redraw = true;
            }

            /*
            0  <= xcorte <= 960, isto é, xcorte só pode ser um valor entre 0 e 960.
            32 <= icorte <= 992
            */
            if(ev.keyboard.keycode == ALLEGRO_KEY_L) {
                if(xcorte_aux + 64*(largura_sel-1) < MAX_X_CORTE) {
                    xcorte_aux += 64;
                    redraw = true;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_H) {
                if(xcorte_aux > MIN_X_CORTE) {
                    xcorte_aux -= 64;
                    redraw = true;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_J) {
                if(ycorte_aux + 32*(altura_sel-1) < MAX_Y_CORTE) {
                    ycorte_aux += 32;
                    redraw = true;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_K) {
                if(ycorte_aux > MIN_Y_CORTE) {
                    ycorte_aux -= 32;
                    redraw = true;
                }
            }
            /* Escolhe tile indo pro extremo cima/esquerda ou extremo esquerda/direita */
            if(ev.keyboard.keycode == ALLEGRO_KEY_O) {
                xcorte_aux = MAX_X_CORTE - 64*(largura_sel-1);
                redraw = true;
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_Y) {
                xcorte_aux = MIN_X_CORTE;
                redraw = true;
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_U) {
                ycorte_aux = MAX_Y_CORTE - 32*(altura_sel-1);
                redraw = true;
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_I) {
                ycorte_aux = MIN_Y_CORTE;
                redraw = true;
            }
            /* Controla o número de tiles inseridos de cada vez. */
            if(ev.keyboard.keycode == ALLEGRO_KEY_Q) {
                if(largura_pincel <= 7) {
                    largura_pincel += 2;
                    redraw = true;
                    largura_sel = 1;
                    altura_sel = 1;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_W) {
                if(largura_pincel > 1) {
                    largura_pincel -= 2;
                    redraw = true;
                    largura_sel = 1;
                    altura_sel = 1;
                }
            }
            /* Controla o número de tiles selecionados de cada vez. */
            if(ev.keyboard.keycode == ALLEGRO_KEY_D && xcorte_aux + 64*(largura_sel-1) < MAX_X_CORTE) {
                if(largura_sel <= 7) {
                    largura_sel += 1;
                    redraw = true;
                    largura_pincel = 1;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_F) {
                if(largura_sel > 1) {
                    largura_sel -= 1;
                    redraw = true;
                    largura_pincel = 1;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_E) {
                if(altura_sel <= 7 && ycorte_aux + 32*(altura_sel-1) < MAX_Y_CORTE) { // Não pode passar do limite pra baixo. Tá errado.
                    altura_sel += 1;
                    redraw = true;
                    largura_pincel = 1;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_R) {
                if(altura_sel > 1) {
                    altura_sel -= 1;
                    redraw = true;
                    largura_pincel = 1;
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_A) {
                arquivo = fopen("lago.txt", "r");
                if(arquivo) {
                    fscanf(arquivo, "%i\n",&index);
                    for(i=0; i<index+1; ++i) {
                        fscanf(arquivo,"%i %i %i %i\n",&xtile[i],&ytile[i],&xcorte[i],&ycorte[i]);
                    }
                    fclose(arquivo);
                }
            }
            if(ev.keyboard.keycode == ALLEGRO_KEY_S) {
                arquivo = fopen("mapa.txt", "w");
                puts("Salvando no arquivo...");
                for(i=0; i<index; ++i) {
                    if(xtile >= 0 && ytile >= 0) {
                        ++aux;
                    }
                }
                //fprintf(arquivo,"%i\n",index+1);
                fprintf(arquivo,"%i\n",aux+1);
                // for(i=0; i<index+1; ++i) {
                for(i=0; i<index; ++i) {
                    if(xtile[i] >= 0 && ytile[i] >= 0) {
                        fprintf(arquivo,"%i %i %i %i\n",xtile[i],ytile[i],xcorte[i],ycorte[i]);
                    }
                }
                fclose(arquivo);
                salvo = true;
            }
        } else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES) {
            mouse_x = ev.mouse.x;
            mouse_y = ev.mouse.y;
            /* Dado dois inteiros mouse_x e mouse_y, pega os valores deles arredondados para um múltiplo de 32 e 16. */
            pos_x = mouse_x - (mouse_x % 32);
            pos_y = mouse_y - (mouse_y % 16);
            if(old_pos_x != pos_x || old_pos_y != pos_y) {
                redraw = true;
            }
            old_pos_x = pos_x;
            old_pos_y = pos_y;
        } else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
            mouse_b = ev.mouse.button;
            redraw = true;
            salvo = false;
        }

        if(mouse_b & 1) {
            /* Se a largura do pincel é maior que 1, é garantido que o tamanho da seleção é 1x1.
               Portanto, escreve tratando a largura do pincel. */
            if(largura_pincel > 1)
                for(i=0; i<largura_pincel; ++i) {
                    for(j=0; j<largura_pincel; ++j) {
                        xtile[index] = pos_x+32*(j+i);
                        ytile[index] = pos_y-16*j+16*i;
                        xcorte[index] = xcorte_aux;
                        ycorte[index] = ycorte_aux;
                        ++index;
                    }
                }
            /* Se a largura for igual a 1, a seleção ou é 1x1 ou é maior. Então trata de um jeito
               genérico, que funciona pra seleção sendo 1x1 ou qualquer outro tamanho. */
            else {
                for(i=0; i<largura_sel; ++i) {
                    for(j=0; j<altura_sel; ++j) {
                        xtile[index] = pos_x+64*i;
                        ytile[index] = pos_y+32*j;
                        xcorte[index] = xcorte_aux+64*i;
                        ycorte[index] = ycorte_aux+32*j;
                        ++index;
                    }
                }
            }
        } else if(mouse_b & 2) {
            for(aux = 0; aux < index; ++aux) {
                xtile[index] = pos_x;
                if(xtile[aux] == pos_x) {
                    if(ytile[aux] == pos_y) {
                        xtile[aux] = -100;
                        ytile[aux] = -100;
                        xcorte[index] = 0;
                        ycorte[index] = 0;
                    }
                }
            }
        }

        mouse_b = 0;

        if(redraw && al_is_event_queue_empty(win.event_queue)) {

            al_clear_to_color(al_map_rgb(0,0,0));

            /* Imprime o mapa. */
            for(j=0; j<index; ++j) {
                if(xtile[j] >= 0)
                    al_draw_bitmap_region(tileiso, xcorte[j], ycorte[j], 64, 32, xtile[j], ytile[j], 0);
            }

            /* Desenha os quadrados azuis pra indicar onde vou inserir o(s) tile(s). */
            al_draw_line((float) pos_x   , (float) pos_y+16, (float) pos_x+32*largura_pincel, (float) pos_y-16*(largura_pincel-1)   , al_map_rgb(0,0,255), 1);
            al_draw_line((float) pos_x+32*(largura_pincel), (float) pos_y-16*(largura_pincel-1)   , (float) pos_x+64+64*(largura_pincel-1), (float) pos_y+16, al_map_rgb(0,0,255), 1);
            al_draw_line((float) pos_x+64+64*(largura_pincel-1), (float) pos_y+16, (float) pos_x+32*largura_pincel, (float) pos_y+16+16*(largura_pincel), al_map_rgb(0,0,255), 1);
            al_draw_line((float) pos_x+32*(largura_pincel), (float) pos_y+16+16*(largura_pincel), (float) pos_x   , (float) pos_y+16, al_map_rgb(0,0,255), 1);

            /* Desenha o menu de tiles. */
            al_draw_bitmap(tilemenu, XMENU, YMENU, 0);

            /* Desenha o retângulo ao redor do menu de tiles. */
            al_draw_rectangle((float) (XMENU - 1), (float) (YMENU + 4), (float) (XMENU + 640/5 + 1), (float) (YMENU + 1024/5 + 5), BRONZE, 1);

            /* Desenha o retângulo azul que mostra quais tiles estão selecionados (pra entender essa linha, olhar no explicação 1 no final do código) */
            al_draw_rectangle(((float) xcorte_aux)/5+XMENU, ((float)ycorte_aux+32*(altura_sel-1))/5+YMENU+8, ((float) (xcorte_aux+64*(largura_sel-1))/5)+12+XMENU, ((float) ycorte_aux)/5+YMENU-2, al_map_rgb(0,0,255), 1);

            /* Imprime comandos básicos. */
            al_draw_text(font, CARMESIM, 20, 20, 0, "Comandos: S (Salvar), Seta <-- e -->, A (Carregar), Q (Expandir Pincel), W (Diminuir Pincel)");
            al_draw_text(font, CARMESIM, 20, 40, 0, "E (Expandir Altura Selecao), R (Diminuir Altura Selecao), D (Expandir Largura Selecao)");
            al_draw_text(font, CARMESIM, 20, 60, 0, "F (Diminuir Largura Selecao), H (Esquerda), J (Baixo), K (Cima), L (Direita)");
            al_draw_text(font, CARMESIM, 20, 80, 0, "Y (Esquerda Total), U (Baixo Total), I (Cima Total), O (Direita Total)");

            /* Imprime se foram feitas modificações desde a última vez que o arquivo foi salvo. */
            if(salvo)
                al_draw_text(font, CARMESIM, 20, 100, 0, "Todas as alteracoes foram salvas.");
            else
                al_draw_text(font, CARMESIM, 20, 100, 0, "Existem alteracoes nao salvas!");

            // al_draw_textf(font, al_map_rgb(255,0,0), 100, 70, 0, "Xcorte = %d, ycorte = %d", pos_x, pos_y);
            al_flip_display();
            redraw = false;
        }

    }
    return 0;
}

/*
Explicação 1:
Tenho um retângulo com os vértices a, b, c, d.

a---b
|   |
|   |
c---d

Pra desenhar ele, só preciso de (x,y) de 'a' e (x,y) de 'd', ou (x,y) de 'c' e (x,y) de 'b'.
Atualmente, eu desenho usando (x,y) de 'c' e 'b'.
*/