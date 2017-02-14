# include "libft.h"


static int	is_a_float(char *s)
{
	int	i;
	int	k;

	if (!((s[0] == '-' && s[1] != '\0') || (s[0] >= '0' && s[0] <= '9')))
		return (0);
	k = 0;
	i = 0;
	while (s[++i])
		if (!((s[i] >= '0' && s[i] <= '9')
			|| (s[i] == '.' && (k += 1) < 2)))
			return (0);
	return (1);
}

float		ft_atof(char *s)
{
	char	**tmp;
	int	len;
	float	pmt;
	float	ret;

	if (s && s[0])
		if (!is_a_float(s))
			return (0);
	tmp = ft_strsplit(s, '.');
	if (tmp[1])
		len = ft_strlen(tmp[1]);
	
	ret = 0;
	ret = tmp[1] ? (float)ft_atoi(tmp[1]) / ft_power(10, len) : 0;
	pmt = (float)ft_atoi(tmp[0]);
	ret = (pmt > 0) ? ret + pmt : pmt - ret; 
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
	return (ret);
}


/*
int	main(int argc, char **argv)
{
	if (is_a_float(argv[1]))
		printf("float : %f\n", ft_atof(argv[1]));
	else
		printf("not float : %f\n", ft_atof(argv[1]));
	return (0);
		
}
*/
