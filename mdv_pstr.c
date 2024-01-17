#include "monty.h"

/**
 * mdv_pstr - prints the string starting at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_pstr(stack_t **head, unsigned int line_number)
{
    stack_t *top; /* Pointer to the top of the stack */

    (void)line_number; // Unused parameter
    top = *head;
    /* Loop through the stack and print each character until a non-printable one is found */
    while (top)
    {
        if (top->n > 127 || top->n <= 0)
        {
            break;
        }
        printf("%c", top->n);
        top = top->next;
    }
    printf("\n");
    /* Return success */
    return 0;
}

