#include <iostream>

using namespace std;

int main() {
  cout << "Hello, world!" << endl << "Please provide how long the loop should work:";

  unsigned long int a = 0;
  unsigned long int b = 1;

  unsigned long long int c, t;
  cin >> t;

  cout << a << endl << b << endl;

  for (int i = 0; i < t; i++) {
    c = a + b;
    a = b;
    b = c;
    cout << c << endl;
  }

  return 0;
}
