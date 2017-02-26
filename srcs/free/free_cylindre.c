/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cylindre.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:58:52 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 18:01:13 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		free_cylindre(t_cyl *cy)
{
	int	i;

	i = -1;
	while (++i < MAX_X * MAX_Y)
		free(cy->t->cam_r_dir[i]);
	free(cy->t->cam_r_dir);
	i = -1;
	while (++i < 3)
		free(cy->t->mat[i]);
	free(cy->t->mat);
	free(cy->t->obj_pos);
	free(cy->t->cam_pos);
	free(cy->t);
	free(cy->axe);
	free(cy->origin);
	if (cy->borne)
		free(cy->borne);
}

int				free_all_cylindre(t_obj *o)
{
	t_cyl	*begin;

	if (!o->cy)
		return (0);
	begin = o->cy;
	free_cylindre(o->cy);
	while ((o->cy = o->cy->next) != NULL)
		free_cylindre(o->cy);
	o->cy = begin;
	while (begin->next != NULL)
	{
		while (o->cy->next->next != NULL)
			o->cy = o->cy->next;
		free(o->cy->next);
		o->cy->next = NULL;
		o->cy = begin;
	}
	free(o->cy);
	o->cy = NULL;
	return (1);
}
