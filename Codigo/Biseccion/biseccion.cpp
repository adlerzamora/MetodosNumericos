// biseccion.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"

using namespace std;


float fun(float x)
{
	return (x*x*x - 4 * x - 9);
}
void bisection(float *x, float a, float b, int *itr)
/* this function performs and prints the result of one iteration */
{
	*x = (a + b) / 2;
	++(*itr);
	printf("Iteration no. %3d X = %7.5f\n", *itr, *x);
}
int main()
{
	int itr = 0, maxmitr;
	float x, a, b, allerr, x1;
	printf("\nEnter the values of a, b, allowed error and maximum iterations:\n");
	scanf("%f %f %f %d", &a, &b, &allerr, &maxmitr);
	bisection(&x, a, b, &itr);
	do
	{
		if (fun(a)*fun(x) < 0)
			b = x;
		else
			a = x;
		bisection(&x1, a, b, &itr);
		if (fabs(x1 - x) < allerr)
		{
			cout << "After " << itr <<  " iterations, root = " << x1;
			return 0;
		}
		x = x1;
	} while (itr < maxmitr);
	
	cout << "The solution does not converge or iterations are not sufficient";
	_getch();
	return 0;
}
