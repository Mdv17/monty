#include "monty.h"

/**
 * mdv_pop - removes the top element of the stack
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_pop(stack_t **head, unsigned int line_number)
{
    stack_t *top; /* Pointer to the top of the stack */

    /* Check if the stack is empty */
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    /* Remove the top element and free its memory */
    top = *head;
    *head = top->next;
    free(top);
    /* Return success */
    return 0;
}

