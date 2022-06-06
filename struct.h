typedef struct{ //Structure informations utilisateur
	char role[2];
	char nom[15];
	char prenom[15];
	char login[15];
	char password[15];
	char nombre_livre[2];
	char blacklist[2];
}User;

typedef struct{ //structure caractéristiques et informations livre
	char titre[50];
	char auteur[50];
	char borrow[2];
	char owner[15];
	char cat[50];
	char h[3];
	char min[3];
	char sec[3];
}Livre;



