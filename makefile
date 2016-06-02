CC = g++
CFLAGS = -g

INCL = -I./

DEPS = Fase1.h colisao.h grafico.h ia.h imprime.h keys.h magia.h map.h menu.h neon.h

OBJ = neon.o grafico.o imprime.o colisao.o keys.o ia.o magia.o map.o menu.o

ALLEGRO = `pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_dialog-5.0 allegro_audio-5.0`

neon: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(ALLEGRO)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCL)

clean:
	rm -f $(OBJ) core

limpa:
	@echo "Limpando sujeira ..."
	@rm -f *% *.bak *~

faxina:   limpa
	@echo "Limpando tudo ..."
	@rm -rf *.o lib$(LIBNOME).*
