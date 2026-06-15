#include "push_swap.h"

static int	ft_abs(int n)
{
    if (n < 0)
        return (-n);
    return (n);
}

static int	stack_pos(t_stack *stack, t_node *node)
{
    t_node	*current;
    int		pos;

    current = stack->top;
    pos = 0;
    while (current)
    {
        if (current == node)
            return (pos);
        current = current->next;
        pos++;
    }
    return (0);
}

int	get_cost(t_stack *a, t_stack *b, t_node *node)
{
    int	pos_a;
    int	pos_b;

    pos_a = find_target_pos(a, node->val);
    pos_b = stack_pos(b, node);
    if (pos_a <= a->size / 2)
        node->cost_a = pos_a;
    else
        node->cost_a = pos_a - a->size;
    if (pos_b <= b->size / 2)
        node->cost_b = pos_b;
    else
        node->cost_b = pos_b - b->size;
    if ((node->cost_a >= 0 && node->cost_b >= 0)
        || (node->cost_a <= 0 && node->cost_b <= 0))
    {
        if (ft_abs(node->cost_a) > ft_abs(node->cost_b))
            return (ft_abs(node->cost_a));
        return (ft_abs(node->cost_b));
    }
    return (ft_abs(node->cost_a) + ft_abs(node->cost_b));
}

void	do_cheapest(t_stack *a, t_stack *b)
{
    t_node	*current;
    t_node	*cheapest;
    int		best;
    int		cost;

    if (!b || !b->top)
        return ;
    current = b->top;
    cheapest = current;
    best = get_cost(a, b, current);
    current = current->next;
    while (current)
    {
        cost = get_cost(a, b, current);
        if (cost < best)
        {
            best = cost;
            cheapest = current;
        }
        current = current->next;
    }
    exec_costs(a, b, cheapest->cost_a, cheapest->cost_b);
}
