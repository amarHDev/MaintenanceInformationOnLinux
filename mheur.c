	
	#include <unistd.h>
	#include <stdio.h>
	#include <time.h>
	#include <errno.h>
	#include <stdlib.h> //atoi
	int main(){

	time_t now=time(NULL);
	struct tm local=*localtime(&now);

	char dates[30],heur[30],min[30];
	int n,heure,minute;

	     printf("\n             ---------------------------\n ");
	     printf("            ¦     Changer la l'heur   ¦ ");
	     printf("\n             --------------------------- \n\n");
		
	     
	do{

	    printf("- Veuillez saisir l'heure et la minute : \n");
	
	    time_t begin = time( NULL );

		do{

	          scanf("%d%d",&local.tm_hour,&local.tm_min);
		  sprintf(heur, "%02u",local.tm_hour);
                  sprintf(min, "%02u",local.tm_min);

                  heure=atoi( heur );
		  minute=atoi( min );

		  if(( heure < 0 || heure >= 24) && (minute < 0 || minute  >= 60)){
		       printf("Veuillez saisire une heure et une minute valide :\n");
		  }else if(minute < 0 || minute  >= 60){
			  printf("Veuillez saisire une minute valide :\n");

		 	 }else if(heure < 0 || heure >= 24){
			    printf("Veuillez saisire une heure valide :\n");
		 	 }
		  

		}while(heure < 0 || heure >= 24 || minute < 0 || minute  >= 60);


	     
 	    time_t end = time( NULL);
	    int secondes = difftime( end, begin );

	     printf("\n\n- L'heure modifié après %d' seconde ", secondes);
	     sprintf(dates, "%02u:%02u:%02u",local.tm_hour,local.tm_min,local.tm_sec); 
	     printf("\n");
	     
	    
	    n = execlp("sudo", "date","date" ,"--set" ,dates, NULL);
	    
         
	      
	      if (n == -1){

		   fprintf(stdout, " \n\n Attention Erreur!!!\n le code de votre erreur est ERRNO[%d]\n", errno);
		   perror(" Nom de l'erreur");
		   printf("\n");
	      }

	
              
	 }while(n == -1);
	   
	    
	    
	}
