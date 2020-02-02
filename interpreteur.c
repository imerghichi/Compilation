
#include "interpreteur.h"

int pc = 1; //compteur de pile
booleen debug = false;

int main(int argc, char** argv) {
    strcpy(fichier_interpreteur_input_nom,"textinterp");
    if(argc>1) debug = true;

    initialiser_pseudo_code();
    initialiser_pile();
    lire_pseudo_code_texte();
    afficher_pseudo_code_texte();
    initialiser_pseudo_code();
    return 0;

}


void interpreter_pseuo_code(){
    pc = 1;
    booleen end = false;
    node_courrant = pseudo_code;
    float retenu;

    while (!end) {
        interpreter_node_courrant();

        switch (node_courrant->ligne.inst){
            case ADD:
                retenu = tete_pile();
                retenu += tete_pile();
                ajouter_element(retenu);
                pc++;
                break;

            case SUB:
                retenu = tete_pile();
                retenu = tete_pile() - retenu;
                ajouter_element(retenu);
                pc++;
                break;
            case MUL:
                retenu = tete_pile();
                retenu *= tete_pile();
                ajouter_element(retenu);
                pc++;
                break;
            case DIV:
                retenu = tete_pile();
                retenu = tete_pile() / retenu;
                ajouter_element(retenu);
                pc++;
                break;
            case  EQL: //egal
                retenu = tete_pile();
                if(retenu == tete_pile()) ajouter_element(1); //egalite
                else ajouter_element(0);
                pc++;
                break;
            case  NEQ: //not egal
                retenu = tete_pile();
                if(retenu == tete_pile()) ajouter_element(0); //egalite
                else ajouter_element(1);
                pc++;
                break;
            case  GTR:
                retenu = tete_pile();
                if(retenu < tete_pile()) ajouter_element(1);
                else ajouter_element(0);
                pc++;
                break;
            case LSS:
                retenu = tete_pile();
                if(retenu > tete_pile()) ajouter_element(1);
                else ajouter_element(0);
                pc++;
                break;
            case  GEQ:
                retenu = tete_pile();
                if(retenu <= tete_pile()) ajouter_element(1);
                else ajouter_element(0);
                pc++;
                break;
            case LEQ:
                retenu = tete_pile();
                if(retenu >= tete_pile()) ajouter_element(1);
                else ajouter_element(0);
                pc++;
                break;
            case PRF:
                printf("%f", tete_pile());
                pc++;
                break;
            case RDF:
                scanf("%f", &retenu);
                ajouter_element(retenu);
                pc++;
                break;
            case INT:
                retenu = node_courrant->ligne.parametre;
                for (int i =0; i< (int) retenu; i++) {
                    ajouter_element(0);
                }
                pc++;
                break;
            case  LDI:
                ajouter_element(node_courrant->ligne.parametre);
                pc++;
                break;
            case LDA: // chargement de l'adresse
                ajouter_element(node_courrant->ligne.parametre);
                pc++;
                break;
            case LDV: // chargement de la valeur
                ajouter_element(get_pile_element((int) tete_pile()));
                pc++;
                break;
            case  STO: // stockage de valeur dans adresse
                retenu=tete_pile();
                set_pile_element((int)tete_pile(), retenu);
                pc++;
                break;
            case  BRN:
                pc =(int)node_courrant->ligne.parametre;
                break;
            case  BZE: //branch si egal
                if (tete_pile() == 0) pc =(int)node_courrant->ligne.parametre;
                else pc++;
                break;
            case HLT: // end of the program
                end = true;
                break;
            case NOP: // no operation
                break;
            case  PRI:
                printf("%i",(int) tete_pile());
                pc++;
                break;
            case  PRC:
                printf("%c",(char) tete_pile());
                pc++;
                break;

            case  NEG: //negatif de nombre
                ajouter_element((-1)*tete_pile());
                pc++;
                break;
            case NBZ: // branch si different
                if (tete_pile() != 0) pc =(int)node_courrant->ligne.parametre;
                else pc++;
                break;
            case SPD: //skip instruct
                pc = (int) node_courrant->ligne.parametre;
                break;
            case RTS: // retourner a l adressse dans la pile
                pc =tete_pile();
                break;
            case JSR: // jump a sousroutine
                retenu =tete_pile();
                ajouter_element(pc+1);
                pc= (int) retenu;
                break;
            case FRE: //free nombre en pile
                for(int i=0; i< (int) node_courrant->ligne.parametre; i++) tete_pile();
                pc++;
                break;
            case DUP:
                retenu = tete_pile();
                ajouter_element(retenu);
                ajouter_element(retenu);
                pc++;
                break;
            default:
                end = true;
                break;
        }
        if (debug) afficher_pile();


    }
}
void interpreter_node_courrant(){
    while (pc != node_courrant->ligne.nombre_ligne){
        if(pc >node_courrant->ligne.nombre_ligne) node_courrant = node_courrant->suivant;
        else node_courrant = node_courrant->precedant;
    }
}