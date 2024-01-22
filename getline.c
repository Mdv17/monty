#include "monty.h"

/* This function reads a line from a stream and stores it in a buffer */
int getline(char **buffer, size_t *size, FILE *stream) {
    int ch; /* The character read from the stream */
    int len = 0; /* The length of the line */
    size_t capacity = *size; /* The capacity of the buffer */

    /* Check if the buffer is NULL or the size is zero */
    if (buffer == NULL || size == NULL) {
        return -1; /* Return error */
    }

    /* Check if the buffer is not allocated or the capacity is too small */
    if (*buffer == NULL || capacity < 2) {
        capacity = 16; /* Set a default capacity */
        *buffer = realloc(*buffer, capacity); /* Reallocate the buffer */
        if (*buffer == NULL) {
            return -1; /* Return error if allocation fails */
        }
    }

    /* Loop until a newline, end of file, or error is encountered */
    while ((ch = fgetc(stream)) != '\n' && ch != EOF && ch != -1) {
        /* Check if the buffer is full */
        if (len == (int)(capacity - 1)) {
            capacity *= 2; /* Double the capacity */
            *buffer = realloc(*buffer, capacity); /* Reallocate the buffer */
            if (*buffer == NULL) {
                return -1; /* Return error if allocation fails */
            }
        }
        /* Append the character to the buffer */
        (*buffer)[len++] = ch;
    }

    /* Check if an error occurred */
    if (ch == -1 && len == 0) {
        return -1; /* Return error */
    }

    /* Null-terminate the buffer */
    (*buffer)[len] = '\0';

    /* Update the size */
    *size = capacity;

    /* Return the length of the line */
    return len;
}

