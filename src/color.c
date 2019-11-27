/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/07 14:33:48 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 11:12:16 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	ft_degrader(t_moniteur *mtr, int up, int dup)
{
	double	degre;
	int		color;

	degre = (double)up / mtr->max * mtr->seuil;
	if (degre <= 0.01)
		degre = 0;
	if (degre > 1)
		degre = 1;
	color = (dup - 1) * degre;
	mtr->color = color + color * dup + color * dup * dup;
}

void	ft_bicolor(t_moniteur *mtr, int up)
{
	double	degre;
	int		color;

	degre = (double)up / mtr->max * mtr->seuil;
	if (degre <= 0.5)
		degre = 0;
	if (degre > 0.5)
		degre = 1;
	color = 255 * degre;
	mtr->color = color + color * 256 + color * 256 * 256;
}

void	ft_real_color(t_moniteur *mtr, int up)
{
	double u;
	double max;

	u = (double)up;
	max = mtr->max;
	if (max == 0)
		max = 1;
	u / max <= 0.0004 ? mtr->color = 255 : 0;
	u / max > 0.0004 && u / max <= 0.01 ? mtr->color = 16777062 : 0;
	u / max > 0.01 && u / max <= 0.02 ? mtr->color = 13434675 : 0;
	u / max > 0.02 && u / max <= 0.05 ? mtr->color = 39219 : 0;
	u / max > 0.05 && u / max <= 0.1 ? mtr->color = 3368448 : 0;
	u / max > 0.1 && u / max <= 0.17 ? mtr->color = 6710835 : 0;
	u / max > 0.17 && u / max <= 0.21 ? mtr->color = 6697728 : 0;
	u / max > 0.21 && u / max <= 0.25 ? mtr->color = 5057289 : 0;
	u / max > 0.25 && u / max <= 0.32 ? mtr->color = 10066278 : 0;
	u / max > 0.32 && u / max <= 0.4 ? mtr->color = 9340542 : 0;
	u / max > 0.4 && u / max <= 0.45 ? mtr->color = 11972521 : 0;
	u / max > 0.45 && u / max <= 0.6 ? mtr->color = 16184562 : 0;
	u / max > 0.6 && u / max <= 0.7 ? mtr->color = 16578805 : 0;
	u / max > 0.7 ? mtr->color = 16777215 : 0;
}

void	ft_color_desert(t_moniteur *mtr, int up)
{
	double u;
	double max;

	u = (double)up;
	max = mtr->max;
	if (max == 0)
		max = 1;
	u / max <= 0.0004 ? mtr->color = 1710592 : 0;
	u / max > 0.0004 && u / max <= 0.01 ? mtr->color = 14732713 : 0;
	u / max > 0.01 && up / max <= 0.02 ? mtr->color = 11438436 : 0;
	u / max > 0.02 && up / max <= 0.05 ? mtr->color = 9256996 : 0;
	u / max > 0.05 && u / max <= 0.1 ? mtr->color = 16289365 : 0;
	u / max > 0.1 && u / max <= 0.17 ? mtr->color = 13125913 : 0;
	u / max > 0.17 && u / max <= 0.21 ? mtr->color = 15794176 : 0;
	u / max > 0.21 && u / max <= 0.25 ? mtr->color = 11016193 : 0;
	u / max > 0.25 && u / max <= 0.32 ? mtr->color = 8717830 : 0;
	u / max > 0.32 && u / max <= 0.4 ? mtr->color = 5570817 : 0;
	u / max > 0.4 && u / max <= 0.45 ? mtr->color = 7538688 : 0;
	u / max > 0.45 && u / max <= 0.6 ? mtr->color = 5898240 : 0;
	u / max > 0.6 && u / max <= 0.7 ? mtr->color = 3670016 : 0;
	u / max > 0.7 ? mtr->color = 1906712 : 0;
}

void	ft_hub_d(void f(t_moniteur *, int), int u, t_moniteur *m)
{
	static double	palier[14] = {0.0004, 0.01, 0.02, 0.05, 0.1, 0.17, 0.21,
		0.25, 0.32, 0.4, 0.45, 0.6, 0.7, 1.1};
	size_t			i;
	int				r;
	int				g;
	int				b;

	i = 0;
	while (palier[i] < (double)u / (double)m->max)
		i++;
	f(m, palier[i] * m->max);
	r = m->color / 256 / 256 * m->special;
	r = r * 256 * 256;
	g = ((m->color / 256) % 256) * m->special;
	g = g * 256;
	b = (m->color % 256) * m->special;
	m->color = r + g + b;
}
