#include "menu.h"

int mousex=0, mousey=0;

char edit[255];
int palavra=0,auxilia_botao=0;//diz qual botao sera usado no codigo allegro

char editor_text(ALLEGRO_EVENT ev,Window win)
{
	//al_wait_for_event(win.event_queue, &ev);
    for(int i=0;i<200;i++) {
	 	if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
            if((ev.keyboard.keycode==i) && (ev.keyboard.keycode!=67) && (ev.keyboard.keycode!=63) &&
			   (ev.keyboard.keycode!=75) && (ev.keyboard.keycode!=59) && (ev.keyboard.keycode!=82) &&
			   (ev.keyboard.keycode!=83) && (ev.keyboard.keycode!=84) && (ev.keyboard.keycode!=85)) {
                edit[palavra]=i+96;
                auxilia_botao=i;
                palavra+=1;
                //al_rest(0.1);
            }
        }
    }
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
		if((ev.keyboard.keycode==75)) {
            edit[palavra]=' ';
            palavra+=1;
        }
        if((ev.keyboard.keycode==82)) {
            edit[palavra]='<';
            auxilia_botao=82;
            palavra+=1;
        }
        if((ev.keyboard.keycode==83)) {
            edit[palavra]='>';
            auxilia_botao=83;
            palavra+=1;
        }
        if((ev.keyboard.keycode==84)) {
            edit[palavra]='^';
            auxilia_botao=84;
            palavra+=1;
        }
        if((ev.keyboard.keycode==85)) {
            edit[palavra]='|';
            auxilia_botao=85;
            palavra+=1;
        }
	    if(ev.keyboard.keycode==63) {
            if(palavra > 0) {
	            palavra-=1;
	            edit[palavra]=0;
	            //al_rest(0.1);
			}
	    } else if(ev.keyboard.keycode==67) {
	    	// Do something?
	    }
    }
    return edit[0];
}

int botao(char *texto,int x,int y,ALLEGRO_EVENT ev)
{
	ALLEGRO_FONT *font2 = al_load_font("Fonts/fixed_font.tga",0,0);
	int tamanho=al_get_text_width(font2,texto);
	if(tamanho<5) {
		tamanho=10;
	}
	if((mousex>x) && (mousex<=x+tamanho) && (mousey>=y) && (mousey<=y+10)) {
		al_draw_textf(font2,AZUL,x,y,0,"%s",texto);
	} else {
		al_draw_textf(font2,VERDE_LIMAO,x,y,0,"%s",texto);
	}
	if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
    	if((mousex>x) && (mousex<=x+tamanho) && (mousey>=y) && (mousey<=y+10)) {
    		return 1;
    	}
    }
    return 0;
    al_destroy_font(font2);
}

void opcoes(Window win, Pessoa *p){
	int tipo_botao=-1,jogador_opcoes=0;
	ALLEGRO_FONT *font2 = al_load_font("Fonts/fixed_font.tga",0,0);
	bool sair = false,muda_botao=false;
	al_flush_event_queue(win.event_queue);
	FILE *cmd = fopen("Comandos/cmd.txt","w");

	do {
		al_clear_to_color(PRETO);
		ALLEGRO_EVENT ev;
        al_wait_for_event(win.event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ) { // Guarda o local do ponteiro do mouse.
			mousex=ev.mouse.x;
			mousey=ev.mouse.y;
		}

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // Clicou no X.
			graphdeinit(win);
			sair = true;
			break ;
		} else if(ev.type == ALLEGRO_EVENT_KEY_UP) { // Soltou alguma tecla.
			switch(ev.keyboard.keycode) { // Os casos DOWN,LEFT,RIGHT,UP sao as setas, e tem que fazer o teu carinha andar. Tah meio bugado, mas funciona um pouco.
				case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break ;
                default: break;
			}
		} else {
	        if(muda_botao==true) {
	            sprintf(p[jogador_opcoes].botao_char[tipo_botao],"%c",editor_text(ev,win));
	            //sscanf(p[jogador_opcoes].botao_char[tipo_botao],"%d",&p[jogador_opcoes].botao_char_int[tipo_botao]);
	            p[jogador_opcoes].botao_char_int[tipo_botao]=auxilia_botao;
				//muda_botao=false;
	        }
	    	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
				exit(1);
			}

	        //editor_text(ev,win);
	        al_draw_text(font2,VERMELHO, 640/2,30,0,"controles:");
	        al_draw_text(font2,VERMELHO, 640/3,50,0,"seta acima:");
	        al_draw_text(font2,VERMELHO, 640/3,70,0,"seta abaixo:");
			al_draw_text(font2,VERMELHO, 640/3,90,0,"seta direita:");
			al_draw_text(font2,VERMELHO, 640/3,110,0,"seta esquerda:");
			al_draw_text(font2,VERMELHO, 640/3,130,0,"ATAQUE:");

	        for(int i=0;i<palavra;++i) {
				al_draw_textf( font2,VERDE, 640/2+i*10,300,0,"%c",edit[i]);
	        }
	        al_draw_textf( font2,VERDE, 640/2+0*10,300+30,0,"ix:%i %i %i %i",ALLEGRO_KEY_UP,ALLEGRO_KEY_DOWN,ALLEGRO_KEY_RIGHT,ALLEGRO_KEY_LEFT);
			//al_rest(5);

			for(int i=0;i<5;++i)
	        {
	            if(botao(p[jogador_opcoes].botao_char[i],(640/3)+150,(2*i+1)*10+50,ev)==1)
	            {
	                sprintf(edit,"%c",p[jogador_opcoes].botao_char[i]);
	                tipo_botao=i;
	                palavra=0;
	                muda_botao=true;
	            }
	        }

	        al_draw_textf( font2,VERDE,30,80,0,"jogador:   %d ",jogador_opcoes+1);
	        if(botao((char*)"<",110,30+1*50,ev)==1 && jogador_opcoes>0) {
	            jogador_opcoes-=1;
	        }
	        if(botao((char*)">",160,30+1*50,ev)==1 && jogador_opcoes<3) {
	            jogador_opcoes+=1;
	        }
	        if(botao((char*)"sair",640/2,400,ev)==1) {
	            sair=true;
	        }
			al_draw_textf(font2,VERDE_LIMAO,300,0,0,"JOGO do Neon %d      %d",ev.mouse.x,mousex); // Essas impressoes explicam porque o while n funciona.
			al_flip_display();
		}
	}while(!sair);
	//al_destroy_font(font);al_destroy_font(font2);


	/*for(int j=0;j<4;j++)
	{
		for(int i=0;i<5;i++)
		{
			fprintf(cmd,"%c  %d \n",p[j].botao_char[i],p[j].botao_char_int[i]);
	    }
	}*/
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<5;i++)
		{
			fprintf(cmd,"%s %d\n",p[j].botao_char[i],p[j].botao_char_int[i]);
			printf("%s %d\n",p[j].botao_char[i],p[j].botao_char_int[i]);
	    }
	}
	fclose(cmd);
	al_destroy_font(font2);
	return;
}

int abremenu(Window win,ALLEGRO_BITMAP *chars, Pessoa *p)
{
	ALLEGRO_FONT *font2 = al_load_font("Fonts/fixed_font.tga",0,0);

	char** opcoesmenu;
	int i,tamanho;
	ALLEGRO_COLOR cor_neon[4];

	opcoesmenu = (char**)malloc(sizeof(char)*10);
	for(i=0;i<10;i++)
		opcoesmenu[i] = (char*)malloc(sizeof(char)*20);
	opcoesmenu[0] = (char*)"Campanha";
	opcoesmenu[1] = (char*)"Load";
	opcoesmenu[2] = (char*)"Multiplayer";
	opcoesmenu[3] = (char*)"Comandos";
	opcoesmenu[4] = (char*)"Sair";

	bool sair = false;
	p[0].ataque=(char*) malloc(30*sizeof(char));
	for(int i=0;i<255;i++){
		edit[i]=0;
	}
	al_flush_event_queue(win.event_queue);

	do
	{
		al_clear_to_color(PRETO);
		ALLEGRO_EVENT ev;
        al_wait_for_event(win.event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ) // Guarda o local do ponteiro do mouse.
   		{
			mousex=ev.mouse.x;
			mousey=ev.mouse.y;
		}

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) { // Clicou no X.
			graphdeinit(win);
			exit(1);
		} else if(ev.type == ALLEGRO_EVENT_KEY_UP) { // Soltou alguma tecla.
			switch(ev.keyboard.keycode)
			{   // Os casos DOWN,LEFT,RIGHT,UP sao as setas, e tem que fazer o teu carinha andar. Tah meio bugado, mas funciona um pouco.
				case ALLEGRO_KEY_ESCAPE:
                     sair = true;
                     break;
                default: break;
			}
		} else {
			for(i=0;i<4;i++)
			{
				if(botao(p[i].nome,20,30+40*i,ev)==1)
				{
					if(p[i].comp==0)
					{
						p[i].comp = 1;
						sprintf(p[i].nome,"Comp");
					}
					else if(p[i].comp==1)
					{
						p[i].comp = 0;
						sprintf(p[i].nome,"Player %d",i+1);
					}
				}
				imprime_char(120,30+i*50,32,0,p[i].desx,p[i].desy,chars);
	    		if(botao((char*)"<",110,30+i*50,ev)==1)
	    		{
	    			p[i].desx-=96;
	    			if((p[i].desx<-32) && (p[i].desy >120))
					{
	                   p[i].desx=96;
	                    p[i].desy-=128;
	                }
	                if((p[i].desx<-32) && (p[i].desy <120))
					{
	                   p[i].desx=96;
	                    p[i].desy=128;
	                }
	            }
	            if((botao((char*)">",160,30+i*50,ev)==1))
	    		{
	    			p[i].desx+=96;
	    			if((p[i].desx>130) && (p[i].desy <120))
					{
	                    p[i].desx=0;
	                    p[i].desy+=128;
	                }
	                if((p[i].desx>130) && (p[i].desy >120))
					{
	                    p[i].desx=0;
	                    p[i].desy=0;
	                }
	        	}
	        	if(p[i].time==2)
	        	{
	        		cor_neon[i]=PIXEL(0,0,255);
	        	}else if(p[i].time==3)
	        	{
	        		cor_neon[i]=PIXEL(0,128,0);
	        	}else if(p[i].time==4)
	        	{
	        		cor_neon[i]=PIXEL(255,0,0);
	        	}else if(p[i].time==1)
	        	{
	        		cor_neon[i]=PIXEL(255,255,0);
	        	}
	        	al_draw_textf(font2,cor_neon[i],180,30+i*50,0,"%i",p[i].time);
	    		if(botao((char*)"<",170,30+i*50,ev)==1)
	    		{
	    			if((p[i].time>1) && (p[i].time<=4))
					{
	                   p[i].time--;
	                }
	            }
	            if((botao((char*)">",190,30+i*50,ev)==1))
	    		{
	    			if((p[i].time>=1) && (p[i].time<4))
					{
	                   p[i].time++;
	                }
	        	}
			}

			if(botao(opcoesmenu[0],350,30,ev)==1)
			{
				//al_destroy_font(font2);al_destroy_font(font);
				sair = true;
				return 1;
	        }
	        if(botao(opcoesmenu[1],355,50,ev)==1)
			{

	        }
	        if(botao(opcoesmenu[2],345,70,ev)==1)
			{

	        }
	        if(botao(opcoesmenu[3],345,90,ev)==1)
			{
	            opcoes(win,p);
	        }
	        if(botao(opcoesmenu[4],345,110,ev)==1)
			{
				sair = true;
				return 0;
	        }
			al_draw_textf(font2,VERDE_LIMAO,20,660,0,"x = %d ",p[0].desx);
			al_draw_textf(font2,VERDE_LIMAO,300,0,0,"JOGO do Neon %d      %d",ev.mouse.x,mousex); // Essas impressoes explicam porque o while n funciona.

			al_flip_display();
		}
	}while(!sair);
	al_destroy_font(font2);
}
