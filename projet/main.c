#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "main.h"


void verification_detrie_croissant (int t[],int dim);
void verification_detrie_decroissant (int t[],int dim);
void tri(int t[],int dim,char reponse);
int doublon(int t[],int dim);
void filtre(int t[] ,int dim);
void affiche(int *arrive,int taille);



int main(){
   int taille,K;
   int i,typetri;
   int tab[30];
   char reponse;

   //demander a l'utilisateur d'entrer la taille et les élèments d'un tableau

   printf(" Entrez le nombre d'elements dans le tableau: ");
   scanf("%d", &taille);

   printf(" Entrez les elements du tableau: ");
   for (i = 0; i < taille; i++)
      scanf("%d", &tab[i]);


    //choix de tri

    printf(" \n \nveuillez saisir l\'ordre ");
    printf("\no : ordre croissant\n");
    printf("n : ordre decroissant");

    do{
        printf("\n");
        scanf("%c", &reponse); // on redemande la réponse tant qu'elle est incorrecte. Son type est une caractère.
    }while ( reponse != 'n' && reponse != 'o'); // tant que la réponse n'est pas n ni o on recommence.



	int arrive[taille];
    if ( reponse == 'n') //soit c'est o
            {
                verification_detrie_decroissant(tab,taille);
            }
    else if ( reponse == 'o')
    {
                verification_detrie_croissant(tab,taille);
    }


	tri(tab,taille,reponse);
	K=doublon(tab,taille);
	filtre(tab,taille);
    printf("\nTaille du nouveau tableau = %d\n", K);
    affiche(tab, K);
	return 0;
}

// cette fonction prend en entrée un tableau et sa dimension et qui verifie si le tableau est déja trieé par ordre croissant ou pas
//par une comparaison des élements de notre tableu avec l'élèment suivant

void verification_detrie_croissant (int t[],int dim){//
	int i ;
    int k=0;
	for (i=0;i<=dim-1;i++){
		if (t[i]<=t[i+1]){//on incremente k si la val de chaque indice i du ableau est inf à la suivante
			k+=1;
		}
		/*
		else {
			k+=0; //sinon k garde sa val
		}
		*/
	}
	 if (k==dim-1){//on compare le k qu'on a incrémenté à
			printf ("le tableau est triee dans l'ordre croissant ");
		}
	 else {
		 printf("le tableau n'est pas triee dans l'ordre croissant");
	 }
	 printf("\n");
}

// cette fonction prend en entrée un tableau et sa dimension et qui verifie si le tableau est déja trieé par ordre decroissant ou pas
//par une comparaison des élements de notre tableu avec l'élèment suivant

void verification_detrie_decroissant (int t[],int dim){
	int i ;
    int k=0;
	for (i=0;i<=dim-1;i++){
		if (t[i]>=t[i+1]){//on incremente k si la val de chaque indice i du ableau est inf à la suivante
			k+=1;
		}
		/*
		else {
			k+=0; //sinon k garde sa val
		}
		*/
	}
	 if (k==dim-1){//on compare le k qu'on a incrémenté à
			printf ("le tableau est tries dans l'ordre deccroissant ");
		}
	 else {
		 printf("le tableau n'est pas tries dans l'ordre decroissant");
	 }
	 printf("\n");
}


// cette fonction prend en entrée notre tableau et sa dimension evec un caractère tapée par l'utilisateur qui permet de choisir le type de tri souhaitée
//il s'agit de tri simple avec la permutation des élement en utilisant une variable cpt.

void tri(int t[],int dim,char reponse){

  int cpt=0;
  int i,j;

    if ( reponse == 'o'){ //soit c'est o
    for ( i=0; i < dim; i++){
        for ( j=i+1; j < dim; j++){
                if ( t[i]>t[j]){
                    cpt=t[i];
                    t[i]=t[j];
                    t[j]=cpt;
                }
        }
    }

    for (i = 0; i < dim; ++i)	printf("%d ", t[i]);
	printf("\n");}

	if ( reponse == 'n'){
    for ( i=0; i < dim; i++){
        for ( j=i+1; j < dim; j++){
                if ( t[i]<t[j]){
                    cpt=t[i];
                    t[i]=t[j];
                    t[j]=cpt;
                }
    }
    }

    for (i = 0; i < dim; ++i)	printf("%d ", t[i]);
	printf("\n");}

}

// cette fonction permet de calculer et retourner le nombre des doublon dans un tableau

int doublon(int t[],int dim){
	int c=0;
	int i;
	for (i=0;i<dim;i++){
		if (t[i]!=t[i+1]){
			c+=1;
		}
		/*
		else {
			c+=0;
		}
		*/
     }
	 printf("le nombre des elements differents est :%d",c);
	 printf("\n");
	 return c;
}

//cette fonction permet de supprimer tous les doublons dans un tableau

void filtre(int t[] ,int dim){
   int i, j, k;
   for (i = 0; i < dim; i++) {
      for (j = i + 1; j < dim;) {
         if (t[j] == t[i]) {
            for (k = j; k < dim; k++) {
               t[k] = t[k + 1];
            }
            dim--;
         } else
            j++;
      }
   }




}

//la fonction affiche c'est pour afficher le tableau final trier et sans doublons

void affiche(int *arrive,int taille){
    int i=0;
    for(i=0;i<taille;i++){
        printf("%d ",arrive[i]);
        //return 0;
    }

}




