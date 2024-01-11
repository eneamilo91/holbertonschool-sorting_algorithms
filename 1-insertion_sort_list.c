#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head of the doubly linked list.
 * @node: Node to swap with its previous node.
*/
void swap_nodes(listint_t **list, listint_t *node)
{
	node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;
	node->next = node->prev;
	node->prev = node->prev->prev;
	node->next->prev = node;
	if (node->prev != NULL)
		node->prev->next = node;
	else
		*list = node;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while (current->prev != NULL && current->n < current->prev->n)
		{
			swap_nodes(list, current);
			print_list((const listint_t *)*list);
		}
		current = current->next;
	}
}
