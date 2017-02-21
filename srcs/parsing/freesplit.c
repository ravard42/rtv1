# include "rtv1.h"

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
