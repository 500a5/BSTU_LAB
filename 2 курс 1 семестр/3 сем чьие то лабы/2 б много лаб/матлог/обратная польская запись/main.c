#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


// Построить таблицу истинности для любых логических выражений
typedef enum {Empty, Number, Variable,Openbracket,Closebracket,  Or ,And, Not} types;
typedef enum { No, Syntax } errors;


void sort_variables(char *a,const int n)
// Сортирует по непоубыванию строку a, длиной n
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
// Заменяет в строке str переменные из variables, на коды двоичного вектора, хранимого в subset
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
// Возвращает истина, если оператор в конце stack имеет большый приоритет, чем оператор pt
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
// Считывает лексему из строки str в token и возвращает её тип
{
	static int i = 0;
	*tty = Empty;
	if (str[i] == '\0') //Проверка на пустоту строки
	{
		i = 0;
		return 0;
	}
	while (isspace(str[i])) i++; //Пропуск разделителей

	if (isalpha(str[i]))  //Лексема - переменная
	{
		*tok = str[i];
		*tty = Variable;
	}
	if (isdigit(str[i]))  //Лексема - число
	{
		*tok = str[i];
		*tty = Number;
	}
	else if ( str[i]=='*')  //Лексема - оператор И
	{
		*tok = str[i];
		*tty = And;
	}
	else if (str[i] == '+')  //Лексема - оператор ИЛИ
	{
		*tok = str[i];
		*tty = Or;
	}
	else if (str[i] == '!')  //Лексема - оператор НЕ
	{
		*tok = str[i];
		*tty = Not;
	}
	else if (str[i]=='(') // Лексема- открывающая скобка
	{
		*tok = str[i];
		*tty = Openbracket;
	}
	else if (str[i] == ')')//Лексема - закрывающая скобка
	{
		*tok = str[i];
		*tty = Closebracket;
	}
	i++;
	return i;
}


int endenter(char newstr[100], char stack[100])
// Если в строке stack остались скобки, возвращает 0, в противном случае выталкивает строку stack в строку newstr, возвращая 1
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
// Если в строке stack не првильно согласованы скобки возвращает 0,
// в противном случае выталкивает операторы после последней скобки из stack в строку newstr,возвращая 1

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
// Записывает в строку newstr постфиксную форму записи строки str, записывая переменные в массив variables и возвращая его длину,
//Если в строке str есть синтаксическая ошибка, возвращает 0
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
				printf("Ошибка синтаксиса");
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
				printf("Ошибка синтаксиса");
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
// Назначение: Вывод строки str;
{
	int i;
	for (i = 0; i < n; i++) printf("%d", str[i]);
}


void parser(char* str,int* subset,int n,char* variables)
// Вычисление значения выражения в строке str, заменой переменных из variables на коды двоичного вектора subset
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
// Назначение: Порождение двоичных векторов. и построение таблицы истинности в subset
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

