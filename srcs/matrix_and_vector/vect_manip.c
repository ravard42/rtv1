/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_manip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 18:18:01 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 18:41:38 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	*set_vect(float *dst, float a, float b, float c)
{
	if (dst == NULL)
		dst = (float *)malloc(sizeof(float) * 3);
	dst[0] = a;
	dst[1] = b;
	dst[2] = c;
	return (dst);
}

float	*vectorial_copy(float *dst, float *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	return (dst);
}
