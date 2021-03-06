/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 21:07:40 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 21:22:55 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		set_param(int i, float *param, t_env *e)
{
	param[0] = pow(e->c->r_dir[i][0], 2)
		+ pow(e->c->r_dir[i][1], 2)
		+ pow(e->c->r_dir[i][2], 2);
	param[1] = 2 * (e->c->r_dir[i][0]
			* (e->c->pos[0] - e->o->s->origin[0])
			+ e->c->r_dir[i][1] * (e->c->pos[1]
				- e->o->s->origin[1]) + e->c->r_dir[i][2]
			* (e->c->pos[2] - e->o->s->origin[2]));
	param[2] = pow(e->c->pos[0]
			- e->o->s->origin[0], 2) + pow(e->c->pos[1]
				- e->o->s->origin[1], 2) + pow(e->c->pos[2]
					- e->o->s->origin[2], 2) - pow(e->o->s->r, 2);
}

static float	solve(float *param)
{
	float	delt;
	float	tmp[2];
	float	sol;

	sol = MAX_DIST;
	if ((delt = pow(param[1], 2) - 4 * param[0] * param[2]) == 0)
	{
		tmp[0] = -param[1] / (2 * param[0]);
		sol = (tmp[0] >= VP_DIST) ? tmp[0] : sol;
	}
	else if (delt > 0)
	{
		tmp[0] = (-param[1] + sqrt(delt)) / (2 * param[0]);
		tmp[1] = (-param[1] - sqrt(delt)) / (2 * param[0]);
		if ((tmp[0] >= VP_DIST && tmp[1] < VP_DIST)
				|| (tmp[1] >= VP_DIST && tmp[0] < VP_DIST))
			sol = (tmp[0] >= VP_DIST) ? tmp[0] : tmp[1];
		else if (tmp[0] >= VP_DIST && tmp[1] >= VP_DIST)
			sol = (tmp[0] <= tmp[1]) ? tmp[0] : tmp[1];
	}
	return (sol);
}

int				sphere_test(t_env *e)
{
	int		i;
	float	param[3];
	float	sol;

	i = -1;
	while (++i < MAX_X * MAX_Y)
	{
		set_param(i, param, e);
		sol = solve(param);
		if (sol <= e->c->r_dist[i] && sol < MAX_DIST)
		{
			e->c->r_dist[i] = sol;
			e->c->obj[i] = e->o->s;
			ft_strcpy(e->c->name[i], "sphere");
		}
	}
	return (1);
}
