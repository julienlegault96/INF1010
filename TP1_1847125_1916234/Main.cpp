/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date de création: 13 Septembre 2017
* Date de la dernière modification: 24 Septembre 2017
**************************************************/

#include "Pixel.h"
#include "Image.h"
#include "GroupImage.h"
#include "Const.h"


#include <string>
#include <iostream>

using namespace std;

int main()
{
	//1- Creez 9 pixels rouge  (255,0,0)
	
	// création tableau 2D de 9 pixels
	Pixel neufPixelsRouges[3][3];

	// coloration des pixels en rouge
	for(int i = 0 ; i < 3 ; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			neufPixelsRouges[i][j].modifierTeinteRouge(MAX_CONCENTRATION_COULEUR);
		}
	}
	//2-Creez 9 pixels verts (0,255,0)

	// création tableau 2D de 9 pixels
	Pixel neufPixelsVerts[3][3];

	// coloration des pixels en rouge
	for (int i = 0; i < 3 ; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			neufPixelsVerts[i][j].modifierTeinteVert(MAX_CONCENTRATION_COULEUR);
		}
	}
	//3- Creez une image de taille 3*3
	Image image1 = Image("Image1", 3, 3);

	//4- Ajouter à l'image créée à l'étape 3 les pixels rouges
	for (unsigned int i = 0; i < image1.obtenirNombrePixelHauteur(); i++)
	{
		for (unsigned int j = 0; j < image1.obtenirNombrePixelLargeur(); j++)
		{
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
	cout << "Quel est le type du groupe d'images?" << endl;
	string type;
	cin >> type;
	GroupImage groupe1 = GroupImage(type, 3);

	//8- Ajoutez les deux images crées precédament au groupe
	groupe1.ajouterImage(image1);
	groupe1.ajouterImage(image2);
	
	//9- Augmentez la teinte bleu du Pixel (1,1) de l'image 0 de 50 unités
	groupe1.obtenirImage(0).augmenterTeintePixel(1, 1, 50, 'B');

	//10- Diminuer la teinte rouge du Pixel (1, 1) de l'image 0 de 255 unités
	groupe1.obtenirImage(0).augmenterTeintePixel(1, 1, -255, 'R');

	//11- Augmentez la teinte bleu du Pixel (2, 1) de l'image 1 de 100 unités
	groupe1.obtenirImage(1).augmenterTeintePixel(2, 1, 100, 'B');

	//12- Affichez les images de ce groupe
	cout <<endl << "***** Groupe d images " << groupe1.obtenirType() << " " << "apres modification de couleur *****" << endl;
	groupe1.afficherImages();

	//13- Doublez la taille de la premiere image du groupe en largeur	
	groupe1.doublerTailleImageEnLargeur(0);

	//14- Doublez la taille de la deuxieme image du groupe en hauteur
	groupe1.doublerTailleImageEnHauteur(1);

	//15- Afficher cette image 
	cout << endl << "***** Deuxieme image avec une taille deux fois plus grande ***" << endl;
	groupe1.obtenirImage(1).afficherImage();
	cout << endl;

	
	image1.~Image();
	image2.~Image();
	groupe1.~GroupImage();
	return 0;
}