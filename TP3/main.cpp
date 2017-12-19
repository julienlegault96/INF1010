/**************************************************
* Titre: Travail pratique #3 - Main.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date de création: 18 oct 2017
* Date de la dernière modification: 21 oct 2017
**************************************************/

#include "TypeImage.h"
#include "TypePixel.h"
#include "Pixel.h"
#include "PixelBN.h"
#include "PixelCouleur.h"
#include "PixelGris.h"
#include "Image.h"
#include "GroupeImage.h"
//#include "bitmap.cpp"

// Si plateforme windows
#ifdef _WIN32 
    #include <Windows.h>
    #define PAUSE system("PAUSE")
// S'il s'agit d'une plateforme UNIX
#else
    #include <unistd.h>
    #define PAUSE sleep(0)
#endif

#include <iostream>
#include <string>

using namespace std;
/*
TODO : Veuillez répondre aux question ici
1) Il est pertinent de dériver la classe PixelCouleur de la classe Pixel puisqu'un 
pixel de couleur est une forme de pixel. Ces classes se ressemblent donc beaucoup,
par exemple elles ont tout les deux un opérateur == permettant de comparer deux pixels.
De plus, dériver la classe PixelCouleur permet de lui ajouter ses propres méthodes
adaptées au fait que ce soit un pixel de couleur.

2) le constructeur de Pixel peut definir le type du pixel. Par contre, il ne peut lui a
affecteur de valeur de pigmentation. Du coup, les pixels p1 et p2 ne seront que deux
pixels de type couleur signifiant que la valeur de b sera true.

3) Le Static Cast est une conversion implicite qui permet d'utiliser des fonctions des 
sous-classes PixelCouleur, PixelGris, PixelBN sur les éléments du vecteur Pixels_ qui est 
du type de la classe-mère Pixels.
*/

int main() {
	
	// Chemin vers les images
    string cheminLoad = "./Ensemble d'image/Originale/";
	// Nom des 6 images dans un tableau de string
    string image[6] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "WiC.bmp"};

	// Creer un groupe d'image
	cout << "**************************************************" << endl;
	cout << "Creation du groupe d'image" << endl;
	cout << "**************************************************" << endl << endl;
	GroupeImage monGroupe = GroupeImage();

	// Ajouter toutes les images au groupe en tant qu'image couleurs
	Image* imageTemp = nullptr;
	string chaineNom;

	for (unsigned int i = 0; i < 6; i++)
	{
		chaineNom = cheminLoad + image[i];
		imageTemp = new Image(chaineNom, TypeImage::Couleurs);
		monGroupe.ajouterImage(imageTemp);
		imageTemp = nullptr;
	}

	// Afficher le contenu du groupe d'image
	cout << monGroupe;

	// Convertir toutes les images en couleurs
	monGroupe.toutMettreEnCouleur();

	// Enregistrer toutes les images convertie
	monGroupe.toutEnregistrer();

	// Convertir toutes les images en Nuance de Gris
	monGroupe.toutMettreEnGris();

	// Enregistrer toutes les images grises
	monGroupe.toutEnregistrer();

	// Convertir toutes les images en Noir et Blanc
	monGroupe.toutMettreEnNB();

	// Enretisgrer toutes les images
	monGroupe.toutEnregistrer();

	// Permet d'afficher le contenu de la console
    PAUSE;

	// Fin du programme
    return 0;
}