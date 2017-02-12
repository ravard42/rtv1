/*
# include <stdio.h>
# include "libft.h"
# include <math.h>

void		not_a_valid_file()
{
	ft_putstr("le fichier demo n'est pas valide\n");
	exit(0);
}
*/

# include "rtv1.h"

void	free_split(char **tmp)
{
	int	i;

	i = -1;
	while (++i < 3)
		free(tmp[i]);
	free(tmp);
}

int	ft_atoi_hexa(char *s)
{
	int	ret;
	int	i;

	if (!s || !(s[0] == '0' && s[1] == 'x' && s[2] != '\0'))
		not_a_valid_file();
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
			not_a_valid_file();
	}
	return (ret);
}

int	ft_is_int(char *tmp)
{
	int	i;

	if (!tmp || !(tmp[0] == '-' || (tmp[0] >= '0' && tmp[0] <= '9')))
			not_a_valid_file();
	i = 0;
	if (tmp[0] == '-' && tmp[1] == '\0')
			not_a_valid_file();
	while (tmp[++i])
		if (!(tmp[i] >= '0' && tmp[i] <= '9'))
			not_a_valid_file();
	return (1);
}

int	is_valid_coord(char *str)
{
	int	len;
	int	i;
	int	k;
	char	**is_int;

	len = ft_strlen(str);
	if (!(str[0] == '{' && str[len - 1] == '}' && str[len] == '\0'))
		not_a_valid_file();
	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] == ',')
			k++;
	if (k != 2)
		not_a_valid_file();
	str = ft_revstr(ft_revstr(str + 1) + 1);
	is_int = ft_strsplit(str, ',');
	i = -1;
	while (++i < 3)
		if (!is_int || !ft_is_int(is_int[i]))
			not_a_valid_file();
	free_split(is_int);
	return (1);
}


void	load_vect(char *s, float *a)
{
	char	**tmp;

	if (!(s && is_valid_coord(s)))
		not_a_valid_file();
	s += 2;  // voir dans is_valid_coord la manip sur s en double revstr
	tmp = ft_strsplit(s, ',');
	a[0] = ft_atoi(tmp[0]);
	a[1] = ft_atoi(tmp[1]);
	a[2] = ft_atoi(tmp[2]);
	free_split(tmp);
}

/*
int	main(int argc, char **argv)
{
	float	a[3];

	printf("%d\n", ft_atoi_hexa(argv[1]));

	load_vect(argv[2], a);
	printf("{%f, %f, %f}\n", a[0], a[1], a[2]);

	return (0);
}
*/
