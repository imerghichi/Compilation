
#include "interpreteur.h"

int pc = 1;
booleen debug = false;

int main(int argc, char** argv) {


}


void interpreter_pseuo_code(){}
void interpreter_node_courrant(){
    while (pc != node_courrant->ligne.nombre_ligne){
        if(pc >node_courrant->ligne.nombre_ligne) node_courrant = node_courrant->suivant;
        else node_courrant = node_courrant->precedant;
    }
}