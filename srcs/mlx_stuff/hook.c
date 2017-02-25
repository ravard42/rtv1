# include "rtv1.h"

int	ft_exit(t_env *e)
{
	free_cam(e);
	free_light(e);
	free_sphere(e->o);
	free_all_plan(e->o);
	free_all_cylindre(e->o);
	free_all_cone(e->o);
	free(e->o);
	e->o = NULL;
	free(e->data_img);
	free(e->img);
	free(e->win);
	free(e->ptr);
	free(e);
	exit(0);
}

int	expose_hook(t_env *e)
{
	clear_img_dist_obj(e);
	global_test(e);
	print(e);
	mlx_put_image_to_window(e->ptr, e->win, e->img, 0, 0);
	return (0);
}

int	key_hook(int keycode, t_env *e)
{
	float 	tmp[3];

	if (keycode == EXIT)
		ft_exit(e);
	else if (keycode == AVANCER)
		vectorial_sum(e->c->pos, e->c->pos,
				vectorial_multi(tmp, PAS, e->c->base[2]));
	else if (keycode == RECULER)
		vectorial_subtraction(e->c->pos, e->c->pos,
				vectorial_multi(tmp, PAS, e->c->base[2]));
	else if (keycode == ROT_D || keycode == ROT_D2)
		rot_d(keycode, e);
	else if (keycode == ROT_G || keycode == ROT_G2)
		rot_g(keycode, e);
	else if (keycode == DEMITOUR)
		demi_tour(e);
	else if (keycode == BAS || keycode == BAS2)
		rot_b(keycode, e);
	else if (keycode == HAUT || keycode == HAUT2)
		rot_h(keycode, e);
	expose_hook(e);
	return (0);	
}
