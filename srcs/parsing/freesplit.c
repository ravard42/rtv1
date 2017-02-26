/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 19:20:57 by ravard            #+#    #+#             */
/*   Updated: 2017/02/26 19:21:02 by ravard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	free_split(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		free(tmp[i]);
	free(tmp);
}

void	free_double_split(char ***input)
{
	int	i;

	i = -1;
	while (input[++i])
		free_split(input[i]);
	free(input);
}
