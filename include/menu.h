// walter.wwb@gmail.com
#include <unistd.h>
#include "imprime.h"
#include "grafico.h"

extern Pessoa pessoa[4];

char editor_text(ALLEGRO_EVENT ev);
int botao(char *texto,int x,int y,ALLEGRO_EVENT ev);
void opcoes(Window win);
int abremenu(Window win,ALLEGRO_BITMAP *chars);
