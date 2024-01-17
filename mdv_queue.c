#include "monty.h"

/**
 * f_queue - prints the top of the stack
 * @head: stack head
 * @line_number: line number
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_queue(stack_t **head, unsigned int line_number)
{
    (void)head; /* Unused parameter */
    (void)line_number; /* Unused parameter */
    data.lifi = 1; /* Set the stack mode to queue */
    return 0; /* Return success */
}

/**
 * addqueue - add node to the end of the stack
 * @head: head of the stack
 * @value: value to be added
 * Return: 0 on success, EXIT_FAILURE on failure
 */
int mdv_addqueue(stack_t **head, int value)
{
    stack_t *new_node, *tail;

    tail = *head;
    new_node = malloc(sizeof(stack_t)); /* Allocate memory for the new node */
    if (new_node == NULL) /* Check if memory allocation failed */
    {
        printf("Error\n");
        return EXIT_FAILURE; /* Return failure */
    }
    new_node->n = value; /* Assign the value to the new node */
    new_node->next = NULL; /* Set the next pointer of the new node to NULL */
    if (tail) /* Check if the stack is not empty */
    {
        while (tail->next) /* Loop until the end of the stack */
            tail = tail->next;
    }
    if (!tail) /* Check if the stack is empty */
    {
        *head = new_node; /* Set the head to the new node */
        new_node->prev = NULL; /* Set the prev pointer of the new node to NULL */
    }
    else /* If the stack is not empty */
    {
        tail->next = new_node; /* Set the next pointer of the tail to the new node */
        new_node->prev = tail; /* Set the prev pointer of the new node to the tail */
    }
    return 0; /* Return success */
}
