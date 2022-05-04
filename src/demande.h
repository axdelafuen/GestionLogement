/**
 *\file demande.h
 *\brief fichier header qui contient les fonctions et variables du programme C afin de le compiler. Il contient aussi la déclaration des types et des structures utilisé dans le programme.
 *\author JACQUELIN Bastien / DE LA FUENTE Axel
 *\date 08 janvier 2022
  */


void logement();

typedef struct Demande Demande;

struct Demande 
{
    int idDmd;
    char nom[30];
    char prenom[30];
    char nationnalite[2];
    int carteSejour;
    float ressourcesAnnuelles;
    int nbPersFoyer;
    int nbpoint;
    Demande *suivant;
};


typedef struct
{
    Demande *tete;
    Demande *queu;
    int deb;
    int nbElem;
    int tailleMax;
}File;

void enregistrementDemande();

int ecritureDemande(Demande dmd);

void globEnregistrement();

void trie();

int chargeTab(char *nomFich, Demande tabDmd[], int taillfich);

void bubbleSort(Demande tabDmd[], int taillfich);

int ecrireTab(char *nomFich, Demande tabDmd[], int taillfich);

int tailleTa();

File CreerFileVide(int taille);

File chargementDemande();

Demande * lireDemande(File *f, FILE *fd);

void afficherFile(File f);

void globRecherch();

void globAfficher();

void affich(Demande tabDmd[], int taillfich);

int rechDemande(int nbplace);

void enleverUneDemande(int val);

void rechGlob();

int rechDemandeId(int id);