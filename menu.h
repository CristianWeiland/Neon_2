#ifndef menu_header
#define menu_header
// walter.wwb@gmail.com
#include <unistd.h>
#include "imprime.h"
#include "grafico.h"

char editor_text(ALLEGRO_EVENT ev);
int botao(char *texto,int x,int y,ALLEGRO_EVENT ev);
void opcoes(Window win, Pessoa *p);
int selecao_personagem(void);
int menu_principal(Window win,Pessoa *p,Sprite s,int *num_jogadores, int vencedor);

#define TEXT_SIZE 128
#define NUM_BOTOES 3
#define BUTTON_WIDTH 122
#define BUTTON_HEIGHT 32
#define HOVER_BUTTON_DISLOCATION 40
#define CLICK_BUTTON_DISLOCATION 80
#define BOTOES_SEL_PERSONAGEM 8
#define BOTOES_SEL_TIME 8
#define BOTOES_SEL_N_JOGADORES 2
#define OUTROS_BOTOES 1 // voltar
//#define COMANDOS_POR_PERSONAGEM é definido no colisao.h

// 16 pra selecionar, 1 pra voltar, 28 teclas (7 pra cada jogador, 4 jogadores), 2 pra selec. nº jogadores -> Total = 47.
#define BOTOES_SEL_PERSONAGEM_TOTAL BOTOES_SEL_PERSONAGEM + BOTOES_SEL_TIME + OUTROS_BOTOES + PESSOAS*COMANDOS_POR_PERSONAGEM + BOTOES_SEL_N_JOGADORES

class Botoes {
public:
    Botoes() {
        x = y = 0;
        font = al_load_font("Fonts/fixed_font.tga", 10, 0);
    }

    void set_text(const char* str) {
        int i, size = strlen(str);
        if(size > TEXT_SIZE) size = TEXT_SIZE;

        for(i=0; i<size; ++i)
            text[i] = str[i];
        text[i] = '\0';

        width = al_get_text_width(font, text);
        if(width < 5)
            width = 10; // Minimum width
        height = al_get_font_line_height(font);

        sumx = x + width;
        sumy = y + height;
    }

    void set_position(int posx, int posy) {
        x = posx;
        y = posy;
    }

    void set_func(int (*fun)(void *)) {
        func = fun;
    }

    void set_button(const char *str, int posx, int posy, int (*fun)(void *), void *param, int tam_param) {
        /* A função que o botão pode executar é genérica. Isso significa que ela deve receber parâmetros genéricos (void*).
         * Assim, eu posso receber qualquer parâmetro quando crio o botão, que vem através de 'param' e tem 'tam_param' bytes.
         * Se a função não recebe nenhum parâmetro, 'param' deve ser igual a NULL ou 'tam_param' igual a 0.
         */
        set_position(posx, posy);
        set_text(str);
        set_func(fun);
        if(tam_param >= 0 && param != NULL) {
            params = malloc(tam_param);
            memcpy(params, param, tam_param);
        }
    }

    int execute() {
        if(!func)
            return -1;
        return func(params);
    }

    bool hovering(int mousex, int mousey) {
        if(mousex > x && mousex < sumx && mousey > y && mousey < sumy)
            return true;
        return false;
    }

    void imprime(bool hover) {
        ALLEGRO_COLOR cor = hover ? BRANCO : CINZA_ESCURO;
        int image_h_sel = hover ? HOVER_BUTTON_DISLOCATION : 0;
        //al_draw_bitmap_region(button_bmp, 0, image_h_sel, BUTTON_WIDTH, BUTTON_HEIGHT, x, y, 0);
        al_draw_text(font, cor, x, y, 0, text);
    }
private:
    int x, y, width, height, sumx, sumy;
    char text[TEXT_SIZE];
    int (*func)(void *);
    void *params;
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *button_bmp;
};
#endif
