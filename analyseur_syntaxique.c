//
//

#include "analyseur_syntaxique.h"
#include "erreurs.h"
//Main := prog
static booleen MAIN(){
    //initialiser
    init_sym();
    initiliser_table_symobole();
    initialiser_pseudo_code();

    //lire 1er token
    sym_Suivant();
    booleen resultat = false;
    adresse_offset = 0;
    //trouver  la grammaire a executer
    if(prog()) resultat= true;
    ajouter_inst(LDA,get_premiere_procedure_adresse());//ajouter inst au pseudo code
    ajouter_inst(JSR,0);
    ajouter_inst(HLT, 0);
    //afficher table des symboles
    afficher_table_symboles();
    ecrire_pseudo_code_texte();
    return resultat;
}
//prog := newline | (expression_or_assign _newline) |(expression_or_assign _semicolon)
static booleen prog(){
    etat = PROCEDURE_NAME;
    int table_de_symboles_debut = table_de_symboles_size;
    if(newline()) return true;
    if(exp_or_assin()) return true;
    return false;
}

