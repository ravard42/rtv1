# include "rtv1.h"


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

	set_vect(tmp, 0, 0, 1);
	if (keycode == EXIT)
		exit(0);
	else if (keycode == AVANCER)
		vectorial_sum(e->c->pos, e->c->pos, vectorial_multi(tmp, PAS, e->c->base[2]));
	else if (keycode == RECULER)
		vectorial_subtraction(e->c->pos, e->c->pos, vectorial_multi(tmp, PAS, e->c->base[2]));
	else if (keycode == ROT_D || keycode == ROT_D2)
	{	
		if (prevent_hori_rot(keycode, e->c->base))
			;
		else
		{
			rot(e->c->base[2], -ROT, tmp);
			set_cam_base(e->c);
		}
		set_cam_ray_dir(e->c);
	}
	else if (keycode == ROT_G || keycode == ROT_G2)
	{	
		if (prevent_hori_rot(keycode, e->c->base))
			;
		else
		{	
			rot(e->c->base[2], ROT, tmp);
			set_cam_base(e->c);
		}
		set_cam_ray_dir(e->c);
	}
	else if (keycode == DEMITOUR)
	{
		vectorial_multi(e->c->base[2], -1, e->c->base[2]);
		set_cam_base(e->c);
		set_cam_ray_dir(e->c);
	}
	else if (keycode == BAS || keycode == BAS2)
	{	
		if (prevent_vert_rot(keycode, e))
		{
			set_vect(e->c->base[2], 0, 0, -1);
			set_cam_base(e->c);
		}
		else
		{
			rot(e->c->base[2], -ROT, e->c->base[0]);
			vectorial_product(e->c->base[1], e->c->base[2], e->c->base[0]);
		}
		set_cam_ray_dir(e->c);
	}
	else if (keycode == HAUT || keycode == HAUT2)
	{	
		if (prevent_vert_rot(keycode, e))
		{
			set_vect(e->c->base[2], 0, 0, 1);
			set_cam_base(e->c);
		}
		else
		{
			rot(e->c->base[2], ROT, e->c->base[0]);
			vectorial_product(e->c->base[1], e->c->base[2], e->c->base[0]);
		}
		set_cam_ray_dir(e->c);
	}
	expose_hook(e);
	return (0);	
}
