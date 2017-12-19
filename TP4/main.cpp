/**************************************************
* Titre: Travail pratique #4 - Main.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date de création: 25 oct 2017
* Date de la dernière modification: 29 oct 2017
**************************************************/

#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

#include <iostream>
#include <string>

#include "GroupeImage.h"


using namespace std;

/*
TODO : Veuillez répondre aux question ici
1) Non il n'est pas possible d'instancier un objet de la classe Pixel. La classe contient
des fonctions virtuelles pures, elle est donc abstraite et par conséquent il est interdit
de l'instancier.

2) La valeur de b est FAUX (O) car c'est le résultat de la comparaison de la couleur des pixels,
qui sont de couleurs différentes.

3) Oui c'est possible car la fonction obtenirR() est bien définie pour les pixels de classe Couleur,
ce qui est le cas de p1 qui a été créé. La fonction est définie pour chaque sous-classe de Pixel.

*/

int main() {
// Chemin vers les images
    string cheminLoad = "./Ensemble d'images/Originale/";
    // Nom des 6 images dans un tableau de string
    string image[6] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

    // Creer un groupe d'image nomme groupeImage1
    cout << "**************************************************" << endl;
    cout << "Creation du groupe d'image" << endl;
    cout << "**************************************************" << endl << endl;

    // Creation un groupe d'image nomme groupeImage1

	GroupeImage groupeImage1 = GroupeImage();

    // Ajouter les 3 premieres images contenue dans le tableau de string
    // image au groupeImage1, en couleur
	Image* imageTemp = nullptr;
	string chaineNom;
	for (int i = 0; i < 3; i++) {
		chaineNom = cheminLoad + image[i];
		imageTemp = new Image(chaineNom, TypeImage::Couleurs);
		groupeImage1.ajouterImage(imageTemp);
		imageTemp = nullptr;
	}


    // Creer un deuxieme groupe image identique au groupeImage precedent
    // en utilisant le constructeur par copie ou l'operateur egal (votre choix).
    // Nomme ce groupe groupeImage2
	GroupeImage groupeImage2 = GroupeImage();
	groupeImage2 = groupeImage1;

    // Afficher le contenu de groupeImage1
	cout << groupeImage1 << endl;


    // Afficher le contenu de groupeImage2
	cout << groupeImage2 << endl;

    // Ajouter toutes les images du tableau de string image au groupeImage2, en couleur
	for (int i = 0; i < 6; i++) {
		chaineNom = cheminLoad + image[i];
		imageTemp = new Image(chaineNom, TypeImage::Couleurs);
		groupeImage2.ajouterImage(imageTemp);
		imageTemp = nullptr;
	}


    // Tentez de convertir toutes les images d'un des groupes en Couleur
	 groupeImage1.toutMettreEnCouleur();		


    // Mettre toutes les images du groupeImage1 en negatif
		groupeImage1.MettreGroupeEnNegatif();
	


    // Enregistrer toutes les images du groupeImage2
		groupeImage2.toutEnregistrer();

    // Convertir toutes les images du groupeImage2 en gris
		groupeImage2.toutMettreEnGris();

    // Enregistrer toutes les images du groupeImage2
		groupeImage2.toutEnregistrer();

    // Convertir toutes les images du groupeImage2 en Noir et Blanc
		groupeImage2.toutMettreEnNB();

    // Enretisgrer toutes les images

		groupeImage1.toutEnregistrer();
		// Comme on enregistre groupe 1 après groupe2, les 3 premières images de groupes2 sont écrasées

		groupeImage2.toutEnregistrer();


    // N'oubliez pas de desallouer la memoire si necessaire
		 groupeImage1.~GroupeImage();
		 groupeImage2.~GroupeImage();


    // Permet d'afficher le contenu de la console
    PAUSE;

    // Fin du programme
    return 0;
}