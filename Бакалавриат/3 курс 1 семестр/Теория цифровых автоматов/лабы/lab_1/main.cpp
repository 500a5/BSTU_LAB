#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

const int NotUsed = system("color F0");

int TableValue(int *X)
{
	int Value = (X[1] * pow(2, 1) + X[2] * pow(2, 0)) + (X[3] * pow(2, 2) + X[4] * pow(2, 1) + X[5] * pow(2, 0));
if ((5 <= Value) && (Value < 9))
		return 1;
	else
		return 0;
}
int AndNot(int x, int y)
{
return !(x && y);
}
int ANAnd(int x, int y)
{
return AndNot(AndNot(x, y), AndNot(x, y));
}
int ANOr(int x, int y)
{
	return AndNot(AndNot(x, x), AndNot(y, y));
}
int OrNot(int x, int y)
{
	return !(x || y);
}

int ONAnd(int x, int y)
{
	return OrNot(OrNot(x, x), OrNot(y, y));
}

int ONOr(int x, int y)
{
return OrNot(OrNot(x, y), OrNot(x, y));
}

int KNF(int *X)
{
	int Z[5], U[7];

	Z[2] = X[2] || X[5];
	Z[3] = X[1] || X[4];
	Z[4] = !X[1] || !X[3];
	Z[1] = !X[4] || Z[4];

	U[1] = X[1] || X[3];
	U[2] = X[3] || X[4];
	U[3] = X[3] || Z[2];
	U[4] = !X[5] || Z[1];
	U[5] = !X[2] || Z[1];
	U[6] = Z[2] || Z[3];

	int f = 1;
	for (int i = 1; i <= 6; i++)
		f = f && U[i];
	return f;
}

int OrNotKNF(int *x)
{
	int z[100], u[100];

    z[4] = OrNot(OrNot(x[0],x[0]),OrNot(x[1],x[1]));
    z[5] = OrNot(OrNot(x[1],x[1]),x[3]);
    z[6] = OrNot(x[0],x[2]);
    z[7] = OrNot(x[1],OrNot(x[3],x[3]));
    z[8] = OrNot(x[0],x[3]);
    z[9] = OrNot(x[0],x[1]);
    z[10] = OrNot(OrNot(x[0],x[0]),x[4]);
    z[11] = OrNot(x[1],OrNot(x[4],x[4]));
    z[12] = OrNot(OrNot(x[3],x[3]),OrNot(x[4],x[4]));
    z[13] = OrNot(OrNot(x[2],x[2]),x[4]);
    z[14] = OrNot(x[2],OrNot(x[4],x[4]));
    z[15] = OrNot(OrNot(x[2],x[2]),x[4]);
    z[16] = OrNot(x[0],x[2]);
    z[17] = OrNot(OrNot(x[0],x[0]),OrNot(x[2],x[2]));
    z[18] = OrNot(x[0],OrNot(x[2],x[2]));
    z[19] = OrNot(OrNot(x[1],x[1]),x[2]);
    z[1] = OrNot(OrNot(x[4],x[4]),z[17]);
    z[2] = OrNot(OrNot(x[4],x[4]),z[18]);
    z[3] = OrNot(OrNot(x[3],x[3]),z[19]);

    u[1] = OrNot(x[3],z[1]);
    u[2] = OrNot(x[1],z[1]);
    u[3] = OrNot(OrNot(x[1],x[1]),z[2]);
    u[4] = OrNot(OrNot(x[3],x[3]),z[2]);
    u[5] = OrNot(x[4],z[3]);
    u[6] = OrNot(x[0],z[3]);
    u[7] = OrNot(z[9],z[12]);
    u[8] = OrNot(z[8],z[13]);
    u[9] = OrNot(z[8],z[14]);
    u[10] = OrNot(z[9],z[15]);
    u[11] = OrNot(z[11],z[16]);
    u[12] = OrNot(x[2],z[4]);
    u[13] = OrNot(x[3],z[4]);
    u[14] = OrNot(OrNot(x[2],x[2]),z[5]);
    u[15] = OrNot(OrNot(x[3],x[3]),z[10]);
    u[16] = OrNot(OrNot(x[4],x[4]),z[5]);
    u[17] = OrNot(OrNot(x[1],x[1]),z[6]);
    u[18] = OrNot(OrNot(x[3],x[3]),z[6]);
    u[19] = OrNot(OrNot(x[2],x[2]),z[7]);
    u[20] = OrNot(OrNot(x[0],x[0]),z[7]);
    u[21] = OrNot(OrNot(x[3],x[3]),z[11]);
    u[22] = OrNot(x[2],z[10]);


	int f = 1;
	for (int i = 1; i <= 20; i++)
		f = ONAnd(f, u[i]);
	return f;
}

int DNF(int *X)
{
	int Z[7], U[7];

	Z[2] = !X[1] && X[3];
	Z[3] = X[1] && X[3];
	Z[4] = !X[2] && X[3];
	Z[5] =  X[4] && !X[5];
	Z[6] =  X[1] && !X[3];
	Z[1] =  X[4] && Z[6];

	U[1] = X[5] && Z[2];
	U[2] = Z[4] && Z[5];
	U[3] = X[2] && Z[2];
	U[4] = Z[3] && !X[4];
	U[5] = X[5] && Z[1];
	U[6] = !X[2] && Z[1];

	int f = 0;
	for (int i = 1; i <= 6; i++)
		f = f || U[i];
	return f;
}

int AndNotDNF(int *x)
{
	int z[15], u[9];
    z[14] = AndNot(x[2],AndNot(x[4],x[4]));
    z[13] = AndNot(x[1],AndNot(x[2],x[2])) ;
    z[4] = AndNot(x[0],AndNot(x[4],x[4]));
    z[5] = AndNot(AndNot(x[1],x[1]),AndNot(x[2],x[2]));
    z[6] = AndNot(AndNot(x[0],x[0]),x[1]);
    z[7] = AndNot(x[0],x[2]);
    z[8] = AndNot(AndNot(x[3],x[3]),AndNot(x[4],x[4]));
    z[9] = AndNot(AndNot(x[1],x[1]),x[2]);
    z[10] = AndNot(z[4],z[9]);
    z[11] = AndNot(x[1],AndNot(x[2],x[2]));
    z[2] = AndNot(x[3],z[6]);
    z[12] = AndNot(x[4],z[2]);
    z[1] = AndNot(z[5],z[8]);
    z[3] = AndNot(x[4],z[7]);

    u[1] = AndNot(AndNot(x[1],x[1]),z[1]);
    u[2] = AndNot(x[0],z[1]);
    u[3] = AndNot(AndNot(x[3],x[3]),z[10]);
    u[4] = AndNot(z[11],z[12]);
    u[5] = AndNot(x[3],z[4]);
    u[6] = AndNot(z[2],z[14]);
    u[7] = AndNot(x[1],z[3]);
    u[8] = AndNot(x[3],z[3]);

	int f = 0;
	for (int i = 1; i <=6 ; i++)
		f = ANOr(f, u[i]);
	return f;
}

int DNFImp4(int x1, int x2, int x3, int x4)
{
return AndNot(ANAnd(x1, x2), ANAnd(x3, x4));
}
int DNFImp3(int x1, int x2, int x3)
{
	return AndNot(ANAnd(x1, x2), x3);
}

int SchemeAndNot(int *X)
{
	int U[7];
	U[1] = DNFImp3(AndNot(X[1], X[1]), X[3], X[5]);
	U[2] = DNFImp4(AndNot(X[2], X[2]), X[3], X[4], AndNot(X[5], X[5]));
	U[3] = DNFImp3(AndNot(X[1], X[1]), X[2], X[3]);
	U[4] = DNFImp3(X[1], X[3], AndNot(X[4], X[4]));
	U[5] = DNFImp4(X[1], AndNot(X[3], X[3]), X[4], X[5]);
	U[6] = DNFImp4(X[1], X[2], AndNot(X[3], X[3]), X[4]);

	int f = 1;
	for (int i = 1; i <= 6; i++)
		f = ANAnd(f, U[i]);
	return AndNot(f, U[6]);
}

int KNFImp4(int x1, int x2, int x3, int x4)
{
	return OrNot(ONOr(x1, x2), ONOr(x3, x4));
}

int KNFImp3(int x1, int x2, int x3)
{
return OrNot(ONOr(x1, x2), x3);
}

int SchemeOrNot(int *X)
{
	int U[7];
	U[1] = OrNot(X[1], X[3]);
	U[2] = OrNot(X[3], X[4]);
	U[3] = KNFImp3(X[2], X[3], X[5]);
	U[4] = KNFImp4(OrNot(X[1], X[1]), OrNot(X[3], X[3]), OrNot(X[4], X[4]), OrNot(X[5], X[5]));
	U[5] = KNFImp4(OrNot(X[1], X[1]), OrNot(X[2], X[2]), OrNot(X[3], X[3]), OrNot(X[4], X[4]));
	U[6] = KNFImp4(X[1], X[2], X[4], X[5]);

	int f = 0;
	for (int i = 1; i <= 6; i++)
		f = ONOr(f, U[i]);
	return OrNot(f, U[6]);
}

int main(int argc, const char * argv[]) {
	int X[6];
	for (int i = 1; i < 6; i++)
		printf(" x%d|", i);
	printf("  F     F1  F2  F3  F4 \n");

	for (X[1] = 0; X[1] < 2; X[1]++)
		for (X[2] = 0; X[2] < 2; X[2]++)
			for (X[3] = 0; X[3] < 2; X[3]++)
				for (X[4] = 0; X[4] < 2; X[4]++)
					for (X[5] = 0; X[5] < 2; X[5]++)
					{
						for (int i = 1; i < 6; i++)
							printf(" %2d|", X[i]);
						printf(" %2d   ", TableValue(X));
						printf(" %2d ", AndNotDNF(X));
						printf(" %2d ", OrNotKNF(X));
						printf(" %2d ", SchemeAndNot(X));
						printf(" %2d ", SchemeOrNot(X));

						printf("\n");
                                                                                 }
	return 0;
}