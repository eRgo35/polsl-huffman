#include <iostream>
#include <random>

void zad1_petle(); // deklaracja funkcji typu void (nic nie zwraca)
void zad1_dzielnik();
void zad1_potega();
void zad2_prime();
void zad3_gra();
void zad4_gra();
void zad5_zbior();

int main()
{

  // zad1_petle(); //wywołanie funkcji
  //  zad1_dzielnik();
  //  zad1_potega();
  // zad2_prime();
  // zad3_gra();
  zad4_gra();
  // zad5_zbior();

  return 0;
}

void zad1_petle() // definicja funkcji
{

  int n;
  std::cout << "Zadanie 1\n";
  std::cout << "Podaj liczbe: ";
  std::cin >> n;

  std::cout << "\nPetla for" << std::endl;
  for (int i = 1; i <= n; i++)
  {
    std::cout << i << " ";
  }
  std::cout << "\nPetla while" << std::endl;
  int i = 1;
  while (i <= n)
  {
    std::cout << i << " ";
    i++; // i = i + 1;
  }
  std::cout << "\nPetla do..while" << std::endl;
  i = 1;
  do
  {
    std::cout << i << " ";
    i++;
  } while (i <= n);

  std::cout << std::endl
            << "***" << std::endl;

  std::cout << "\nPetla for (odwrotna kolejnosc)" << std::endl;
  for (int i = n; i >= 1; i--)
  {
    std::cout << i << " ";
  }

  std::cout << "\nPetla while (odwrotna kolejnosc)" << std::endl;
  {
    int i = n;
    while (i >= 1)
    {
      std::cout << i << " ";
      i--;
    }
  }

  std::cout << "\nPetla do..while (odwrotna kolejnosc)" << std::endl;
  {
    int i = n;
    do
    {
      std::cout << i << " ";
      i--;
    } while (i >= 1);
  }

  std::cout << std::endl
            << "***" << std::endl;
}

void zad1_dzielnik()
{
  std::cout << "\nPodaj start stop dzielnik";
  int start, stop, dzielnik;
  std::cin >> start >> stop >> dzielnik;

  for (int i = start; i < stop; i++)
  {
    if (i % dzielnik == 0)
    {
      std::cout << i << std::endl;
    }
  }

  // operator %
  /* *
  0%2 -> 0
  1%2 -> 1
  2%2 -> 0
  3%2 -> 1
  4%2 -> 0
  5%2 -> 1
  6%2 -> 0

  0%3 -> 0
  1%3 -> 1
  2%3 -> 2
  3%3 -> 0
  4%3 -> 1
  5%3 -> 2
  6%3 -> 0
  */
}

void zad1_potega()
{
  std::cout << "\nPodaj podstawe i wykladnik";
  int podstawa, wykladnik;
  std::cin >> podstawa >> wykladnik;

  if (wykladnik < 0)
    std::cout << " brak obsługi\n";
  else if (wykladnik == 0)
    std::cout << "Wynik: 1\n";
  else
  {
    long wynik = 1;
    int i = 0;
    while (true)
    {
      if (i >= wykladnik)
        break;
      i++;
      wynik *= podstawa;
    }

    std::cout << "Wynik: " << wynik << std::endl;
  }
}

void zad2_prime()
{
  std::cout << "Podaj liczbę: ";
  long liczba;
  std::cin >> liczba;
  if (liczba <= 1)
  {
    std::cout << "liczby pierwsze mogą być tylko liczbami naturalnymi większymi od 1" << std::endl;
    return;
  }
  for (int i = 2; i < sqrt(liczba); i++)
  {
    if (liczba % i == 0)
    {
      std::cout << "liczba nie jest pierwsza" << std::endl;
      return;
    }
  }
  std::cout << "liczba jest pierwsza" << std::endl;
  return;
}

void zad3_gra()
{
  // source: https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
  std::random_device rd;  // Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> distrib(1, 100);

  int liczba = distrib(gen);

  std::cout << "Zgadnij liczbe z przedzialu [1,100]" << std::endl;

  int proby = 0;
  int strzal;

  while (true)
  {
    if (proby > 10)
    {
      std::cout << "Niestety nie trafiłeś w 10 próbach" << std::endl;
      return;
    }

    std::cout << "Strzelaj: ";
    std::cin >> strzal;

    if (strzal == liczba)
    {
      std::cout << "Gratulacje! Zgadłeś w " << proby << " próbach!" << std::endl;
      return;
    }

    if (strzal > liczba)
    {
      std::cout << "liczba jest mniejsza" << std::endl;
    }

    if (strzal < liczba)
    {
      std::cout << "liczba jest większa" << std::endl;
    }

    proby++;
  }

  return;
}

void zad4_gra()
{
  int min = 1;
  int max = 100;

  std::cout << "Podaj minimalną liczbę z przedziału (domyślnie 1): ";
  std::cin >> min;
  std::cout << "Podaj maksymalną liczbę z przedziału (domyślnie 100): ";
  std::cin >> max;

  std::cout << "Zgadnę liczbe z przedzialu [" << min << ", " << max << "]" << std::endl;

  char tn;
  int liczba;
  int max_l = max;
  int min_l = min;

  while (true)
  {
    liczba = (max_l + min_l) / 2;
    std::cout << "Czy twoja liczba jest większa od " << liczba << " (t/n)? ";
    std::cin >> tn;

    if (tn == 't')
    {
      min_l = liczba;
    }

    if (tn == 'n')
    {
      max_l = liczba;
    }

    if (max_l - min_l < 2)
    {
      std::cout << "Twoja liczba to " << liczba << std::endl;
      return;
    }

    // std::cout << std::endl << "Stack: " << min_l << " " << max_l << " " << liczba << std::endl;
  }
  return;
}

void zad5_zbior()
{
  int liczby[1337]{};
  int i = 0;
  double avg = 0;
  int sum = 0;

  std::cout << "Podaj liczby (użyj Ctrl-D aby zakończyć wprowadzanie): ";
  while (std::cin >> liczby[i])
    i++;

  for (int j = 0; j < i; j++)
    sum += liczby[j];
  avg = (double)sum / i;

  int min = liczby[0];
  int max = liczby[0];
  double sigma_sum = 0;

  for (int j = 0; j < i; j++)
  {
    if (min > liczby[j])
      min = liczby[j];
    if (max < liczby[j])
      max = liczby[j];
    sigma_sum += pow((liczby[j] - avg), 2);
  }

  double diff = sqrt(sigma_sum / i);

  std::cout << "Ilość liczb: " << i << std::endl;
  std::cout << "Średnia: " << avg << std::endl;
  std::cout << "Minimalna: " << min << std::endl;
  std::cout << "Maksymalna: " << max << std::endl;
  std::cout << "Odchylenie: " << diff << std::endl;
}