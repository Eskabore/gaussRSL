CC = gcc
CFLAGS = -Wall -pedantic
LDFLAGS = -lsx
SRCS = main.c vue.c callbacks.c data.c matrice.c matriceC.c vecteur.c liste.c


EXEC = main
OBJS = $(SRCS:.c=.o)


all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS)

main.o: data.h vue.h
vue.o: vue.h data.h callbacks.h
callbacks.o: data.h callbacks.h vue.h
data.o: matrice.h matriceC.h vecteur.h data.h liste.h
matrice.o: matrice.h
vecteur.o: vecteur.h
matriceC.o: matriceC.h liste.h
liste.o: liste.h


%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)



.PHONY: all clean

clean:
	rm -rf *.o $(EXEC)
