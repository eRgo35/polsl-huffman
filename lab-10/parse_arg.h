/** @file */


//  parse_arg.h
//  projekt_ex
//
//  Created by Agnieszka Danek on 01/12/2021.
//

#ifndef parse_arg_h
#define parse_arg_h

#include <string>
#include <iostream>

/** Typ reprezentujący wynik spawdzenia parametrów wywołania programu. */
enum params_result
{
   PARAMS_OK,     ///< poprawne wywołanie programu
   PARAMS_HELP,   ///< wywołanie pomocy
   PARAMS_ERROR   ///< niepoprawne parametry wywołania programu
};


/**  Funkcja odczytujaca parametry wywolania programu. Sa one podane w postaci przelacznikow:
 
 -i input                      nazwa pliku wejsciowego

 -o output                     nazwa pliku wyjsciowego

 -h                            wyswielenie pomocy

 Przelaczniki moga byc podane w dowolnej kolejnosci.
 
 uwagi:
 ------
 Brak obsługi "-h" (do zaimplementowania)
 
@param  ile liczba parametrow przy uruchomieniu programu
@param  argumenty tablica wskaznikow na lancuchy uzytych przy uruchomienieu programu
@param  szInput parametr wyjsciowy, do ktorego zostanie zapisana odczytana nazwa pliku wejsciowego
@param  szOutput parameter wyjsciowy, do ktorego zostanie zapisana odczytana nazwa pliku wyjsciowego
@return typ wyliczeniowy params_result
*/
params_result odczytaj_argumenty(int ile, const char ** argumenty, std::string & szInput, std::string & szOutput);


#endif /* parse_arg_h */
