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


static void	put_pixel_light(int i, float *p, void *obj, t_env *e)
{
	t_lght	*begin;
	float	nor[3];
	float	rayon[3];
	float	rgb[9];
	int	n;
	int	color;
	int	bri;
	float	cos_angle[2];
	float	angle;
	int	obj_light;

	begin = e->l;
	obj_light = set_normal(nor, e->c->name[i], obj, p);
	set_vect(rgb, 0, 0, 0);
	bri = 0;
	rgb_to_coef(hexa_to_rgb(rgb + 3, recup_color(&color, e->c->name[i], obj, &bri)));
	n = 0;
	while (e->l)
	{
		vectorial_subtraction(rayon, p, e->l->origin);
		ft_norme(rayon);
		cos_angle[0] = -scalar_product(nor, rayon);
		if ((obj_light == 1 && e->l->id == ((t_sph *)obj)->id_light)
			|| (obj_light == 2 && e->l->id == ((t_cyl *)obj)->id_light))
		{
			cos_angle[0] = -cos_angle[0];
			angle = acos(cos_angle[0] - 0.02);
		}
		else
			angle = acos(cos_angle[0]);
		cos_angle[1] = (bri && angle < M_PI / 4) ? cos(2 * angle) : 0;
		if (e->l->scope && cos_angle[0] > 0)
		{
			hexa_to_rgb(rgb + 6, recup_color(&color, "light", e->l, NULL));
			rgb[0] += cos_angle[0] * rgb[3] * rgb[6] + 3 * pow(cos_angle[1], BRI) * rgb[6]; 
			rgb[1] += cos_angle[0] * rgb[4] * rgb[7] + 3 * pow(cos_angle[1], BRI) * rgb[7]; 
			rgb[2] += cos_angle[0] * rgb[5] * rgb[8] + 3 * pow(cos_angle[1], BRI) * rgb[8];
		}
		n++;
		e->l->scope = 0;
		e->l = e->l->next;
	}
	n = (n == 0) ? 1 : n;
	vectorial_multi(rgb, 1.0 / n, rgb);
	luminosity(rgb, e->c->name[i], obj);
	rgb_to_hexa(&color, rgb);
	*((int *)e->data_img + i) = color;
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
