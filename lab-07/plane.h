#ifndef PLANE_H
#define PLANE_H

#include <iostream>
#include <vector>
#include <cmath>

/**
 * @brief zbiór rodzajów położenia dwóch kół
 * 
 */
enum circle_position
{
  coaxial,
  intrinsically_tangential,
  extrinsic_tangent,
  internally_disconnected,
  externally_disconnected,
  intersecting
};

/**
 * @brief struktura opisująca punkt
 * 
 */
struct Point
{
  double x, y;
};

/**
 * @brief struktura opisująca kwadrat
 * 
 */
struct Square
{
  Point point1, point2;
};

/**
 * @brief struktura opisująca koło
 * 
 */
struct Circle
{
  Point point;
  double length;
};

/**
 * @brief zwraca losową liczbę w przedziale podanym w zmiennej distribution
 * 
 * @return double 
 */
double generate_random_number();

/**
 * @brief generuje wektor N - punktów
 * 
 * @param N 
 * @return std::vector<Point> 
 */
std::vector<Point> generate_points_vector(int N);

/**
 * @brief generuje wektor M - kwadratów
 * 
 * @param M 
 * @return std::vector<Square> 
 */
std::vector<Square> generate_squares_vector(int M);

/**
 * @brief generuje wektor O - kół
 * 
 * @param O 
 * @return std::vector<Circle> 
 */
std::vector<Circle> generate_circles_vector(int O);

/**
 * @brief zwraca odległość pomiędzy dwoma punktami
 * 
 * @param a 
 * @param b 
 * @return double 
 */
double distance_between_two_points(Point &a, Point &b);

/**
 * @brief zwraca punkt środkowy pomiędzy dwoma punktami
 * 
 * @param a 
 * @param b 
 * @return Point 
 */
Point center_between_two_points(Point &a, Point &b);

/**
 * @brief zwraca pole kwadratu
 * 
 * @param square 
 * @return double 
 */
double area_of_a_square(Square &square);

/**
 * @brief zwraca większy kwadrat
 * 
 * @param square1 
 * @param square2 
 * @return Square 
 */
Square bigger_square(Square &square1, Square &square2);

/**
 * @brief zwraca pole koła
 * 
 * @param circle 
 * @return double 
 */
double area_of_a_circle(Circle &circle);

/**
 * @brief zwraca wzajemne położenie między dwoma okręgami
 * 
 * @param circle1 
 * @param circle2 
 * @return circle_position 
 */
circle_position mutual_position_of_two_circles(Circle &circle1, Circle &circle2);

#endif