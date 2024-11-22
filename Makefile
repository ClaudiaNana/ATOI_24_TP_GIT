CC=gcc
CFLAGS=-O3 -g
LDFLAGS=-lm  # Ajoutez cette ligne pour lier la bibliothèque mathématique

TARGET=mandel

all: $(TARGET)

mandel: mandel.c libppm.so
        $(CC) $(CFLAGS) $(LDFLAGS) mandel.c -lppm -L. -o $@

clean:
        rm -fr $(TARGET) *.so

