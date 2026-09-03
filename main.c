/**************************************************************************************************************************************************************
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1 = NULL, *tail1 = NULL;
	Dlist *head2 = NULL, *tail2 = NULL;
	Dlist *headR = NULL, *tailR = NULL;
	char operator;

	if(argc != 4)
	{
        printf("Usage: ./a.out number1 operator number2\n");
        return 1;
	}

	/* Code for reading the inputs */
	if (argv[2][0] != '+' && argv[2][0] != '-' &&
    	argv[2][0] != 'x' && argv[2][0] != '/')
	{
    	printf("Error: Invalid operator\n");
    	return 1;
	}

operator = argv[2][0];

	/*To insert first operand to list*/
	for(int i=0; argv[1][i] != '\0'; i++)
	{
		if(isdigit(argv[1][i]))
		{
			insert_at_last(&head1, &tail1, argv[1][i] - '0');
		}
		else
			return 0;
	}

	for(int i=0; argv[3][i] != '\0'; i++)
	{
		if(isdigit(argv[3][i]))
		{
			insert_at_last(&head2, &tail2, argv[3][i] - '0');
		}
	}


	switch (operator)
	{
		case '+':
			/* call the function to perform the addition operation */
			break;
		case '-':	
			/* call the function to perform the subtraction operation */
			break;
		case 'x':	
			/* call the function to perform the multiplication operation */
			break;
		case '/':	
			/* call the function to perform the division operation */
			break;
		default:
			printf("Invalid Input:-( Try again...\n");
	}
		

	return 0;
}

void insert_at_last(Dlist **head, Dlist **tail, int data)
{
	Dlist *new = malloc(sizeof(Dlist));

	if(new == NULL)
	{
		return;
	}

	new->data = data;
	new->prev = NULL;
	new->next = NULL;

	if(*head = NULL)
	{
		*head = *tail = new;
	}
	else
	{
		new->prev = *tail;
		(*tail)->next = new;
		*tail = new;
	}
}