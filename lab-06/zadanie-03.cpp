#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
  for (int i = 1; i < argc; i++)
  {
    if (i + 1 != argc && std::string(argv[i]) == "-i")
      std::cout << "Plik wejściowy: " << argv[i + 1] << std::endl;

    if (i + 1 != argc && std::string(argv[i]) == "-o")
      std::cout << "Plik wyjściowy: " << argv[i + 1] << std::endl;
  }
  return 0;
}