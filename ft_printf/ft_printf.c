/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akapusti <akapusti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:40:58 by akapusti          #+#    #+#             */
/*   Updated: 2023/02/18 15:26:23 by akapusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char *format, va_list args, int *len)
{
	if (*format == 'c')
		ft_putchar(va_arg(args, int), len);
	else if (*format == 's')
		ft_string(va_arg(args, char *), len);
	else if (*format == 'p')
		ft_pointer(va_arg(args, void *), len);
	else if (*format == 'd')
		ft_putnbr(va_arg(args, int), len);
	else if (*format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (*format == 'u')
		ft_unsigned(va_arg(args, unsigned int), len);
	else if (*format == 'x')
		ft_hex(va_arg(args, unsigned int), len, 'x');
	else if (*format == 'X')
		ft_hex(va_arg(args, unsigned int), len, 'X');
	else if (*format == '%')
		ft_putchar('%', len);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_format(format, args, &len);
			format++;
		}
		else
			ft_putchar(*format++, &len);
	}
	va_end(args);
	return (len);
}
