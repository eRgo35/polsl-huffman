#include <iostream>

using namespace std;

int main()
{
  int g = 4;
  char tn;

  cout << "Czy twoja liczba jest mniejsza lub równa " << g << "? ";
  cin >> tn;

  if (tn == 't')
  {
    // przedział zmniejsza się do 1-4
    g -= 2;
  }

  if (tn == 'n')
  {
    // przedział zmniejsza się do 5-8
    g += 2;
  }

  cout << "Czy twoja liczba jest mniejsza lub równa " << g << "? ";
  cin >> tn;

  if (tn == 't')
  {
    // przedział zmniejsza się do 1-2 lub 5-6
    g--;
  }

  if (tn == 'n')
  {
    // przedział zmniejsza się do 3-4 lub 7-8
    g++;
  }

  cout << "Czy twoja liczba jest mniejsza lub równa " << g << "? ";
  cin >> tn;

  if (tn == 't')
  {

  }

  if (tn == 'n')
  {
    g++;
  }

  cout << "Twoja liczba to: " << g << endl;

  return 0;
}