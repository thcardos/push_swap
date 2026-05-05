/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:45:45 by thcardos          #+#    #+#             */
/*   Updated: 2026/02/09 13:19:38 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_spec(const char *input, int *i, va_list args)
{
	char	spec;

	spec = input[*i + 1];
	if (spec == 'c')
		return (ft_print_char(va_arg(args, int)));
	if (spec == 's')
		return (ft_print_str(va_arg(args, char *)));
	if (spec == '%')
		return (ft_print_char('%'));
	if (spec == 'd' || spec == 'i')
		return (ft_print_int(va_arg(args, int)));
	if (spec == 'u')
		return (ft_print_uint(va_arg(args, unsigned int)));
	if (spec == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	if (spec == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	if (spec == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	return (0);
}

static int	ft_handle_percent(const char *input, int *i, va_list args)
{
	int	written;

	if (input[*i + 1] == '\0')
	{
		ft_putchar_fd('%', 1);
		(*i) += 1;
		return (1);
	}
	written = ft_handle_spec(input, i, args);
	(*i) += 2;
	return (written);
}

int	ft_printf(char const *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!input)
		return (0);
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%')
			count += ft_handle_percent(input, &i, args);
		else
		{
			ft_putchar_fd(input[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}
