#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// ��������� ������� ���������� ��� ����� ���������� ���������
typedef enum {Empty, Number, Variable,Openbracket,Closebracket,  Or ,And, Not} types;
typedef enum { No, Syntax } errors;


void sort_variables(char *a,const int n)
// ��������� �� ������������ ������ a, ������ n
{
	int i = 0, j = 0;
	char c;
	for(j;j<n;j++)
		for(i;i<n-j-1;i++)
			if (a[i] > a[i + 1])
			{
				c = a[i];
				a[i] = a[i + 1];
				a[i + 1] = c;
			}
}


void change_element(char *str,int* subset,char*variables)
// �������� � ������ str ���������� �� variables, �� ���� ��������� �������, ��������� � subset
{
	int i = 0,j=0;
	while (str[i] != '\0')
	{
		if (isalpha(str[i]))
		{
			j = 0;
			while (str[i] != variables[j])j++;
			str[i] = subset[j] + '0';
		}
		i++;
	}
}


int priority(char token, char* stack,types pt)
// ���������� ������, ���� �������� � ����� stack ����� ������� ���������, ��� �������� pt
{
	types type=Empty;
	switch (stack[strlen(stack)-1])
	{
		case '*':
			type = And;
			break;
		case '+':
			type = Or;
			break;
		case '!':
			type = Not;
			break;
	}
	return(type > pt);

}


int getToken(char* tok,  types* tty,char *str)  //tty -token type
// ��������� ������� �� ������ str � token � ���������� � ���
{
	static int i = 0;
	*tty = Empty;
	if (str[i] == '\0') //�������� �� ������� ������
	{
		i = 0;
		return 0;
	}
	while (isspace(str[i])) i++; //������� ������������

	if (isalpha(str[i]))  //������� - ����������
	{
		*tok = str[i];
		*tty = Variable;
	}
	if (isdigit(str[i]))  //������� - �����
	{
		*tok = str[i];
		*tty = Number;
	}
	else if ( str[i]=='*')  //������� - �������� �
	{
		*tok = str[i];
		*tty = And;
	}
	else if (str[i] == '+')  //������� - �������� ���
	{
		*tok = str[i];
		*tty = Or;
	}
	else if (str[i] == '!')  //������� - �������� ��
	{
		*tok = str[i];
		*tty = Not;
	}
	else if (str[i]=='(') // �������- ����������� ������
	{
		*tok = str[i];
		*tty = Openbracket;
	}
	else if (str[i] == ')')//������� - ����������� ������
	{
		*tok = str[i];
		*tty = Closebracket;
	}
	i++;
	return i;
}


int endenter(char newstr[100], char stack[100])
// ���� � ������ stack �������� ������, ���������� 0, � ��������� ������ ����������� ������ stack � ������ newstr, ��������� 1
{
	int i = 0, j = 0;
	j = strlen(stack)-1;
	i = strlen(newstr);
	while (j >= 0)
	{
		if ((stack[j] != '(') && (stack[j] != ')'))
			newstr[i++] = stack[j--];
		else return 0;
	}
	newstr[i] = '\0';
	return 1;

}


int stacktostr(char newstr[100], char stack[100])
// ���� � ������ stack �� �������� ����������� ������ ���������� 0,
// � ��������� ������ ����������� ��������� ����� ��������� ������ �� stack � ������ newstr,��������� 1

{
	int i = 0, j = 0, k, l = 0;
	while (newstr[i] > ' ') i++;
	j = strlen(stack)-1;
	while ((j>-1) && (stack[j] != '(')) j--;
	if (j == -1) return 0;
	k = j;
	j = strlen(stack)-1;
	while (j != k)
	{
		l++;
		newstr[i] = stack[j];
		j--;
		i++;
	}
	stack[k] = '\0';
	newstr[i] = '\0';

	return l;
}


int postfix(char* newstr,char* str,char* variables)
// ���������� � ������ newstr ����������� ����� ������ ������ str, ��������� ���������� � ������ variables � ��������� ��� �����,
//���� � ������ str ���� �������������� ������, ���������� 0
{
	char stack[100], token;
	types type = Empty;
	int i = 0, j = 0, k = 0, l = 0,m=0;
	while (str[i] != '/0')
	{
		i = getToken(&token, &type, str);
		switch (type)
		{
		case Variable:
		{
			if (!(strchr(variables, token))) variables[j++] = token;
			newstr[k++] = token;
			newstr[k] = '\0';
		}
		break;

		case Openbracket:
		{
			stack[l++] = token;
			stack[l] = '\0';
		}
		break;

		case Closebracket:
		{

			if (!(m = stacktostr(newstr, stack)))
			{
				printf("������ ����������");
				return 0;
			}
			else
			{
				k += m;
				l = l - m - 2;
			}
		}
		break;
		case Empty:
		{
			if (!(endenter(newstr, stack)))
			{
				printf("������ ����������");
				return 0;
			}
			printf("%s", newstr);
			return(j);
		}
		break;
		default:
		{
			while ((priority(token, stack, type))&&(--l>=0))
			{
				newstr[k++] = stack[l];
				newstr[k] = '\0';
				stack[l] = '\0';

			}
			stack[l++] = token;
			stack[l] = '\0';
		}
		break;
		}
	}
}


void write_set(int *str, const int n)
// ����������: ����� ������ str;
{
	int i;
	for (i = 0; i < n; i++) printf("%d", str[i]);
}


void parser(char* str,int* subset,int n,char* variables)
// ���������� �������� ��������� � ������ str, ������� ���������� �� variables �� ���� ��������� ������� subset
{
	char stack[100];
	char token;
	types type = Empty;
	int i = 0, j = 0, k = 0, l = 0;
	char* newstr=(char*)malloc(strlen(str)*sizeof(char));
	while (newstr[j] = str[j])j++;
	change_element(newstr, subset, variables);
	while (newstr[i] != '\0')
	{
		i = getToken(&token, &type,newstr);

		switch (type)
		{
			case Number:
			{
				stack[k++] = token;
				stack[k] = '\0';
			}
			break;

			case And:
			{
				stack[k - 2] = ((stack[k - 2]-'0') * (stack[k - 1]-'0'))+'0';
				stack[--k] = '\0';
			}
			break;

			case Or:
			{
				stack[k - 2] = ((stack[k-2]-'0')||(stack[k-1])-'0') + '0';
				stack[--k] = '\0';
			}
			break;

			case Not:
			{
				if (stack[k - 1] == '0')stack[k - 1] = '1';
				else stack[k - 1] = '0';
			}
			break;

		}
	}
	printf("%s", stack);
}


void subsets(int i,const int n,int* subset,char* newstr,char * variables)
// ����������: ���������� �������� ��������. � ���������� ������� ���������� � subset
{
		int x;
		for (x = 0; x<2; x++)
		{
			subset[i] = x;
			if (i == n - 1)
			{
				write_set(subset, n);
				parser(newstr, subset, n,variables);
				printf("\n");
			}
			else subsets(i + 1,n,subset,newstr,variables);
		}

}


int main()
{
	char variables[10];
	char str[100];
	char newstr[100];
	int* subset;
	types type;
	errors error;
	int l;
	gets(str);
	l=postfix(newstr,str,variables);
	subset = (int*)malloc(l * sizeof(int));
	sort_variables(variables, l);
	printf("\n");
	subsets(0, l,subset,newstr,variables);
}

