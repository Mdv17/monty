#include "monty.h"

/**
 * mdv_sub - subtracts the top element of the stack from the second top element
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_sub(stack_t **head, unsigned int line_number)
{
    stack_t *top; /* Pointer to the top of the stack */
    int diff; /* Difference between the top two elements */
    int nodes; /* Number of nodes in the stack */

    top = *head;
    /* Count the number of nodes in the stack */
    for (nodes = 0; top != NULL; nodes++)
        top = top->next;
    /* Check if the stack has at least two elements */
    if (nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
        fclose(data.file);
        free(data.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    top = *head;
    /* Subtract the top element from the second top element */
    diff = top->next->n - top->n;
    /* Replace the second top element with the result */
    top->next->n = diff;
    /* Remove the top element and free its memory */
    *head = top->next;
    free(top);
    /* Return success */
    return 0;
}

