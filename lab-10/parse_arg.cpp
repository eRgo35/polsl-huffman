/** @file */

//  parse_arg.h
//  projekt_ex
//
//  Created by Agnieszka Danek on 01/12/2021.
//

#include "parse_arg.h"

params_result odczytaj_argumenty(int ile, const char ** argumenty, std::string & szInput, std::string & szOutput)
{
    const std::string ETYKIETA_INPUT  ("-i");
    const std::string ETYKIETA_OUTPUT ("-o");
    const int    FLAGA_INPUT     = 1;
    const int    FLAGA_OUTPUT    = FLAGA_INPUT << 1;

    const int    POPRAWNY_WYNIK  = FLAGA_INPUT | FLAGA_OUTPUT;
    int wynik = 0;
    
    for (int i = 1; i < ile - 1; i++)
    {
        std::string arg (argumenty[i]);
        if (arg == ETYKIETA_INPUT)
        {
           szInput = argumenty[i + 1];
           wynik |= FLAGA_INPUT;
        }
        if (arg == ETYKIETA_OUTPUT)
        {
           szOutput = argumenty[i + 1];
           wynik |= FLAGA_OUTPUT;
        }
    }
    
    if (wynik == POPRAWNY_WYNIK)
       return params_result::PARAMS_OK  ;
    else
       return params_result::PARAMS_ERROR ;
}
