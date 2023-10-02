#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//#include <iostream>
//#include <ctime>
#define N 7

void refl(int a[N][N]){
	int f=1,i;
	for (i=0;(i<N)&&f;i++)
		if(a[i][i]==0){
		 f=0;
		 printf("Не рефлексивно, так как (%d,%d) не принадлежит отношению\n",i+1,i+1);
	}

    if (f==0) for(i=0;(i<N)&&!f;i++)
      {
	  if(a[i][i]==1) {
	  printf("Не антирефлексивно, так как (%d,%d) принадлежит отношению\n",i+1,i+1);
	  f=1;
      }
      }
      else printf("Отношение рефлексивно\n");
    if (!f)  printf("Отношение антирефлексивно\n");

}

void generation (int a[N][N], unsigned count1,int n)
{
    srand( n );
    unsigned i,j,k;
    for ( k=0;k<count1;++k)
     {
        do
        {
          i=rand()%N;
          j=rand()%N;
        }
        while (a[i][j]);
        a[i][j]=1;
     }
}

void simm(int a[N][N]){
	int f1=1,f2=1,i,j;
	for (i=0;(i<N)&&f1;i++)
	  for(j=0;(j<N)&&f1;j++)
		if(a[i][j]!=a[j][i]) {
		f1=0;
		printf("Не симметрично, так как из %dR%d не следует %dR%d\n",i+1,j+1,j+1,i+1);
	}

    for (i=0;(i<N)&&f2;i++)
	            for(j=0;(j<N)&&f2;j++)
	              	{
					  if(a[i][j]&&a[j][i]) {
					  f2=0;
					  printf("Не антисимметрично, так как из %dR%d следует %dR%d\n",i+1,j+1,j+1,i+1);
					  }
					  }

    if(f1) printf("Отношение симметрично\n");
    if (f2)  printf("Отношение антисимметрично\n");
}



void poln(int a[N][N]){
	int f=1,i,j,z;
	for (i=0;(i<N)&&f;i++)
	  for(j=0;(j<N)&&f;j++)
	   if ((a[i][j]||a[j][i])!=1) f=0;
    if (f)  printf("Отношение полное\n");

}

void vivod(int a[N][N]){
		int i,j;
	for(i=0;i<N;i++){
	  for(j=0;j<N;j++)
      printf("%d ",a[i][j]);
    printf("\n" );
    }
    printf("\n" );
}

void transit(int a[N][N]){
	int f1=1,f2=1,i,j,z;
	for (i=0;(i<N)&&f1;i++)
	  for(j=0;(j<N)&&f1;j++)
	    for(z=0;(z<N)&&f1;z++)
		  if((a[i][j]==0)&&(a[i][z]&&a[z][j])) {
		  f1=0;
		  printf("Не транзитивно, так как из %dR%d и %dR%d не следует %dR%d\n",i+1,z+1,z+1,j+1,i+1,j+1);
	}

	for (i=0;(i<N)&&f2;i++)
	  for(j=0;(j<N)&&f2;j++)
	    for(z=0;(z<N)&&f2;z++){
		  if((a[i][j]==1)&&(a[i][z]&&a[z][j])) {
		  f2=0;
		  printf("Не антитранзитивно, так как из %dR%d и %dR%d следует %dR%d\n",i+1,z+1,z+1,j+1,i+1,j+1);
		  }
		  }
	if(f1){
	 printf("Отношение транзитивно\n");
    }if (f2)  printf("Отношение антитранзитивно\n");
}

int rav(int a[N][N],int b[N][N],int *k){
	int x=0,y,f=1;
	while((x<N)&&(f==1)){
		y=0;
		while((y<N)&&(f==1)){
			f=(a[x][y]==b[x][y]);
		    y++;
		    (*k)++;
		}
		x++;
	}
	return(f);
}

int vkl(int a[N][N],int b[N][N],int *k){
	int x=0,y,f=1;
	while((x<N)&&(f)){
		(*k)++;
		y=0;
		while((y<N)&&(f)){

			f=(a[x][y]<=b[x][y]);
		    y++;
		    (*k)+=2;
		}
		x++;
	}
	return(f);
}

int ob(int a[N][N],int b[N][N],int c[N][N],int *k){
	int x=0,y=0,f=0;
	for(;x<N;x++){
	(*k)++;
	  for(y=0;y<N;y++){
	  	(*k)++;
	  	if((a[x][y]^b[x][y])){
	    c[x][y]=(a[x][y]||b[x][y]);
	    f=1;
	    (*k)+=2;
		}
	}
}
		return(f);
}

void per(int a[N][N],int b[N][N],int c[N][N]){
	int x=0,y=0;
	for(;x<N;x++)
	  for(y=0;y<N;y++)
	    c[x][y]=(a[x][y]&&b[x][y]);

}

void raz(int a[N][N],int b[N][N],int c[N][N]){
	int x=0,y=0;
	for(;x<N;x++)
	  for(y=0;y<N;y++)
	    c[x][y]=(a[x][y]>b[x][y]);
}

void s_raz(int a[N][N],int b[N][N],int c[N][N]){
	int x=0,y=0;
	for(;x<N;x++)
	  for(y=0;y<N;y++)
	    c[x][y]=(a[x][y]!=b[x][y]);
}

void dop(int a[N][N],int c[N][N]){
	int x=0,y=0;
	for(;x<N;x++)
	  for(y=0;y<N;y++)
	    c[x][y]=(!a[x][y]);
}

void obr(int a[N][N],int c[N][N]){
	int x=0,y=0,tmp=0;
	for(;x<N;x++)
	  for(y=0;y<=x;y++){
	  	tmp=a[x][y];
	    c[x][y]=a[y][x];
	    c[y][x]=tmp;
		}
}




void otn(int a[N][N],int b[N][N],int c[N][N]){
	int i,j;

	for(i=0;i<N;i++)
	  for(j=0;j<N;j++){
	    if (((i+2)/(j+2))>1)
	      a[i][j]=1;
         else a[i][j]=0;
    }

    for(i=0;i<N;i++){
	  for(j=0;j<N;j++)
	    if ((i+2)%2==(j+2)%2)
	      b[i][j]=1;
         else b[i][j]=0;
    }

    for(i=0;i<N;i++)
	  for(j=0;j<N;j++){
	    if ((i+j+4>8)&&(i+j+4<12))
	      c[i][j]=1;
         else c[i][j]=0;

    }
}

void nol(int a[N][N]){
  int i,j;
  for(i=0;i<N;i++)
    for(j=0;j<N;j++){
    	a[i][j]=0;
	}
}

prov(int a[N][N]){
	refl(a);
	simm(a);
	transit(a);
	poln(a);
}

vvod(int a[N][N]){
	int i,j;
	for(i=0;i<N;i++)
      for(j=0;j<N;j++)
        scanf("%d",&a[i][j]);
}



void copy(int a[N][N], int b[N][N]){
	int i,j;
	for(i=0;i<N;i++)
	  for (j=0;j<N;j++)
	    a[i][j]=b[i][j];
}

int comp(int a[N][N],int b[N][N],int c[N][N]){
	int x,y=0,z,k=0;
	for(x=0;x<N;x++){
	k++;
	  for(y=0;y<N;y++){
	  	k++;
	    c[x][y]=0;
	    z=0;
	    while((z<N)&&!c[x][y]){
	      c[x][y]=(c[x][y]||(a[x][z]&&b[z][y]));
	      k+=2;
          z++;
	  }
}
}
return(k);
}

//3.10
  alg310(int a[N][N], int c[N][N]){
    int i;
    int t[N][N];
    int k =0;
    copy(c, a);
    nol(t);
    k+=comp(c, c, t);
    while(!vkl(t,c,&k)){
    	k++;
    	ob(c,t,c,&k);
    	nol(t);
        k+=comp(c, c, t);
    }
    return(k);
}

//Объединение степеней
int alg311(int a[N][N], int c[N][N]){
    int i;
    int t1[N][N],t2[N][N];
    int k =0,f=1;
    copy(t1, a);
    copy(c, a);
    for (i =2; i <= N; ++i){
    	k++;
  	    nol(t2);
        k+=comp(t1, a, t2);
        ob(c,t2,c,&k);
        copy(t1,t2);
    }
    return(k);
}

//Объединение степеней ул
int alg311u1(int a[N][N], int c[N][N]){
    int i;
    int t1[N][N],t2[N][N];
    int k =0,f=1;
    copy(t1, a);
    copy(c, a);
    for (i =2; i <= N&&f; ++i){
    	k++;
        nol(t2);
        k+=comp(t1, a, t2);
        f=ob(c,t2,c,&k);
        copy(t1,t2);
    }
    return(k);
}

//Уоршал
int  alg312(int a[N][N], int c[N][N]){
    copy(c, a);
    int x, y, z;
    unsigned long k =0;

    for (z =0; z < N; ++z){
    	k++;
        for (x =0; x < N; ++x){
        	k++;
            for (y =0; y < N; ++y){
                c[x][y] |= c[x][z] & c[z][y];
                k+=2;
            }
        }
    }
    return(k);
}

//Уоршал ул
int  alg312u(int a[N][N], int c[N][N]){
    copy(c, a);
    int x, y, z,f=1;
    unsigned long k=0;

    for (z =0; z < N; ++z){
    	k++;
        for (x =0; x < N; ++x){
        	k++;
        	f=1;
        	if(c[x][z])
            for (y =0; y < N&&f; ++y){
                 c[x][y] |= c[z][y];
                 k+=2;
			}
        }
    }
    return(k);
}

void init_mn(int a[N]){
	for(int i=0;i<N;i++)
	  a[i]=1;
}

int sr_mn(int* a,int* b){
	for(int i=0;i<N;i++)
	 if (a[i]!=b[i]) return(0);
    return(1);
}



void Pos_Kl_Ek(int a[N][N],int x, int b[N]){
	b[x]=1;
	for(int i=0;i<N;i++)
	  if(a[x-1][i]) b[i+1]=1;
}

void Rasb(int a[N][N]){
	int b[N][N], s[N],k,f,i,j ;
	Pos_Kl_Ek(a,1,b[0]);
	k=1;
	for(i=0;i<10;i++){
	   f=1;
       Pos_Kl_Ek(a,i,b[k]);
       for(j=0;j<=k&&f;j++)
         f=sr_mn(b[k],b[j]);
       if (!f) k++;
	}

}

void Timer(char * name, int (*F)(int[N][N], int[N][N]),int n){
    int i;
    unsigned int t;
    double t_sr =0;
    int kmin=99999999,kmax=-1,k;
    int A[N][N],B[N][N];
    for (i =0; i < 1; ++i){
    	nol(A);
    	nol(B);
        generation(A,n,i+time(NULL));
        k=F(A,B);
        if(k<kmin) kmin=k;
        if(k>kmax) kmax=k;
    }
    printf("\n%s Мин значение = %d, Макс значеине = %d n = %d\n", name,kmin,kmax, N);
}

int main(){
	int a[N][N],b[N][N],c[N][N],d[N][N];
	 setlocale(LC_ALL, "Russian");
    otn(a,b,c);
    vivod(c);
    prov(c);
    alg312u(c,d);
    vivod(d);
    prov(d);
}









#include <stdio.h>
#include <malloc.h>
#include <iostream>
#include <math.h>

#define N 5

void refl(int a[N][N]) {
	int f = 1, i;
	for (i = 0; (i<N) && f; i++)
		if (a[i][i] == 0) {
			f = 0;
			printf("Не рефлексивно, так как (%d,%d) не принадлежит отношению\n", i + 1, i + 1);
		}

	if (f == 0) for (i = 0; (i<N) && !f; i++)
	{
		if (a[i][i] == 1) {
			printf("Не антирефлексивно, так как (%d,%d) принадлежит отношению\n", i + 1, i + 1);
			f = 1;
		}
	}
	else printf("Отношение рефлексивно\n");
	if (!f)  printf("Отношение антирефлексивно\n");

}

void simm(int a[N][N]) {
	int f1 = 1, f2 = 0, i, j;
	for (i = 0; (i<N) && f1; i++)
		for (j = 0; (j<N) && f1; j++)
			if (a[i][j] != a[j][i]) {
				f1 = 0;
				printf("Не симметрично, так как из %dR%d не следует %dR%d\n", i + 1, j + 1, j + 1, i + 1);
			}

	for (i = 0; (i<N) && !f1; i++)
		for (j = 0; (j<N) && !f1; j++)
		{
			if (a[i][j] && a[j][i]) {
				f2 = 0;
				printf("Не антисимметрично, так как из %dR%d следует %dR%d\n", i + 1, j + 1, j + 1, i + 1);
			}
		}

	if (f1) printf("Отношение симметрично\n");
	if (f2)  printf("Отношение антисимметрично\n");
}

void transit(int a[N][N]) {
	int f1 = 1, f2 = 1, i, j, z;
	for (i = 0; (i<N) && f1; i++)
		for (j = 0; (j<N) && f1; j++)
			for (z = 0; (z<N) && f1; z++)
				if ((a[i][j] == 0) && (a[i][z] && a[z][j])) {
					f1 = 0;
					printf("Не транзитивно, так как из %dR%d и %dR%d не следует %dR%d\n", i + 1, z + 1, z + 1, j + 1, i + 1, j + 1);
				}

	for (i = 0; (i<N) && f2; i++)
		for (j = 0; (j<N) && f2; j++)
			for (z = 0; (z<N) && f2; z++) {
				if ((a[i][j] == 1) && (a[i][z] && a[z][j])) {
					f2 = 0;
					printf("Не антитранзитивно, так как из %dR%d и %dR%d следует %dR%d\n", i + 1, z + 1, z + 1, j + 1, i + 1, j + 1);
				}
			}
	if (f1) printf("Отношение транзитивно\n");
	if (f2)  printf("Отношение антитранзитивно\n");
}

void poln(int a[N][N]) {
	int f = 1, i, j, z;
	for (i = 0; (i<N) && f; i++)
		for (j = 0; (j<N) && f; j++)
			if ((a[i][j] || a[j][i]) != 1) f = 0;
	if (f)  printf("Отношение полное\n");

}

void vivod(int a[N][N]) {
	int i, j;
	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

int rav(int a[N][N], int b[N][N]) {
	int x = 0, y, f = 1;
	while ((x<N) && (f == 1)) {
		y = 0;
		while ((y<N) && (f == 1)) {
			f = (a[x][y] == b[x][y]);
			y++;
		}
		x++;
	}
	return f;
}

int vkl(int a[N][N], int b[N][N]) {
	int x = 0, y, f = 1;
	while ((x<N) && (f == 1)) {
		y = 0;
		while ((y<N) && (f == 1)) {
			f = (a[x][y] <= b[x][y]);
			y++;
		}
		x++;
	}
	return f;
}

void ob(int a[N][N], int b[N][N], int c[N][N]) {
	int x = 0, y = 0;
	for (; x<N; x++)
		for (y = 0; y<N; y++)
			c[x][y] = (a[x][y] || b[x][y]);

}

void per(int a[N][N], int b[N][N], int c[N][N]) {
	int x = 0, y = 0;
	for (; x<N; x++)
		for (y = 0; y<N; y++)
			c[x][y] = (a[x][y] && b[x][y]);

}

void raz(int a[N][N], int b[N][N], int c[N][N]) {
	int x = 0, y = 0;
	for (; x<N; x++)
		for (y = 0; y<N; y++)
			c[x][y] = (a[x][y]>b[x][y]);
}

void s_raz(int a[N][N], int b[N][N], int c[N][N]) {
	int x = 0, y = 0;
	for (; x<N; x++)
		for (y = 0; y<N; y++)
			c[x][y] = (a[x][y] != b[x][y]);
}

void dop(int a[N][N], int c[N][N]) {
	int x = 0, y = 0;
	for (; x<N; x++)
		for (y = 0; y<N; y++)
			c[x][y] = (!a[x][y]);
}

void obr(int a[N][N], int c[N][N]) {
	int x = 0, y = 0, tmp = 0;
	for (; x<N; x++)
		for (y = 0; y <= x; y++) {
			tmp = a[x][y];
			c[x][y] = a[y][x];
			c[y][x] = tmp;
		}
}

int comp(int a[N][N], int b[N][N], int c[N][N]) {
	int x = 0, y = 0, z, k = 0;
	for (; x<N; x++)
		for (y = 0; y<N; y++) {
			c[x][y] = 0;
			z = 0;
			while ((z<N) && !c[x][y]) {
				c[x][y] = (c[x][y] || a[x][z] && b[z][y]);
				k++;
				z++;
			}
		}
	return(k);
}


void otn(int a[N][N], int b[N][N], int c[N][N]) {
	int i, j;

	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++) {
			if (((i+1)%2==0)&&((j+1)%2==0))
				a[i][j] = 1;
			else a[i][j] = 0;
		}

	for (i = 0; i<N; i++) {
		for (j = 0; j<N; j++)
			if (abs((i+1)-(j+1))<5)
				b[i][j] = 1;
			else b[i][j] = 0;
	}

	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++) {
			if (((i+1)*(i+1))%(j+1)==0)
				c[i][j] = 1;
			else c[i][j] = 0;

		}
}

void nol(int a[N][N]) {
	int i, j;
	for (i = 0; i<10; i++)
		for (j = 0; j<10; j++) {
			a[i][j] = 0;
		}
}

void prov(int a[N][N]) {
	refl(a);
	simm(a);
	transit(a);
	poln(a);
}

void vvod(int a[N][N]) {
	int i, j;
	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++)
			scanf("%d", &a[i][j]);
}

void copy(int a[N][N], int b[N][N]) {
	int i, j;
	for (i = 0; i<N; i++)
		for (j = 0; j<N; j++)
			a[i][j] = b[i][j];
}

//Объединение степеней
unsigned long Transit1(int a[N][N], int c[N][N]) {
	int i;
	int t1[N][N], t2[N][N];
	unsigned long k = 0;
	copy(t1, a);
	copy(c, a);
	for (i = 2; i <= N; ++i) {
		k += comp(t1, a, t2);
		ob(c, t2, c);
		copy(t1, t2);
	}
	return k;
}

//Уоршал
unsigned long Transit2(int a[N][N], int c[N][N]) {
	copy(c, a);
	int x, y, z;
	unsigned long k = (N + 1)*(N + 1)*(N + 1);

	for (z = 0; z < N; ++z) {
		for (x = 0; x < N; ++x) {
			for (y = 0; y < N; ++y) {
				c[x][y] |= c[x][z] & c[z][y];
			}
		}
	}
	return k;
}

int main() {
	int a[N][N], b[N][N], c[N][N], d[N][N], e[N][N], f[N][N], g[N][N];
	int k = 0;
	setlocale(LC_ALL, "Russian");
	otn(a, b, c);//генерация отношений
	////проверка и вывод свойств
	//vivod(a);
	//prov(a);
	//vivod(b);
	//prov(b);
	//vivod(c);
	//prov(c);
	//транзитивное замыкание
	k=Transit1(a, b);
	printf("%d\n", k);
	//k=Transit2(a, c);
	//printf("%d\n", k);
	system("pause");
}

























