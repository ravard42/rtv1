/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 17:57:29 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 17:58:12 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int	ft_usage(char *path)
{
	char *tmp;

	tmp = ft_strdup(ft_revstr(path));
	tmp[5] = '\0';
	if (ft_strcmp("1vtr.", tmp))
	{
		ft_putstr("usage : ./rtv1 demoX.rtv1\n");
		exit(0);
	}
	free(tmp);
	ft_revstr(path);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !ft_usage(argv[1]))
		;
	loop(install(argv[1]));
	return (0);
}
