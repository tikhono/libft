/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 20:26:26 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/08 19:11:54 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int base)
{
	size_t		i;
	size_t		res;
	int			symbol;

	i = 0;
	while ((str[i] >= 0 && str[i] <= 20) || str[i] == ' ')
		++i;
	res = 0;
	symbol = 1;
	if (str[i] == '-')
		symbol = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	if (base == 16)
		i += 2;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'A' && str[i] <= 'F'))
	{
		res = res * base + ((str[i] >= 'A') ? str[i++] - 'A' + 10 : str[i++] - '0');
		if (res > 9223372036854775807U && symbol == 1)
			return (-1);
		if (res > 9223372036854775808U && symbol == -1)
			return (0);
	}
	return ((int)(res) * symbol);
}
