#include "logement.h"
#define LOC
#include "demande.h"
#define DMD

/**
 *\file locataire.h
 *\brief fichier header qui contient les fonctions et variables du programme C afin de le compiler. Il contient aussi la déclaration des types et des structures utilisé dans le programme.
 *\author JACQUELIN Bastien / DE LA FUENTE Axel
 *\date 08 janvier 2022
  */
typedef struct{
    char nom[30];
    char prenom[30];
    char nationnalite[2];
    float ressourcesAnnuelles;
    int nbPersFoyer;
    int idLog;
    int idLoc;
}Locataire;

void chargementLocataire(Locataire tLoc[], int taille);

int tailleTLoc();

Locataire lireLoc(FILE *fd);

void afficherLoc();

void trisNom(Locataire tLoc[], int taille);

void trisNbPers(Locataire tLoc[], int taille);

int ecrireTabLoc(Locataire tLoc[], int taille);

void creerLoc(Locataire tLoc[], int tailleTLoc, int idLog, int tailleTLog, int placeTLog, Logement tLog[]);

void globalRech();

void affichLoc(Locataire tLoc[], int placeL);

int rechLoc(int tailleTableauLocataires, Locataire tabLocRech[], char nom[], char prenom[]);

int rechLocId(int tailleTableauLocataires, Locataire tabLocRechId[], int idLoc);
