/****************************************************************************
* Fichier: Pixel.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 13 sept 2017
* Mise a jour : 24 seot 2017
* Description: Implémentation de la classe Pixel
****************************************************************************/


#include "Pixel.h"
#include "Const.h"

/****************************************************************************
* Fonction: Pixel ::Pixel
* Description: Constructeur par default
* Paramètres: aucun     
* Retour: aucun
****************************************************************************/
Pixel::Pixel()
{
	tauxRouge_ = MIN_CONCENTRATION_COULEUR;
	tauxBleu_ = MIN_CONCENTRATION_COULEUR;
	tauxVert_ = MIN_CONCENTRATION_COULEUR;
}


/****************************************************************************
* Fonction: Pixel ::Pixel
* Description: Constructeur par paramètres
* Paramètres: - unsigned int tauxRouge: valeur de tauxRouge_(IN)
			  - unsigned int tauxBleu: valeur de tauxBleu_(IN)
			  - unsigned int tauxVert: valeur de tauxVert_(IN)
* Retour: aucun
****************************************************************************/
Pixel::Pixel(unsigned int tauxRouge,unsigned int tauxBleu, unsigned int tauxVert)
{
	tauxRouge_ = tauxRouge;
	tauxBleu_ = tauxBleu;
	tauxVert_ = tauxVert;
}

/****************************************************************************
* Fonction: Pixel ::getTauxRouge
* Description: Retourne tauxRouge_
* Paramètres: aucun
* Retour: unsigned int la valeur de tauxRouge_
****************************************************************************/
unsigned int Pixel::getTauxRouge() const
{
	return tauxRouge_;
}


/****************************************************************************
* Fonction: Pixel ::getTauxBleu
* Description: Retourne tauxBleu_
* Paramètres: aucun
* Retour: unsigned int la valeur de tauxBleu_
****************************************************************************/
unsigned int Pixel::getTauxBleu() const
{
	return tauxBleu_;
}

/****************************************************************************
* Fonction: Pixel ::getTauxVert
* Description: Retourne tauxVert_
* Paramètres: aucun
* Retour: unsigned int la valeur de tauxVert_
****************************************************************************/
unsigned int Pixel::getTauxVert() const
{
	return tauxVert_;
}

/****************************************************************************
* Fonction: Pixel :: modifierTeinteRouge
* Description: Modifie tauxRouge_
* Paramètres: - int incrementRouge: la valeur à ajouter à tauxRouge__ (IN)
* Retour: aucun
****************************************************************************/
void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (incrementRouge + tauxRouge_ > MAX_CONCENTRATION_COULEUR)
		tauxRouge_ = MAX_CONCENTRATION_COULEUR;
	else if (incrementRouge + tauxRouge_ < MIN_CONCENTRATION_COULEUR)
		tauxRouge_ = MIN_CONCENTRATION_COULEUR;
	else 
		tauxRouge_ += incrementRouge;
	
}

/****************************************************************************
* Fonction: Pixel :: modifierTeinteVerte
* Description: Modifie tauxVert_
* Paramètres: - int incrementRouge: la valeur à ajouter à tauxVert__ (IN)
* Retour: aucun
****************************************************************************/
void Pixel::modifierTeinteVert(int incrementVert) {
	if (incrementVert + tauxVert_ > MAX_CONCENTRATION_COULEUR)
		tauxVert_ = MAX_CONCENTRATION_COULEUR;
	else if (incrementVert + tauxVert_ < MIN_CONCENTRATION_COULEUR)
		tauxVert_ = MIN_CONCENTRATION_COULEUR;
	else
		tauxVert_ += incrementVert;
}

/****************************************************************************
* Fonction: Pixel :: modifierTeinteBleu
* Description: Modifie tauxBleu_
* Paramètres: - int incrementRouge: la valeur à ajouter à tauxBleu__ (IN)
* Retour: aucun
****************************************************************************/
void Pixel::modifierTeinteBleu(int incrementBleu) {
	if (incrementBleu + tauxBleu_ > MAX_CONCENTRATION_COULEUR)
		tauxBleu_ = MAX_CONCENTRATION_COULEUR;
	else if (incrementBleu + tauxBleu_ < MIN_CONCENTRATION_COULEUR)
		tauxBleu_ = MIN_CONCENTRATION_COULEUR;
	else
		tauxBleu_ = tauxBleu_ + incrementBleu;
}

/****************************************************************************
* Fonction: Pixel:: afficherPixel
* Description: Affiche le pixel.
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Pixel::afficherPixel() const
{
	if ((getTauxRouge() > MIN_CONCENTRATION_COULEUR) && (getTauxBleu() == MIN_CONCENTRATION_COULEUR) && (getTauxVert() == MIN_CONCENTRATION_COULEUR))
		cout << 'R';
	else if ((getTauxRouge() == MIN_CONCENTRATION_COULEUR) && (getTauxBleu() >MIN_CONCENTRATION_COULEUR) && (getTauxVert() == MIN_CONCENTRATION_COULEUR))
		cout << 'B';
	else if ((getTauxRouge() == MIN_CONCENTRATION_COULEUR) && (getTauxBleu() == MIN_CONCENTRATION_COULEUR) && (getTauxVert() > MIN_CONCENTRATION_COULEUR))
		cout << 'V';
	else
		cout << 'Q';


}



