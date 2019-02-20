/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorold- <dgorold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:31:18 by dgorold-          #+#    #+#             */
/*   Updated: 2019/02/13 12:42:23 by dgorold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		to_putchar(char c)
{
	unsigned char	tmp1;
	unsigned char	tmp2;

	if ((unsigned char)c < 128)
		write(1, &c, 1);
	else
	{
		tmp1 = 192 + (unsigned char)c / 64;
		tmp2 = 128 + (unsigned char)c % 64;
		write(1, &tmp1, 1);
		write(1, &tmp2, 1);
	}
}

void		input_figure(t_fig figures[ARRAY], t_pos *board, int i)
{
	int		bit;
	int		x;
	int		y;
	int		cnt;

	bit = 15;
	cnt = 0;
	figures[i].prev_y = board->y;
	figures[i].prev_x = board->x;
	while (bit >= 0)
	{
		if (cnt == 4)
			break ;
		if ((figures[i].figure >> bit) & 1)
		{
			cnt++;
			y = ((15 - bit) / 4);
			x = (15 - bit) - (y * 4);
			board->board[y + figures[i].prev_y][x + figures[i].prev_x] = i + 1;
		}
		bit--;
	}
}

void		print_board(t_pos board)
{
	board.y = 0;
	while (board.y < board.size)
	{
		board.x = 0;
		while (board.x < board.size)
		{
			if (board.board[board.y][board.x] == 0)
				to_putchar(46);
			else
				to_putchar((board.board[board.y][board.x]) + 64);
			board.x++;
		}
		write(1, "\n", 1);
		board.y++;
	}
	close(board.fd);
	exit(0);
}

int			possibility_of_placing(t_fig figures[ARRAY], t_pos board, int index)
{
	int		bit;
	int		y;
	int		x;
	int		cnt;

	bit = 15;
	cnt = 0;
	while (bit >= 0)
	{
		if (cnt == 4)
			break ;
		if ((figures[index].figure >> bit) & 1)
		{
			cnt++;
			y = ((15 - bit) / 4);
			x = (15 - bit) - y * 4;
			if (x + board.x >= board.size || y + board.y >= board.size ||
					board.board[y + board.y][x + board.x] != 0)
				return (0);
		}
		bit--;
	}
	return (1);
}

void		zero_form(t_fig figures[ARRAY], t_pos *board, int i)
{
	int		bit;
	int		x;
	int		y;

	bit = 15;
	while (bit >= 0)
	{
		if ((figures[i].figure >> bit) & 1)
		{
			y = ((15 - bit) / 4);
			x = (15 - bit) - (y * 4);
			board->board[y + figures[i].prev_y][x + figures[i].prev_x] = 0;
		}
		bit--;
	}
	figures[i].prev_y = -1;
	figures[i].prev_x = -1;
}
