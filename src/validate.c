/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   validate.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 14:04:52 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/10 16:06:57 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

t_bool			ft_count_and_check(char *str, size_t *ref)
{
	size_t res;

	res = 0;
	if (*ref == 0)
		*ref = nb_word(str, ' ');
	res = nb_word(str, ' ');
	if (res != *ref)
		return (false);
	return (true);
}
