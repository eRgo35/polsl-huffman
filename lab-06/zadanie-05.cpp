#include <iostream>
#include <random>
#include <cmath>
#include <vector>

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 100.00);

struct Point
{
  double x;
  double y;
};

struct Square
{
  Point point1;
  Point point2;
};

struct Circle
{
  Point point;
  double length;
};

struct Time
{
  int hours;
  int minutes;
  int seconds;
};

double generate_random_number()
{
  double num = distribution(generator);

  return num;
}

std::vector<Point> generate_points_vector(int N)
{
  std::vector<Point> vec;
  for (int i = 0; i < N; i++)
  {
    Point point;
    point.x = generate_random_number();
    point.y = generate_random_number();
    vec.push_back(point);
  }
  return vec;
}

std::vector<Square> generate_squares_vector(int M)
{
  std::vector<Square> vec;
  for (int i = 0; i < M; i++)
  {
    Square square;
    std::vector<Point> points = generate_points_vector(2);
    square.point1 = points.at(0);
    square.point2 = points.at(1);
    vec.push_back(square);
  }
  return vec;
}

std::vector<Circle> generate_circles_vector(int O)
{
  std::vector<Circle> vec;
  for (int i = 0; i < O; i++)
  {
    Circle circle;
    std::vector<Point> point = generate_points_vector(1);
    circle.point = point.at(0);
    circle.length = generate_random_number();
    vec.push_back(circle);
  }
  return vec;
}

double distance_between_two_points(Point a, Point b)
{
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

Point center_between_two_points(Point a, Point b)
{
  Point point;
  point.x = (a.x + b.x / 2);
  point.y = (a.y + b.y / 2);

  return point;
}

int main()
{
  std::vector<Point> points = generate_points_vector(1000);

  // check if points render properly
  // for (Point point : points)
  // printf("(%f, %f)\n", point.x, point.y);

  std::vector<Square> squares = generate_squares_vector(10);

  // check if squares render properly
  // for (Square square : squares)
  // printf("[(%f, %f), (%f, %f)]\n", square.point1.x, square.point1.y, square.point2.x, square.point2.y);

  std::vector<Circle> circles = generate_circles_vector(10);

  // check if circles render properly
  // for (Circle circle : circles)
  // printf("[(%f, %f), %f]\n", circle.point.x, circle.point.y, circle.length);

  double distance = distance_between_two_points(points[(int) generate_random_number()], points[(int) generate_random_number()]);
  
  // check if distance is calculated properly
  // printf("d = %f\n", distance);

  Point center = center_between_two_points(points[(int) generate_random_number()], points[(int) generate_random_number()]);

  // check if center is calculated properly
  // printf("(%f, %f)\n", center.x, center.y);

  
  return 0;
}