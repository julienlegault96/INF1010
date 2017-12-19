/****************************************************************************
* Fichier: PixelGris.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 4 oct 2017
* Mise a jour : 22 oct 2017
* Description: Impl�mentation de la classe PixelBN
****************************************************************************/

#include "PixelBN.h"

/****************************************************************************
* Fonction: PixelBN
* Description: Constructeur par defaut
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelBN::PixelBN() {
	donnee_ = false;
	type_ = TypePixel::NoireBlanc;
}


/****************************************************************************
* Fonction: PixelBN
* Description: Constructeur par param�tres
* Param�tres: bool p : valeur de donnee_(IN)
* Retour: aucun
****************************************************************************/
PixelBN::PixelBN(bool p) {
	donnee_ = p;
	type_ = TypePixel::NoireBlanc;
}


/****************************************************************************
* Fonction: ~PixelBN
* Description: Destructeur
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelBN::~PixelBN() {};


/****************************************************************************
* Fonction: obtenirDonnee
* Description: retourne donnee_
* Param�tres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
bool PixelBN::obtenirDonnee() const {
        return donnee_;
}


/****************************************************************************
* Fonction: convertirPixelGris
* Description: retourne la valeur de couleur du pixel converti
* Param�tres: aucun
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
* Param�tres: aucun
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
* Param�tres: PixelBN& pixel
* Retour: bool�en
****************************************************************************/
bool PixelBN::operator==(const PixelBN& pixel) const {
	if ((type_ == pixel.type_) && (donnee_ == pixel.donnee_))
		return true;
	else return false;
}