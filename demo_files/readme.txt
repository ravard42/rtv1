affectation possible pour les differents objet:

cam : {origin dir}
sphere : {origin rayon tr tr_dir couleur lum ombre id_light}
plan : {origin tr tr_dir rot rot_dir tr_nor couleur lum ombre borne}
cylindre : {origin tr tr_dir rot rot_dir rayon couleur lum ombre borne id_light}
cone : {origin tr tr_dir rot rot_dir couleur lum ombre borne}
light : {origin tr tr_dir couleur id}

valeurs par defaut:
par defaut les origin sont placee a {0,0,0}  et les vecteurs necessaire a l'utilisation du programme  a {0,0,1}.
la couleur par defaut est le blanc et les rayon sont placee a 1.

note : gaffe a pas oublier d'affecter dir sinon ca va mater les oiseau severe! 

lum et ombre :
lum est un coef affecter a la couleur du pixel une fois tout les calcules effectuee donc modifie juste l'intensitee de l'objet, il est par defaut a 1.
ombre est egalement  a 1 par defaut et signie que les objet bloquent la lumiere (sauf si id = id_light avec une certaine lumiere mais c est un cas particulier) . si ombre vaut 0 alors l'objet n'aura aucune ombre portee car il laissera passer toutes les lumieres qui lui arriveront dessus.



ex demo_file :

cam origin:{-40,40,3} dir:{1,-1,0}
light origin:{-20,20,3}
plan rot:2 rot_dir:{-1,-1,0}
sphere couleur:0xFF0000 origin:{-10,-10,0} rayon:5 id_light:1
plan origin:{0,0,-10} couleur:0xFF00FF lum:2 
cylindre origin:{-10,0,0} couleur:0xFF00FF borne:{-5,5,42}
cone rot:3 rot_dir:{0,1,0} couleur:0x00FF00 lum:2 ombre:0 borne:{-3,3,0}


rem: l'odre des affectations n'importe pas


pour que le fichier soit valide :

1) les coordonnees des point et des vecteurs suivent directement leur affectations avec ':' pour delimiter, de plus elles doivent  etre placees entre {}, separees par des ',' sans espace.

2) Concernant les rotation d'axe pour les cylindres et les cones, l axe final de tracE du cylindre/cone est une rotation de eZ->(0,0,1) [DANS LE REPERE INITIAL]  de M_PI / rot par rapport a rot_dir.

3) Les couleurs sont exprimees en hexa, lettres en majuscule, sensible casse!

4) pour les bornes:
- concernant les plan si l affectation borne:{x,y,z} est specifiee seul x est pris en compte (par soucis d'implementation des fonctions de parsing) et x est la valeur du rayon du disque contenu dans le plan et ayant la meme origin.
-pour les cylindres et les cones si l'affectation borne:{x,y,z} est specifiee seul x et y sont pris en compte, x est la borne negative sur l axe du cylindre/cone et y la positive.

5) pour le plan si rot et rot_dir sont affectee alors l'objet se comporte comme les cylindre et les cones avec la nouvelle normale calculee, normee et rangE dans e->o->p->nor en faisant une rotation de eZ->(0,0,1) [REPERE INITIAL]  de M_PI/rot par rapport a rot_dir de plus si l'affectation tr_nor est valide, l'origine sera translatee de tr_rot * la normale du plan et cette derniere sera inversee si tr_nor < 0 (la normale doit pointer vers l exterieur de l objet (cone ou cylindre bornee)).

6) la valeur id_light pour les sphere et cylindre vaut 0 par defaut et la valeur id pour les light vaut 42 par defaut.
si id(light)=id_light(sphere/cylindre) ce la signie que l'objet est link a la lumiere et laisse ainsi passer les rayons qui lui sont propre.
