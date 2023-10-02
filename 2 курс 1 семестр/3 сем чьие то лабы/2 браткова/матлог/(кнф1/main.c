#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef char token;

char chislo_tok (token t)
{
    return t == '0' || t == '1';
}

char perem_tok (token t)
{
    return (t >= 'A' && t <= 'Z') || (t >= 'a' && t <= 'z');
}

char oper_tok (token t)
{
    return (t == '|' || t == '&' || t == '-' || t == '>' || t == '!');
}

char open_tok (token t)
{
    return t == '(';
}

char open_tok (token t)
{
    return t == ')';
}

char priopitet (token op)
{
	//assert (oper_tok(op));
	int res = 0;
	switch (op)
	{
		case '-':
			// ��������� � ��������� ���������
			res = 5;
			break;
		case '&':
			// ����������
			res = 4;
			break;
		case '|':
			// ����������
			res = 3;
			break;
		case '>':
			// ����������
			res = 2;
			break;
		case '!':
			// ��������������� � ��������� ���������
			res = 1;
			break;
	}
	return res;
}




void main()
{
    setlocale(LC_ALL,"Rus");

}
