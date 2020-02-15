//
//

#ifndef COMPILATION_TABLE_DE_SYMBOLES_H
#define COMPILATION_TABLE_DE_SYMBOLES_H

#include "utilites.h"
;void initiliser_table_symobole();
booleen ajouter_symbole(symbole_type symboleType);
int symbole_existants();
int symbole_existe(char *symbole);
void afficher_table_symboles();
int getAdresse(); //du symbole courrant
symbole_type get_type ();
//pour dernier symbole
void setSymbole_type(symbole_type symboleType);
void setSymbole_const();
void setSymbole_adresse(int adresse);
void setSymbole_start(int start);
void setSymbole_end(int end);

int symbole_table_free(int start);

int get_premiere_procedure_adresse();
booleen est_symbole_courrant_constant();
symbole_type getSymbole_courrant_type();
int getSymbole_adresse();

int getSymbole_end();
int getSymbole_start();

static void changer_size();

#endif //COMPILATION_TABLE_DE_SYMBOLES_H
