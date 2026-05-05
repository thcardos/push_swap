/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 19:04:25 by thcardos          #+#    #+#             */
/*   Updated: 2026/02/09 13:13:48 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex(unsigned long number)
{
	char	*hex_lowercase;
	int		current_digit;

	hex_lowercase = "0123456789abcdef";
	if (number >= 16)
		ft_put_hex(number / 16);
	current_digit = number % 16;
	ft_putchar_fd(hex_lowercase[current_digit], 1);
}

static int	ft_count_digits(unsigned long number)
{
	int	count;

	if (number == 0)
		return (1);
	count = 0;
	while (number > 0)
	{
		number /= 16;
		count++;
	}
	return (count);
}

int	ft_print_ptr(void *p)
{
	unsigned long	ptr_value;
	int				count;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ptr_value = (unsigned long)p;
	count = 0;
	ft_putstr_fd("0x", 1);
	count += 2;
	ft_put_hex(ptr_value);
	count += ft_count_digits(ptr_value);
	return (count);
}
