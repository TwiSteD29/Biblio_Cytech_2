all : biblio_cytech

fonctions_livre.o : fonctions_livre.c fonctions_livre.h fonctions_utilisateur.h
			gcc -o fonctions_livre.o -c fonctions_livre.c

fonctions_utilisateur.o : fonctions_utilisateur.c fonctions_utilisateur.h struct.h
			gcc -o fonctions_utilisateur.o -c fonctions_utilisateur.c


menu_biblio.o : menu_biblio.c menu_biblio.h fonctions_livre.h
			gcc -o menu_biblio.o -c menu_biblio.c

main.o : main.c menu_biblio.h 
	gcc -o main.o -c main.c

biblio_cytech : main.o fonctions_livre.o fonctions_utilisateur.o menu_biblio.o struct.h
	gcc main.o fonctions_livre.o fonctions_utilisateur.o menu_biblio.o -o biblio_cytech
