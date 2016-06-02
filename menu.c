#include "menu.h"

Window Win;
int mousex=0, mousey=0;
/*
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
/*	for(int j=0;j<4;j++)
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
*/
void imprime_menu(Botoes *botoes, int n_botoes, int mx, int my) {
/* Imprimir o menu eh uma operacao cara. Soh imprima quando ele mudar:
o jogador passar o mouse por cima de um botao ou clicar em um botao. */

    int i;

    al_clear_to_color(PRETO);

    //printf("Imprimindo com mx = %d e my = %d\n",mx, my);

    for(i=0; i<n_botoes; ++i) {
        botoes[i].imprime(botoes[i].hovering(mx,my));
    }

    al_flip_display();
}

int comeca_jogo() {
    return 1;
}

int fecha_jogo(void) {
    graphdeinit(Win);
    exit(0);
    return 0;
}

int abremenu(Window win,Pessoa *p,Sprite s)
{
	ALLEGRO_FONT *font2 = al_load_font("Fonts/fixed_font.tga",0,0);
    Win = win;

	char** opcoesmenu;
	int i,tamanho;
	ALLEGRO_COLOR cor_neon[4];

	opcoesmenu = (char**)malloc(sizeof(char*)*10);
	for(i=0; i<10; ++i)
		opcoesmenu[i] = (char*)malloc(sizeof(char)*20);

	strcpy(opcoesmenu[0], "Campanha");
	strcpy(opcoesmenu[0], "Load");
	strcpy(opcoesmenu[0], "Multiplayer");
	strcpy(opcoesmenu[0], "Comandos");
	strcpy(opcoesmenu[0], "Sair");

	bool sair = false;
	/*p[0].ataque=(char*) malloc(30*sizeof(char));
	for(int i=0;i<255;i++){
		edit[i]=0;
	}*/
	al_flush_event_queue(win.event_queue);

    int mx = 0, my = 0;

    Botoes botoes[NUM_BOTOES];
    bool oldHovering[NUM_BOTOES], newHovering[NUM_BOTOES], devoImprimir = false;
    for(i=0; i<NUM_BOTOES; ++i)
        oldHovering[i] = newHovering[i] = false;

    botoes[0].set_position(30,50);
    botoes[1].set_position(30,90);
    botoes[2].set_position(30,130);
    botoes[3].set_position(30,170);
    botoes[4].set_position(30,210);
    botoes[0].set_text("Jogar");
    botoes[1].set_text("Carregar");
    botoes[2].set_text("Multiplayer");
    botoes[3].set_text("Comandos");
    botoes[4].set_text("Sair");
    botoes[0].set_func(comeca_jogo);
    botoes[4].set_func(fecha_jogo);

    imprime_menu(botoes, NUM_BOTOES, mx, my);

    int retorno = 0;

    ALLEGRO_EVENT ev;
    do {
        al_wait_for_event(win.event_queue, &ev);
        switch (ev.type) {
            case ALLEGRO_EVENT_DISPLAY_CLOSE:
                //puts("Clicou no X");
			    graphdeinit(win);
    			exit(1);
                break ;
            case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                for(i=0; i<NUM_BOTOES; ++i) {
                    if(botoes[i].hovering(mx,my)) {
                        //printf("Clicou no botao %d\n",i);
                        retorno = botoes[i].execute();
                        if(retorno == 1) { // Começa jogo
                        	return 1;
                        }
                        imprime_menu(botoes, NUM_BOTOES, mx, my);
                    }
                }
                //puts("Clicou com o mouse");
                break ;
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                //puts("Soltou o mouse");
                break ;
            case ALLEGRO_EVENT_MOUSE_AXES:
			    mx = ev.mouse.x;
    			my = ev.mouse.y;
                for(i=0; i<NUM_BOTOES; ++i) {
                    newHovering[i] = botoes[i].hovering(mx,my);
                    if(oldHovering[i] != newHovering[i]) { // Se tava em cima do botao, tirou. Se tava fora, colocou em cima.
                        oldHovering[i] = newHovering[i];
                        devoImprimir = true;
                        //puts("Tirou ou colocou em/de cima de um botao");
                    }
                    if(devoImprimir) {
                        imprime_menu(botoes, NUM_BOTOES, mx, my);
                        devoImprimir = false;
                    }
                }
                //puts("Mexeu o mouse");
                break ;
        }
        if(retorno == 2) {
            //opcoes(win,p);
        }
    } while(!retorno);
	al_destroy_font(font2);
    return retorno;
/*
	ALLEGRO_EVENT ev;
	do
	{
        if(al_is_event_queue_empty(win.event_queue)) {
            puts("Event queue is empty.");
        }
		al_clear_to_color(PRETO);
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
				imprime_char(120,30+i*50,32,0,p[i].desx,p[i].desy,s);
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
*/
}
