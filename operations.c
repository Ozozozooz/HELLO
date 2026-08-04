#include "pushswap.h"

void    ft_swap(t_stack **ab)
{
    t_stack *first;
    t_stack *second;

    if (!*ab || !(*ab)->next)
        return;

    first = *ab;
    second = (*ab)->next;
    first->prev = second;
    first->next = second->next;
    second->prev = NULL;
    second->next = first;
    if (first->next)
        first->next->prev = first;
    *ab = second;

}

void    sa(t_stack **a)
{
    ft_swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    ft_swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack **a, t_stack **b)
{
    ft_swap(a);
    ft_swap(b);
    write(1, "ss\n", 3);
}

void    pa(t_stack **b, t_stack **a)
{
    t_stack *temp_b;
    t_stack *temp_a;


    if(!*b)
        return;

    temp_b = *b;
    temp_a = *a;

    *b = temp_b->next;      //Assigning the pointer of second node as head
    if (*b)                 // Because temp_b->next could also be NULL
        (*b)->prev = NULL;

    *a = temp_b;            //Assigning node b as head, cant use 'b' here because its **
    temp_b->next = temp_a;
    temp_b->prev = NULL;
    if(temp_a)              //Becasue stack a could be empty
        temp_a->prev = temp_b;
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    t_stack *temp_a;
    t_stack *temp_b;


    if(!*a)
        return;

    temp_b = *b;
    temp_a = *a;

    *a = temp_a->next;      //Assigning the pointer of second node as head
    if (*a)                 // Because temp_a->next could also be NULL
        (*a)->prev = NULL;

    *b = temp_a;            //Assigning node a as head, cant use 'a' here because its **
    temp_a->next = temp_b;
    temp_a->prev = NULL;
    if(temp_b)              //Becasue stack a could be empty
        temp_b->prev = temp_a;
    write(1, "pb\n", 3);
}

void    ft_rotate(t_stack **ab)
{
    t_stack *temp;
    t_stack *tail;

    if (!(*ab) || !(*ab)->next)
        return;

    temp = *ab;
    tail = *ab;

    *ab = temp->next;
    (*ab)->prev = NULL;
    
    while (tail->next)
        tail = tail->next;

    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
}

void    ra(t_stack **a)
{
    ft_rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack **b)
{
    ft_rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack **a, t_stack **b)
{
    ft_rotate(a);
    ft_rotate(b);
    write(1, "rr\n", 3);
}

void    ft_reverse_rotate(t_stack **a)
{
    t_stack *last;

    if (!a || !(*a) || !(*a) ->next)
        return;

    last = *a;

    while (last ->next)
    {
        last = last ->next;
    }
    last ->prev ->next = NULL;
    last ->next = *a;
    (*a) ->prev = last;
    last -> prev = NULL;
    *a = last;
}

void    rra(t_stack **a)
{
    ft_reverse_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack **b)
{
    ft_reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack **a, t_stack **b)
{
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
    write(1, "rrr\n", 4);
}