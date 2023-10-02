#include <iostream>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;
void ChangeMatr (char * Fname);
//void ChangeNum (char *Fname);
int main ()
{
    setlocale(LC_ALL, "Russian");
    char * FileName = "1.txt";
    ChangeMatr (FileName);
  //  int n = 3, i, j;

}

void ChangeMatr (char* Fname)
{
    int n, i, j;
    char *Tname = "tmp.txt";
    ifstream f(Fname);
    f >> n;
    ofstream t;
    t.open(Tname);
    float a[n][n];
   /* a = new float *[n];
    for (i=0; i<n; i++)
        a[i] = new float [n];*/
cout << "lol" << endl;
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
            f >> a[i][j];
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1;j++)
            t << a[i][j] << " ";
        t << endl;
    }
    f.close();
    t.close();
    remove (Fname);
    rename(Fname, Tname);

}
