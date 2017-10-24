/****************************************************************************
* Fichier: Pixel.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 13 sept 2017
* Mise a jour : 02 oct 2017
* Description: Impl�mentation de la classe Pixel
****************************************************************************/

#include "Pixel.h"
#include <iostream>
#include "Const.h"

using namespace std;


/****************************************************************************
* Fonction: Pixel ::Pixel
* Description: Constructeur avec liste d'initialisation
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
Pixel::Pixel() : tauxRouge_(0),tauxVert_(0),tauxBleu_(0)
{
}


/****************************************************************************
* Fonction: Pixel ::Pixel
* Description: Destructeur par d�faut
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
Pixel::~Pixel()
{
}


/****************************************************************************
* Fonction: Pixel ::Pixel
* Description: Constructeur par param�tres
* Param�tres: - unsigned int tauxRouge: valeur de tauxRouge_(IN)
- unsigned int tauxBleu: valeur de tauxBleu_(IN)
- unsigned int tauxVert: valeur de tauxVert_(IN)
* Retour: aucun
****************************************************************************/
Pixel::Pixel(unsigned int tauxRouge, unsigned int tauxVert, unsigned int tauxBleu) :
	tauxRouge_(tauxRouge), tauxVert_(tauxVert), tauxBleu_(tauxBleu)
{
}


/****************************************************************************
* Fonction: Pixel ::obtenirTauxRouge
* Description: Retourne tauxRouge_
* Param�tres: aucun
* Retour: unsigned int la valeur de tauxRouge_
****************************************************************************/
unsigned int Pixel::obtenirTauxRouge() const {
	return tauxRouge_;
}


/****************************************************************************
* Fonction: Pixel ::obtenirTauxVert
* Description: Retourne tauxVert_
* Param�tres: aucun
* Retour: unsigned int la valeur de tauxVert_
****************************************************************************/
unsigned int Pixel::obtenirTauxVert() const {
	return tauxVert_;
}


/****************************************************************************
* Fonction: Pixel ::obtenirTauxBleu
* Description: Retourne tauxBleu_
* Param�tres: aucun
* Retour: unsigned int la valeur de tauxBleu_
****************************************************************************/
unsigned int Pixel::obtenirTauxBleu() const {
	return tauxBleu_;
}


/****************************************************************************
* Fonction: Pixel :: modifierTeinteRouge
* Description: Modifie tauxRouge_
* Param�tres: - int incrementRouge: la valeur � ajouter � tauxRouge__ (IN)
* Retour: aucun
****************************************************************************/
void Pixel::modifierTeinteRouge(int incrementRouge) {
	if (incrementRouge < 0) {
		if (abs(incrementRouge) >= tauxRouge_) {
		    tauxRouge_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ -= incrementRouge;
		}
	}
	else {
		unsigned int temp = tauxRouge_ + incrementRouge;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxRouge_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxRouge_ = temp;
		}
	}
}


/****************************************************************************
* Fonction: Pixel :: modifierTeinteVert
* Description: Modifie tauxVert_
* Param�tres: - int incrementVert: la valeur � ajouter � tauxRouge__ (IN)
* Retour: aucun
****************************************************************************/
void Pixel::modifierTeinteVert( int incrementVert) {
	if (incrementVert < 0) {
		if (abs(incrementVert) >= tauxVert_) {
		    tauxVert_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ -= incrementVert;
		}
	}
	else {
		unsigned int temp = tauxVert_ + incrementVert;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxVert_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxVert_ = temp;
		}
	}
}


/****************************************************************************
* Fonction: Pixel :: modifierTeinteBleu
* Description: Modifie tauxBleu_
* Param�tres: - int incrementBleu: la valeur � ajouter � tauxBleu__ (IN)
* Retour: aucun
****************************************************************************/
void Pixel::modifierTeinteBleu( int incrementBleu) {
	if (incrementBleu < 0) {
		if (abs(incrementBleu) >= tauxBleu_) {
		    tauxBleu_ = MIN_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ -= incrementBleu;
		}
	}
	else {
		unsigned int temp = tauxBleu_ + incrementBleu;
		if (temp >= MAX_CONCENTRATION_COULEUR) {
		    tauxBleu_ = MAX_CONCENTRATION_COULEUR;
		}
		else {
		    tauxBleu_ = temp;
		}
	}
}


/****************************************************************************
* Fonction: Pixel:: retournerCouleur
* Description: Retourne la lettre correspondant � la couleur du pixel
* Param�tres: aucun
* Retour: char : la lettre de la couleur
****************************************************************************/
char Pixel :: retournerCouleur() const {
	if (tauxVert_ == 0 && tauxBleu_ == 0 && tauxRouge_ != 0) {
		return 'R';
	}
	
	else if (tauxRouge_ == 0 && tauxBleu_ == 0 && tauxVert_ != 0) {
		return 'G';
	}
	
	else if (tauxRouge_ == 0 && tauxVert_ == 0 && tauxBleu_ != 0) {
		return 'B';
	}
	else {
		return 'Q';
	}	
}


/****************************************************************************
* Fonction: Pixel :: Pixel
* Description: operator<< surcharge de l'op�rateur de flux de sortie
* Param�tres   - ostream sortie : l'information qui va �tre affich�e
*				- pixel p : le pixel qui sera affich�
* Retour: ostream : ce qui sera affich�
****************************************************************************/
ostream& operator<<(ostream& sortie, const Pixel & p)
{
	return sortie << p.retournerCouleur();
}


/****************************************************************************
* Fonction: Pixel :: Pixel
* Description: operator== surcharge de l'op�rateur de comparaison
* Param�tres   - Pixel p2 : le pixel avec lequel l'objet courant sera compar�
* Retour: bool : r�sultat comparaison
****************************************************************************/
bool Pixel::operator==(const Pixel & p2)
{
	return ( tauxRouge_== p2.tauxRouge_) && (tauxBleu_ == p2.tauxBleu_) && (tauxVert_=p2.tauxVert_);
}


/****************************************************************************
* Fonction: Pixel :: Pixel
* Description: operator== surcharge de l'op�rateur de comparaison
* Param�tres   - char couleur : la couleur avec laquelle la couleur du pixel courante sera compar�e
* Retour: bool : r�sultat comparaison
****************************************************************************/
bool Pixel::operator==(char& couleur) {
	return (retournerCouleur() == couleur);
}


/****************************************************************************
* Fonction: Pixel :: Pixel
* Description: operator== surcharge de l'op�rateur de comparaison
* Param�tres   - char couleur : la couleur avec laquelle la couleur du pixel courante sera compar�e
*				- Pixel p2 : le pixel pour lequel on veut v�rifier la couleur
* Retour: bool : r�sultat comparaison
****************************************************************************/
bool operator==(const char& couleur, const Pixel& p) {
	return (couleur == p.retournerCouleur());
}