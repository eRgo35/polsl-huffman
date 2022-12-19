//
//  funkcje.h
//  projekt_ex
//
//  Created by Agnieszka Danek on 01/12/2021.
//

#ifndef funkcje_h
#define funkcje_h

/**  Funkcja zwracająca wartość f(x) = x dla danego x
 @param  x argument funkcji
 @return wartośc funkcji
*/
double f1(double x); //deklaracja funkcji f1, która pobiera double i zwraca double

/**  Funkcja zwracająca wartość f(x) = x*x dla danego x
@param  x argument funkcji
@return wartośc funkcji
*/
double f2(double x); //deklaracja funkcji f2, która pobiera double i zwraca double

/**  Funkcja zwracająca wartość f(x) = x*x dla danego x
 @param  a początek przedziału całkowania
 @param  b koniec przedziału całkowania
 @param  fun całkowana funkcja
 @return całka oznaczona z funkcji fun w przedziale [a,b]
*/
double calk_num(double a, double b, double (* fun)(double)); //deklaracja funkcji calk_num, która pobiera double, double i wskaźnik na funkcję, która pobiera double i zwraca double


#endif /* funkcje_h */
