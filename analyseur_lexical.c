//
// Created by taaha on 28/01/2020.
//

#include "analyseur_lexical.h"
#include "utilites.h"

int index_courrant = 0;


static booleen est_special(){r;e
    switch (char_courrant){
        case ':':
        case '+':
        case '-':
        case '*':
        case ';':
        case '(':
        case ')':
        case '<':
        case '>':
        case '/':
        case '=':
            return true;
        default:
            return false;
    }
}
static booleen est_car(){
    if ((char_courrant >= 'a' && char_courrant <='z') ||(char_courrant >= 'A' && char_courrant <= 'Z')){
        return true;
    }
    return false;
}
static booleen est_nombre(){
    if (char_courrant >= '0' && char_courrant <= '9'){
        return true;
    }
    return false;
}
static booleen est_separateur();
static booleen est_comment(){
    if(char_courrant == "#") return true;
    return false;
}
static booleen est_double_quote();
static booleen est_simple_quote();
static booleen est_eof();
static booleen est_nouvelle_ligne();

void sym_Suivant() {
    do{
        //clear le buffer
        flush_mot();

        //grammaire
        if(est_eof()) lire_end_of_file();
        else if (est_point_car()) point_car();
        else if (est_nombre()) lireNombre();
        else if (est_comment()) lireComment();
        else if (est_car()) lireCar();
        else if (est_special()) lire_special
        else if (est_double_quote()) lire_string();
        else if (est_simple_quote()) lireCar();
        else if  (est_separateur()) lire_separateur();
        else if (est_nouvelle_ligne()) lire_nouvelle_ligne();
        else if (est_car()) lireMot();
        else lire_erreur();
    }while (symbole_courrant.code = SEPARATOR_TOKEN)

}
void init_sym(){
    //initialiser compteur de lignes
    ligne_courrante = 1;
    //lire premier caractere
    caractere_suivant();
}

static void assign_token(TOKEN token){

    symbole_courrant.mot[index_courrant -1] = '\0';
    if (token != NOTHING){
        symbole_courrant.code =token;
        if (token != SEPARATOR_TOKEN) printf ("AFF %i : %s \n", token, symbole_courrant.mot);
    }
    else {
        //comparer
        int i;
        for (i=0; i<NOMBRE_TOKENS; i++){
            if (strcmp(symbole_courrant.mot,mots_cles[i]) == 0) {
                symbole_courrant.code = i ;
                printf ("AFF %i : %s \n", i, symbole_courrant.mot);
                break;
            }
        }
        // on a pas trouvé de token donc id
        if (i == NOMBRE_TOKENS) {
            symbole_courrant.code =ID_TOKEN;
            printf ("AFF %i : %s \n", i, symbole_courrant.mot);
        }
    }
}
static void caractere_suivant(){
    char_courrant = fgetc (fichier);

    symbole_courrant.mot[index_courrant] = char_courrant;
    index_courrant++;
    symbole_courrant.mot[index_courrant] = '\0';
    // verifier qu on a pas depasser le buffer
    index_courrant %= LONGUEUR_MOT -1;
}
static void flush_mot(){
    index_courrant = 1;
    symbole_courrant.mot[0] = char_courrant;
    symbole_courrant.mot[1] = '\0';
}

static void lire_numeral();
static void lire_decimal();
static void lire_string();
static void lire special;
static void point_car();

void lireMot(){
/*
    memset(sym_Cour.NOM , '\0' , 100);
    sym_Cour.NOM[0]=car_Cour;
    int i =1;
    lireCar();
    while((car_Cour>='a' && car_Cour<='z')||(car_Cour>='A' && car_Cour<='Z')||(car_Cour>=48 && car_Cour<=57) || car_Cour==95){ // _ lettres et chiffres
        sym_Cour.NOM[i]=car_Cour;
        i++;
        lireCar();
    }
    if(strlen(sym_Cour.NOM)>250){
        sym_Cour.CODE = ERREUR_TOKEN;
        Gen_Erreur(ERR_ID_LONG);
    }
    else if(strcmp(sym_Cour.NOM,"if")){
        sym_Cour.CODE = IF_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"else")){
        sym_Cour.CODE = ELSE_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"repeat")){
        sym_Cour.CODE = REPEAT_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"while")){
        sym_Cour.CODE = WHILE_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"function")){
        sym_Cour.CODE = FUNCTION_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"for")){
        sym_Cour.CODE = FOR_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"in")){
        sym_Cour.CODE = IN_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"break")){
        sym_Cour.CODE = BREAK_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"true")){
        sym_Cour.CODE = TRUE_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"false")){
        sym_Cour.CODE = FALSE_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"NULL")){
        sym_Cour.CODE = NULL_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"Inf")){
        sym_Cour.CODE = INF_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"NaN")){
        sym_Cour.CODE = NAN_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"NA")){
        sym_Cour.CODE = NA_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"NA_real")){
        sym_Cour.CODE = NA_REAL_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"NA_integer")){
        sym_Cour.CODE = NA_INTEGER_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"next")){
        sym_Cour.CODE = NEXT_TOKEN;
    }
    else if(strcmp(sym_Cour.NOM,"...")){
        sym_Cour.CODE = TREE_DOTS_TOKEN;
    }

    else{
        sym_Cour.CODE = ID_TOKEN;
    }*/
}
static void lire_separateur();
static void lire_erreur();
static void lireNombre();
static void lireComment();
static void lireCar();
static void lire_end_of_file ();
static void lire_nouvelle_ligne ();

