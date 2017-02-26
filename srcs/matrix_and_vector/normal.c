/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:16:45 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 18:19:53 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	sph_normal(float *nor, float *p, t_sph *s)
{
	nor[0] = p[0] - s->origin[0];
	nor[1] = p[1] - s->origin[1];
	nor[2] = p[2] - s->origin[2];
	ft_norme(nor);
}

void	cyl_normal(float *nor, float *p, t_cyl *cy)
{
	float	k;

	k = (cy->axe[0] * (p[0] - cy->origin[0])
		+ cy->axe[1] * (p[1] - cy->origin[1])
		+ cy->axe[2] * (p[2] - cy->origin[2])
		/ (pow(cy->axe[0], 2) + pow(cy->axe[1], 2)
		+ pow(cy->axe[2], 2)));
	nor[0] = p[0] - (cy->origin[0] + k * cy->axe[0]);
	nor[1] = p[1] - (cy->origin[1] + k * cy->axe[1]);
	nor[2] = p[2] - (cy->origin[2] + k * cy->axe[2]);
	ft_norme(nor);
}

void	con_normal(float *nor, float *p, t_con *co)
{
	float	tmp[3];
	int		sign;
	float	k;

	tmp[0] = p[0] - co->origin[0];
	tmp[1] = p[1] - co->origin[1];
	tmp[2] = p[2] - co->origin[2];
	sign = (scalar_product(co->axe, tmp) > 0) ? 1 : -1;
	k = (co->axe[0] * (p[0] - co->origin[0])
		+ co->axe[1] * (p[1] - co->origin[1])
		+ co->axe[2] * (p[2] - co->origin[2]
		+ sign * cos(M_PI / 4)))
		/ (pow(co->axe[0], 2) + pow(co->axe[1], 2)
		+ pow(co->axe[2], 2));
	nor[0] = p[0] - (co->origin[0] + k * co->axe[0]);
	nor[1] = p[1] - (co->origin[1] + k * co->axe[1]);
	nor[2] = p[2] - (co->origin[2] + k * co->axe[2]);
	ft_norme(nor);
}
