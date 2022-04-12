#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 28 // longueur pour l'alphabet

////////// FONCTION 1 : PERMUTATION ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void Permutation(char sortie[]){
    int i ; // compteur
    int random;
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    strcpy(sortie,alphabet);//alphabet de départ copié dans la sortie
    char temp;

    for (i=strlen(sortie)-1; i>1; i--){ // longueur-2 pour exclure la dernière case contenant '/0' de la permutation
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



//////////// FONCTION 2 : CHIFFREMENT //////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    sortie[i]='\0';
    // on parcourt le texte avec une boucle tant que text[i]!='\0'
    // on prends le caractère et on le remplace avec le caractère associé dans la clef de chiffrement
    // le message chiffré est stocké par effet de bord dans la variable sortie
}

///////////////// FONCTION 3 : DECHIFFREMENT ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int indice_in_clef(char clef[],char carac){
    int indice=0;
    while (clef[indice]!=carac){
        indice++;
    }
    return indice;
    //fonction permettant de trouver l'indice du carac dans l'alphabet
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
    sortie[i]='\0';
}


/////////////////// FONCTION 4 : NETTOYAGE CHAINE DE CARACTERES ///////////////////////////////////////////////////////////////////////////////////////////////////////////

char Changement_carac(char carac){
    /* Retourne :
     * '.' pour tous les éléments ne devant pas apparitre dans la chaine "propre"
     * 'Majuscule' pour tous les éléments minuscules et accentuées
     * ' ' pour tous les espaces */
    char sortie='.'; // le cas ou il ne trouve pas des exceptions
    if ((carac<'a' || carac>'z')&& (carac<'A' ||carac>'Z') && carac!=' '){
        if (carac==-96 || carac==-94 || carac==-92 ){
                sortie='A'; //remplacer à â ä
        }
        else if (carac>=-88 && carac<=-85){
            sortie='E'; //remplacer é è ê ë
        }
        else if (carac==-89){
            sortie='C'; // remplacer ç
        }
        else if (carac==-71 || carac ==-69 || carac==-68){ // remplacer ù û ü
            sortie='U';
        }
        else if (carac==-76 || carac==-74){//remplacer ô ö
            sortie='O';
        }
        else if (carac==-82 || carac==-81){//remplacer î ï
            sortie='I';
        }
        else if (carac==':' || carac=='!' || carac=='?' || carac==',' || carac=='.' || carac=='\'' || carac=='-' ){
            sortie='.';
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
    int i=0 ,j=0;
    char temp;
    while (text[i]!='\0'){
        temp=Changement_carac(text[i]);
        if (temp!='.'){
            sortie[j]=temp;
            j++;
        }
        i++;
    }
    sortie[j]='\0'; //je rajoute '\0' pour éviter l'apparition de caractère non désiré
}

//////////////////// FONCTION 5 : OCCURENCE //////////////////////////////////////////////////////////////////////////////////////////////////////
void occurence(float tab[],char text[]){
    int i=0;
    int nb_carac=1;
    int indice;
    while (text[i]!='\0'){
        indice=indice_in_alpha(text[i]);
        tab[indice]+=1;
        nb_carac++;
        i++;
    }
    for (i=0;i<N-1;i++){
        tab[i]=tab[i]/nb_carac;
    }
}

//////////////////// FONCTION 6 : DECRYPTAGE //////////////////////////////////////////////////////////////////////////////////////////////////////

void tri_ordre_desc(float occ[], char app_txt[]){
  int i = 0, j;
  float max_occ;
  int indice_max;
  char alphabet[N];
  strcpy(alphabet, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
  printf("----- tri_ordre_desc -----\n");

  for (i=0;i<N-1;i++){
      max_occ = occ[i];
      indice_max = i;
      for (j=0;j<N-1;j++){
          if (occ[j] > max_occ){
              max_occ = occ[j];
              indice_max = j;
          }
      }
      occ[indice_max] = -1;
      app_txt[i] = alphabet[indice_max];
      printf("%c", app_txt[i]);
  }
 app_txt[i+1] = ' ';
 printf("\n");

}

void clef_freq(char app_txt[], char clef[]){
  int i=0;
  int indice;
  char app_fr[N];
  strcpy(app_fr, " EASINTRLUODCMPVGFBQHXJYZKW" );
  while (app_fr[i] != '\0'){
    indice = indice_in_alpha(app_fr[i]);
    clef[indice] = app_txt[i];
    i++;
  }
  clef[i]='\0';
  printf("----CLEF----\n");
  printf("%s\n", clef);
}

void Decryptage(char sortie[], char text[]){
float freq[N-1]={0};
  char app_txt[N];
  char clef[N];

  occurence(freq, text);
  tri_ordre_desc(freq, app_txt);
  clef_freq(app_txt, clef);

  Dechiffrement(sortie, text, clef);  
}



////////////////////////////////// MAIN ////////////////////////////////////////////////////////////////////////////////////////////////////////


int main(){
    srand(time(NULL));
    int i;
    char alphabet[N];
    strcpy(alphabet, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    printf("%s\n",alphabet);
    //permutation
    char permutation[N];
    Permutation(permutation);
    printf("------- CLEF DE PERMUTATION -------\n");
    printf("%s\n",permutation);

    //nettoyage
    char text[]="Bonjour à tous !";
    /*printf("%s\n",text);*/
    char texte_propre[strlen(text)];
    Nettoyage(texte_propre,text);
    //printf("%s\n",texte_propre);
    
    //ocurrence
    float table_des_frequences[N-1]={0}; //j'ai mis N-1 pour que le tableau soit de la taille de l'alphabet excepté '\0'
    occurence(table_des_frequences,texte_propre);
    printf("------- TABLE DES FREQUENCES --------\n");
    for (i=0;i<N-1;i++){
    printf("%c = %.8f | ",alphabet[i],table_des_frequences[i]);
    }
    printf("\n");
    
    //chiffrement
    char sortie_chiffree[strlen(texte_propre)];
    Chiffrement(sortie_chiffree,texte_propre,permutation);
    printf("------- TEXTE CHIFFREE -------\n");
    printf("%s\n",sortie_chiffree);
    printf("------- FIN ------\n");
    
    //dechiffrement
    /* char sortie_dechiffree[strlen(texte_propre)];
    Dechiffrement(sortie_dechiffree,sortie_chiffree,permutation);
    printf("%s\n",sortie_dechiffree);*/

    //decryptage
    char sortie_dechiffree[strlen(texte_propre)];
    Decryptage(sortie_dechiffree, sortie_chiffree);
    printf("------- TEXTE DECHIFFREE -------\n");
    printf("%s\n",sortie_dechiffree);
    printf("------- FIN -------\n");
    
    return 0;
}
