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

//////////////////// FONCTION 5 : OCCURENCE //////////////////////////////////////////////////////////////////////////////////////////////////////
void occurence(float tab[],char text[]){
    int i=0;
    int nb_carac=1;
    int indice;
    printf("---Occ---\n");
    while (text[i]!='\0'){
        indice=indice_in_alpha(text[i]);

        tab[indice]+=1;
        nb_carac++;
        i++;
    }
    for (i=0;i<N-1;i++){
        tab[i]=tab[i]/nb_carac;
	printf("|%f", tab[i]);
    }
    printf("|\n");
}

//////////////////// FONCTION 6 : DECRYPTAGE //////////////////////////////////////////////////////////////////////////////////////////////////////

/* Fréquences d'apparition des lettres par ordre décroissant de fréquence:
"EASINTRLUODCPMVGFBQHXJYZKW"*/

void tri_ordre_desc(float occ[], char app_txt[]){
  int i = 0, j;
  float max_occ;
  int indice_max;
  char alphabet[N];
  strcpy(alphabet, "ABCDEFGHIJKLMNOPQRSTUVWXYZ ");
  printf("----- tri_ordre_desc -----\n");

  while (occ[i+1] != '\0'){
    max_occ = occ[0];
    indice_max = 0;
    j = 1;
    while (occ[j+1] != '\0'){
      if (occ[j] > max_occ){
	max_occ = occ[j];
	indice_max = j;
      }
      j++;
    }
    occ[indice_max] = -1;
    app_txt[i] = alphabet[indice_max];
    printf("%c", app_txt[i]);
    i++;
  }
  app_txt[i] = ' ';
  app_txt[i+1] = '\0';
  printf("\n");
}

void clef_freq(char app_txt[], char clef[]){
  int i=0;
  int indice;
  char app_fr[N-1];
  strcpy(app_fr, "EASINTRLUODCPMVGFBQHXJYZKW" );

  while (app_fr[i] != '\0'){
    indice = indice_in_alpha(app_fr[i]);
    //printf("lettre %c\n", app_fr[i]);
    //printf("indice %d\n", indice);
    clef[indice] = app_txt[i];
    //printf("clef %c\n",  clef[indice]);
    i++;
  }
  printf("----CLEF----\n");
  printf("%s\n", clef);
}

void Decryptage(char sortie[], char text[]){
  float freq[N];
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
    //int i;

    //permutation
    char permutation[N];
    Permutation(permutation);
    printf("------- CLEF DE PERMUTATION -------\n");
    printf("%s\n",permutation);

    //nettoyage
    char text[]="J’appuyais tendrement mes joues contre les belles joues de l’oreiller qui, pleines et fraîches, sont comme les joues de notre enfance. Je frottais une allumette pour regarder ma montre. Bientôt minuit. C’est l’instant où le malade, qui a été obligé de partir en voyage et a dû coucher dans un hôtel inconnu, réveillé par une crise, se réjouit en apercevant sous la porte une raie de jour. Quel bonheur, c’est déjà le matin ! Dans un moment les domestiques seront levés, il pourra sonner, on viendra lui porter secours. L’espérance d’être soulagé lui donne du courage pour souffrir. Justement il a cru entendre des pas ; les pas se rapprochent, puis s’éloignent. Et la raie de jour qui était sous sa porte a disparu. C’est minuit ; on vient d’éteindre le gaz ; le dernier domestique est parti et il faudra rester toute la nuit à souffrir sans remède.Je me rendormais, et parfois je n’avais plus que de courts réveils d’un instant, le temps d’entendre les craquements organiques des boiseries, d’ouvrir les yeux pour fixer le kaléidoscope de l’obscurité, de goûter grâce à une lueur momentanée de conscience le sommeil où étaient plongés les meubles, la chambre, le tout dont je n’étais qu’une petite partie et à l’insensibilité duquel je retournais vite m’unir. Ou bien en dormant j’avais rejoint sans effort un âge à jamais révolu de ma vie primitive, retrouvé telle de mes terreurs enfantines comme celle que mon grand-oncle me tirât par mes boucles et qu’avait dissipée le jour – date pour moi d’une ère nouvelle – où on les avait coupées. J’avais oublié cet événement pendant mon sommeil, j’en retrouvais le souvenir aussitôt que j’avais réussi à m’éveiller pour échapper aux mains de mon grand-oncle, mais par mesure de précaution j’entourais complètement ma tête de mon oreiller avant de retourner dans le monde des rêves.Quelquefois, comme Ève naquit d’une côte d’Adam, une femme naissait pendant mon sommeil d’une fausse position de ma cuisse. Formée du plaisir que j’étais sur le point de goûter, je m’imaginais que c’était elle qui me l’offrait. Mon corps qui sentait dans le sien ma propre chaleur voulait s’y rejoindre, je m’éveillais. Le reste des humains m’apparaissait comme bien lointain auprès de cette femme que j’avais quittée il y avait quelques moments à peine ; ma joue était chaude encore de son baiser, mon corps courbaturé par le poids de sa taille. Si, comme il arrivait quelquefois, elle avait les traits d’une femme que j’avais connue dans la vie, j’allais me donner tout entier à ce but : la retrouver, comme ceux qui partent en voyage pour voir de leurs yeux une cité désirée et s’imaginent qu’on peut goûter dans une réalité le charme du songe. Peu à peu son souvenir s’évanouissait, j’avais oublié la fille de mon rêve.Un homme qui dort, tient en cercle autour de lui le fil des heures, l’ordre des années et des mondes. Il les consulte d’instinct en s’éveillant et y lit en une seconde le point de la terre qu’il occupe, le temps qui s’est écoulé jusqu’à son réveil ; mais leurs rangs peuvent se mêler, se rompre. Que vers le matin après quelque insomnie, le sommeil le prenne en train de lire, dans une posture trop différente de celle où il dort habituellement, il suffit de son bras soulevé pour arrêter et faire reculer le soleil, et à la première minute de son réveil, il ne saura plus l’heure, il estimera qu’il vient à peine de se coucher. Que s’il s’assoupit dans une position encore plus déplacée et divergente, par exemple après dîner assis dans un fauteuil, alors le bouleversement sera complet dans les mondes désorbités, le fauteuil magique le fera voyager à toute vitesse dans le temps et dans l’espace, et au moment d’ouvrir les paupières, il se croira couché quelques mois plus tôt dans une autre contrée. Mais il suffisait que, dans mon lit même, mon sommeil fût profond et détendît entièrement mon esprit ; alors celui-ci lâchait le plan du lieu où je m’étais endormi, et quand je m’éveillais au milieu de la nuit, comme j’ignorais où je me trouvais, je ne savais même pas au premier instant qui j’étais ; j’avais seulement dans sa simplicité première, le sentiment de l’existence comme il peut frémir au fond d’un animal ; j’étais plus dénué que l’homme des cavernes ; mais alors le souvenir – non encore du lieu où j’étais, mais de quelques-uns de ceux que j’avais habités et où j’aurais pu être – venait à moi comme un secours d’en haut pour me tirer du néant d’où je n’aurais pu sortir tout seul ; je passais en une seconde par-dessus des siècles de civilisation, et l’image confusément entrevue de lampes à pétrole, puis de chemises à col rabattu, recomposaient peu à peu les traits originaux de mon moi.Peut-être l’immobilité des choses autour de nous leur est-elle imposée par notre certitude que ce sont elles et non pas d’autres, par l’immobilité de notre pensée en face d’elles. Toujours est-il que, quand je me réveillais ainsi, mon esprit s’agitant pour chercher, sans y réussir, à savoir où j’étais, tout tournait autour de moi dans l’obscurité, les choses, les pays, les années. Mon corps, trop engourdi pour remuer, cherchait, d’après la forme de sa fatigue, à repérer la position de ses membres pour en induire la direction du mur, la place des meubles, pour reconstruire et pour nommer la demeure où il se trouvait. Sa mémoire, la mémoire de ses côtes, de ses genoux, de ses épaules, lui présentait successivement plusieurs des chambres où il avait dormi, tandis qu’autour de lui les murs invisibles, changeant de place selon la forme de la pièce imaginée, tourbillonnaient dans les ténèbres. Et avant même que ma pensée, qui hésitait au seuil des temps et des formes, eût identifié le logis en rapprochant les circonstances, lui, – mon corps, – se rappelait pour chacun le genre du lit, la place des portes, la prise de jour des fenêtres, l’existence d’un couloir, avec la pensée que j’avais en m’y endormant et que je retrouvais au réveil. Mon côté ankylosé, cherchant à deviner son orientation, s’imaginait, par exemple, allongé face au mur dans un grand lit à baldaquin et aussitôt je me disais : « Tiens, j’ai fini par m’endormir quoique maman ne soit pas venue me dire bonsoir », j’étais à la campagne chez mon grand-père, mort depuis bien des années ; et mon corps, le côté sur lequel je reposais, gardiens fidèles d’un passé que mon esprit n’aurait jamais dû oublier, me rappelaient la flamme de la veilleuse de verre de Bohême, en forme d’urne, suspendue au plafond par des chaînettes, la cheminée en marbre de Sienne, dans ma chambre à coucher de Combray, chez mes grands-parents, en des jours lointains qu’en ce moment je me figurais actuels sans me les représenter exactement et que je reverrais mieux tout à l’heure quand je serais tout à fait éveillé.Puis renaissait le souvenir d’une nouvelle attitude ; le mur filait dans une autre direction : j’étais dans ma chambre chez Mme de Saint-Loup, à la campagne ; mon Dieu ! il est au moins dix heures, on doit avoir fini de dîner ! J’aurai trop prolongé la sieste que je fais tous les soirs en rentrant de ma promenade avec Mme de Saint-Loup, avant d’endosser mon habit. Car bien des années ont passé depuis Combray, où, dans nos retours les plus tardifs, c’étaient les reflets rouges du couchant que je voyais sur le vitrage de ma fenêtre. C’est un autre genre de vie qu’on mène à Tansonville, chez Mme de Saint-Loup, un autre genre de plaisir que je trouve à ne sortir qu’à la nuit, à suivre au clair de lune ces chemins où je jouais jadis au soleil ; et la chambre où je me serai endormi au lieu de m’habiller pour le dîner, de loin je l’aperçois, quand nous rentrons, traversée par les feux de la lampe, seul phare dans la nuit.Ces évocations tournoyantes et confuses ne duraient jamais que quelques secondes ; souvent, ma brève incertitude du lieu où je me trouvais ne distinguait pas mieux les unes des autres les diverses suppositions dont elle était faite, que nous n’isolons, en voyant un cheval courir, les positions successives que nous montre le kinétoscope. Mais j’avais revu tantôt l’une, tantôt l’autre, des chambres que j’avais habitées dans ma vie, et je finissais par me les rappeler toutes dans les longues rêveries qui suivaient mon réveil ; chambres d’hiver où quand on est couché, on se blottit la tête dans un nid qu’on se tresse avec les choses les plus disparates : un coin de l’oreiller, le haut des couvertures, un bout de châle, le bord du lit, et un numéro des Débats roses, qu’on finit par cimenter ensemble selon la technique des oiseaux en s’y appuyant indéfiniment ; où, par un temps glacial le plaisir qu’on goûte est de se sentir séparé du dehors (comme l’hirondelle de mer qui a son nid au fond d’un souterrain dans la chaleur de la terre), et où, le feu étant entretenu toute la nuit dans la cheminée, on dort dans un grand manteau d’air chaud et fumeux, traversé des lueurs des tisons qui se rallument, sorte d’impalpable alcôve, de chaude caverne creusée au sein de la chambre même, zone ardente et mobile en ses contours thermiques, aérée de souffles qui nous rafraîchissent la figure et viennent des angles, des parties voisines de la fenêtre ou éloignées du foyer, et qui se sont refroidies ; – chambres d’été où l’on aime être uni à la nuit tiède, où le clair de lune appuyé aux volets entrouverts, jette jusqu’au pied du lit son échelle enchantée, où on dort presque en plein air, comme la mésange balancée par la brise à la pointe d’un rayon ; – parfois la chambre Louis XVI, si gaie que même le premier soir je n’y avais pas été trop malheureux et où les colonnettes qui soutenaient légèrement le plafond s’écartaient avec tant de grâce pour montrer et réserver la place du lit ; parfois au contraire celle, petite et si élevée de plafond, creusée en forme de pyramide dans la hauteur de deux étages et partiellement revêtue d’acajou, où dès la première seconde j’avais été intoxiqué moralement par l’odeur inconnue du vétiver, convaincu de l’hostilité des rideaux violets et de l’insolente indifférence de la pendule qui jacassait tout haut comme si je n’eusse pas été là ; – où une étrange et impitoyable glace à pieds quadrangulaire, barrant obliquement un des angles de la pièce, se creusait à vif dans la douce plénitude de mon champ visuel accoutumé un emplacement qui n’était pas prévu ; – où ma pensée, s’efforçant pendant des heures de se disloquer, de s’étirer en hauteur pour prendre exactement la forme de la chambre et arriver à remplir jusqu’en haut son gigantesque entonnoir, avait souffert bien de dures nuits, tandis que j’étais étendu dans mon lit, les yeux levés, l’oreille anxieuse, la narine rétive, le coeur battant : jusqu’à ce que l’habitude eût changé la couleur des rideaux, fait taire la pendule, enseigné la pitié à la glace oblique et cruelle, dissimulé, sinon chassé complètement, l’odeur du vétiver et notablement diminué la hauteur apparente du plafond. L’habitude ! aménageuse habile mais bien lente et qui commence par laisser souffrir notre esprit pendant des semaines dans une installation provisoire ; mais que malgré tout il est bien heureux de trouver, car sans l’habitude et réduit à ses seuls moyens il serait impuissant à nous rendre un logis habitable.Certes, j’étais bien éveillé maintenant, mon corps avait viré une dernière fois et le bon ange de la certitude avait tout arrêté autour de moi, m’avait couché sous mes couvertures, dans ma chambre, et avait mis approximativement à leur place dans l’obscurité ma commode, mon bureau, ma cheminée, la fenêtre sur la rue et les deux portes. Mais j’avais beau savoir que je n’étais pas dans les demeures dont l’ignorance du réveil m’avait en un instant sinon présenté l’image distincte, du moins fait croire la présence possible, le branle était donné à ma mémoire ; généralement je ne cherchais pas à me rendormir tout de suite ; je passais la plus grande partie de la nuit à me rappeler notre vie d’autrefois, à Combray chez ma grand-tante, à Balbec, à Paris, à Doncières, à Venise, ailleurs encore, à me rappeler les lieux, les personnes que j’y avais connues, ce que j’avais vu d’elles, ce qu’on m’en avait raconté.";

    /*printf("%s\n",text);*/
    char texte_propre[strlen(text)];
    Nettoyage(texte_propre,text);
    /* printf("%s\n",texte_propre);*/
    
    //ocurrence
    //float table_des_frequences[N-1]={0};
    //occurence(table_des_frequences,texte_propre);
    // printf("------- TABLE DES FREQUENCES --------\n");
    //for (i=0;i<N-1;i++){
    //printf("%f | ",table_des_frequences[i]);
    //}
    //printf("\n");
    
    //chiffrement
    char sortie_chiffree[strlen(texte_propre)];
    Chiffrement(sortie_chiffree,texte_propre,permutation);
    // printf("------- TEXTE CHIFFREE -------\n");
    //printf("%s\n",sortie_chiffree);
    //printf("------- FIN ------\n");
    
    //dechiffrement
    /* char sortie_dechiffree[strlen(texte_propre)];
    Dechiffrement(sortie_dechiffree,sortie_chiffree,permutation);
    printf("%s\n",sortie_dechiffree);*/

    //decryptage
    // char sortie_dechiffree[strlen(texte_propre)];
    // Decryptage(sortie_dechiffree, sortie_chiffree);
    //printf("------- TEXTE DECHIFFREE -------\n");
    //printf("%s\n",sortie_dechiffree);
    //printf("------- FIN -------\n");

    float occ[N] = {0};
    char app_txt[N];
    
    occurence(occ, sortie_chiffree);
    tri_ordre_desc(occ, app_txt);
    
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
