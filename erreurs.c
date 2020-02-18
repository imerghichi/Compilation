//
// Created by imaane on 30/01/2020.
//

#include "erreurs.h"

char* erreurs[ERREUR_NOMBRE] ={
        "caractere inconnu",
        "single quote est manquante",
        "caractere exige",
        "simple quote symbol exige",
        "B ouvrante erreur",
        "affectation erreur",
        "manque parethese ouverte",
        "manque parenthese fermee",
        "erreur des guillemets",
        "B fermante erreur",
        "erreue en boucle for",
        "erreur en else",
        "erreur en boucle while",
        "erreur en condition",
        "erreur en lecture",
        "erreur en ecriture",
        "erreur en addition",



};

void raise_erreur(erreurs_codes erreursCodes){
    if(erreursCodes >= ERREUR_NOMBRE) {
        printf("Erreur nombre %i : erreur en ligne %i \n", erreursCodes, ligne_courrante);
    }else {
        printf("Erreur: %i , en ligne %i \n", erreursCodes, erreurs[erreursCodes]);
    }
}