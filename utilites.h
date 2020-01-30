//
// Created by imaane on 28/01/2020.
//

#ifndef COMPILATION_UTILITES_H
#define COMPILATION_UTILITES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LONGUEUR_MOT 250
#define NOMBRE_TOKENS 46

typedef enum _booleen {
    false, true
} booleen;

//listes des lexemes


typedef enum _TOKEN {
    NOTHING ,
    EOF_TOKEN ,
    NUM_TOKEN ,
    ERREUR_TOKEN ,
    ID_TOKEN ,
    IF_TOKEN ,
    ELSE_TOKEN  ,
    REPEAT_TOKEN,
    WHILE_TOKEN ,
    FUNCTION_TOKEN ,
    FOR_TOKEN ,
    IN_TOKEN,
    BREAK_TOKEN ,
    TRUE_TOKEN ,
    FALSE_TOKEN ,
    NULL_TOKEN ,
    INF_TOKEN ,
    NAN_TOKEN ,
    NA_TOKEN ,
    NA_REAL_TOKEN ,
    NA_INTEGER_TOKEN ,
    NEXT_TOKEN ,
    TREE_DOTS_TOKEN ,
    COMMENT_TOKEN ,
    PLUS_TOKEN ,
    MOINS_TOKEN,
    AP_TOKEN ,
    MUL_TOKEN ,
    V_TOKEN ,
    PO_TOKEN ,
    PF_TOKEN ,
    PT_TOKEN ,
    DIV_TOKEN ,
    PV_TOKEN ,
    OR_TOKEN,
    AND_TOKEN ,
    MODULO_TOKEN,
    DIV_EUC_TOKEN ,
    INFEG_TOKEN ,
    INFERIOR_TOKEN ,
    SUPEG_TOKEN ,
    SUP_TOKEN,
    EGAL_TOKEN ,
    AFF_TOKEN ,
    NOT_TOKEN ,
    DIFF_TOKEN ,
    SEPARATOR_TOKEN ,
    STRING_TOKEN ,
    POINT_TOKEN,



    /*  ABS_TOKEN = 1019,
      ALL_TOKEN= 1020,
      ANY_TOKEN =1021,
      APROPOS_TOKEN = 1022,
      ATTACH_TOKEN =1023,
      ATTR_TOKEN = 1024,
      ATTRIBUTES_TOKEN = 1025,
      AS_FACTORS8TOKEN =1026,
      AS_NUMERIC_TOKEN= 1027,
      BARPLOT_TOKEN = 1028,
      BOXPLOT_TOKEN= 1029,
      CASEFOLD_TOKEN = 1030,
      CBIND_TOKEN = 1031,
      CEILING_TOKEN = 1032,
      CHARMATCH_TOKEN = 1033,
      CHARTR_TOKEN = 1034,
      COLMEANS_TOKEN = 1035,
      COLNAMES_TOKEN = 1036,
      COLSUMS_TOKEN = 1037,
      COMPLETECASES_TOKEN = 1038,
      CUMSUM_TOKEN = 1039,
      DBETA_TOKEN = 1040,
      DBERN_TOKEN = 1041,
      DBINOM_TOKEN = 1042,
      DCAUCHY_TOKEN = 1043,
      DCHISQ_TOKEN = 1044,
      DENSITY_TOKEN = 1045,
      DEPARSE_TOKEN = 1046,
      DETACH_TOKEN = 1047,
      DEXP_TOKEN = 1048,
      DF_TOKEN= 1049,
      DGAMMA_TOKEN = 1050,
      DGEOM_TOKEN = 1051,
      DHYPER_TOKEN = 1052,
      DIFFTIME_TOKEN = 1054,
    DIM_TOKEN = 1055,
    DIR_TOKEN = 1056,
    DLNORM_TOKEN = 1057,
    DLOGIS_TOKEN = 1058,
    DNBINOM_TOKEN = 1059,
    DNORM_TOKEN = 1060,
    DOWNLOADFILE_TOKEN = 1061,
    DPOLS_TOKEN = 1062,
    DROPLEVELS_TOKEN = 1063,
    DSIGNRANK_TOKEN = 1064,
     */



}TOKEN;

struct _symbole {
    TOKEN code;
    char mot[LONGUEUR_MOT];
};

typedef enum _symbole_type {
    TVAR,
} symbole_type;

struct _symbole_stocke {


};

FILE* fichier;
char fichier_output_nom[30];
char fichier_interpreteur_input_nom[30];

char char_courrant;

int ligne_courrante;
struct _symbole symbole_courrant;


#endif //COMPILATION_UTILITES_H
