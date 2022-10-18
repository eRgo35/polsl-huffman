#include <iostream>

using namespace std;

int main()
{

  double a1, b1, c1, a2, b2, c2;

  /*
    { a1x + b1y = c1
    { a2x + b2y = c2

    zmiana na:

    { y = (c1 - a1x)b1
    { y = (c2 - a2x)b2

    (c1 - a1x)b1 = (c2 - a2x)b2

    c1b1 - a1b1x = c2b2 - a2b2x
  */

  cout << "Podaj a1: ";
  cin >> a1;
  cout << "Podaj b1: ";
  cin >> b1;
  cout << "Podaj c1: ";
  cin >> c1;
  cout << "Podaj a2: ";
  cin >> a2;
  cout << "Podaj b2: ";
  cin >> b2;
  cout << "Podaj c2: ";
  cin >> c2;

  double x, y;

  if ((a1 == 0 && b1 == 0 && c1 == 0) || (a2 == 0 && b2 == 0 && c2 == 0)) {
    cout << "Układ równań posiada nieskończenie wiele rozwiązań" << endl;
    return 0;
  }

  if (b1 == 0 || b2 == 0 || ((-a1/b1) + (a2/b2)) == 0) {
    cout << "Układ równań nie ma rozwiązań" << endl;
    return 0;
  }
  
  // po przekształceniu równań mamy wychodzi poniższy wzór na x oraz y

  x = -((c1/b1) + (-c2/b2)) / ((-a1/b1) + (a2/b2));
  
  y = (a2/b2) * x - (c2/b2);
  
  if (x == 0 && y == 0) {
    cout << "Układ równań posiada nieskończenie wiele rozwiązań" << endl;
    return 0;
  }

  cout << "Rozwiązaniem układu równań " << endl << "(1) " << a1 << "x + " << b1 << "y = " << c1 << endl << "(2) " << a2 << "x + " << b2 << "y = " << c2 << endl << "są liczby (x, y): (" << x << ", " << y << ")" << endl;

  return 0;
}