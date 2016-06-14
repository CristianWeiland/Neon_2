#include <unistd.h>
//#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

char** escreve_arquivo(char **map);
char** escreve_tile_1_1(char **map,int linhas,int colunas);
char** escreve_tile_4_1(char **map,int linhas,int colunas);
char** escreve_tile_4_2(char **map,int linhas,int colunas);
char** escreve_tile_4_3(char **map,int linhas,int colunas);
char** escreve_tile_4_4(char **map,int linhas,int colunas);
char** escreve_tile_4_5(char **map,int linhas,int colunas);
char** escreve_tile_4_6(char **map,int linhas,int colunas);
char** escreve_tile_4_7(char **map,int linhas,int colunas);
char** escreve_tile_4_8(char **map,int linhas,int colunas);
char** escreve_tile_4_9(char **map,int linhas,int colunas);
char** escreve_tile_5_1(char **map,int linhas,int colunas);
char** escreve_tile_5_2(char **map,int linhas,int colunas);
char** escreve_tile_5_3(char **map,int linhas,int colunas);
char** escreve_tile_5_4(char **map,int linhas,int colunas);
char** escreve_tile_5_5(char **map,int linhas,int colunas);
char** escreve_tile_5_6(char **map,int linhas,int colunas);
char** escreve_tile_5_7(char **map,int linhas,int colunas);
char** escreve_tile_5_8(char **map,int linhas,int colunas);
char** escreve_tile_5_9(char **map,int linhas,int colunas);
char** escreve_tile_6_1(char **map,int linhas,int colunas);
char** escreve_tile_6_2(char **map,int linhas,int colunas);
char** escreve_tile_6_3(char **map,int linhas,int colunas);
char** escreve_tile_6_4(char **map,int linhas,int colunas);
char** escreve_tile_7_1(char **map,int linhas,int colunas);
char** escreve_tile_7_2(char **map,int linhas,int colunas);
char** escreve_tile_7_3(char **map,int linhas,int colunas);
char** escreve_tile_7_4(char **map,int linhas,int colunas);
char** escreve_tile_8_1(char **map,int linhas,int colunas);
char** escreve_tile_8_2(char **map,int linhas,int colunas);
char** escreve_tile_8_3(char **map,int linhas,int colunas);
char** escreve_tile_8_4(char **map,int linhas,int colunas);
char** escreve_tile_8_5(char **map,int linhas,int colunas);
char** escreve_tile_8_6(char **map,int linhas,int colunas);
char** escreve_tile_8_7(char **map,int linhas,int colunas);
char** escreve_tile_8_7(char **map,int linhas,int colunas);
char** escreve_tile_8_8(char **map,int linhas,int colunas);
char** escreve_tile_8_9(char **map,int linhas,int colunas);
char** escreve_tile_8_10(char **map,int linhas,int colunas);
char** escreve_tile_9_1(char **map,int linhas,int colunas);
char** escreve_tile_9_2(char **map,int linhas,int colunas);
char** escreve_tile_9_3(char **map,int linhas,int colunas);
char** escreve_tile_9_4(char **map,int linhas,int colunas);
char** escreve_tile_9_5(char **map,int linhas,int colunas);
char** escreve_tile_9_7(char **map,int linhas,int colunas);
char** escreve_tile_9_8(char **map,int linhas,int colunas);
char** escreve_tile_9_9(char **map,int linhas,int colunas);
char** escreve_tile_9_10(char **map,int linhas,int colunas);
char** escreve_tile_10_1(char **map,int linhas,int colunas);
char** escreve_tile_10_2(char **map,int linhas,int colunas);
char** escreve_tile_10_3(char **map,int linhas,int colunas);
char** escreve_tile_10_4(char **map,int linhas,int colunas);
char** escreve_tile_10_5(char **map,int linhas,int colunas);
char** escreve_tile_10_6(char **map,int linhas,int colunas);
char** escreve_tile_10_7(char **map,int linhas,int colunas);
char** escreve_tile_10_8(char **map,int linhas,int colunas);
char** escreve_tile_10_9(char **map,int linhas,int colunas);
char** escreve_tile_10_10(char **map,int linhas,int colunas);
char** escreve_tile_11_7(char **map,int linhas,int colunas);
char** escreve_tile_11_8(char **map,int linhas,int colunas);
char** escreve_tile_11_9(char **map,int linhas,int colunas);
char** escreve_tile_11_10(char **map,int linhas,int colunas);
char** escreve_tile_12_1(char **map,int linhas,int colunas);
char** escreve_tile_12_2(char **map,int linhas,int colunas);
char** escreve_tile_13_1(char **map,int linhas,int colunas);
char** escreve_tile_13_1(char **map,int linhas,int colunas);
char** escreve_tile_14_1(char **map,int linhas,int colunas);
char** escreve_tile_14_2(char **map,int linhas,int colunas);
char** escreve_tile_14_3(char **map,int linhas,int colunas);
char** escreve_tile_14_4(char **map,int linhas,int colunas);
char** escreve_tile_14_5(char **map,int linhas,int colunas);
char** escreve_tile_14_7(char **map,int linhas,int colunas);
char** escreve_tile_14_8(char **map,int linhas,int colunas);
char** escreve_tile_14_9(char **map,int linhas,int colunas);
char** escreve_tile_14_10(char **map,int linhas,int colunas);
char** escreve_tile_15_1(char **map,int linhas,int colunas);
char** escreve_tile_15_2(char **map,int linhas,int colunas);
char** escreve_tile_15_3(char **map,int linhas,int colunas);
char** escreve_tile_15_4(char **map,int linhas,int colunas);
char** escreve_tile_15_5(char **map,int linhas,int colunas);
char** escreve_tile_15_6(char **map,int linhas,int colunas);
char** escreve_tile_15_7(char **map,int linhas,int colunas);
char** escreve_tile_15_8(char **map,int linhas,int colunas);
char** escreve_tile_15_9(char **map,int linhas,int colunas);
char** escreve_tile_15_10(char **map,int linhas,int colunas);
char** escreve_tile_16_1(char **map,int linhas,int colunas);
char** escreve_tile_16_2(char **map,int linhas,int colunas);
char** escreve_tile_16_3(char **map,int linhas,int colunas);
char** escreve_tile_23_3(char **map,int linhas,int colunas);
char** escreve_tile_27_1(char **map,int linhas,int colunas);
char** escreve_tile_27_5(char **map,int linhas,int colunas);

int main()
{
    char **map;
    int mapsize,*colunas,*linhas,*xcorte,*ycorte,*tilex,*tiley;
    int i,j;
    FILE* mapa = fopen("map.txt","r");

    /* Allocando memoria dinamicamente pro map (permite um maior tamanho) */
    map = (char**)calloc(TAM,sizeof(char*));
    for(i=0;i<TAM;++i)
    	map[i] = (char*)calloc(TAM,sizeof(char));
    for(i=0;i<TAM;++i)
    {
        for(j=0;j<TAM;j++)
            map[i][j] = '0';
        map[i][0] = 'F';
    }

    /* Lendo a quantidade de tiles pra alocar dinamicamente e economizar memoria */
    fscanf(mapa,"%i\n",&mapsize);
    colunas = (int*)calloc(mapsize,sizeof(int));
    linhas = (int*)calloc(mapsize,sizeof(int));
    xcorte = (int*)calloc(mapsize,sizeof(int));
    ycorte = (int*)calloc(mapsize,sizeof(int));
    tilex = (int*)calloc(mapsize,sizeof(int));
    tiley = (int*)calloc(mapsize,sizeof(int));

    /* Leitura do map.txt e atualizando a matriz map, para poder salva-la no arquivo matriz.txt */
    for(i=0;i<mapsize;++i)
    {
    	fscanf(mapa,"%i %i %i %i\n",&colunas[i],&linhas[i],&xcorte[i],&ycorte[i]);
    	
    	tiley[i] = ycorte[i] / 32; // Tiley vai indicar a linha da imagem, começando no 0 (linha bugada). 0, 2a e 4a linhas nao existem.
    	tilex[i] = xcorte[i] / 64; // Começa a contagem a partir do 0 (coluna jah existente).
    	//colunas[i] -= 16/4;
    	//linhas[i] -= 32/4;
    	if (tiley[i] == 2 || tiley[i] == 4)
    	    tiley[i] = 0;
    	
    	/* Caso tenha usado um quadrado rosa da imagem dos tiles. */
        if( (tiley[i]==1 && tilex[i]>6)  ||  (tiley[i]==3 && tilex[i]>7) || (tilex[i]>3 && (tiley[i]==5 || tiley[i]==8 || tiley[i]==9) )  
            || ( (tiley[i]==6 || tiley[i]==7) && tilex[i]>8) || ( (tiley[i]==20 || tiley[i]==21) && tilex[i]>2) || 
			( (ycorte[i]==26 || tiley[i]==27) && (tilex[i]<2 || tilex[i] > 3)) )
			tiley[i] = 0;
            
        /* Tiles 9x5, 9x6, 11x1, 11x2, 11x3, 11x4, 11x5, 11x6, 13x2, 13x3, 13x4, 13x5, 13x6, 13x7, 13x8, 13x9, 13x10 sao todos iguais. */
        if((tiley[i] == 11 && tilex[i] == 6) || (tiley[i]==13 && (tilex[i]==1 || tilex[i]==2 || tilex[i]==3 || tilex[i]==4
		 || tilex[i]==5 || tilex[i]==0) ) || (tiley[i]==15 && tilex[i]!=0) )
		{
			tiley[i] = 11;
			tilex[i] = 4;
		} 
		
		/* Tiles 12x2, 12x3, ..., 12x10 sao todos iguais. */
		if((tiley[i] == 14) && (tilex[i]>1 && tilex[i]<11))
		    tilex[i] = 1;
		
        // OBS: Os tiles das funcoes escreve_tile NAO CONTAM as linhas fantasmas (0, 2 e 4). Tiley SIM! NAO CONFUNDIR!
        
    	if (tiley[i] == 3 || tiley[i] == 5)
    	    tiley[i] = 1; // Nessas 3 linhas, todos os tiles sao iguais em questao de colisao.
    	
    	printf("%d %d %d %d\n",tiley[i],tilex[i],linhas[i]/4,colunas[i]/4);
    	
    	switch(tiley[i])
    	{
    		case 0: break; // Caso seja alguma das linhas bugadas soh cai fora.
    		case 1:
    			map = escreve_tile_1_1(map,linhas[i]/4,colunas[i]/4);
    			break;
    		case 6: 
			    switch(tilex[i])
			    {
			    	case 0:
			    		map = escreve_tile_4_1(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 1:
			    		map = escreve_tile_4_2(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 2:
			    		map = escreve_tile_4_3(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 3:
			    		map = escreve_tile_4_4(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 4:
			    		map = escreve_tile_4_5(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 5:
			    		map = escreve_tile_4_6(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 6:
			    		map = escreve_tile_4_7(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 7:
			    		map = escreve_tile_4_8(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	case 8:
			    		map = escreve_tile_4_9(map,linhas[i]/4,colunas[i]/4);
			    		break;
			    	default: break;
			    }
			    break;
			case 7:
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_5_1(map,linhas[i]/4,colunas[i]/4);
						break;
					case 1:
						map = escreve_tile_5_2(map,linhas[i]/4,colunas[i]/4);
						break;
					case 2:
						map = escreve_tile_5_3(map,linhas[i]/4,colunas[i]/4);
						break;
					case 3:
						map = escreve_tile_5_4(map,linhas[i]/4,colunas[i]/4);
						break;
					case 4:
						map = escreve_tile_5_5(map,linhas[i]/4,colunas[i]/4);
						break;
					case 5:
						map = escreve_tile_5_6(map,linhas[i]/4,colunas[i]/4);
						break;
					case 6:
						map = escreve_tile_5_7(map,linhas[i]/4,colunas[i]/4);
						break;
					case 7:
						map = escreve_tile_5_8(map,linhas[i]/4,colunas[i]/4);
						break;
					case 8:
						map = escreve_tile_5_9(map,linhas[i]/4,colunas[i]/4);
						break;
					default: break;
				}
				break;
			case 8:
				break;
			case 10:
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_8_1(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 1:
						map = escreve_tile_8_2(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 2:
						map = escreve_tile_8_3(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 3:
						map = escreve_tile_8_4(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 4:
						map = escreve_tile_8_5(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 5:
						map = escreve_tile_8_6(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 6:
						map = escreve_tile_8_7(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 7:
						map = escreve_tile_8_8(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 8:
						map = escreve_tile_8_9(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 9:
						map = escreve_tile_8_10(map,linhas[i]/4,colunas[i]/4);
				        break;
					default: break;
				}
				break;
			case 11:
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_9_1(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 1:
						map = escreve_tile_9_2(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 2:
						map = escreve_tile_9_3(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 3:
						map = escreve_tile_9_4(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 4: 
					    map = escreve_tile_9_5(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 6:
						map = escreve_tile_9_7(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 7:
						map = escreve_tile_9_8(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 8:
						map = escreve_tile_9_9(map,linhas[i]/4,colunas[i]/4);
				        break;
				    case 9:
						map = escreve_tile_9_10(map,linhas[i]/4,colunas[i]/4);
				        break;
					default: break; 
			    }
			    break;
			case 12:
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_10_1(map,linhas[i]/4,colunas[i]/4);
						break;
					case 1:
						map = escreve_tile_10_2(map,linhas[i]/4,colunas[i]/4);
						break;
					case 2:
						map = escreve_tile_10_3(map,linhas[i]/4,colunas[i]/4);
						break;
					case 3:
						map = escreve_tile_10_4(map,linhas[i]/4,colunas[i]/4);
						break;
					case 4:
						map = escreve_tile_10_5(map,linhas[i]/4,colunas[i]/4);
						break;
					case 5:
						map = escreve_tile_10_6(map,linhas[i]/4,colunas[i]/4);
						break;
					case 6:
						map = escreve_tile_10_7(map,linhas[i]/4,colunas[i]/4);
						break;
					case 7:
						map = escreve_tile_10_8(map,linhas[i]/4,colunas[i]/4);
						break;
					case 8:
						map = escreve_tile_10_9(map,linhas[i]/4,colunas[i]/4);
						break;
					case 9:
						map = escreve_tile_10_10(map,linhas[i]/4,colunas[i]/4);
						break;
					default: break;
				}
				break;
			case 13:
				switch(tilex[i])
				{
					case 6:
						map = escreve_tile_11_7(map,linhas[i]/4,colunas[i]/4);
						break;
					case 7:
						map = escreve_tile_11_8(map,linhas[i]/4,colunas[i]/4);
						break;
					case 8:
						map = escreve_tile_11_9(map,linhas[i]/4,colunas[i]/4);
						break;
					case 9:
						map = escreve_tile_11_10(map,linhas[i]/4,colunas[i]/4);
						break;
					default: break;
				}
				break;
	        case 14:
                 switch(tilex[i])
                 {
                 	case 0:
                        map = escreve_tile_12_1(map,linhas[i]/4,colunas[i]/4);
                        break;
                    case 1:
                        map = escreve_tile_12_2(map,linhas[i]/4,colunas[i]/4);
                        break;
                    default: break;
                 }
                 break; 
			case 15:
			     switch(tilex[i])
				 {
				 	case 0:
				 		map = escreve_tile_13_1(map,linhas[i]/4,colunas[i]/4);
				 		break;
				 	default: break;
				 }    
				 break;   
			case 17: // Pulou case 16 por causa da linha rosa do tiles.
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_14_1(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 1:
						map = escreve_tile_14_2(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 2:
						map = escreve_tile_14_3(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 3:
						map = escreve_tile_14_4(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 4:
						map = escreve_tile_14_5(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 5:
						map = escreve_tile_14_5(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 6:
						map = escreve_tile_14_7(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 7:
						map = escreve_tile_14_8(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 8:
						map = escreve_tile_14_9(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 9:
						map = escreve_tile_14_10(map,linhas[i]/4,colunas[i]/4);
					    break;
					default: break;
				}
			    break;
			case 19:
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_15_1(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 1:
						map = escreve_tile_15_2(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 2:
						map = escreve_tile_15_3(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 3:
						map = escreve_tile_15_4(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 4:
						map = escreve_tile_15_5(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 5:
						map = escreve_tile_15_6(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 6:
						map = escreve_tile_15_7(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 7:
						map = escreve_tile_15_8(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 8:
						map = escreve_tile_15_9(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 9:
						map = escreve_tile_15_10(map,linhas[i]/4,colunas[i]/4);
					    break;
					default: break;
				}
			    break;
			case 21:
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_16_1(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 1:
						map = escreve_tile_16_2(map,linhas[i]/4,colunas[i]/4);
					    break;
					case 2:
						map = escreve_tile_16_3(map,linhas[i]/4,colunas[i]/4);
					    break;
					default: break;
				}
			    break;
			case 27:
				switch(tilex[i])
				{
					case 2:
						map = escreve_tile_23_3(map,linhas[i]/4,colunas[i]/4);
						break;
					case 3:
						map = escreve_tile_23_3(map,linhas[i]/4,colunas[i]/4);
						break;
					default: break;
				}
				break;
			case 31:
				switch(tilex[i])
				{
					case 0:
						map = escreve_tile_27_1(map,linhas[i]/4,colunas[i]/4);
						break;
					case 1:
						map = escreve_tile_27_1(map,linhas[i]/4,colunas[i]/4);
						break;
					case 2:
						map = escreve_tile_23_3(map,linhas[i]/4,colunas[i]/4); // O tile de 27x3 e 27x4 eh igual ao tile do 23x3.
						break;
					case 3:
						map = escreve_tile_23_3(map,linhas[i]/4,colunas[i]/4);
						break;
					case 5:
						map = escreve_tile_27_5(map,linhas[i]/4,colunas[i]/4);
						break;
					case 8:
						map = escreve_tile_27_5(map,linhas[i]/4,colunas[i]/4);
						break;
					default: break;
				}
				break;
			    
    		default: break;
    	}
    }
    
    map = escreve_arquivo(map);
    
    return 1;
}
    


char** escreve_tile_1_1(char **map,int linhas,int colunas)
/* Fazer o formato de um chao normal. Obs: 0 = Nao existe, 1 = Passa,
2 = Passa lento (subida/descida), 3 = Nao passa 
*/
{
	int i;
	for(i=0;i<4;++i)
    {
    	map[linhas][colunas+6+i] = '1';
    	map[linhas+7][colunas+6+i] = '1';
    }
    for(i=0;i<8;++i)
    {
    	map[linhas+1][colunas+4+i] = '1';
    	map[linhas+6][colunas+4+i] = '1';
    }
    for(i=0;i<12;++i)
    {
    	map[linhas+2][colunas+2+i] = '1';
    	map[linhas+5][colunas+2+i] = '1';
    }
    for(i=0;i<16;++i)
    {
    	map[linhas+3][colunas+i] = '1';
    	map[linhas+4][colunas+i] = '1';
    }
    return map;
}

char** escreve_tile_4_1(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<2;++i)
    	map[linhas][colunas+7+i] = '1';
    for(i=0;i<4;++i)
    	map[linhas+1][colunas+6+i] = '1';
    for(i=0;i<6;++i)
    {
    	map[linhas+2][colunas+5+i] = '1';
    	map[linhas+3][colunas+5+i] = '1';
    }
    for(i=0;i<8;++i)
    	map[linhas+4][colunas+4+i] = '1';
    for(i=0;i<10;++i)
    {
    	map[linhas+5][colunas+3+i] = '1';
    	map[linhas+6][colunas+3+i] = '1';
    }
    for(i=0;i<12;++i)
    	map[linhas+7][colunas+2+i] = '1';
    return map;
}

char** escreve_tile_4_2(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<3;++i)
    {
    	map[linhas][colunas+7+i] = '2';
    }
    for(i=0;i<4;++i)
    {
    	map[linhas+1][colunas+7+i] = '2';
    }
    for(i=0;i<8;++i)
    {
    	map[linhas+2][colunas+6+i] = '2';
    }
    for(i=0;i<12;++i)
    {
    	map[linhas+3][colunas+4+i] = '2';
    	map[linhas+4][colunas+4+i] = '2';
    }
    for(i=0;i<12;++i)
    {
    	map[linhas+5][colunas+3+i] = '2';
    }
    map[linhas+5][colunas+15] = '3';
    for(i=0;i<12;++i)
    {
    	map[linhas+6][colunas+2+i] = '2';
    }
    map[linhas+6][colunas+14] = '3';
    map[linhas+6][colunas+15] = '3';
    for(i=0;i<11;++i)
    {
    	map[linhas+7][colunas+2+i] = '2';
    }
    map[linhas+7][colunas+13] = '3';
    map[linhas+7][colunas+14] = '3';
    map[linhas+7][colunas+15] = '3';

    return map;
}

char** escreve_tile_4_3(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<3;++i)
    	map[linhas][colunas+6+i] = '2';
    for(i=0;i<5;++i)
    	map[linhas+1][colunas+5+i] = '2';
    for(i=0;i<8;++i)
    	map[linhas+2][colunas+3+i] = '2';
    for(i=0;i<11;++i)
    	map[linhas+3][colunas+1+i] = '2';
    for(i=0;i<12;++i)
    	map[linhas+4][colunas+i] = '2';
   	for(i=0;i<2;++i)
   	{
   	    map[linhas+5][colunas+i] = '3';
   	    map[linhas+6][colunas+i] = '3';
    }
    for(i=0;i<11;++i)
    {
        map[linhas+5][colunas+2+i] = '2';
        map[linhas+6][colunas+2+i] = '2';
    }
    for(i=0;i<3;++i)
        map[linhas+7][colunas+i] = '3';
    for(i=0;i<11;++i)
        map[linhas+7][colunas+3+i] = '2';
        
    /* Essas proximas atribuiçoes fazem a "linha" de colisao pra nao atravessar a parte da direita do tile. */
   	map[linhas][colunas+8] = '3';
   	map[linhas+1][colunas+9] = '3';
   	map[linhas+2][colunas+10] = '3';
   	map[linhas+3][colunas+11] = '3';
   	map[linhas+4][colunas+11] = '3';
   	map[linhas+5][colunas+12] = '3';
   	map[linhas+6][colunas+12] = '3';
   	map[linhas+7][colunas+13] = '3';
   	
    return map;
}

char** escreve_tile_4_4(char **map,int linhas,int colunas)
{
       int i;
       for(i=0;i<4;++i)
           map[linhas+4][colunas+12+i] = '2';
       for(i=0;i<5;++i)
           map[linhas+5][colunas+10+i] = '2';
       map[linhas+5][colunas+15] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+9+i] = '2';
       for(i=0;i<2;++i)
           map[linhas+6][colunas+14+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+7][colunas+8+i] = '2';
       for(i=0;i<3;++i)
           map[linhas+7][colunas+13+i] = '3';
       
       return map;
}    

char** escreve_tile_4_5(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '4';
       for(i=0;i<6;++i)
           map[linhas+1][colunas+5+i] = '4';
       for(i=0;i<10;++i)
           map[linhas+2][colunas+3+i] = '4';
       for(i=0;i<14;++i)
           map[linhas+3][colunas+1+i] = '4';
       for(i=0;i<16;++i)
           map[linhas+4][colunas+i] = '4';
       for(i=0;i<3;++i)
       {
           map[linhas+5][colunas+i] = '3';
           map[linhas+5][colunas+13+i] = '3';
       }
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '4';
       for(i=0;i<5;++i)
       {
           map[linhas+6][colunas+i] = '3';
           map[linhas+6][colunas+11+i] = '3';
       }
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '4';
       for(i=0;i<7;++i)
       {
           map[linhas+7][colunas+i] = '3';
           map[linhas+7][colunas+10+i] = '3';
       }
       for(i=0;i<3;++i)
           map[linhas+7][colunas+7+i] = '4';
                  
       return map;
}    

char** escreve_tile_4_6(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
           map[linhas+4][colunas+i] = '2';
       for(i=0;i<2;++i)
           map[linhas+5][colunas+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+5][colunas+2+i] = '2';
       for(i=0;i<3;++i)
           map[linhas+6][colunas+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+6][colunas+3+i] = '2';
       for(i=0;i<4;++i)
       {
           map[linhas+7][colunas+i] = '3';
           map[linhas+7][colunas+4+i] = '2';
       }
       
       return map;
       
}    

char** escreve_tile_4_7(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<3;++i)
           map[linhas+4][colunas+12+i] = '2';
       map[linhas+4][colunas+15] = '3';
       for(i=0;i<4;++i)
           map[linhas+5][colunas+9+i] = '2';
       for(i=0;i<3;++i)
           map[linhas+5][colunas+13+i] = '3';
       for(i=0;i<5;++i)
       {
           map[linhas+6][colunas+6+i] = '2';
           map[linhas+6][colunas+11+i] = '3';
       }
       for(i=0;i<5;++i)
           map[linhas+7][colunas+4+i] = '2';
       for(i=0;i<6;++i)
           map[linhas+7][colunas+9+i] = '3';
       
       return map;
}    

char** escreve_tile_4_8(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
            map[linhas+4][colunas+i] = '2';
       for(i=0;i<2;++i)
            map[linhas+5][colunas+i] = '3';
       for(i=0;i<5;++i)
            map[linhas+5][colunas+2+i] = '2';
       for(i=0;i<4;++i)
            map[linhas+6][colunas+i] = '3';
       for(i=0;i<5;++i)
            map[linhas+6][colunas+4+i] = '2';
       for(i=0;i<6;++i)
            map[linhas+7][colunas+i] = '3';
       for(i=0;i<5;++i)
            map[linhas+7][colunas+6+i] = '2';
       
       return map;
}    

char** escreve_tile_4_9(char **map,int linhas,int colunas)
{      // Nao tem nada nesse tile.
       return map;
}    

char** escreve_tile_5_1(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<14;++i)
    {
    	map[linhas][colunas+1+i] = '1';
    	map[linhas+1][colunas+1+i] = '1';
    	map[linhas+4][colunas+1+i] = '1';
    }
    for(i=0;i<16;++i)
    {
    	map[linhas+2][colunas+i] = '1';
    	map[linhas+3][colunas+i] = '1';
    }
    for(i=0;i<10;++i)
    	map[linhas+5][colunas+3+i] = '1';
    for(i=0;i<6;++i)
    	map[linhas+6][colunas+5+i] = '1';
    for(i=0;i<2;++i)
    	map[linhas+7][colunas+7+i] = '1';

    return map;
}

char** escreve_tile_5_2(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<11;++i)
	{
	    map[linhas][colunas+1+i] = '2';
	    map[linhas+1][colunas+1+i] = '2';
	}
    for(i=0;i<4;++i)
    {
        map[linhas][colunas+i+11] = '3';
        map[linhas+1][colunas+i+11] = '3';
    }
    
    for(i=0;i<10;++i)
    {
    	map[linhas+2][colunas+1+i] = '2';
    }
    for(i=0;i<5;++i)
    {
    	map[linhas+2][colunas+10+i] = '3';
    }
    
    for(i=0;i<10;++i)
    	map[linhas+3][colunas+i] = '2';
    for(i=0;i<6;++i)
    	map[linhas+3][colunas+9+i] = '3';
    	
    for(i=0;i<9;++i)
        map[linhas+4][colunas+1+i] = '2';
    for(i=0;i<6;++i)
        map[linhas+4][colunas+9+i] = '3';
        
    for(i=0;i<6;++i)
        map[linhas+5][colunas+3+i] = '2';
    for(i=0;i<5;++i)
        map[linhas+5][colunas+9+i] = '3';
    
    for(i=0;i<5;++i)
        map[linhas+6][colunas+4+i] = '2';
    for(i=0;i<3;++i)
        map[linhas+6][colunas+9+i] = '3';
        
    for(i=0;i<3;++i)
        map[linhas+7][colunas+6+i] = '2';
        
    return map;
}

char** escreve_tile_5_3(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<4;++i)
    	map[linhas][colunas+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas][colunas+4+i] = '2';
    for(i=0;i<5;++i)
    {
    	map[linhas+1][colunas+i] = '3';
    	map[linhas+2][colunas+i] = '3';
    }
    for(i=0;i<10;++i)
    {
    	map[linhas+1][colunas+5+i] = '2';
    	map[linhas+2][colunas+5+i] = '2';
    }
    map[linhas+2][colunas+15] = '2';
    for(i=0;i<6;++i)
    {
    	map[linhas+3][colunas+i] = '3';
        map[linhas+4][colunas+i] = '3';
    }
    for(i=0;i<10;++i)
    {
    	map[linhas+3][colunas+6+i] = '2';
        map[linhas+4][colunas+6+i] = '2';
    }
    for(i=0;i<4;++i)
    	map[linhas+5][colunas+2+i] = '3';
   	for(i=0;i<8;++i)
   	    map[linhas+5][colunas+7+i] = '2';
    for(i=0;i<2;++i)
        map[linhas+6][colunas+5+i] = '3';
    for(i=0;i<5;++i)
        map[linhas+6][colunas+7+i] = '2';
    for(i=0;i<3;++i)
        map[linhas+7][colunas+8+i] = '2';

    /* Arrumar a linha diagonal de colisao. */
	map[linhas][colunas+13] = '3';
    map[linhas+1][colunas+14] = '3';
    map[linhas+2][colunas+15] = '3';

    return map;
}

char** escreve_tile_5_4(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<5;++i)
           map[linhas][colunas+7+i] = '2';
       for(i=0;i<4;++i)
           map[linhas][colunas+12+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+1][colunas+5+i] = '2';
       for(i=0;i<5;++i)
           map[linhas+1][colunas+11+i] = '3';
       for(i=0;i<7;++i)
           map[linhas+2][colunas+3+i] = '2';
       for(i=0;i<6;++i)
           map[linhas+2][colunas+10+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+3][colunas+1+i] = '2';
       for(i=0;i<6;++i)
           map[linhas+3][colunas+10+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+4][colunas+i] = '2';
       for(i=0;i<6;++i)
           map[linhas+4][colunas+10+i] = '3';
       for(i=0;i<7;++i)
           map[linhas+5][colunas+2+i] = '2';
       for(i=0;i<5;++i)
           map[linhas+5][colunas+9+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+4+i] = '2';
       for(i=0;i<3;++i)
           map[linhas+6][colunas+9+i] = '3';
       for(i=0;i<2;++i)
       {
           map[linhas+7][colunas+6+i] = '2';
           map[linhas+7][colunas+8+i] = '3';
       }
       
       return map;
}    

char** escreve_tile_5_5(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<15;++i)
       {
           map[linhas][colunas+i] = '3';
           map[linhas+1][colunas+i] = '3';
       }
       for(i=0;i<16;++i)
       {
           map[linhas+2][colunas+i] = '3';
           map[linhas+3][colunas+i] = '3';
           map[linhas+4][colunas+i] = '3';
       }
       for(i=0;i<12;++i)
           map[linhas+5][colunas+2+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+6][colunas+4+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+7][colunas+6+i] = '3';
       
       return map;
}    

char** escreve_tile_5_6(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
           map[linhas][colunas+i] = '3';
       for(i=0;i<5;++i)
       {
           map[linhas][colunas+4+i] = '2';
           map[linhas+1][colunas+i] = '3';
           map[linhas+2][colunas+i] = '3';
       }
       for(i=0;i<6;++i)
           map[linhas+1][colunas+5+i] = '2';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+5+i] = '2';
       for(i=0;i<6;++i)
       {
           map[linhas+3][colunas+i] = '3';
           map[linhas+4][colunas+i] = '3';
       }
       for(i=0;i<10;++i)
       {
           map[linhas+3][colunas+6+i] = '2';
           map[linhas+4][colunas+6+i] = '2';
       }
       for(i=0;i<4;++i)
           map[linhas+5][colunas+2+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+5][colunas+6+i] = '2';
       for(i=0;i<3;++i)
           map[linhas+6][colunas+4+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+7+i] = '2';
       map[linhas+7][colunas+6] = '3';
       for(i=0;i<3;++i)
           map[linhas+7][colunas+7+i] = '2';
       
       return map;
}    

char** escreve_tile_5_7(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<3;++i)
           map[linhas][colunas+3+i] = '2';
       for(i=0;i<9;++i)
           map[linhas][colunas+6+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+1][colunas+2+i] = '2';
       for(i=0;i<10;++i)
           map[linhas+1][colunas+4+i] = '3';
       map[linhas+2][colunas+1] = '2';
       for(i=0;i<14;++i)
           map[linhas+2][colunas+2+i] = '3';
       map[linhas+3][colunas] = '2';
       for(i=0;i<15;++i)
           map[linhas+3][colunas+1+i] = '3';
       for(i=0;i<15;++i)
           map[linhas+4][colunas+1+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+5][colunas+2+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+6][colunas+4+i] = '3';
       for(i=0;i<3;++i)
	       map[linhas+7][colunas+6+i] = '3'; 
       
       return map;
}    

char** escreve_tile_5_8(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<10;++i)
           map[linhas][colunas+i] = '3';
       for(i=0;i<3;++i)
	       map[linhas][colunas+10+i] = '2';
	   for(i=0;i<12;++i)
	       map[linhas+1][colunas+i] = '3';
	   for(i=0;i<2;++i)
	       map[linhas+1][colunas+12+i] = '2';
	   for(i=0;i<13;++i)
	       map[linhas+2][colunas+i] = '3';
	   for(i=0;i<2;++i)
	       map[linhas+2][colunas+13+i] = '2';
	   for(i=0;i<14;++i)
	       map[linhas+3][colunas+i] = '3';
	   for(i=0;i<2;++i)
	       map[linhas+3][colunas+14+i] = '2';
	   for(i=0;i<16;++i)
	       map[linhas+4][colunas+i] = '3';
	   for(i=0;i<12;++i)
	       map[linhas+5][colunas+2+i] = '3';
	   for(i=0;i<8;++i)
	       map[linhas+6][colunas+4+i] = '3';
	   for(i=0;i<4;++i)
	       map[linhas+7][colunas+6+i] = '3';             
       
       return map;
}    

char** escreve_tile_5_9(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<3;++i)
           map[linhas][colunas+5+i] = '3';
       for(i=0;i<2;++i)
           map[linhas][colunas+8+i] = '2';
       for(i=0;i<9;++i)
           map[linhas+1][colunas+3+i] = '3';
       map[linhas+1][colunas+12] = '2';
       for(i=0;i<13;++i)
           map[linhas+2][colunas+1+i] = '3';
       map[linhas+2][colunas+14] = '2';
       for(i=0;i<15;++i)
           map[linhas+3][colunas+i] = '3';
       map[linhas+3][colunas+15] = '2';
       for(i=0;i<16;++i)
           map[linhas+4][colunas+i] = '3';
	   for(i=0;i<12;++i)
	       map[linhas+5][colunas+2+i] = '3';
	   for(i=0;i<8;++i)
	       map[linhas+6][colunas+4+i] = '3';
	   for(i=0;i<4;++i)
	       map[linhas+7][colunas+6+i] = '3';    
       
       return map;
}    

char** escreve_tile_6_1(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
       {
       	   map[linhas+4][colunas+i] = '2';
       	   map[linhas+4][colunas+12+i] = '2';
       }
       for(i=0;i<3;++i)
       {
       	   map[linhas+5][colunas+i] = '3';
       	   map[linhas+5][colunas+13+i] = '3';
       }
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '2';
       for(i=0;i<5;++i)
       {
       	   map[linhas+6][colunas+i] = '3';
       	   map[linhas+6][colunas+11+i] = '3';
       }
       for(i=0;i<6;++i)
       {
       	   map[linhas+6][colunas+5+i] = '2';
       }
       for(i=0;i<7;++i)
           map[linhas+7][colunas+i] = '3';
       for(i=0;i<2;++i)
	       map[linhas+7][colunas+7+i] = '2';
	   for(i=0;i<6;++i)
	       map[linhas+7][colunas+9+i] = '3'; 
       
       return map;
}    

char** escreve_tile_6_2(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<3;++i)
           map[linhas][colunas+6+i] = '2';
       for(i=0;i<6;++i)
	       map[linhas+1][colunas+4+i] = '2';
	   for(i=0;i<9;++i)
	       map[linhas+2][colunas+2+i] = '2';
	   for(i=0;i<12;++i)
	   {
	   	   map[linhas+3][colunas+i] = '2';
	   	   map[linhas+4][colunas+i] = '2';
	   }
	   for(i=0;i<3;++i)
	       map[linhas+5][colunas+i] = '3';
	   for(i=0;i<10;++i)
	       map[linhas+5][colunas+3+i] = '2';
	   for(i=0;i<5;++i)
	       map[linhas+6][colunas+i] = '3';
	   for(i=0;i<9;++i)
	       map[linhas+6][colunas+5+i] = '2';
	   for(i=0;i<7;++i)
	   {
	   	   map[linhas+7][colunas+i] = '3';
	   	   map[linhas+7][colunas+7+i] = '2';
	   } 
       
       return map;
}    

char** escreve_tile_6_3(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
           map[linhas][colunas+6+i] = '2';
       for(i=0;i<7;++i)
           map[linhas+1][colunas+4+i] = '2';
       for(i=0;i<11;++i)
	       map[linhas+2][colunas+3+i] = '2';
	   for(i=0;i<16;++i)
	   {
	   	   map[linhas+3][colunas+i] = '2';
	   	   map[linhas+4][colunas+i] = '2';
	   } 
	   map[linhas+5][colunas] = '3';
	   map[linhas+5][colunas+15] = '3';
	   for(i=0;i<14;++i)
	       map[linhas+5][colunas+1+i] = '2';
	   for(i=0;i<2;++i)
	   {
	   	   map[linhas+6][colunas+i] = '3';
	   	   map[linhas+6][colunas+14+i] = '3';
	   } 
	   for(i=0;i<12;++i)
	       map[linhas+6][colunas+2+i] = '2';
       for(i=0;i<3;++i)
       {
       	   map[linhas+7][colunas+i] = '3';
       	   map[linhas+7][colunas+13+i] = '3';
       } 
       for(i=0;i<10;++i)
           map[linhas+7][colunas+3+i] = '2';
       
       return map;
}    

char** escreve_tile_6_4(char **map,int linhas,int colunas)
{
       int i;

       for(i=0;i<3;++i)
           map[linhas][colunas+7+i] = '2';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+7+i] = '2';
       for(i=0;i<9;++i)
           map[linhas+2][colunas+5+i] = '2';
       for(i=0;i<11;++i)
           map[linhas+3][colunas+5+i] = '2';
       for(i=0;i<12;++i)
	       map[linhas+4][colunas+4+i] = '2';    
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '2';
       for(i=0;i<3;++i)
           map[linhas+5][colunas+13+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+6][colunas+2+i] = '2';
       for(i=0;i<4;++i)
           map[linhas+6][colunas+12+i] = '3';
       for(i=0;i<7;++i)
           map[linhas+7][colunas+2+i] = '2';
       for(i=0;i<6;++i)
           map[linhas+7][colunas+8+i] = '3';
       
       return map;
}    

char** escreve_tile_7_1(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<15;++i)
           map[linhas][colunas+i] = '3';
       for(i=0;i<16;++i)
	   {
	   	   map[linhas+1][colunas+i] = '3';
	   	   map[linhas+2][colunas+i] = '3';
	   	   map[linhas+3][colunas+i] = '3';
	   	   map[linhas+4][colunas+i] = '3';
	   } 
	   for(i=0;i<12;++i)
	       map[linhas+5][colunas+2+i] = '3';
	   for(i=0;i<8;++i) 
           map[linhas+6][colunas+4+i] = '3';
	   for(i=0;i<4;++i)
	       map[linhas+7][colunas+6+i] = '3';
		   
       return map;
}     

char** escreve_tile_7_2(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<10;++i)
           map[linhas][colunas+i] = '3';
       for(i=0;i<5;++i)
	       map[linhas][colunas+10+i] = '2';
	   for(i=0;i<13;++i)
	       map[linhas+1][colunas+i] = '3';
	   for(i=0;i<2;++i)
	       map[linhas+1][colunas+13+i] = '2';
	   for(i=0;i<14;++i)
	       map[linhas+2][colunas+i] = '3';
	   for(i=0;i<2;++i)
	       map[linhas+2][colunas+14+i] = '2';
	   for(i=0;i<15;++i)
	       map[linhas+3][colunas+i] = '3';
	   map[linhas+3][colunas+15] = '2';
	   for(i=0;i<16;++i)
	       map[linhas+4][colunas+i] = '3';	       
	   for(i=0;i<12;++i)
	       map[linhas+5][colunas+2+i] = '3';
	   for(i=0;i<8;++i) 
           map[linhas+6][colunas+4+i] = '3';
	   for(i=0;i<4;++i)
	       map[linhas+7][colunas+6+i] = '3';        
       
       return map;
}    

char** escreve_tile_7_3(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
       {
           map[linhas][colunas+i] = '3';
           map[linhas][colunas+12+i] = '3';
           map[linhas+1][colunas+i] = '3';
           map[linhas+1][colunas+12+i] = '3';
       }
       for(i=0;i<8;++i)
       {
       	   map[linhas][colunas+4+i] = '2';
       	   map[linhas+1][colunas+4+i] = '2';
       }
       for(i=0;i<5;++i)
       {
       	   map[linhas+2][colunas+i] = '3';
       	   map[linhas+3][colunas+i] = '3';
       	   map[linhas+2][colunas+11+i] = '3';
       	   map[linhas+3][colunas+11+i] = '3';
       }
       for(i=0;i<6;++i)
       {
       	   map[linhas+2][colunas+5+i] = '2';
       	   map[linhas+3][colunas+5+i] = '2';
       }
       for(i=0;i<6;++i)
       {
       	   map[linhas+4][colunas+i] = '3';
       	   map[linhas+4][colunas+10+i] = '3';
       }
       for(i=0;i<3;++i)
       {
       	   map[linhas+5][colunas+2+i] = '3';
       	   map[linhas+5][colunas+5+i] = '2';
       }
       for(i=0;i<6;++i)
           map[linhas+5][colunas+8+i] = '3';
       for(i=0;i<3;++i)
	   {
	   	   map[linhas+6][colunas+4+i] = '3';
	   	   map[linhas+6][colunas+6+i] = '3';
	   }    
       for(i=0;i<2;++i)
           map[linhas+7][colunas+7+i] = '2';
       for(i=0;i<4;++i)
	       map[linhas+7][colunas+6+i] = '2'; 
       
       return map;
}

char** escreve_tile_7_4(char **map,int linhas,int colunas)
{
       int i;
 
       for(i=0;i<5;++i)
           map[linhas][colunas+1+i] = '2';
       for(i=0;i<9;++i)
           map[linhas][colunas+6+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+1+i] = '2';
       for(i=0;i<11;++i)
           map[linhas+1][colunas+5+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+2][colunas+i] = '2';
       for(i=0;i<12;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+3][colunas+i] = '2';
       for(i=0;i<14;++i)
           map[linhas+3][colunas+2+i] = '3';
       for(i=0;i<16;++i)
           map[linhas+4][colunas+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+5][colunas+2+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+6][colunas+4+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+7][colunas+6+i] = '3';
       
       return map;
}

char** escreve_tile_8_1(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<5;++i)
	{
		map[linhas+3][colunas+4+i] = '3';
		map[linhas+4][colunas+4+i] = '3';
		map[linhas+5][colunas+4+i] = '3';
	}
	for(i=0;i<8;++i)
	    map[linhas+6][colunas+4+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+7][colunas+3+i] = '3';
	
	return map;
}

char** escreve_tile_8_2(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<2;++i)
	    map[linhas+2][colunas+7+i] = '3';
	for(i=0;i<4;++i)
	    map[linhas+3][colunas+7+i] = '3';
	for(i=0;i<5;++i)
	    map[linhas+4][colunas+6+i] = '3';
	for(i=0;i<7;++i)
	    map[linhas+5][colunas+5+i] = '3';
	for(i=0;i<8;++i)
	    map[linhas+6][colunas+5+i] = '3';
	for(i=0;i<9;++i)
	    map[linhas+7][colunas+4+i] = '3';
	return map;
}

char** escreve_tile_8_3(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<4;++i)
	    map[linhas+2][colunas+5+i] = '3';
	for(i=0;i<7;++i)
	    map[linhas+3][colunas+2+i] = '3';
	for(i=0;i<8;++i)
	    map[linhas+4][colunas+1+i] = '3';
	for(i=0;i<9;++i)
	{
		map[linhas+5][colunas+1+i] = '3';
		map[linhas+6][colunas+1+i] = '3';
	}
	for(i=0;i<10;++i)
	    map[linhas+7][colunas+1+i] = '3';
	return map;
}

char** escreve_tile_8_4(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<4;++i)
	{
		map[linhas+4][colunas+12+i] = '3';
		map[linhas+5][colunas+12+i] = '3';
	}
	for(i=0;i<10;++i)
	    map[linhas+6][colunas+6+i] = '3';
	for(i=0;i<9;++i)
	    map[linhas+7][colunas+7+i] = '3';
	return map;
}

char** escreve_tile_8_5(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<2;++i)
	    map[linhas][colunas+7+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+1][colunas+5+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+2][colunas+5+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	{
		map[linhas+4][colunas+i] = '3';
		map[linhas+5][colunas+i] = '3';
		map[linhas+6][colunas+i] = '3';
		map[linhas+7][colunas+i] = '3';
	}

	return map;
}

char** escreve_tile_8_6(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<4;++i)
	    map[linhas][colunas+7+i] = '3';
	for(i=0;i<5;++i)
	    map[linhas+1][colunas+6+i] = '3';
	for(i=0;i<11;++i)
	    map[linhas+2][colunas+3+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	{
		map[linhas+4][colunas+i] = '3';
		map[linhas+5][colunas+i] = '3';
		map[linhas+6][colunas+i] = '3';
		map[linhas+7][colunas+i] = '3';
	}
    return map;
}

char** escreve_tile_8_7(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<3;++i)
		map[linhas+4][colunas+1+i] = '3';
	for(i=0;i<6;++i)
	{
	    map[linhas+5][colunas+i] = '3';
	    map[linhas+6][colunas+i] = '3';
    }
    for(i=0;i<2;++i)
        map[linhas+6][colunas+8+i] = '3';
    for(i=0;i<10;++i)
        map[linhas+7][colunas+i] = '3';

	return map;
}

char** escreve_tile_8_8(char **map,int linhas,int colunas)
{
	int i;

	for(i=0;i<2;++i)
	    map[linhas+4][colunas+12+i] = '3';
	for(i=0;i<9;++i)    
	    map[linhas+5][colunas+7+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+6][colunas+6+i] = '3';
	for(i=0;i<13;++i)
	    map[linhas+7][colunas+3+i] = '3';
	
	return map;
}

char** escreve_tile_8_9(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<3;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<8;++i)
	    map[linhas+4][colunas+1+i] = '3';
	for(i=0;i<10;++i)
	{
	    map[linhas+5][colunas+i] = '3';
        map[linhas+6][colunas+i] = '3';
    }
	for(i=0;i<11;++i)
	    map[linhas+7][colunas+i] = '3';
	return map;
}

char** escreve_tile_8_10(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+8+i] = '3';
	return map;
}

char** escreve_tile_9_1(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<11;++i)
	    map[linhas][colunas+3+i] = '3';
	for(i=0;i<12;++i)
	    map[linhas+1][colunas+2+i] = '3';
	for(i=0;i<13;++i)
    {
    	map[linhas+2][colunas+1+i] = '3';
    	map[linhas+3][colunas+1+i] = '3';
    }
	for(i=0;i<9;++i)
	    map[linhas+4][colunas+3+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+5][colunas+4+i] = '3';
	for(i=0;i<3;++i)
	    map[linhas+6][colunas+7+i] = '3';
	return map;
}

char** escreve_tile_9_2(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<10;++i)
        map[linhas][colunas+4+i] = '3';
    for(i=0;i<12;++i)
        map[linhas+1][colunas+2+i] = '3';
    for(i=0;i<13;++i)
    {
    	map[linhas+2][colunas+1+i] = '3';
    	map[linhas+3][colunas+1+i] = '3';
    }
	for(i=0;i<11;++i)
	    map[linhas+4][colunas+2+i] = '3';
	for(i=0;i<3;++i)
	{
		map[linhas+5][colunas+3+i] = '3';
		map[linhas+5][colunas+8+i] = '3';
	}
	for(i=0;i<2;++i)
	    map[linhas+6][colunas+8+i] = '3';
	return map;
}

char** escreve_tile_9_3(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<13;++i)
	{
		map[linhas][colunas+i] = '3';
		map[linhas+1][colunas+i] = '3';
	}
	for(i=0;i<14;++i)
	{
		map[linhas+2][colunas+i] = '3';
		map[linhas+3][colunas+i] = '3';
	}
	for(i=0;i<11;++i)
	    map[linhas+4][colunas+1+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+5][colunas+5+i] = '3';
	map[linhas+6][colunas+8] = '3';
	return map;
}

char** escreve_tile_9_4(char **map,int linhas,int colunas)
{
	int i;	
	for(i=0;i<11;++i)
	    map[linhas][colunas+5+i] = '3';
	for(i=0;i<13;++i)
	{
		map[linhas+1][colunas+3+i] = '3';
		map[linhas+2][colunas+3+i] = '3';
		map[linhas+3][colunas+3+i] = '3';
	}
	for(i=0;i<11;++i)
	    map[linhas+4][colunas+4+i] = '3';
	for(i=0;i<8;++i)
	    map[linhas+5][colunas+5+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+6][colunas+8+i] = '3';
	return map;
}

char** escreve_tile_9_5(char **map,int linhas,int colunas)
{
       int i;
       printf("Yay");
       for(i=0;i<16;++i)
       {
       	   map[linhas][colunas+i] = '3';
       	   map[linhas+1][colunas+i] = '3';
       	   map[linhas+2][colunas+i] = '3';
       	   map[linhas+3][colunas+i] = '3';
       }
       for(i=0;i<14;++i)
           map[linhas+4][colunas+1+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '3';
       for(i=0;i<3;++i)
           map[linhas+7][colunas+7+i] = '3';
        
       return map;
}    

char** escreve_tile_9_7(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<10;++i)
	{
		map[linhas][colunas+1+i] = '3';
		map[linhas+1][colunas+1+i] = '3';
		map[linhas+4][colunas+1+i] = '3';
	}
	map[linhas+4][colunas+11] = '3';
	for(i=0;i<13;++i)
	{
		map[linhas+2][colunas+i] = '3';
		map[linhas+3][colunas+i] = '3';
	}
	for(i=0;i<9;++i)
	    map[linhas+5][colunas+3+i] = '3';
	map[linhas+6][colunas+6] = '3';
	return map;
}

char** escreve_tile_9_8(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<14;++i)
	{
		map[linhas][colunas+2+i] = '3';
		map[linhas+1][colunas+2+i] = '3';
		map[linhas+4][colunas+1+i] = '3';
	}
	for(i=0;i<15;++i)
	    map[linhas+2][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	    map[linhas+3][colunas+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+5][colunas+3+i] = '3';
	for(i=0;i<4;++i)
	    map[linhas+6][colunas+6+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+7+i] = '3';
	return map;
}

char** escreve_tile_9_9(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<13;++i)
	{
		map[linhas][colunas+i] = '3';
		map[linhas+1][colunas+i] = '3';
	}
	for(i=0;i<15;++i)
	{
		map[linhas+2][colunas+i] = '3';
		map[linhas+3][colunas+i] = '3';
	}
	for(i=0;i<12;++i)
	    map[linhas+4][colunas+1+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+5][colunas+3+i] = '3';
	for(i=0;i<4;++i)
	    map[linhas+6][colunas+6+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+7+i] = '3';
	return map;
}

char** escreve_tile_9_10(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<5;++i)
	    map[linhas][colunas+6+i] = '3';
	for(i=0;i<8;++i)
	    map[linhas+1][colunas+5+i] = '3';
	for(i=0;i<12;++i)
	    map[linhas+2][colunas+3+i] = '3';
	for(i=0;i<13;++i)
	{
		map[linhas+3][colunas+2+i] = '3';
		map[linhas+4][colunas+2+i] = '3';
	}
	for(i=0;i<10;++i)
	    map[linhas+5][colunas+3+i] = '3';
	for(i=0;i<5;++i)
	    map[linhas+6][colunas+6+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+7+i] = '3';
	return map;
}

char** escreve_tile_10_1(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<3;++i)
	    map[linhas][colunas+8+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+1][colunas+5+i] = '3';
	for(i=0;i<12;++i)
	    map[linhas+2][colunas+3+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	{
	    map[linhas+4][colunas+i] = '3';
	    map[linhas+5][colunas+i] = '3';
	    map[linhas+6][colunas+i] = '3';
	    map[linhas+7][colunas+i] = '3';
    }
    return map;
}

char** escreve_tile_10_2(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<6;++i)
	    map[linhas+1][colunas+5+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+2][colunas+4+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	{
	    map[linhas+4][colunas+i] = '3';
	    map[linhas+5][colunas+i] = '3';
	    map[linhas+6][colunas+i] = '3';
	    map[linhas+7][colunas+i] = '3';
    }
    return map;
}

char** escreve_tile_10_3(char **map,int linhas,int colunas)
{
	return escreve_tile_10_2(map,linhas,colunas);
}

char** escreve_tile_10_4(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<3;++i)
	    map[linhas][colunas+8+i] = '3';
	for(i=0;i<7;++i)
	    map[linhas+1][colunas+5+i] = '3';
	for(i=0;i<12;++i)
	    map[linhas+2][colunas+3+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	{
	    map[linhas+4][colunas+i] = '3';
	    map[linhas+5][colunas+i] = '3';
	    map[linhas+6][colunas+i] = '3';
	    map[linhas+7][colunas+i] = '3';
    }
    return map;
}

char** escreve_tile_10_5(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<3;++i)
	    map[linhas][colunas+8+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+1][colunas+5+i] = '3';
	for(i=0;i<11;++i)
	    map[linhas+2][colunas+3+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	{
	    map[linhas+4][colunas+i] = '3';
	    map[linhas+5][colunas+i] = '3';
	    map[linhas+6][colunas+i] = '3';
	    map[linhas+7][colunas+i] = '3';
    }
    return map;
}

char** escreve_tile_10_6(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<6;++i)
	    map[linhas+1][colunas+5+i] = '3';
	for(i=0;i<11;++i)
	    map[linhas+2][colunas+3+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+3][colunas+1+i] = '3';
	for(i=0;i<16;++i)
	{
	    map[linhas+4][colunas+i] = '3';
	    map[linhas+5][colunas+i] = '3';
	    map[linhas+6][colunas+i] = '3';
	    map[linhas+7][colunas+i] = '3';
    }
    return map;
}

char** escreve_tile_10_7(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<2;++i)
	    map[linhas+6][colunas+7+i] = '3';
	for(i=0;i<3;++i)
	    map[linhas+7][colunas+6+i] = '3';
	return map;
}

char** escreve_tile_10_8(char **map,int linhas,int colunas)
{
	return map;
}

char** escreve_tile_10_9(char **map,int linhas,int colunas)
{
	int i;
    map[linhas+6][colunas+7] = '3';
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+7+i] = '3';
	return map;
}

char** escreve_tile_10_10(char **map,int linhas,int colunas)
{
	return map;
}

char** escreve_tile_11_7(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<4;++i)
	{
		map[linhas][colunas+6+i] = '3';
		map[linhas+1][colunas+6+i] = '3';
	}
	for(i=0;i<2;++i)
	    map[linhas+2][colunas+7+i] ='3';
	return map;
}


char** escreve_tile_11_8(char **map,int linhas,int colunas)
{
	for(int i=0;i<3;++i)
	{
		map[linhas+1][colunas+11+i] = '3';
		map[linhas+2][colunas+11+i] = '3';
		map[linhas+3][colunas+11+i] = '3';
	}
	return map;
}

char** escreve_tile_11_9(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<4;++i)
	{
		map[linhas][colunas+6+i] = '3';
		map[linhas+1][colunas+6+i] = '3';
	}
	for(i=0;i<2;++i)
	    map[linhas+2][colunas+7+i] = '3';
	return map;
}


char** escreve_tile_11_10(char **map,int linhas,int colunas)
{
	int i;
	for(i=0;i<11;++i)
	    map[linhas+1][colunas+3+i] = '3';
	for(i=0;i<12;++i)
	{
		map[linhas+2][colunas+2+i] = '3';
		map[linhas+3][colunas+2+i] = '3';
	}
	for(i=0;i<9;++i)
	    map[linhas+4][colunas+4+i] = '3';
	for(i=0;i<5;++i)
	    map[linhas+5][colunas+6+i] = '3';
	return map;
}

char** escreve_tile_12_1(char **map,int linhas,int colunas)
{
	int i;
	
	for(i=0;i<4;++i)
	    map[linhas+7][colunas+4+i] = '3';
	
	return map;
}

char** escreve_tile_12_2(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
           map[linhas][colunas+6+i] = '2';
       for(i=0;i<8;++i)
	       map[linhas+1][colunas+4+i] = '2';
	   for(i=0;i<10;++i)
	       map[linhas+2][colunas+3+i] = '2';
	   for(i=0;i<14;++i)
	       map[linhas+3][colunas+1+i] = '2';
       for(i=0;i<16;++i)
           map[linhas+4][colunas+i] = '2';
       for(i=0;i<2;++i)
           map[linhas+5][colunas+i] = '3';
       for(i=0;i<13;++i)
           map[linhas+5][colunas+2+i] = '2';
       map[linhas+5][colunas+15] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+6][colunas+5+i] = '2';
       for(i=0;i<3;++i)
           map[linhas+6][colunas+13+i] = '3';
       for(i=0;i<7;++i)
           map[linhas+7][colunas+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+7][colunas+7+i] = '2';
       for(i=0;i<5;++i)
           map[linhas+7][colunas+11+i] = '3';
	   
       return map;
}    

char** escreve_tile_13_1(char **map,int linhas,int colunas)
{
	int i;
	
	for(i=0;i<6;++i)
	    map[linhas][colunas+4+i] = '3';
	for(i=0;i<8;++i)
	    map[linhas+1][colunas+3+i] = '3';
	for(i=0;i<9;++i)
	    map[linhas+2][colunas+3+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+3][colunas+2+i] = '3';
	map[linhas+3][colunas+13] = '3';
	for(i=0;i<9;++i)
	    map[linhas+4][colunas+3+i] = '3';
	map[linhas+4][colunas+13] = '3'; // Tava = '4' antes.
	for(i=0;i<6;++i)
	    map[linhas+5][colunas+5+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+6][colunas+7+i] = '3';
	
	return map;
}

char** escreve_tile_14_1(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
       {
       	   map[linhas][colunas+7+i] = '3';
       	   map[linhas+6][colunas+7+i] = '3';
       }
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
       {
       	   map[linhas+3][colunas+2+i] = '3';
       	   map[linhas+4][colunas+2+i] = '3';
       }
       for(i=0;i<7;++i)
           map[linhas+5][colunas+5+i] = '3';
       
       
       return map;
}

char** escreve_tile_14_2(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
       {
       	   map[linhas+2][colunas+4+i] = '3';
       	   map[linhas+3][colunas+6+i] = '3';
       }
       for(i=0;i<11;++i)
           map[linhas+4][colunas+4+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+5][colunas+4+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+6][colunas+9+i] = '3';
       
       return map;
}

char** escreve_tile_14_3(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+3][colunas+2+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+4][colunas+1+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+5+i] = '3';
       
       return map;
}

char** escreve_tile_14_4(char **map,int linhas,int colunas)
{
       int i;
       
       map[linhas+1][colunas+9] = '3';
       for(i=0;i<6;++i)
           map[linhas+2][colunas+6+i] = '3';
       for(i=0;i<11;++i)
           map[linhas+3][colunas+3+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+4][colunas+3+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+5][colunas+4+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+6][colunas+7+i] = '3';
       
       return map;
}

char** escreve_tile_14_5(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
       {
	       map[linhas][colunas+7+i] = '3';
	       map[linhas+7][colunas+7+i] = '3';
	   }
	   for(i=0;i<4;++i)
	   {
	   	   map[linhas+1][colunas+6+i] = '3';
	   	   map[linhas+6][colunas+6+i] = '3';
	   }
	   for(i=0;i<8;++i)
	   {
	       map[linhas+2][colunas+4+i] = '3';
	       map[linhas+5][colunas+4+i] = '3';
       }
	   for(i=0;i<14;++i)
	   {
	   	   map[linhas+3][colunas+1+i] = '3';
	   	   map[linhas+4][colunas+1+i] = '3';
	   }
	   
       return map;
}

char** escreve_tile_14_7(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+3][colunas+2+i] = '3';
       for(i=0;i<13;++i)
           map[linhas+4][colunas+1+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+6][colunas+5+i] = '3';
       
       return map;
}

char** escreve_tile_14_8(char** map,int linhas,int colunas)
{
	int i;
	
	for(i=0;i<3;++i)
	    map[linhas+1][colunas+7+i] = '3';
	for(i=0;i<5;++i)
	    map[linhas+2][colunas+7+i] = '3';
	for(i=0;i<11;++i)
	    map[linhas+3][colunas+3+i] = '3';
	for(i=0;i<14;++i)
	    map[linhas+4][colunas+2+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+5][colunas+3+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+6][colunas+5+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+7+i] = '3';
	
	return map;
}

char** escreve_tile_14_9(char** map,int linhas,int colunas)
{
	int i;
	
	for(i=0;i<3;++i)
	    map[linhas+1][colunas+6+i] = '3';
	for(i=0;i<8;++i)
	    map[linhas+2][colunas+4+i] = '3';
	for(i=0;i<13;++i)
	{
		map[linhas+3][colunas+1+i] = '3';
		map[linhas+4][colunas+1+i] = '3';
	}
	for(i=0;i<10;++i)
	    map[linhas+5][colunas+3+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+6][colunas+5+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+7+i] = '3';
    
	return map;
}

char** escreve_tile_14_10(char** map,int linhas,int colunas)
{
	int i;
	
	for(i=0;i<3;++i)
	    map[linhas+1][colunas+7+i] = '3';
	for(i=0;i<7;++i)
	    map[linhas+2][colunas+4+i] = '3';
	for(i=0;i<11;++i)
	    map[linhas+3][colunas+3+i] = '3';
	for(i=0;i<13;++i)
	    map[linhas+4][colunas+2+i] = '3';
	for(i=0;i<10;++i)
	    map[linhas+5][colunas+3+i] = '3';
	for(i=0;i<6;++i)
	    map[linhas+6][colunas+5+i] = '3';
	for(i=0;i<2;++i)
	    map[linhas+7][colunas+7+i] = '3';
	
	return map;
}

char** escreve_tile_15_1(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<14;++i)
           map[linhas+3][colunas+1+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+4][colunas+2+i] = '3';
       for(i=0;i<7;++i)
           map[linhas+5][colunas+5+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+6][colunas+8+i] = '3';
       
       return map;
}    

char** escreve_tile_15_2(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<3;++i)
           map[linhas+1][colunas+5+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+2][colunas+3+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+3][colunas+5+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+4][colunas+4+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+5][colunas+4+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+6][colunas+9+i] = '3';
       
       return map;
}    

char** escreve_tile_15_3(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<3;++i)
           map[linhas+1][colunas+7+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+2][colunas+7+i] = '3';
       for(i=0;i<11;++i)
           map[linhas+3][colunas+3+i] = '3';
       for(i=0;i<11;++i)
           map[linhas+4][colunas+2+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+5+i] = '3';
       
       return map;
}    

char** escreve_tile_15_4(char **map,int linhas,int colunas)
{
       int i;
       
       map[linhas+1][colunas+9] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+5+i] = '3';
       for(i=0;i<11;++i)
       {
       	   map[linhas+3][colunas+3+i] = '3';
       	   map[linhas+4][colunas+3+i] = '3';
       }
       for(i=0;i<9;++i)
           map[linhas+5][colunas+4+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+6][colunas+7+i] = '3';
       
       return map;
}    

char** escreve_tile_15_5(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<9;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
       {
           map[linhas+3][colunas+2+i] = '3';
           map[linhas+4][colunas+2+i] = '3';
       }
       for(i=0;i<9;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+5+i] = '3';
       
       return map;
}    

char** escreve_tile_15_6(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<11;++i)
           map[linhas+3][colunas+3+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+4][colunas+2+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '3';
       
       return map;
}    

char** escreve_tile_15_7(char **map,int linhas,int colunas)
{
       int i;
       
       map[linhas][colunas+7] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<14;++i)
       {
       	   map[linhas+3][colunas+1+i] = '3';
       	   map[linhas+4][colunas+1+i] = '3';
       }
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+7][colunas+7+i] = '3';
       
       return map;
}    

char** escreve_tile_15_8(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+3][colunas+2+i] = '3';
       for(i=0;i<13;++i)
           map[linhas+4][colunas+1+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+7][colunas+7+i] = '3';
       
       return map;
}    

char** escreve_tile_15_9(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
       {
       	   map[linhas+3][colunas+2+i] = '3';
       	   map[linhas+4][colunas+2+i] = '3';
       }
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+7][colunas+7+i] = '3';
       
       return map;
}    

char** escreve_tile_15_10(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+3][colunas+2+i] = '3';
       for(i=0;i<14;++i)
           map[linhas+4][colunas+1+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '3';
       
       return map;
}    

char** escreve_tile_16_1(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<3;++i)
           map[linhas][colunas+6+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+1][colunas+5+i] = '3';
       for(i=0;i<8;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<12;++i)
           map[linhas+3][colunas+2+i] = '3';
       for(i=0;i<14;++i)
           map[linhas+4][colunas+1+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+6][colunas+5+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+7][colunas+7+i] = '3';
       
       return map;
}    

char** escreve_tile_16_2(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas+1][colunas+7+i] = '3';
       for(i=0;i<6;++i)
           map[linhas+2][colunas+4+i] = '3';
       for(i=0;i<10;++i)
           map[linhas+3][colunas+3+i] = '3';
       for(i=0;i<5;++i)
       {
       	   map[linhas+4][colunas+4+i] = '3';
       	   map[linhas+5][colunas+3+i] = '3';
       }
       
       return map;
}    

char** escreve_tile_16_3(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<2;++i)
           map[linhas][colunas+7+i] = '3';
       for(i=0;i<4;++i)
           map[linhas+1][colunas+6+i] = '3';
       for(i=0;i<3;++i)
       {
       	   map[linhas+2][colunas+4+i] = '3';
       	   map[linhas+2][colunas+9+i] = '3';
       }
       for(i=0;i<6;++i)
           map[linhas+3][colunas+1+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+3][colunas+9+i] = '3';
       for(i=0;i<5;++i)
       {
       	   map[linhas+4][colunas+1+i] = '3';
       	   map[linhas+4][colunas+10+i] = '3';
       }
       for(i=0;i<10;++i)
           map[linhas+5][colunas+3+i] = '3';
       for(i=0;i<5;++i)
           map[linhas+6][colunas+5+i] = '3';
       for(i=0;i<2;++i)
           map[linhas+7][colunas+7+i] = '3';
       
       return map;
}    

char** escreve_tile_23_3(char **map,int linhas,int colunas)
{
       int i;
       
	   for(i=0;i<3;++i)
	   {
	   		map[linhas+2][colunas+6+i] = '3';
	   		map[linhas+3][colunas+6+i] = '3';
	   }
       
       return map;
}    

char** escreve_tile_27_1(char **map,int linhas,int colunas)
{
       int i;
       
	   for(i=0;i<3;++i)
	   {
	   		map[linhas+2][colunas+6+i] = '3';
	   		map[linhas+3][colunas+6+i] = '3';
	   		map[linhas+4][colunas+6+i] = '3';
	   }
       
       return map;
}

char** escreve_tile_27_5(char **map,int linhas,int colunas)
{
       int i;
       
       for(i=0;i<4;++i)
       {
       	   map[linhas][colunas+6+i] = '3';
       	   map[linhas+1][colunas+6+i] = '3';
       }
       for(i=0;i<6;++i)
       {
       	   map[linhas+2][colunas+5+i] = '3';
       	   map[linhas+4][colunas+6+i] = '3';
       }
	   for(i=0;i<10;++i)
	   		map[linhas+3][colunas+3+i] = '3';
       map[linhas+5][colunas+6] = '3';
       
       return map;
}


/*
"Prototipo"
char** escreve_tile_x_x(char **map,int linhas,int colunas)
{
       int i;
       return map;
}
*/


/*
"Prototipo"
char** escreve_tile_x_x(char **map,int linhas,int colunas)


*
{
       int i;
       return map;
}
*/

char** escreve_arquivo(char **map)
{
	FILE *fp = fopen("matriz.txt","w");
	int j;

	for(int i=0;i<TAM;++i)
	{
	    for(j=0;j<TAM;j++)
	        fprintf(fp,"%c",map[i][j]);
	    fprintf(fp,"\n");
    }

    fclose(fp);

    char travar;

    scanf("%c",&travar);

    return map;
}


/*

TODOS OS TILES:

Tile 1x1:
X X X X X X 1 1 1 1 0 0 0 0 0 0 
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 1 1 1 1 1 1 1 1 1 1 1 1 0 0 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
0 0 1 1 1 1 1 1 1 1 1 1 1 1 0 0 
0 0 0 0 1 1 1 1 1 1 1 1 0 0 0 0 
0 0 0 0 0 0 1 1 1 1 0 0 0 0 0 0 

Tile 4x1:
X X X X X X X 2 2 X X X X X X X 
X X X X X X 2 2 2 2 X X X X X X 
X X X X X 2 2 2 2 2 2 X X X X X
X X X X X 2 2 2 2 2 2 X X X X X
X X X X 2 2 2 2 2 2 2 2 X X X X
X X X 2 2 2 2 2 2 2 2 2 2 X X X
X X X 2 2 2 2 2 2 2 2 2 2 X X X
X X 2 2 2 2 2 2 2 2 2 2 2 2 X X

Tile 4x2:
X X X X X X X 2 2 2 X X X X X X 
X X X X X X X 2 2 2 2 X X X X X 
X X X X X X 2 2 2 2 2 2 2 2 X X 
X X X X 2 2 2 2 2 2 2 2 2 2 2 2 
X X X X 2 2 2 2 2 2 2 2 2 2 2 2 
X X X 2 2 2 2 2 2 2 2 2 2 2 2 3 
X X 2 2 2 2 2 2 2 2 2 2 2 2 3 3 
X X 2 2 2 2 2 2 2 2 2 2 2 3 3 3 

Tile 4x3:
X X X X X X 2 2 3 X X X X X X X 
X X X X X 2 2 2 2 3 X X X X X X 
X X X 2 2 2 2 2 2 2 3 X X X X X 
X 2 2 2 2 2 2 2 2 2 2 3 X X X X 
2 2 2 2 2 2 2 2 2 2 2 3 X X X X 
3 3 2 2 2 2 2 2 2 2 2 2 3 X X X 
3 3 2 2 2 2 2 2 2 2 2 2 3 X X X 
3 3 3 2 2 2 2 2 2 2 2 2 2 3 X X 

Tile 4x4:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X 2 2 2 2 
X X X X X X X X X X 2 2 2 2 2 3 
X X X X X X X X X 2 2 2 2 2 3 3 
X X X X X X X X 2 2 2 2 2 3 3 3 

Tile 4x5:
X X X X X X X 2 2 X X X X X X X 
X X X X X 2 2 2 2 2 2 X X X X X 
X X X 2 2 2 2 2 2 2 2 2 2 X X X 
X 2 2 2 2 2 2 2 2 2 2 2 2 2 2 X 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
3 3 3 2 2 2 2 2 2 2 2 2 2 3 3 3 
3 3 3 3 3 2 2 2 2 2 2 3 3 3 3 3 
3 3 3 3 3 3 3 2 2 2 3 3 3 3 3 X  

Tile 4x6:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
2 2 2 2 X X X X X X X X X X X X 
3 3 2 2 2 2 X X X X X X X X X X 
3 3 3 2 2 2 2 X X X X X X X X X 
3 3 3 3 2 2 2 2 X X X X X X X X 

Tile 4x7:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X 2 2 2 3 
X X X X X X X X X 2 2 2 2 3 3 3 
X X X X X X 2 2 2 2 2 3 3 3 3 3 
X X X X 2 2 2 2 2 3 3 3 3 3 3 X 

Tile 4x8:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
2 2 2 2 X X X X X X X X X X X X 
3 3 2 2 2 2 2 X X X X X X X X X 
3 3 3 3 2 2 2 2 2 X X X X X X X 
3 3 3 3 3 3 2 2 2 2 2 X X X X X 

Tile 4x9:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 5x1:
X 2 2 2 2 2 2 2 2 2 2 2 2 2 2 X
X 2 2 2 2 2 2 2 2 2 2 2 2 2 2 X
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
X 2 2 2 2 2 2 2 2 2 2 2 2 2 2 X
X X X 2 2 2 2 2 2 2 2 2 2 X X X
X X X X X 2 2 2 2 2 2 X X X X X
X X X X X X X 2 2 X X X X X X X 

Tile 5x2:
X 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 
X 2 2 2 2 2 2 2 2 2 2 2 3 3 3 3 
X 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 
2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 
X 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 
X X X 2 2 2 2 2 2 3 3 3 3 3 X X 
X X X X 2 2 2 2 2 3 3 3 X X X X 
X X X X X X 2 2 2 X X X X X X X 

Tile 5x3:
3 3 3 3 2 2 2 2 2 2 2 2 2 3 X X 
3 3 3 3 3 2 2 2 2 2 2 2 2 2 3 X 
3 3 3 3 3 2 2 2 2 2 2 2 2 2 2 3 
3 3 3 3 3 3 2 2 2 2 2 2 2 2 2 2 
3 3 3 3 3 3 2 2 2 2 2 2 2 2 2 2 
X X 3 3 3 3 2 2 2 2 2 2 2 2 X X 
X X X X X 3 3 2 2 2 2 2 X X X X 
X X X X X X X X 2 2 2 X X X X X 

Tile 5x4:
X X X X X X X 2 2 2 2 2 3 3 3 3 
X X X X X 2 2 2 2 2 2 3 3 3 3 3 
X X X 2 2 2 2 2 2 2 3 3 3 3 3 3 
X 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 
2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 
X X 2 2 2 2 2 2 2 3 3 3 3 3 X X 
X X X X 2 2 2 2 2 3 3 3 X X X X 
X X X X X X 2 2 3 3 X X X X X X 

Tile 5x5:
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 X X X X X X 

Tile 5x6:
3 3 3 3 2 2 2 2 2 X X X X X X X 
3 3 3 3 3 2 2 2 2 2 2 X X X X X 
3 3 3 3 3 2 2 2 2 2 2 2 2 X X X 
3 3 3 3 3 3 2 2 2 2 2 2 2 2 2 2 
3 3 3 3 3 3 2 2 2 2 2 2 2 2 2 2 
X X 3 3 3 3 2 2 2 2 2 2 2 2 X X 
X X X X 3 3 3 2 2 2 2 2 X X X X 
X X X X X X 3 2 2 2 X X X X X X 

Tile 5x7:
X X X 2 2 2 3 3 3 3 3 3 3 3 3 X 
X X 2 2 3 3 3 3 3 3 3 3 3 3 3 X 
X 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 X X X X X X X 

Tile 5x8:
3 3 3 3 3 3 3 3 3 3 2 2 2 X X X 
3 3 3 3 3 3 3 3 3 3 3 3 2 2 X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 2 2 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 2 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 X X X X X X 

Tile 5x9:
X X X X X 3 3 3 2 2 X X X X X X 
X X X 3 3 3 3 3 3 3 3 3 2 X X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 2 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 X X X X X X 

Tile 6x1:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
2 2 2 2 X X X X X X X X 2 2 2 2 
3 3 3 2 2 2 2 2 2 2 2 2 2 3 3 3 
3 3 3 3 3 2 2 2 2 2 2 3 3 3 3 3 
3 3 3 3 3 3 3 2 2 3 3 3 3 3 3 X 

Tile 6x2:
X X X X X X 2 2 2 X X X X X X X 
X X X X 2 2 2 2 2 2 X X X X X X 
X X 2 2 2 2 2 2 2 2 2 X X X X X 
2 2 2 2 2 2 2 2 2 2 2 2 X X X X 
2 2 2 2 2 2 2 2 2 2 2 2 X X X X 
3 3 3 2 2 2 2 2 2 2 2 2 2 X X X 
3 3 3 3 3 2 2 2 2 2 2 2 2 2 X X 
3 3 3 3 3 3 3 2 2 2 2 2 2 2 X X 

Tile 6x3:
X X X X X X 2 2 2 2 X X X X X X 
X X X X 2 2 2 2 2 2 2 X X X X X 
X X X 2 2 2 2 2 2 2 2 2 2 2 X X 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
3 2 2 2 2 2 2 2 2 2 2 2 2 2 2 3 
3 3 2 2 2 2 2 2 2 2 2 2 2 2 3 3 
3 3 3 2 2 2 2 2 2 2 2 2 2 3 3 3 

Tile 6x4:
X X X X X X X 2 2 2 X X X X X X 
X X X X X X X 2 2 2 2 X X X X X 
X X X X X 2 2 2 2 2 2 2 2 2 X X 
X X X X X 2 2 2 2 2 2 2 2 2 2 2 
X X X X 2 2 2 2 2 2 2 2 2 2 2 2 
X X X 2 2 2 2 2 2 2 2 2 2 3 3 3 
X X 2 2 2 2 2 2 2 2 2 2 3 3 3 3 
X X 2 2 2 2 2 2 2 3 3 3 3 3 3 X 

Tile 7x1:
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 X X X X X X 

Tile 7x2:
3 3 3 3 3 3 3 3 3 3 2 2 2 2 2 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 2 2 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 2 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 2 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 X X X X X X 

Tile 7x3:
3 3 3 3 2 2 2 2 2 2 2 2 3 3 3 3 
3 3 3 3 2 2 2 2 2 2 2 2 3 3 3 3 
3 3 3 3 3 2 2 2 2 2 2 3 3 3 3 3 
3 3 3 3 3 2 2 2 2 2 2 3 3 3 3 3 
3 3 3 3 3 3 2 2 2 2 3 3 3 3 3 3 
X X 3 3 3 2 2 2 3 3 3 3 3 3 X X 
X X X X 3 3 3 2 2 3 3 3 X X X X 
X X X X X X 2 2 2 2 X X X X X X 

Tile 7x4:
X 2 2 2 2 2 3 3 3 3 3 3 3 3 3 X 
X 2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 
2 2 2 2 3 3 3 3 3 3 3 3 3 3 3 3 
2 2 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 X X X X X X 

Tile 8x1:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X 3 3 3 3 3 X X X X X X X 
X X X X 3 3 3 3 3 X X X X X X X 
X X X X 3 3 3 3 3 X X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 

Tile 8x2:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X 3 3 X X X X X X X 
X X X X X X X 3 3 3 3 X X X X X 
X X X X X X 3 3 3 3 3 X X X X X 
X X X X X 3 3 3 3 3 3 3 X X X X 
X X X X X 3 3 3 3 3 3 3 3 X X X 
X X X X 3 3 3 3 3 3 3 3 3 X X X  

Tile 8x3:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X 3 3 3 3 X X X X X X X 
X X 3 3 3 3 3 3 3 X X X X X X X 
X 3 3 3 3 3 3 3 3 X X X X X X X 
X 3 3 3 3 3 3 3 3 3 X X X X X X 
X 3 3 3 3 3 3 3 3 3 X X X X X X 
X 3 3 3 3 3 3 3 3 3 3 X X X X X 

Tile 8x4:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X 3 3 3 3 
X X X X X X X X X X X X 3 3 3 3 
X X X X X X 3 3 3 3 3 3 3 3 3 3 
X X X X X X X 3 3 3 3 3 3 3 3 3 

Tile 8x5:
X X X X X X X 3 3 X X X X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 8x6:
X X X X X X X 3 3 3 3 X X X X X 
X X X X X X 3 3 3 3 3 X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 8x7:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X 3 3 3 X X X X X X X X X X X X 
3 3 3 3 3 3 X X X X X X X X X X 
3 3 3 3 3 3 X X 3 3 X X X X X X 
3 3 3 3 3 3 3 3 3 3 X X X X X X 

Tile 8x8:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X 3 3 X X 
X X X X X X X 3 3 3 3 3 3 3 3 3 
X X X X X X 3 3 3 3 3 3 3 3 3 3 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 8x9:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X 3 3 3 X X X X X X X X X X X X 
X 3 3 3 3 3 3 3 3 X X X X X X X 
3 3 3 3 3 3 3 3 3 3 X X X X X X 
3 3 3 3 3 3 3 3 3 3 X X X X X X 
3 3 3 3 3 3 3 3 3 3 3 X X X X X 

Tile 8x10:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X 3 3 X X X X X X 

Tile 9x1:
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X X X 3 3 3 3 3 3 X X X X X X 
X X X X X X X 3 3 3 X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 9x2:
X X X X 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 X X X 
X X X 3 3 3 X X 3 3 3 X X X X X 
X X X X X X X X 3 3 X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 9x3:
3 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X X 3 X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 9x4:
X X X X X 3 3 3 3 3 3 3 3 3 3 3 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X X X 3 3 3 3 3 3 3 3 3 3 3 X 
X X X X X 3 3 3 3 3 3 3 3 X X X 
X X X X X X X X 3 3 X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 9x7:
X 3 3 3 3 3 3 3 3 3 3 X X X X X 
X 3 3 3 3 3 3 3 3 3 3 X X X X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
X 3 3 3 3 3 3 3 3 3 3 3 X X X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 9x8:
X X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 9x9:
3 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 9x10:
X X X X X X 3 3 3 3 3 X X X X X 
X X X X X 3 3 3 3 3 3 3 3 X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 10x1:
X X X X X X X X 3 3 3 X X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 10x2:
X X X X X X X X X X X X X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 10x3:
X X X X X X X X X X X X X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 10x4:
X X X X X X X X 3 3 3 X X X X X 
X X X X X 3 3 3 3 3 3 3 X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 10x5:
X X X X X X X X 3 3 3 X X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 10x6:
X X X X X X X X X X X X X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 

Tile 10x7:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 X X X X X X X 

Tile 10x8:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 10x9:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X 3 X X X X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 10x10:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 11x7:
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X X 3 3 X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X 3 X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 11x8:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X 3 3 3 X X 
X X X X X X X X X X X 3 3 3 X X 
X X X X X X X X X X X 3 3 3 X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 11x9:
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X X 3 3 X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 11x10:
X X X X X X X X X X X X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X 3 3 3 3 3 X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 9x5, 9x6, 11x1, 11x2, 11x3, 11x4, 11x5, 11x6, 13x2, 13x3, 13x4, 13x5, 13x6, 13x7, 13x8, 13x9, 13x10
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 3 X X X X X X 

Tile 12x1:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X 3 3 3 3 X X X X X X X X 

Tile 12x2, 12x3, 12x4, 12x5, 12x6, 12x7, 12x8, 12x9, 12x10:
X X X X X X 2 2 2 2 X X X X X X 
X X X X 2 2 2 2 2 2 2 2 X X X X 
X X X 2 2 2 2 2 2 2 2 2 2 X X X 
X 2 2 2 2 2 2 2 2 2 2 2 2 2 2 X 
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 
3 3 2 2 2 2 2 2 2 2 2 2 2 2 2 3 
3 3 3 3 3 2 2 2 2 2 2 2 2 3 3 3 
3 3 3 3 3 3 3 2 2 2 2 3 3 3 3 3 

Tile 13x1:
X X X X 3 3 3 3 3 3 X X X X X X 
X X X 3 3 3 3 3 3 3 3 X X X X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X 3 3 3 3 3 3 3 3 3 3 X 3 X X 
X X X 3 3 3 3 3 3 3 3 3 X 3 X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 14x1:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X X 3 3 3 3 3 3 3 X X X X 
X X X X X X X 3 3 X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 14x2:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 3 3 3 X 
X X X X 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X X X X 3 3 X X X X X 
X X X X X X X X X X X X X X X X 

Tile 14x3:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 X X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X X X X 3 3 3 3 3 X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 14x4:
X X X X X X X X X X X X X X X X 
X X X X X X X X X 3 X X X X X X 
X X X X X X 3 3 3 3 3 3 X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X X 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X X 3 3 3 3 X X X X X 
X X X X X X X X X X X X X X X X 

Tile 14x5 e 14x6:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 14x7:
X X X X X X X X X X X X X X X X 
X X X X X X 3 3 X X X X X X X X 
X X X X 3 3 3 3 3 3 3 3 3 X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X X X X 3 3 3 3 X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 14x8:
X X X X X X X X X X X X X X X X 
X X X X X X X 3 3 3 X X X X X X 
X X X X X X X 3 3 3 3 3 X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 14x9:
X X X X X X X X X X X X X X X X 
X X X X X X 3 3 3 X X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 14x10:
X X X X X X X X X X X X X X X X 
X X X X X X X 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 15x1:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X X 3 3 3 3 3 3 3 X X X X 
X X X X X X X X 3 3 X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 15x2:
X X X X X X X X X X X X X X X X 
X X X X X 3 3 3 X X X X X X X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X X X X 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X X X X 3 3 X X X X X 
X X X X X X X X X X X X X X X X 

Tile 15x3:
X X X X X X X X X X X X X X X X 
X X X X X X X 3 3 3 X X X X X X 
X X X X X X X 3 3 3 3 3 X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 X X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X X X X 3 3 3 3 3 X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 15x4:
X X X X X X X X X X X X X X X X 
X X X X X X X X X 3 X X X X X X 
X X X X X 3 3 3 3 3 3 3 3 X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X X 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X X 3 3 3 3 X X X X X 
X X X X X X X X X X X X X X X X 

Tile 15x5:
X X X X X X X X X X X X X X X X 
X X X X X X 3 3 X X X X X X X X 
X X X X 3 3 3 3 3 3 3 3 3 X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 X X X X 
X X X X X 3 3 3 3 3 X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 15x6:
X X X X X X X X X X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 X X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X X X X X X X X X X 

Tile 15x7:
X X X X X X X 3 X X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 15x8:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 15x9:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 15x10:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X X X X X X X X X X 

Tile 16x1:
X X X X X X 3 3 3 X X X X X X X 
X X X X X 3 3 3 3 3 X X X X X X 
X X X X 3 3 3 3 3 3 3 3 X X X X 
X X 3 3 3 3 3 3 3 3 3 3 3 3 X X 
X 3 3 3 3 3 3 3 3 3 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 16x2:
X X X X X X X X X X X X X X X X 
X X X X X X X 3 3 X X X X X X X 
X X X X 3 3 3 3 3 3 X X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X 3 3 3 3 3 X X X X X X X 
X X X 3 3 3 3 3 X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 16x3:
X X X X X X X 3 3 X X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X 3 3 3 X X 3 3 3 X X X X 
X 3 3 3 3 3 3 X X 3 3 3 3 3 X X 
X 3 3 3 3 3 X X X X 3 3 3 3 3 X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X 3 3 3 3 3 X X X X X X 
X X X X X X X 3 3 X X X X X X X 

Tile 21x3:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X 3 3 3 X X X X X X X 
X X X X X X 3 3 3 X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 27x1:
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X 3 3 3 X X X X X X X 
X X X X X X 3 3 3 X X X X X X X 
X X X X X X 3 3 3 X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 

Tile 27x5:
X X X X X X 3 3 3 3 X X X X X X 
X X X X X X 3 3 3 3 X X X X X X 
X X X X X 3 3 3 3 3 3 X X X X X 
X X X 3 3 3 3 3 3 3 3 3 3 X X X 
X X X X X X 3 3 3 3 3 3 X X X X 
X X X X X X 3 X X X X X X X X X 
X X X X X X X X X X X X X X X X 
X X X X X X X X X X X X X X X X 
*/
