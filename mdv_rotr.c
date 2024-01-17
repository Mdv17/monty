#include "monty.h"

/**
 * mdv_rotr - rotates the stack to the bottom
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_rotr(stack_t **head, unsigned int line_number)
{
    stack_t *last; /* Pointer to the last element of the stack */

    (void)line_number; /* Unused parameter */
    last = *head;
    /* Check if the stack is empty or has only one element */
    if (*head == NULL || (*head)->next == NULL)
    {
        return 0; /* Return success */
    }
    /* Loop until the end of the stack */
    while (last->next)
    {
        last = last->next;
    }
    /* Move the last element to the top of the stack */
    last->next = *head;
    last->prev->next = NULL;
    last->prev = NULL;
    (*head)->prev = last;
    (*head) = last;
    /* Return success */
    return 0;
}
