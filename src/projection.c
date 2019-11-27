/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   projection.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 12:18:36 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 11:09:15 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	iso_proj(t_moniteur *mt, size_t x, size_t y, double idx[4])
{
	idx[0] = x * mt->space - y * mt->space + mt->ofx + mt->sourisx;
	idx[1] = y * mt->space * 2 / 3 + mt->ofy + mt->sourisy;
	idx[1] += x * mt->space * 2 / 3 - mt->map->map[x] * !mt->ddd;
	if (mt->space < 1.2)
		idx[1] += (1.2 - mt->space) * mt->map->map[x] * !mt->ddd;
	if (x + 1 < mt->size_x)
	{
		idx[2] = (x + 1) * mt->space - y * mt->space + mt->ofx + mt->sourisx;
		idx[3] = y * mt->space * 2 / 3 + mt->ofy + mt->sourisy;
		idx[3] += (x + 1) * mt->space * 2 / 3 - mt->map->map[x + 1] * !mt->ddd;
		if (mt->space < 1.2)
			idx[3] += (1.2 - mt->space) * mt->map->map[x + 1] * !mt->ddd;
		switch_color(mt, max_beetween(mt->map->map[x], mt->map->map[x + 1]));
		algo_bresenham(idx, mt);
	}
	if (y + 1 < mt->size_y)
	{
		idx[2] = (x) * mt->space - (y + 1) * mt->space + mt->ofx + mt->sourisx;
		idx[3] = (y + 1) * mt->space * 2 / 3 + mt->ofy + mt->sourisy;
		idx[3] += x * mt->space * 2 / 3 - mt->map->next->map[x] * !mt->ddd;
		if (mt->space < 1.2)
			idx[3] += (1.2 - mt->space) * mt->map->next->map[x] * !mt->ddd;
		switch_color(mt, max_beetween(mt->map->map[x], mt->map->next->map[x]));
		algo_bresenham(idx, mt);
	}
}

void	face_proj(t_moniteur *mt, size_t x, size_t y, double idx[4])
{
	idx[0] = x * mt->space;
	idx[0] = idx[0] + mt->ofx + mt->sourisx;
	if (idx[0] < 0)
		return ;
	idx[1] = y * mt->space + mt->ofy + mt->sourisy;
	if (x + 1 < mt->size_x)
	{
		idx[2] = (x + 1) * mt->space;
		idx[2] = idx[2] + mt->ofx + mt->sourisx;
		idx[3] = y * mt->space + mt->ofy + mt->sourisy;
		switch_color(mt, max_beetween(mt->map->map[x], mt->map->map[x + 1]));
		algo_bresenham(idx, mt);
	}
	if (y + 1 < mt->size_y)
	{
		idx[2] = x * mt->space;
		idx[2] = idx[2] + mt->ofx + mt->sourisx;
		idx[3] = (y + 1) * mt->space + mt->ofy + mt->sourisy;
		switch_color(mt, max_beetween(mt->map->map[x], mt->map->next->map[x]));
		algo_bresenham(idx, mt);
	}
}

void	h_proj(t_moniteur *mt, size_t x, double idx[4])
{
	if (mt->space > 1)
		mt->space = 1;
	idx[0] = x * mt->space;
	idx[0] = idx[0] + mt->ofx + mt->sourisx;
	idx[1] = mt->ofy + mt->sourisy;
	if (x + 1 < mt->size_x)
	{
		idx[2] = x * mt->space;
		idx[2] = idx[2] + mt->ofx + mt->sourisx;
		idx[3] = -mt->map->map[x] * mt->space + mt->ofy + mt->sourisy;
		switch_color(mt, max_beetween(mt->map->map[x], mt->map->map[x + 1]));
		algo_bresenham(idx, mt);
	}
}
