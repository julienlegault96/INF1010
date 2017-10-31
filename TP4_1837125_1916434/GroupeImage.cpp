/**************************************************************************
* Fichier: GroupImage.cpp
* Auteur : Arnaud Lebrun et Julien Legault
* Date : 4 oct 2017
* Mise a jour : 22 oct 2017
* Description : Implémentation de la classe GroupeImage
****************************************************************************/

//
// Created by Gabriel Bernard
//
#include <iostream>
#include "GroupeImage.h"


using namespace std;

/****************************************************************************
* Fonction: GroupImage
* Description: Constructeur par defaut
* Paramètres: -aucun
* Retour: aucun
****************************************************************************/
GroupeImage::GroupeImage() {};

/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
GroupeImage::~GroupeImage() {};


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
* Fonction: afficherImages
* Description: afiche un groupe d'images
* Paramètres: - ostream& os
* Retour:aucun
****************************************************************************/
void GroupeImage::afficherImages(ostream& os ) const {

    os << endl;
    os << "**************************************************" << endl;
    os << "Affichage des images du groupe :  " << endl;
    os << "**************************************************" << endl << endl;

    for  (unsigned int j= 0; j < images_.size(); j++) {
        os << *images_[j] << "--------------------------------------------------" << endl;
    }
    os << endl;
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
std::ostream& operator<<(std::ostream& os, const GroupeImage& groupeImage)
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


Image* GroupeImage::operator[](const unsigned int& indice) const {
    if(indice >= images_.size()) {
        cerr << "L'indice est plus grand que la quantite d'image present dans ce groupe." << endl;
        return nullptr;
    }
    return images_[indice];
}

unsigned int GroupeImage::obtenirNombreImages() const {
    return images_.size();
}


/****************************************************************************
* Fonction: toutMettreEnNB
* Description: Convertit l'image en noire et blanc
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutMettreEnNB(){
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirNB();
    }
    cout << endl;
}


/****************************************************************************
* Fonction: toutMettreEnGris
* Description: Convertit l'image en gris
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutMettreEnGris() {
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirGris();
    }
    cout << endl;
}


/****************************************************************************
* Fonction: toutMettreEnCouleur
* Description: Convertit l'image en couleur
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutMettreEnCouleur() {
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        images_[i]->convertirCouleurs();
    }
    cout << endl;
}


/****************************************************************************
* Fonction: toutenregister
* Description: Enregistre le groupe d'image dans un dossier
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutEnregistrer() {
    unsigned int i;
    for(i = 0; i < images_.size(); i++) {
        Image* image = images_[i];
        string nom = "../TP4/Ensemble d'images/" + image->obtenirTypeEnString()
                     + "/im" + to_string(i) + image->obtenirNomImage();
        cout << "Sauvegarde de " << nom << endl;
        images_[i]->sauvegarderImage(nom);
    }
    cout << endl;
}

/****************************************************************************
* Fonction: GroupImage
* Description: Construit une copie identique du groupe d'images
* Paramètres: - const GroupeImage& groupeImage
* Retour: aucun
****************************************************************************/
// Constructeur par copie
GroupeImage::GroupeImage(const GroupeImage& groupeImage)
{
	std::vector<Image*> images_;
	for (unsigned int i = 0; i < groupeImage.images_.size(); i++)
	{
		images_.push_back(new Image(*groupeImage.images_[i]));
	}
				
}


/****************************************************************************
* Fonction: operator=
* Description: affecte le groupe d'image en paramètre au groupe actuelle
* Paramètres: - objet image : GroupeImage* groupeImage
* Retour: adresse du GroupeImage
****************************************************************************/
GroupeImage& GroupeImage::operator=(const GroupeImage& groupeImage)
{
	if (this != &groupeImage)
	{																																				   
		for (unsigned int i = 0; i < images_.size(); i++)
		{
			images_.pop_back();
		}
		for (unsigned int i = 0; i < groupeImage.images_.size(); i++)
		{
			images_.push_back(new Image(*groupeImage.images_[i]));
		}
	}
	return *this;
}


/****************************************************************************
* Fonction: MettreGroupeEnNegatif
* Description: inverse les couleur des pixels du groupe 
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::MettreGroupeEnNegatif() const
{
	for (unsigned int i = 0; i < images_.size(); i++)
	{
		images_[i]->MettreImageEnNegatif();
	}
}