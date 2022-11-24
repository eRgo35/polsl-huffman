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

double area_of_a_square(Square square)
{
  double side = distance_between_two_points(square.point1, square.point2);
  return side * side;
}

Square bigger_square(Square square1, Square square2)
{
  if (area_of_a_square(square1) > area_of_a_square(square2))
    return square1;
  return square2;
}

double area_of_a_circle(Circle circle)
{
  return 3.1415 * circle.length * circle.length;
}

char *mutual_position_of_two_circles(Circle circle1, Circle circle2)
{
  if (distance_between_two_points(circle1.point, circle2.point) == 0)
    return "współśrodkowe";

  if (distance_between_two_points(circle1.point, circle2.point) == fabs(circle1.length - circle2.length))
    return "styczne wewnętrznie";

  if (distance_between_two_points(circle1.point, circle2.point) == circle1.length + circle2.length)
    return "styczne zewnętznie";

  if (distance_between_two_points(circle1.point, circle2.point) < fabs(circle1.length - circle2.length))
    return "rozłączne wewnętrznie";

  if (distance_between_two_points(circle1.point, circle2.point) > circle1.length + circle2.length)
    return "rozłączne zewnętrznie";

  return "przecinające się";
}

void add_time(Time &time1, Time &time2)
{
  if ((time1.seconds += time2.seconds) >= 60)
  {
    time1.seconds %= 60;
    time1.minutes++;
  }

  if ((time1.minutes += time2.minutes) >= 60)
  {
    time1.minutes %= 60;
    time1.hours++;
  }

  if ((time1.hours += time2.hours) >= 24)
  {
    time1.hours %= 24;
  }
}

void sub_time(Time &time1, Time &time2)
{
  if ((time1.seconds -= time2.seconds) < 0)
  {
    time1.seconds += 60;
    time1.minutes--;
  }

  if ((time1.minutes -= time2.minutes) < 0)
  {
    time1.minutes += 60;
    time1.hours--;
  }

  if ((time1.hours += time2.hours) < 0)
  {
    time1.hours += 24;
  }
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

  double distance = distance_between_two_points(points[(int)generate_random_number()], points[(int)generate_random_number()]);

  // check if distance is calculated properly
  // printf("d = %f\n", distance);

  Point center = center_between_two_points(points[(int)generate_random_number()], points[(int)generate_random_number()]);

  // check if center is calculated properly
  // printf("(%f, %f)\n", center.x, center.y);

  double area = area_of_a_square(squares[(int)generate_random_number()]);

  // check if area is calculated properly
  // printf("area = %f\n", area);

  Square square1 = squares[(int)generate_random_number()];
  Square square2 = squares[(int)generate_random_number()];
  Square bigger = bigger_square(square1, square2);

  // check if square size is calculated properly
  // printf("bigger = %f | square1 = %f | square2 = %f\n", area_of_a_square(bigger), area_of_a_square(square1), area_of_a_square(square2));

  double carea = area_of_a_circle(circles[(int)generate_random_number()]);

  // check if area is calculated properly
  // printf("area = %f\n", carea);

  enum circle_position
  {

  };

  Circle circle1 = circles[(int)generate_random_number()];
  Circle circle2 = circles[(int)generate_random_number()];
  char *type = mutual_position_of_two_circles(circle1, circle2);
  // check if position is calculated properly
  printf("type = %s | circle1 = (%f, %f), %f | circle2 = (%f, %f), %f\n", type, circle1.point.x, circle1.point.y, circle1.length, circle2.point.x, circle2.point.y, circle2.length);

  std::cout << "------------------------------------------------" << std::endl;

  Time time1;
  time1.hours = 23;
  time1.minutes = 59;
  time1.seconds = 59;

  Time time2;
  time2.hours = 0;
  time2.minutes = 0;
  time2.seconds = 2;

  Time time3;
  time3.hours = 0;
  time3.minutes = 0;
  time3.seconds = 1;

  add_time(time1, time2);

  printf("%i:%i:%i\n", time1.hours, time1.minutes, time1.seconds);

  sub_time(time3, time2);

  printf("%i:%i:%i\n", time3.hours, time3.minutes, time3.seconds);

  return 0;
}