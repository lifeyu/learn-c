#include "calculator.h"

int sp = 0;				// 下一个空闲栈位置
double val[MAXVAL];			// 值栈

char buf[BUFSIZE];			// 用于 ungetch 函数的缓冲区
int bufp = 0;				// buf 中下一个空闲位置

void push(double data)
{
	if (sp < MAXVAL)
	{
		val[sp++] = data;	
	}
	else
	{
		printf("error: stack full, can't push %g\n", data);	
	}
}

double pop()
{
	if (sp > 0)
	{
		return val[--sp];	
	}
	else
	{
		printf("error: stack empty\n");
		return 0.0;	
	}
}

int getop(char op[])
{
	int i, c;
	while ((op[0] = c = getch()) == ' ' || c == '\t')
		;
	op[1] = '\0';

	if (!isdigit(c) && c != '.') return c;		// 不是数

	i = 0;

	if (isdigit(c))			// 收集整数部分
	{
		while (isdigit(op[++i] = c = getch()))
			;	
	}

	if (c == '.')			// 收集小数部分
	{
		while (isdigit(op[++i] = c = getch()))	
			;
	}

	op[i] = '\0';

	if (c != EOF) ungetch(c);

	return NUMBER;
}

int getch()
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int ch)
{
	if (bufp >= BUFSIZE)
	{
		printf("ungetch: too many characters\n");	
	}
	else
	{
		buf[bufp++] = ch;	
	}
}

/*double atof(char ch[])
{
	double val, power;
	int i, sign;

	for (i = 0; isspace(ch[i]); i++)		// 跳过空白符
		;

	sign = (ch[i] == '-') ? -1 : 1;
	if (ch[i] == '+' || ch[i] == '-') i++;

	for (val = 0.0; isdigit(ch[i]); i++)
	{
		val = 10.0 * val + (ch[i] - '0');	
	}
	if (ch[i] == '.') i++;

	for (power = 1.0; isdigit(ch[i]); i++)
	{
		val = 10.0 * val + (ch[i] - '0');
		power *= 10.0;	
	}

	return sign * val / power;
}*/
