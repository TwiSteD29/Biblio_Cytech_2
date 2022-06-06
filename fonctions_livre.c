#include"fonctions_livre.h"


    int liste_livre_biblio(User tab[],int place,int nmb_livre){
    // Fonction permettant d'afficher tous les livres de la bibliothèque.
        
        //User u;    avec User[tab] declare en haut et cette ligne en commentaire ,ajout du livre dans user fonctionne
        int nmb_user;
             
       	affichage();
        
	FILE *f;
	f = fopen("liste_livre.txt", "r");
    	if(f==NULL){
        	printf("Erreur lors de l'ouverture d'un fichier");
        	exit(1);
    	}	
    	int ch ; 
    	printf("\n    Liste des livres :  \n");
    	printf("TITRE  /  AUTEUR  /  CATEGORIE / EMPRUNT / PROPRIETAIRE\n");
       

    	while((ch=fgetc(f))!=EOF){
		printf("%c", ch); 

    	}
 
    	fclose(f);
          
      

    	printf("\nretour menu bibliotheque ? , tapez 0  \n");
    	char retour[1];
    	scanf( "%s",&retour);
    	if (strcmp (retour,"0") == 0) {
            biblio(tab,place,nmb_user);    
              
    	}                                    
    	else{
		liste_livre_biblio(tab,place,nmb_livre);
	}

}


int recherche_livre(){
//int recherche_livre(User tab[],int place){
 // Fonction permettant de rechercher un livre dans la bibliothèque en fonction d'un mot clé.
 // La recherche est effectuée à la fois par rapport au titre, à l'auteur et à la catégorie.
 int place;
 User tab[20];
    User u; 
       int nmb_user;
    
    char retour[1];
    do{
    FILE *f;
    f = fopen("liste_livre.txt", "r");
    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }
    char motcle[20];
    printf("\n Saisissez un mot cle pour rechercher un livre  \n");
    scanf( "%s",motcle);
    char ligneLivre[10000];
    printf("\n Liste des livres  : %s", ligneLivre);
    while (fgets(ligneLivre,9999,f)!=NULL){
    char * resultat;
       resultat=strstr(ligneLivre,motcle);
         if (resultat != 0 ) {
      printf("\n %s", ligneLivre);
         }
    }
    fclose(f);
    printf("\nretour menu bibliotheque tapez 1  \n");
    scanf( "%s",&retour);
    if (strcmp(retour,"1") ==0) {
    biblio(tab,place,nmb_user);
    }                                    
    	else{
		recherche_livre(tab,place);
	} 
  
    }while (strcmp(retour,"1") != 0 || strcmp(retour,"2") != 0 );
    
}

void enregistrelivre(Livre tab[],int nmb_livre){
// Fonction permettant de modifier le fichier  liste_livre en ajoutant l'emprunteur(user), l'heure d'emprunt et indiquer que le livre est emprûnté(variable borrow).
	FILE *f;
	int i=0;
    	f = fopen("liste_livre.txt", "w");
    	if(f==NULL){
        	printf("Erreur lors de l'ouverture d'un fichier");
        	exit(1);
    	}
	while(i<nmb_livre){
		fprintf(f,"%s %s %s %s %s %s %s %s\n",tab[i].titre,tab[i].auteur,tab[i].cat, 		tab[i].borrow,tab[i].owner,tab[i].h,tab[i].min,tab[i].sec) ;
	i++;
	}
	fclose(f);
}


int emp_livre(User tab[],int place,Livre tab_livre[],int nmb_livre){
// Fonction permettant d'emprunter un livre, d'afficher l'emprunteur et l'heure d'emprunt.
    	FILE *f;
	int a=0;
	int h, min, sec;
    	f = fopen("liste_livre.txt", "a+");
    	if(f==NULL){
        	printf("Erreur lors de l'ouverture d'un fichier");
        	exit(1);
    	}
	for(int i=0;i<=nmb_livre;i++){
		if(tab_livre[i].borrow[0]=='1'){
		printf("%d : %s\n",i,tab_livre[i].titre);
		}	
	}
   	printf("Quel numero de livre voulez vous emprunter ? \n");
   	char numero[3];
   	scanf("%s",numero);
        
   	strcpy(tab_livre[atoi(&numero)].owner,tab[place].login);
    
	tab_livre[atoi(&numero)].borrow[0]='2';


  	printf("%s a emprunté %s\n",tab_livre[atoi(&numero)].owner,tab_livre[atoi(&numero)].titre);
	
	timee(&h,&min,&sec);
	printf("emprunté a %d:%d:%d\n",h,min,sec);
	sprintf(tab_livre[atoi(&numero)].h,"%d",h);
	sprintf(tab_livre[atoi(&numero)].min,"%d",min);
	sprintf(tab_livre[atoi(&numero)].sec,"%d",sec);
        
        sleep(2);
        //printf("on entre dans enregistrelivre \n");
	enregistrelivre(tab_livre,nmb_livre);
        //printf("on revient dans emplivre \n");
        
	fclose(f);
	
	/*heure_max_restitution(&h,&min,&sec);
	printf("DEBUG : etape1\n");
	printf("%d\n",tab[i].role);
	if(strcmp (u.role,"1") == 0){
		sec=sec+120;
		printf("%d\n",sec);
		printf("Heure de restitution maximale %d:%d:%d\n",h,min,sec);
	}

	else if(strcmp (u.role,"2") == 0){
		printf("DEBUG : etape2\n");
		sec=sec+180;
		printf("%d\n",sec);
		printf("Heure de restitution maximale %d:%d:%d\n",h,min,sec);
	}  */
	
    	
	/*
        do{
		printf("Retour menu bibliotheque ? Tapez 0\n");
		printf("Emprunter un nouveau livre ? Tapez 1\n");
    		char retour[2];
    		scanf( "%s",&retour);
    		if (strcmp (&retour,"0") == 0){
		a=1;
    		// retour menu biblio
    		biblio(tab,place);
    		}
    		else if(strcmp (&retour,"1") == 0){
		a=1;
		emp_livre(tab,place,tab_livre,nmb_livre);
		}
	}while(a==0); */
			
}

void timee(int* h,int* min,int* sec){
// Procédure permettant de récupérer l'heure
	time_t now;
	//renvoie l'heure actuelle
	time(&now);
	//convertir au format heure locale
	struct tm* local = localtime(&now);
	*h=local->tm_hour;
	*min=local->tm_min;
	*sec=local->tm_sec;
	

} 

void heure_max_restitution(int* h, int* min, int* sec){
// Procédure permettant de récupérer l'heure
// Cette procédure sera utiliser pour le calcul de l'heure max à laquelle l'utilisateur doit rendre son livre. 
	time_t now;
	//renvoie l'heure actuelle
	time(&now);
	//convertir au format heure locale
	struct tm* local = localtime(&now);
	*h=local->tm_hour;
	*min=local->tm_min;
	*sec=local->tm_sec;
	
	
}



int ajout_livre(User tab[],int place){ 
// Fonction permettant d'ajouter un livre 
// Cas professeur (voir menu biblio).
	affichage();
    
	Livre new;
	FILE *f;
 	f = fopen("liste_livre.txt", "a");

    if(f==NULL){
        printf("Erreur lors de l'ouverture d'un fichier");
        exit(1);
    }

    printf("Entrez le titre du livre : \n");
    scanf( "%s", &new.titre);

    printf("Entrez l'auteur du livre : \n");
    scanf( "%s", &new.auteur);
  
    printf("Entrez la categorie du livre : \n");
    scanf( "%s", &new.cat);

	//new.borrow[0]='1';
        int toto=1;
	
    fprintf(f, "%s %s %s %d %s %s %s %s\n", new.titre, new.auteur,new.cat,toto,new.owner,new.h,new.min,new.sec);

    fclose(f);
    
    printf("Ajouter un autre livre ? Tapez 1\n");
    printf("Retour menu bibliotheque ? Tapez 0\n");
    char retour[1];
    scanf( "%s",retour);
    if (strcmp (retour,"1") == 0) {
    // retour menu biblio
    ajout_livre(tab,place);
    }
    if (strcmp (retour,"0") == 0) {
    // retour menu biblio
    biblio(tab,place);
    }
    return 0;
}

void rest_livre(User tab[],int place, int nmb_livre){
// Procédure permettant de restituer un livre.
	Livre* tab_livre;	
	int c;
	liste_livre_emp(tab,place,nmb_livre);
	tab_livre=recuplivre(&nmb_livre);
	printf("entrez le numéro du livre que vous voulez rendre\n");
	scanf("%d",&c);
	tab_livre[c].borrow[0]='1';
	printf("%s rendu !\n",tab_livre[c].titre);
	enregistrelivre(tab_livre,nmb_livre);
}


void liste_livre_emp(User tab[],int place, int nmb_livre){
// Procédure permettant d'afficher la liste des livres empruntés par un user.
Livre* tab_livre;
tab_livre=recuplivre(&nmb_livre);
printf("Vos livres empruntés :\n");
for(int i=0;i<nmb_livre;i++){
	if(strcmp(tab_livre[i].owner,tab[place].login)==0 && atoi(tab_livre[i].borrow)==2){
		printf("%d : %s\n",i,tab_livre[i].titre);
	}
}

}



Livre* recuplivre(int *nmb_livre){
// Fonction permettant de récupérer les caractéristiques et informations sur les livres.
	
	Livre* tab = NULL;
	FILE* save = NULL;
	save=fopen("liste_livre.txt","r");
	if(save == NULL){
		printf("Ouverture du fichier impossible\n");
		//printf("code d'erreur = %d\n", errno);
		exit(1);
	}
	
	char lignelivre[1000];
	while(fgets(lignelivre,999,save)!=NULL){
		*nmb_livre=*nmb_livre+1;
	}
	tab = malloc(*nmb_livre * sizeof(Livre));

	rewind(save);

	int i=0;

	while(fgets(lignelivre,999,save)!=NULL){

                //printf("%s",lignelivre);

		sscanf(lignelivre,"%s %s %s %s %s %s %s %s",tab[i].titre,tab[i].auteur,tab[i].cat, tab[i].borrow,tab[i].owner,tab[i].h,tab[i].min,tab[i].sec) ;
	i++;

	
	}
	
	fclose(save);
	return tab;
}
