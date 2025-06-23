/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akapusti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:32:50 by akapusti          #+#    #+#             */
/*   Updated: 2023/02/17 17:38:04 by akapusti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdarg.h> 
# include <stddef.h> 

void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	ft_hex(unsigned long i, int *len, char cases);
void	ft_pointer(void *ptr, int *len);
void	ft_string(char *str, int *len);
void	ft_unsigned(unsigned int i, int *len);
void	ft_format(const char *format, va_list args, int *len);
int		ft_printf(const char *format, ...);

#endif
