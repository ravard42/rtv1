# include "rtv1.h"

int	input_number(char **tmp)
{
	int	i;

	i = -1;
	while (tmp[++i])
		;
	return (i);
}

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
	{
		free(input[i][0]);
		free(input[i][1]);
		free(input[i]);
	}
	free(input);
}

int	ft_atoi_hexa(char *s)
{
	int	ret;
	int	i;

	if (!s || !(s[0] == '0' && s[1] == 'x' && s[2] != '\0'))
		not_a_valid_file("go rtv1/demo_files/readme.txt\n");
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
			not_a_valid_file("go rtv1/demo_files/readme.txt\n");
	}
	return (ret);
}

int	ft_is_float(char *tmp)
{
	int	i;
	int	k;

	if (!tmp || !((tmp[0] == '-' && tmp[1] != '\0') || (tmp[0] >= '0' && tmp[0] <= '9')))
			not_a_valid_file("go rtv1/demo_files/readme.txt\n");
	i = 0;
	k = 0;
	while (tmp[++i])
		if (!((tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] == '.' && (k += 1) < 2)))
			not_a_valid_file("go rtv1/demo_files/readme.txt\n");
	return (1);
}

int	is_valid_coord(char *str)
{
	int	len;
	int	i;
	int	k;
	char	**is_float;

	len = ft_strlen(str);
	if (!(str[0] == '{' && str[len - 1] == '}' && str[len] == '\0'))
		not_a_valid_file("go rtv1/demo_files/readme.txt\n");
	i = -1;
	k = 0;
	while (str[++i])
		if (str[i] == ',')
			k++;
	if (k != 2)
		not_a_valid_file("go rtv1/demo_files/readme.txt\n");
	str = ft_revstr(ft_revstr(str + 1) + 1);
	is_float = ft_strsplit(str, ',');
	i = -1;
	while (++i < 3)
		if (!is_float || !ft_is_float(is_float[i]))
			not_a_valid_file("go rtv1/demo_files/readme.txt\n");
	free_split(is_float);
	return (1);
}


float	*load_vect(float *a, char *s)
{
	char	**tmp;

	if (!(s && is_valid_coord(s)))
		not_a_valid_file("go rtv1/demo_files/readme.txt\n");
	if (!a)
		a = (float *)malloc(sizeof(float) * 3);
	s += 2;  // voir dans is_valid_coord la manip sur s en double revstr
	tmp = ft_strsplit(s, ',');
	a[0] = ft_atof(tmp[0]);
	a[1] = ft_atof(tmp[1]);
	a[2] = ft_atof(tmp[2]);
	free_split(tmp);
	return(a);
}
