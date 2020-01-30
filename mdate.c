	
	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <time.h>
	#include <string.h>
	#include <errno.h>

	void main(){

		time_t now=time(NULL);

		struct tm local=*localtime(&now);


		 char dates[15],jr[30],ann[30];
		 char Newmois[10];
		 int n,mois,jour,annee;

		 const char * NomMois[] = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"}; 
	    
	     printf("\n             ---------------------------\n ");
	     printf("            ¦     Changer la date     ¦ ");
	     printf("\n             --------------------------- \n\n");
		
	     
	     do{

	     	printf("- Veuillez saisir le jour le mois(en chiffre) et l'année :\n");

		time_t begin = time( NULL );

		     do{
		      
			scanf("%d%d%d",&local.tm_mday,&mois,&local.tm_year);
		 	sprintf(jr,"%02u",local.tm_mday);
                        sprintf(ann,"%04u",local.tm_year);

                        jour=atoi( jr );
		        annee=atoi( ann );

			 if(jour <= 0 || jour  > 31){
			  printf("Veuillez saisire l'indice d'un jour valide \n");
		 	 }

			 if(annee < 1900){
			  printf("Veuillez saisire une annee valide \n");
		 	 }

			 if(mois>0 && mois<=12){
			   	strcpy(Newmois, NomMois[mois-1]);
			 }else{
			 	  printf("Ce mois nexiste pas, Veuillez saisire un mois valide :\n");
			 }

		     }while(mois<=0 || mois>12 || jour < 0 || jour  > 31 ||  annee < 1900);

	      time_t end = time( NULL);
	      int secondes = difftime( end, begin );

	      sprintf(dates, "%d %s %d %d:%d",local.tm_mday,Newmois,local.tm_year,local.tm_hour,local.tm_min); 
	   
	      printf("\n\n- Date modifié après %d' seconde ", secondes);
	     
	
	      n= execlp("sudo", "date","date" ,"--set" ,dates, NULL);
	      
	      if (n == -1){

		   fprintf(stdout, " \n\n Attention Erreur!!!\n le code de votre erreur est ERRNO[%d]\n", errno);
		   perror(" Nom de l'erreur");
		   //printf("Nom de l'erreur");puts( strerror( errno ) );
		   printf("\n");
	      }
   
	 }while(n == -1);
   
       }
