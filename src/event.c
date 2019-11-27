/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   event.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 15:18:28 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 10:45:03 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fdf.h"

int			deal_key3(int key, t_moniteur *mtr)
{
	if (key >= 82 && key <= 86)
		mtr->switch_color = key - 82;
	else if (key == 50)
	{
		if (mtr->special > 50)
			mtr->special = 1;
		mtr->special += 1;
	}
	else if (key == 15)
		initial_mtr(mtr);
	else if (key == 53)
		exit(1);
	return (0);
}

int			deal_key2(int key, t_moniteur *mtr)
{
	if (key == 0)
		mtr->sourisx -= 10;
	else if (key == 2)
		mtr->sourisx += 10;
	else if (key == 13)
		mtr->sourisy -= 10;
	else if (key == 1)
		mtr->sourisy += 10;
	else if (key == 67)
	{
		if (mtr->degrader)
			mtr->degrader = true;
		else
		{
			mtr->special = 1;
			mtr->degrader = false;
		}
	}
	else
		deal_key3(key, mtr);
	return (0);
}

int			deal_key(int key, void *data)
{
	t_moniteur *mtr;

	mtr = (t_moniteur *)data;
	if (key == 24 && mtr->seuil <= 255)
		mtr->seuil += 3;
	else if (key == 27 && mtr->seuil > 1)
		mtr->seuil -= 3;
	else if (key == 69)
		mtr->ddd = true;
	else if (key == 78)
		mtr->ddd = false;
	else if (key == 48)
	{
		if (mtr->projection == 1)
			mtr->projection = 2;
		else if (mtr->projection == 2)
			mtr->projection = 3;
		else
			mtr->projection = 1;
	}
	else
		deal_key2(key, mtr);
	print_image(mtr);
	return (0);
}

int			deal_mouse(int button, int x, int y, void *data)
{
	t_moniteur *mtr;

	x = 0;
	y = 0;
	mtr = (t_moniteur *)data;
	if (button == 5 && mtr->space < 40)
	{
		mtr->space += 0.2;
		print_image(mtr);
	}
	else if (button == 4 && mtr->space > 0.4)
	{
		mtr->space -= 0.2;
		print_image(mtr);
	}
	return (0);
}
