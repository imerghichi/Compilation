

#ifndef COMPILATION_PILE_H
#define COMPILATION_PILE_H

#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 10


float *pile;
int pile_indexe;
int pile_indexe_max;

void initialiser_pile();
void ajouter_element(float element);
float  tete_pile();
void afficher_pile();
float get_pile_element(int i);
void set_pile_element(int i, float element);


#endif //COMPILATION_PILE_H
