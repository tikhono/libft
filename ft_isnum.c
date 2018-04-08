/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atikhono <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/08 17:01:26 by atikhono          #+#    #+#             */
/*   Updated: 2018/04/08 17:10:41 by atikhono         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnum(char *num, int base)
{
	char	*c;

	if (num)
	{
		c = num;
		if ((*c == '-' || *c == '+') && base == 10)
			++c;
		if ((*c == '0') && base == 16)
		{
			++c;
			if (*c == 'x')
				++c;
		}
		while (*c != '\0')
		{
			if (!ft_isdigit(*c) && !((base == 16) && (*c >= 'A' && *c <= 'F')))
				return (0);
			++c;
		}
		return (1);
	}
	return (0);
}
