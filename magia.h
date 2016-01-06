#ifndef MAGIA_H
#define MAGIA_H

#include "colisao.h"

void tira_neon(bool *puxa,bool *temneon,int *cx,int *cy, Pessoa *p);
void desconta_energia(Pessoa *p, int njogadores);
void usa_magias(int *cx,int *cy,char **matriz,Magia (*fb)[2], Pessoa *pessoas);
int calcula_direcao(Pessoa *p,int i);
void flash(Pessoa *p,int *cx,int *cy,int *tlep,char **matriz);

#endif