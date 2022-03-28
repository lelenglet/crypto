#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 28

char* copieur(const char *originale)
{

    char *copie=NULL;

    copie=malloc((strlen(originale))*sizeof(char));
    strcpy(copie,originale);

    return copie; // on retourne le pointeur vers la copie de la chaine de caractere
}




void Permutation(char sortie[]){
    int i ; // compteur
    int random;
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    strcpy(sortie,alphabet);//alphabet de départ
    char temp;

    for (i=strlen(sortie)-2; i>1; i--){ // longueur-2 pour exclure la dernière case contenant '/0' de la permutation
        random = rand () % i;
        temp= sortie[i];
        sortie[i]=sortie[random];
        sortie[random]=temp;
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



int indice_in_alpha(char carac){
    int indice=0;
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    while (alphabet[indice]!=carac){
        indice++;
    }
    return indice;
    //fonction permettant de trouver l'indice du carac dans l'alaphabet
    //retourne indice
}


void Chiffrement(char sortie[], char text[], char clef[]){
    int i =0;
    int indice;
    while (text[i]!='\0'){
        indice=indice_in_alpha(text[i]);
        sortie[i]=clef[indice];
        i++;
    }
    // on parcourt le texte avec une boucle for avec i allant de 0 a longueur_text-1
    // on prends le carac et et on le remplace avec la clef de chiffrement
    // on retourne le message chiffré
}


int indice_in_clef(char clef[],char carac){
    int indice=0;
    while (clef[indice]!=carac){
        indice++;
    }
    return indice;
    //fonction permettant de trouver l'indice du carac dans l'alaphabet
    //retourne indice
}

void Dechiffrement(char sortie[], char text[], char clef[]){
    int i =0;
    int indice;
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ ");

    while (text[i]!='\0'){
        indice=indice_in_clef(clef,text[i]);
        sortie[i]=alphabet[indice];
        i++;
    }
}




char Changement_carac(char carac){
    char sortie=' ';
    if ((carac<'a' || carac>'z')&& (carac<'A' ||carac>'Z') && carac!=' '){
        if (carac==':' || carac=='!' || carac=='?' || carac==',' || carac=='.' || carac=='\''){
            sortie=' ';
        }}
    else {
        if(carac>='a' && carac<='z'){
            sortie=carac+('A'-'a');
        }
        else {
            sortie=carac;
        }
    }
    return sortie;
}

void  Nettoyage(char sortie[],char text[]){
    int i=0 ;
    while (text[i]!='\0'){
        sortie[i]=Changement_carac(text[i]);
        i++;
    }
}


int main(){
    srand(time(NULL));
    char permutation[N];
    Permutation(permutation);
    printf("%s\n",permutation);


    char text[]="BONJOURààà";
    printf("%s\n",text);
        char sortie[strlen(text)];
        Nettoyage(sortie,text);
        printf("%s\n",sortie);
/*
    Chiffrement(sortie,text,permutation);
    printf("%s\n",sortie);

    char sortie2[strlen(text)];
    Dechiffrement(sortie2,sortie,permutation);
    printf("%s\n",sortie2);*/

return 0;
}



/*
**
int main(int argc, char *argv[])
{

    char chaine[] = "Texte";
    char* copie=NULL;

    copie = copieur(chaine);


    printf("chaine vaut : %s\n", chaine);
    printf("copie vaut : %s\n", copie);
     free(copie);
 
    return 0;

}

char* copieur(const char *originale)
{

     char *copie=NULL;

    copie=malloc((strlen(originale)+1)*sizeof(char));
    strcpy(copie,originale);

   return copie;
}
**
**
*/
