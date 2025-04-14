#include <iostream>
#include "../Solver/Vector.h"

using namespace std;
using VECTOR::Vector;

Vector getVector(const string& message);

double getValue(const string& message);

Vector::Mode getMode(const string& message);

int main()
{
	setlocale(LC_ALL, "Russian");
	Vector v1 = getVector("¬ведите вектор v1: ");
	Vector v2 = getVector("¬ведите вектор v2: ");
	Vector v3;
	double k = getValue("¬ведите коэффициент: ");
	cout << "v1 = " << v1;
	cout << "v2 = " << v2;
	cout << "v3 = " << v3;
	cout << "v1 + v2 = " << v1 + v2 << endl;
	cout << "v1 - v2 = " << v1 - v2 << endl;
	cout << "-v1 = " << -v1 << endl;
	cout << "v1 * k = " << v1 * k << endl;
	cout << "k * v2 = " << k * v2 << endl;
	return 0;
}

Vector getVector(const string& message)
{
	cout << message << endl;
	double param1 = getValue("¬ведите первый параметр: ");
	double param2 = getValue("¬ведите второй параметр: ");
	Vector::Mode mode = getMode("¬ведите режим:");
	return Vector(param1, param2, mode);
}

double getValue(const string& message)
{
	cout << message << endl;
	double value = 0;
	cin >> value;
	if (cin.fail())
	{
		throw("ќшибка ввода");
	}
	return value;
}

Vector::Mode getMode(const string& message)
{
	cout << message << endl;
	cout << Vector::RECT << " дл€ вывода в декартовой "
		"системе координат, " << Vector::POL
		<< " дл€ вывода в пол€рной "
		"системе координат, " << endl;
	int value = 0;
	cin >> value;
	if (cin.fail())
	{
		throw("ќшибка ввода");
	}
	return (Vector::Mode)value;
}
