/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:27:19 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 19:41:23 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static t_pln	*init_pln(t_obj *o)
{
	t_pln	*begin;

	if (o->p == NULL)
	{
		o->p = (t_pln *)malloc(sizeof(t_pln));
		begin = o->p;
	}
	else
	{
		begin = o->p;
		while (o->p->next != NULL)
			o->p = o->p->next;
		o->p->next = (t_pln *)malloc(sizeof(t_pln));
		o->p = o->p->next;
	}
	o->p->origin = (float *)ft_memalloc(sizeof(float) * 3);
	o->p->nor = set_vect(NULL, 0, 0, 1);
	o->p->color = 0xFFFFFF;
	o->p->lum = 1;
	o->p->bri = 1;
	o->p->ombre = 1;
	o->p->borne = NULL;
	o->p->next = NULL;
	return (begin);
}

static void		read_input_data(float *tmp_save, char **inp, t_pln *p)
{
	if (!ft_strcmp("origin", inp[0]))
		load_vect(p->origin, inp[1]);
	else if (!ft_strcmp("couleur", inp[0]))
		p->color = ft_atoi_hexa(inp[1]);
	else if (!ft_strcmp("tr", inp[0]))
		tmp_save[0] = ft_atof(inp[1]);
	else if (!ft_strcmp("tr_dir", inp[0]))
		load_vect(tmp_save + 1, inp[1]);
	else if (!ft_strcmp("rot", inp[0]))
		tmp_save[4] = ft_atof(inp[1]);
	else if (!ft_strcmp("rot_dir", inp[0]))
		load_vect(tmp_save + 5, inp[1]);
	else if (!ft_strcmp("tr_nor", inp[0]))
		tmp_save[8] = ft_atof(inp[1]);
	else if (!ft_strcmp("lum", inp[0]))
		p->lum = ft_atof(inp[1]);
	else if (!ft_strcmp("bri", inp[0]))
		p->bri = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("ombre", inp[0]))
		p->ombre = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("borne", inp[0]))
		p->borne = load_vect(NULL, inp[1]);
}

static void		axe_translation(t_pln *p, float val)
{
	float	tmp[3];

	if (val)
		vectorial_sum(p->origin, p->origin,
			vectorial_multi(tmp, val, p->nor));
	if (val < 0)
		vectorial_multi(p->nor, -1, p->nor);
}

void			set_plan(char **tmp, t_obj *o)
{
	t_pln	*begin;
	char	***input;
	int		i;
	float	tmp_save[9];

	begin = init_pln(o);
	i = input_number(tmp);
	input = (char ***)malloc(sizeof(char **) * i);
	i = 0;
	while (tmp[++i])
		input[i - 1] = ft_strsplit(tmp[i], ':');
	input[i - 1] = NULL;
	ft_memset(tmp_save, 0, sizeof(float) * 9);
	i = -1;
	while (input[++i])
		read_input_data(tmp_save, input[i], o->p);
	free_double_split(input);
	if (tmp_save[0])
		vectorial_sum(o->p->origin, o->p->origin,
			vectorial_multi(tmp_save + 1, tmp_save[0], tmp_save + 1));
	if (tmp_save[4])
		rot(o->p->nor, M_PI / tmp_save[4], tmp_save + 5);
	ft_norme(o->p->nor);
	axe_translation(o->p, tmp_save[8]);
	o->p = begin;
}
