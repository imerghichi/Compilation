#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "utilites.h"
#include "analyseur_syntaxique.h"

int main(int argc, char** argv) {

    fichier = fopen(argv[1], "r");

    if(argc == 3) strcpy(argv[2], "output");

    fclose(fichier);
    printf("compilation termine avec succes");
    return 0;


}
