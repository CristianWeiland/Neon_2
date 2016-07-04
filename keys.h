#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "colisao.h"

/* Allegro */
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3
#define CORRE 4
#define PUXAR 5
#define FLASH 6
#define ICEBALL 7
#define TRAP 8

void teclas_iniciais(Pessoa *pessoa);
void keyboard_down(int evkeyboardkeycode,bool *puxa,int *flash, Pessoa *p, Magias *m, int njogadores);
void keyboard_up(int evkeyboardkeycode,bool *puxa,bool *sair, Pessoa *p, int njogadores);

/*
b 2
c 3
> 83
< 82
: 218
i 9
k 11
l 12
j 10
u 21
t 20
g 7
h 8
f 6
r 18
w 23
s 19
d 4
a 1
q 17
*/
