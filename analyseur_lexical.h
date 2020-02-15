//
// Created by imaane on 28/01/2020.
//

#ifndef COMPILATION_ANALYSEUR_LEXICAL_H
#define COMPILATION_ANALYSEUR_LEXICAL_H

#include "utilites.h"
;static char mots_cles[NOMBRE_TOKENS][30] ={
        "if",
        "else",
        "repeat",
        "while",
        "for",
        "in",
        "break",
        "true",
        "false",
        "null",
        "inf",
        "NAN",
        "-",
};
void lireMot();
static void lire_separateur();
static void lire_erreur();
static void lireNombre();
static void lireComment();
static void lireCar();
static void lire_end_of_file ();
static void lire_nouvelle_ligne ();
static void lire_string();
static void lire_special();

static booleen est_special();
static booleen est_deuxieme_special();
static booleen est_car();
static booleen est_nombre();
static booleen est_separateur();
static booleen est_comment();
static booleen est_double_quote();
static booleen est_simple_quote();
static booleen est_eof();
static booleen est_nouvelle_ligne();
static booleen est_point_car();


void sym_Suivant() ;
void init_sym();

static void assign_token(TOKEN);
static void caractere_suivant();
static void flush_mot();

static void lire_numeral();
static void lire_decimal();
static void point_car();

#endif //COMPILATION_ANALYSEUR_LEXICAL_H
