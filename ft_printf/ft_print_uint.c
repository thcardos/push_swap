/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:06:15 by thcardos          #+#    #+#             */
/*   Updated: 2026/01/27 18:02:55 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_put_uint(unsigned int n)
{
	if (n >= 10)
		ft_put_uint(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}

int	ft_print_uint(unsigned int n)
{
	ft_put_uint(n);
	return (ft_count_digits(n));
}
