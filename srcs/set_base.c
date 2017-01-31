# include "rtv1.h"

void	set_base(t_scn *s)
{
	int		sens;

	ft_norme(s->base[2]);
	if (s->base[2][1] == 0 && s->base[2][2] == 0)
	{
		sens = (s->base[2][0] > 0) ? 1 : -1;
		s->base[0][0] = 0;
		s->base[0][1] = -sens;
		s->base[0][2] = 0;
		s->base[1][0] = 0;
		s->base[1][1] = 0;
		s->base[1][2] = -1;
	}
	else if (s->base[2][0] == 0 && s->base[2][2] == 0)
	{
		sens = (s->base[2][1] > 0) ? 1 : -1;
		s->base[0][0] = sens;
		s->base[0][1] = 0;
		s->base[0][2] = 0;
		s->base[1][0] = 0;
		s->base[1][1] = 0;
		s->base[1][2] = -1;
	}
	else if (s->base[2][0] == 0 && s->base[2][1] == 0)
	{
		sens = (s->base[2][2] > 0) ? 1 : -1;
		s->base[0][0] = 0;
		s->base[0][1] = 1;
		s->base[0][2] = 0;
		s->base[1][0] = -sens;
		s->base[1][1] = 0;
		s->base[1][2] = 0;
	}
	else if (s->base[2][0] == 0)
	{
		sens = (s->base[2][1] > 0) ? 1 : -1;
		s->base[0][0] = sens;
		s->base[0][1] = 0;
		s->base[0][2] = 0;
		s->base[1][0] = 0;
		s->base[1][1] = -s->base[2][2] * sens;
		s->base[1][2] = -s->base[2][1] * sens;
	}
	else if (s->base[2][1] == 0)
	{
		sens = (s->base[2][0] > 0) ? 1 : -1;
		s->base[0][0] = 0;
		s->base[0][1] = -sens;
		s->base[0][2] = 0;
		s->base[1][0] = -s->base[2][2] * sens;
		s->base[1][1] = 0;
		s->base[1][2] = s->base[2][0] * sens;
	}
	else
	{
		sens = (s->base[2][0] * s->base[2][1] > 0) ? 1 : -1;
		s->base[0][0] = sens / s->base[2][0];
		s->base[0][1] = -sens / s->base[2][1];
		s->base[0][2] = 0;
		ft_norme(s->base[0]);
		s->base[1][0] = sens * s->base[2][2] * s->base[2][0];
		s->base[1][1] = sens * s->base[2][2] * s->base[2][1];
		s->base[1][2] = -sens * (s->base[2][0] + s->base[2][1]);
	}
}
