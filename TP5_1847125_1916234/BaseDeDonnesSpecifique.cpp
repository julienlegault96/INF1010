/****************************************************************************
* Fichier:BaseDeDonnesSpecifique.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 8 nov 2017
* Mise a jour : 20 nov 2017
* Description: Impl�mentation de la classe BaseDeDonnesSpecifique
****************************************************************************/
#include "BaseDeDonnesSpecifique.h"

using namespace std;


/****************************************************************************
* Fonction:		AssocierImage
* Description:	ajoute une image � un groupe d'images
* Param�tres:	 groupe: pointeur vers un groupe d'images
				 image: pointeur vers une image
* Retour:		bool�en
****************************************************************************/
bool BaseDeDonnesSpecifique::AssocierImage(GroupeImage* groupe, Image* image)
{
	if (groupe->ajouterImage(image)) {
		ajouter(image);
		return true;
	}
	return false;		  
}


/****************************************************************************
* Fonction:		EnleverImage
* Description:	retire une image d'un groupe d'images
* Param�tres:	 groupe : pointeur vers un groupe d'images (IN)
				image : pointeur vers une image (IN)
* Retour:		bool�en
****************************************************************************/
bool BaseDeDonnesSpecifique::EnleverImage(GroupeImage* groupe, const std::string& nomImage)
{
	if(groupe->retirerImage(nomImage))
		return true;
	return false;
}


/****************************************************************************
* Fonction:		operator<<
* Description:	affiche le nombre d'images dans le groupe et le nom de chaque image
* Param�tres:	 database:  Base de donn�es � afficher (IN)
				 os: conteneur de l'affichage (IN)
* Retour:		ostream
****************************************************************************/
ostream& operator<<(std::ostream& os, const BaseDeDonnesSpecifique& dataBase) {
	os << "Nombre d'images dans la liste d'image: " << dataBase.obtenirListImages().size() << endl;	
	list<Image*>::const_iterator fin = dataBase.listImage_.end();
	for (list<Image*>::const_iterator pos = dataBase.listImage_.begin(); pos != fin; ++pos) {
		os << "Nom de l'image: " << (*pos)->obtenirNomImage() << endl;
	}
	os << "Nombre de groupes dans la liste de groupe d'image: " <<
	dataBase.obtenirListGroupeImages().size() << endl;
	return os;
}