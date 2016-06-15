ALLEGRO = `pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_dialog-5.0 allegro_audio-5.0`

OBJ = main.o

CC = g++
CFLAGS = -Wall -g

cria_matriz: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(ALLEGRO)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o core cria_matriz
