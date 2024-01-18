#include "monty.h"

/**
 * mdv_swap - swaps the top two elements of the stack
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_swap(stack_t **head, unsigned int line_number)
{
    stack_t *top; /* Pointer to the top of the stack */
    int size; /* Number of nodes in the stack */
    int temp; /* Temporary variable to store the value to be swapped */

    top = *head;
    size = 0;
    /* Count the number of nodes in the stack */
    while (top)
    {
        top = top->next;
        size++;
    }
    /* Check if the stack has at least two elements */
    if (size < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        fclose(data.file);
        free(data.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    top = *head;
    /* Swap the values of the top two elements */
    temp = top->n;
    top->n = top->next->n;
    top->next->n = temp;
    /* Return success */
    return 0;
}
