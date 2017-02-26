/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:42:38 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 18:42:44 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		init_env(t_env *e)
{
	int	info[3];

	e->ptr = mlx_init();
	e->win = mlx_new_window(e->ptr, MAX_X, MAX_Y, "rtv1");
	e->img = mlx_new_image(e->ptr, MAX_X, MAX_Y);
	e->c = NULL;
	e->data_img = mlx_get_data_addr(e->img, info, info + 1, info + 2);
	e->o = (t_obj *)malloc(sizeof(t_obj));
	e->o->s = NULL;
	e->o->p = NULL;
	e->o->cy = NULL;
	e->o->co = NULL;
	e->l = NULL;
}
