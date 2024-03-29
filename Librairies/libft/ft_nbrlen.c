/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_nbrlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/23 16:36:08 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/23 16:54:01 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int t;
	int i;

	if (n > 0)
		n = -n;
	t = 1;
	i = 0;
	while (n / t <= -10)
	{
		t *= 10;
		i++;
	}
	return (i); 
}