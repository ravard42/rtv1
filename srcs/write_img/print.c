# include "rtv1.h"

static int	*recup_color(int *color, char *name, void *obj)
{
	if (!ft_strcmp(name, "sphere"))
		*color = ((t_sph *)obj)->color;
	else if (!ft_strcmp(name, "plan"))
		*color = ((t_pln *)obj)->color;
	else if (!ft_strcmp(name, "cylindre"))
		*color = ((t_cyl *)obj)->color;
	else if (!ft_strcmp(name, "cone"))
		*color = ((t_con *)obj)->color;
	else if (!ft_strcmp(name, "light"))
		*color = ((t_lght *)obj)->color;
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
		return (3);
	}
	else if (!ft_strcmp(name, "cylindre"))
	{
		cyl_normal(nor, p, obj);
		if (((t_cyl *)obj)->id_light == 42)
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
	float	cos_angle;
	int	obj_light;

	begin = e->l;
	obj_light = set_normal(nor, e->c->name[i], obj, p);
	set_vect(rgb, 0, 0, 0);
	rgb_to_coef(hexa_to_rgb(rgb + 3, recup_color(&color, e->c->name[i], obj)));
	n = 0;
	while (e->l)
	{
		vectorial_subtraction(rayon, p, e->l->origin);
		ft_norme(rayon);
		cos_angle = scalar_product(nor, rayon);
		if ((obj_light == 1 && e->l->id == ((t_sph *)obj)->id_light) || obj_light == 2)
			cos_angle = -cos_angle;
		if ((!obj_light || obj_light == 3
			|| obj_light == 1
			|| (obj_light == 2 && e->l->id == 42))
			&& e->l->scope && cos_angle < 0)
		{
			hexa_to_rgb(rgb + 6, recup_color(&color, "light", e->l));
			rgb[0] -= cos_angle * rgb[3] * rgb[6]; 
			rgb[1] -= cos_angle * rgb[4] * rgb[7]; 
			rgb[2] -= cos_angle * rgb[5] * rgb[8]; 
		}
		n++;
		e->l->scope = 0;
		e->l = e->l->next;
	}
	n = (n == 0) ? 1 : n;
	vectorial_multi(rgb, 1.0 / n, rgb);
	if (obj_light == 1)
		obj_light_up(rgb, ((t_sph *)obj)->light_coef);
	if (obj_light == 2)
		obj_light_up(rgb, ((t_cyl *)obj)->light_coef);
	if (obj_light == 3)
		obj_light_up(rgb, ((t_pln *)obj)->coef);
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
			*recup_color(&color, e->c->name[i], e->c->obj[i]);
		else
		{
			vectorial_sum(p, e->c->pos,
				vectorial_multi(p, e->c->r_dist[i], e->c->r_dir[i]));
			global_light_test(p, e->c->obj[i], e);
			put_pixel_light(i, p, e->c->obj[i] ,e);
		}
	}
}
