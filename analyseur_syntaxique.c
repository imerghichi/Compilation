//
//

#include "analyseur_syntaxique.h"

static booleen FUNCTION(){

}
static booleen FUNTION_CALL();
static booleen RETURN();

static booleen EXPRESSION();
static booleen RELATION(); //RELATION =  SIMPLE_EXPRESSION [ RELATION_OPERATOR SIMPLE_EXPRESSION ]
static booleen TERM();
static booleen FACTEUR();
static booleen PRIMARY();

static booleen ADDING(); //puls minus
static  booleen MULTIPLYING(); // multiplying //dividing// modulo
static booleen CONDITION();

static booleen OPERATION();


static booleen WHILE_LOOP();
static booleen FOR_LOOP();
//static booleen CASE();

static booleen SEQUENCE_OF_STATEMANT();
static booleen SIMPLE_STATEMENT();
static booleen STATEMENT();

static booleen AFFETATION();

static booleen IF();

static booleen IO();
static booleen WRITE();
static booleen READ();
static booleen EXIT();