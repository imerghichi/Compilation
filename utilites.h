//
// Created by taaha on 28/01/2020.
//

#ifndef COMPILATION_UTILITES_H
#define COMPILATION_UTILITES_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LONGUEUR_MOT 250

typedef enum _booleen {
    false, true
} booleen;

//listes des lexemes


typedef enum _TOKEN {
    NOTHING = -1,
    EOF_TOKEN = 996,
    NUM_TOKEN = 997,
    ERREUR_TOKEN = 998,
    ID_TOKEN = 999,
    IF_TOKEN = 1000,
    ELSE_TOKEN  =1001,
    REPEAT_TOKEN= 1002,
    WHILE_TOKEN = 1003,
    FUNCTION_TOKEN = 1004,
    FOR_TOKEN = 1005,
    IN_TOKEN= 1006,
    BREAK_TOKEN = 1007,
    TRUE_TOKEN = 1008,
    FALSE_TOKEN = 1009,
    NULL_TOKEN = 1010,
    INF_TOKEN = 1011,
    NAN_TOKEN = 1012,
    NA_TOKEN = 1013,
    NA_REAL_TOKEN = 1014,
    NA_INTEGER_TOKEN = 1015,
    NEXT_TOKEN = 1016,
    TREE_DOTS_TOKEN = 1017,
    COMMENT_TOKEN = 1018,
    PLUS_TOKEN = 1019,
    MOINS_TOKEN= 1020,
    AP_TOKEN = 1021,
    MUL_TOKEN = 1022,
    V_TOKEN = 1023,
    PO_TOKEN = 1024,
    PF_TOKEN = 1025,
    PT_TOKEN = 1026,
    DIV_TOKEN =1027,
    PV_TOKEN = 1028,
    OR_TOKEN=1029,
    AND_TOKEN = 1030,
    MODULO_TOKEN= 1031,
    DIV_EUC_TOKEN = 1032,
    INFEG_TOKEN = 1033,
    INFERIOR_TOKEN = 1034,
    SUPEG_TOKEN = 1035,
    SUP_TOKEN= 1036,
    EGAL_TOKEN =1037,
    AFF_TOKEN = 1038,
    NOT_TOKEN = 1039,
    DIFF_TOKEN = 1040,



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

int line_courrante;



#endif //COMPILATION_UTILITES_H
