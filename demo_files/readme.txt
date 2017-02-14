ex demo_file :

#debut
cam {20,20,20} {-1,0,0} 			// cam origin direction
sphere {0,0,0} 1 0xFFFFFF 			// sphere origin rayon couleur
plan {0,0,0} {0,0,1} 0xFF00FF			// plan point normale couleur
cylindre {5,0,0} 1 6 {1,0,0} 0x0000FF {1,-5,5}	// cylindre origin rayon valeur_rot axe_rot couleur borne
cone {0,5,0} 6 {0,1,0} 0x00FF00 {0,0,0} 	// cone origin valeur_rot axe_rot couleur borne
#fin

pour que le fichier soit valide les coordonnees des point et des vecteurs doivent etre des entier (pas de ',' ni de '.') de plus elles doivent etre placees entre {}, separees par des ',' et sans espace.
Concernant les rotation d'axe pour les cylindres et les cones, l axe final de tracE du cylindre/cone est une rotation de eZ->(0,0,1) [DANS LE REPERE INITIAL]  de M_PI/valeur_rot par rapport a axe_rot. Donc valeur_rot doit etre un entier positif ou negatif (si nul on ne fait pas la division, l'axe reste inchangE), on parcours ainsi tout les angles possible!
Les couleurs sont exprimees en hexa, lettres en majuscule, sensible casse!
Pour les bornes, si borne[0] est nul pas de borne, sinon la borne negative vaut borne[1] et la borne positive borne[2].
