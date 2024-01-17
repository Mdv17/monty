#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", mdv_push}, {"pall", mdv_pall}, {"pint", mdv_pint},
				{"pop", mdv_pop},
				{"swap", mdv_swap},
				{"add", mdv_add},
				{"nop", mdv_nop},
				{"sub", mdv_sub},
				{"div", mdv_div},
				{"mul", mdv_mul},
				{"mod", mdv_mod},
				{"pchar", mdv_pchar},
				{"pstr", mdv_pstr},
				{"rotl", mdv_rotl},
				{"rotr", mdv_rotr},
				{"queue", mdv_queue},
				{"stack", mdv_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
