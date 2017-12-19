/****************************************************************************
* Fichier: GroupeImage.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Mise a jour : 20 nov 2017
* Description: Implémentation de la classe GroupeImage
****************************************************************************/

#include "GroupeImage.h"

using namespace std;

/****************************************************************************
* Fonction:		GroupeImage::GroupeImage
* Description:	Constructeur par défaut
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
GroupeImage::GroupeImage() {};


/****************************************************************************
* Fonction: GroupImage
* Description: Constructeur par paramètres
* Paramètres: GroupeImage : groupe
* Retour: aucun
****************************************************************************/
GroupeImage::GroupeImage(const GroupeImage& groupe) : images_(groupe.images_) {}


/****************************************************************************
* Fonction:		GroupeImage::~GroupeImage
* Description:	Destructeur par default
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
GroupeImage::~GroupeImage() {};


/****************************************************************************
* Fonction: operator=
* Description: affecte le groupe d'image en paramètre au groupe actuelle
* Paramètres: - objet image : GroupeImage* groupeImage
* Retour: adresse du GroupeImage
****************************************************************************/
GroupeImage& GroupeImage::operator=(const GroupeImage &groupe) {

	images_.clear();
	list<Image*>::const_iterator end = groupe.images_.end();
	for(list<Image*>::const_iterator pos = groupe.images_.begin(); pos != end; pos++)
	{
		images_.insert(pos, *pos);
	}

	return *this;
}


/****************************************************************************
* Fonction: ajouterImage
* Description: retourne si l'image a été ajoutée
* Paramètres: - pointeur Image
* Retour: booléen
****************************************************************************/
bool GroupeImage::ajouterImage(Image* image) {		
	FoncteurImagesDeMemeNom memeNom(image->obtenirNomImage());
	list<Image*>::iterator it = find_if(images_.begin(), images_.end(), memeNom);
	if (it != images_.end())
	{
		cout << image->obtenirNomImage() << " n'a pas ete ajoute" << endl;
		return false;
	}														
														
	images_.push_back(image);
	cout << image->obtenirNomImage() << " a bien ete ajoute" << endl;
	return true;
}


/****************************************************************************
* Fonction: retirerImage
* Description: retourne si l'image a été retirée
* Paramètres: - string nom
* Retour: booléen
****************************************************************************/
bool GroupeImage::retirerImage(const std::string& nom) {
	list<Image*>::iterator pos = remove_if(images_.begin(), images_.end(), FoncteurImagesDeMemeNom(nom));
	list<Image*>::iterator fin = images_.end();
	if (pos == fin)
	{
		cout << nom << " n'a pas ete retire" << endl;	   
		return false;
	}
	else
		cout << nom << " a bien ete retire" << endl;
	return true;
}


/****************************************************************************
* Fonction: afficherImages
* Description: afiche un groupe d'images
* Paramètres: - ostream& os
* Retour:aucun
****************************************************************************/
void GroupeImage::afficherImages(ostream& os) const {

	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;
	os << "**************************************************" << endl << endl;

	list<Image*>::const_iterator fin = images_.end();
	list<Image*>::const_iterator pos = images_.begin();
	for ( pos; pos != fin; pos++) {
		os << *pos << "--------------------------------------------------" << endl;
	}
	os << endl;
	return;
}

/****************************************************************************
* Fonction: obtenirImage
* Description: retourne une image
* Paramètres: - unsigned int indiceImage: valeur de indiceImage_
* Retour: pointeur Image
****************************************************************************/
Image* GroupeImage::obtenirImage(const std::string& nom) const {
	FoncteurImagesDeMemeNom foncteurNom(nom);
	list<Image*>::const_iterator pos = find_if(images_.begin(), images_.end(), foncteurNom);
	return *pos;
}

/****************************************************************************
* Fonction:		GroupeImage::operator+=
* Description:	operateur d'incrementation
* Paramètres:	(Image) image: valeur d'une classe image(IN)
* Retour:		*this
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
	os << "**************************************************" << endl;
	os << "Affichage des images du groupe :  " << endl;

	os << "**************************************************" << endl << endl;
	list<Image*>::const_iterator pos = groupeImage.images_.begin();
	list<Image*>::const_iterator fin = groupeImage.images_.end();
	for (pos ; pos != fin; pos++) {
		os << *pos << "--------------------------------------------------" << endl;
	}
	os << endl;
	return os;
}

/****************************************************************************
* Fonction: obtenirNombreImages
* Description: retourne la taille du groupe d'image
* Paramètres: aucun
* Retour: unsigned int : la taille du groupe
****************************************************************************/
unsigned int GroupeImage::obtenirNombreImages() const {
	return images_.size();
}

/****************************************************************************
* Fonction: toutenregister
* Description: Enregistre le groupe d'image dans un dossier
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
void GroupeImage::toutEnregistrer() {
	cout << endl;
	//unsigned int i;
	//for (i = 0; i < images_.size(); i++) {
	//	Image* image = images_[i];
	//	string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
	//		+ "/im" + to_string(i) + image->obtenirNomImage();
	//	cout << "Sauvegarde de " << nom << endl;
	//	images_[i]->sauvegarderImage(nom);
	//}

	unsigned int i = 0;
	for (list<Image*>::iterator it = images_.begin(); it != images_.end(); it++) {
		Image* image = *it;												
		string nom = "./Ensemble d'images/" + image->obtenirTypeEnString()
			+ "/im" + to_string(i) + image->obtenirNomImage();
		cout << "Sauvegarde de " << nom << endl;
		(*it)->sauvegarderImage(nom);
		i++;
	}
}

/****************************************************************************
* Fonction: obtenirImageParIndex
* Description: retourne l'image selon l'index en paramètre
* Paramètres: - int index
* Retour: Image* : un pinteur sur l'image identifié en paramètre
****************************************************************************/
Image* GroupeImage::obtenirImageParIndex(int index)
{
	list<Image*>::iterator it = images_.begin();
	advance(it, index);
	return  *it;
}


/****************************************************************************
* Fonction: obtenirIntensiteMoyenne
* Description: retourne l'intensité moyenne du groupe
* Paramètres: aucun
* Retour: double : l'intensité moyenne
****************************************************************************/
double GroupeImage::obtenirIntensiteMoyenne() {
	double sommeIntensites = 0.0;

	list<Image*>::iterator end = images_.end();
	for (list<Image*>::iterator pos = images_.begin(); pos != end; pos++)
	{
		sommeIntensites = sommeIntensites + (*pos)->obtenirIntensiteMoyenne();
	}
	double moyIntensite = sommeIntensites / images_.size();
	return moyIntensite; 
}

/****************************************************************************
* Fonction: obtenirTailleMoyenne
* Description: retourne la taille moyenne du groupe
* Paramètres: aucun
* Retour: double : la taille moyenne
****************************************************************************/
double GroupeImage::obtenirTailleMoyenne()
{
	list<Image*>::iterator pos = images_.begin();
	list<Image*>::iterator fin = images_.end();
	double sommeTailles = 0.0;
	while (pos != fin)
	{
		sommeTailles = sommeTailles + (*pos)->obtenirTaille();
		++pos;
	};

	double moy = sommeTailles / images_.size();																				
	return moy;
}

