/****************************************************************************
* Fichier: PixelGris.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 25 oct 2017
* Mise a jour : 29 oct 2017
* Description: Impl�mentation de la classe PixelGris
****************************************************************************/

#include "PixelGris.h"

/****************************************************************************
* Fonction: PixelGris
* Description: Constructeur par defaut
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelGris::PixelGris() 
{}

/****************************************************************************
* Fonction: PixelGris
* Description: Constructeur par param�tres
* Param�tres: unsigned int donnee_ : valeur de donnee_(IN)
* Retour: aucun
****************************************************************************/
PixelGris::PixelGris(unsigned int donnee) {
    if(donnee < VALEUR_MAX_PIXEL) {
        donnee_ = donnee;
    } else {
        donnee_ = VALEUR_MAX_PIXEL;
    }
}

/****************************************************************************
* Fonction: ~PixelGris
* Description: Destructeur
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelGris::~PixelGris() {}


/****************************************************************************
* Fonction: convertirPixelCouleur
* Description: retourne un tableau de pointeurs
* Param�tres: aucun
* Retour: unchar* un tableau de pointeurs
****************************************************************************/
unchar* PixelGris::convertirPixelCouleur() const {
	unchar *ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = donnee_;
	return ret;
}

/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la valeur de donnee_ est plus grande que 127
* Param�tres: aucun
* Retour: bool
****************************************************************************/
bool PixelGris::convertirPixelBN() const {
	return donnee_ > 127;
}

/****************************************************************************
* Fonction: PixelGris ::obtenirDonnee
* Description: retourne donnee_
* Param�tres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
unsigned int PixelGris::obtenirDonnee() const {
	return donnee_;
}


/****************************************************************************
* Fonction: PixelGris ::mettreEnNegatif
* Description: retourne l'oppos� de donnee_
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
void PixelGris::mettreEnNegatif() {
	donnee_ = VALEUR_MAX_PIXEL - donnee_;
}

/****************************************************************************
* Fonction: PixelGris ::obtenirR
* Description: retourne l'oppos� de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelGris::obtenirR() const {
	return donnee_;
}

/****************************************************************************
* Fonction: PixelGris ::obtenirG
* Description: retourne l'oppos� de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelGris::obtenirG() const {
	return donnee_;
}

/****************************************************************************
* Fonction: PixelGris ::obtenirB
* Description: retourne l'oppos� de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelGris::obtenirB() const {
	return donnee_;
}

/****************************************************************************
* Fonction: PixelGris ::retournerCopieProfonde
* Description: retourne un pointeur de type pixel 
* Param�tres: aucun
* Retour: Pixel* un pointeur de type pixel 
****************************************************************************/
Pixel* PixelGris::retournerCopieProfonde() const {
	Pixel* p = new PixelGris(obtenirDonnee());
	 return p;
}

/****************************************************************************
* Fonction: convertirPixelGris
* Description: retourne donnee_
* Param�tres: aucun
* Retour: unchar une donnee
****************************************************************************/
unchar PixelGris::convertirPixelGris() const {
	return donnee_;
}