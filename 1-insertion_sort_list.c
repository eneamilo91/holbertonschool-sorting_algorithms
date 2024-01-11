#include"sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list
 * @node1: First node to be swapped
 * @node2: Second node to be swapped
 */

void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;

	node2->next = node1;
	node1->prev = node2;

	if (node2->prev == NULL)
		*list = node2;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The doubly linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *virtual;	

	if (*list == NULL || list == NULL)
		return;

	virtual = (*list)->next;
	while (virtual)
	{
		while (virtual->prev && virtual->prev->n > virtual->n)
		{
			swap_nodes(list, virtual->prev, virtual);
			print_list(*list);
		}
		virtual = virtual->next;
	}
}
