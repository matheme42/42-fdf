/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   algo_bresenham.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 10:18:04 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/11 12:30:15 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

static t_bool	algo_bresenham_x(int i[4], t_moniteur *mtr, double e, double d)
{
	while (i[0] < i[2])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		if ((e = e + d) >= 0.5)
		{
			i[1] = i[1] + 1;
			e -= 1.0;
		}
		i[0]++;
	}
	while (i[0] > i[2])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		e = e - d;
		e <= 0.5 ? i[1] = i[1] - 1 : 0;
		e <= 0.5 ? e += 1.0 : 0;
		i[0]--;
	}
	return (true);
}

static t_bool	algo_bresenham_y(int i[4], t_moniteur *mtr, double e, double d)
{
	while (i[1] < i[3])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		if ((e = e + d) >= 0.5)
		{
			i[0] = i[0] + 1;
			e -= 1.0;
		}
		i[1]++;
	}
	while (i[1] > i[3])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		e = e - d;
		e <= 0.5 ? i[0] = i[0] - 1 : 0;
		e <= 0.5 ? e += 1.0 : 0;
		i[1]--;
	}
	return (true);
}

static t_bool	algo_bresenham_yn(int i[4], t_moniteur *mtr, double e, double d)
{
	while (i[1] < i[3])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		if ((e = e + d) <= 0.5)
		{
			i[0] = i[0] - 1;
			e += 1.0;
		}
		i[1]++;
	}
	while (i[1] > i[3])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		e = e - d;
		e >= 0.5 ? i[0] = i[0] + 1 : 0;
		e >= 0.5 ? e -= 1.0 : 0;
		i[1]--;
	}
	return (true);
}

static t_bool	algo_bresenham_xn(int i[4], t_moniteur *mtr, double e, double d)
{
	while (i[0] < i[2])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		if (!(e = e - d))
		{
			i[1] = i[1] - 1;
			e -= 1.0;
		}
		i[0]++;
	}
	while (i[0] > i[2])
	{
		if (fill_pixel(mtr, i[0], i[1]))
			return (false);
		e = e - d;
		e >= 0.5 ? i[1] = i[1] + 1 : 0;
		e >= 0.5 ? e -= 1.0 : 0;
		i[0]--;
	}
	return (true);
}

t_bool			algo_bresenham(double index[4], t_moniteur *mtr)
{
	double	dx;
	double	dy;
	int		index_cpy[4];

	dy = index[3] - index[1];
	dx = index[2] - index[0];
	index_cpy[0] = (int)index[0];
	index_cpy[1] = (int)index[1];
	index_cpy[2] = (int)index[2];
	index_cpy[3] = (int)index[3];
	if (dx / dy >= 1)
		return (algo_bresenham_x(index_cpy, mtr, 0, dy / dx));
	else if (dx / dy < 1 && dx / dy >= 0)
		return (algo_bresenham_y(index_cpy, mtr, 0, dx / dy));
	else if (dx / dy < 0 && dx / dy > -1)
		return (algo_bresenham_yn(index_cpy, mtr, 0, dx / dy));
	else
		return (algo_bresenham_xn(index_cpy, mtr, 0, dy / dx));
	return (true);
}
