#include "monty.h"

/**
 * mdv_push - add node to the stack
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_push(stack_t **head, unsigned int line_number)
{
    int value; /* Value to be added to the stack */
    int index = 0; /* Index to loop through the argument */
    int invalid = 0; /* Flag to indicate invalid argument */

    /* Check if the argument is given */
    if (bus.arg)
    {
        /* Check if the argument is negative */
        if (bus.arg[0] == '-')
            index++;
        /* Loop through the argument and check if it is a valid integer */
        for (; bus.arg[index] != '\0'; index++)
        {
            if (bus.arg[index] > 57 || bus.arg[index] < 48)
                invalid = 1;
        }
        /* If the argument is invalid, print an error message and exit */
        if (invalid == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    /* If the argument is not given, print an error message and exit */
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    /* Convert the argument to an integer */
    value = atoi(bus.arg);
    /* Check if the stack mode is LIFO or FIFO */
    if (bus.lifi == 0)
        /* Add the node to the beginning of the stack */
        addnode(head, value);
    else
        /* Add the node to the end of the stack */
        addqueue(head, value);
    /* Return success */
    return 0;
}
