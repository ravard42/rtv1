# include "rtv1.h"

void		not_a_valid_file(char *str)
{
	ft_putstr(str);
	exit(0);
}

int		analyzer(char **tmp)
{
	if (!tmp[0])
		return (-42);
	if (!ft_strcmp("cam", tmp[0]))
		return (0);
	else if (!ft_strcmp("sphere", tmp[0]))
		return (1);
	else if (!ft_strcmp("plan", tmp[0]))
		return (2);
	else if (!ft_strcmp("cylindre", tmp[0]))
		return (3);
	else if (!ft_strcmp("cone", tmp[0]))
		return (4);
	else if (!ft_strcmp("light", tmp[0]))
		return (5);
	return (-42);
}
