//
//

#include "analyseur_syntaxique.h"
#include "erreurs.h"

static booleen INST(){
    switch (symbole_courrant.code){
        case IF_TOKEN:
            IF();
            return true;
        case ELSE_TOKEN:
            ELSE();
            return true;
        case WHILE_TOKEN:
            WHILE();
            return true;
        case FOR_TOKEN:
            FOR();
            return true;
        case PRINT_TOKEN:
            WRITE();
            return true;
        case READ_TOKEN:
            READ();
            return true;
        case CAT_TOKEN:
            WRITE();
            return true;
        case ID_TOKEN:
            sym_Suivant();
            AFTERID();
            return true;
    }
}
static booleen INSTS(){
    switch (symbole_courrant.code) {
        case PV_TOKEN:
            Sym_Suiv();
            INST();
            INSTF();
            return true;
        case RL_TOKEN:
            Sym_Suiv();
            INST();
            INSTF();
            return true;
        default:
            INST();
            return true;
    }
}
static booleen INSTF(){
    switch (symbole_courrant.code) {
        case BO_TOKEN:
            INSTS();
            if(symbole_courrant.code != BF_TOKEN) raise_erreur(BO_ERROR);
            return true;
        case RL_TOKEN:
            INSTS();
            sym_Suivant();
            return true;
        case PV_TOKEN:
            INSTS();
            return true;
        default:
            return false;
    }
}
static booleen SEP(){
    switch (symbole_courrant.code){
        case SEPARATOR_TOKEN:
            return true;
        default:
            return false;
    }
}
static booleen IF(){
    switch (symbole_courrant.code) {
        case IF_TOKEN:
            sym_Suivant();
            if (symbole_courrant.code != PO_TOKEN) {raise_erreur(PO_ERROR);
                return false;
            }
            CONDS();
            if (symbole_courrant.code != PF_TOKEN) {raise_erreur(PF_ERROR);
            return false;}
            if (symbole_courrant.code != BO_TOKEN) {raise_erreur(BO_ERROR);
                return false;}
            INSTS();
            if(symbole_courrant.code != BF_TOKEN) {
                raise_erreur(BF_ERROR);
                return false;
            }
            if(symbole_courrant.code==ELSE_TOKEN){
                INSTS();
            }
            return true;
        default:
            raise_erreur(IF_ERROR);
            return false;
    }
}
static booleen ELSE(){
    switch (symbole_courrant.code) {
        case ELSE_TOKEN:
            sym_Suivant();
            ELSEIF();
            return true;
        default:
            raise_erreur(ELSE_ERROR);
            return false;
    }
}
static booleen AFFECTATION(){
    if (symbole_courrant.code != AFF_TOKEN){ raise_erreur(AFF_ERROR);
    return false;}
    else AFFECT();
    return true;
}
static booleen WHILE(){
    switch (symbole_courrant.code) {
        case WHILE_TOKEN:
            sym_Suivant();
            if (symbole_courrant.code != PO_TOKEN) {raise_erreur(PO_ERROR);
                return false;
            }
            CONDS();

            if (symbole_courrant.code != PF_TOKEN) {raise_erreur(PF_ERROR);
                return false;}
            if (symbole_courrant.code != BO_TOKEN) {raise_erreur(BO_ERROR);
                return false;}
            INSTS();
            if(symbole_courrant.code != BF_TOKEN) {
                raise_erreur(BF_ERROR);
                return false;
            }
            return true;
        default:
            raise_erreur(WHILE_ERROR);
            return false;
    }
}
static booleen FOR(){
    switch (symbole_courrant.code) {
        case FOR_TOKEN:
            sym_Suivant();
            if(symbole_courrant.code != PO_TOKEN){
                raise_erreur(PO_ERROR);
                return false;
            }
            FOR_LOOP();
            if(symbole_courrant.code != PF_TOKEN){
                raise_erreur(PF_TOKEN);
                return false;
            }
            if(symbole_courrant.code != BO_TOKEN){
                raise_erreur(BO_TOKEN);
                return false;
            }
            INSTS();
            if(symbole_courrant.code != BF_TOKEN){
                raise_erreur(BF_TOKEN);
                return false;
            }
            return true;
        default:
            printf("FOR");
            return false;
    }
}
static booleen WRITE(){
    switch (symbole_courrant.code) {
        case CAT_TOKEN:
            sym_Suivant();
            if (symbole_courrant.code != PO_TOKEN) {raise_erreur(PO_ERROR);
                return false;
            }
            STRING();

            if (symbole_courrant.code != PF_TOKEN) {raise_erreur(PF_ERROR);
                return false;}
            return true;
        case PRINT_TOKEN:
            if (symbole_courrant.code != PO_TOKEN) {raise_erreur(PO_ERROR);
                return false;
            }
            STRING();

            if (symbole_courrant.code != PF_TOKEN) {raise_erreur(PF_ERROR);
                return false;}
            return true;
        default:
            raise_erreur(WRITE_ERROR);
            return false;
    }
}
static booleen AFTERID(){
    switch (symbole_courrant.code) {
        case READ_TOKEN:
            READ();
            return true;
        case AFF_TOKEN:
            AFFECTATION();
            return true;
        case EGAL_TOKEN:
            symbole_courrant();
            AFTERID();
            return true;
        default:
            return false;
    }
}
static booleen READ(){
    switch (symbole_courrant.code) {
        case EGAL_TOKEN:
            sym_Suivant();
            if(symbole_courrant.code==READ_TOKEN){
                sym_Suivant();
                if (symbole_courrant.code != PO_TOKEN) {raise_erreur(PO_ERROR);
                    return false;
                }
                TOREAD();

                if (symbole_courrant.code != PF_TOKEN) {raise_erreur(PF_ERROR);
                    return false;}
            return true;
            }
        default:
            return false;
    }
}
static booleen AFFECT(){
    switch (symbole_courrant.code) {
        case FUNCTION_TOKEN:
            sym_Suivant();
            if (symbole_courrant.code != PO_TOKEN) raise_erreur(PO_ERROR);
            ARGUMENTS();
            if (symbole_courrant.code != PF_TOKEN) raise_erreur(PF_ERROR);
            return true;
        case DOUBLE_QUOTE_TOKEN:
            if (symbole_courrant.code != DOUBLE_QUOTE_TOKEN) raise_erreur(DOUBLE_QUOTE_ERROR);
            EXPR();
            if (symbole_courrant.code != DOUBLE_QUOTE_TOKEN) raise_erreur(DOUBLE_QUOTE_ERROR);
            return true;
        default:
            Sym_Suiv();
            EXPR();
            return true;
    }
}
static booleen EXPR(){

    TERM();
    EXPRF();
}
static booleen EXPRF(){
    switch (symbole_courrant.code) {
        case PLUS_TOKEN:
            sym_Suivant();
            EXPR();
            return true;
        case MINUS_TOKEN:
            sym_Suivant();
            EXPR();
            return true;
        default:
            return false;

}
}
static booleen ARGUMENTS(){
    ARGUMENT();
}
static booleen ARGUMENT(){
    STRING();
}
static booleen ADD_OP(){
    switch (symbole_courrant.code){
        case PLUS_TOKEN:
            sym_Suivant();
            EXPR();
            return true;

        case PLUS_TOKEN:
            sym_Suivant();
            EXPR();
            return true;
        default:
            raise_erreur(ADD_ERROR);
            return false;

    }
}
static booleen CONDITION(){
    switch (symbole_courrant.code) {
        case AND_TOKEN:
            sym_Suivant();
            CONDS();
            return true;
        case OR_TOKEN:
            sym_Suivant();
            CONDS();
            return true;
        default:
            raise_erreur(COND_ERROR);
            return false;
    }
}
static booleen ELSEIF(){
    switch (symbole_courrant.code) {
        case BO_TOKEN:
            sym_Suivant();
            INSTS();
            if(symbole_courrant.code != BF_TOKEN) {raise_erreur(BF_TOKEN);
                return false;}
            return true;
        case IF_TOKEN:
            sym_Suivant();
            IF ();
        default:
            printf("eELSEIF\n");
            return false;
    }
}
static booleen FOR_LOOP(){
    switch (symbole_courrant.code) {
        case ID_TOKEN:
            sym_Suivant();
            if(symbole_courrant.code==IN_TOKEN){
                sym_Suivant();
                FOR_LOOPF();
            }
        default:
            printf("BOUCLEFOR\n");
            return false;
    }
}
static booleen STRING(){
    switch (symbole_courrant.code) {
        case DOUBLE_QUOTE_TOKEN:
            sym_Suivant();
            EXPR();
            if(symbole_courrant.code != DOUBLE_QUOTE_TOKEN){
                raise_erreur(DOUBLE_QUOTE_ERROR);
                return false;
            }
            STRINGF();
            return true;
        case ID_TOKEN:
            sym_Suivant();
            STRINGF();
            return true;
        case NUM_TOKEN:
            sym_Suivant();
            STRINGF();
            return true;
        default:printf("STRING\n");
            return false;
    }
}
static booleen COND(){
    EXPR();
    REL_OP();
    EXPR();
}
static booleen TOREAD(){
    switch (symbole_courrant.code) {
        case PROMPT_TOKEN:
            sym_Suivant();
            if(sym.CODE==EG_TOKEN){
                symbole_courrant();
                if(symbole_courrant.code==DOUBLE_QUOTE_TOKEN){
                    Sym_Suiv();
                    EXPR();
                    if(symbole_courrant.code != DOUBLE_QUOTE_TOKEN){
                        raise_erreur(DOUBLE_QUOTE_ERROR);
                        return false;
                    }
                }
            }
            return true;
        case DOUBLE_QUOTE_TOKEN:
            sym_Suivant();
            EXPR();
            if(symbole_courrant.code != DOUBLE_QUOTE_TOKEN){
                raise_erreur(DOUBLE_QUOTE_ERROR);
                return false;
            }
            return true;
        default:
            raise_erreur(TOREAD_ERROR);
            return false;
    }
}
static booleen CONDS(){
    COND();
    CONDITION();
}
static booleen REL_OP(){
    switch (symbole_courrant.code) {
        case EGAL_TOKEN:
            sym_Suivant();
            return true;
        case NOT_EGAL_TOKEN:
            sym_Suivant();
            return true;
        case SUP_TOKEN:
            sym_Suivant();
            return true;
        case INF_TOKEN:
            sym_Suivant();
            return true;
        case SUPEG_TOKEN:
            sym_Suivant();
            return true;
        case INFEG_TOKEN:
            sym_Suivant();
            return true;
        default:
            return false;
}
}
static booleen TERM(){
    FACT();
    TERMF();
}
static booleen TERMF(){
    switch (sym.CODE) {
        case MULT_TOKEN:
            sym_Suivant();
            TERM();
            return true;
        case DIV_TOKEN:
            sym_Suivant();
            TERM();
            return true;
        default:
            return false;
    }
}
static booleen FACT(){
    switch (symbole_courrant.code) {
        case ID_TOKEN:
            sym_Suivant();
            FACT();
            return true;
        case NUM_TOKEN:
            sym_Suivant();
            FACT();
            return true;
        case PO_TOKEN:
            sym_Suivant();
            EXPR();
            if(symbole_courrant.code != PF_TOKEN){
                raise_erreur(PF_TOKEN);
                return false;
            }
            return true;
        default:
            return false;
    }
}
static booleen MULTI_OP(){
    switch (symbole_courrant.code){
        case MUL_TOKEN:
            sym_Suivant();
            return true;
        case DIV_TOKEN:
            sym_Suivant();
            return true;
        default:
            raise_erreur(MUL_ERROR);
            return false;

    }
}
static booleen STRINGF(){
    switch (symbole_courrant.code) {
        case VI_TOKEN:
            sym_Suivant();
            STRING();
            return true;
        default:
            return false;
    }
}
static booleen FOR_LOOPF(){
    switch (symbole_courrant.code) {
        case ID_TOKEN:
            sym_Suivant();
            return true;
        case NUM_TOKEN:
            sym_Suivant();
            if(symbole_courrant.code == DOUBLE_POINT_TOKEN){
                sym_Suivant();
                if(symbole_courrant.code==NUM_TOKEN){
                    symbole_courrant();
                    return true;
                }
                else {
                    raise_erreur(FOR_LOOP_ERROR);
                }
            }
        default:
            raise_erreur(FOR_LOOP_ERROR);
            return false;
    }
}
