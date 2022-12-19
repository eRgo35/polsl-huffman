/** @file */

//
//  main.cpp
//  projekt_ex
//
//  Created by Agnieszka Danek on 01/12/2021.
//

#include <iostream>
// #include "parse_arg.h"
#include "funkcje.h"

/**  Funkcja main, punkt wyjścia do wykonywania programu
 
@param  argc liczba parametrow przy uruchomieniu programu
@param  argv tablica wskaznikow na lancuchy uzytych przy uruchomienieu programu

@return jeśli program wykonał się prawidłowo zwracane jest 0
*/

int main(int argc, const char ** argv) {

    std::cout << f1(4) << " " << f2(4) << std::endl;
    
    //double f1(double); //przykładowa deklaracja funkcji f1 pobierającej double i zwracającej double
    //Wskaźnik na funkcję
    double (*wsk_fun)(double); //wskaźnik wsk_fun na funkcję pobierającą double i zwracającą double
    wsk_fun = f1;
    double (*tab1[3]) (double); //tablica wskaźników na funkcje pobierające double i zwracające double
    tab1[0] = f1;
    tab1[1] = f2;
    
    typedef double (*pf)(double);
    pf tab2[3];  //tablica wskaźników na funkcje pobierające double i zwracające double
    tab2[0] = f1;
    tab2[1] = f2;
    
    
    std::cout << tab1[0](4) << " " << tab2[1](4) << std::endl;
    
    double a = 1;
    double b = 10;
    double res = calk_num(a, b, f1);
    res = calk_num(a, b, f2);
    
    std::cout << a << " " << b << " " << res << std::endl;
    
    std::string in_file, out_file;

    // if(odczytaj_argumenty(argc, argv, in_file, out_file) == PARAMS_OK)
    // {
    //     std::cout << "Nazwa pliku wejściowego: " <<  in_file << std::endl;
    //     std::cout << "Nazwa pliku wyjściowego: " <<  out_file << std::endl;
    // }
    // else
    // {
    //     std::cout << "Nieprawidłowe parametry wywołania programu" << std::endl;
    // }
    
    
    
    
    
    
    return 0;
}
