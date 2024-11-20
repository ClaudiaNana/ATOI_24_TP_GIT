              EXERCICE 1 : STRUCTURE ET COMPREHENSION DU CODE

                              TP_GIT :

         EXO 1 : structure et compréhension du code

1.      claudia@claudia-VirtualBox:~/Bureau/TP_GIT/ATOI_24_TP_GIT$ git config --global user.name "claudia"
        claudia@claudia-VirtualBox:~/Bureau/TP_GIT/ATOI_24_TP_GIT$ git config --global user.email "nanaclaudia902@gmail.com"
        claudia@claudia-VirtualBox:~/Bureau/TP_GIT/ATOI_24_TP_GIT$ git config --global user.name "Asmae"
        claudia@claudia-VirtualBox:~/Bureau/TP_GIT/ATOI_24_TP_GIT$ git config --global user.email  "asmaeelfehri@gmail.com"

2.      ppm.c  : Le code manipule cette image en allouant et libérant de la mémoire, puis en enregistrant l'image dans un fichier PPM binaire.
        ppmc.h : Ce fichier d'en-tête définit les structures et les fonctions nécessaires pour manipuler des images au format PPM.
                ce fichier permet de créer, manipuler et sauvegarder des images PPM sim

        mandel.c :Le programme génère une image représentant l’ensemble de Mandelbrot sous forme de niveaux de gris. Chaque pixel
                 de l'image correspond à un point du plan complexe, et l'intensité de chaque pixel est déterminée par le nombre d'itérations
                 avant que le point ne dépasse le seuil TRSH
        makefile : le Makefile gèrer la compilation d'testet mandel, utlibppm.so

3.      Documentation du header ppm.h
