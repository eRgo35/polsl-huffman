#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string generate_fib()
{
  int a = 1;
  int b = 1;
  int c;

  std::stringstream d;
  d << a << "\n" << b << "\n";

  for (int i = 0; i < 10; i++)
  {
    d << a + b << "\n";
    c = b;
    b += a;
    a = c;
  }
  
  return d.str();
}

int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    for (int i = 1; i < argc; i++)
    {
      if (i + 1 != argc && std::string(argv[i]) == "-o")
      {
        std::ofstream file(argv[i + 1]);
        if (file)
          file << generate_fib();
      }
      std::cout << "File saved to: " << argv[i + 1] << std::endl;
    }
  }
  else
    std::cout << "Provide output location: " << argv[0] << " -o <file>" << std::endl;
  return 0;
}