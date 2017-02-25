# include "rtv1.h"

static int	*recup_color(int *color, char *name, void *obj, int *bri)
{
	int	k;

	if (!ft_strcmp(name, "light") && (k = 0))
		*color = ((t_lght *)obj)->color;
	else if (!ft_strcmp(name, "sphere") && (k = 1))
		*color = ((t_sph *)obj)->color;
	else if (!ft_strcmp(name, "plan") && (k = 2))
		*color = ((t_pln *)obj)->color;
	else if (!ft_strcmp(name, "cylindre") && (k = 3))
		*color = ((t_cyl *)obj)->color;
	else if (!ft_strcmp(name, "cone") && (k = 4))
		*color = ((t_con *)obj)->color;
	if (bri && k == 1)
		*bri = ((t_sph *)obj)->bri ? 1 : 0;
	else if (bri && k == 2)
		*bri = ((t_pln *)obj)->bri ? 1 : 0;
	else if (bri && k == 3)
		*bri = ((t_cyl *)obj)->bri ? 1 : 0;
	else if (bri && k == 4)
		*bri = ((t_con *)obj)->bri ? 1 : 0;
	return (color);
}

static int	set_normal(float *nor, char *name,  void *obj, float *p)
{
	if (!ft_strcmp(name, "sphere"))
	{
		sph_normal(nor, p, obj);
		if (((t_sph *)obj)->id_light)
			return (1);
	}
	else if (!ft_strcmp(name, "plan"))
	{
		nor[0] = ((t_pln *)obj)->nor[0];
		nor[1] = ((t_pln *)obj)->nor[1];
		nor[2] = ((t_pln *)obj)->nor[2];
	}
	else if (!ft_strcmp(name, "cylindre"))
	{
		cyl_normal(nor, p, obj);
		if (((t_cyl *)obj)->id_light)
			return (2);
	}
	else if (!ft_strcmp(name, "cone"))
		con_normal(nor, p, obj);
	return (0);

}

// tmp[0-2] -> return_rgb
// tmp[3-5] -> material_rgb
// tmp[6-8] -> light_rgb
// tmp[9-11] -> nor_vect
// tmp[12-14] -> rayon_vect
// tmp[15-17] -> {cos(rayon_incident, normal), angle(rayon_incident, normal) = 2 * angle(rayon_incident, rayon_reflechi), cos(rayon_incident, rayon reflechi)}

//tmp2[0] -> nombre lumiere
//tmp2[1] -> couleur hexa
//tmp2[2] -> brillance
//tmp2[3] -> couplage objet/lumiere

static void	join_light(float *tmp, int *tmpi, void *obj, t_env *e)
{
	ft_norme(tmp + 12);
	tmp[15] = -scalar_product(tmp + 9, tmp + 12);
	if ((tmpi[3] == 1 && e->l->id == ((t_sph *)obj)->id_light)
			|| (tmpi[3] == 2 && e->l->id == ((t_cyl *)obj)->id_light))
	{
		tmp[15] = -tmp[15];
		tmp[16] = acos(tmp[15] - 0.02);
	}
	else
		tmp[16] = acos(tmp[15]);
	tmp[17] = (tmpi[2] && tmp[16] < M_PI / 4) ? cos(2 * tmp[16]) : 0;
	if (e->l->scope && tmp[15] > 0)
	{
		hexa_to_rgb(tmp + 6, recup_color(&tmpi[1], "light", e->l, NULL));
		tmp[0] += tmp[15] * tmp[3] * tmp[6] + BRI_INT * pow(tmp[17], 1.0 / BRI_ANGL) * tmp[6]; 
		tmp[1] += tmp[15] * tmp[4] * tmp[7] + BRI_INT * pow(tmp[17], 1.0 / BRI_ANGL) * tmp[7]; 
		tmp[2] += tmp[15] * tmp[5] * tmp[8] + BRI_INT * pow(tmp[17], 1.0 / BRI_ANGL) * tmp[8];
	}
	tmpi[0]++;
	e->l->scope = 0;
}


static void	put_pixel_light(int i, float *p, void *obj, t_env *e)
{
	t_lght	*begin;
	float	tmp[18];
	int	tmpi[4];

	begin = e->l;
	tmpi[3] = set_normal(tmp + 9 , e->c->name[i], obj, p);
	set_vect(tmp, 0, 0, 0);
	tmpi[2] = 0;
	rgb_to_coef(hexa_to_rgb(tmp + 3, recup_color(&tmpi[1], e->c->name[i], obj, &tmpi[2])));
	tmpi[0] = 0;
	while (e->l)
	{
		vectorial_subtraction(tmp + 12, p, e->l->origin);
		join_light(tmp, tmpi, obj, e);
		e->l = e->l->next;
	}
	tmpi[0] = (tmpi[0] == 0) ? 1 : tmpi[0];
	vectorial_multi(tmp, 1.0 / tmpi[0], tmp);
	luminosity(tmp, e->c->name[i], obj);
	rgb_to_hexa(&tmpi[1], tmp);
	*((int *)e->data_img + i) = tmpi[1];
	e->l = begin;
}

void		print(t_env *e)
{
	int	i;
	float	p[3];
	int	color;


	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		color = 0;
		if (e->l == NULL || e->c->obj[i] == NULL)
			*((int *)e->data_img + i) =
				*recup_color(&color, e->c->name[i], e->c->obj[i], NULL);
		else
		{
			vectorial_sum(p, e->c->pos,
					vectorial_multi(p, e->c->r_dist[i], e->c->r_dir[i]));
			global_light_test(p, e->c->obj[i], e);
			put_pixel_light(i, p, e->c->obj[i] ,e);
		}
	}
}
