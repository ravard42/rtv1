# include "rtv1.h"

int	main(int argc, char **argv)
{
	t_env		*e;
	float		cam[3];
	float		dir_cam[3];
	int		i;

	if (argc != 7)
		exit(0);
	i = 0;
	while (++i < 4)
		cam[i - 1] = (float)ft_atoi(argv[i]);
	while (++i < 8)
		dir_cam[i - 5] = (float)ft_atoi(argv[i - 1]);

	i = -1;
	while (++i < 3)
		printf("cam[%d] = %f && dir_cam[%d] = %f\n", i, cam[i], i, dir_cam[i]);	

	e = init_env(cam, dir_cam);
	loop(e);
	return (0);
}
