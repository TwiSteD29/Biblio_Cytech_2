#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void timee(int* h,int* min,int* sec){
	int h, min, s;
	time_t now;
	//renvoie l'heure actuelle
	time(&now);
	//convertir au format heure locale
	printf("Aujourd'hui il est : %s",ctime(&now));
	struct tm* local = localtime(&now);
	h=local->tm_hour;
	min=local->tm_min;
	s=local->tm_sec;
	
	//printf("L'heure : %02d:%02d:%02d\n",h,min,s);
	//afficher la date courante
	//printf("La date : %02d/%02d/%d\n",jour,mois,an);
} 

void heure_max_restitution(int* h, int* min, int* sec){
	int h, min, s;
	time_t now;
	//renvoie l'heure actuelle
	time(&now);
	//convertir au format heure locale
	printf("Aujourd'hui il est : %s",ctime(&now));
	struct tm* local = localtime(&now);
	h=local->tm_hour;
	min=local->tm_min;
	s=local->tm_sec;
	
	//printf("L'heure : %02d:%02d:%02d\n",h,min,s);
	//afficher la date courante
	//printf("La date : %02d/%02d/%d\n",jour,mois,an);

}
