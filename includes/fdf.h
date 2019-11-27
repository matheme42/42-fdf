/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 12:11:45 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 10:51:58 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_SIZE_X 2000
# define WIN_SIZE_Y 1500

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

enum	e_bool
{
	true = 0,
	false = 1
};

typedef enum e_bool	t_bool;

typedef struct		s_map
{
	int				*map;
	struct s_map	*next;
	struct s_map	*prev;
}					t_map;

typedef struct		s_moniteur
{
	char			*name;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;

	char			*img_str;
	int				bpp;
	int				s_l;
	int				endian;

	t_bool			degrader;
	double			special;
	int				color;
	int				seuil;
	int				switch_color;

	t_bool			ddd;
	double			space;
	int				ofx;
	int				ofy;
	int				sourisx;
	int				sourisy;

	struct s_map	*map;
	size_t			size_x;
	size_t			size_y;

	int				min;
	int				max;
	int				projection;
}					t_moniteur;

/*
** fonction d'erreeur
*/
t_bool				wrong_file(char *file_name);
t_bool				wrong_read(char *file_name);
t_bool				usage(char *prog_name, int ac);
t_bool				full_ac(char *prog_name);
t_bool				map_error(char *map_name);
void				mexit();
/*
** fonction de parsing et de check
*/
int					*tab_atoi(char **tab, int size, int *max);
t_bool				ft_count_and_check(char *str, size_t *ref);

/*
** fonction d'affichage de la carte
*/
t_map				*get_the_map(int f, size_t *sizex, size_t *sizey, int *m);
void				initial_mtr(t_moniteur *m);
void				print_image(t_moniteur *mtr);
void				show_t_map(t_moniteur *mtr);
void				ft_putmap(t_moniteur *mtr);
void				iso_proj(t_moniteur *m, size_t x, size_t y, double i[4]);
void				face_proj(t_moniteur *m, size_t x, size_t y, double i[4]);
void				h_proj(t_moniteur *m, size_t x, double i[4]);
void				ft_put_user_interface(t_moniteur *mtr, int color);
t_bool				algo_bresenham(double index[4], t_moniteur *mtr);

void				ft_degrader(t_moniteur *mtr, int up, int dup);
void				ft_bicolor(t_moniteur *mtr, int up);
void				ft_real_color(t_moniteur *mtr, int up);
void				ft_color_desert(t_moniteur *mtr, int up);
void				ft_hub_d(void f(t_moniteur *, int), int u, t_moniteur *m);
void				switch_color(t_moniteur *mtr, int up);

t_bool				fill_pixel(t_moniteur *mtr, int x, int y);
void				black_screen(t_moniteur *mtr);
/*
** fonction d'event
*/
int					deal_mouse(int button, int x, int y, void *data);
int					deal_key(int key, void *data);

#endif
