/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alorilee <alorilee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 19:11:26 by alorilee          #+#    #+#             */
/*   Updated: 2020/05/16 22:17:18 by alorilee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumber(char *str)
{
	int		i;
	int		digits;

	i = 0;
	digits = ft_strlen(str);
	while (ft_isdigit(str[i]) == 1)
		i++;
	return (i == digits);
}
