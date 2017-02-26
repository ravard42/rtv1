/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:42:49 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 18:44:21 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rot_d(int keycode, t_env *e)
{
	float	tmp[3];

	set_vect(tmp, 0, 0, 1);
	if (!prevent_hori_rot(keycode, e->c->base))
	{
		rot(e->c->base[2], -ROT, tmp);
		set_cam_base(e->c);
	}
	set_cam_ray_dir(e->c);
}

void	rot_g(int keycode, t_env *e)
{
	float	tmp[3];

	set_vect(tmp, 0, 0, 1);
	if (!prevent_hori_rot(keycode, e->c->base))
	{
		rot(e->c->base[2], ROT, tmp);
		set_cam_base(e->c);
	}
	set_cam_ray_dir(e->c);
}

void	demi_tour(t_env *e)
{
	vectorial_multi(e->c->base[2], -1, e->c->base[2]);
	set_cam_base(e->c);
	set_cam_ray_dir(e->c);
}

void	rot_b(int keycode, t_env *e)
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

void	rot_h(int keycode, t_env *e)
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
