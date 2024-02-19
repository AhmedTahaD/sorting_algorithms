#include "sort.h"
/**
 * swap_node - function swaps 2 nodes in a doubly-linked list
 * @node1: address of the first node
 * @node2: address of the second node
 *
 */
void swap_node(listint_t *node1, listint_t *node2)
{
	if (node1->prev)
	{
		node1->prev->next = node2;
	}
	if (node2->next)
	{
		node2->next->prev = node1
	}
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: address of pointer to head node
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	i = (*list)->next;
	while (i)
	{
		j = i;
		i = i->next;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap_node(j->prev, j);
				if (!j->prev)
					*list = j;
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
