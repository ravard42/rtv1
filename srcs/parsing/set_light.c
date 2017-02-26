/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:26:51 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 19:40:56 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_lght	*init_light(t_env *e)
{
	t_lght	*begin;

	if (e->l == NULL)
	{
		e->l = (t_lght *)malloc(sizeof(t_lght));
		begin = e->l;
	}
	else
	{
		begin = e->l;
		while (e->l->next != NULL)
			e->l = e->l->next;
		e->l->next = (t_lght *)malloc(sizeof(t_lght));
		e->l = e->l->next;
	}
	e->l->name = "light";
	e->l->origin = (float *)ft_memalloc(sizeof(float) * 3);
	e->l->color = 0xFFFFFF;
	e->l->id = 42;
	e->l->scope = 0;
	e->l->next = NULL;
	return (begin);
}

static void		read_input_data(float *tmp_save, char **inp, t_lght *l)
{
	if (!ft_strcmp("origin", inp[0]))
		load_vect(l->origin, inp[1]);
	else if (!ft_strcmp("couleur", inp[0]))
		l->color = ft_atoi_hexa(inp[1]);
	else if (!ft_strcmp("id", inp[0]))
		l->id = ft_atof(inp[1]);
	else if (!ft_strcmp("tr", inp[0]))
		tmp_save[0] = ft_atof(inp[1]);
	else if (!ft_strcmp("tr_dir", inp[0]))
		load_vect(tmp_save + 1, inp[1]);
}

void			set_light(char **tmp, t_env *e)
{
	t_lght		*begin;
	char		***input;
	int			i;
	float		tmp_save[4];

	begin = init_light(e);
	i = input_number(tmp);
	input = (char ***)malloc(sizeof(char **) * i);
	i = 0;
	while (tmp[++i])
		input[i - 1] = ft_strsplit(tmp[i], ':');
	input[i - 1] = NULL;
	ft_memset(tmp_save, 0, sizeof(float) * 4);
	i = -1;
	while (input[++i])
		read_input_data(tmp_save, input[i], e->l);
	free_double_split(input);
	if (tmp_save[0])
		vectorial_sum(e->l->origin, e->l->origin,
			vectorial_multi(tmp_save + 1, tmp_save[0], tmp_save + 1));
	e->l = begin;
}
