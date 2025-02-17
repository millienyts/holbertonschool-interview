#ifndef LIST_H
#define LIST_H

/**
 * struct List - Doubly linked list node structure
 * @str: String (malloc'ed string)
 * @prev: Points to the previous node
 * @next: Points to the next node
 *
 * Description: Structure for a double circular linked list node
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/* Function prototypes */
List *add_node_end(List **list, char *str);
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
