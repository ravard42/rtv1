# include "rtv1.h"


t_env		*install(char *path)
{
	t_env	*e;
	char	*line;
	char	**tmp;
	int	k;
	int 	fd;

	e = (t_env *)malloc(sizeof(t_env));
	init_env(e);
	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		tmp = ft_strsplit(line, ' ');
		if (!tmp)
			not_a_valid_file();
		k = analyzer(tmp[0]);
		if (k == 0)
			set_cam(tmp, e->c);
		else if (k == 1)
			set_sphere(tmp, e->o);
		else if (k == 2)
			set_plan(tmp, e->o);
		/*else if (k == 3)
			set_cylindree(tmp, e->o);
		else if (k == 4)
			set_cone(tmp, e->o);*/
		free_split(tmp);
	}
	close(fd);
	return (e);
}
