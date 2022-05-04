/**
 *\file logement.h
 *\brief fichier header qui contient les fonctions et variables du programme C afin de le compiler. Il contient aussi la déclaration des types et des structures utilisé dans le programme.
 *\author JACQUELIN Bastien / DE LA FUENTE Axel
 *\date 08 janvier 2022
  */
typedef struct{
	int id;
	char adresse[50];
	char type[3];
	int occup;// 1 si occupé ssinon 0
	int place;
} Logement;

int chargerLogement(Logement tLog[], int taillemax);

Logement lireLog(FILE *fe);

void afficherLogement();

int tailleT();

void suprrLogement();

int rechercheLogement(Logement tLog[], int taillemax, int num);

void suppr(Logement tLog[], int taillemax, int pos);

void ajouterLogement();

void afficherType();

void trisPlace(Logement tLog[], int taillemax);

void trisType(Logement tLog[], int taillemax);

int rechercheLogVide(Logement tLog[], int taillemax, int *placeCheked);

void modifLog(Logement tLog[], char *champModif, int id, int taillemax);
