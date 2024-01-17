#include "monty.h"

/**
 * mdv_stack - prints the top of the stack
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_stack(stack_t **head, unsigned int line_number)
{
    (void)head; /* Unused parameter */
    (void)line_number; /* Unused parameter */
    bus.lifi = 0; /* Set the stack mode to stack */
    return 0; /* Return success */
}
