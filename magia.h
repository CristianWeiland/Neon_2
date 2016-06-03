#ifndef MAGIA_H
#define MAGIA_H

#include "colisao.h"

void tira_neon(bool *puxa,bool *temneon, Pessoa *p);
void calcula_energia(Pessoa *p, int njogadores);
void usa_fireball(char **matriz,Magia (*fb)[2], Pessoa *p);
void explosao(Pessoa *p, int njogadores, Sprite s,int explox[4][2],int exploy[4][2],Magia (*fireball)[2]);
void usa_magias(char **matriz,Magia (*fb)[2], Pessoa *pessoas, int njogadores, Sprite s,int explox[4][2],int exploy[4][2], int *flash);
int calcula_direcao(Pessoa *p,int i);
void usa_flash(Pessoa *p,int *flash,char **matriz);

#endif