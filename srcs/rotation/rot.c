/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 20:57:25 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 21:04:40 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
** on effectue la rotation de ez  de value radian par rapport a n
** et on stock le resultat dans ez
*/

void	rot(float *ez, float value, float *n)
{
	int		i;
	float	**rot;

	ft_norme(n);
	rot = (float **)malloc(sizeof(float *) * 3);
	i = -1;
	while (++i < 3)
		rot[i] = (float *)malloc(sizeof(float) * 3);
	rot[0][0] = cos(value) + (1 - cos(value)) * (pow(n[0], 2));
	rot[0][1] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (-n[2]);
	rot[0][2] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (n[1]);
	rot[1][0] = (1 - cos(value)) * (n[0] * n[1]) - sin(value) * (n[2]);
	rot[1][1] = cos(value) + (1 - cos(value)) * (pow(n[1], 2));
	rot[1][2] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (-n[0]);
	rot[2][0] = (1 - cos(value)) * (n[0] * n[2]) - sin(value) * (-n[1]);
	rot[2][1] = (1 - cos(value)) * (n[1] * n[2]) - sin(value) * (n[0]);
	rot[2][2] = cos(value) + (1 - cos(value)) * (pow(n[2], 2));
	matrix_product(ez, rot, ez);
	i = -1;
	while (++i < 3)
		free(rot[i]);
	free(rot);
}
