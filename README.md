# Linux : syscall about Date and time
This is a programme which displays a menu where there are several options to change the information relating to the date and time of the linux system

# Usage
Firstly you have to compile all the .c files like that :
Open Terminal 
Go to the directory where there are the files and type theses commands 
```
#Compile all files

$gcc -o main main.c   
$gcc -o afficher afficher.c 
$gcc -o mdate mdate.c 
$gcc -o mfhoraire mfhoraire.c
$gcc -o mheur mheur.c
$gcc -o mheurhiverete.c  

```
To run the program 
```
$./main

```

# Documentation
In what follows we will see how to obtain and modify among other things:

- The date and / or time. (with 2 different ways).
- toggle between summer and winter time.
- Change the time zone of our system.

Our program is thus divided into several parts (sub-programs):

mdate.c / mheur.c / mdate/h.c / mfhoraire.c / afficher.c / mheurhiverete.c

These sub-programs will be called via a main program " main.c "







