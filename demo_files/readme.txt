ex demo_file :

#debut
cam {20,20,20} {-1,0,0} 			// cam origin direction
sphere {0,0,0} 1 0xFFFFFF 			// sphere origin rayon couleur
plan {0,0,0} {0,0,1} 0xFF00FF			// plan point normale couleur
cylindre {5,0,0} 1 6 {1,0,0} 0x0000FF		// cylindre origin rayon valeur_rot axe_rot couleur
cone {0,5,0} 6 {0,1,0} 0x00FF00 		// cone origin valeur_rot axe_rot couleur
#fin

pour que le fichier soit valide les coordonnees des point et des vecteurs doivent etre des entier (pas de ',' ni de '.') de plus elles doivent etre placees entre {}, separees par des ',' et sans ' '.
Concernant les rotation d'axe pour les cylindres et les cones, l axe final de tracE du cylindre/cone est une rotation de eZ->(0,0,1) [DANS LE REPERE INITIAL]  de M_PI/valeur_rot par rapport a axe_rot. Donc valeur_rot doit etre un entier NON NUL, positif ou negatif, on parcours ainsi tout les angles possible!
Les couleurs sont exprimees en hexa, lettres en majuscule, sensible casse!
