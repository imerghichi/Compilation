#ifndef COMPILATION_PSEUDO_CODE_H
#define COMPILATION_PSEUDO_CODE_H

#include "utilites.h"

typedef enum _pcode_inst {
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
}pcode_inst;

static char inst_table[30][10] ={
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
    pcode_inst inst;
    float parametre;
} pseudo_code_ligne;

typedef struct _node{
    struct _node *precedant;
    pseudo_code_ligne ligne;
    struct _node *suivant;
} node;

int nombre_ligne;
node *pseudo_code;
node *pseudo_code_courrant;

void initialiser_pseudo_code();
void ajouter_inst(pcode_inst inst, float parametre);
void ecrire_pseud_code(); //en binaire
void ecrire_pseudo_code_texte();
void lire_pseudo_code_texte();
void afficher_pseudo_code();
void afficher_pseudo_code_texte();

void bze_pseudo_code_fixer();
void nbz_pseudo_code_fixer();
void brn_pseudo_code_fixer();
void spd_pseudo_code_fixer();
int pseudo_code_ligne_courrante();

#endif //COMPILATION_PSEUDO_CODE_H
