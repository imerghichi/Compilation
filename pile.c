#include "pile.h"


void initialiser_pile(){
    pile_indexe = 0;
    pile_indexe_max = INITIAL_SIZE - 1;

    pile = malloc ((pile_indexe_max + 1) * sizeof(float));
}
void ajouter_element(float element){
    if(pile_indexe == pile_indexe_max){
        pile_indexe_max += 10;
        pile = realloc(pile,(pile_indexe_max + 1) * sizeof(float));
    }
    pile[pile_indexe++] = element;
}
float  tete_pile(){
    return pile[--pile_indexe];
}
void afficher_pile(){
    printf("_________Contenu de la pile______");
    for (int i = 0;i < pile_indexe; i++){
        printf(" - %f \t", pile[i]);
    }
    printf("\n\n");
}
float get_pile_element(int i){
    return pile[i];
}
void set_pile_element(int i, float element){
    pile[i] = element;
}