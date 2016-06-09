ALLEGRO = `pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_dialog-5.0 allegro_audio-5.0`

OBJ = faz_isom.o

CC = gcc
CFLAGS = -Wall -g

faz_isom: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(ALLEGRO)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *.o core faz_isom