#include "binary_trees.h"

/**
 * binary_tree_size - Computes the size of the binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree (number of nodes).
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

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
	heap_t **queue = malloc(sizeof(heap_t *) * size);
	int front = 0, rear = 0;
	heap_t *last = NULL;

	if (!queue)
		return (NULL);

	queue[rear++] = root;

	while (front < rear)
	{
		last = queue[front++];

		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	free(queue);
	return (last);
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
	size_t size;
	heap_t *last;

	if (!root || !*root)
		return (0);

	size = binary_tree_size(*root);
	last = find_last_node(*root, size);

	if (!last)
		return (0);

	value = (*root)->n;

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
