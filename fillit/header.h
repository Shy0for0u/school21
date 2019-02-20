/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorold- <dgorold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:32:29 by dgorold-          #+#    #+#             */
/*   Updated: 2019/02/15 10:04:09 by dgorold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_HEADER_H
# define FILLIT_HEADER_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# define BUFF_SIZE 21
# define ARRAY 26

typedef struct	s_fig
{
	int			prev_y;
	int			prev_x;
	int			figure;
}				t_fig;

typedef struct	s_pos
{
	int			fd;
	int			quantity;
	int			y;
	int			x;
	int			size;
	int			board[64][64];
}				t_pos;

int				stage1_of_validation(const char *str, long ret);
int				stage2_of_validation(const char *str);
int				stage3_of_validation(const char *str);
int				validation(const char *str, long ret);
int				bit_shift(int fgr);
int				bin_to_int(char *str);
void			to_putchar(char c);
int				reading_of_figures(int fd, t_fig figures[ARRAY]);
void			create_board(t_pos *board);
void			input_figure(t_fig figures[ARRAY], t_pos *board, int index);
void			print_board(t_pos board);
int				possibility_of_placing(t_fig figures[ARRAY],
		t_pos board, int index);
void			zero_form(t_fig figures[ARRAY], t_pos *board, int index);

#endif
