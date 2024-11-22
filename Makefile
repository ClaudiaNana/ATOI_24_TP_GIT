CC=gcc
CFLAGS=-O3 -g
LDFLAGS=

TARGETS=test mandel

all: $(TARGETS)

# Compilation de la bibliothèque partagée libppm.so
libppm.so: ppm.o
	$(CC) $(CFLAGS) -fpic -shared ppm.o -o libppm.so

# Compilation du fichier ppm.o
ppm.o: ppm.c ppm.h
	$(CC) $(CFLAGS) -fpic -c ppm.c -o ppm.o

# Compilation de l'exécutable test
test: main.c libppm.so
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -lppm -L. -o $@

# Compilation de l'exécutable mandel
mandel: mandel.c libppm.so
	$(CC) $(CFLAGS) $(LDFLAGS) mandel.c -lppm -L. -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(TARGETS) *.o *.so
