/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcardos <thcardos@student.42malaga.co>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 16:03:43 by thcardos          #+#    #+#             */
/*   Updated: 2026/06/15 19:48:56 by thcardos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	free_tokens(char **tokens)
{
    int	i;

    if (!tokens)
        return ;
    i = 0;
    while (tokens[i])
    {
        free(tokens[i]);
        i++;
    }
    free(tokens);
}

static int	has_duplicate(t_stack *stack, int val)
{
    t_node	*current;

    current = stack->top;
    while (current)
    {
        if (current->val == val)
            return (1);
        current = current->next;
    }
    return (0);
}
int	ft_atol_check(const char *str, long *out)
{
    long	result;
    int		sign;
    int		i;

    result = 0;
    sign = 1;
    i = 0;
    if (!str || !str[0])
        return (0);
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        result = result * 10 + (str[i++] - '0');
    }
    *out = result * sign;
    return (1);
}
static int	fill_stack(t_stack *stack, char **args, int start)
{
    int		i;
    long	num;

    i = start;
    while (args[i])
        i++;
    while (--i >= start)
    {
        if (!ft_atol_check(args[i], &num) || num < INT_MIN || num > INT_MAX)
            return (0);
        if (has_duplicate(stack, (int)num))
            return (0);
        stack_push(stack, (int)num);
    }
    return (1);
}

t_stack	*parse_args(int argc, char **argv)
{
    t_stack	*stack;
    char	**tokens;

    if (argc <= 1)
        return (NULL);
    stack = stack_new();
    if (!stack)
        return (NULL);
    if (argc == 2 && ft_strchr(argv[1], ' '))
    {
        tokens = ft_split(argv[1], ' ');
        if (!tokens || !fill_stack(stack, tokens, 0))
            return (free_tokens(tokens), free_stack(stack), NULL);
        free_tokens(tokens);
    }
    else if (!fill_stack(stack, argv, 1))
        return (free_stack(stack), NULL);
    return (stack);
}
