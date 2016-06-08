#ifndef MAGIA_H
#define MAGIA_H

#include "colisao.h"

void init_magias(Magias *m);
void tira_neon(bool *puxa,bool *temneon, Pessoa *p);
void calcula_status(Pessoa *p, int njogadores);
void usa_fireball(char **matriz, Pessoa *p, Magias *m);
void explosao(Pessoa *p, int njogadores, Sprite s,int explox[4][2],int exploy[4][2], Magias *m);
void usa_iceball(char **matriz, Pessoa *p, Magias *m);
void gelo(Pessoa *p, int njogadores, Sprite s,int explox[4][2],int exploy[4][2], Magias *m);
void usa_magias(char **matriz, Pessoa *pessoas, int njogadores, Sprite s, int *flash, Magias *m);
int calcula_direcao(Pessoa *p,int i);
void usa_flash(Pessoa *p,int *flash,char **matriz);

#endif