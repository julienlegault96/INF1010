/**************************************************************************
* Fichier: GroupImage.cpp
* Auteur : Arnaud Lebrun et Julien Legault
* Date : 4 oct 2017
* Mise a jour : 22 oct 2017
* Description : Implémentation de la classe GroupeImage
****************************************************************************/
#include <iostream>
#include <string>
#include "GroupeImage.h"

#include <sstream>


using namespace std;

/****************************************************************************
* Fonction: GroupImage
* Description: Constructeur par defaut
* Paramètres: -aucun
* Retour: aucun
****************************************************************************/
GroupeImage::GroupeImage() {};


/****************************************************************************
* Fonction: ajouterImage
* Description: retourne si l'image a été ajoutée
* Paramètres: - pointeur Image 
* Retour: booléen
****************************************************************************/
bool GroupeImage::ajouterImage(Image* image) {
    for (unsigned int i = 0; i <  images_.size(); i++)
    {
        if (image->obtenirNomImage() == *(images_[i]))
        {
            cout << image->obtenirNomImage() << " n'a pas ete ajoute" << std::endl;
            return false;
        }
    }
    images_.push_back(image);
    std::cout << image->obtenirNomImage() << " a bien ete ajoute" << std::endl;
    return true;
}


/****************************************************************************
* Fonction: retirerImage
* Description: retourne si l'image a été retirée
* Paramètres: - string nom
* Retour: booléen
****************************************************************************/
bool GroupeImage::retirerImage(const std::string& nom) {
    for (unsigned int i = 0; i < images_.size(); i++)
    {
        if (*(images_[i]) == nom)
        {
            images_[i] = images_.back();
            images_.pop_back();
            cout << nom << " a bien ete retire" << endl;
            return true;
        }
    }
    return false;
}


/****************************************************************************
* Fonction: obtenirType
* Description: retourne une image
* Paramètres: - unsigned int indiceImage: valeur de indiceImage_
* Retour: pointeur Image
****************************************************************************/
Image* GroupeImage::obtenirImage(unsigned int indiceImage) const {
    return images_[indiceImage];
}


/****************************************************************************
* Fonction: operator+=
* Description: ajoute une image au groupe d'image
* Paramètres: - objet image : pointeur Image
* Retour: Classe GroupeImage
****************************************************************************/
GroupeImage& GroupeImage::operator+=(Image* image)
{
    ajouterImage(image);
    return *this;
}


/****************************************************************************
* Fonction: operator-=
* Description: retire une image au groupe d'image
* Paramètres: - objet image : pointeur Image
* Retour: Classe GroupeImage
****************************************************************************/
GroupeImage& GroupeImage::operator-=(Image* image)
{
    retirerImage(image->obtenirNomImage());
    return *this;
}


/****************************************************************************
* Fonction: operator<<
* Description: afiche un groupe d'images
* Paramètres: - parametres sortie
			  - objet groupeImage
* Retour: operateur de sortie
****************************************************************************/
ostream& operator<<(ostream& os, const GroupeImage& groupeImage)
{
    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;
    
    for  (unsigned int j= 0; j < groupeImage.images_.size(); j++) {
        os << *groupeImage.images_[j] << "--------------------------------------------------" << endl;
    }
    
    os << endl;

    return os;
}

/****************************************************************************
* Fonction: toutMettreEnNB
* Description: Convertit l'image en noire et blanc
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutMettreEnNB()
{
	for (unsigned int i = 0; i < images_.size(); i++) {
		images_[i]->convertirNB();
	}
}

/****************************************************************************
* Fonction: toutMettreEnGris
* Description: Convertit l'image en gris
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutMettreEnGris()
{
	for (unsigned int i = 0; i < images_.size(); i++) {
		images_[i]->convertirGris();
	}
}

/****************************************************************************
* Fonction: toutMettreEnCouleur
* Description: Convertit l'image en couleur
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutMettreEnCouleur()
{
	for (unsigned int i = 0; i < images_.size(); i++) {
		images_[i]->convertirCouleur();
	}
}

/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
GroupeImage::~GroupeImage() {};


/****************************************************************************
* Fonction: toutenregister
* Description: Enregistre le groupe d'image dans un dossier
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutEnregistrer() 
{
	for (unsigned int i = 0; i < images_.size(); i++)
	{
		//cout << images_[i]->obtenirTypeEnString() << endl;

		std::stringstream sChaine;
		sChaine << "./Ensemble d'image/" << images_[i]->obtenirTypeEnString() << "/" << images_[i]->obtenirNomImage();
		std::string chaine = sChaine.str();

		//string chaine1 = ;
		//string chaine2 = ;
		//string chaine3 = ;
		//string chaine4 = ;
		//string chaine =  chaine1 + chaine2 + chaine3 + chaine4 ;
		
		//images_[i].sauvegarderImage("./Ensemble d'images/" + images_[i].obtenirTypeEnString() + "/" + images_[i].obtenirNomImage());
		//images_[i]->sauvegarderImage("./Ensemble d'images/" + images_[i]->obtenirTypeEnString() + "/" + images_[i]->obtenirNomImage());
		images_[i]->sauvegarderImage(chaine);

	}
}
