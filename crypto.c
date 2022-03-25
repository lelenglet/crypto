#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 28

void PermutationTableau(char alpha[],int longueur){
    int i ; // compteur
    int random;
    char temp;
    for (i=longueur-2; i>1; i--){ // longueur-2 pour exclure la dernière case contenant '/0' de la permutation
        random = rand () % i;
        temp= alpha[i];
        alpha[i]=alpha[random];
        alpha[random]=temp;
    }
    // algo de fisher yates
    //
    // arguments possibles : alphabet non permuté :type char
    //                       longueur de la chaine : type int
    //
    // boucle for i | n-1 -> 1{
    //j = entier aléatoire entre 0 et i
    // permutation valeur place j et i
}

int indice_in_cle(char clef [], char carac ){
    //fonction permettant de trouver l'indice du carac dans la clef
    //retourne indice
}

char Chiffrement(char text[], char clef[],int longueur_text, int longueur_clef){
    // on parcourt le texte avec une boucle for avec i allant de 0 a longueur_text-1
    // on prends le carac et et on le remplace avec la clef de chiffrement
    // on retourne le message chiffré
}


int main(){
    srand(time(NULL));
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ "); //alphabet de départ
    char permutation[N];
    strcpy(permutation,alphabet);// alphabet qui sera permuté
    PermutationTableau(permutation,N);
    printf("%s\n%s",permutation,alphabet);
return 0;
}
