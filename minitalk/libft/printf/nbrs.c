/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssitchsa <ssitchsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:05:20 by ssitchsa          #+#    #+#             */
/*   Updated: 2023/12/11 05:02:10 by ssitchsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

int	ft_unsigned_putnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	else
		i += ft_putchar(n + 48);
	return (i);
}

int	ft_puthexa(unsigned long n, char c)
{
	int		i;
	char	*hex;
	char	*hexa;

	i = 0;
	hex = "0123456789abcdef";
	hexa = "0123456789ABCDEF";
	if (n < 16 && c == 'x')
		i += write(1, &hex[n], 1);
	else if (n < 16 && c == 'X')
		i += write(1, &hexa[n], 1);
	else if (n >= 16)
	{
		i += ft_puthexa(n / 16, c);
		i += ft_puthexa(n % 16, c);
	}
	return (i);
}

int	ft_putptr(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i += ft_putstr("(nil)");
		return (i);
	}
	else
	{
		i += ft_putstr("0x");
		i += ft_puthexa(n, 'x');
	}
	return (i);
}
