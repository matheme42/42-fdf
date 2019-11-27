/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   show.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/12/12 11:07:16 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 11:10:10 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

void	print_image(t_moniteur *mtr)
{
	black_screen(mtr);
	ft_putmap(mtr);
	mlx_put_image_to_window(mtr->mlx_ptr, mtr->win_ptr, mtr->img_ptr, 0, 0);
	ft_put_user_interface(mtr, 16777215);
}

void	ft_putmap(t_moniteur *mtr)
{
	size_t	x;
	size_t	y;
	double	idx[4];
	t_map	*begin;

	begin = mtr->map;
	y = 0;
	while (y < mtr->size_y)
	{
		x = 0;
		while (x < mtr->size_x)
		{
			if (mtr->projection == 1)
				iso_proj(mtr, x, y, idx);
			else if (mtr->projection == 2)
				face_proj(mtr, x, y, idx);
			else
				h_proj(mtr, x, idx);
			x++;
		}
		y++;
		mtr->map = mtr->map->next;
	}
	mtr->map = begin;
}

void	ft_put_user_interface_part_3(t_moniteur *mtr, int c, char *nb)
{
	void	*mp;
	void	*wp;

	mp = mtr->mlx_ptr;
	wp = mtr->win_ptr;
	mlx_string_put(mp, wp, 10, 10, c, mtr->name);
	mlx_string_put(mp, wp, 10, 220, c, "move: WASD");
	mlx_string_put(mp, wp, 10, 250, c, "reinitialiser: R");
	mlx_string_put(mp, wp, 10, 280, c, "quitter: esc");
	if (mtr->switch_color == 1 || mtr->switch_color == 4)
	{
		mlx_string_put(mp, wp, 10, 340, c, "special: *                 |");
		!mtr->degrader ? mlx_string_put(mp, wp, 300, 340, c, "ON") : 0;
		mtr->degrader ? mlx_string_put(mp, wp, 300, 340, c, "OFF") : 0;
		if (!mtr->degrader)
		{
			mlx_string_put(mp, wp, 10, 370, c, "numero: ~                  |");
			nb = ft_itoa(mtr->special);
			mlx_string_put(mp, wp, 300, 370, c, nb);
			free(nb);
		}
	}
}

void	ft_put_user_interface_part_2(t_moniteur *mtr, int color, char *nb)
{
	void	*mp;
	void	*wp;

	mp = mtr->mlx_ptr;
	wp = mtr->win_ptr;
	if (mtr->switch_color == 0)
		mlx_string_put(mp, wp, 300, 130, color, "blanc");
	else if (mtr->switch_color == 1)
		mlx_string_put(mp, wp, 300, 130, color, "couleur Terre");
	else if (mtr->switch_color == 2)
		mlx_string_put(mp, wp, 300, 130, color, "degrader blanc");
	else if (mtr->switch_color == 3)
		mlx_string_put(mp, wp, 300, 130, color, "bicolor");
	else if (mtr->switch_color == 4)
		mlx_string_put(mp, wp, 300, 130, color, "volcanique");
	if (mtr->switch_color == 2 || mtr->switch_color == 3)
	{
		mlx_string_put(mp, wp, 10, 160, color, "seuil: -\\+                 |");
		nb = ft_itoa(mtr->seuil);
		mlx_string_put(mp, wp, 300, 160, color, nb);
		free(nb);
	}
	ft_put_user_interface_part_3(mtr, color, nb);
}

void	ft_put_user_interface(t_moniteur *mtr, int color)
{
	char	*nb;
	void	*mp;
	void	*wp;

	mp = mtr->mlx_ptr;
	wp = mtr->win_ptr;
	mlx_string_put(mp, wp, 10, 40, color, "changer de projection: tab |");
	if (mtr->projection == 1)
		mlx_string_put(mp, wp, 300, 40, color, "isometrique");
	else if (mtr->projection == 2)
		mlx_string_put(mp, wp, 300, 40, color, "face");
	else
		mlx_string_put(mp, wp, 300, 40, color, "les hauteurs");
	if (mtr->projection == 1)
	{
		mlx_string_put(mp, wp, 10, 70, color, "contraste: +\\-   |");
		!mtr->ddd ? mlx_string_put(mp, wp, 300, 70, color, "ON") : 0;
		mtr->ddd ? mlx_string_put(mp, wp, 300, 70, color, "OFF") : 0;
	}
	mlx_string_put(mp, wp, 10, 100, color, "zoom: molette              |");
	nb = ft_itoa(mtr->space);
	mlx_string_put(mp, wp, 300, 100, color, nb);
	free(nb);
	mlx_string_put(mp, wp, 10, 130, color, "color: 0 - 4               |");
	ft_put_user_interface_part_2(mtr, color, nb);
}
