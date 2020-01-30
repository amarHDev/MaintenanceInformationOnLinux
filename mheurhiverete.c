
	#include<stdio.h>
	#include<stdlib.h>
	#include<unistd.h>
	#include <time.h>

	void main(){

	time_t now=time(NULL);
	struct tm local=*localtime(&now);
		
	char dates[30];
	int n;
		
	int mois=local.tm_mon+1;

		     printf("\n             -------------------------------------------\n ");
		     printf("            ¦     Changer l'heure dete et d'hiver     ¦ ");
		     printf("\n             ------------------------------------------- \n\n");

	printf("1-Pour activer l'heure d'été\n");
	printf("2-Pour désactiver l'heure d'été\n\n");
	printf("Faite votre choix : ");
	scanf("%d",&n);

	    if(n==1){
		if(mois<4 || mois>10){ 
			printf("\nVous etes en hiver, l'heure d'ete n'est pas encore arriver \n");
			
		}else{
			sprintf(dates, "%02u:%02u:%02u",local.tm_hour+1,local.tm_min,local.tm_sec); 

			printf("Vous etes en heure d'ete à présent \n");

			execlp("sudo", "date","date" ,"--set" ,dates, NULL);
		}
	    }
	    if(n==2){
		if(mois>3 && mois<9 ){ 
			printf("\nVous etes en ete, l'heure d'hiver n'est pas encore arriver \n");
			
		}else{
			sprintf(dates, "%02u:%02u:%02u",local.tm_hour-1,local.tm_min,local.tm_sec); 
			printf("Vous etes en heure d'hiver à présent\n");
			
			execlp("sudo", "date","date" ,"--set" ,dates, NULL);
		}
	    }
     }

