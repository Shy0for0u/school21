/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorold- <dgorold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:26:32 by dgorold-          #+#    #+#             */
/*   Updated: 2019/02/04 15:20:45 by dgorold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			bit_shift(int fgr)
{
	if (!((fgr >> 15) & 1) && !((fgr >> 14) & 1) &&
	!((fgr >> 13) & 1) && !((fgr >> 12) & 1))
		fgr = bit_shift(fgr << 4);
	if (!((fgr >> 15) & 1) && !((fgr >> 11) & 1) &&
	!((fgr >> 7) & 1) && !((fgr >> 3) & 1))
		fgr = bit_shift(fgr << 1);
	return (fgr);
}

int			bin_to_int(char *str)
{
	int		total;

	total = 0;
	while (*str)
	{
		if (*str != '\n')
		{
			total *= 2;
			if (*str == '#')
				total += 1;
		}
		str++;
	}
	total = bit_shift(total);
	return (total);
}

int			reading_of_figures(int fd, t_fig figures[ARRAY])
{
	char	buff[BUFF_SIZE];
	long	ret;
	int		quantity;

	quantity = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		if (!validation(buff, ret))
			return (0);
		figures[quantity].figure = bin_to_int(buff);
		figures[quantity].prev_y = -1;
		figures[quantity].prev_x = -1;
		quantity++;
	}
	if (ret < 0 || buff[20] != '\0' || quantity > 26)
		return (0);
	return (quantity);
}

void		create_board(t_pos *board)
{
	int		k;
	int		h;

	k = 0;
	board->size++;
	while (k < board->size)
	{
		h = 0;
		while (h < board->size)
		{
			board->board[k][h] = 0;
			h++;
		}
		k++;
	}
}
