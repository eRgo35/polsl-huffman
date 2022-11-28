#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <vector>
#include <cmath>

enum circle_position
{
  coaxial,
  intrinsically_tangential,
  extrinsic_tangent,
  internally_disconnected,
  externally_disconnected,
  intersecting
};

struct Point
{
  double x, y;
};

struct Square
{
  Point point1, point2;
};

struct Circle
{
  Point point;
  double length;
};

double generate_random_number();

std::vector<Point> generate_points_vector(int N);

std::vector<Square> generate_squares_vector(int M);

std::vector<Circle> generate_circles_vector(int O);

double distance_between_two_points(Point &a, Point &b);

Point center_between_two_points(Point &a, Point &b);

double area_of_a_square(Square &square);

Square bigger_square(Square &square1, Square &square2);

double area_of_a_circle(Circle &circle);

circle_position mutual_position_of_two_circles(Circle &circle1, Circle &circle2);

#endif