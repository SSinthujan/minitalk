/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:34:48 by ssitchsa          #+#    #+#             */
/*   Updated: 2023/12/11 04:02:14 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_param(va_list args, char c, int i)
{
	if (c == 's')
		i += ft_putstr(va_arg(args, char *));
	else if (c == 'c')
		i += ft_putchar(va_arg(args, int));
	else if (c == 'p')
		i += ft_putptr(va_arg(args, size_t));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		i += ft_unsigned_putnbr(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_puthexa(va_arg(args, unsigned int), 'x');
	else if (c == 'X')
		i += ft_puthexa(va_arg(args, unsigned int), 'X');
	else if (c == '%')
		i += ft_putchar(c);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, s);
	if (!s)
		return (-1);
	while (s[j])
	{
		if (s[j] == '%')
		{
			j++;
			i = ft_param(args, s[j], i);
		}
		else
			i += write(1, &s[j], 1);
		j++;
	}
	va_end(args);
	return (i);
}
