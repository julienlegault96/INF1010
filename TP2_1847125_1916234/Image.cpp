/****************************************************************************
* Fichier: Pixel.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 13 sept 2017
* Mise a jour : 02 oct 2017
* Description: Implémentation de la classe Image
****************************************************************************/
#include "Image.h"
#include "Image.h"
#include <iostream>
#include "Const.h"

using namespace std;


/****************************************************************************
* Fonction: Image ::Image
* Description: Constructeur par défaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
Image::Image():nomImage_("Image Vide"),nombrePixelEnHauteur_(1),nombrePixelEnLargeur_(1)
{
	pixels_ = new Pixel*[1];
	pixels_[0] = new Pixel[1];
}


/****************************************************************************
* Fonction: Image ::Image
* Description: Destructeur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
Image::~Image()
{
	/*
	for(unsigned int i = 0; i < nombrePixelEnHauteur_; i++){
		delete[] pixels_[i];
	}
	delete[] pixels_;
	nombrePixelEnHauteur_ = 0;
	nombrePixelEnLargeur_ = 0;
	pixels_ = nullptr;
	*/
}


/****************************************************************************
* Fonction: Image ::Image
* Description: Constructeur par liste d'initialisation
* Paramètres: - string nomImage: valeur de nomImage_(IN)
- unsigned int nombrePixelEnHauteur: nombrePixelEnHauteur_(IN)
- unsigned int nombrePixelEnLargeur: nombrePixelEnLargeur_(IN)
* Retour: aucun
****************************************************************************/
Image::Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur) :nomImage_(nomImage),
	nombrePixelEnHauteur_(nombrePixelHauteur), nombrePixelEnLargeur_(nombrePixelLargeur)
{
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0; i < nombrePixelEnHauteur_;i++){
		pixels_[i] = new Pixel[nombrePixelEnLargeur_];
	}
}


/****************************************************************************
* Fonction: Image ::Image
* Description: Constructeur par copie et liste d'initialisation
* Paramètres: - Image image : qui sera copuée dans l'objet
* Retour: aucun
****************************************************************************/
Image::Image(const Image& copieImage) : nombrePixelEnHauteur_(copieImage.nombrePixelEnHauteur_), nombrePixelEnLargeur_(copieImage.nombrePixelEnLargeur_), nomImage_(copieImage.nomImage_), pixels_(0) {
	pixels_ = new Pixel*[nombrePixelEnHauteur_];
	for (int i = 0; i < nombrePixelEnHauteur_; i++)
		pixels_[i] = new Pixel[i];
	for (int ligne = 0; ligne < nombrePixelEnHauteur_; ++ligne) {
		for (int colonne = 0; colonne < nombrePixelEnLargeur_; ++colonne) {
			pixels_[ligne][colonne] = copieImage.obtenirPixel(ligne, colonne);
		}
	}
}


/****************************************************************************
* Fonction: Image ::Image
* Description: modifierNomImage
* Paramètres : string nomImage: la nouvelle valeur de nomImage_ (IN)
* Retour: aucun
****************************************************************************/
void Image::modifierNomImage(const string & nomImage) {
	nomImage_ = nomImage;
}


/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirNombrePixelHauteur
* Paramètres : aucun
* Retour: unsigned int nombrePixelEnHauteur_ : la hauteur en pixels
****************************************************************************/
unsigned int Image::obtenirNombrePixelHauteur() const {
	return nombrePixelEnHauteur_;
}


/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirNombrePixelLargeur
* Paramètres : aucun
* Retour: unsigned int nombrePixelEnLargeur_ : la largeur en pixels
****************************************************************************/
unsigned int Image::obtenirNombrePixelLargeur() const {
	return nombrePixelEnLargeur_;
}


/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirNomImage
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
string Image::obtenirNomImage() const{
	return nomImage_;
}


/****************************************************************************
* Fonction: Image ::Image
* Description: ajouterPixel
* Paramètres : - Pixel pixel : -la nouvelle valeur de pixel_ (IN)
- unsigned int positionLargeur
- unsigned int positionHauteur
* Retour: booléen
****************************************************************************/
bool Image::ajouterPixel(Pixel & pixel, unsigned int positionLargeur, unsigned int positionHauteur) {
	if (positionLargeur >= nombrePixelEnLargeur_ || positionHauteur >= nombrePixelEnHauteur_) {
		return false;
	}
	else {
		pixels_[positionHauteur][positionLargeur] = pixel;
		return true;
	}
}


/****************************************************************************
* Fonction: Image ::Image
* Description: doublerTailleEnHauteur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
void Image::doublerTailleEnHauteur(){
	nombrePixelEnHauteur_ *= 2;

	Pixel** imageTemp = new Pixel*[nombrePixelEnHauteur_];
	for (unsigned int i = 0;i < nombrePixelEnHauteur_ / 2;i++) {
		imageTemp[i] = pixels_[i];
	}

	for (unsigned int i = nombrePixelEnHauteur_ / 2;i < nombrePixelEnHauteur_;i++) {
		imageTemp[i] = new Pixel[nombrePixelEnLargeur_];
	}	

	delete[] pixels_;
	pixels_ = imageTemp;
	imageTemp = nullptr;

}


/****************************************************************************
* Fonction: Image ::Image
* Description: doublerTailleEnLargeur
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
void Image::doublerTailleEnLargeur() {
	nombrePixelEnLargeur_ *= 2;

	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		Pixel* colonneImage = new Pixel[nombrePixelEnLargeur_];
		for (unsigned int j = 0;j < nombrePixelEnLargeur_ / 2; j++) {
			colonneImage[j] = pixels_[i][j];
		}
		delete[] pixels_[i];
		pixels_[i] = colonneImage;
	}
}


/****************************************************************************
* Fonction: Image ::Image
* Description: afficherImage
* Paramètres : aucun
* Retour: aucun
****************************************************************************/
void Image::afficherImage() const {

	cout << "Affichage de l'image :  " << obtenirNomImage().c_str()<< endl;
	
	for (unsigned int i = 0; i < nombrePixelEnHauteur_; i++) {
		cout << "    ";
			for (unsigned int j = 0; j < nombrePixelEnLargeur_;j++) {
					cout << pixels_[i][j];
		    }
		cout << endl;
	}
}


/****************************************************************************
* Fonction: Image ::Image
* Description: obtenirPixel
* Paramètres   - unsigned int positionLargeur
*	      		- unsigned int positionHauteur
* Retour: Pixel
****************************************************************************/
Pixel Image::obtenirPixel(unsigned int positionLargeur,unsigned int positionHauteur) const {
 
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
void Image::augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur) {

	if (couleur == 'R') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteRouge(increment);
	}
	if (couleur == 'G') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteVert(increment);
	}
	if (couleur == 'B') {
		pixels_[positionHauteur][positionLargeur].modifierTeinteBleu(increment);
	}

}


/****************************************************************************
* Fonction: Image ::Image
* Description: operator= surcharge de l'opérateur d'affectation
* Paramètres   - unsigned int copieImage : celle qui sera copiée dans l'objet
* Retour: Image : la nouvelle image
****************************************************************************/
Image & Image::operator=(const Image & copieImage) {
	if (this != &copieImage) {
		delete pixels_;
		Image temp(copieImage);
		nombrePixelEnHauteur_ = copieImage.nombrePixelEnHauteur_;
		nombrePixelEnLargeur_ = copieImage.nombrePixelEnLargeur_;
		nomImage_ = copieImage.nomImage_;
		Pixel ** nouveau(temp.pixels_);
		temp.pixels_ = pixels_;
		pixels_ = nouveau;
	}
		return *this;	
}


/****************************************************************************
* Fonction: Image ::Image
* Description: operator<< surcharge de l'opérateur de flux de sortie
* Paramètres   - ostream sortie : l'information qui va être affichée
*				- image image : l'image qui sera affichée
* Retour: ostream : ce qui sera affiché
****************************************************************************/
ostream& operator<<(ostream& sortie, const Image & image)
{
	sortie << "Affichage de l'image :  " << image.obtenirNomImage().c_str() << endl;

	for (unsigned int i = 0; i < image.obtenirNombrePixelHauteur(); i++) {
		sortie << "    ";
		for (unsigned int j = 0; j < image.obtenirNombrePixelLargeur(); j++) {
			sortie << image.obtenirPixel(i, j);
		}
		sortie << endl;
	}
	return sortie;
}


/****************************************************************************
* Fonction: Image ::Image
* Description: operator== surcharge de l'opérateur de comparaison
* Paramètres   - Image image : l'image avec laquelle l'objet courant sera comparé
* Retour: bool : résultat comparaison
****************************************************************************/
bool Image::operator==(const Image & image)
{
	if (nomImage_ != image.obtenirNomImage())
	{
		return false;
	}

	for (unsigned int i = 0; i < image.obtenirNombrePixelHauteur(); i++) {
		for (unsigned int j = 0; j < image.obtenirNombrePixelLargeur(); j++) {
			if (!(pixels_[i][j] == image.obtenirPixel(i, j)))
			{
				return false;
			}
		}
	}
	return true;
}


/****************************************************************************
* Fonction: Image ::Image
* Description: operator== surcharge de l'opérateur de comparaison
* Paramètres   - string nom : le nom avec lequel le nom de l'image courante sera comparé
* Retour: bool : résultat comparaison
****************************************************************************/
bool Image::operator==(const string & nom)
{
	return (nomImage_ == nom);
}


/****************************************************************************
* Fonction: Image ::Image
* Description: operator== surcharge de l'opérateur de comparaison
* Paramètres   - string nom : le nom avec lequel le nom de l'image en paramètre sera comparé
*				- Image Image : l'image pour laquelle on veut vérifier le nom
* Retour: bool : résultat comparaison
****************************************************************************/
bool operator==(const string & nom, const Image & Image)
{
	return (nom == Image.obtenirNomImage());
}