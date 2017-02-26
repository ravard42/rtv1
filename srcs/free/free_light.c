/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:59:10 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 18:01:39 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	free_light(t_env *e)
{
	t_lght		*begin;

	if (!e->l)
		return (0);
	begin = e->l;
	free(e->l->origin);
	while ((e->l = e->l->next) != NULL)
		free(e->l->origin);
	e->l = begin;
	while (begin->next != NULL)
	{
		while (e->l->next->next != NULL)
			e->l = e->l->next;
		free(e->l->next);
		e->l->next = NULL;
		e->l = begin;
	}
	free(e->l);
	e->l = NULL;
	return (1);
}
