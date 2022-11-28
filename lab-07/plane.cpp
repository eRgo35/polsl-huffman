#include "plane.h"
#include <random>

std::default_random_engine generator;
std::uniform_real_distribution<double> distribution(0.0, 100.00);

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
    Point point{x : generate_random_number(), y : generate_random_number()};
    vec.push_back(point);
  }
  return vec;
}

std::vector<Square> generate_squares_vector(int M)
{
  std::vector<Square> vec;
  for (int i = 0; i < M; i++)
  {
    std::vector<Point> points = generate_points_vector(2);
    Square square{point1 : points.at(0), point2 : points.at(1)};
    vec.push_back(square);
  }
  return vec;
}

std::vector<Circle> generate_circles_vector(int O)
{
  std::vector<Circle> vec;
  for (int i = 0; i < O; i++)
  {
    std::vector<Point> point = generate_points_vector(1);
    Circle circle{point : point.at(0), length : generate_random_number()};
    vec.push_back(circle);
  }
  return vec;
}

double distance_between_two_points(Point &a, Point &b)
{
  return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

Point center_between_two_points(Point &a, Point &b)
{
  Point point{x : (a.x + b.x / 2), y : (a.y + b.y / 2)};
  return point;
}

double area_of_a_square(Square &square)
{
  double side = distance_between_two_points(square.point1, square.point2);
  return side * side;
}

Square bigger_square(Square &square1, Square &square2)
{
  if (area_of_a_square(square1) > area_of_a_square(square2))
    return square1;
  return square2;
}

double area_of_a_circle(Circle &circle)
{
  return 3.1415 * circle.length * circle.length;
}

circle_position mutual_position_of_two_circles(Circle &circle1, Circle &circle2)
{
  if (distance_between_two_points(circle1.point, circle2.point) == 0)
    return coaxial;

  if (distance_between_two_points(circle1.point, circle2.point) == fabs(circle1.length - circle2.length))
    return intrinsically_tangential;

  if (distance_between_two_points(circle1.point, circle2.point) == circle1.length + circle2.length)
    return extrinsic_tangent;

  if (distance_between_two_points(circle1.point, circle2.point) < fabs(circle1.length - circle2.length))
    return internally_disconnected;

  if (distance_between_two_points(circle1.point, circle2.point) > circle1.length + circle2.length)
    return externally_disconnected;

  return intersecting;
}