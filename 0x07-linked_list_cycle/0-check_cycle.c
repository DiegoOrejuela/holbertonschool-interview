#include "lists.h"
/**
 * check_cycle - checks if a singly linked list has a cycle in it.
 * @list: pointer to head of list
 * Return: 1 if is a cycle; 0 is not.
 */
int check_cycle(listint_t *list)
{
	listint_t *p1;
	listint_t *p2;

	if (list == NULL)
		return(0);

	p1 = list;
	p2 = (*list).next;

	for (; p2 != NULL && (*p2).next != NULL; p1 = (*p1).next)
	{
		if (p1 == p2)
			return (1);
		p2 = (*(*p2).next).next;
	}
	return (0);
}
