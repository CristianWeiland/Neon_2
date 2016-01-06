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

# nome de todas as bibliotecas
LIBS = neon.a grafico.a imprime.a colisao.a keys.a

# nome do arquivo header com as declarações da biblioteca
INCFILES = neon.h Fase1.h grafico.h menu.h keys.h imprime.h colisao.h

# modulos que contém as funções da biblioteca
LIBOBJ = neon.o grafico.o menu.o keys.o imprime.o colisao.o

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

install : lib$(LIBNOME).a lib$(LIBNOME2).a lib$(LIBNOME3).a lib$(LIBNOME4).a lib$(LIBNOME5).a  Fase1.h
	$(INSTALL) $^ $(LIBDIR)
	$(INSTALL) $(INCFILES) $(INCDIR)

neon : lib$(LIBNOME5).a lib$(LIBNOME4).a lib$(LIBNOME3).a lib$(LIBNOME2).a lib$(LIBNOME).a $(INCFILES)
	$(CC) $(INCS) $(LIBS) -o $(EXECDIR)$@ $@.c -l$(LIBNOME) -l$(LIBNOME2) -l$(LIBNOME3) -lgrafico $(ALLEGRO)

limpa:
	@echo "Limpando sujeira ..."
	@rm -f *% *.bak *~

faxina:   limpa
	@echo "Limpando tudo ..."
	@rm -rf *.o lib$(LIBNOME).*
