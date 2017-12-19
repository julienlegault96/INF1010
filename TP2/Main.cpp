/**************************************************
 * Titre: Travail pratique #2 - Main.cpp
 * Date: Septembre 2017
 * Auteur : Arnaud Lebrun et Julien Legault + enseignants
 * Date : 13 sept 2017
 * Mise a jour : 02 oct 2017
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"


#include <string>
#include <iostream>

using namespace std;

/*
TODO : Veuillez répondre aux question ici
1) Le constructeur par copie et l'opérateur « = » peuvent être appelés successivement afin de créer
une copie d'un objet existant. Dans le cas où l'objet contient des pointeurs, si nous ne procédons pas de cette façon, le constructeur par défaut sera
appelé et fera tout simplement une copie des pointeurs (nous nous retrouvons à avoir deux objets pointant vers le même objet). Le constructeur par copie
et l'opérateur « = » réalisent une copie de l'attribut pointé pour chaque objet, au lieu de juste copier le pointeur.

2) Lorsqu'on nous voulons éviter de créer différents objets ayant comme attributs des pointeurs qui du coup pointeraient 
vers le même endroit. Ils sont utiles en permettant de copier la donnée pointée ; chaque objet en contenant alors une copie.

3)L'opérateur « = » nécessite un objet existant afin de faire une affectation alors que le constructeur crée l'objet. C'est alors en exécutant
les deux commandes qu'on peut crééer un objet aux attributs identiques.
*/

int main()
{


	//1- Creez 9 pixels rouge  (255,0,0)
	Pixel neufPixelsRouges[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			neufPixelsRouges[i][j].modifierTeinteRouge(255);
		}
	}

	//2-Creez 9 pixels verts (0,255,0)
	Pixel neufPixelsVerts[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			neufPixelsVerts[i][j].modifierTeinteVert(255);
		}
	}

	//3- Creez une image de taille 3*3 
	Image image1 = Image("Image1", 3, 3);

	//4- Ajouter à l'image créées à l'étape 3 les pixels rouges
	for (unsigned int i = 0; i < image1.obtenirNombrePixelLargeur(); i++) {
		for (unsigned int j = 0; j < image1.obtenirNombrePixelHauteur(); j++) {
			image1.ajouterPixel(neufPixelsRouges[i][j], j, i);
		}
	}
	
	//5- Creez une deuxième image de taille 3*3 
	Image image2 = Image("Image2", 3, 3);

	//6- Ajouter à l'image créées à l'étape 3 les pixels verts
	for (unsigned int i = 0; i < image2.obtenirNombrePixelHauteur(); i++)
	{
		for (unsigned int j = 0; j < image2.obtenirNombrePixelLargeur(); j++)
		{
			image2.ajouterPixel(neufPixelsVerts[i][j], j, i);
		}

	}

	//7- Creez un groupe d'image avec une capacite de 3
	GroupImage groupImage = GroupImage();
	
	//8- Ajoutez les deux images crées precédament au groupe
	groupImage += image1;
	groupImage += image2;
	
	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	groupImage.obtenirImage(0)->augmenterTeintePixel(1, 1, 50, 'B');

	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	groupImage.obtenirImage(0)->augmenterTeintePixel(1, 1, -255, 'R');

	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités  
	groupImage.obtenirImage(1)->augmenterTeintePixel(1, 2, 100, 'B');

	//12- Afficher le groupe d'image
	cout << groupImage;

	//13- Supprimer la premiere image du groupe d'image
	groupImage.retirerImage(image1.obtenirNomImage());

	//14- Afficher le groupe d'image
	cout << groupImage;

	groupImage.~GroupImage();
	
	return 0;
}