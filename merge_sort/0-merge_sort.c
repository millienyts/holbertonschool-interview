#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, int left, int mid, int right, int *temp)
{
    int i = left, j = mid + 1, k = left;

    // Print the merging step
    printf("Merging...\n");

    // Print the left array
    printf("[left]: ");
    for (int l = left; l <= mid; l++)
        printf("%d, ", array[l]);
    printf("\n");

    // Print the right array
    printf("[right]: ");
    for (int r = mid + 1; r <= right; r++)
        printf("%d, ", array[r]);
    printf("\n");

    // Merge the two subarrays
    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    // Copy any remaining elements from the left array
    while (i <= mid)
        temp[k++] = array[i++];

    // Copy any remaining elements from the right array
    while (j <= right)
        temp[k++] = array[j++];

    // Copy the sorted elements back into the original array
    for (i = left; i <= right; i++)
        array[i] = temp[i];

    // Print the merged array
    printf("[Done]: ");
    for (int i = left; i <= right; i++)
        printf("%d, ", array[i]);
    printf("\n");
}

void merge_sort_recursive(int *array, int left, int right, int *temp)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        // Recursively sort the left and right halves
        merge_sort_recursive(array, left, mid, temp);
        merge_sort_recursive(array, mid + 1, right, temp);

        // Merge the sorted halves
        merge(array, left, mid, right, temp);
    }
}

void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *temp = malloc(size * sizeof(int));
    if (temp == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    merge_sort_recursive(array, 0, size - 1, temp);

    free(temp);
}
