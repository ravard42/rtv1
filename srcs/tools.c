# include <stdio.h>
# include "libft.h"
# include <math.h>

int	ft_atoi_hexa(char *s)
{
	int	ret;
	int	i;

	if (s[0] != '0' && s[1] != 'x')
	{
		ft_putstr("probleme conversion atoi_hexa\n");
		exit(0);
	}
	ft_revstr(s);
	ret = 0;
	i = -1;
	while(s[++i] != 'x')
	{
		if (s[i] >= '0' && s[i] <= '9')
			ret += (s[i] - '0') * pow(16, i) ;
		else if (s[i] >= 'A' && s[i] <= 'F')
			ret += (10 + s[i] - 'A') * pow(16, i);
		else
		{
			ft_putstr("probleme conversion atoi_hexa\n");
			exit(0);
		}
	}
	return (ret);
}

void	load_vect(char *s, float *a)
{
	int	i;
	char	**tmp;

	s = s + 1;
	ft_revstr(s);
	s = s + 1;
	ft_revstr(s);
	tmp = ft_strsplit(s, ',');
	a[0] = ft_atoi(tmp[0]);
	a[1] = ft_atoi(tmp[1]);
	a[2] = ft_atoi(tmp[2]);
	i = -1;
	while (++i < 3)
		free(tmp[i]);
	free(tmp);
}

/*
int	main(int argc, char **argv)
{
	int	a[3];

	printf("%d\n", ft_atoi_hexa(argv[1]));

	load_vect(argv[2], a);
	printf("{%d, %d, %d}\n", a[0], a[1], a[2]);

	return (0);
}*/
