ex demo_file :

#debut
cam {-20,5,5} {-1,0,0} 		// cam origin direction
sphere {0,0,0} 1 0xFFFFFF 	// sphere origin rayon couleur
plan {0,0,0} {0,0,1} 0x888888	// plan point normale couleur
cylindre			// a revoir 4 param max norme ?
cone				// a revoir 4 param max norme ?
#fin

pour que le fichier soit valide les coordonnees des point et des vecteurs doivent etre des entier (pas de ',' ni de '.') de plus elles doivent etre placees entre {}, separees par des ',' et sans ' '.
Les couleurs sont exprimees en hexa, lettres en majuscule, sensible casse!
