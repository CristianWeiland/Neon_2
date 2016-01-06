#ifndef MAGIA_H
#define MAGIA_H

#include "colisao.h"

void tira_neon(bool *puxa,bool *temneon,int *cx,int *cy,int *andou_b,int *andou_c,int *andou_d,int *andou_e, Pessoa *p);
void desconta_energia(int andou_b[],int andou_c[],int andou_d[],int andou_e[],int correr[],int energia[], Pessoa *p);
void usa_magias(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int *energia,int *cx,int *cy,char **matriz,Magia (*fb)[2], Pessoa *pessoas);
int calcula_direcao(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int i);
void flash(int *andou_b,int *andou_c,int *andou_d,int *andou_e,int *energia,int *cx,int *cy,int *tlep,char **matriz, Pessoa *p);

#endif