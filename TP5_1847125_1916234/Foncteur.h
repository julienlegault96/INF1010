/****************************************************************************
* Fichier: Foncteur.h
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 1 nov 2017
* Mise a jour : 20 nov 2017
* Description: Implémentation des foncteurs
****************************************************************************/

#ifndef  FONCTEUR
#define  FONCTEUR

#include "GroupeImage.h"
#include <cstdlib>
#include <random>
#include <ctime>
#include "Image.h"


#define RAND_MIN_DEFAUT 0
#define RAND_MAX_DEFAUT 3


class FoncteurEgalImages
{
public:
	FoncteurEgalImages(Image* image) {
		image_ = image;
	}
	~FoncteurEgalImages() {}

	bool FoncteurEgalImages::operator() (Image* imageAComparer) const {
		if (*imageAComparer == *image_)
			return true;
		else
			return false;
	}

private:
	Image* image_;
};


/****************************************************************************
* Fonction: FoncteurImagesDeMêmeNom
* Description: compare les noms de deux images
* Paramètres: le nom à comparer
* Retour: booléen
****************************************************************************/
class FoncteurImagesDeMemeNom
{
public:
	FoncteurImagesDeMemeNom(const std::string& nom) {
		nom_ = nom;
	}
	~FoncteurImagesDeMemeNom() {};

	bool operator() ( Image* image) const {
		if (nom_ == image->obtenirNomImage())
			return true;
		else
			return false;
	}

private:
	std::string nom_;
};


/****************************************************************************
* Fonction: FoncteurobtenirTailleImage
* Description: retourne la taille de l'image
* Paramètres: l'image
* Retour: unsigned int, la taille
****************************************************************************/
class FoncteurObtenirTailleImage
{
public:
	FoncteurObtenirTailleImage() {}
	~FoncteurObtenirTailleImage() {}

	unsigned int operator() (const Image* image) const {
		return image->obtenirTaille();
	}
};


/****************************************************************************
* Fonction: FoncteurMettreEnGris
* Description: met l'image en gris
* Paramètres: l'image
* Retour: aucun
****************************************************************************/
class FoncteurMettreEnGris
{
public:
	FoncteurMettreEnGris() {}
	~FoncteurMettreEnGris() {}

	void operator() (Image* image) {
		image->convertirGris();
	}

};


/****************************************************************************
* Fonction: FoncteurMettreEnCouleur
* Description: met l'image en couleurs
* Paramètres: l'image
* Retour: aucun
****************************************************************************/
class FoncteurMettreEnCouleur
{
public:
	FoncteurMettreEnCouleur() {}
	~FoncteurMettreEnCouleur() {}

	void operator() (Image* image) {
		image->convertirCouleur();
	}

};


/****************************************************************************
* Fonction: FoncteurMettreEnBN
* Description: met l'image en noir et blanc
* Paramètres: l'image
* Retour: aucun
****************************************************************************/
class FoncteurMettreEnBN
{
public:
	FoncteurMettreEnBN() {}
	~FoncteurMettreEnBN() {}

	void operator() (Image* image) {
		image->convertirBN();
	}

};


/****************************************************************************
* Fonction: FoncteurMettreEnNegatif
* Description: transforme l'image en son négatif
* Paramètres: l'image
* Retour: aucun
****************************************************************************/
class FoncteurMettreEnNegatif
{
public:
	FoncteurMettreEnNegatif() {}
	~FoncteurMettreEnNegatif() {}

	void operator() (Image* image) {
		image->mettreEnNegatif();
	}

};


/****************************************************************************
* Fonction: FoncteurgenerateurNombresAlea
* Description: retourne un nombre aléatoire
* Paramètres: unsigned int min et max les bornes de l'intervalle
* Retour: unsigned int le nombre aléatoire
****************************************************************************/
class FoncteurGenerateurNombresAlea
{
public:
	FoncteurGenerateurNombresAlea() {
		min_ = 0;
		max_ = 0;
	}

	FoncteurGenerateurNombresAlea(unsigned int min, unsigned int max) {
		srand((unsigned int)time(NULL));
		min_ = min;
		max_ = max;
	}

	~FoncteurGenerateurNombresAlea() {}

	unsigned int operator() () const {
		unsigned int nombreRandom = rand() % (max_)+(min_);
		return nombreRandom;
	}

private:
	unsigned int min_;
	unsigned int max_;
};


#endif;
