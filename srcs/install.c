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
		k = analyzer(tmp[0]);
		if (k == 0 && analyzer_cam(tmp))
			set_cam(tmp, e->c);
		else if (k == 1 && analyzer_sphere(tmp))
			set_sphere(tmp, e->o);
		/*else if (k == 2 && analyzer_plan(tmp))
			set_plan(tmp, e->o);
		else if (k == 3 && analyzer_cylindre(tmp))
			set_cylindree(tmp, e->o);
		else if (k == 4 && analyzer_cone(tmp))
			set_cone(tmp, e->o);*/
	}
	close(fd);
	return (e);
}
