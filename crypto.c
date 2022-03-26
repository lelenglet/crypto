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

int indice_in_alpha(char alphabet [], char carac ){
    int indice=0;
    while (alphabet[indice]!=carac){
        indice++;
    }
    return indice;
    //fonction permettant de trouver l'indice du carac dans l'alaphabet
    //retourne indice
}

char Chiffrement(char text[], char clef[], char alphabet[],int longueur_text){
    int i ;
    int indice;
    char sortie [longueur_text+1];
    for (i=0;i<longueur_text;i++){
        indice=indice_in_alpha(alphabet,text[i]);
        sortie[i]=clef[indice];
    }
    printf("%s",sortie);
    return * sortie;
    // on parcourt le texte avec une boucle for avec i allant de 0 a longueur_text-1
    // on prends le carac et et on le remplace avec la clef de chiffrement
    // on retourne le message chiffré
}

char Dechiffrement(char text[], char clef[], char alphabet[],int longueur_text){
    int i ;
    int indice;
    char sortie [longueur_text+1];
    for (i=0;i<longueur_text;i++){
        indice=indice_in_alpha(clef,text[i]);
        sortie[i]=alphabet[indice];
    }
    printf("%s",sortie);
    return * sortie;
}


char Changement_carac(char carac ,char alphabet[]){
    char sortie=' ';
    if ((carac<'a' || carac>'z')&& (carac<'A' ||carac>'Z') && carac!=' '){
        sortie=' ';
    }
    return sortie;
}

char *  Nettoyage(char text[], char alphabet[],int longueur_text){
    int i ;
    for (i=0;i<longueur_text;i++){
        text[i]=Changement_carac(text[i],alphabet);
    }
    return text;
}


int main(){
    srand(time(NULL));
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ "); //alphabet de départ
    char permutation[N];
    strcpy(permutation,alphabet);// alphabet qui sera permuté
    PermutationTableau(permutation,N);
    printf("%s\n%s",permutation,alphabet);
    char text [101];
    char * sortie [101];
    scanf("%s",text);
    strcpy(sortie,Chiffrement(text,permutation,alphabet,101));

return 0;
}
