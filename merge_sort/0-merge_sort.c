#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Merges two sorted sub-arrays into a sorted array.
 * @array: The array to be sorted.
 * @left: Left index of the array.
 * @right: Right index of the array.
 * @temp: Temporary array used to merge.
 */
void merge(int *array, int left, int mid, int right, int *temp)
{
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (array[i] <= array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }

    while (i <= mid)
        temp[k++] = array[i++];

    while (j <= right)
        temp[k++] = array[j++];

    for (i = left; i <= right; i++)
        array[i] = temp[i];
}

/**
 * merge_sort_recursive - Recursively divides the array and sorts each part.
 * @array: The array to be sorted.
 * @left: Left index of the array.
 * @right: Right index of the array.
 * @temp: Temporary array used to merge.
 */
void merge_sort_recursive(int *array, int left, int right, int *temp)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort_recursive(array, left, mid, temp);
        merge_sort_recursive(array, mid + 1, right, temp);
        merge(array, left, mid, right, temp);
    }
}

/**
 * merge_sort - Sorts an array using the merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    int *temp = malloc(sizeof(int) * size);
    if (temp == NULL)
        return;

    merge_sort_recursive(array, 0, size - 1, temp);
    free(temp);
}
