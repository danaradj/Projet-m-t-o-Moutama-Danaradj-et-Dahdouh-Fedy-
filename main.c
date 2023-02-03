#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define TAILLE 1000

typedef struct Chainon Chainon; //structure permettant de definir la liste chainée
struct Chainon {
  char chaine[TAILLE]; 
  Chainon *suivant; 
}; 

/*Fonction qui va permettre l'insertion de mot dans notre liste chainée*/

Chainon *add_word (Chainon **pliste, char *mot) {
  Chainon *nouveau = malloc(sizeof(*nouveau)); //on alloue l'espace necessaire
  strcpy(nouveau->chaine, mot);
  nouveau->suivant =*pliste; // on ajoute les mots en début de liste
  *pliste = nouveau;
}

/*Fonction qui va permettre d'ouvrir le fichier avec lequel nous souhaitons travailler pour ajouter les
mots de ce fichier à une liste chainée */

Chainon *add_word_liste (Chainon **pliste) {
  FILE *fichier = NULL;
  char str[100]; //on ouvre le fichier csv qui contient les données méteo
  printf("Quel est le nom du fichier à trier(ce fichier doit etre dans le meme dossier que le programme)\n"); 
  gets(str); 
  fichier = fopen(str, "r"); 
  if(fichier == NULL) {
    printf("Il est impossible de travailler sur le fichier que vous avez selectionner\n");
  }
  char mot[TAILLE];
  while(fgets(mot, TAILLE, fichier) != NULL) {  //tant qu'il y a des caractères dans le fichier on ajoute les mots à la liste
    add_word(pliste,mot);
  }
}

//Procédure qui permet de libérer la liste

void vider_liste(Chainon *pliste) {
  Chainon *nouveau; 
  Chainon *mot; 
  for (nouveau = pliste; nouveau;)
  {
    mot = nouveau->suivant;
    free(nouveau); 
    nouveau = mot; 
  }
}

/*Fonction qui permet d'écrire les données triée de la liste dans un nouveau fichier*/

FILE *Ecrire_donnee_trier(char *str, Chainon *pliste) {
  
  Chainon *nouveau = pliste;
  FILE* fichier = NULL;
  fichier = fopen(str, "w"); //On crée le fichier de sortie qui va contenir les données triées
  while (pliste != NULL) {
    fputs(pliste->chaine, fichier); //on ecrit les données dans le nouveau fichier de sortie en question 
    pliste = pliste -> suivant; 
  } 
  fclose(fichier); 
  vider_liste(nouveau); 

}

/*Fonction qui va permettre de trier la liste qui contient les mots du fichiers*/

Chainon *Trier_liste(Chainon **pliste) {
  Chainon *nouveau; 
  char str[TAILLE]; 
  if(*pliste != NULL) {
    for(nouveau=(*pliste)->suivant; nouveau; nouveau=nouveau->suivant) {
      if(strcmp((*pliste)->chaine,nouveau->chaine)>0) { //je trie les donnnées de facon croissante
        strcpy(str,(*pliste)->chaine);
        strcpy((*pliste)->chaine,nouveau->chaine);    //méthode du tri à bulle pour les listes
        strcpy(nouveau->chaine,str);
      }

    }
    Trier_liste(&((*pliste)->suivant));
  }
}

int main(int argc, char const *argv[])
{
  char str[] = "Fichier de donnée trier"; //Nom du fichier de sortie qui est triée
  Chainon *pliste = NULL; 
  add_word_liste(&pliste);
  Trier_liste(&pliste);
  Ecrire_donnee_trier(str, pliste);
  printf("Le fichier à été trié correctement\n");  
  return 0;
}