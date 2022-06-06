#include<stdio.h>
#include<time.h>
#include<math.h>
#include<errno.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<ctype.h>
#include"struct.h"
#define TAILLE 100

int affichage();
User constructUser(User tab[]);
void displayUser(User u);
User* saveUser(int *nmb_user);
int login(User tab[]);
void enregistreuser(User tab[],int nmb_user);

