#include "monty.h"

/* Define constants for ASCII range */
#define MAX_ASCII 127
#define MIN_ASCII 0

/**
 * mdv_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_pchar(stack_t **head, unsigned int counter)
{
    stack_t *top; /* Pointer to the top of the stack */

    top = *head;
    /* Check if the stack is empty */
    if (!top)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    /* Check if the value at the top is a valid ASCII character */
    if (top->n > MAX_ASCII || top->n < MIN_ASCII)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    /* Print the character and a new line */
    printf("%c\n", top->n);
    /* Return success */
    return 0;
}
