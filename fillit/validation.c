/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgorold- <dgorold-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:22:53 by dgorold-          #+#    #+#             */
/*   Updated: 2019/02/15 11:57:19 by dgorold-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			stage1_of_validation(const char *str, long ret)
{
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	if (ret == 21 && str[20] != '\n')
		return (0);
	return (1);
}

int			stage2_of_validation(const char *str)
{
	int		elem1;
	int		elem2;

	elem1 = 0;
	elem2 = 0;
	while (*str)
	{
		if (*str == '.')
			elem1++;
		if (*str == '#')
			elem2++;
		str++;
	}
	if (elem1 != 12 || elem2 != 4)
		return (0);
	return (1);
}

int			stage3_of_validation(const char *str)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (i > 4 && str[i - 5] == '#')
				sum = sum + 1;
			if (i < 15 && str[i + 5] == '#')
				sum = sum + 1;
			if (str[i + 1] == '#')
				sum = sum + 1;
			if (str[i - 1] == '#' && i != 0)
				sum = sum + 1;
		}
		i++;
	}
	if (sum == 6 || sum == 8)
		return (1);
	return (0);
}

int			validation(const char *str, long ret)
{
	if (ret < 20)
		return (0);
	if (!stage1_of_validation(str, ret))
		return (0);
	if (!stage2_of_validation(str))
		return (0);
	if (!stage3_of_validation((char*)str))
		return (0);
	return (1);
}
