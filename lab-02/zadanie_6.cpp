#include <iostream>

using namespace std;

int main()
{
  // Plan czynności serwisowych:
  //  a) wymiana oleju: co 30,000 km lub co 2 lata,
  //  b) wymiana świec: co 50,000 km,
  //  c) wymiana rozrządu: co 100,000 km lub 6 lat.

  int p;
  int oilY, oilP;
  int swcP;
  int rozY, rozP;

  int y = 2022;

  bool oilSerwis = false;
  bool swcSerwis = false;
  bool rozSerwis = false;

  cout << "Aktualny przebiej pojazdu: ";
  cin >> p;

  cout << "Rok serwisowania oleju: ";
  cin >> oilY;
  cout << "Przebiej w czasie serwisowania: ";
  cin >> oilP;

  cout << "Przebiej w czasie serwisowania: ";
  cin >> swcP;

  cout << "Rok serwisowania rozrządu: ";
  cin >> rozY;
  cout << "Przebiej w czasie serwisowania: ";
  cin >> rozP;

  if ((y - oilY) >= 2 || (p - oilP) >= 30000) {
    oilSerwis = true;
  }

  if ((p - swcP) >= 50000) {
    swcSerwis = true;
  }

  if ((y - rozY) >= 6 || (p - rozP) >= 100000) {
    rozSerwis = true;
  }

  // Przekroczenie o 20%

  cout << "--------" << endl << "|         |" << endl;

  return 0;
}