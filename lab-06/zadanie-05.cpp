#include <iostream>
#include <random>
#include <cmath>

struct Point
{
  double x;
  double y;
} point;

struct Square
{
  Point point1;
  Point point2;
} square;

struct Circle
{
  Point point;
  double length;
} circle;

struct Time
{
  int hours;
  int minutes;
  int seconds;
};

double distance_between_two_points(Point a, Point b)
{
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

int main()
{
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 100.00);
  Point a, b;
  for (int i = 0; i < 10; ++i)
  {
    a.x = distribution(generator);
    a.y = distribution(generator);

    b.x = distribution(generator);
    b.y = distribution(generator);

    std::cout << "(" << a.x << ", " << a.y << ") and (" << b.x << ", " << b.y << ") = " << distance_between_two_points(a, b) << std::endl;
  }

  return 0;
}