#include "../include/so_long.h"

t_node    *last_node(t_node *node)
{
    while (node->next)
    {
        node = node->next;
    }
    return (node);
}

void    delete_node(t_node *node)
{
    while (node->next && node->next->next)
    {
        node = node->next;
    }
    free (node->next);
    node->next = 0;
}

void    add_node_back(t_node  *new, t_node  *node)
{
    while (node->next != 0)
    {
        node = node->next;
    }
    node->next = new;
}

void    add_node_front(t_node *new, t_node **node)
{
    new->next = *node;
    *node = new;
}

t_node    *new_node(int   x, int  y)
{
    t_node    *node;
    node = 0;
    node = malloc(sizeof(node));

    node->x = x;
    node->y = y;
    node->next = 0;
    return (node);
}