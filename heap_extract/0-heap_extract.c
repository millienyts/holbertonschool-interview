#include "binary_trees.h"

/**
 * swap - Swaps the values of two nodes.
 * @a: First node.
 * @b: Second node.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify_down - Restores the Max-Heap property by sifting down.
 * @node: Pointer to the current node.
 */
void heapify_down(heap_t *node)
{
	heap_t *largest = node;

	if (node->left && node->left->n > largest->n)
		largest = node->left;

	if (node->right && node->right->n > largest->n)
		largest = node->right;

	if (largest != node)
	{
		swap(&node->n, &largest->n);
		heapify_down(largest);
	}
}

/**
 * find_last_node - Finds the last node in level-order traversal.
 * @root: Pointer to the root of the heap.
 * @size: Total size of the heap.
 *
 * Return: Pointer to the last node.
 */
heap_t *find_last_node(heap_t *root, int size)
{
	heap_t *queue[1024]; /* Assuming max nodes <= 1024 */
	int front = 0, rear = 0, i;

	queue[rear++] = root;

	for (i = 0; i < size; i++)
	{
		heap_t *node = queue[front++];

		if (node->left)
			queue[rear++] = node->left;

		if (node->right)
			queue[rear++] = node->right;
	}

	return (queue[front - 1]);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node.
 *
 * Return: Value of the extracted root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
	int value;
	heap_t *last;

	if (!root || !*root)
		return (0);

	value = (*root)->n;
	last = find_last_node(*root, 1024); /* Placeholder for actual size function */

	if (*root == last)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	(*root)->n = last->n;

	if (last->parent->left == last)
		last->parent->left = NULL;
	else
		last->parent->right = NULL;

	free(last);
	heapify_down(*root);

	return (value);
}
