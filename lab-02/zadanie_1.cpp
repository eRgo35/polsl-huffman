#include <iostream>
using namespace std;
int main()
{
  double a, b;
  
  cout << "Podaj liczbę a: ";
  cin >> a;
  cout << "Podaj liczbę b: ";
  cin >> b;
  
  cout << a << " + " << b << " = " << a + b << endl;
  cout << a << " - " << b << " = " << a - b << endl;
  cout << a << " * " << b << " = " << a * b << endl;
  cout << a << " / " << b << " = " << a / b << endl;
  return 0;
}