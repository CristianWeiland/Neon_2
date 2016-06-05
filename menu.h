#ifndef menu_header
#define menu_header
// walter.wwb@gmail.com
#include <unistd.h>
#include "imprime.h"
#include "grafico.h"

//extern Pessoa pessoa[4];

char editor_text(ALLEGRO_EVENT ev);
int botao(char *texto,int x,int y,ALLEGRO_EVENT ev);
void opcoes(Window win, Pessoa *p);
int selecao_personagem(void);
int menu_principal(Window win,Pessoa *p,Sprite s);

#define TEXT_SIZE 128
#define NUM_BOTOES 5
#define BUTTON_WIDTH 122
#define BUTTON_HEIGHT 32
#define HOVER_BUTTON_DISLOCATION 40
#define CLICK_BUTTON_DISLOCATION 80
#define NUM_BOTOES_SEL_PERSONAGEM 18 // 16 pra selecionar, 1 pra voltar, 1 pra salvar.


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

    void set_func(int (*fun)()) {
        func = fun;
    }

    int execute() {
        if(!func)
            return -1;
        return func();
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
    int (*func)();
    ALLEGRO_FONT *font;
    ALLEGRO_BITMAP *button_bmp;
};
#endif
