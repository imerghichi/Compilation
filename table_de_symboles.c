//
// Created by taaha on 30/01/2020.
//

#include "table_de_symboles.h"
void initiliser_table_symobole(){
    table_de_symbole = 0;
    table_de_symboles_max_size = 20;
    adresse_courrante = 0;
    table_de_symbole= malloc (table_de_symboles_max_size * sizeof(struct _symbole_stocke));

}
booleen ajouter_symbole(symbole_type symboleType){
    if(symbole_existants() == -1){
        //y a plus de place
        if(table_de_symboles_size > table_de_symboles_max_size){
            changer_size();
        }
        strcpy(table_de_symbole[table_de_symboles_size].mot, symbole_courrant.mot);
        table_de_symbole[table_de_symboles_size].type = symboleType;
        table_de_symbole[table_de_symboles_size].est_constant = false;
        table_de_symbole[table_de_symboles_size].offset = adresse_offset;
        table_de_symbole[table_de_symboles_size].end = 0;
        if (symboleType == TVAR) table_de_symbole[table_de_symboles_size].adresse = adresse_offset + adresse_courrante++ ;
        table_de_symboles_size++;
        return true;
    } else return false;

}
int symbole_existants(){
    for(int i =0; i<table_de_symboles_size; i++){
        if(strcmp (table_de_symbole[i].mot, symbole_courrant.mot) == 0) return i;
    }
    return -1;

}
int symbole_existe(char *symbole){
    for(int i =0; i<table_de_symboles_size; i++){
        if(strcmp (table_de_symbole[i].mot, symbole) == 0) return i;
    }
    return -1;
}
void afficher_table_symboles(){
    printf("\n\n");
    printf("_____________________________________\n");
    printf("__________ Table de symboles ________\n");
    printf("_____________________________________\n");
    printf("  Symbole  | Tp |  ad | Of | Ct | ed \n");
    printf("------------------------------------\n");

    for(int i = 0; i < table_de_symboles_size; i++) {
        printf("%10s | %2i | %2i | %2i | %2i | %2i \n", table_de_symbole[i].mot, table_de_symbole[i].type, table_de_symbole[i].adresse, table_de_symbole[i].offset, table_de_symbole[i].est_constant, table_de_symbole[i].end);
    }
}
int getAdresse(){
    for(int i =0; i<table_de_symboles_size; i++){
        if(strcmp (table_de_symbole[i].mot, symbole_courrant.mot) == 0) return table_de_symbole[i].adresse;
    }
    return -1;

}
symbole_type get_type (){
    for(int i =0; i<table_de_symboles_size; i++){
        if(strcmp (table_de_symbole[i].mot, symbole_courrant.mot) == 0) return table_de_symbole[i].type;
    }
    return -1;


}
//pour dernier symbole
void setSymbole_type(symbole_type symboleType){
    table_de_symbole[table_de_symboles_size - 1].type = symboleType;
}
void setSymbole_const(){
    table_de_symbole[table_de_symboles_size -1].est_constant = true;
}

void setSymbole_adresse(int adresse){
    table_de_symbole[table_de_symboles_size -1].adresse = adresse;
}
void setSymbole_start(int start){
    table_de_symbole[table_de_symboles_size -1].start = start;

}
void setSymbole_end(int end){
    table_de_symbole[table_de_symboles_size -1].end = end;

}

int symbole_table_free(int start);

booleen est_symbole_courrant_constant();
symbole_type getSymbole_courrant_type();
int getSymbole_adresse();

int getSymbole_end();
int getSymbole_start();

static void changer_size(){
    table_de_symboles_max_size += 20;
    table_de_symbole = realloc(table_de_symbole, table_de_symboles_max_size * sizeof(struct _symbole_stocke));
}
