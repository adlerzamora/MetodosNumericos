#include <iostream>
#include <cmath>
#include <conio.h>

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
	cout << "Iteration no. "<< itr << " X = "<< x <<endl;
}
int main()
{
	int itr = 0, maxmitr;
	float x, a, b, allerr, x1;
	cout << "Ingresa el valor de a: ";
	cin >> a;
	cout << "\nIngresa el valor de b: ";
	cin >> b;
	cout << "\nIngresa el valor del error permitido: ";
	cin >> allerr;
	cout << "\nIngresa el valor de las iteraciones maximas: ";
	cin >> maxmitr;
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
			cout << "Despues de " << itr <<  " iteraciones, la raiz es = " << x1<<endl;
			return 0;
		}
		x = x1;
	} while (itr < maxmitr);
	
	cout << "La solucion no converge o no fueron suficientes iteraciones.";
	_getch();
	return 0;
}
