CC=gcc
CFLAGS=-O3 -g

TARGET=test mandel

all: $(TARGET)

# Crée une bibliothèque partagée pour gérer les images PPM
libppm.so : ppm.c
	$(CC) $(CFLAGS) -fpic -shared $^ -o $@

# Crée le programme de test avec libppm.so
test: main.c libppm.so
	$(CC) $(CFLAGS) $(LDFLAGS) main.c -lppm -L. -o $@

# Crée le programme Mandelbrot avec libppm.so
mandel: mandel.c libppm.so
	$(CC) $(CFLAGS) $(LDFLAGS) mandel.c -lppm -L. -o $@

# Nettoie les fichiers binaires et les bibliothèques partagées
clean:
	rm -fr $(TARGET) *.so
