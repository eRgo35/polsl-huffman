#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <fstream>
#include <random>

void print(std::vector<int> wektor)
{
  std::cout << "[ ";
  for (int w : wektor)
    std::cout << w << " ";
  std::cout << "]" << std::endl;
}

void print(std::list<int> &list)
{
  std::cout << "[ ";
  for (int l : list)
    std::cout << l << " ";
  std::cout << "]" << std::endl;
}

void print(std::set<int> &set)
{
  std::cout << "[ ";
  for (int s : set)
    std::cout << s << " ";
  std::cout << "]" << std::endl;
}

void print(std::map<std::string, std::string> &map)
{
  std::cout << "[ ";
  for (std::pair<std::string, std::string> m : map)
    std::cout << m.first << ": " << m.second << std::endl;
  std::cout << "]" << std::endl;
}

std::string trim(const std::string &s)
{
  // "(Hamlet?"  --> "Hamlet"

  std::size_t first = s.find_first_not_of("(){}[]?!\'\"-.,;:*");
  std::size_t last = s.find_last_not_of("(){}[]?!\'\"-.,;:*");

  if (first != std::string::npos and last != std::string::npos)
    return s.substr(first, last - first + 1);
  else
    return std::string("");
}

int main()
{
  // Zadanie 1

  std::vector<int> wektor = {55, 32, 11, 55, 11, 11};
  std::list<int> list1;
  std::list<int> list2;
  std::set<int> s;

  list1.push_back(55);
  list2.push_front(55);
  s.insert(55);
  list1.push_back(32);
  list2.push_front(32);
  s.insert(32);
  list1.push_back(11);
  list2.push_front(11);
  s.insert(11);
  list1.push_back(55);
  list2.push_front(55);
  s.insert(55);
  list1.push_back(11);
  list2.push_front(11);
  s.insert(11);
  list1.push_back(11);
  list2.push_front(11);
  s.insert(11);

  print(wektor);
  print(list1);
  print(list2);
  print(s);

  list1.push_front(33);
  std::list<int>::iterator i = list1.begin();
  advance(i, 3);
  list1.insert(i, 22);

  print(list1);

  // Zadanie 2

  std::map<std::string, std::string> KtoGdzie;
  KtoGdzie["Kasia"] = "Gliwice";
  KtoGdzie["Kuba"] = "Mikołów";
  KtoGdzie["Ania"] = "Gdynia";
  KtoGdzie.insert(std::pair<std::string, std::string>("Jan", "Katowice"));
  KtoGdzie.insert(std::pair<std::string, std::string>("Piotr", "Mikołów"));
  KtoGdzie.insert(std::pair<std::string, std::string>("Jacek", "Gliwice"));

  print(KtoGdzie);

  // Zadanie 3

  std::ifstream file("pantadeusz.txt");
  std::map<std::string, int> words;

  if (file)
  {
    std::string word;
    while (file >> word)
      words[trim(word)]++;
  }

  for (const auto &word : words)
  {
    std::cout << word.first << " | " << word.second << std::endl;
  }

  // Zadanie 4

  // Zadanie 5
  return 0;
}