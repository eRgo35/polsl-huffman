#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  double a, b, c;

  cout << "Podaj a: ";
  cin >> a;

  cout << "Podaj b: ";
  cin >> b;

  cout << "Podaj c: ";
  cin >> c;

  if (a == 0 && b == 0 && c == 0)
  {
    cout << "Spełniają wszystkie liczby rzeczywiste" << endl;
    return 0;
  }

  if (a == 0 && b == 0)
  {
    cout << "Sprzeczność, " << c << " = " << "0" << endl;
    return 0;
  }

  if (a == 0)
  {
    cout << (-c/b) << endl;
    return 0;
  }

  double d = b*b-4*a*c;

  if (d < 0) {
    cout << "Liczby zespolone, delta = " << d << endl;
    return 0;
  }

  if (d == 0) {
    cout << (-b/(2*a)) << endl;
    return 0;
  }

  if (d > 0) {
    cout << "x1 = " << ((-b-sqrt(d))/(2*a)) << "; x2 = " << ((-b+sqrt(d))/(2*a)) << endl;
    return 0;
  }

  cout << "Nieprawidłowe wartości!" << endl;
  
  return 0;
}