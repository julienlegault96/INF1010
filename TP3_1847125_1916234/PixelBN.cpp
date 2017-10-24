/****************************************************************************
* Fichier: PixelGris.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 4 oct 2017
* Mise a jour : 22 oct 2017
* Description: Implémentation de la classe PixelBN
****************************************************************************/

#include "PixelBN.h"

/****************************************************************************
* Fonction: PixelBN
* Description: Constructeur par defaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
PixelBN::PixelBN() {
	donnee_ = false;
	type_ = TypePixel::NoireBlanc;
}


/****************************************************************************
* Fonction: PixelBN
* Description: Constructeur par paramètres
* Paramètres: bool p : valeur de donnee_(IN)
* Retour: aucun
****************************************************************************/
PixelBN::PixelBN(bool p) {
	donnee_ = p;
	type_ = TypePixel::NoireBlanc;
}


/****************************************************************************
* Fonction: ~PixelBN
* Description: Destructeur
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
PixelBN::~PixelBN() {};


/****************************************************************************
* Fonction: obtenirDonnee
* Description: retourne donnee_
* Paramètres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
bool PixelBN::obtenirDonnee() const {
        return donnee_;
}


/****************************************************************************
* Fonction: convertirPixelGris
* Description: retourne la valeur de couleur du pixel converti
* Paramètres: aucun
* Retour: valeur du pixel
****************************************************************************/
unchar PixelBN::convertirPixelGris() const {
	if (donnee_ == false)
		return VALEUR_MIN_PIXEL;
	else
		return VALEUR_MAX_PIXEL;
}


/****************************************************************************
* Fonction: convertirPixelCouleur
* Description: retourne un tableau de pointeurs
* Paramètres: aucun
* Retour: unchar* un tableau de pointeurs
****************************************************************************/
unchar* PixelBN::convertirPixelCouleur() const {
	unsigned char* tab = new unsigned char[3];
	tab[0] = convertirPixelGris();
	tab[1] = convertirPixelGris();
	tab[2] = convertirPixelGris();
	return tab;
}


/****************************************************************************
* Fonction: operator==
* Description: retourne vrai si deux pixels sont identiques
* Paramètres: PixelBN& pixel
* Retour: booléen
****************************************************************************/
bool PixelBN::operator==(const PixelBN& pixel) const {
	if ((type_ == pixel.type_) && (donnee_ == pixel.donnee_))
		return true;
	else return false;
}