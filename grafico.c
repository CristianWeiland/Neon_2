#include "grafico.h"

Window graphinit(FILE* errext)
{
  int depth, res, i;
  Window win = {NULL, NULL, NULL, {0, 0, 0, 0}};
  
  if(!al_init()) {
    fprintf(errext,"Erro ao abrir al_init");fclose(errext);exit(1); }
  if(!al_init_image_addon()) {
    fprintf(errext,"Erro ao abrir al_init_image_addon");fclose(errext);exit(1); }
  if(!al_init_primitives_addon()) {
    fprintf(errext,"Erro ao abrir al_init_primitives_addon");fclose(errext);exit(1); }
  if(!al_init_native_dialog_addon()) {
    fprintf(errext,"Erro ao abrir al_init_native_dialog_addon");fclose(errext);exit(1); }
  al_init_font_addon();
  if(!al_install_audio()) {
    fprintf(errext,"Erro ao abrir al_install_audio");fclose(errext);exit(1); }
  //al_init_acodec_addon();
  //al_init_timeout(win.timeout,1.0);
  
  /* Define Janela */
/*

  puts("Escolha uma resolução de janela:");
  for (i=0; i < al_get_num_display_modes(); ++i)
    {
      al_get_display_mode(i, &win.disp_data);
      if (win.disp_data.refresh_rate == 60) // 60 Hz
	printf("(%d): %d %d %d %d\n", i, win.disp_data.width, win.disp_data.height, 
	       win.disp_data.format, win.disp_data.refresh_rate);
    }

  if (i) {  
     scanf("%d", &i);
     getchar();
  }
  else {
     fprintf(stderr, "\nNao eh possivel definir um display para o Allegro.\n\n");
     exit(2);
  }
  
  al_get_display_mode(i, &win.disp_data);
  al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE); // ALLEGRO_FULLSCREEN
                                                                  // ALLEGRO_FRAMELESS
*/

  win.disp_data.width = 1024;
  win.disp_data.height = 700;
  win.disp_data.refresh_rate = 60;
  win.display = al_create_display(win.disp_data.width, win.disp_data.height);
  if(!win.display) {
  	fprintf(errext,"Erro ao abrir display");fclose(errext);exit(1); }
  
  al_install_mouse();
  al_install_keyboard();

  win.timer = al_create_timer(1.0 / win.disp_data.refresh_rate);
  win.event_queue = al_create_event_queue();
  
  al_register_event_source(win.event_queue, al_get_display_event_source(win.display));
  al_register_event_source(win.event_queue, al_get_mouse_event_source());
  al_register_event_source(win.event_queue, al_get_keyboard_event_source());
  al_register_event_source(win.event_queue, al_get_timer_event_source(win.timer));
  
  al_clear_to_color(PRETO);
  al_flip_display();
  al_start_timer(win.timer);
  
  return (win);
  
}

void graphdeinit(Window win)
{
  al_destroy_timer(win.timer);
  al_destroy_event_queue(win.event_queue);
  al_destroy_display(win.display);
}

bool is_inside_bitmap (BITMAP2 img, int x, int y)
{
  return (x >= img.x && x < img.x+img.w &&
	  y >= img.y && y < img.y+img.h );
}

Sprite init_sprites(FILE *errext) {
    int i;
    Sprite s;

    s.neons = (ALLEGRO_BITMAP**) malloc(4*sizeof(ALLEGRO_BITMAP*));
    s.iceballs = (ALLEGRO_BITMAP**) malloc(4*sizeof(ALLEGRO_BITMAP*));
    s.fireballs = (ALLEGRO_BITMAP**) malloc(4*sizeof(ALLEGRO_BITMAP*));

    s.chars = al_load_bitmap("Imgs/chars.bmp"); // Obs: Cada imagem de cada char eh 32x32
    if(!(s.chars)) {
        fprintf(errext,"Falha ao abrir a imagem chars.");
        fclose(errext);
        exit(1);
    }

    s.chars_congelados = al_load_bitmap("Imgs/chars_congelados.bmp"); // Obs: Cada imagem de cada char eh 32x32
    if(!(s.chars_congelados)) {
        fprintf(errext,"Falha ao abrir a imagem chars_congelados.");
        fclose(errext);
        exit(1);
    }

    s.tiles = al_load_bitmap("Imgs/tiles.bmp");
    if(!(s.tiles)) {
        fprintf(errext,"Falha ao abrir a imagem tiles.");
        fclose(errext);
        exit(1);
    }

    s.bar = al_load_bitmap("Imgs/bar.bmp");
    if(!(s.bar)) {
        printf("Falha ao abrir a imagem bar! O problema foi: %s\n",strerror(errno));
        exit(1);
    }

    s.healthbar = al_load_bitmap("Imgs/healthbar.bmp");
    if(!(s.healthbar)) {
        printf("Falha ao abrir a imagem healthbar! O problema foi: %s\n",strerror(errno));
        exit(1);
    }

    s.energybar = al_load_bitmap("Imgs/energybar.bmp");
    if(!(s.energybar)) {
        printf("Falha ao abrir a imagem energybar! O problema foi: %s\n",strerror(errno));
        exit(1);
    }

    s.dead = al_load_bitmap("Imgs/dead.bmp");
    if(!(s.dead)) {
        printf("Falha ao abrir a imagem dead! O problema foi: %s\n",strerror(errno));
        exit(1);
    }

    s.explosion = al_load_bitmap("Imgs/Explo.bmp");
    if(!(s.explosion)) {
        fprintf(errext,"Falha ao abrir a imagem explo.");
        fclose(errext);
        exit(1);
    }

    // s.animacao_flash = al_load_bitmap("Imgs/smoke.bmp");
    s.animacao_flash = al_load_bitmap("Imgs/Explo.bmp");
    if(!(s.animacao_flash)) {
        fprintf(errext,"Falha ao abrir a imagem smoke.");
        fclose(errext);
        exit(1);
    }

    s.neons[0] = al_load_bitmap("Imgs/neonamarelo.bmp");
    if(!s.neons[0]) {
        fprintf(errext,"Falha ao abrir a imagem s.neons[0].");
        fclose(errext);
        exit(1);
    }

    s.neons[1] = al_load_bitmap("Imgs/neonazul.bmp");
    if(!s.neons[1]) {
        fprintf(errext,"Falha ao abrir a imagem s.neons[1].");
        fclose(errext);
        exit(1);
    }

    s.neons[2] = al_load_bitmap("Imgs/neonverde.bmp");
    if(!s.neons[2]) {
        fprintf(errext,"Falha ao abrir a imagem s.neons[2].");
        fclose(errext);
        exit(1);
    }

    s.neons[3] = al_load_bitmap("Imgs/neonvermelho.bmp");
    if(!s.neons[3]) {
        fprintf(errext,"Falha ao abrir a imagem s.neons[3].");
        fclose(errext);
        exit(1);
    }

    s.fireballs[0] = al_load_bitmap("Imgs/Fireballc.bmp");
    if(!s.fireballs[0]) {
        fprintf(errext,"Falha ao abrir a imagem s.fireballs[0].");
        fclose(errext);
        exit(1);
    }

    s.fireballs[1] = al_load_bitmap("Imgs/Fireballd.bmp");
    if(!s.fireballs[1]) {
        fprintf(errext,"Falha ao abrir a imagem s.fireballs[1].");
        fclose(errext);
        exit(1);
    }

    s.fireballs[2] = al_load_bitmap("Imgs/Fireballe.bmp");
    if(!s.fireballs[2]) {
        fprintf(errext,"Falha ao abrir a imagem s.fireballs[2].");
        fclose(errext);
        exit(1);
    }

    s.fireballs[3] = al_load_bitmap("Imgs/Fireballb.bmp");
    if(!s.fireballs[3]) {
        fprintf(errext,"Falha ao abrir a imagem s.fireballs[3].");
        fclose(errext);
        exit(1);
    }

    s.iceballs[0] = al_load_bitmap("Imgs/Iceballc.bmp");
    if(!s.iceballs[0]) {
        fprintf(errext,"Falha ao abrir a imagem s.iceballs[0].");
        fclose(errext);
        exit(1);
    }

    s.iceballs[1] = al_load_bitmap("Imgs/Iceballd.bmp");
    if(!s.iceballs[1]) {
        fprintf(errext,"Falha ao abrir a imagem s.iceballs[1].");
        fclose(errext);
        exit(1);
    }

    s.iceballs[2] = al_load_bitmap("Imgs/Iceballe.bmp");
    if(!s.iceballs[2]) {
        fprintf(errext,"Falha ao abrir a imagem s.iceballs[2].");
        fclose(errext);
        exit(1);
    }

    s.iceballs[3] = al_load_bitmap("Imgs/Iceballb.bmp");
    if(!s.iceballs[3]) {
        fprintf(errext,"Falha ao abrir a imagem s.iceballs[3].");
        fclose(errext);
        exit(1);
    }

    al_convert_mask_to_alpha(s.bar,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.dead,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.tiles,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.chars,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.explosion,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.healthbar,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.energybar,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.animacao_flash,al_map_rgb(255,0,255));
    al_convert_mask_to_alpha(s.chars_congelados,al_map_rgb(255,0,255));
    for(i=0;i<4;i++) {
        al_convert_mask_to_alpha(s.neons[i],al_map_rgb(255,0,255));
        al_convert_mask_to_alpha(s.fireballs[i],al_map_rgb(255,0,255));
        al_convert_mask_to_alpha(s.iceballs[i],al_map_rgb(255,0,255));
    }

    return s;
}