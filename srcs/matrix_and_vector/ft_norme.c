/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:15:54 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 18:16:22 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_dist(float *a, float *b)
{
	float	tmp;

	tmp = sqrt(pow(b[0] - a[0], 2)
		+ pow(b[1] - a[1], 2)
		+ pow(b[2] - a[2], 2));
	return (tmp);
}

void	ft_norme(float *v)
{
	float	tmp;

	if (v[0] == 0 && v[1] == 0 && v[2] == 0)
	{
		ft_putstr("on ne peut pas normer le vecteur NULL!\n");
		exit(0);
	}
	tmp = sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2));
	v[0] = v[0] / tmp;
	v[1] = v[1] / tmp;
	v[2] = v[2] / tmp;
}
