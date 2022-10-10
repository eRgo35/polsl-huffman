#include <iostream>

using namespace std;

int main() {
  cout << "Hello, world!" << endl << "Please provide how long the loop should work:";

  int a = 0;
  int b = 1;

  int t;
  cin >> t;

  cout << a << endl << b << endl;

  for (int i = 0; i < t; i++) {
    b = a + b;
    a = b;
    // 0 1 1 2 3 

    cout << a << endl;
  }

  return 0;
}
