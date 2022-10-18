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

  bool oilPilne = false;
  bool swcPilne = false;
  bool rozPilne = false;

  int oilYRek = 2;
  int oilPRek = 30000;
  int swcPRek = 50000;
  int rozYRek = 6;
  int rozPRek = 100000;

  cout << "Aktualny przebiej pojazdu: ";
  cin >> p;

  cout << "Rok serwisowania oleju: ";
  cin >> oilY;
  cout << "Przebiej przed ostatnią wymianą oleju: ";
  cin >> oilP;

  cout << "Przebiej przed ostatnią wymianą świec: ";
  cin >> swcP;

  cout << "Rok serwisowania rozrządu: ";
  cin >> rozY;
  cout << "Przebiej przed ostatnią wymianą rozrządu: ";
  cin >> rozP;

  if ((y - oilY) >= oilYRek || (p - oilP) >= oilPRek)
  {
    oilSerwis = true;
  }

  if ((p - swcP) >= swcPRek)
  {
    swcSerwis = true;
  }

  if ((y - rozY) >= rozYRek || (p - rozP) >= rozPRek)
  {
    rozSerwis = true;
  }

  if ((y - oilY) >= (oilYRek + 1) || (p - oilP) >= (oilPRek * 1.2))
  {
    oilPilne = true;
  }

  if ((p - swcP) >= (swcPRek * 1.2))
  {
    swcPilne = true;
  }

  if ((y - rozY) >= (rozYRek + 1) || (p - rozP) >= (rozPRek * 1.2))
  {
    rozPilne = true;
  }

  // Przekroczenie o 20%

  cout << "| czynność serwisowa | konieczność serwisu |" << endl;
  cout << "|--------------------+---------------------|" << endl;
  cout << "| wymiana oleju      | " << (oilSerwis ? "        tak        " : (oilPilne) ? "      Pilne !      " :  "        nie        ") << " |" << endl;
  cout << "| wymiana świec      | " << (swcSerwis ? "        tak        " : (swcPilne) ? "      Pilne !      " :  "        nie        ") << " |" << endl;
  cout << "| wymiana rozrządu   | " << (rozSerwis ? "        tak        " : (rozPilne) ? "      Pilne !      " :  "        nie        ") << " |" << endl;

  return 0;
}