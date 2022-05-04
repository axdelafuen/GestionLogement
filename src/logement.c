#include <stdio.h>
#include "errno.h"
#include "stdlib.h"
#include <string.h>
#include "logement.h"

/**
 *\brief Il s'agit de la fonction permettant de charger les logements du fichiers "logements.txt" dans un tableau.
 *\param tLog est un tableau de la strcture Logement
 *\taillemax est la taille que doit faire le tableau (il s'agit du nombre de lignes du fichier "logement.txt")
 *\return 0 si ouverture réussis, -1 sinon
 *\author DE LA FUENTE Axel
  */
int chargerLogement(Logement tLog[], int taillemax){
	FILE *fe;
        fe=fopen("../doc/logement.txt","r");
        if(fe==NULL) { perror("fopen"); exit(errno);}
        int i=0;
        while(feof(fe)==0){
		//if(i>=taillemax){return -1;}
		Logement log;
                log=lireLog(fe);
                tLog[i]=log;
		++i;
        }           
        fclose(fe);
        return 0;
}

/**
 *\brief Il s'agit de la fonction parcourant le fichier "logement.txt afin de déterminer sa taille (nombre de lignes)".
 *\return la taille du fichier (nombre de ligne)
 *\author DE LA FUENTE Axel
  */
int tailleT(){
	int taille=-1;
	FILE *fe;
        fe=fopen("../doc/logement.txt","r");
        if(fe==NULL) { perror("fopen"); exit(errno);}
        while(feof(fe)==0){
		fscanf(fe, "%*d %*s %*s %*d %*d");
		++taille;
	}
	fclose(fe);
	return taille;
}

/**
 *\brief Il s'agit de la fonction permettant de lire les logements du fichier "logement.txt" et de les inclure dans un variable de type Logement et de la renvoyer.
 *\param *fe est un pointeur sur un fichier ouvert en lecture ("logement.txt")
 *\return un Logement remplit par les valeurs du fichier "logement.txt" la où se trouve le curseur
 *\author DE LA FUENTE Axel
  */
Logement lireLog(FILE *fe){
        Logement log;

        fscanf(fe, "%d %s %s %d %d", &log.id, log.adresse, log.type, &log.place, &log.occup);
        return log;
		fclose(fe);
}

/**
 *\brief Il s'agit de la fonction global permettant d'afficher les logements possèdé.
 *\author DE LA FUENTE Axel
  */
void afficherLogement(){
	int taillemax;
	taillemax=tailleT();
	Logement tLog[taillemax];
	chargerLogement(tLog, taillemax);
	
	while(1==1){
		int choix=-1;
		printf("\t ~~~Veuillez renseigner votre choix : ~~~\n");
		printf("\t-1 Afficher selon les places du logement \n");
		printf("\t-2 Afficher selon le type du logement \n");
		printf("\t-3 Afficher sans trier \n");
		printf("\t-0 Quitter\n");
		scanf("%d", &choix);
	
		if(choix==0){return;}
		if(choix==1){trisPlace(tLog, taillemax); break;}
		if(choix==2){trisType(tLog, taillemax); break;}
		if(choix==3){break;}
}
	for(int i=0; i<taillemax; ++i){
                printf("%d \t %s \t %s \t %d\n", tLog[i].id, tLog[i].adresse, tLog[i].type, tLog[i].place);
        }
}

/**
 *\brief Il s'agit de la fonction permettant de trier les logements en fonction de leur nombre de places.
 *\param tLog est un tableau de la structure Logement
 *\param taillemax est la taille que doit faire le tableau (il s'agit du nombre de ligne du fichier "logement.txt")
 *\author DE LA FUENTE Axel
  */
void trisPlace(Logement tLog[], int taillemax){
	int i,j;               
        char change;

        for(i=taillemax;i!=0;--i){
                change=0;
                for(j=0; j<i; ++j){                     
                        if(tLog[j].place>tLog[j+1].place){                                                                
                                Logement tmp;            
                                tmp=tLog[j];                  
                                tLog[j]=tLog[j+1];          
                                tLog[j+1]=tmp;                
                                change=1;                       
                        }      
                }
        }                      
        if(change==0) return; 
}

/**
 *\brief Il s'agit de la fonction permettant de trier les logements en fonction de leur types.
 *\param tLog est un tableau de la structure Logement
 *\param taillemax est la taille que doit faire le tableau (il s'agit du nombre de ligne du fichier "logement.txt")
 *\author DE LA FUENTE Axel
  */
void trisType(Logement tLog[], int taillemax){ 
	int i,j;               
        char change;           

        for(i=taillemax;i!=0;--i){
                change=0;
                for(j=0; j<i; ++j){                     
                        if(strcmp(tLog[j].type,tLog[j+1].type)>0){
				Logement tmp;            
                                tmp=tLog[j];                  
                                tLog[j]=tLog[j+1];          
                                tLog[j+1]=tmp;                
                                change=1;                       
                        }      
                }
        }                      
        if(change==0) return; 
}

/**
 *\brief Il s'agit de la fonction global permettant de supprimer des logements et de mettre a jour le fichier "logement.txt".
 *\author DE LA FUENTE Axel
  */
void suprrLogement(){
	int taillemax;
	taillemax=tailleT();
	Logement tLog[taillemax];
	chargerLogement(tLog, taillemax);

	int num;
	printf("Entrer le numéro du logement que vous souhaitez supprimer : \n");
	scanf("%d", &num);

	int pos;
	pos=rechercheLogement(tLog, taillemax, num);
	if(pos==-1){printf("Il y a une erreur : numéros introuvable\n"); return;}

	suppr(tLog, taillemax, pos);
}

/**
 *\brief Il s'agit de la fonction permettant de rechercher un logement en fonction de son id.
 *\param tLog est le tableau de la structure Logement
 *\param taillemax est la taille que doit faire le tableau (il s'agit du nombre de ligne du fichier "logement.txt")
 *\param num est l'identifiant du logement a modifier
 *\return la place dans le tableau de la où se trouve la valeur cherché.
 *\author JACQUELIN Bastien
  */
int rechercheLogement(Logement tLog[], int taillemax, int num){
	for(int i=0; i<taillemax; ++i){
		if(tLog[i].id==num){
			return i;
		}
	}
	return -1;
}

/**
 *\brief Il s'agit de la fonction permettant de supprimer un logement en fonction de sa position dans le tableau.
 *\param tLog est le tableau de la structure Logement
 *\param taillemax est la taille que doit faire le tableau (il s'agit du nombre de ligne du fichier "logement.txt")
 *\param pos est la position dans le tableau du logement a supprimer
 *\author JACQUELIN Bastien
  */
void suppr(Logement tLog[], int taillemax, int pos){

	for(int i=pos; i<taillemax; ++i){
		tLog[i]=tLog[i+1];
	}
	--taillemax;

	FILE* fe;
	fe=fopen("../doc/logement.txt","w");
        if(fe==NULL) { perror("fopen"); exit(errno);}
	
	for(int i=0; i<taillemax; ++i){
                fprintf(fe,"%d \t %s \t %s \t %d \t%d\n", tLog[i].id, tLog[i].adresse, tLog[i].type, tLog[i].place,tLog[i].occup);}

	fclose(fe);
}

/**
 *\brief Il s'agit de la fonction global permettant d'ajouter un logement dans le tableau et de mettre a jour le fichier "logement.txt"
 *\author DE LA FUENTE Axel
  */
void ajouterLogement(){
	Logement log;
	
	printf("Entrer le numéro du logement : \n");
	scanf("%d", &log.id);
	printf("Entrer l'adresse du logement (ex : 20-rue-mareshall)\n");
	scanf("%s", log.adresse);
	printf("Entrer le type du logement (ex : T1)\n");
	scanf("%s", log.type);
	printf("Entrer le nombre de place maximum du logmement\n");
	scanf("%d", &log.place);
	log.occup=0;
	FILE* fe;
	fe=fopen("../doc/logement.txt","a");
        if(fe==NULL) { perror("fopen"); exit(errno);}
	
	fprintf(fe,"%d \t %s \t %s \t %d \t %d\n", log.id, log.adresse, log.type, log.place, log.occup);
	
	fclose(fe);
}

/**
 *\brief Il s'agit de la fonction global permettant d'afficher les logements spécifique a un type.
 *\author DE LA FUENTE Axel
  */
void afficherType(){
	int taillemax;
	taillemax=tailleT();
	Logement tLog[taillemax];
	chargerLogement(tLog, taillemax);

	char type[3];

	printf("Entrer le type que vous souhaitez voir : \n");
	scanf("%s", type);
		
	for(int i=0; i<taillemax; ++i){
		if(strcmp(tLog[i].type,type)==0){
			printf("%d \t %s \t %s \t %d \n", tLog[i].id, tLog[i].adresse, tLog[i].type, tLog[i].place);
        	}
	}
}

/**
 *\brief Il s'agit de la fonction permettant de chercher les logements vide dans le tableau.
 *\param tLog est le tableau de la structure Logement
 *\param taillemax est la taille du tableau
 *\return la place du tableau, où la valeur cherché est trouvé.
 *\author JACQUELIN Bastien
  */
int rechercheLogVide(Logement tLog[], int taillemax, int *placeCheked){
	int i=*placeCheked;
	while(i<=taillemax){
		i=*placeCheked;
		*placeCheked=*placeCheked+1;
		//printf("\nTABLEAU OCCUPE ? : %d --- place : %d\n\n", tLog[i].occup, i);
		if(tLog[i].occup==0){
			return i;
		}
	}
	return -1;
}

/**
 *\brief Il s'agit de la fonction permettant de mofifier les informations sur un logement.
 *\param tLog est le tableau de la structure Logement
 *\param *champModif est une chaine de caractere comportant les informations a modifier sur le logement
 *\param id est l'identifiant du logement a modifier
 *\author JACQUELIN Bastien
  */
void modifLog(Logement tLog[], char *champModif, int id, int taillemax)
{
	FILE *fl;
	fl=fopen("../doc/logement.txt","w");
	int pos;
	//printf("id: %d", id);
	pos=rechercheLogement(tLog, taillemax, id);
	//printf("pos du log recherché: %d", pos);
	if (strcmp(champModif,"occup")==0)
	{
		tLog[pos].occup=1;
		fprintf(fl,"%d \t %s \t %s \t %d \t %d\n", tLog[pos].id, tLog[pos].adresse, tLog[pos].type, tLog[pos].place, tLog[pos].occup);
	}
	for (int i = 0; i <taillemax; i++)
	{
		if (i==pos)
		{
			continue;
		}
		fprintf(fl,"%d \t %s \t %s \t %d \t %d\n", tLog[i].id, tLog[i].adresse, tLog[i].type, tLog[i].place, tLog[i].occup);
	}
	
	fclose(fl);
	return;
}
