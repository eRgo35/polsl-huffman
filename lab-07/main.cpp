#include <iostream>
#include <vector>

#include "plane.h"
#include "time.h"

int main()
{
  std::vector<Point> points = generate_points_vector(1000);

  // check if points render properly
  for (Point point : points)
    printf("(%f, %f)\n", point.x, point.y);

  std::vector<Square> squares = generate_squares_vector(10);

  // check if squares render properly
  for (Square square : squares)
    printf("[(%f, %f), (%f, %f)]\n", square.point1.x, square.point1.y, square.point2.x, square.point2.y);

  std::vector<Circle> circles = generate_circles_vector(10);

  // check if circles render properly
  for (Circle circle : circles)
    printf("[(%f, %f), %f]\n", circle.point.x, circle.point.y, circle.length);

  double distance = distance_between_two_points(points[(int)generate_random_number()], points[(int)generate_random_number()]);

  // check if distance is calculated properly
  printf("d = %f\n", distance);

  Point center = center_between_two_points(points[(int)generate_random_number()], points[(int)generate_random_number()]);

  // check if center is calculated properly
  printf("(%f, %f)\n", center.x, center.y);

  double area = area_of_a_square(squares[(int)generate_random_number()]);

  // check if area is calculated properly
  printf("area = %f\n", area);

  Square square1 = squares[(int)generate_random_number()];
  Square square2 = squares[(int)generate_random_number()];
  Square bigger = bigger_square(square1, square2);

  // check if square size is calculated properly
  printf("bigger = %f | square1 = %f | square2 = %f\n", area_of_a_square(bigger), area_of_a_square(square1), area_of_a_square(square2));

  double carea = area_of_a_circle(circles[(int)generate_random_number()]);

  // check if area is calculated properly
  printf("area = %f\n", carea);

  Circle circle1 = circles[(int)generate_random_number()];
  Circle circle2 = circles[(int)generate_random_number()];
  circle_position type = mutual_position_of_two_circles(circle1, circle2);
  
  std::string type_s;
  switch(type)
  {
    case coaxial: type_s = "współśrodkowe"; break;
    case intrinsically_tangential: type_s = "styczne wewnętrznie"; break;
    case extrinsic_tangent: type_s = "styczne zewnętrznie"; break;
    case internally_disconnected: type_s = "rozłączne wewnętrznie"; break;
    case externally_disconnected: type_s = "rozłączne zewnętrznie"; break;
    case intersecting: type_s = "przecinające się"; break;
  }
  
  // check if position is calculated properly
  printf("type = %s | circle1 = (%f, %f), %f | circle2 = (%f, %f), %f\n", type_s.c_str(), circle1.point.x, circle1.point.y, circle1.length, circle2.point.x, circle2.point.y, circle2.length);

  std::cout << "------------------------------------------------" << std::endl;

  Time time1{23, 59, 59};

  Time time2{0, 0, 2};

  Time time3{0, 0, 1};

  add_time(time1, time2);

  printf("%i:%i:%i\n", time1.hours, time1.minutes, time1.seconds);

  sub_time(time3, time2);

  printf("%i:%i:%i\n", time3.hours, time3.minutes, time3.seconds);

  return 0;
}