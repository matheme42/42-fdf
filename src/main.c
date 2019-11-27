/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 16:53:45 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 11:09:54 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_map		*get_the_map(int f, size_t *size_x, size_t *size_y, int *max)
{
	t_map	*list;
	t_map	*begin;
	char	*temp;

	*max = 0;
	if (!(list = malloc(sizeof(t_map))))
		mexit();
	list->prev = NULL;
	begin = list;
	while (get_next_line(f, &temp) > 0)
	{
		if (ft_count_and_check(temp, size_x))
			return (NULL);
		if (!(list->map = tab_atoi(ft_strsplit(temp, ' '), *size_x, max)))
			mexit();
		if (!(list->next = malloc(sizeof(t_map))))
			mexit();
		list->next->prev = list;
		list = list->next;
		free(temp);
		(*size_y)++;
	}
	list->next = NULL;
	close(f);
	return (begin);
}

void		initial_mtr(t_moniteur *m)
{
	m->sourisx = 0;
	m->sourisy = 0;
	m->projection = 1;
	m->seuil = 4;
	m->special = 1;
	m->degrader = false;
	m->ddd = true;
	m->switch_color = 0;
	m->color = 16777215;
	m->space = 2.0;
	m->ofx = WIN_SIZE_X / 2;
	m->ofy = WIN_SIZE_Y / 2 - m->size_y;
}

void		switch_color(t_moniteur *mtr, int up)
{
	if (!mtr->degrader && (mtr->switch_color == 1 || mtr->switch_color == 4))
	{
		mtr->switch_color == 1 ? ft_hub_d(&ft_real_color, up, mtr) : 0;
		mtr->switch_color == 4 ? ft_hub_d(&ft_color_desert, up, mtr) : 0;
		return ;
	}
	if (mtr->switch_color == 0)
		mtr->color = 16777215;
	else if (mtr->switch_color == 1)
		ft_real_color(mtr, up);
	else if (mtr->switch_color == 2)
		ft_degrader(mtr, up, 256);
	else if (mtr->switch_color == 3)
		ft_bicolor(mtr, up);
	else if (mtr->switch_color == 4)
		ft_color_desert(mtr, up);
}

int			main(int ac, char **av)
{
	t_moniteur	m;
	char		*buff;
	int			f;

	if (ac == 1 || ac > 2)
		return (usage(av[0], ac));
	else if ((f = open(av[1], O_RDONLY)) == -1)
		return (wrong_file(av[1]));
	else if (read(f, &buff, 0) == -1)
		return (wrong_read(av[1]));
	m.size_x = 0;
	m.size_y = 0;
	m.name = av[1];
	if (!(m.map = get_the_map(f, &m.size_x, &m.size_y, &m.max)))
		return (map_error(av[1]));
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y, av[1]);
	m.img_ptr = mlx_new_image(m.mlx_ptr, WIN_SIZE_X, WIN_SIZE_Y);
	m.img_str = mlx_get_data_addr(m.img_ptr, &(m.bpp), &(m.s_l), &(m.endian));
	initial_mtr(&m);
	print_image(&m);
	mlx_hook(m.win_ptr, 2, 1, deal_key, (void *)&m);
	mlx_mouse_hook(m.win_ptr, deal_mouse, (void *)&m);
	mlx_loop(m.mlx_ptr);
	return (0);
}
