/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:28:52 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 19:41:51 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_sph	*init_sphere(t_obj *o)
{
	t_sph	*begin;

	if (o->s == NULL)
	{
		o->s = (t_sph *)malloc(sizeof(t_sph));
		begin = o->s;
	}
	else
	{
		begin = o->s;
		while (o->s->next != NULL)
			o->s = o->s->next;
		o->s->next = (t_sph *)malloc(sizeof(t_sph));
		o->s = o->s->next;
	}
	o->s->origin = (float *)ft_memalloc(sizeof(float) * 3);
	o->s->color = 0xFFFFFF;
	o->s->r = 1;
	o->s->lum = 1;
	o->s->bri = 1;
	o->s->ombre = 1;
	o->s->id_light = 0;
	o->s->next = NULL;
	return (begin);
}

static void		read_input_data(float *tmp_save, char **inp, t_sph *s)
{
	if (!ft_strcmp("origin", inp[0]))
		load_vect(s->origin, inp[1]);
	else if (!ft_strcmp("rayon", inp[0]))
		s->r = ft_atof(inp[1]);
	else if (!ft_strcmp("couleur", inp[0]))
		s->color = ft_atoi_hexa(inp[1]);
	else if (!ft_strcmp("tr", inp[0]))
		tmp_save[0] = ft_atof(inp[1]);
	else if (!ft_strcmp("tr_dir", inp[0]))
		load_vect(tmp_save + 1, inp[1]);
	else if (!ft_strcmp("lum", inp[0]))
		s->lum = ft_atof(inp[1]);
	else if (!ft_strcmp("bri", inp[0]))
		s->bri = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("ombre", inp[0]))
		s->ombre = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("id_light", inp[0]))
		s->id_light = ft_atof(inp[1]);
}

void			set_sphere(char **tmp, t_obj *o)
{
	t_sph		*begin;
	char		***input;
	int			i;
	float		tmp_save[4];

	begin = init_sphere(o);
	i = input_number(tmp);
	input = (char ***)malloc(sizeof(char **) * i);
	i = 0;
	while (tmp[++i])
		input[i - 1] = ft_strsplit(tmp[i], ':');
	input[i - 1] = NULL;
	ft_memset(tmp_save, 0, sizeof(float) * 4);
	i = -1;
	while (input[++i])
		read_input_data(tmp_save, input[i], o->s);
	free_double_split(input);
	if (tmp_save[0])
		vectorial_sum(o->s->origin, o->s->origin,
			vectorial_multi(tmp_save + 1, tmp_save[0], tmp_save + 1));
	o->s = begin;
}
