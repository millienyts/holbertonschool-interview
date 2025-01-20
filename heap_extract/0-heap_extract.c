#include "binary_trees.h"

/**
 * calculate_size - Calculates the size of the heap.
 * @root: Pointer to the root node of the heap.
 *
 * Return: The total number of nodes in the heap.
 */
int calculate_size(heap_t *root)
{
    if (!root)
        return (0);
    return (1 + calculate_size(root->left) + calculate_size(root->right));
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
    heap_t *queue[1024];
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
 * swap - Swaps two integer values.
 * @a: First integer.
 * @b: Second integer.
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
 * heap_extract - Extracts the root node of a Max Binary Heap.
 * @root: Double pointer to the root node.
 *
 * Return: Value of the extracted root node, or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return (0);

    int value = (*root)->n;

    int size = calculate_size(*root); // Calculate the size of the heap
    heap_t *last = find_last_node(*root, size); // Find the last node

    if (*root == last) // Only one node in the heap
    {
        free(*root);
        *root = NULL;
        return (value);
    }

    (*root)->n = last->n;

    // Disconnect the last node from its parent
    if (last->parent)
    {
        if (last->parent->left == last)
            last->parent->left = NULL;
        else
            last->parent->right = NULL;
    }

    free(last); // Free the last node
    heapify_down(*root); // Restore the Max-Heap property

    return (value);
}
