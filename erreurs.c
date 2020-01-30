//
// Created by imaane on 30/01/2020.
//

#include "erreurs.h"

char* erreurs[ERREUR_NOMBRE] ={
        "caractere inconnu",
        "single quote est manquante",
};

void raise_erreur(erreurs_codes erreursCodes){
    if(erreursCodes >= ERREUR_NOMBRE)
        printf("Erreur nombre %i : erreur en ligne %i \n", erreursCodes, ligne_courrante);
    else
        printf("Erreur: %s , en ligne %i \n", erreursCodes, erreurs[erreursCodes]);
}