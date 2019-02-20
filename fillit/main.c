/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorold- <dgorold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:35:20 by dgorold-          #+#    #+#             */
/*   Updated: 2019/02/15 10:04:09 by dgorold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			placing_the_pieces(t_fig figures[ARRAY], t_pos board, int i)
{
	board.y = -1;
	while (board.y++ < board.size)
	{
		board.x = -1;
		while (board.x++ < board.size)
		{
			if ((board.x > figures[i].prev_x || board.y > figures[i].prev_y))
			{
				if (possibility_of_placing(figures, board, i))
				{
					input_figure(figures, &board, i);
					if (board.quantity == (i + 1))
						print_board(board);
					if (placing_the_pieces(figures, board, i + 1) == -1)
						zero_form(figures, &board, i);
				}
			}
		}
	}
	if ((i - 1) < 0)
	{
		create_board(&board);
		placing_the_pieces(figures, board, 0);
	}
	return (-1);
}

int			main(int argc, char *argv[])
{
	t_fig	figures[ARRAY];
	t_pos	board;
	char	buff[1];

	board.fd = open(argv[1], O_RDONLY);
	if (argc != 2)
	{
		close(board.fd);
		write(1, "usage: ./fillit [file]\n", 23);
		return (0);
	}
	if (board.fd == -1 || read(board.fd, buff, 0) ||
	!(board.quantity = reading_of_figures(board.fd, figures)))
	{
		if (board.fd != -1)
			close(board.fd);
		write(1, "error\n", 6);
		exit(0);
	}
	board.size = 63;
	create_board(&board);
	board.size = 1;
	placing_the_pieces(figures, board, 0);
	return (0);
}
