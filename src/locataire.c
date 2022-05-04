#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errno.h"
#include "locataire.h"


/**
 *\brief Il s'agit de la fonction global permettant d'afficher les locations en cours.
 *\author DE LA FUENTE Axel
  */
void afficherLoc(){
    int taille;
    taille=tailleTLoc();
    if (taille<0)
    {
        printf("il n'y a pas encore de locataires\n");
        return;
    }
    Locataire tLoc[taille+1];
    chargementLocataire(tLoc, taille);
    taille=tailleTLoc();
    while(1==1){
        int choix3=-1;
		printf("\t ~~~Veuillez renseigner votre choix : ~~~\n");
		printf("\t-1 Tri par nom \n");
		printf("\t-2 Tri par nombre de personne dans le logement \n");
		printf("\t-3 Afficher sans trier \n");
		printf("\t-0 Quitter\n");
		scanf("%d", &choix3);
	
		if(choix3==0){return;}
		if(choix3==1){trisNom(tLoc,taille); break;}
		if(choix3==2){trisNbPers(tLoc,taille); break;}
		if(choix3==3){break;}
    }
    
    taille=tailleTLoc();

    for(int i=0; i<=taille; ++i){
        printf("%s\t %s\t %s\t %f\t %d\t %d %d\n", tLoc[i].nom, tLoc[i].prenom, tLoc[i].nationnalite, tLoc[i].ressourcesAnnuelles, tLoc[i].nbPersFoyer, tLoc[i].idLog, tLoc[i].idLoc);
    }
    return;
}

/**
 *\brief Il s'agit de la fonction permettant de charger le fichier "locataire.txt" dans un tableau de la structure Locataire.
 *\param tLoc est un tableau de la structure Locataire
 *\param taille est la taille maximum que doit faire le tableau (il s'agit du nombre de lignes que fait "locataire.txt")
 *\author DE LA FUENTE Axel
  */
void chargementLocataire(Locataire tLoc[], int taille){
    FILE *fl;
    fl=fopen("../doc/locataire.txt","r");
    if(fl==NULL) { perror("fopen"); exit(errno);}
    Locataire loc;
    int i=0;
    while(feof(fl)==0)
    {
	    if(i>taille){perror("taille tableau"); exit(errno);}
        loc=lireLoc(fl);
        tLoc[i]=loc;
	++i;
    }
    fclose(fl);
    return;
}

/**
 *\brief Il s'agit de la fonction permettant de lire le fichier "locataire.txt" est de l'attribuer à une variable de la structure Locataire.
 *\param *fd est un pointeur sur le fichier ouvert en lecture "locataire.txt"
 *\return un Locataire de la ligne sur laquelle le curseur est dans "locataire.txt"
 *\author DE LA FUENTE Axel
  */
Locataire lireLoc(FILE *fd){
        Locataire loc;

        fscanf(fd, "%s %s %s %f %d %d %d", loc.nom, loc.prenom, loc.nationnalite, &loc.ressourcesAnnuelles, &loc.nbPersFoyer, &loc.idLog, &loc.idLoc);
        return loc;
}

/**
 *\brief Il s'agit de la fonction permettant de charger le fichier "locataire.txt" en mémoire, de passer ligne par ligne et de les compter, afin de terminer sa taille.
 *\return la taille du fichier (nombre de lignes)
 *\author DE LA FUENTE Axel
  */
int tailleTLoc(){
	int taille=-1;
	FILE *fe;
    fe=fopen("../doc/locataire.txt","r");
        if(fe==NULL) { perror("fopen"); exit(errno);}
    while(feof(fe)==0)
    {
		fscanf(fe, "%*s %*s %*s %*f %*d %*d %*d");
		++taille;
	}
    fclose(fe);
	return taille;
}

/**
 *\brief Il s'agit de la fonction permettant de trier le tableau de la strucutre Locataire en fonction des noms.
 *\param tLoc est un tableau de la structure Locataire
 *\param taille est la taille maximum que doit faire le tableau (il s'agit du nombre de lignes que fait "locataire.txt")
 *\author DE LA FUENTE Axel / JACQUELIN Bastien
  */
void trisNom(Locataire tLoc[], int taille){ 
	int i,j;               
        char change;

        for(i=taille;i!=0;--i){
                change=0;
                for(j=0; j<i; ++j){                     
                        if(strcmp(tLoc[j].nom,tLoc[j+1].nom)<0){
				Locataire tmp;            
                                tmp=tLoc[j];                  
                                tLoc[j]=tLoc[j+1];          
                                tLoc[j+1]=tmp;                
                                change=1;                       
                        }      
                }
        }                      
        if(change==0) return; 
}

/**
 *\brief Il s'agit de la fonction permettant de trier le tableau de la strucutre Locataire en fonction du nombre de personnes.
 *\param tLoc est un tableau de la structure Locataire
 *\param taille est la taille maximum que doit faire le tableau (il s'agit du nombre de lignes que fait "locataire.txt")
 *\author DE LA FUENTE Axel / JACQUELIN Bastien
  */
void trisNbPers(Locataire tLoc[], int taille){
	int i,j;               
        char change;

        for(i=taille;i!=0;--i){
                change=0;
                for(j=0; j<i; ++j){                     
                        if(tLoc[j].nbPersFoyer>tLoc[j+1].nbPersFoyer){                                                                
                                Locataire tmp;            
                                tmp=tLoc[j];                  
                                tLoc[j]=tLoc[j+1];          
                                tLoc[j+1]=tmp;                
                                change=1;                       
                        }      
                }
        }                      
        if(change==0) return; 
}

/**
 *\brief Il s'agit de la fonction permettant creer un nouvelle location, l'inclure dans un tableau puis l'écrire dans "locataire.txt"
 *\param tLoc est un tableau de la structure Locataire
 *\param tailleTLoc est la taille maximum que doit faire le tableau des locataires (il s'agit du nombre de lignes que fait "locataire.txt")
 *\param idLog est l'identifiant du logement choisis pour le locataire
 *\param tailleTLog est la taille maximum que doit faire le tableau des logements
 *\param placeTLog est le nombre de places disponible dans le logement souhaité
 *\author JACQUELIN Bastien
  */
void creerLoc(Locataire tLoc[], int tailleTLoc, int idLog, int tailleTLog, int placeTLog, Logement tLog[])
{
    tailleTLoc-=1;
    chargementLocataire(tLoc, tailleTLoc);
    int taillfich;
    taillfich=tailleTa();
    Demande tabDmd[taillfich];
    chargeTab("../doc/demande.txt", tabDmd, taillfich);

    int placeTDmd=rechDemande(tLog[placeTLog].place);
    strcpy(tLoc[tailleTLoc].nom,tabDmd[placeTDmd].nom);
    strcpy(tLoc[tailleTLoc].prenom,tabDmd[placeTDmd].prenom);
    strcpy(tLoc[tailleTLoc].nationnalite,tabDmd[placeTDmd].nationnalite);
    tLoc[tailleTLoc].ressourcesAnnuelles=tabDmd[placeTDmd].ressourcesAnnuelles;
    tLoc[tailleTLoc].nbPersFoyer=tabDmd[placeTDmd].nbPersFoyer;
    tLoc[tailleTLoc].idLog=idLog;
    printf("Saisissez le l'idantifiant du nouveau locataire: \n");
    scanf("%d", &tLoc[tailleTLoc].idLoc);
    ecrireTabLoc(tLoc, tailleTLoc);
    enleverUneDemande(tabDmd[placeTDmd].idDmd);
    return;
}

/**
 *\brief Il s'agit de la fonction permettant d'écrire le tableau de la strucutre Locataire dans le fichier "locataire.txt".
 *\param tLoc est un tableau de la structure Locataire
 *\param taille est la taille maximum que doit faire le tableau (il s'agit du nombre de lignes que fait "locataire.txt")
 *\return 0 si ouverture réussis, -1 sinon
 *\author DE LA FUENTE Axel / JACQUELIN Bastien
  */
int ecrireTabLoc(Locataire tLoc[], int taille)
{
    FILE *fd;
    fd=fopen("../doc/locataire.txt", "w");
    if (fd==NULL)
    {
        printf("erreur ouverture");
        return -1;
    }
    for (int i=0; i<=taille; i++)
    {
        fprintf(fd,"%s\t %s\t %s\t %f\t %d\t %d\t %d\n", tLoc[i].nom, tLoc[i].prenom, tLoc[i].nationnalite, tLoc[i].ressourcesAnnuelles, tLoc[i].nbPersFoyer, tLoc[i].idLog, tLoc[i].idLoc);
    }
    fclose(fd);
    return 0;
}
/**
 *\brief Il s'agit de la fonction permettant d'effetctuer une recherche dans un tableau de structure Locataire selon un nom et un prénom .
 *\param tLocRech est un tableau de la structure Locataire
 *\param prenom est la le prenom du nom du locataire que l'on recherche
 *\param nom est la le nom du nom du locataire que l'on recherche
 *\return i la place dans le tableau si la valeur chercher a été trouvé, -1 sinon
 *\author JACQUELIN Bastien
  */
int rechLoc(int tailleTableauLocataires, Locataire tabLocRech[], char nom[], char prenom[])
{
    for (int i = 0; i <= tailleTableauLocataires; i++)
    {
        if ((strcmp(tabLocRech[i].nom,nom)==0)&&(strcmp(tabLocRech[i].prenom,prenom)==0))
        {
            return i;
        }
    }
    return -1;
}

/**
 *\brief Il s'agit de la fonction permettant d'effetctuer une recherche dans un tableau de structure Locataire selon un identifiant de locataire .
 *\param tailleTableauLocataires est la taille logique du tableau de locataire
 *\param tabLocRechId est un tableau de la structure Locataire
 *\param idLoc est l'identifiant du locataire que l'on recherche
 *\return i la place dans le tableau si la valeur chercher a été trouvé, -1 sinon
 *\author JACQUELIN Bastien / DE LA FUENTE Axel
  */
int rechLocId(int tailleTableauLocataires, Locataire tabLocRechId[], int idLoc)
{
    for (int i = 0; i <= tailleTableauLocataires; i++)
    {
        if (idLoc==tabLocRechId[i].idLoc)
        {
            return i;
        }
    }
    return -1;
}

/**
 *\brief Il s'agit de la fonction permettant dafficher un tableau de structure Locataire.
 *\param placeL est la place à laquelle se situe le locataire que l'on recherche dans le tableau suivant,
 *\param tLoc est un tableau de la structure Locataire
 *\author JACQUELIN Bastien
  */
void affichLoc(Locataire tLoc[], int placeL)
{
    printf("%s\t %s\t %s\t %f\t %d\t %d\t %d\n", tLoc[placeL].nom, tLoc[placeL].prenom, tLoc[placeL].nationnalite, tLoc[placeL].ressourcesAnnuelles, tLoc[placeL].nbPersFoyer, tLoc[placeL].idLog, tLoc[placeL].idLoc);
    return;
}

/**
 *\brief Il s'agit de la fonction global permettant de charger un tableau de structure locataire depuis un fichier "locataire.txt" et d'effectuer une recherche selon un identifiant ou un nom + prenom
 *\author JACQUELIN Bastien / DE LA FUENTE Axel
  */
void globalRech()
{
    int taille, placeLoc=-1, idLoc, choix;
    char nom[30], prenom[30];
    
    taille=tailleTLoc();
    Locataire tLoc[taille+1];
    chargementLocataire(tLoc, taille);
        
    printf("-1 : Recherche par nom \n-2 : Rechercher par id\n");
    scanf("%d", &choix);
    if (choix==1)
    {
        printf("Nom du locataire à rechercher: \n");
        scanf("%s", nom);

        printf("Prenom du locataire à rechercher: \n");
        scanf("%s", prenom);
;
        placeLoc=rechLoc(taille, tLoc, nom, prenom);
    }
    if (choix==2)
    {
        printf("Id du locataire que vous cherchez:");
        scanf("%d", &idLoc);
        placeLoc=rechLocId(taille, tLoc, idLoc);
    }

    if ((placeLoc<0) || (placeLoc>taille))
    {
        printf("Le locataire que vous recherchez est introuvable");
        return;
    }
    affichLoc(tLoc, placeLoc);
    return;
}