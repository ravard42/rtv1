ex demo_file :

#debut
cam origin:{20,20,20} direction:{-1,0,0} 				
light origin:{0,0,0} couleur:0xFFFFFF id:1					
sphere origin:{0,0,0} trans_val:5 trans_dir:{1,1,1} rayon:1 couleur:0xFFFFFF luminosite:1 id_light:1 ombre:1
plan origin:{0,0,0} trans_val:5 trans_dir:{1,0,1} rot_val:2 rot_dir:{1,0,0} trans_val_axe:5 couleur:0xFF00FF luminosite:1 borne:{1,5,42} ombre:1
cylindre origin:{5,0,0} trans_val:5 trans_dir:{0,0,0} rot_val:6 rot_dir:{1,0,0} rayon:1 couleur:0x0000FF luminosite:1 borne:{1,-5,5} id_light:42 ombre:0	
cone origin:{0,5.555,0} trans_val:5 trans_dir:{0,0,0} rot_val:6 rot_dir:{0,1,0} couleur:0x00FF00 luminosite:1 borne:{0,0,0} ombre:1
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

6) la valeur id_light pour les sphere et light pour les cylindre est en general toujours a 0 qui signifie qu'il s agit d'un objet fait de matiere.. 
- pour les sphere si  la valeur est !0 alors l'objet est  associE a la lumiere ayant le meme id . cela signie qu'elle est consideree comme transparente pour sa lumiere associE ( rem : la sphere laissera passer uniquement sa lumiere) et ca normal sera inversee pour que la lumiere placee en son centre puissent la faire apparaitre. (remarque : le cosinus de l'angle vaudra toujours 1 donc eclairage maximal).
de plus si l'id > 42, la sphere laisse egalement passer les autres lumiere. (pas d'ombre!! utile pour lune et soleil) 
- Un cylindre contrairement a la sphere pourra avoir plusieurs lampes associees et sera par defaut insensible aux eclairage exterieur. (pas d 'ombre ni variation de lumiere) 
Son id le reliant a ses lampes devra necessairement valoir 42. 
!=42 <=> 0  pour les cylindre (enfin plutot le cylindre du coup, un seul tube de lumiere par map c est deja assez la merde comme ca ;) )
