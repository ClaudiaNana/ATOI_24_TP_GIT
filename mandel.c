#include <stdio.h>
#include <complex.h>
#include <math.h>
#include <stdlib.h>
#include "ppm.h"

#define TRSH 2.0
#define ITER 1024ull

#define SIZEX 1500
#define SIZEY 1500

double cx(int x)
{
    static const double qx = 3.0 / (double)SIZEX;
    return -2.0 +  x * qx;
}

double cy(int y)
{
    static const double qy = 2.0 / (double)SIZEY;
    return -1.0 + y * qy;
}

int main(int argc, char *argv[])
{
    struct ppm_image im;
    if (ppm_image_init(&im, SIZEX, SIZEY) != 0) {
        fprintf(stderr, "Error initializing image\n");
        return EXIT_FAILURE;
    }

    int i, j;
    double colref = 255.0 / log(ITER);

    for (i = 0; i < SIZEX; ++i) {
        for (j = 0; j < SIZEY; ++j) {

            unsigned long int iter = 0;

            double complex c = cx(i) + cy(j) * I;
            double complex z = 0;

            while (iter < ITER)
            {
                double mod = cabs(z);

                if (TRSH < mod) {
                    break;
                }

                z = z*z + c;
                iter++;
            }

            // Calcul des couleurs à partir du nombre d'itérations
            unsigned char red = (iter * 255) / ITER;
            unsigned char green = (iter * 255) / (ITER / 2);
            unsigned char blue = (iter * 255) / (ITER / 3);

            ppm_image_setpixel(&im, i, j, red, green, blue);
        }
    }

    ppm_image_dump(&im, "mandelbrot.ppm");
    ppm_image_release(&im);

    return 0;
}
