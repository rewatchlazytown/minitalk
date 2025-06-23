/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akapusti <akapusti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:59:09 by akapusti          #+#    #+#             */
/*   Updated: 2023/05/25 15:32:59 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex(unsigned long i, int *len, char cases)
{
	char	*low;
	char	*upp;

	upp = "0123456789ABCDEF";
	low = "0123456789abcdef";
	if (i >= 16)
	{
		ft_hex(i / 16, len, cases);
		ft_hex(i % 16, len, cases);
	}
	else
	{
		if (cases == 'x')
			ft_putchar(low[i], len);
		else if (cases == 'X')
			ft_putchar(upp[i], len);
	}
}
