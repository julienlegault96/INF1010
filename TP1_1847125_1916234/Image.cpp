/****************************************************************************
* Fichier: Pixel.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 13 sept 2017
* Mise a jour : 24 seot 2017
* Description: Implémentation de la classe Image
****************************************************************************/
#include "Image.h"
#include "Const.h"

/****************************************************************************
* Fonction: Image ::Image
* Description: Constructeur par default
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
Image::Image() 
{
	nomImage_ = "";
	nombrePixelEnHauteur_ = 1;
	nombrePixelEnLargeur_ = 1;
	pixels_ = nullptr;
}

/****************************************************************************
* Fonction: Image ::Image
* Description: Constructeur par paramètres
* Paramètres: - string nomImage: valeur de nomImage_(IN)
			  - unsigned int nombrePixelEnHauteur: nombrePixelEnHauteur_(IN)
			  - unsigned int nombrePixelEnLargeur: nombrePixelEnLargeur_(IN)
* Retour: aucun
****************************************************************************/
Image::Image(const string& nomImage,unsigned int nombrePixelEnHauteur,unsigned int nombrePixelEnLargeur)
{	
	nomImage_ = nomImage;
	nombrePixelEnHauteur_ = nombrePixelEnHauteur;
	nombrePixelEnLargeur_ = nombrePixelEnLargeur;
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++)
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
}

/****************************************************************************
* Fonction: Image ::Image
* Description: Destructeur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
Image::~Image() {
	// rien
}

/****************************************************************************
* Fonction: Image ::Image
* Description: doublerTailleEnLargeur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
void Image::doublerTailleEnLargeur()
{
	// création nouvelle image
	nombrePixelEnLargeur_ = 2 * nombrePixelEnLargeur_;
	Pixel** ImageLargeurDouble = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++)
	{
		ImageLargeurDouble[i] = new Pixel[nombrePixelEnLargeur_];
	}
	
	// copie du contenu de l'ancienne vers la nouvelle
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++)
	{
		for (unsigned int j = 0; j < nombrePixelEnLargeur_/2; j++)
		{
			ImageLargeurDouble[i][j] = pixels_[i][j];
		}
	}

	delete[] pixels_;
	pixels_=ImageLargeurDouble;
}

/****************************************************************************
* Fonction: Image ::Image
* Description: doublerTailleEnHauteur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
void Image::doublerTailleEnHauteur()
{
	// création nouvelle image
	nombrePixelEnHauteur_ = 2 * nombrePixelEnHauteur_;
	Pixel** ImageLargeurDouble = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++)
	{
		ImageLargeurDouble[i] = new Pixel[nombrePixelEnLargeur_];
	}
	
	// copie du contenu de l'ancienne vers la nouvelle
	for (unsigned int i = 0; i < nombrePixelEnHauteur_/2; i++)
	{
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++)
		{
			ImageLargeurDouble[i][j] = pixels_[i][j];
		}
	}

	delete[] pixels_;
	pixels_=ImageLargeurDouble;	
}

/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirNombrePixelHauteur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
unsigned int Image::obtenirNombrePixelHauteur() const 
{
	return nombrePixelEnHauteur_;
}

/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirNombrePixelLargeur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
unsigned int Image::obtenirNombrePixelLargeur() const
{
	return nombrePixelEnLargeur_;
}

/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirNomImage
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
string Image::obtenirNomImage() const
{
	return nomImage_;
}

/****************************************************************************
* Fonction: Image ::Image
* Description: modifierNomImage
* Paramètres : string nomImage: la nouvelle valeur de nomImage_ (IN)
* Retour: aucun
****************************************************************************/
void Image::modifierNomImage(const string & nomImage) 
{
	nomImage_ = nomImage;
}


/****************************************************************************
* Fonction: Image ::Image
* Description: afficherImage
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
void Image::afficherImage() const
{
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		cout << "\t";
		for (unsigned int j = 0; j < nombrePixelEnLargeur_; j++) {
				pixels_[i][j].afficherPixel();
		}
		cout << endl;
	}
	cout << endl;
}

/****************************************************************************
* Fonction: Image ::Image
* Description: ajouterPixel
* Paramètres : - Pixel pixel : -la nouvelle valeur de pixel_ (IN)
			   - unsigned int positionLargeur
			   - unsigned int positionHauteur
* Retour: booléen
****************************************************************************/
bool Image:: ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) 
{
	if ((positionHauteur > nombrePixelEnHauteur_) || (positionLargeur > nombrePixelEnLargeur_))
		return false;
	else
		pixels_[positionHauteur][positionLargeur] = pixel;
		return true;
}

/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirPixel
* Paramètres   - unsigned int positionLargeur
			   - unsigned int positionHauteur
* Retour: Pixel
****************************************************************************/
Pixel Image :: obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const
{
	return pixels_[positionHauteur][positionLargeur];
}

/****************************************************************************
* Fonction: Image ::Image
* Description: augmenterTeintePixel
* Paramètres   - unsigned int positionLargeur
			   - unsigned int positionHauteur
			   - int increment 
			   - char couleur
* Retour: Pixel
****************************************************************************/
void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int increment, char couleur)
{
	if (couleur == 'R')
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	else if (couleur == 'B')
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
	else if (couleur == 'V')
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	else
		cout << "Couleur invalide" << endl;
}