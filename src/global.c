/**
 *\file global.c
 *\brief Il s'agit du fichier contenant la fonction mère du programme. Ici sont déclarés tout les menus et les apelles a toutes les fonctions importante du programme.
 *\author DE LA FUENTE Axel / JACQUELIN Bastien
 *\date 08 janvier 2022
 *Ce programme permet la gestion des logement et des locataires de HLM63 en fonction des demandes et de leur importance.
 *Plusieur fonction sont disponible comme afficher / trier / rechercher / ajouter / supprimer des logements, locataire, demande.
 *L'un des points forts de l'application est sont automatisme. En effet il est possible d'actualiser la file d'attente des demandes en fonction des points de chaque demande et de lui assigner un logement.
 *La gestion de toutes ces données passes par des fichiers textes situer dans "./doc"
  */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"

#include "global.h"
#include "locataire.h"

#ifndef LOC
#define LOC
#include "logement.h"
#endif

#ifndef DMD
#define DMD
#include "demande.h"
#endif

/**
 *\brief Il s'agit de la fonction global qui lance le menu et permet d'acceder a toute les fonctionnalités de l'applacation.
 *\author JACQUELIN Bastien
  */
void global()
{
    int choix1=-1;
    int choix2=-1;
    while (choix1!=0)
    {
        //printf("\e[1;1H\e[2J");
        printf("\n\t\t \033[31m~~~Menu-Principal~~~\033[00m \n\t-1 : Gestion des logements \n\t-2 : Gestion des locataires \n\t-3 : Gestion demande de logement \n\t-4 : Actualisation des points des demandes \n\t-0 : Quitter\n");
        scanf("%d", &choix1);
        if (choix1==1)
        {
            //printf("\e[1;1H\e[2J");
            printf("\n\t\t \033[34m~~~Sous-Menu-Logement~~~\033[0m \n\t-1 : Ajout d'un nouveau logement \n\t-2 : Suppression d'un logement \n\t-3 : Affichage de tous les logements \n\t-4 : Affichage des logements selon un type\n\t-0 : Quitter\n");
            scanf("%d", &choix2);
            if(choix2==1){
                ajouterLogement();
            }    
            if(choix2==2){
                suprrLogement();	
            } 
            if(choix2==3){
                afficherLogement();
                }
            if(choix2==4){
                afficherType();
            } 
	    }
        if (choix1==2)
        {
            //printf("\e[1;1H\e[2J");
            printf("\n\t\t \033[34m~~~Sous-Menu-Locataire~~~\033[0m \n\t-1 : Affichage de tous les locataires \n\t-2 : Recherche d'un locataire \n\t-0 : Quitter\n");
            scanf("%d", &choix2);
            if(choix2==1){
		        afficherLoc();
            }
            if(choix2==2){
                globalRech();
            } 
        }
        if (choix1==3)
        {   
            //printf("\e[1;1H\e[2J");
            printf("\n\t\t \033[34m~~~Sous-Menu-Demande~~~\033[0m \n\t-1 : Enregistrement d'une demande \n\t-2 : Recherche d'une demande \n\t-3 : Affichage de toutes les demandes \n\t-5 : Trier en fonction des points (début de chaque mois) \n\t-0 : Quitter\n");
            scanf("%d", &choix2);
            if(choix2==1){
		        enregistrementDemande();
            }    
            if(choix2==2){
                rechGlob();
            } 
            if(choix2==3){
                globAfficher();
                }
            if(choix2==4){
                trie();
            }
        }
        if(choix1==4){
            actualisationLogement();
            break;
        }
    }
}

/**
 *\brief Il s'agit de la fonction permettant l'actualisation automatique de la file d'attente en fonction des points ainsi que d'assigner un logement à la première demande repondant au critère.
 *\author JACQUELIN Bastien
  */
void actualisationLogement()
{
    int placeTLog, tailleTLog, idLog, tailleLoc,tailleDmd, taillemax, idDmdSupr, placeCheked;
    placeCheked=0;
    /* Logement*/
	tailleTLog=tailleT();
	Logement tabLog[tailleTLog];
	chargerLogement(tabLog, tailleTLog);

    placeTLog=rechercheLogVide(tabLog, tailleTLog, &placeCheked);
    //printf("place log vide %d\n", placeTLog);
    if (placeTLog==-1)
    {
        return;
    }
    
    /*~~~~~~~*/
    /*Locataires*/

    tailleLoc=tailleTLoc();
    //printf("Taille loc %d\n", tailleLoc);
    //Demande
    tailleDmd=tailleTa();
    taillemax=tailleLoc+tailleDmd;
    //printf("ZEBI");
    //Loc
    Locataire tabLoc[taillemax+1];
    chargementLocataire(tabLoc, tailleLoc);

    //log
    tailleTLog=tailleT();
    Logement tLog[tailleTLog+1];
    chargerLogement(tLog, tailleTLog);
    //printf("AVT LE WHILE\n");
    while (placeTLog>=0)
    {
        tailleLoc+=1;
        //printf("Place logement vide : %d\n", placeTLog);
        //printf("\nID logement :  %d : ", tabLog[placeTLog].id);
        //printf("Place dispo pour le logement %d\n", tabLog[placeTLog].place);
        idDmdSupr=rechDemande(tabLog[placeTLog].place);
        //printf("DMD VALIDE ? : %d\n", idDmdSupr);
        if(idDmdSupr!=-1)
        {
            chargementLocataire(tabLoc, tailleLoc-1);
            modifLog(tabLog, "occup", tabLog[placeTLog].id, tailleTLog);
            idLog=tabLog[placeTLog].id;
            creerLoc(tabLoc, tailleLoc, idLog, tailleTLog, placeTLog, tLog);
            enleverUneDemande(idDmdSupr);
            placeTLog=rechercheLogVide(tabLog, tailleTLog, &placeCheked);
            //aucun logement vide
            if (placeTLog==-1)
            {
                break;
            }
        }
        placeTLog=rechercheLogVide(tabLog, tailleTLog, &placeCheked);
        //printf("NOUVELLE PLACE LOG VIDE %d\n", placeTLog);
    }
    return;
}