#include"fonctions_utilisateur.h"


int affichage(){ 
// Fonction affichage.
	system("clear") ;
	printf("************************************************\n");
	printf("        APPLICATION BIBLIOTHEQUE CY TECH        \n");
	printf("************************************************\n");
}


void enregistreuser(User tab[],int nmb_user){
// Fonction permettant d'ajouter dans le fichier save_user le fait que l'utilisateur n'a plus le droit d'emprunter un livre.
// variable blacklist
	FILE *f;
	int i=0;
    	//f = fopen("save_user.txt", "w");
	f = fopen("save_user.txt", "r+");
    	if(f==NULL){
        	printf("Erreur lors de l'ouverture d'un fichier");
        	exit(1);
    	}
	while(i<nmb_user){
		fprintf(f,"%s %s %s %s %s %s %s\n",tab[i].prenom, tab[i].nom , tab[i].login , tab[i].password,
tab[i].role,tab[i].nombre_livre,tab[i].blacklist) ;
		i++;
	}
	fclose(f);
}


User constructUser(User tab[]){
// Fonction permettant de créer un compte et d'écrire les informations dans le fichier save_user contenant les informations de tous les utilisateurs.
	User u;
	FILE* save;
	save=fopen("save_user.txt","a");
	rewind(save);
	char ep[2];
	int a=0;
	do{
		printf("Si vous êtes un étudiant tapez 1 ou si vous êtes un professeur tapez 2 ?\n");
		scanf("%s",&u.role);

		if(strcmp (u.role,"1") == 0){
			a=1;
		}
		else if(strcmp(u.role,"2") ==0){
			a=1;
		}
 
	}while(a==0);
	

        do{
	printf("Quel est vôtre prénom? (max 15 caractères)\n");
	scanf("%s",u.prenom);
        }while (strlen (u.prenom) > 15);
	
        do{
	printf("Quel est votre nom? (max 15 caractères)\n");
	scanf("%s",u.nom);
        }while (strlen (u.nom) > 15);
	
        do{
	printf("Veuillez renseigner votre nom d'utilisateur (max 15 caractères)\n");
	scanf("%s",u.login);
	
		char ligneUser[1000]; 
		u.nombre_livre[0]='0';
         	int i=0;
         	int y=0;
         	do{
          		i=0;
          		y=0;
         		FILE* f;
         		f=fopen("save_user.txt","r");  
         		while (fgets(ligneUser,TAILLE,f)!=NULL){
          			sscanf(ligneUser,"%s %s %s %s %s %s %s",tab[i].prenom, tab[i].nom , tab[i].login , tab[i].password, tab[i].role,tab[i].nombre_livre,tab[i].blacklist) ;
          			if (strcmp(u.login,tab[i].login) != 0) {
          				
         			}
          			if (strcmp(u.login,tab[i].login) ==0) {
          				printf("Nom d'utilisateur déjà utilisé.\n");
          				y++;
          			}
         		}
         		if (y==0) {
         			printf("Nom d'utilisateur accepté.\n");
         			break;
          		} 
         		if (y>=1){ 
          			printf("Veuillez saisir un autre nom d'utilisateur.\n");
          			scanf("%s",u.login);
         		}
        		fclose(f);  
        	}while (y>0) ;
	  	
	}while (strlen (u.login) > 15 );
        
  
        do{
	printf("Veuillez renseigner votre password (max 15 caractères)\n");
	scanf("%s",u.password);
        }while (strlen (u.password) > 15);

        int titi=1;
        u.blacklist[0]='1';
	fprintf(save,"%s %s %s %s %s %s %d \n",u.prenom,u.nom,u.login,u.password,u.role,u.nombre_livre,titi);	
	fclose(save);
    	return u;

	
}	

void displayUser(User u){ 
// Procédure d'affichage des informations d'un utilisateur.
	printf("Voici un récapitulatif de vos informations:\n\n");
	if(u.role==1){
        	printf("Vous êtes un étudiant.\n");
	}
	else if(u.role==2){
        	printf("Vous êtes un professeur.\n");
        }
	printf("Votre prénom est : %s\n",u.prenom);
	printf("Votre Nom de famille est : %s\n",u.nom);
	printf("Votre login est : %s\n",u.login);
	printf("Votre password est : %s\n",u.password);
	printf("\n");
	printf("Votre compte a été créé !\nBienvenue %s\n",u.prenom);
}




User* saveUser(int *nmb_user){
// Fonction permettant de récupérer les informations des utilisateurs.
	User* tab = NULL;
	FILE* save = NULL;
	save=fopen("save_user.txt","r");
	if(save == NULL){
		printf("Ouverture du fichier impossible\n");
		printf("code d'erreur = %d\n", errno);
		exit(1);
	}

	char ligneUser[1000];
	while (fgets(ligneUser,999,save)!=NULL){
	    *nmb_user=*nmb_user+1;
	}
	
	tab = malloc(*nmb_user * sizeof(User));

	rewind(save);
        
        int i=0;
       	while (fgets(ligneUser,999,save)!=NULL){
                sscanf(ligneUser,"%s %s %s %s %s %s %s",tab[i].prenom,tab[i].nom , tab[i].login , tab[i].password, tab[i].role,tab[i].nombre_livre,tab[i].blacklist) ;
		i++;
        }
	fclose(save);
	return tab;
}




int login(User tab[]){
// Fonction permettant à un utilisateur de se connecter.
	char password[50];
	char login[50];
	int trouver=0;
	char a[2];
	FILE* save;	
	save=fopen("save_user.txt","r");
	rewind(save);

	printf("Veuillez renseigner votre nom d'utilisateur\n");
	scanf("%s",login);
	for(int i=0;i<=TAILLE;i++){
                	
		if(strcmp(login,tab[i].login) == 0 ){	
			trouver=1;
				
			printf("Bienvenue %s\n",tab[i].prenom);
			printf("Quel est votre password ? (3 tentatives possibles)\n");
			scanf("%s",password);
	
			
                        if(strcmp(password,tab[i].password)==0){
			printf("Password correct\n");	
			return i;
			
			}
			else{
				printf("Password incorrect\n");
				printf("Veuillez réessayer\n");
				scanf("%s",password);
				if(strcmp(password,tab[i].password)==0){
					printf("Password correct\n");	
					return i;
				}
				else{
					printf("Password incorrect\n");
					printf("Veuillez réessayer\n");
					scanf("%s",password);
					
					if(strcmp(password,tab[i].password)==0){
						printf("Password correct\n");	
						return i;
					}
					else{
						printf("Password incorrect\n");
						printf("Veuillez recréer un compte\n");
						return (-1);       
				        }
				}
			} 
                        			
		}
                

               
        
        }

	if(trouver!=1){

	   do{
		printf("Nom d'utilisateur inexsistant ou incorrect\n");
		printf("Voulez vous réessayer(1) ou créer un compte (2) ?\n");
		scanf("%s",&a);
		while(strcmp(a,"1") != 0 && strcmp(a,"2") !=0){	 
			printf("Veuillez saisir 1 ou 2\n");
			scanf("%s",&a);
		}
		if(a[0]=='1'){
			printf("Veuillez renseigner votre nom d'utilisateur\n");
			scanf("%s",login);
			for(int i=0;i<=TAILLE;i++){	
			   if((strcmp(login,tab[i].login))==0){	
				trouver=1;	
				printf("Bienvenue %s\n",tab[i].login);
				printf("Quel est votre password ?\n");
				scanf("%s",password);
				
				if(strcmp(password,tab[i].password)==0){
					printf("Password correct\n");	
				}
				else{
					printf("Password incorrect\n");
					printf("Veuillez réessayer\n");
					scanf("%s",password);
					if(strcmp(password,tab[i].password)==0){
						printf("Password correct\n");	
					}
					else{
						printf("Password incorrect\n");
						printf("Veuillez réessayer\n");
						scanf("%s",password);
					
						if(strcmp(password,tab[i].password)==0){
							printf("Password correct\n");	
						}
						else{
							printf("Password incorrect\n");
							printf("Veuillez recréer un compte\n");
                                                        constructUser(tab);        
				        	}
					}
				}			
			}
		}
		}
		else if(a[0]=='2'){
			constructUser(tab);
			trouver=1;
			  
		}
		
		
	   }while(trouver!=1);	
		
	}        	
}



