/**************************************************************************
* Fichier: GroupImage.cpp
* Auteur : Arnaud Lebrun et Julien Legault
* Date : 13 sept 2017
* Mise a jour : 02 oct 2017
* Description : Implémentation de la classe GroupImage
****************************************************************************/
#include "GroupImage.h"
#include <iostream>
#include <string>

using namespace std;

/****************************************************************************
* Fonction: GroupImage
* Description: Constructeur par defaut
* Paramètres: -aucun
* Retour: aucun
****************************************************************************/
GroupImage::GroupImage():type_("par defaut") {}


/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Paramètres: -aucun
* Retour: aucun
***************************************************************************/
GroupImage::~GroupImage() {
	// Mettre ce destructeur occasionne des problèmes mémoire
	//for (unsigned int i = 0; i < Images_.size(); i++) {
	//	delete Images_[i];
	//}
}


/****************************************************************************
* Fonction: GroupImage
* Description: modifierType
* Paramètres: - string type: valeur de type_ (IN)
* Retour: aucun
****************************************************************************/
void GroupImage::modifierType(const string & type) {
	type_ = type;
}


/****************************************************************************
* Fonction: GroupImage
* Description: obtenirType
* Paramètres: - aucun
* Retour: (string) la valeur de type_
****************************************************************************/
string GroupImage::obtenirType() const{
	return type_;
}


/****************************************************************************
* Fonction: GroupImage
* Description: ajouterImage
* Paramètres: - Image image
* Retour: aucun
****************************************************************************/
void GroupImage::ajouterImage(Image* image) {
		
	bool NomPresent = false;
	for (unsigned int i = 0; i < Images_.size(); i++) {
		if (image->obtenirNomImage() == Images_[i]->obtenirNomImage()) {
			NomPresent = true;
		}
	}
	if (!NomPresent) {
		Images_.push_back(image);
	}
	cout << "L'image " << Images_[Images_.size() - 1 ]->obtenirNomImage() << " a bien ete ajoutee. " << endl ;
}


/****************************************************************************
* Fonction: GroupImage
* Description: retirerImage
* Paramètres: -string : nomImage
* Retour: aucun
****************************************************************************/
void GroupImage::retirerImage(const string & nomImage) 
{
	for (unsigned int i = 0; i < Images_.size(); i++)
	{
		if ( (*Images_[i]) == nomImage)
		{
			for (unsigned int j = i; j < Images_.size() - 1; j++) {
				Images_[j] = Images_[j + 1];
			}
			cout << "L'image " << nomImage << " a bien ete retiree." << endl;
			Images_.pop_back();
		}
	}
}


/****************************************************************************
* Fonction: GroupImage
* Description: afficherImages
* Paramètres: -ostream : sortie
* Retour: aucun
****************************************************************************/
void GroupImage::afficherImages(ostream& sortie) const {

	sortie << "*********************************************" << endl;
	sortie << "Affichage des images du groupe :  ";
	sortie << obtenirType() << endl;
	sortie << "*********************************************"<< endl;
	
	for (unsigned int i = 0; i <Images_.size(); i++) {

		sortie << *Images_[i];
		sortie << "---------------------------------------------" << endl;

	}
	sortie << endl;
}


/****************************************************************************
* Fonction: GroupImage
* Description: obtenirImage
* Paramètres: -unsigned int : indiceImage
* Retour: Image*
****************************************************************************/
Image* GroupImage::obtenirImage(unsigned int indiceImage) const {
	return Images_[indiceImage];
}


/****************************************************************************
* Fonction: GroupImage
* Description: doublerTailleImageEnLargeur
* Paramètres: -unsigned int : indiceImage
* Retour: aucun
****************************************************************************/
void GroupImage::doublerTailleImageEnLargeur(unsigned int indiceImage) {
	(*Images_[indiceImage]).doublerTailleEnLargeur();
}


/****************************************************************************
* Fonction: GroupImage
* Description: doublerTailleImageEnHauteur
* Paramètres: -unsigned int : indiceImage
* Retour: aucun
****************************************************************************/
void GroupImage::doublerTailleImageEnHauteur(unsigned int indiceImage) {
	(*Images_[indiceImage]).doublerTailleEnHauteur();
}


/****************************************************************************
* Fonction: GroupImage
* Description: operateur d'ajout d'images
* Paramètres: -classe Image : image
* Retour: GroupImage
****************************************************************************/
 GroupImage &  GroupImage::operator +=  ( Image &image){
	 Image* pointeur = &image;
	 ajouterImage(pointeur);
	return *this;
}


 /****************************************************************************
 * Fonction: GroupImage
 * Description: operateur de retrait d'images
 * Paramètres: -classe Image : image
 * Retour: GroupImage
 ****************************************************************************/
GroupImage &  GroupImage::operator -= (Image &image){
	retirerImage(image.obtenirNomImage());
	return *this;
}


/****************************************************************************
* Fonction: GroupImage
* Description: Affichage d'image
* Paramètres: -paramètre de sortie
			  - GroupImage: g
* Retour: paramètre en sortie
****************************************************************************/
ostream& operator << (ostream& sortie, const GroupImage& g){
	 g.afficherImages(sortie);
	return sortie;
}