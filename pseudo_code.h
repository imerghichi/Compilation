//
// Created by taaha on 30/01/2020.
//

#ifndef COMPILATION_PSEUDO_CODE_H
#define COMPILATION_PSEUDO_CODE_H

#include "utilites.h"


typedef enum {
    ADD,
    SUB,
    MUL,
    DIV,
    EQL, //egal
    NEQ, //not egal
    GTR,
    LSS,
    GEQ,
    LEQ,
    PRF,
    RDF,
    INT,
    LDI,
    LDA, // chargement de l'adresse
    LDV, // chargement de la valeur
    STO, // stockage de valeur dans adresse
    BRN,
    BZE, //branch si egal
    HLT, // end of the program
    NOP, // no operation
    PRI,
    PRC,
    NEG, //negatif de nombre
    NBZ, // branch si different
    SPD, //skip instruct
    RTS, // retourner a l adressse dans la pile
    JSR, // jump a sousroutine
    FRE, //free nombre en pile
    DUP, //duplicate tete de pile
}pseudo_code_inst;

static char int_table[30][10] ={
        "ADD",
        "SUB",
        "MUL",
        "DIV",
        "EQL", //egal
        "NEQ", //not egal
        "GTR",
        "LSS",
        "GEQ",
        "LEQ",
        "PRF",
        "RDF",
        "INT",
        "LDI",
        "LDA", // chargement de l'adresse
        "LDV", // chargement de la valeur
        "STO", // stockage de valeur dans adresse
        "BRN",
        "BZE", //branch si egal
        "HLT", // end of the program
        "NOP", // no operation
        "PRI",
        "PRC",
        "NEG", //negatif de nombre
        "NBZ", // branch si different
        "SPD", //skip instruct
        "RTS", // retourner a l adressse dans la pile
        "JSR", // jump a sousroutine
        "FRE", //free nombre en pile
        "DUP", //duplicate tete de pile
};

typedef struct _pseudo_code_ligne{
    int nombre_ligne;
    pseudo_code_inst inst;
    float parametre;
} pseudo_code_ligne;

typedef struct _node{
    struct _node *precedant;
    pseudo_code_ligne ligne;
    struct _node *suivant;
} node;

int nombre_ligne;
node *pseudo_code;
node *pseuo_code_courrant;

void initialiser_pseuo_code();
#endif //COMPILATION_PSEUDO_CODE_H
