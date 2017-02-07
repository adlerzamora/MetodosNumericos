// metodoNewtonRaphson.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#define ERR 0.00000000000000000001

using namespace std;

double derivate(double *x) {
	// prueba1 return (3 * pow(*x, 2)) + 5;
	double x1 = *x;
	return (exp(x1) + 1);
}

double function(double *x) {
	//prueba1 return (pow(*x, 3) + (5 * *x) - 10);
	double x1 = *x;
	return  exp(x1) + *x;
}

void newtonRapshon(double *x0) {
	*x0 = (*x0 - (function(x0) / derivate(x0)));
}

void GetRoot(double *x0) {
	do
	{
		newtonRapshon(x0);
	} while (function(x0) >= ERR);
}

int main()
{
	double x0;	
	cout << "x0: ";
	cin >> x0 ;
	cout << endl;
	GetRoot(&x0);
	cout << "result: " << x0;
	cout << endl << "Tu resultado tiene un error de: " << ERR;
	_getch();

    return 0;
}

