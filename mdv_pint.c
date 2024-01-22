#include "monty.h"

/**
 * mdv_pint - prints the value at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
void mdv_pint(stack_t **head, unsigned int line_number)
{
    /* Check if the stack is empty */
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    /* Print the value at the top and a new line */
    printf("%d\n", (*head)->n);
}
