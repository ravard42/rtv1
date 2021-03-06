/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   install.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:21:08 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 19:30:44 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		set(t_env *e, char **tmp, int k)
{
	if (k == 0)
		set_cam(tmp, e);
	else if (k == 1)
		set_sphere(tmp, e->o);
	else if (k == 2)
		set_plan(tmp, e->o);
	else if (k == 3)
		set_cylindre(tmp, e->o);
	else if (k == 4)
		set_cone(tmp, e->o);
	else if (k == 5)
		set_light(tmp, e);
}

t_env			*install(char *path)
{
	t_env	*e;
	char	*line;
	char	**tmp;
	int		fd;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		set(e, tmp, analyzer(tmp));
		free_split(tmp);
		free(line);
	}
	close(fd);
	if (!e->c)
		not_a_valid_file("haven't found any cam input informations\n");
	return (e);
}
