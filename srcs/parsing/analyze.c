# include "rtv1.h"

void		not_a_valid_file()
{
	ft_putstr("le fichier demo n'est pas valide\n");
	exit(0);
}

int		analyzer(char *tmp)
{
	if (!ft_strcmp("cam", tmp))
		return (0);
	else if (!ft_strcmp("sphere", tmp))
		return (1);
	else if (!ft_strcmp("plan", tmp))
		return (2);
	else if (!ft_strcmp("cylindre", tmp))
		return (3);
	else if (!ft_strcmp("cone", tmp))
		return (4);
	else if (!ft_strcmp("light", tmp))
		return (5);
	else
		not_a_valid_file();
	return (1);
}
