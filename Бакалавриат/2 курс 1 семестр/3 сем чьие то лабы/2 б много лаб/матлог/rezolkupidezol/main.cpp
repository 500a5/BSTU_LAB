#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <vector>
#include <stack>

//std::stack <char> per; // стек переменных
 // стек действий

std::string opz(std::string s); // перевод строки в обратную польскую запись
void inputt (std::string *s, int n);

int main()
{
    int n, i=0;
    std::cout << "Skolko posilok >> ";
    std::cin >> n;
    std::string *pos= new std::string [n];
    std::cout << "Vvod posilok >> ";
    inputt (pos, n);
    std::cout << "Vvod sledstviya >> ";
    std::string sled;
    std::cin >> sled;

    std::string *opos = new std::string[n];
    for (i=0; i<n; i++)
        opos[i]=opz(pos[i]);
    std::string osled = opz(sled);


    /*std::cout << osled << std::endl;
    std::cout << "Opz posilok>> " << std::endl;
    for (i=0; i<n; i++)
        std::cout << opzs[i] << std::endl;*/

    return 0;
}


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

void inputt (std::string *s, int n)
{
    for (int i=0; i<n; i++)
    {
        std::cin >> s[i];
    }
}

