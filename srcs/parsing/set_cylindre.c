/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylindre.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:26:29 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 19:39:51 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void		init_var(t_cyl *cy)
{
	cy->origin = (float *)ft_memalloc(sizeof(float) * 3);
	cy->axe = set_vect(NULL, 0, 0, 1);
	cy->r = 1;
	cy->color = 0xFFFFFF;
	cy->lum = 1;
	cy->bri = 1;
	cy->ombre = 1;
	cy->borne = NULL;
	cy->id_light = 0;
	cy->next = NULL;
}

static t_cyl	*init_cyl(t_obj *o)
{
	t_cyl	*begin;

	if (o->cy == NULL)
	{
		o->cy = (t_cyl *)malloc(sizeof(t_cyl));
		begin = o->cy;
	}
	else
	{
		begin = o->cy;
		while (o->cy->next != NULL)
			o->cy = o->cy->next;
		o->cy->next = (t_cyl *)malloc(sizeof(t_cyl));
		o->cy = o->cy->next;
	}
	init_var(o->cy);
	return (begin);
}

static void		read_input_data(float *tmp_save, char **inp, t_cyl *cy)
{
	if (!ft_strcmp("origin", inp[0]))
		load_vect(cy->origin, inp[1]);
	else if (!ft_strcmp("rayon", inp[0]))
		cy->r = ft_atof(inp[1]);
	else if (!ft_strcmp("couleur", inp[0]))
		cy->color = ft_atoi_hexa(inp[1]);
	else if (!ft_strcmp("tr", inp[0]))
		tmp_save[0] = ft_atof(inp[1]);
	else if (!ft_strcmp("tr_dir", inp[0]))
		load_vect(tmp_save + 1, inp[1]);
	else if (!ft_strcmp("rot", inp[0]))
		tmp_save[4] = ft_atof(inp[1]);
	else if (!ft_strcmp("rot_dir", inp[0]))
		load_vect(tmp_save + 5, inp[1]);
	else if (!ft_strcmp("lum", inp[0]))
		cy->lum = ft_atof(inp[1]);
	else if (!ft_strcmp("bri", inp[0]))
		cy->bri = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("ombre", inp[0]))
		cy->ombre = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("borne", inp[0]))
		cy->borne = load_vect(NULL, inp[1]);
	else if (!ft_strcmp("id_light", inp[0]))
		cy->id_light = ft_atof(inp[1]);
}

void			set_cylindre(char **tmp, t_obj *o)
{
	t_cyl	*begin;
	char	***input;
	int		i;
	float	tmp_save[8];

	begin = init_cyl(o);
	i = input_number(tmp);
	input = (char ***)ft_memalloc(sizeof(char **) * i);
	i = 0;
	while (tmp[++i])
		input[i - 1] = ft_strsplit(tmp[i], ':');
	input[i - 1] = NULL;
	ft_memset(tmp_save, 0, sizeof(float) * 8);
	i = -1;
	while (input[++i])
		read_input_data(tmp_save, input[i], o->cy);
	free_double_split(input);
	if (tmp_save[0])
		vectorial_sum(o->cy->origin, o->cy->origin,
			vectorial_multi(tmp_save + 1, tmp_save[0], tmp_save + 1));
	if (tmp_save[4])
		rot(o->cy->axe, M_PI / tmp_save[4], tmp_save + 5);
	ft_norme(o->cy->axe);
	set_cyl_transfer(o->cy);
	o->cy = begin;
}
