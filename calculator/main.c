#include "calculator.h"

void main()
{
	int type;
	double op;
	char ch[MAXOP];

	while ((type = getop(ch)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(ch));
			break;	
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op = pop();
			push(pop() - op);	
			break;
		case '/':
			op = pop();
			if (op != 0.0)
			{
				push(pop() / op);	
			}
			else
			{
				printf("error: zero divisor\n");	
			}
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", ch);
			break;
		}	
	}
}
