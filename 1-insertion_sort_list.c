#include"sort.h"

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    listint_t *prev_node1 = node1->prev;
    listint_t *next_node2 = node2->next;

    if (prev_node1 != NULL)
        prev_node1->next = node2;
    else
        *list = node2;

    if (next_node2 != NULL)
        next_node2->prev = node1;
    
    node2->prev = prev_node1;
    node1->next = next_node2;
    node2->next = node1;
    node1->prev = node2;
}





void insertion_sort_list(listint_t **list)
{
	listint_t *virtual = *list;	

	if (*list == NULL || (*list)->next == NULL)
		return;

	while (virtual->next != NULL)
	{
		if (virtual->n > virtual->next->n)
		{
			swap_nodes(list, virtual, virtual->next);
			print_list(*list);
			while (virtual->prev != NULL)
			{
				if (virtual->prev->n > virtual->n)
				{
					swap_nodes(list, virtual->prev, virtual);
					print_list(*list);
				}
				virtual = virtual->prev;
			}
		}
		virtual = virtual->next;
	}
}
