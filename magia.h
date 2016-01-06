#ifndef MAGIA_H
#define MAGIA_H

#include "colisao.h"

void tira_neon(bool *puxa,bool *temneon, Pessoa *p);
void desconta_energia(Pessoa *p, int njogadores);
void usa_magias(char **matriz,Magia (*fb)[2], Pessoa *pessoas);
int calcula_direcao(Pessoa *p,int i);
void flash(Pessoa *p,int *tlep,char **matriz);

#endif