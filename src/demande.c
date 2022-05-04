#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "errno.h"

#include "demande.h"

/**
 *\brief Il s'agit de la fonction principal pour l'affichage des demandes. Elle permet de créer la file de l'initialiser et enfin de la remplier avec le fichier "demande.txt".
 *\author DE LA FUENTE Axel
  */
void globAfficher(){
    File f;
    f=chargementDemande();
    afficherFile(f);
}

/**
 *\brief Il s'agit de la fonction permettant la création d'une demande, une suite de question permette de créer une nouvelle demande, elle est assigner a une variable de structure Demande."
 *\author JACQUELIN Bastien
  */
void enregistrementDemande()
{   
    Demande dmd;
    printf("Saisissez votre identifiant de demande : \n");
    scanf("%d",&dmd.idDmd);
    printf("Saisissez votre nom\n");
    scanf("%s", dmd.nom );
    if (sizeof(char *)*30<sizeof(dmd.nom))
    {
        printf("Nom trop long\n");
    }
    printf("Saisissez votre prenom\n");
    scanf("%s", dmd.prenom );
    if (sizeof(char *)*30<sizeof(dmd.nom))
    {
        printf("Prenom trop long\n");
    }
    printf("Saisissez votre Nationnalité; ex: FR\n");
    scanf("%s", dmd.nationnalite );
    if (strcmp(dmd.nationnalite, "FR")==0)
    {
        dmd.carteSejour=0;
    }
    else
    {
        printf("Saisissez \"1\" si la carte de séjour est toujours en cours de validité sinon \"0\". \n");
        scanf("%d", &dmd.carteSejour);
        if ((dmd.carteSejour>1) || (dmd.carteSejour<0))
        {
            
            while (dmd.carteSejour>1 || dmd.carteSejour<0)
            {
                printf("Erreur de saisie\n\n");
                printf("Saisissez \"1\" si la carte de séjour est toujours en cours de validité sinon \"0\". \n");
                scanf("%d", &dmd.carteSejour);
            }
            
        }
        if (dmd.carteSejour==0)
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : Personne non Francaise et sans carte de séjour toujours en cours de validité");
            return ;
        }
    }
    printf("Saisissez le montant de vos ressources annuelles\n");
    scanf("%f", &dmd.ressourcesAnnuelles );
    
    printf("Saisissez le nombre de personnes composant le foyer\n");
    scanf("%d", &dmd.nbPersFoyer );
    if (dmd.nbPersFoyer==1)
    {
        if (dmd.ressourcesAnnuelles>=20966)
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : ressources annuelles trop élevées");
            return;
        }
    }

    if (dmd.nbPersFoyer==2)
    {
        if (dmd.ressourcesAnnuelles>=27998)
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : ressources annuelles trop élevées");
            return;
        }
    }

    if (dmd.nbPersFoyer==3)
    {
        if (dmd.ressourcesAnnuelles>=33670)
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : ressources annuelles trop élevées");
            return;
        }
    }

    if (dmd.nbPersFoyer==4)
    {
        if (dmd.ressourcesAnnuelles>=40648)
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : ressources annuelles trop élevées");
            return;
        }
    }
    if (dmd.nbPersFoyer==5)
    {
        if (dmd.ressourcesAnnuelles>=47618)
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : ressources annuelles trop élevées");
            return;
        }
    }
    if (dmd.nbPersFoyer==6)
    {
        if (dmd.ressourcesAnnuelles>=53891)
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : ressources annuelles trop élevées");
            return;
        }
    }
    if (dmd.nbPersFoyer>6)
    {
        if (dmd.ressourcesAnnuelles>=53891+((dmd.nbPersFoyer-6)*6011))
        {
            printf("La demande ne peut être finalisée. Les conditions ne sont pas remplies : ressources annuelles trop élevées");
            return;
        }
    }
    int condition;
    dmd.nbpoint=0;
    printf("Renseignez votre condition:\n 0-Sans condition particulière \n 1-handicapé\n 2-victimes de violences au sein du couple\n 3-hébergées ou logées temporairement\n 4-sans aucun logement ou menacées d expulsion sans relogement\n 5-logées dans un logement insalubre ou dangereux\n");
    scanf("%d", &condition);
    if (condition<0 || condition>5)
    {
        
        while (condition<0 || condition>5)
        {
            printf("Erreur de saisie\n\n");
            printf("Renseignez votre condition:\n 0-Sans condition particulière \n 1-handicapé\n 2-victimes de violences au sein du couple\n 3-hébergées ou logées temporairement\n 4-sans aucun logement ou menacées d expulsion sans relogement\n 5-logées dans un logement insalubre ou dangereux\n");
            scanf("%d", &condition);
        }
        
    }
        if (condition==0)
        {
            dmd.nbpoint+=0;
        }
        if (condition==1)
        {
            dmd.nbpoint+=30;
        }
        if (condition==2 || condition==3)
        {
            dmd.nbpoint+=15;
        }
        if (condition==4)
        {
            dmd.nbpoint+=10;
        }
        if (condition==5)
        {
            dmd.nbpoint+=8;
        }
    while (condition!=0)
    {
        printf("Renseignez votre condition:\n 0-Si vous ne possédez pas d'autres conditions particulières \n 1-handicapé\n 2-victimes de violences au sein du couple\n 3-hébergées ou logées temporairement\n 4-sans aucun logement ou menacées d expulsion sans relogement\n 5-logées dans un logement insalubre ou dangereux\n");
        scanf("%d", &condition);
        if (condition==0)
        {
            dmd.nbpoint+=0;
        }
        if (condition==1)
        {
            dmd.nbpoint+=30;
        }
        if (condition==2 || condition==3)
        {
            dmd.nbpoint+=15;
        }
        if (condition==4)
        {
            dmd.nbpoint+=10;
        }
        if (condition==5)
        {
            dmd.nbpoint+=8;
        }
    }
    printf("Votre demande a bien été finalisée\n");
    ecritureDemande(dmd);
    return;
}

/**
 *\brief Il s'agit de la fonction qui permet d'écrire une nouvelle demande a la suite dans le fichier "demande.txt"
 *\return 0 si l'ouverture reussis, -1 si il y a un échec
 *\author JACQUELIN Bastien
  */
int ecritureDemande(Demande dmd)
{
    FILE * fd;
    fd=fopen("../doc/demande.txt", "a");
    if (fd==NULL)
    {
        printf("erreur ouverture");
        return -1;
    }
    fprintf(fd, "%d\t %s\t %s\t %s\t %d\t %.2f \t%d\t %d\n", dmd.idDmd, dmd.nom, dmd.prenom, dmd.nationnalite, dmd.carteSejour, dmd.ressourcesAnnuelles, dmd.nbPersFoyer, dmd.nbpoint);
    fclose(fd);
    return 0;
}

/**
 *\brief Il s'agit de la fonction permettant de charger le fichier "demande.txt" en mémoire dans une file.
 *\retourn une file pleine.
 *\author DE LA FUENTE Axel
  */
File chargementDemande()
{
    int taille;
    File f;
    taille=tailleTa();
    f=CreerFileVide(taille);
    FILE * fd;
    fd=fopen("../doc/demande.txt", "r");
    if(fd==NULL) { perror("fopen"); exit(errno);}

    f.tete=lireDemande(&f, fd);

    fclose(fd);

    return f;
}

/**
 *\brief Il s'agit de la fonction permettant de déterminer de quelle taille est le fichier "demande.txt" (nombres de lignes).
 *\return la taille du fichier (nombre de ligne)
 *\author DE LA FUENTE Axel
  */
int tailleTa(){
	int taille=-1;
	FILE *fe;
        fe=fopen("../doc/demande.txt","r");
        if(fe==NULL) { perror("fopen"); exit(errno);}
        while(feof(fe)==0){
		fscanf(fe, "%*d %*s %*s %*s %*d %*f %*d %*d");
		++taille;
	}
    fclose(fe);
	return taille;
}

/**
 *\brief Il s'agit de la fonction permettant d'initialiser un file vide.
 *\param[out] taille est la taille que va faire la file (il s'agit du nombres de lignes du fichiers "demande.txt")
 *\return une file vide
 *\author DE LA FUENTE Axel
  */
File CreerFileVide(int taille){
    File f;
    if((f.tete=(Demande *)malloc(sizeof(Demande)*taille))==NULL){
        perror("file"); exit(errno);
    }
    
    f.tete=NULL;
    f.queu=NULL;
    f.deb=0;
    f.nbElem=0;
    f.tailleMax=taille;
    free(f.tete);
    return f;
}

/**
 *\brief Il s'agit de la fonction permettant de lire une ligne du fichier "demande.txt" et de la mettre dans une strcture File de Demande.
 *\param *f est un pointeur sur la file de demande
 *\param *fd est un pointeur sur le fichier ouvert en lecture "demande.txt"
 *\return un pointeur sur une demande remplit par la ligne ou se trouve le curseur, sur le fichier "Demande.txt"
 *\author DE LA FUENTE Axel
  */
Demande * lireDemande(File *f, FILE *fd){
    
    if(f->nbElem >= f->tailleMax){
        return NULL;
    }
    
    Demande *dmd;
    dmd=(Demande*)malloc(sizeof(Demande));

    fscanf(fd, "%d %s %s %s %d %f %d %d", &dmd->idDmd, dmd->nom, dmd->prenom, dmd->nationnalite, &dmd->carteSejour, &dmd->ressourcesAnnuelles, &dmd->nbPersFoyer, &dmd->nbpoint);

    f->nbElem=f->nbElem+1;
    
    dmd->suivant=lireDemande(f, fd);
    if(dmd->suivant==NULL){
        f->queu=dmd;
    }
    
    return dmd;
}

/**
 *\brief Il s'agit de la fonction permettant d'afficher la file des demandes.
 *\param f est la file des demandes
 *\author DE LA FUENTE Axel
  */
void afficherFile(File f){

    if(f.deb>=f.nbElem){
        return;
    }

    printf("%d\t %s\t %s\t %s\t %d\t %.2f\t %d\t %d\n", f.tete->idDmd, f.tete->nom, f.tete->prenom, f.tete->nationnalite, f.tete->carteSejour, f.tete->ressourcesAnnuelles, f.tete->nbPersFoyer, f.tete->nbpoint );
    f.deb=f.deb+1;
    f.tete=f.tete->suivant;
    afficherFile(f);
    
    return;
}

/**
 *\brief Il s'agit de la fonction global permettant de trier la file .
 *\author JACQUELIN Bastien
  */
void trie()
{
    char *nomfich="../doc/demande.txt";
    Demande *tabDmd;
    int taille;
    taille=tailleTa();
    tabDmd=(Demande*)malloc(sizeof(Demande)*taille);
    chargeTab(nomfich,tabDmd,taille);
    bubbleSort(tabDmd,taille);
    ecrireTab(nomfich,tabDmd,taille);
    affich(tabDmd, taille);

    return;
}

/**
 *\brief Il s'agit de la fonction permettant de charger la file dans un tableau afin de la trier simplement.
 *\param *nomFich est un pointeur sur le nom du fichier "demande.txt"
 *\param tabDmd est un tableau de structure Demande
 *\param taillfich est la taille que devra faire le tableau (il s'agit du nombre de ligne du fichier "demande.txt")
 *\return 0 si ouverture de fichier réussis, -1 sinon
 *\author JACQUELIN Bastien
  */
int chargeTab(char *nomFich, Demande tabDmd[], int taillfich)
{
    FILE * fd;
    fd=fopen(nomFich, "r");
    if (fd==NULL)
    {
        printf("erreur ouverture");
        return -1;
    }
    for (int i=0; i<taillfich; i++)
    {
        fscanf(fd,"%d %s %s %s %d %f %d %d", &tabDmd[i].idDmd, tabDmd[i].nom, tabDmd[i].prenom, tabDmd[i].nationnalite, &tabDmd[i].carteSejour, &tabDmd[i].ressourcesAnnuelles, &tabDmd[i].nbPersFoyer, &tabDmd[i].nbpoint);
    }
    fclose(fd);
    return 0;
}

/**
 *\brief Il s'agit de la fonction permettant d'afficher le tableau des demandes une fois trier.
 *\param tabDmd est un tableau de la structure Demande
 *\param taillfich est la taille que devra faire le tableau (il s'agit du nombre de lignes du fichier "demande.txt")
 *\author JACQUELIN Bastien
  */
void affich(Demande tabDmd[], int taillfich)
{
    for (int i = 0; i < taillfich; i++)
    {
        printf("%d\t %s\t %s\t %s\t %d\t %0.2f\t %d\t %d\n", tabDmd[i].idDmd, tabDmd[i].nom, tabDmd[i].prenom, tabDmd[i].nationnalite, tabDmd[i].carteSejour, tabDmd[i].ressourcesAnnuelles, tabDmd[i].nbPersFoyer, tabDmd[i].nbpoint);
    }
    return;
}

/**
 *\brief Il s'agit de la fonction permettant de trier le tableau de la file .
 *\param tabDmd est un tableau de la structure Demande
 *\param taillfich est la taille que devra faire le tableau (il s'agit du nombre de lignes du fichier "demande.txt")
 *\author JACQUELIN Bastien
  */
void bubbleSort(Demande tabDmd[], int taillfich){
    Demande tmp;
    for (int i=0; i<taillfich; ++i){
        for (int j=i+1; j<taillfich; j++){
            if (tabDmd[i].nbpoint<tabDmd[j].nbpoint)
            {
                tmp=tabDmd[i];
                tabDmd[i]=tabDmd[j];
                tabDmd[j]=tmp;
            }
        }
    }
}

/**
 *\brief Il s'agit de la fonction permettant d'écrire le tableau de la file dans le fichier "demande.txt".
 *\param *nomFich est un pointeur sur le nom du fichier "demande.txt"
 *\param tabDmd est un tableau de la structure Demande
 *\param taillfich est la taille que devra faire le tableau (il s'agit du nombre de lignes du fichier "demande.txt")
 *\return 0 si ouverture de fichier réussis, -1 sinon
 *\author JACQUELIN Bastien
  */
int ecrireTab(char *nomFich, Demande tabDmd[], int taillfich)
{
    FILE *fd;
    fd=fopen(nomFich, "w");
    if (fd==NULL)
    {
        printf("erreur ouverture");
        return -1;
    }
    for (int i=0; i<taillfich; i++)
    {
        fprintf(fd,"%d\t %s\t %s\t %s\t %d\t %0.2f\t %d\t %d\n", tabDmd[i].idDmd,tabDmd[i].nom, tabDmd[i].prenom, tabDmd[i].nationnalite, tabDmd[i].carteSejour, tabDmd[i].ressourcesAnnuelles, tabDmd[i].nbPersFoyer, tabDmd[i].nbpoint);
    }
    fclose(fd);
    return 0;
}

/**
 *\brief Il s'agit de la fonction permettant de retirer.
 *\param val est la valeur de l'identifiant de la demande qu'il faut retirer.
 *\author DE LA FUENTE Axel
  */
void enleverUneDemande(int val)
{
    int taillefich;
    taillefich=tailleTa();
    Demande tabDmd[taillefich+1];
    chargeTab("../doc/demande.txt", tabDmd, taillefich);
    for(int i=0; i<taillefich; ++i){
        if(tabDmd[i].idDmd==val){
            int k=i;
            for(int j=i+1; j<taillefich; ++j){
                tabDmd[i]=tabDmd[j];
                ++k;
            }
            --taillefich;
            ecrireTab("../doc/demande.txt", tabDmd, taillefich);
            return;
        }
    }
    return;
}

/**
 *\brief Il s'agit de la fonction permettant de chercher dans le tableau de la file, une demande selon son nombre de places.
 *\param nbplace est le nombre de place demandée dans une demande.
 *\return 0 si la valeur et trouver et qu'elle a ete supprimée; -1 sinon
 *\author DE LA FUENTE Axel
  */
int rechDemande(int nbplace)
{
    int taille;
    taille=tailleTa();
    Demande tDmd[taille+1];
    chargeTab("../doc/demande.txt",tDmd, taille);
    for(int i=0; i<taille; ++i){
        if (tDmd[i].nbPersFoyer==nbplace)
        {
            return i;
        }
        
    }
    return -1;
}

/**
 *\brief Il s'agit de la fonction permettant de chercher dans le tableau de la file, une demande selon son identifiant.
 *\param nbplace est le nombre de place demandée dans une demande.
 *\return 0 si la valeur et trouver et qu'elle a ete supprimée; -1 sinon
 *\author DE LA FUENTE Axel
  */
int rechDemandeId(int id)
{
    int taille;
    taille=tailleTa();
    Demande tDmd[taille+1];
    chargeTab("../doc/demande.txt",tDmd, taille);
    for(int i=0; i<taille; ++i){
        if (tDmd[i].idDmd==id)
        {
            return i;
        }
        
    }
    return -1;
}
/**
 *\brief Il s'agit de la fonction permettant la recherche d'une demande selon un identifiant ou selon un nombre de personne souhaiter."
 *\author JACQUELIN Bastien
  */
void rechGlob()
{
    int choix;
    int taille;
    taille=tailleTa();
    Demande tabDmd[taille+1];
    chargeTab("../doc/demande.txt",tabDmd, taille);
    printf("-1 : Recherche par identifiant\n-2 : Recherche par nombre de personnes composants le foyer\n");
    scanf("%d", &choix);

    if(choix==1){
        printf("Veuillez renseigner l'identifiant : \n");
        int idD,i;
        scanf("%d", &idD);
        i=rechDemandeId(idD);
        if(i==-1){printf("\nDemande introuvable\n\n");return;}
        printf("%d\t %s\t %s\t %s\t %d\t %0.2f\t %d\t %d\n", tabDmd[i].idDmd, tabDmd[i].nom, tabDmd[i].prenom, tabDmd[i].nationnalite, tabDmd[i].carteSejour, tabDmd[i].ressourcesAnnuelles, tabDmd[i].nbPersFoyer, tabDmd[i].nbpoint);

    }
    if(choix==2){
        printf("Veuillez renseigner le nombre de personnes composants le foyer\n");
        int nbPersFoyer,i;
        scanf("%d", &nbPersFoyer);
        i=rechDemande(nbPersFoyer);
        if(i==-1){printf("\nDemande introuvable\n\n");return;}
        printf("%d\t %s\t %s\t %s\t %d\t %0.2f\t %d\t %d\n", tabDmd[i].idDmd, tabDmd[i].nom, tabDmd[i].prenom, tabDmd[i].nationnalite, tabDmd[i].carteSejour, tabDmd[i].ressourcesAnnuelles, tabDmd[i].nbPersFoyer, tabDmd[i].nbpoint);
    }
    return;
}