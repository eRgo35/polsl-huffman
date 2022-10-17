#include <iostream>

using namespace std;

int main()
{
  int g = 5;
  char tn;

  while (true)
  {
    cout << "Czy twoja liczba jest mniejsza od " << g << "? ";

    cin >> tn;

    if (tn == 'n')
    {
      if (g == 7)
      {
        g += 1;
        continue;
      }
      if (g == 8)
      {
        cout << "Twoja liczba to 8" << endl;
        break;
      }
      g += 2;
      continue;
    }
    else if (tn == 't')
    {
      if (g == 3)
      {
        g -= 1;
        continue;
      }
      if (g == 2)
      {
        cout << "Twoja liczba to 1" << endl;
        break;
      }
      g -= 2;
      continue;
    }
    else
    {
      continue;
    }
  }
  return 0;
}