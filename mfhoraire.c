	
	#include<stdio.h>
	#include<stdlib.h>
	#include<unistd.h>
	#include <time.h>
	#include <string.h>
	int main(){

	char chaine[80];
	int  d=0,res;

        strcat(chaine,"timedatectl set-timezone ");

        printf("\n             -------------------------------\n ");
	printf("            ¦   Changer la fuseau horaire  ¦ ");
	printf("\n             ------------------------------- \n\n");

	printf("- Votre date/heure liée à votre fuseau horaire actuelle est :\n");

	system("date");

	printf("\n- Pour changer le fuseau horaire tappez sur 1,");
	printf(" pour quitter tappez sur 2 :\n");

        time_t begin = time( NULL );
	
	do{
	    printf("Faite votre choix: ");
	    scanf("%d",&d);
	    if(d==2){

		 printf("Sortie du programme ...\n");
		 return 0;
	
	    }else if(d==1){
                 printf("\nChoisissez la destination que vous voulez :\n");
                 printf(" 1-Kenya/Nairobi\n 2-Colombie/Bogota\n 3-Algerie/Alger\n 4-Japan/Tokyo\n");
                 printf(" 5-Portugal/Lisbonne\n 6-America/Denver\n 7-Allemagne/Berlin\n 8-Finlande/Helsinki\n");
  		 printf(" 9-Russie/Moscou\n 10-Norvège/Oslo\n 11-Suede/Stockholm\n 12-Brésil/Rio de Janeiro\n");
   
	do{
	  printf("\nFaite votre choix: ");
	  scanf("%d", &res);
		if(res<1 || res>12){
			printf("Se menu n'existe pas, veuillez réessayer\n");
		}
        }while(res<1 || res>12);

	switch(res){
	  case 1:
		 strcat(chaine,"Africa/Nairobi");break;  	
	  case 2:
		 strcat(chaine,"America/Bogota"); break;   
          case 3:
		 strcat(chaine,"Africa/Algiers"); break;   
	  case 4:
		 strcat(chaine,"Asia/Tokyo"); break; 		
	  case 5:
		strcat(chaine,"Europe/Lisbon"); break;
 	  case 6:

		strcat(chaine,"America/Denver"); break;
	  case 7:
		strcat(chaine,"Europe/Berlin"); break;	
	  case 8:
		strcat(chaine,"Europe/Helsinki"); break;	
	  case 9:
		strcat(chaine,"Europe/Moscow"); break;
	  case 10:
		strcat(chaine,"Europe/Oslo"); break;
	  case 11:
		strcat(chaine,"Europe/Stockholm"); break;	
	  case 12:
		strcat(chaine,"America/Sao_Paulo"); break;
	  }         
	}else{
		 printf(" Valeur tapper incorrecte, veuillez réessayer :\n");
	    }
	}while(d!=1 );
		if(res>0 && res<13 ){
		system(chaine);

		time_t end = time( NULL);
		int secondes = difftime( end, begin );

		printf("\n\n- Fuseau horaire modifié après %d' secondes :\n", secondes);
		printf("Votre nouvelle date/heure liée à votre fuseau horaire actuelle est : \n");
		system("date");
	 }
     }
