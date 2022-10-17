#include <iostream>
#include <string>

using namespace std;

int main()
{
  string imie;
  int wiek;

  cout << "Jak masz na imię: ";
  cin >> imie;

  cout << "Ile masz lat: ";
  cin >> wiek;

  cout << "Cześć, " << imie << "!" << endl;

  if (wiek < 18) {
    cout << "Jesteś małoletni" << endl;
  }
  else if (wiek == 18) {
    cout << "Masz 18 lat!" << endl;
  }
  else if (wiek > 18) {
    cout << "Jesteś dorosły" << endl;
  }
  else {
    cout << "To chyba nie jest twój wiek?" << endl;
  }

  return 0;
}