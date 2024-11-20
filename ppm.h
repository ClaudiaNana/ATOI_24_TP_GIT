#ifndef PPM_H
#define PPM_H

/**
 * @file ppm.h
 * @brief Fichier d'en-tête pour la gestion du format d'image PPM (Portable Pixmap).
 *
 * Ce fichier définit les structures et fonctions nécessaires pour créer, 
 * modifier et exporter des images au format PPM. Il permet de manipuler 
 * les pixels individuellement et de gérer des tableaux de pixels.
 */

/** 
 * @struct ppm_pixel
 * @brief Représente un pixel individuel dans une image PPM.
 *
 * Champs :
 * - r : Composante rouge du pixel (valeur entre 0 et 255).
 * - g : Composante verte du pixel (valeur entre 0 et 255).
 * - b : Composante bleue du pixel (valeur entre 0 et 255).
 */
struct ppm_pixel {
  unsigned char r; ///< Composante rouge du pixel.
  unsigned char g; ///< Composante verte du pixel.
  unsigned char b; ///< Composante bleue du pixel.
};

/**
 * @brief Définit la couleur d'un pixel.
 * 
 * @param px Pointeur vers la structure ppm_pixel.
 * @param r Valeur de la composante rouge (0-255).
 * @param g Valeur de la composante verte (0-255).
 * @param b Valeur de la composante bleue (0-255).
 */
static inline void ppm_setpixel(struct ppm_pixel *px, unsigned char r,
                                unsigned char g, unsigned char b) {
  px->r = r;
  px->g = g;
  px->b = b;
}

/**
 * @struct ppm_image
 * @brief Représente une image au format PPM.
 *
 * Champs :
 * - width : Largeur de l'image en pixels.
 * - height : Hauteur de l'image en pixels.
 * - px : Pointeur vers un tableau de structures ppm_pixel représentant les pixels de l'image.
 */
struct ppm_image {
  unsigned int width; ///< Largeur de l'image.
  unsigned int height; ///< Hauteur de l'image.
  struct ppm_pixel *px; ///< Pointeur vers le tableau des pixels.
};

/**
 * @brief Initialise une structure ppm_image avec les dimensions spécifiées.
 * 
 * Alloue la mémoire pour le tableau de pixels et définit les dimensions de l'image.
 * 
 * @param im Pointeur vers la structure ppm_image à initialiser.
 * @param w Largeur de l'image.
 * @param h Hauteur de l'image.
 * @return 0 si succès, -1 si échec.
 */
int ppm_image_init(struct ppm_image *im, int w, int h);

/**
 * @brief Libère la mémoire allouée pour une structure ppm_image.
 * 
 * Libère le tableau de pixels et réinitialise les dimensions à zéro.
 * 
 * @param im Pointeur vers la structure ppm_image à libérer.
 * @return 0 si succès, -1 si échec.
 */
int ppm_image_release(struct ppm_image *im);

/**
 * @brief Définit la couleur d'un pixel dans une ppm_image.
 * 
 * @param im Pointeur vers la structure ppm_image.
 * @param x Coordonnée X du pixel (indexé à partir de 0).
 * @param y Coordonnée Y du pixel (indexé à partir de 0).
 * @param r Valeur de la composante rouge (0-255).
 * @param g Valeur de la composante verte (0-255).
 * @param b Valeur de la composante bleue (0-255).
 */
static inline void ppm_image_setpixel(struct ppm_image *im, int x, int y,
                                      unsigned char r, unsigned char g,
                                      unsigned char b) {
  struct ppm_pixel *px = im->px + im->width * y + x;
  ppm_setpixel(px, r, g, b);
}

/**
 * @brief Écrit le contenu d'une ppm_image dans un fichier.
 * 
 * Exporte l'image au format PPM en l'enregistrant dans le chemin spécifié.
 * 
 * @param im Pointeur vers la structure ppm_image.
 * @param path Chemin du fichier où exporter l'image.
 * @return 0 si succès, -1 si échec.
 */
int ppm_image_dump(struct ppm_image *im, char *path);

#endif /* PPM_H */
