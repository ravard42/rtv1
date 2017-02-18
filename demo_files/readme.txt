ex demo_file :

#debut
cam {20,20,20} {-1,0,0} 				// cam origin direction
sphere {0,0,0} 1 0xFFFFFF 0				// sphere  origin rayon couleur light
plan {0,0,0} {0,0,1} 2 {1,0,0} 5 0xFF00FF {1,5,42}	// plan origin normale valeur_rot axe_rot tranlation_axe_rot couleur borne
cylindre {5,0,0} 1 6 {1,0,0} 0x0000FF {1,-5,5} 0	// cylindre origin rayon valeur_rot axe_rot couleur borne light
cone {0,5.555,0} 6 {0,1,0} 0x00FF00 {0,0,0} 		// cone origin valeur_rot axe_rot couleur borne
#fin

pour que le fichier soit valide :

1) les coordonnees des point et des vecteurs doivent etre placees entre {}, separees par des ',' et sans espace.

2) Concernant les rotation d'axe pour les cylindres et les cones, l axe final de tracE du cylindre/cone est une rotation de eZ->(0,0,1) [DANS LE REPERE INITIAL]  de M_PI/valeur_rot par rapport a axe_rot. Donc valeur_rot doit etre un entier positif ou negatif (si nul on ne fait pas la division, l'axe reste inchangE), on parcours ainsi tout les angles possible!

3) Les couleurs sont exprimees en hexa, lettres en majuscule, sensible casse!

4) Pour les bornes, si borne[0] est nul pas de borne, sinon :
- pour les plan, borne[1] represente la distance a l 'origine du plan, c'est a dire que si le point (du plan etendu) en question se trouve a une distance de l'origine du plan <= borne[1] alors il appartient a l'objet (plan borne) sinon il est en dehors.
NB : borne[2] n'est pas utilisE mais reste implementee par soucis de compatibilitE avec les fonctions de parsing.	   
- pour les cylindres et cones la borne negative vaut borne[1] et la borne positive borne[2] (par rapport a l axe de l'objet).

5) pour le plan si valeur_rot != 0 alors l'objet se comporte comme les cylindre et les cones avec la nouvelle normale calculee normee et rangE dans e->o->p->nor en faisant une rotation de eZ->(0,0,1) [REPERE INITIAL]  de M_PI/valeur_rot par rapport a axe_rot de plus l'origine sera translatee de tranlsation_axe_rot / a cette nouvelle normale et la normale inversee si la valeur de translation est negative.

6) la valeur light pour les sphere et les cylindre est en general toujours a 0 qui signifie qu'il s agit bien d'un objet. 
- pour les sphere si  la valeur est a 1 alors l'objet est totalement transparent et est ignorE au moment du calcul des ombres, ca normal devra egalement etre inversee pour que la/les lumieres placee en son centre puissent la faire apparaitre. 
- Pour les cylindre si la valeur est a 1 alors il revelera totalement ses couleurs quelaue soit l eclairage, par contre il sera bien considerer au moment du calcul des eventuelles ombres portee sur l exterieur. 
