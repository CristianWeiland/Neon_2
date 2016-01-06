# nome da biblioteca, usado para gerar o arquivo libnome.a
LIBNOME = neon

# nome da biblioteca 2, usado para gerar o arquivo libnome2.a
LIBNOME2 = grafico

# nome da biblioteca 3, usado para gerar o arquivo libnome3.a
LIBNOME3 = imprime

# nome da biblioteca 4, usado para gerar o arquivo libnome4.a
LIBNOME4 = colisao

# nome da biblioteca 5, usado para gerar o arquivo libnome5.a
LIBNOME5 = keys

# nome da biblioteca 6, usado para gerar o arquivo libnome6.a
LIBNOME6 = ia

# nome da biblioteca 7, usado para gerar o arquivo libnome7.a
LIBNOME7 = magia

# nome da biblioteca 7, usado para gerar o arquivo libnome7.a
LIBNOME8 = map

# nome de todas as bibliotecas
LIBS = neon.a grafico.a imprime.a colisao.a keys.a ia.a magia.a map.a

# nome do arquivo header com as declarações da biblioteca
INCFILES = neon.h Fase1.h grafico.h menu.h keys.h imprime.h colisao.h ia.h magia.h map.h

# modulos que contém as funções da biblioteca
LIBOBJ = neon.o grafico.o menu.o keys.o imprime.o colisao.o ia.o magia.o map.o

# diretorio base onde estarão os diretórios de biblioteca
PREFIX = ./

# diretorio onde ficam os .h's de bibliotecas
INCDIR = $(PREFIX)include

# diretorio onde ficam bibliotecas
LIBDIR = $(PREFIX)lib

# diretorio onde fica o arquivo executavel
EXECDIR = $(PREFIX)bin/

ALLEGRO = `pkg-config --libs allegro-5.0 allegro_image-5.0 allegro_primitives-5.0 allegro_font-5.0 allegro_ttf-5.0 allegro_dialog-5.0 allegro_audio-5.0`

LIBDIR_GRAPH = /home

INCDIR_GRAPH = /home

INCS = -I $(INCDIR) -I $(INCDIR_GRAPH)

LIBS = -L $(LIBDIR) -L $(LIBDIR_GRAPH)


CC = g++ -g
AR = ar -rcu
INSTALL = install


all : install neon

%.o : %.c %.h
	$(CC) -c $(INCS) $<

#%.a : $(LIBOBJ)
#	$(AR) $@ $?
#	ranlib $@

lib$(LIBNOME).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

lib$(LIBNOME2).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

lib$(LIBNOME3).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

lib$(LIBNOME4).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

lib$(LIBNOME5).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

lib$(LIBNOME6).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

lib$(LIBNOME7).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

lib$(LIBNOME8).a : $(LIBOBJ)
	$(AR) $@ $?
	ranlib $@

install : lib$(LIBNOME).a lib$(LIBNOME2).a lib$(LIBNOME3).a lib$(LIBNOME4).a lib$(LIBNOME5).a lib$(LIBNOME6).a lib$(LIBNOME7).a lib$(LIBNOME8).a Fase1.h
	$(INSTALL) $^ $(LIBDIR)
	$(INSTALL) $(INCFILES) $(INCDIR)

neon : lib$(LIBNOME5).a lib$(LIBNOME4).a lib$(LIBNOME3).a lib$(LIBNOME2).a lib$(LIBNOME).a $(INCFILES)
	$(CC) $(INCS) $(LIBS) -o $(EXECDIR)$@ $@.c -l$(LIBNOME) -l$(LIBNOME2) -l$(LIBNOME3) -l$(LIBNOME4) -l$(LIBNOME5) -l$(LIBNOME6) -l$(LIBNOME7) -l$(LIBNOME8) -lgrafico $(ALLEGRO)

limpa:
	@echo "Limpando sujeira ..."
	@rm -f *% *.bak *~

faxina:   limpa
	@echo "Limpando tudo ..."
	@rm -rf *.o lib$(LIBNOME).*
