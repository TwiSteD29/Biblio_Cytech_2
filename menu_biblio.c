#include"menu_biblio.h"

int biblio(User tab[],int place,int nmb_user){
// Fonction qui affiche le menu de la bibliothèque une fois le user connecté.
	system("clear") ;
	User u;
	char c;
	int a;
        FILE* save;
	Livre* tab_livre;
	int nmb_livre=0;
	int h,min,sec,seclivre,res;
	save=fopen("save_user.txt","r");        
        int choix=0;
        do {
       	affichage();
        printf("1. Liste des livres de la bibliotheque.\n");
        printf("2. Rechercher un livre.\n");
        printf("3. Liste des livres empruntés.\n");
        printf("4. Emprunter un livre.\n");
        printf("5. Restituer un livre.\n");
        printf("6. Ajouter un livre. (cas professeur)\n");
        printf("7. Quitter.\n");
        printf("votre choix?\n");	
        scanf("%d",&choix);
        // attention si choix est une lettre ca fonctionne pas ...        
        }while (choix <1 || choix >7);  
 
        switch ( choix )
        {
         case 1:
          {     
          // liste_livre_biblio(tab,place);
          liste_livre_biblio(tab,place,nmb_livre);
          break;
          }
         case 2:
          {
          recherche_livre();
          break;
          }
         case 3:
          {
          	liste_livre_emp(tab,place,nmb_livre);
		printf("tapez 1 pour retourner au menu  \n");
			scanf("%s",&c);
			if(c=='1'){
			biblio(tab,place,nmb_user);
			}
			else{
			biblio(tab,place,nmb_user);		
			}
          break;
          }
         case 4:
          {	
             
		//printf("on rentre dans le choix 4\n");
                tab_livre=recuplivre(&nmb_livre);
                //printf("on passe recuplivre\n");
		for(int i=0;i<nmb_livre;i++){
                //printf("on entre dans la boucle for et nombre livre = %d\n" ,nmb_livre );
                //        sleep(1) ;
                          
                         // printf("valeur 1 : %s\n" ,tab_livre[i].owner) ; // =nom user(login dans fichier livre)
                         // printf("valeur 2 : %s\n" ,tab[place].login) ; // =nom user(login)
                          
                          
                          
                         // sleep(2);
					if(strcmp(tab_livre[i].owner,tab[place].login)==0 && atoi(tab_livre[i].borrow)==2){
                                                //printf("on recupere heure\n");
						timee(&h,&min,&sec);
						sec+=min*60 +h*60*60;
						seclivre=atoi(tab_livre[i].sec)+atoi(tab_livre[i].min)*60 +atoi(tab_livre[i].h)*60*60;		
						res=sec-seclivre;
						if(atoi(tab[place].role)==1){
							
							if(res>120){
								tab[place].blacklist[0]='2';
							}
						}
						else if(atoi(tab[place].role)==2){
							if(res>180){
								tab[place].blacklist[0]='2';
							}
						}
                                                //printf("on entre dans enregistreuser\n");
						enregistreuser(tab,nmb_user);
                                                //printf("on est sorti de enregistreuser\n");
					}
		}
		if(atoi(tab[place].role)==1 ){
                        //printf("on est etudiant \n");
                        //sleep(2) ;
			if (atoi(tab[place].blacklist)==2){
 
				printf("Vous avez oublié de rendre un livre, vous ne pouvez donc plus en emprunter.\n");
				sleep(3);
				biblio(tab,place,nmb_user);
			}
			else if(atoi(tab[place].nombre_livre)<3){
                                //printf("on entre dans emp_livre\n");
                                sleep(2);
				emp_livre(tab,place,tab_livre,nmb_livre);
				a=atoi(tab[place].nombre_livre);
				a=a+1;
                                printf("nombre de livre : %d \n ",a);
                                sleep(2);
				sprintf(tab[place].nombre_livre,"%d",a);
				enregistreuser(tab,nmb_user);
				biblio(tab,place,nmb_user);
			}
			else{
				printf("Vous avez atteint votre maximum de livre emprunté ! retour au menu ...\n");			
				sleep(3);
				biblio(tab,place,nmb_user);
			}
		}
		else if(atoi(tab[place].role)==2){
                        // printf("on est prof \n");
                       // sleep(2) ;
			if (atoi(tab[place].blacklist)==2){
                                
				printf("Vous avez oublier de rendre un livre vous ne pouvez donc plus en emprunter.\n");
                                sleep(3);
				biblio(tab,place,nmb_user);
			}
			else if(atoi(tab[place].nombre_livre)<5){
                                                //printf("on entre dans emp_livre\n");
                                                //sleep(2);
						emp_livre(tab,place,tab_livre,nmb_livre);
						a=atoi(tab[place].nombre_livre);
                                                a=a+1;
                                                printf("nombre de livre : %d \n ",a);
                                                sleep(2);
						sprintf(tab[place].nombre_livre,"%d",a);
						enregistreuser(tab,nmb_user);
						biblio(tab,place,nmb_user);
			}
			else{
				printf("Vous avez atteint votre maximum de livre emprunté ! retour au menu ...\n");		
				sleep(3);
				biblio(tab,place,nmb_user);
			}
		}

		
          break;
          }
         case 5:
          {
		if(atoi(tab[place].nombre_livre)>0){
          			rest_livre(tab,place,nmb_livre);
				a=atoi(tab[place].nombre_livre);
				a=a-1;
				sprintf(tab[place].nombre_livre,"%d",a);
				enregistreuser(tab,nmb_user);
				sleep(2);
				biblio(tab,place,nmb_user);
		}
		else{
			printf("vous n'avez pas de livres à rendre ! retour au menu...\n");
			sleep(2);
				biblio(tab,place,nmb_user);
		}
          break;
          }
         case 6:
          {
		
		sleep(1);
		if(atoi(&tab[place].role) == 1){
			printf("En tant qu'étudiant vous n'avez pas accès à cette fonctionnalité.\n");	
			sleep(2);
			biblio(tab,place,nmb_user);
		}
				
		else if(atoi(&tab[place].role)==2){
		ajout_livre(tab,place);
		}
		
		break;
          }
         case 7:
          {
          printf("Au revoir ...\n");
          sleep (2);
          main();
          }
          /*default:
          {
          printf("\n choix impossible \n");
          sleep(2);
          return(0);
          } */

  
       } 
 
    

exit (0);
}
