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
