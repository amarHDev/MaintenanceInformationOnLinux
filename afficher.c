		
	#include<stdio.h>
	#include<stdlib.h>
	#include<unistd.h>
	#include <time.h>

	int main(){

	char format[128];

	time_t temps=time(NULL);
	struct tm d,t;
	t=*localtime(&temps);
	d=*gmtime(&temps);

	int choix;

	printf("\n1-Pour voir l'heure GMT \n");
	printf("2-Voir quelle est le jour de la semaine \n");
	printf("3-Voir le format de la date \n");
	printf("4-Nombre de jours ecoulés dans l'année\n");
	printf("\nfaites votre choix : \n");
	scanf("%d",&choix);

	switch (choix){

	  case 1: 
		printf("L'heure GMT est : %d:%d:%d \n", d.tm_hour, d.tm_min,d.tm_sec);
	  break;

	  case 2: 
                if(t.tm_wday == 1){
			printf("On est dans le %d er jour de la semaine\n",t.tm_wday);
		}else{
	  		printf("On est dans le %d eme jour de la semaine\n",t.tm_wday);
		}
	  break;

	  case 3: 
		strftime(format, 128, "%A %d-%B-%Y; %H:%M:%S  TZ= %Z \n", &t);
		printf("Mon format personnel est : ");
	  	printf("%s",format); 
	  break;

	  case 4:
		printf("Le nombre de jours ecoulés dans l'année est %d\n",t.tm_yday); 
	  break;

	}
	  

	}
