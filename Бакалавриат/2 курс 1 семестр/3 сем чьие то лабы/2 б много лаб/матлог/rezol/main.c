#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <vector>
#include <stack>

//std::stack <char> per; // стек переменных
 // стек действий

std::string opz(std::string s); // перевод строки в обратную польскую запись
std::string opz(std::string s)
{
    std::stack<char> oper;
    std::string rez="";
    for(int i=0; i<s.length(); i++)
    {

        if ((s[i]>='a' && s[i] <= 'z' || s[i]>='A' && s[i]<='Z') && s[i]!='v')
        {
            rez+= s[i];
        }
        if(s[i]=='(' || s[i]=='!' || s[i]=='v' || s[i]=='&')
        {
            oper.push(s[i]);
            //std::cout<<s[i];
        }
        if (s[i]==')')
        {
            char c=oper.top();
            oper.pop();
            while(c!='(')
            {
                rez+= c;
               c=oper.top();
               oper.pop();


            }
        }
    }
    while (!oper.empty())
    {
        char c=oper.top();
        oper.pop();
        rez+=c;
    }
    return rez;

}

int main()
{
    printf("Hello world!\n");
    return 0;
}
