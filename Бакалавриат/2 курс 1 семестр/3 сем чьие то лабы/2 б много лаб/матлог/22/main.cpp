#include <iostream>
#include <set>
#include <string>
#include <cmath>
#include <vector>
#include <stack>

//std::stack <char> per; // стек переменных
 // стек действий

std::string opz(std::string s); // перевод строки в обратную польскую запись
void t_per (std::string s); // кол-во переменных
std::set<char> per; // множество перменных
void virah(std::string s);
std::vector <std::string> vir; // хранит выражения
void output(); // вывод следтвий и з посылок
void soch(int i, int b, int N, int k); // заполняемое место, минимальный элемент, из N по k
void out(); // вывод выражения получено в рез-те сочетания
std::vector<int>C;
void inputt (std::string *s, int n);
void kol_per (std::string *s, int n);
void make_vir (std::string *s, int n);

int main()
{
    std::cout<<"Strok ";
    int n;
    std::cin >> n; //ввод количества строк
    std::string *vir = new std::string [n]; //выделение памяти под массив строк
    inputt(vir, n);         // ввод массива сток
    kol_per(vir, n);         // подсчет кол-ва переменных
    make_vir(vir, n);        //создание выражения
    std::cout<< " " << std::endl;
    std::cout<<"Rez " << std::endl;
    output(); //вывод результата
}

void inputt (std::string *s, int n)
{
    for (int i=0; i<n; i++)
    {
        std::cin >> s[i];
    }
}

void kol_per (std::string *s, int n)
{
    for (int i=0; i<n; i++)
    {
        t_per(s[i]);
    }
}

void make_vir (std::string *s, int n)
{
    for (int i=0; i<n; i++)
    {
        virah(s[i]);
    }
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

void t_per (std::string s) // кол-во переменных
{
    for (int i = 0; i<s.length(); i++)
    {
        if (((s[i] >= 'A') &&(s[i]<='Z'))|| (((s[i] >= 'a') && (s[i] <= 'z')) && s[i]!='v'))
        {
            if ( !per.count(s[i])) // 1 если элемент есть в множестве, иначе 0
                per.insert(s[i]);
        }
    }
}

void virah(std::string s)
{
//    int count=0;
    std::set<char> pod_mn;
    //std::cout<<s;
    for(int i=0; i<s.length(); i++)
    {
          if (((s[i] >= 'A') &&(s[i]<='Z'))|| (((s[i] >= 'a') && (s[i] <= 'z')) && s[i]!='v')){
              pod_mn.insert(s[i]);
          }
    }
    if (pod_mn.size() == per.size())
    {
        //std::cout<<"!! "<<std::endl;
        vir.push_back(s); //расширяет на один элемент и записывает в него s

        return;
    }
    int dob =  per.size() - pod_mn.size() ; //сколько добавить?????????
    int st = pow(2, dob);
    std::string *sn = new std::string [st];
    for (int i=0; i<st; i++){
         //std::cout<<"@@"<<std::endl;
        //sn[i]=new std::string ();
         sn[i]=s;
         //std::cout<<sn[i]<<std::endl;
    }

//    for (int i=0; i<dob; i++)
        int m=0;
        for (std::set<char>::iterator p=per.begin(); p!=per.end(); p++) // итератор по полному множеству
        {
            if (!pod_mn.count(*p))
            {
//                m++;
               // std::cout<<"$";
                int n = 0;
                bool f = 1;
                for (int j=0; j<st; j++)
                {
                    if(f){
                        sn[j]+='v';
                        sn[j]+=*p;
                    }
                    else
                    {
                        sn[j]+="v!";
                        sn[j]+=*p;

                    }
                    n++;
                    if (n==pow(2, m))
                    {
                        n=0;
                        f=!f;
                    }
                    m++;
                }
            }
        }
        for(int i=0; i<st; i++)
        {
            vir.push_back(sn[i]);

        }
}




void output()
{
    for (int i=0; i<vir.size(); i++)
    {
        C.push_back(i);
        soch(0,0,vir.size(),i);

    }
}

void soch(int i, int b, int N, int k)
{

    for (int j = b; j < N-k+i; j++)
    {
        C[i] = j;
        //std::cout<<"#";
        if (i == k)
        {
            //std::cout<<"!";
            out();
        }
        else soch(i+1, j+1, N, k);
    }
}

void out ()
{
    for (unsigned int i = 0; i < C.size(); i++)
    {
        if(i+1==C.size())
            std::cout << vir[C[i]];
        else
            std::cout << vir[C[i]]<<" & ";
    }
    std::cout<<std::endl;
}







