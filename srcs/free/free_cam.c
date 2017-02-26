/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:58:40 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 17:59:37 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_cam(t_env *e)
{
	int	i;

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		free(e->c->name[i]);
		free(e->c->r_dir[i]);
	}
	free(e->c->name);
	free(e->c->obj);
	free(e->c->r_dist);
	free(e->c->r_dir);
	i = -1;
	while (++i < 3)
		free(e->c->base[i]);
	free(e->c->base);
	free(e->c->pos);
	free(e->c);
	e->c = NULL;
}
