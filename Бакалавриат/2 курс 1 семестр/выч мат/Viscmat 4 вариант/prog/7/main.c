
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double t_point[2];
typedef double(*t_f)(t_point);
typedef t_f t_grad[2];

double u(t_point);
double du_dx1(t_point);
double du_dx2(t_point);
int gradient(t_f, t_grad, t_point*, double, double, double, double, int);
/********************************************************/
double u(t_point x)
{
	return ((x[0]*x[0])+(x[1]*x[1])-x[0]*x[1]+2*x[0]-4*x[1]);
}
double du_dx1(t_point x)
{
	return ((2*x[0])-x[1]+2);
}
double du_dx2(t_point x)
{
	return (2*x[1]-x[0]-4);
}

int gradient(t_f U, t_grad G, t_point* M, double a, double b, double c, double eps, int n)
{
	int f = 0, i;
	double ci = c, right, Ux0;
	t_point x0, x1, grad1, ag;

	grad1[0] = (G[0])(*M);
	grad1[1] = (G[1])(*M);

	x0[0] = (*M)[0];
	x0[1] = (*M)[1];

	x1[0] = x0[0] - a*grad1[0];
	x1[1] = x0[1] - a*grad1[1];

	ag[0] = a*grad1[0];
	ag[1] = a*grad1[1];
	right = -a*b*ci*(pow(grad1[0], 2) + pow(grad1[1], 2));

	Ux0 = U(x0);
	for (i = 0; (f == 0) && (i<n); ++i)
	{
		x1[0] = x0[0] - ag[0] * ci;
		x1[1] = x0[1] - ag[1] * ci;
		right *= c;
		f = (U(x1) - Ux0)<right;
		ci *= c;
	}

	(*M)[0] = x1[0];
	(*M)[1] = x1[1];

	f = (abs(U(x0) - U(*M))<eps);
	return (f && (i <= n));
}
int main()
{
	t_grad G;
	int n;
	t_point M0;
	M0[0] = -1.1; M0[1] = 0.59;
	G[0] = du_dx1;
	G[1] = du_dx2;
	n = 5000;
	printf("Minimize:%i\n", gradient(&u, G, &M0, 0.1, 0.5, 1, 0.01, n));
	printf("Mx1=%f Mx2=%f", M0[0], M0[1]);
	return 0;
}

