	
	#include<stdio.h>
	#include<unistd.h>
	#include <time.h>

	void main(){

	int choix = 0;// choix

	const char * NomJourSemaine[] = {"Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi"}; 
	const char * NomMois[] = {"janvier", "fevrier", "mars"     , "avril"  , "mai"     , "juin"    , 
				          "juillet", "aout"   , "septembre", "octobre", "novembre", "decembre"}; 

	/* lire l'heure courante */
	time_t temp=time(NULL);  

	/* la convertir en heure locale */
	struct tm * now=localtime(&temp); 
		  

		printf("\n             ---------------------------\n ");
		printf("            ¦         BIENVENU        ¦ ");
		printf("\n             --------------------------- \n\n");
		/* Affiche la date et l'heure courante (format francais) */ 
		printf("\n- Nous sommes %s, ", NomJourSemaine[now->tm_wday]); 
		printf("le %02u %s %04u, ", now->tm_mday, NomMois[now->tm_mon], 1900 + now->tm_year); 
		printf("et il est %02uh %02umin %02usec.\n\n", now->tm_hour, now->tm_min, now->tm_sec);
		
	  

	printf("1- Changement du fuseau horaire \n");
	printf("2- Changement de la date\n");
	printf("3- Changement de l'heure\n");
	printf("4- Changement de l'heure d'été/hiver\n");
	printf("5- Afficher plus d'infomations\n\n");

	
        do{
	  printf("Faite votre choix: ");
	  scanf("%d", &choix);
		if(choix<1 || choix>6){
			printf("Se menu n'existe pas, veuillez réessayer\n");
		}
        }while(choix<1 || choix>6);
	

	switch(choix){

	case 1:
	execlp("./mfhoraire","./mfhoraire",NULL);
	break;

	case 2:
	execlp("./mdate","./mdate",NULL);
	break;
	
	case 3:
	execlp("./mheur","./mheur",NULL);
	break;
	
	case 4:
	execlp("./mheurhiverete","./mheurhiverete",NULL);
	break;
	
	case 5:
	execlp("./afficher","./afficher",NULL);
	break;
	
   }
}
