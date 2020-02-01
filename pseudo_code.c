//
//

#include "pseudo_code.h"

int pseudo_code_ligne_courrante(){
    return nombre_ligne;
}
void initialiser_pseudo_code(){
    nombre_ligne = 0;
    pseudo_code = NULL;
    pseudo_code_courrant =NULL;

    pseudo_code = (node*)malloc(sizeof(node));
    pseudo_code->ligne.nombre_ligne = nombre_ligne++;
    pseudo_code->ligne.inst = NOP;
    pseudo_code->ligne.parametre = 0;
    pseudo_code->precedant = NULL;
    pseudo_code->suivant = NULL;

    pseudo_code_courrant = pseudo_code;

}
void ajouter_inst(pseudo_code_inst inst, float parametre){
    //creer inst suivant
    pseudo_code_courrant->suivant=(node*) malloc(sizeof(node));
    pseudo_code_courrant->suivant->precedant =pseudo_code_courrant;
    pseudo_code_courrant = pseudo_code_courrant->suivant;

    pseudo_code_courrant->ligne.nombre_ligne = nombre_ligne++;
    pseudo_code_courrant->ligne.parametre = parametre;
    pseudo_code_courrant->ligne.inst = inst;
}
void ecrire_pseud_code(){
    node *node1 = pseudo_code;

    FILE *file = fopen(fichier_output_nom,"w");

    pseudo_code_ligne *ligne;
    ligne = malloc (sizeof(pseudo_code_ligne));
    while (node1 ! = NULL){
        ligne = &(node1->ligne);
        fwrite(ligne, sizeof(pseudo_code_inst),1,file);
        node1 = node1->suivant;
    }
    fclose(file);
}
void ecrire_pseudo_code_texte(){
    node *node1 = pseudo_code->suivant;

    FILE *file = fopen(fichier_output_nom,"w");

    pseudo_code_ligne *ligne;
    ligne = malloc (sizeof(pseudo_code_ligne));
    while (node1 ! = NULL){
        ligne = &(node1->ligne);
        fprintf(file, "%i %i %f \n", ligne->nombre_ligne, ligne->inst, ligne->parametre);
        node1 = node1->suivant;
    }
    fclose(file);
}
void lire_pseudo_code_texte(){
    node *node1 = pseudo_code;

    FILE *file = fopen(fichier_output_nom,"r");

    pseudo_code_ligne *ligne;
    ligne = malloc (sizeof(pseudo_code_ligne));
    while (fscanf(file,"%i %i %f \n",&(ligne->nombre_ligne),&(ligne->inst), &(ligne->parametre)) != EOF){
       ajouter_inst(ligne->inst,ligne->parametre);
    }
    fclose(file);
}
void afficher_pseudo_code(){
    printf("\n_______________PSEUDO CODE______________\n\n");

    node *node1 = pseudo_code;
    while (node1 != NULL){
        printf("Istruction : %2d\t%d\t%f \n", node1->ligne.nombre_ligne, node1->ligne.inst, node1->ligne.parametre);
        node1 = node1->suivant;
    }
    printf("\n_______________PSEUDO CODE______________\n\n");

}
void afficher_pseudo_code_texte(){
    printf("\n_______________PSEUDO CODE______________\n\n");

    node *node1 = pseudo_code;
    while (node1 != NULL){
        printf("Istruction : %2d\t%s\t%f \n", node1->ligne.nombre_ligne,inst_table[node1->ligne.inst], node1->ligne.parametre);
        node1 = node1->suivant;
    }
    printf("\n_______________PSEUDO CODE______________\n\n");
}

void bze_pseudo_code_fixer(){
    booleen fixe = false;
    node *node1 = pseudo_code_courrant;

    //chercher bze agument
    while (node1 != NULL &&  !fixe){
        if (node1->ligne.inst == BZE && node1->ligne.parametre == -1){
            node1->ligne.parametre = nombre_ligne;
            fixe = true;
        }
        node1 = node1->precedant;
    }
}
void nbz_pseudo_code_fixer(){
    booleen fixe = false;
    node *node1 = pseudo_code_courrant;

    while (node1 != NULL &&  !fixe){
        if (node1->ligne.inst == NBZ && node1->ligne.parametre == -1){
            node1->ligne.parametre = nombre_ligne;
            fixe = true;
        }
        node1 = node1->precedant;
    }
}
void brn_pseudo_code_fixer(){
    booleen fixe = false;
    node *node1 = pseudo_code_courrant;

    while (node1 != NULL &&  !fixe){
        if (node1->ligne.inst == BRN && node1->ligne.parametre == -1){
            node1->ligne.parametre = nombre_ligne;
            fixe = true;
        }
        node1 = node1->precedant;
    }
}
void spd_pseudo_code_fixer(){
    booleen fixe = false;
    node *node1 = pseudo_code_courrant;

    while (node1 != NULL &&  !fixe){
        if (node1->ligne.inst == SPD && node1->ligne.parametre == -1){
            node1->ligne.parametre = nombre_ligne;
            fixe = true;
        }
        node1 = node1->precedant;

    }
}
