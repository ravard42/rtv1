# include <rtv1.h>

static t_con	*init_con(t_obj *o)
{
	t_con	*begin;

	if (o->co == NULL)
	{
		o->co = (t_con *)malloc(sizeof(t_con));
		begin = o->co;
	}
	else
	{
		begin = o->co;
		while (o->co->next != NULL)
			o->co = o->co->next;
		o->co->next = (t_con *)malloc(sizeof(t_con));
		o->co = o->co->next;
	}
	o->co->origin = (float *)ft_memalloc(sizeof(float) * 3);
	o->co->axe = set_vect(NULL, 0, 0, 1);
	o->co->color = 0xFFFFFF;
	o->co->lum = 1;
	o->co->bri = 1;
	o->co->ombre = 1;
	o->co->borne = NULL;
	o->co->next = NULL;
	return (begin);
}

static void	read_input_data(float *tmp_save, char **inp, t_con *co)
{
	if (!ft_strcmp("origin", inp[0]))
		load_vect(co->origin, inp[1]);
	else if (!ft_strcmp("couleur", inp[0]))
		co->color = ft_atoi_hexa(inp[1]);
	else if (!ft_strcmp("tr", inp[0]))
		tmp_save[0] = ft_atof(inp[1]);
	else if (!ft_strcmp("tr_dir", inp[0]))
		load_vect(tmp_save + 1, inp[1]);
	else if (!ft_strcmp("rot", inp[0]))
		tmp_save[4] = ft_atof(inp[1]);
	else if (!ft_strcmp("rot_dir", inp[0]))
		load_vect(tmp_save + 5, inp[1]);
	else if (!ft_strcmp("lum", inp[0]))
		co->lum = ft_atof(inp[1]);
	else if (!ft_strcmp("bri", inp[0]))
		co->bri = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("ombre", inp[0]))
		co->ombre = (int)ft_atof(inp[1]);
	else if (!ft_strcmp("borne", inp[0]))
		co->borne = load_vect(NULL, inp[1]);
}

void	set_cone(char **tmp, t_obj *o)
{
	t_con	*begin;
	char	***input;
	int	i;
	float	tmp_save[8];

	begin = init_con(o);	
	i = input_number(tmp);
	input = (char ***)malloc(sizeof(char **) * i);
	i = 0;
	while (tmp[++i])
		input[i - 1] = ft_strsplit(tmp[i], ':');
	input[i - 1] = NULL;	
	ft_memset(tmp_save, 0, sizeof(float) * 8);
	i = -1;
	while (input[++i])
		read_input_data(tmp_save, input[i], o->co);
	free_double_split(input);
	if (tmp_save[0])
		vectorial_sum(o->co->origin, o->co->origin,
			vectorial_multi(tmp_save + 1, tmp_save[0], tmp_save + 1));
	if (tmp_save[4])
		rot(o->co->axe, M_PI / tmp_save[4], tmp_save + 5);
	ft_norme(o->co->axe);
	set_cone_transfer(o->co);
	o->co = begin;
}
