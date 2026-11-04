#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *arr = NULL;
    int *temp = NULL;
    int i;
    int initial_size = 3;
    int new_size = 5;

    /* 1. Allocate initial memory for 3 integers */
    arr = (int *)malloc(initial_size * sizeof(int));
    if (arr == NULL)
    {
        fprintf(stderr, "Initial memory allocation failed.\n");
        return 1;
    }

    /* Initialize and print initial array */
    for (i = 0; i < initial_size; i++)
    {
        arr[i] = (i + 1) * 10; /* 10, 20, 30 */
    }

    printf("Initial array: ");
    for (i = 0; i < initial_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* 2. Resize the array to hold 5 integers using realloc */
    /* ALWAYS assign to a temporary pointer first to prevent memory leaks on failure */
    temp = (int *)realloc(arr, new_size * sizeof(int));

    if (temp == NULL)
    {
        fprintf(stderr, "Resizing memory failed. Original memory is still valid.\n");
        free(arr); /* Clean up original memory before exiting */
        return 1;
    }

    /* Reallocation succeeded, safely overwrite the original pointer */
    arr = temp;

    /* Initialize the newly added elements */
    for (i = initial_size; i < new_size; i++)
    {
        arr[i] = (i + 1) * 10; /* 40, 50 */
    }

    /* Print the resized array */
    printf("Resized array: ");
    for (i = 0; i < new_size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    /* 3. Always free dynamically allocated memory */
    free(arr);
    arr = NULL;

    return 0;
}
