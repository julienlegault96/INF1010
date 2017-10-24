/**************************************************************************
* Fichier: GroupImage.cpp
* Auteur : Arnaud Lebrun et Julien Legault
* Date : 13 sept 2017
* Mise a jour : 24 seot 2017
* Description : Implémentation de la classe GroupImage
****************************************************************************/
#include "GroupImage.h"

/****************************************************************************
* Fonction: GroupImage
* Description: Constructeur par defaut
* Paramètres: -aucun
* Retour: aucun
****************************************************************************/
GroupImage::GroupImage()
{
	type_ = "" ;
	nombreImages_ = 0 ;
	capaciteImages_ = 0 ;
	images_ = nullptr ;
}


/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Paramètres: -aucun
* Retour: aucun
***************************************************************************/
GroupImage::~GroupImage()
{
	//rien
}


/****************************************************************************
* Fonction: GroupImage
* Description: Constructeur par paramètre
* Paramètres: - string type: valeur de type_ (IN)
 *            - unsigned int capaciteImages: valeur de capaciteImages_ (IN)
* Retour: aucun
****************************************************************************/
GroupImage::GroupImage(const string & type, unsigned int capaciteImages)
{
	type_ = type ;
	nombreImages_ = 0 ;
	capaciteImages_ = capaciteImages ;
	images_ = new Image[capaciteImages];
}


/****************************************************************************
* Fonction: GroupImage
* Description: modifierType
* Paramètres: - string type: valeur de type_ (IN)
* Retour: aucun
****************************************************************************/
void GroupImage::modifierType(const string &type)
{
	type_= type ;
}


/****************************************************************************
* Fonction: GroupImage
* Description: obtenirType
* Paramètres: - aucun
* Retour: (string) la valeur de type_
****************************************************************************/
string GroupImage::obtenirType() const
{
	return type_ ;
}


/****************************************************************************
* Fonction: GroupImage
* Description: obtenirType
* Paramètres: - unsigned int indiceImage: valeur de indiceImage_
* Retour: (string) la valeur de type_
****************************************************************************/
Image GroupImage::obtenirImage(unsigned int indiceImage) const
{
	return images_[indiceImage];
}


/****************************************************************************
* Fonction: GroupImage
* Description: obtenirNombreImages
* Paramètres: - aucun
* Retour: (unsigned int) la valeur de nombreImages_
****************************************************************************/
unsigned int GroupImage::obtenirNombreImages() const
{
	return nombreImages_ ;
}


/****************************************************************************
* Fonction: GroupImage
* Description: ajouterImage
* Paramètres: - Image image
* Retour: aucun
****************************************************************************/
void GroupImage::ajouterImage(const Image &image)
{
	if (nombreImages_ < capaciteImages_)
	{
		images_[nombreImages_++] = image;
	}
	else
		cout << "Plus de place restante" << endl;
}


/****************************************************************************
* Fonction: GroupImage
* Description: afficherImages
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupImage::afficherImages() const
{
	for (unsigned int i = 0; i < nombreImages_; i++)
	{
		images_[i].afficherImage();
	}
}

/****************************************************************************
* Fonction: GroupImage
* Description: doublerTailleImageEnLargeur
* Paramètres: - unsigned int indiceImage
* Retour: aucun
****************************************************************************/
void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage)
{
	images_[indiceImage].doublerTailleEnLargeur();
}


/****************************************************************************
* Fonction: GroupImage
* Description: doublerTailleImageEnHauteur
* Paramètres: - unsigned int indiceImage
* Retour: aucun
****************************************************************************/
void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage)
{
	images_[indiceImage].doublerTailleEnHauteur();
}
