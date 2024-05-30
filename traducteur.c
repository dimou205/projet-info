#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "lexer.h" // import the functions from lexer.c

void traducteur(FILE* fichier, FILE* sortie) {
    maillon* chaine = lexeur(fichier);

    while (chaine != NULL) {

        if (chaine->lexeme == 'V') {
            fprintf(sortie, "!%s ", chaine->argument);
            chaine = chaine->suivant;
        } else if (chaine->lexeme == 'T') {
            if (chaine->suivant->suivant->suivant->suivant->lexeme == 'E') {
                fprintf(sortie, "let %s = ref ", chaine->suivant->suivant->argument);
                chaine = chaine->suivant->suivant->suivant->suivant->suivant->suivant;
            }
            /* else{
                étape 5
            } */
        } else if (chaine->lexeme == 'O') {
            fprintf(sortie, "%c ", chaine->lexeme);
            chaine = chaine->suivant;
        } else if (chaine->lexeme == 'B') {
            if (chaine->suivant->lexeme == 'B') {
                fprintf(sortie, "%s ", chaine->argument);
                chaine = chaine->suivant;
            } else if (strcmp(chaine->argument, "=") == 0 && strcmp(chaine->suivant->argument, "=") == 0) {
                fprintf(sortie, "= ");
                chaine = chaine->suivant->suivant;
            } else if (strcmp(chaine->argument, "!") == 0 && strcmp(chaine->suivant->argument, "=") == 0) {
                fprintf(sortie, "<> ");
                chaine = chaine->suivant->suivant;
            } else {
                fprintf(sortie, "%s%s ", chaine->argument, chaine->suivant->argument);
                chaine = chaine->suivant->suivant;
            }
        } else if (chaine->lexeme == 'C') {
            fprintf(sortie, "(* %s *) ", chaine->argument);
            chaine = chaine->suivant;
        } else {
            chaine = chaine->suivant;
        }
    }
}


int main() {
    FILE *fichier = fopen("test.txt", "r");
    if (!fichier) {
        perror("erreur lors de l'ouverture du fichier d'entrée");
        return 1;
    }

    FILE *sortie = fopen("code.ml", "w");
    if (!sortie) {
        perror("erreur lors de l'ouverture du fichier de sortie");
        fclose(fichier);
        return 1;
    }

    traducteur(fichier, sortie);

    fclose(fichier);
    fclose(sortie);

    return 0;
}

    
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*if(chaine->argument == "int"){ 
            fputs("let",d.ml);
            fputc(' ',d.ml);
            fputs(chaine->suivant->suivant->argument,d.ml); // nom var
            fputc(' ',d.ml);
            fputs(chaine->suivant->suivant->suivant->suivant->argument,d.ml); // =
            fputs(" ref ",d.ml);
            chaine = chaine->suivant->suivant->suivant->suivant->suivant->suivant;
            while(chaine->suivant->argument != ";"){
                if(chaine->lexeme == 'V'){
                    fputc(("!%s",chaine->argument), d.ml);
                    chaine = chaine->suivant;
                }
                else if(chaine->argument == '=' && chaine->suivant->argument == '='){
                    fputc('=',d.ml);
                    chaine = chaine->suivant;
                }
                else if(chaine->argument == '!' && chaine->suivant->argument == '='){
                    fputs("<>",d.ml);
                    chaine = chaine->suivant;
                }
                else{
                    fputc(("%s",chaine->argument),d.ml);
                    chaine = chaine->suivant;
                }
            }
            if(chaine->suivant->suivant->suivant->suivant->suivant->suivant->suivant->argument == ';' && chaine->suivant->suivant->suivant->suivant->suivant->suivant->suivant->suivant->argument != ';'){
                fputs(" in\n",d.ml);
            };
            chaine = chaine->suivant;
            }
        if(chaine->argument == "bool"){
            fputs("let",d.ml);
            fputc(' ',d.ml);
            fputs(chaine->suivant->suivant->argument,d.ml); // nom var
            fputc(' ',d.ml);
            fputs(chaine->suivant->suivant->suivant->suivant->argument,d.ml); // =
            fputs(" ref ",d.ml);
            fputs(chaine->suivant->suivant->suivant->suivant->suivant->suivant->argument,d.ml); // valeur 
            if(chaine->suivant->suivant->suivant->suivant->suivant->suivant->suivant->argument == ';' && chaine->suivant->suivant->suivant->suivant->suivant->suivant->suivant->suivant->argument != ';'){
                fputs(" in\n",d.ml);
            };
            chaine = chaine->suivant;
            }
        else{
            chaine = chaine->suivant;
        }*/

