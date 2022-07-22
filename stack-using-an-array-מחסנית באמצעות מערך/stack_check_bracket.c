#include <stdio.h>
#include "stack_arr.h"

/*
	Question 3:
	Make sure to change stack_type to char
*/

int checkBracket(char *str)
{
	int i=0;
	char temp;
	stack s1;
	create_stack(&s1);

	while (str[i] != '\0')
	{
		switch (str[i])
		{
			case '{':
			case '[':
			case '(':	push(str[i],&s1);	break;
			case '}':	if (!pop(&s1,&temp) || (temp != '{')) return 0;	break;
			case ']':	if (!pop(&s1,&temp) || (temp != '[')) return 0;	break;
			case ')':	if (!pop(&s1,&temp) || (temp != '(')) return 0;	break;
			default:	break; //do nothing... we only check the bracket
		}
		i++;
	}

	return stack_is_empty(&s1);
}


void main()
{
	char str1[100] = "{[a + b] - [(c-)]}";
	char str2[100] = "((h)*{([j + k]}))";


	printf("Result str1: %d\n", checkBracket(str1));
	printf("Result str2: %d\n", checkBracket(str2));
}