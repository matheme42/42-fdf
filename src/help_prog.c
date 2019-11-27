/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   help_prog.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 17:11:51 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 11:08:28 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	show_t_map(t_moniteur *mtr)
{
	size_t	i;
	int		j;

	ft_putstr("  ");
	ft_putnbr(mtr->size_x);
	ft_putstr("--");
	ft_putnbr(mtr->size_y);
	ft_putchar('\n');
	while (mtr->map->next)
	{
		i = 0;
		while (i < mtr->size_x)
		{
			j = ft_nbrlen(mtr->map->map[i]);
			if (mtr->map->map[i] >= 0)
				ft_putchar(' ');
			if (j == 0)
				ft_putchar(' ');
			ft_putnbr(mtr->map->map[i]);
			ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		mtr->map = mtr->map->next;
	}
}

int		*tab_atoi(char **tab, int size, int *max)
{
	int		*tabint;
	int		i;

	i = -1;
	if (!(tabint = malloc(sizeof(int) * size)))
		mexit();
	while (++i < size)
	{
		tabint[i] = ft_atoi(tab[i]);
		if (tabint[i] > *max)
			*max = tabint[i];
		free(tab[i]);
	}
	free(tab);
	return (tabint);
}

t_bool	fill_pixel(t_moniteur *mtr, int x, int y)
{
	size_t	pos;

	pos = x * 4 + y * mtr->s_l;
	if (x * 4 < mtr->s_l && y < WIN_SIZE_Y && x * 4 >= 0 && y >= 0)
	{
		mtr->img_str[pos + 2] = mtr->color / 256 / 256;
		mtr->img_str[pos + 1] = mtr->color / 256;
		mtr->img_str[pos] = mtr->color % 256;
		return (true);
	}
	return (true);
}

void	black_screen(t_moniteur *mtr)
{
	int i;

	i = 0;
	while (i < 4 * WIN_SIZE_X * WIN_SIZE_Y - 1)
	{
		mtr->img_str[i] = 0;
		mtr->img_str[i + 1] = 0;
		mtr->img_str[i + 2] = 0;
		i += 4;
	}
}
