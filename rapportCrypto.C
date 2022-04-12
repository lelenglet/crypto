#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 28 // longueur pour l'alphabet

////// FONCTION 1 : PERMUTATION ////
void Permutation(char sortie[]){
    int i ; // compteur
    int random;
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    strcpy(sortie,alphabet);//alphabet de départ copié dans la sortie
    char temp;

    for (i=strlen(sortie)-1; i>1; i--){ // longueur-1 pour exclure la dernière case contenant '/0' de la permutation
        random = rand () % i;
        temp= sortie[i];
        sortie[i]=sortie[random];
        sortie[random]=temp;
    }
}

////// FONCTION 2 : CHIFFREMENT ////
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

//// FONCTION 3 : DECHIFFREMENT ////
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
    sortie[i]='\0';
}


//// FONCTION 4 : NETTOYAGE ////
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
        else if (carac==':' || carac=='!' || carac=='?' || carac==',' || carac=='.' || carac=='\'' || carac=='-'){
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

//// FONCTION 5 : OCCURENCE ////
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
 printf("\n\n");
}

void clef_freq(char app_txt[], char clef[]){
  int i=0;
  int indice;
  char app_fr[N];
  strcpy(app_fr, " EASINTRLUODCPMVGFBQHXJYZKW" );
  while (app_fr[i] != '\0'){
    indice = indice_in_alpha(app_fr[i]);
    clef[indice] = app_txt[i];
    i++;
  }
  clef[i]='\0';
  printf("----CLEF----\n");
  printf("%s\n\n", clef);
}

void Decryptage(char sortie[], char text[]){
  float freq[N-1];
  char app_txt[N];
  char clef[N];

  occurence(freq, text);
  tri_ordre_desc(freq, app_txt);
  clef_freq(app_txt, clef);

  Dechiffrement(sortie, text, clef);
}

/////// FONCTION PRINCIPALE ////////////////

int main(){
    srand(time(NULL));
    int i;
    char alphabet[N];
    strcpy(alphabet, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    printf("------- ALPHABET -------\n|%s|\n\n",alphabet);

    //permutation
    char permutation[N];
    Permutation(permutation);
    printf("------- CLEF DE PERMUTATION -------\n");
    printf("%s\n\n",permutation);

    //nettoyage
    char text[]="À cette heure où je descendais apprendre le menu, le dîner était déjà commencé, et Françoise, commandant aux forces de la nature devenues ses aides, comme dans les féeries où les géants se font engager comme cuisiniers, frappait la houille, donnait à la vapeur des pommes de terre à étuver et faisait finir à point par le feu les chefs-d’oeuvre culinaires d’abord préparés dans des récipients de céramistes qui allaient des grandes cuves, marmites, chaudrons et poissonnières, aux terrines pour le gibier, moules à pâtisserie, et petits pots de crème en passant par une collection complète de casseroles de toutes dimensions. Je m’arrêtais à voir sur la table, où la fille de cuisine venait de les écosser, les petits pois alignés et nombrés comme des billes vertes dans un jeu ; mais mon ravissement était devant les asperges, trempées d’outremer et de rose et dont l’épi, finement pignoché de mauve et d’azur, se dégrade insensiblement jusqu’au pied – encore souillé pourtant du sol de leur plant – par des irisations qui ne sont pas de la terre. Il me semblait que ces nuances célestes trahissaient les délicieuses créatures qui s’étaient amusées à se métamorphoser en légumes et qui, à travers le déguisement de leur chair comestible et ferme, laissaient apercevoir en ces couleurs naissantes d’aurore, en ces ébauches d’arc-en-ciel, en cette extinction de soirs bleus, cette essence précieuse que je reconnaissais encore quand, toute la nuit qui suivait un dîner où j’en avais mangé, elles jouaient, dans leurs farces poétiques et grossières comme une féerie de Shakespeare, à changer mon pot de chambre en un vase de parfum. La pauvre Charité de Giotto, comme l’appelait Swann, chargée par Françoise de les « plumer », les avait près d’elle dans une corbeille, son air était douloureux, comme si elle ressentait tous les malheurs de la terre ; et les légères couronnes d’azur qui ceignaient les asperges au-dessus de leurs tuniques de rose étaient finement dessinées, étoile par étoile, comme le sont dans la fresque les fleurs bandées autour du front ou piquées dans la corbeille de la Vertu de Padoue. Et cependant, Françoise tournait à la broche un de ces poulets, comme elle seule savait en rôtir, qui avaient porté loin dans Combray l’odeur de ses mérites, et qui, pendant qu’elle nous les servait à table, faisaient prédominer la douceur dans ma conception spéciale de son caractère, l’arôme de cette chair qu’elle savait rendre si onctueuse et si tendre n’étant pour moi que le propre parfum d’une de ses vertus. Mais le jour où, pendant que mon père consultait le conseil de famille sur la rencontre de Legrandin, je descendis à la cuisine, était un de ceux où la Charité de Giotto, très malade de son accouchement récent, ne pouvait se lever ; Françoise, n’étant plus aidée, était en retard. Quand je fus en bas, elle était en train, dans l’arrière-cuisine qui donnait sur la basse-cour, de tuer un poulet qui, par sa résistance désespérée et bien naturelle, mais accompagnée par Françoise hors d’elle, tandis qu’elle cherchait à lui fendre le cou sous l’oreille, des cris de « sale bête ! sale bête ! », mettait la sainte douceur et l’onction de notre servante un peu moins en lumière qu’il n’eût fait, au dîner du lendemain, par sa peau brodée d’or comme une chasuble et son jus précieux égoutté d’un ciboire. Quand il fut mort, Françoise recueillit le sang qui coulait sans noyer sa rancune, eut encore un sursaut de colère, et regardant le cadavre de son ennemi, dit une dernière fois : « Sale bête ! » Je remontai tout tremblant ; j’aurais voulu qu’on mît Françoise tout de suite à la porte. Mais qui m’eût fait des boules aussi chaudes, du café aussi parfumé, et même… ces poulets ?… Et en réalité, ce lâche calcul, tout le monde avait eu à le faire comme moi. Car ma tante Léonie savait – ce que j’ignorais encore – que Françoise qui, pour sa fille, pour ses neveux, aurait donné sa vie sans une plainte, était pour d’autres êtres d’une dureté singulière. Malgré cela ma tante l’avait gardée, car si elle connaissait sa cruauté, elle appréciait son service. Je m’aperçus peu à peu que la douceur, la componction, les vertus de Françoise cachaient des tragédies d’arrière-cuisine, comme l’histoire découvre que les règnes des Rois et des Reines, qui sont représentés les mains jointes dans les vitraux des églises, furent marqués d’incidents sanglants. Je me rendis compte que, en dehors de ceux de sa parenté, les humains excitaient d’autant plus sa pitié par leurs malheurs, qu’ils vivaient plus éloignés d’elle. Les torrents de larmes qu’elle versait en lisant le journal sur les infortunes des inconnus se tarissaient vite si elle pouvait se représenter la personne qui en était l’objet d’une façon un peu précise. Une de ces nuits qui suivirent l’accouchement de la fille de cuisine, celle-ci fut prise d’atroces coliques ; maman l’entendit se plaindre, se leva et réveilla Françoise qui, insensible, déclara que tous ces cris étaient une comédie, qu’elle voulait « faire la maîtresse ». Le médecin, qui craignait ces crises, avait mis un signet, dans un livre de médecine que nous avions, à la page où elles sont décrites et où il nous avait dit de nous reporter pour trouver l’indication des premiers soins à donner. Ma mère envoya Françoise chercher le livre en lui recommandant de ne pas laisser tomber le signet. Au bout d’une heure, Françoise n’était pas revenue ; ma mère indignée crut qu’elle s’était recouchée et me dit d’aller voir moi-même dans la bibliothèque. J’y trouvai Françoise qui, ayant voulu regarder ce que le signet marquait, lisait la description clinique de la crise et poussait des sanglots maintenant qu’il s’agissait d’une malade-type qu’elle ne connaissait pas. À chaque symptôme douloureux mentionné par l’auteur du traité, elle s’écriait Hé là ! Sainte Vierge, est-il possible que le Bon Dieu veuille faire souffrir ainsi une malheureuse créature humaine ? Hé ! la pauvre ! Mais dès que je l’eus appelée et qu’elle fut revenue près du lit de la Charité de Giotto, ses larmes cessèrent aussitôt de couler ; elle ne put reconnaître ni cette agréable sensation de pitié et d’attendrissement qu’elle connaissait bien et que la lecture des journaux lui avait souvent donnée, ni aucun plaisir de même famille, dans l’ennui et dans l’irritation de s’être levée au milieu de la nuit pour la fille de cuisine, et à la vue des mêmes souffrances dont la description l’avait fait pleurer, elle n’eut plus que des ronchonnements de mauvaise humeur, même d’affreux sarcasmes, disant, quand elle crut que nous étions partis et ne pouvions plus l’entendre : « Elle n’avait qu’à ne pas faire ce qu’il faut pour ça ! ça lui a fait plaisir ! qu’elle ne fasse pas de manières maintenant. Faut-il tout de même qu’un garçon ait été abandonné du Bon Dieu pour aller avec ça. Ah ! c’est bien comme on disait dans le patois de ma pauvre mère : Qui du cul d’un chien s’amourose, Il lui paraît une rose. Si, quand son petit-fils était un peu enrhumé du cerveau, elle partait la nuit, même malade, au lieu de se coucher, pour voir s’il n’avait besoin de rien, faisant quatre lieues à pied avant le jour afin d’être rentrée pour son travail, en revanche ce même amour des siens et son désir d’assurer la grandeur future de sa maison se traduisait dans sa politique à l’égard des autres domestiques par une maxime constante qui fut de n’en jamais laisser un seul s’implanter chez ma tante, qu’elle mettait d’ailleurs une sorte d’orgueil à ne laisser approcher par personne, préférant, quand elle-même était malade, se relever pour lui donner son eau de Vichy plutôt que de permettre l’accès de la chambre de sa maîtresse à la fille de cuisine. Et comme cet hyménoptère observé par Fabre, la guêpe fouisseuse, qui pour que ses petits après sa mort aient de la viande fraîche à manger, appelle l’anatomie au secours de sa cruauté et, ayant capturé des charançons et des araignées, leur perce avec un savoir et une adresse merveilleux le centre nerveux d’où dépend le mouvement des pattes, mais non les autres fonctions de la vie, de façon que l’insecte paralysé près duquel elle dépose ses oeufs, fournisse aux larves quand elles écloront un gibier docile, inoffensif, incapable de fuite ou de résistance, mais nullement faisandé, Françoise trouvait pour servir sa volonté permanente de rendre la maison intenable à tout domestique, des ruses si savantes et si impitoyables que, bien des années plus tard, nous apprîmes que si cet été-là nous avions mangé presque tous les jours des asperges, c’était parce que leur odeur donnait à la pauvre fille de cuisine chargée de les éplucher des crises d’asthme d’une telle violence qu’elle fut obligée de finir par s’en aller.";
    char texte_propre[strlen(text)];
    Nettoyage(texte_propre,text);
    printf("------- TEXTE NETTOYE -------\n");
    printf("%s\n",texte_propre);
    printf("------- FIN ------\n\n");


    //ocurrence
    float table_des_frequences[N-1]={0}; //j'ai mis N-1 pour que le tableau soit de la taille de l'alphabet excepté '\0'
    occurence(table_des_frequences,texte_propre);
    printf("------- TABLE DES FREQUENCES --------\n");
    for (i=0;i<N-1;i++){
    printf("%c = %f | ",alphabet[i],table_des_frequences[i]);
    }
    printf("\n\n");

    //chiffrement
    char sortie_chiffree[strlen(texte_propre)];
    Chiffrement(sortie_chiffree,texte_propre,permutation);
    printf("------- TEXTE CHIFFREE -------\n");
    printf("%s\n",sortie_chiffree);
    printf("------- FIN ------\n\n");

    //dechiffrement
    char sortie_dechiffree1[strlen(texte_propre)];
    Dechiffrement(sortie_dechiffree1,sortie_chiffree,permutation);
    printf("------- TEXTE DECHIFFREE PAR FONCTION 4 -------\n");
    printf("%s\n",sortie_dechiffree1);
    printf("------- FIN ------\n\n");


    //decryptage
    char sortie_dechiffree2[strlen(texte_propre)];
    Decryptage(sortie_dechiffree2, sortie_chiffree);
    printf("------- TEXTE DECHIFFREE PAR FONCTION 6 -------\n");
    printf("%s\n",sortie_dechiffree2);
    printf("------- FIN -------\n\n");

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define N 28 // longueur pour l'alphabet

////// FONCTION 1 : PERMUTATION ////
void Permutation(char sortie[]){
    int i ; // compteur
    int random;
    char alphabet[N];
    strcpy(alphabet,"ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    strcpy(sortie,alphabet);//alphabet de départ copié dans la sortie
    char temp;

    for (i=strlen(sortie)-1; i>1; i--){ // longueur-1 pour exclure la dernière case contenant '/0' de la permutation
        random = rand () % i;
        temp= sortie[i];
        sortie[i]=sortie[random];
        sortie[random]=temp;
    }
}

////// FONCTION 2 : CHIFFREMENT ////
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

//// FONCTION 3 : DECHIFFREMENT ////
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
    sortie[i]='\0';
}


//// FONCTION 4 : NETTOYAGE ////
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
        else if (carac==':' || carac=='!' || carac=='?' || carac==',' || carac=='.' || carac=='\'' || carac=='-'){
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

//// FONCTION 5 : OCCURENCE ////
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
 printf("\n\n");
}

void clef_freq(char app_txt[], char clef[]){
  int i=0;
  int indice;
  char app_fr[N];
  strcpy(app_fr, " EASINTRLUODCPMVGFBQHXJYZKW" );
  while (app_fr[i] != '\0'){
    indice = indice_in_alpha(app_fr[i]);
    clef[indice] = app_txt[i];
    i++;
  }
  clef[i]='\0';
  printf("----CLEF----\n");
  printf("%s\n\n", clef);
}

void Decryptage(char sortie[], char text[]){
  float freq[N-1];
  char app_txt[N];
  char clef[N];

  occurence(freq, text);
  tri_ordre_desc(freq, app_txt);
  clef_freq(app_txt, clef);

  Dechiffrement(sortie, text, clef);
}

/////// FONCTION PRINCIPALE ////////////////

int main(){
    srand(time(NULL));
    int i;
    char alphabet[N];
    strcpy(alphabet, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
    printf("------- ALPHABET -------\n|%s|\n\n",alphabet);

    //permutation
    char permutation[N];
    Permutation(permutation);
    printf("------- CLEF DE PERMUTATION -------\n");
    printf("%s\n\n",permutation);

    //nettoyage
    char text[]="À cette heure où je descendais apprendre le menu, le dîner était déjà commencé, et Françoise, commandant aux forces de la nature devenues ses aides, comme dans les féeries où les géants se font engager comme cuisiniers, frappait la houille, donnait à la vapeur des pommes de terre à étuver et faisait finir à point par le feu les chefs-d’oeuvre culinaires d’abord préparés dans des récipients de céramistes qui allaient des grandes cuves, marmites, chaudrons et poissonnières, aux terrines pour le gibier, moules à pâtisserie, et petits pots de crème en passant par une collection complète de casseroles de toutes dimensions.";
    char texte_propre[strlen(text)];
    Nettoyage(texte_propre,text);
    printf("------- TEXTE NETTOYE -------\n");
    printf("%s\n",texte_propre);
    printf("------- FIN ------\n\n");


    //ocurrence
    float table_des_frequences[N-1]={0}; //j'ai mis N-1 pour que le tableau soit de la taille de l'alphabet excepté '\0'
    occurence(table_des_frequences,texte_propre);
    printf("------- TABLE DES FREQUENCES --------\n");
    for (i=0;i<N-1;i++){
    printf("%c = %f | ",alphabet[i],table_des_frequences[i]);
    }
    printf("\n\n");

    //chiffrement
    char sortie_chiffree[strlen(texte_propre)];
    Chiffrement(sortie_chiffree,texte_propre,permutation);
    printf("------- TEXTE CHIFFREE -------\n");
    printf("%s\n",sortie_chiffree);
    printf("------- FIN ------\n\n");

    //dechiffrement
    char sortie_dechiffree1[strlen(texte_propre)];
    Dechiffrement(sortie_dechiffree1,sortie_chiffree,permutation);
    printf("------- TEXTE DECHIFFREE PAR FONCTION 4 -------\n");
    printf("%s\n",sortie_dechiffree1);
    printf("------- FIN ------\n\n");


    //decryptage
    char sortie_dechiffree2[strlen(texte_propre)];
    Decryptage(sortie_dechiffree2, sortie_chiffree);
    printf("------- TEXTE DECHIFFREE PAR FONCTION 6 -------\n");
    printf("%s\n",sortie_dechiffree2);
    printf("------- FIN -------\n\n");

    return 0;
}
