//
// Created by imaane on 30/01/2020.
//

#ifndef COMPILATION_ERREURS_H
#define COMPILATION_ERREURS_H

#include "utilites.h"
#define ERREUR_NOMBRE 19

;typedef enum _erreurs_codes{
    CARACTERE_INCONNU,
    SINGLE_QUOTE,
    CARACTERE_DEMANDE,
    SIMPLE_QUOTE_ERROR,
} erreurs_codes;

void raise_erreur(erreurs_codes);

#endif //COMPILATION_ERREURS_H
