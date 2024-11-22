Introduction
Le projet de Kevin consiste à générer une image de la fractale de Mandelbrot et à l'exporter au format PPM. Cependant, le code avait des erreurs empêchant la compilation, et une fonctionnalité de couleur avait été implémentée dans une branche séparée mais ne fonctionnait pas correctement. Le but de ce TP est de réparer ces erreurs, de restaurer la génération correcte de l’image de Mandelbrot et d'ajouter la couleur à l'image.

Exercice 1 : Structure et compréhension du code
Configuration de Git : Avant de commencer,on a configuré mes compte Git pour que nos commits soient associés à nos noms et à nos adresse e-mail.

Structure du code : Le projet était composé de plusieurs fichiers. Voici leur rôle :

mandel.c : C'est le fichier principal où la fractale de Mandelbrot est générée. Il initialise l'image, effectue les calculs pour chaque pixel, et génère l'image en niveaux de gris.
ppm.c et ppm.h : Ces fichiers sont utilisés pour manipuler les images au format PPM. ppm.c contient les fonctions pour initialiser une image, y insérer des pixels, et exporter l’image au format PPM.
Makefile : Il contient les règles pour compiler le projet. Le fichier Makefile est responsable de la compilation de mandel.c et de la création des bibliothèques partagées, ainsi que de la gestion des dépendances.                                                                                                                                                                                     Exercice 2 : Réparer le code et se l’approprier
Correction du code de mandel.c et du Makefile : Le code initial de mandel.c ne compilait pas à cause de plusieurs erreurs :

L’erreur principale était une référence indéfinie à la fonction cabs pour calculer le module d’un nombre complexe. Cette fonction fait partie de la bibliothèque complex.h, et j'ai donc ajouté l'inclusion de cette bibliothèque.
Le Makefile avait aussi besoin d'être corrigé pour lier correctement la bibliothèque mathématique libm. J'ai ajouté -lm dans le Makefile pour résoudre cette erreur.
Explication du code de mandel.c : Le fichier mandel.c génère une image de la fractale de Mandelbrot en suivant les étapes suivantes :

Initialisation de l'image : L'image est créée en utilisant la fonction ppm_image_init de ppm.h.
Calcul de Mandelbrot : Pour chaque pixel, les coordonnées complexes sont calculées avec les fonctions cx() et cy(), et la fractale est calculée en utilisant l'itération de la formule de Mandelbrot.
Coloration en niveaux de gris : Une échelle de gris est utilisée pour chaque pixel en fonction du nombre d’itérations avant que cabs(z) dépasse une certaine valeur.
Exportation de l’image : L'image est ensuite enregistrée au format PPM avec la fonction ppm_image_dump.                                                                                                                                               Exercice 3 : Ajouter la couleur
Ramener la branche color_support au-dessus de master : J'ai utilisé git rebase pour ramener la branche color_support au-dessus de master. Cela permet d'intégrer les modifications de la branche master tout en gardant les changements de la branche color_support.

Fusion des branches : Après avoir résolu les éventuels conflits,on a fusionné la branche color_support dans master. Cela a permis de conserver les modifications sur la couleur tout en intégrant la dernière version du code principal.

Ajouter la couleur : La modification principale dans mandel.c pour ajouter la couleur consiste à calculer les composantes RGB en fonction des itérations et à utiliser ces valeurs pour colorier les pixels de l’image.

Exercice 4 : Sauver cela ailleurs
Choix du dépôt distant :on a choisi de créer un dépôt GitHub pour héberger le projet. Cela permet une gestion centralisée du code et facilite le travail collaboratif. Pour créer un dépôt sur GitHub, on a suivi ces étapes :

Créer un dépôt public  sur GitHub.
Copier l’URL du dépôt cr
Envoyer le travail sur le dépôt distant :on  utilisé git remote add pour ajouter le dépôt distant GitHub, puis on a poussé les branches master et color_support vers ce dépôt.
