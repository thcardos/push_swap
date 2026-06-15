/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:22:02 by thcardos          #+#    #+#             */
/*   Updated: 2026/01/26 19:03:53 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_hex(unsigned int number, int is_uppercase)
{
	char	*hex_lowercase;
	char	*hex_uppercase;
	int		current_digit;

	hex_lowercase = "0123456789abcdef";
	hex_uppercase = "0123456789ABCDEF";
	if (number >= 16)
		ft_put_hex(number / 16, is_uppercase);
	current_digit = number % 16;
	if (is_uppercase)
		ft_putchar_fd(hex_uppercase[current_digit], 1);
	else
		ft_putchar_fd(hex_lowercase[current_digit], 1);
}

static int	ft_count_digits(unsigned int number)
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

int	ft_print_hex(unsigned int number, int is_uppercase)
{
	ft_put_hex(number, is_uppercase);
	return (ft_count_digits(number));
}
