all: compilateur

compilateur: compilateur.o analyseur_lexical.o global.o analyseur_syntaxique.o table_de_symboles.o pseudo_code.o
	gcc -o compilateur compilateur.o analyseur_lexical.o analyseur_syntaxique.o erreurs.o table_de_symboles.o pseudo_code.o -g

compilateur.o: compilateur.c analyseur_syntaxique.h global.h analyseur_syntaxique.h table_de_symboles.h pseudo_code.h
	gcc -o compilateur.o -c compilateur.c -g

analyseur_syntaxique.o: analyseur_syntaxique.c analyseur_syntaxique.h analyseur_lexical.h utilites.h erreurs.h table_de_symboles.h
	gcc -std=gnu99 -o analyseur_syntaxique.o -c analyseur_syntaxique.c -g

pseudo_code.o: pseudo_code.h pseudo_code.c utilites.h
	gcc -o pseudo_code.o -c pseudo_code.c -g

table_de_symboles.o: table_de_symboles.c table_de_symboles.h utilites.h
	gcc -std=c99  -o table_de_symboles.o -c table_de_symboles.c -g

analyseur_lexical.o: analyseur_lexical.c utilites.h erreurs.h
	gcc -o analyseur_lexical.o -c analyseur_lexical.c -g

utilites.o: erreurs.c erreurs.h
	gcc -o erreurs.o -c erreurs.c -g

clean:
	rm -rf *.o *.c~ *.h~

bp: clean mrproper clean_output
	rm interpreteur

clean_output: output
	rm output

mrproper:
	rm compilateur

interpreteur: interpreteur.o pile.o pseudo_code.o
	gcc -o interpreteur interpreteur.o pile.o pseudo_code.o -g

interpreteur.o: interpreteur.c interpreteur.h pile.h
	gcc -std=c99 -o interpreteur.o -c interpreteur.c -g

pile.o: pile.c pile.h
	gcc -std=c99 -o pile.o -c pile.c -g

