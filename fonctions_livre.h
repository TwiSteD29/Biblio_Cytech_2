#include<stdio.h>
#include<time.h>
#include<math.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#include "fonctions_utilisateur.h" 
#define TAILLE 100

void timee(int* h,int* min,int* sec);
void heure_max_restitution(int* h,int* min,int* sec);
int liste_livre_biblio();
int recherche_livre();
int emp_livre(User tab[],int place,Livre tab_livre[],int nmb_livre);
void rest_livre(User tab[],int place, int nmb_livre);
void liste_livre_emp(User tab[],int place, int nmb_livre);
void enregistrelivre(Livre tab_livre[],int nmb_livre);
int ajout_livre(User tab[],int place);
Livre* recuplivre(int* nmb_livre);

