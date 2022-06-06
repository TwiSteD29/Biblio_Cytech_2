#include"menu_biblio.h"


int main(){
// Programme principal
        affichage();
	User u;
        User newuser;
	User tab[TAILLE];
	char sel[2];
	int nmb_user=0;
	int place;
			
	printf("Bienvenue dans la bibliothèque Cytech\n");
	do{
		printf("1. Se connecter.\n");
		printf("2. Nouvel utilisateur.\n");
		printf("3. Quitter.\n");
		printf("Sélectionner 1,2 ou 3 selon votre choix.\n");	
		scanf("%s",&sel);
	
		if(strcmp(sel,"1") == 0){			
			User* tab=saveUser(&nmb_user);
			place=login(tab);
			sleep(1);
			
                        
			if(place>=0){
                        	biblio(tab,place,nmb_user);
			}
			else{
				constructUser(tab);	
			}
		}	

		else if(strcmp(sel,"2") == 0){
			newuser=constructUser(tab);
			printf("\n\n");
			displayUser(newuser);
			sleep(5);
			User* tab=saveUser(&nmb_user);
			main();
                        
                        if(place>=0){
                        	biblio(tab,place,nmb_user);
			}
			else{
				constructUser(tab);	
			}
                        }
	}while(strcmp(sel,"3") != 0 );
        printf("Au revoir ...\n");
		
}
