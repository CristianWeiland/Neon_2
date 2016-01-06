#include "colisao.h"

/* ---------------------------------------- */

char** le_matriz(FILE *fp)
{
	char** matriz;
	int i,j;
	//FILE *fp = ;

	matriz = (char**)calloc(TAM,sizeof(char*));
	for(i=0;i<TAM;i++)
	    matriz[i] = (char*)calloc(TAM,sizeof(char));

	for(i=0;i<TAM;i++)
	{
	    for(j=0;j<TAM;j++){
	        fscanf(fp,"%c",&matriz[j][i]);
	    }
	    fscanf(fp,"\n");
	}
	return matriz;
}

int contato_proximo(int *cx,int *cy,int *andou_b,int *andou_c,int *andou_d,int *andou_e,int i,int j, Pessoa *p)
{	// I eh o char que tah realizando a acao, J eh o cara que talvez foi atacado / puxado o neon
	if(p[i].andou_c == 1 || (p[i].andou_b == 0 && p[i].andou_c == 0 && p[i].andou_d == 0 && p[i].andou_e == 0)) { // Olhando pra cima.
		for(j=0;j<4;j++) {
			if(j!=i && ( (cy[i]-cy[j]<=24 && cy[i]-cy[j]>=0) && (cx[i]-cx[j]<=8 && cx[i]-cx[j]>=-8 ) ) )
				return j;
		}
	} else if(p[i].andou_d == 1) { // Olhando pra direita.
		for(j=0;j<4;j++) {
			if(j!=i && ( (cy[i]-cy[j]<=8 && cy[i]-cy[j]>=-8) && (cx[i]-cx[j]<=0 && cx[i]-cx[j]>=-32 ) ) )
				return j;
		}
	} else if(p[i].andou_e == 1) {
		for(j=0;j<4;j++) {
			if(j!=i && ( (cy[i]-cy[j]<=8 && cy[i]-cy[j]>=-8) && (cx[i]-cx[j]<=32 && cx[i]-cx[j]>=0 ) ) )
				return j;
		}
	}
	if(p[i].andou_b == 1) { // Olhando pra baixo. OBS: AQUI EH MESMO IF E NAO ELSE IF??
		for(j=0;j<4;j++) {
			if(j!=i && ( (cy[i]-cy[j]<=0 && cy[i]-cy[j]>=-24) && (cx[i]-cx[j]<=8 && cx[i]-cx[j]>=-8 ) ) )
				return j;
		}
	}
	return 5;
}

int contato_proximo_direcionado(int x,int y,int *cx,int *cy,int i,int j,int d)
{	// I eh o char que tah realizando a acao, J eh o cara que talvez foi atacado / puxado o neon *
/* x e y eh a posicao de quem tah andando (ex: fireball, char), cx e cy usados pra verificar se  *
 * bateu em algum outro char. D eh a direçao (0 = cima, 1 = direita, 2 = esquerda, 3 = baixo)    */
	if(d == 0) { // Olhando pra cima.
		for(j=0;j<4;j++) {
			if(j!=i && ( (y-cy[j]<=24 && y-cy[j]>=0) && (x-cx[j]<=8 && x-cx[j]>=-8 ) ) )
				return j;
		}
	} else if(d == 1) { // Olhando pra direita.
		for(j=0;j<4;j++) {
			if(j!=i && ( (y-cy[j]<=8 && y-cy[j]>=-8) && (x-cx[j]<=0 && x-cx[j]>=-32 ) ) )
				return j;
		}
	} else if(d == 2) {
		for(j=0;j<4;j++) {
			if(j!=i && ( (y-cy[j]<=8 && y-cy[j]>=-8) && (x-cx[j]<=32 && x-cx[j]>=0 ) ) )
				return j;
		}
	}
	if(d == 3) { // Olhando pra baixo.
		for(j=0;j<4;j++) {
			if(j!=i && ( (y-cy[j]<=0 && y-cy[j]>=-24) && (x-cx[j]<=8 && x-cx[j]>=-8 ) ) )
				return j;
		}
	}
	return 5;
}

int colisao_fireball(char** map,int x,int y,int d)
/* M eh a matriz, x e y sao as coordenadas que a fireball tah,       *
 * d eh a direcao que ela tah indo.	xm e ym serao x e y na matriz.   *
 * Lembrando que a fireball eh 16x32 ou 32x16 (4x8 ou 8x4 na matriz) */
{
	int i,j;
	int xm = x/4;
	int ym = y/4;
	switch(d) {
		case 0: // Fireball pra cima
			for(i=0;i<4;i++) {
				if(map[xm+8+i][ym+1] == '3' || map[xm+8+i][ym+2] == '3')
                       return 1;
			}
			break;
		case 1:

			break;
		case 2:

			break;
		case 3:

			break;
	}
	return 0;
}

int colidiu(char** map,int x,int y,int caso,int cx[],int cy[],int eu)
/*
Lembrando que o formato do char eh (A eh o que representa ele):
P X X X X X X X     // Isso eh 8x8 porque a imagem do char eh 32x32 pixels. Como a matriz foi dividida por 4 em cada direçao,
X X X X X X X X     // 32/4 = 8 e 32/4 = 8 -> 32x32 = 8x8.
X X X X X X X X     // Como sao as pernas que fazem a colisao na imagem, apenas os A's podem bater.
X X X X X X X X
P X A A A A X X
X X A A A A X X
X X A A A A X X
X X A A A A X X
X X H H H H X X
X X H H H H X X
X X H H H H X X
X X H H H H X X

X P X X X X X X X     // Isso eh 8x8 porque a imagem do char eh 32x32 pixels. Como a matriz foi dividida por 4 em cada direçao,
X X X X X X X X X     // 32/4 = 8 e 32/4 = 8 -> 32x32 = 8x8.
X X X X X X X X X     // Como sao as pernas que fazem a colisao na imagem, apenas os A's podem bater.
X X X X X X X X X
X X P A A A A X X
X X X A A A A X X
X X X A A A A X X
X X X A A A A X X
X X X X H H H H X
X X X X H H H H X
X X X X H H H H X
X X X X H H H H X

X P X X X X X X X     // Isso eh 8x8 porque a imagem do char eh 32x32 pixels. Como a matriz foi dividida por 4 em cada direçao,
X X X X X X X X X     // 32/4 = 8 e 32/4 = 8 -> 32x32 = 8x8.
X X X X X X X X X     // Como sao as pernas que fazem a colisao na imagem, apenas os A's podem bater.
X X X X X X X X X
P X X A A A A X X
X X X A A A A X X
X X X A A A A X X
X X X A A A A X X
X X H H H H X X X
X X H H H H X X X
X X H H H H X X X
X X H H H H X X X

X P X X X X X X X X   // Isso eh 8x8 porque a imagem do char eh 32x32 pixels. Como a matriz foi dividida por 4 em cada direçao,
X X X X X X X X X X   // 32/4 = 8 e 32/4 = 8 -> 32x32 = 8x8.
X X X X X X X X X X   // Como sao as pernas que fazem a colisao na imagem, apenas os A's podem bater.
X X X X X X X X X X
X X X A P A A X X X
X X X A A A A X X X
X X X A A A A X X X
X X X A A A A X X X
X X X X X X H H H H
X X X X X X H H H H
X X X X X X H H H H
X X X X X X H H H H

As colisoes funcionam do seguinte modo (sendo B colisao pra baixo, C pra cima, E pra esquerda e D pra direita).
X X C C C C X X
X E A A A A D X
X E A A A A D X
X E A A A A D X
X E A A A A D X
X X B B B B X X
*/
{
    int i,j,coordx[5],coordy[5];
    for(i=0;i<5;i++)
    {
        coordx[i] = cx[i]/4;
        coordy[i] = cy[i]/4;
    }
    //printf("\n\n\n%d",caso);

    /*for(i=0;i<25;i++)
    {
        for(j=0;j<25;j++)
            printf("%c",map[x+i][y+j]);
        printf("\n");asd
    }*/
    switch(caso)
    {
        case 0: // Tentou andar pra baixo.
            for(i=0;i<4;i++) // Colisoes com o mapa.
                if((map[x+2+i][y+8] =='0')||(map[x+2+i][y+8] == '3'))
                    return 1;
                for(i=0;i<5;i++) // Colisoes com os chars.
                    if(coordy[i]-4 == y && ((x==coordx[i]+3)||(x==coordx[i]+2)||(x==coordx[i]+1)||(x==coordx[i])||(x==coordx[i]-1)||(x==coordx[i]-2)||(x==coordx[i]-3))&& i!=eu)
                        return 1;

            break;
        case 1: // Tentou andar pra esquerda.
            for(i=0;i<4;i++)
                if(map[x+1][y+4+i] == '3' || map[x+1][y+4+i] == '0')
                    return 1;
            if(x<=0) // Nao deixa ele passar do limite esquerdo do display.
	        {
			  	return 1;
            }

            for(i=0;i<5;i++) // Colisoes com os chars.
                if(coordx[i]+5 == x && ((y==coordy[i]+3)||(y==coordy[i]+2)||(y==coordy[i]+1)||(y==coordy[i])||(y==coordy[i]-1)||(y==coordy[i]-2)||(y==coordy[i]-3)) && i!=eu)
                    return 1;

            break;
        case 2: // Tentou andar pra cima.
            for(i=0;i<4;i++)
                if(map[x+2+i][y+3] == '3' || map[x+2+i][y+3] == '0')
                    return 1;
            for(i=0;i<5;i++) // Colisoes com os chars.
                if(coordy[i]+4 == y && ((x==coordx[i]+3)||(x==coordx[i]+2)||(x==coordx[i]+1)||(x==coordx[i])||(x==coordx[i]-1)||(x==coordx[i]-2)||(x==coordx[i]-3))&& i!=eu)
                    return 1;

              break;
        case 3: // Tentou andar pra direita.
            for(i=0;i<4;i++)
                if(map[x+6][y+4+i] == '3' || map[x+6][y+4+i] == '0')
                    return 1;
            for(i=0;i<5;i++) // Colisoes com os chars.
                if(coordx[i]-5 == x && ((y==coordy[i]+3)||(y==coordy[i]+2)||(y==coordy[i]+1)||(y==coordy[i])||(y==coordy[i]-1)||(y==coordy[i]-2)||(y==coordy[i]-3)) && i!=eu)
                    return 1;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}
