#include <allegro.h>
#include <stdio.h>

#define n 1000
#define ladobuffer 640
int main(){

    allegro_init();
   	install_timer();
	install_keyboard();
	install_mouse();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 640, 480);
    //set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 640, 480);
    
    BITMAP *tileiso=load_bitmap("fig\\tile iso.bmp",NULL);
    BITMAP *tilemenu=load_bitmap("fig\\menuiso.bmp",NULL);
    BITMAP *buffer = create_bitmap (ladobuffer, 480);
    
    
    int xtile[n],ytile[n],xcorte[n],ycorte[n],tile_arquivo[n];
    int xcorte_aux=0,ycorte_aux=0;
    int aux=-1,tipoaux=0,aux_do_aux=-1,impedir=0,pos=0;
    int xbuffer=0,numero=0;
    int h=0;
    char tamanho[100];
    FILE *arquivo;
    
    
    for(int i=0;i<n;i++)
    {
         xtile[i]=-100;
         ytile[i]=-100;                          
    }
	while (!key[KEY_ESC]) {
          clear(buffer);
          //stretch_blit(tileiso, buffer,0,0,640,1024, 512,276,128,204);
          if(key[KEY_RIGHT]){
          for(int j=0;j<n;j++){
                  xtile[j]+=32;
                  }   
                  pos+=1;
                  rest(300);
               }
          if(key[KEY_LEFT]){
          for(int j=0;j<n;j++){
                  xtile[j]-=32;
                  }   
                  pos-=1;rest(300);
               }
          if(key[KEY_C]){xcorte_aux+=64;rest(300);
          }else if(key[KEY_Z]){xcorte_aux-=64;rest(300);
          }else if(key[KEY_X]){ycorte_aux+=32;rest(300);
          }else if(key[KEY_S]){ycorte_aux-=32;rest(300);
          }else if(key[KEY_O]){
                arquivo= fopen("lago1.txt", "r");
                fscanf(arquivo,"%i\n",&aux);
               	for(int i=0;i<aux+1;i++){
                 fscanf(arquivo,"%i %i %i %i\n",&xtile[i],&ytile[i],&xcorte[i],&ycorte[i]);
                 }
          }else if(key[KEY_S]){
                    arquivo= fopen("mapa.txt", "w");
                    fprintf(arquivo,"%i\n",aux+1);
	                for(int i=0;i<aux+1;i++){
                            fprintf(arquivo,"%i %i %i %i\n",xtile[i],ytile[i],xcorte[i],ycorte[i]);
                    }
          }
          if(key[KEY_1]){tamanho[numero]='1';numero+=1;rest(300);
          }else if(key[KEY_2]){tamanho[numero]='2';numero+=1;rest(300);
          }else if(key[KEY_3]){tamanho[numero]='3';numero+=1;rest(300);
          }else if(key[KEY_4]){tamanho[numero]='4';numero+=1;rest(300);
          }else if(key[KEY_5]){tamanho[numero]='5';numero+=1;rest(300);
          }else if(key[KEY_6]){tamanho[numero]='6';numero+=1;rest(300);
          }else if(key[KEY_7]){tamanho[numero]='7';numero+=1;rest(300);
          }else if(key[KEY_8]){tamanho[numero]='8';numero+=1;rest(300);
          }else if(key[KEY_9]){tamanho[numero]='9';numero+=1;rest(300);
          }else if(key[KEY_0]){tamanho[numero]='0';numero+=1;rest(300);}
          for(int j=0;j<n;j++){
                  //draw_sprite (buffer, tipo_tile[j], xtile[j], ytile[j]);
                  masked_blit(tileiso, buffer,xcorte[j],ycorte[j],xtile[j],ytile[j], 64, 32);
                  }
                  
          textprintf(buffer, font, 200, 10, makecol(255,250,0), "pos: %i", pos);
          textprintf(buffer, font, 200, 30, makecol(255,250,0), "n: %i", aux);
          textprintf(buffer, font, 300, 10, makecol(0,250,0), "%s", tamanho);
          textprintf(buffer, font, 100, 10, makecol(0,250,0), "click: o");
          
          
          for(int x=0;x<1000;x+=32)
          {
          for(int y=0;y<1000;y+=16)
          {
                  //putpixel(buffer,x,y,(0,0,200));
                  if((mouse_x>=x-14)and(mouse_x<x+14)and
                  (mouse_y>=y-10)and(mouse_y<y+10)and((x<=480)or(y<=244)))
                  {
                      line(buffer, x-32,y,x,y-16,(0,0,255));
                      line(buffer, x,y-16,x+32,y,(0,0,255));
                      line(buffer, x+32,y,x,y+16,(0,0,255));
                      line(buffer, x,y+16,x-32,y,(0,0,255));
                  
                      for(int j=0;j<n;j++)
                      {           
                          if((mouse_x>=xtile[j])and(mouse_x<xtile[j]+64)and
                          (mouse_y>=ytile[j])and(mouse_y<ytile[j]+32))
                          {
                                  if(mouse_b==2)
                                  {   // Click do botao direito.
                                      aux_do_aux=aux;
                                      aux=j;
                                      xtile[j]=-100;
                                      ytile[j]=-100;
                                      rest(300);
                                  }
                                  else if(mouse_b==1)
                                  {
                                        impedir=1;
                                  }
                                  else
                                  {
                                      impedir=0;
                                  }
                          }
                      }
                  
                      if((mouse_b==1)and(aux_do_aux<=-1))
                      {
                                 aux+=1;
                                 xtile[aux]=x-32;
                                 ytile[aux]=y-16;
                                 xcorte[aux]=xcorte_aux;
                                 ycorte[aux]=ycorte_aux+32;
                                 tile_arquivo[aux]=tipoaux;
                                 //tipo_tile[aux]=tile[tipoaux];
                                 rest(300);
                      }
                      else if((mouse_b==1)and(aux_do_aux>-1))
                      {
                        xtile[aux]=x-32;
                        ytile[aux]=y-16;   
                        aux=aux_do_aux; 
                        aux_do_aux=-1;
                        rest(300);                    
                      }
                  }
          } // Fim do for de dentro (do y).
          } // Fim do for de fora (do x).
          masked_blit(tilemenu, buffer,0,0,512,276, 200, 206);
          rect(buffer, (xcorte_aux/5)+512,(ycorte_aux/5)+282,(xcorte_aux/5)+6+512,(ycorte_aux/5)+6+282,(0,0,255));
          show_mouse(buffer);
          //masked_blit(buffer, screen,xbuffer,0,0,0, ladobuffer, 480);
          masked_blit(buffer, screen,0,0,0,0, 680, 480);

	}
    arquivo= fopen("dado.txt", "w");
    fprintf(arquivo,"%i\n",aux+1);
	for(int i=0;i<aux+1;i++){
            fprintf(arquivo,"%i %i %i %i\n",xtile[i],ytile[i],xcorte[i],ycorte[i]);
    }
}
END_OF_MAIN();

