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
}

/****************************************************************************
* Fonction: PixelBN
* Description: Constructeur par paramètres
* Paramètres: bool p : valeur de donnee_(IN)
* Retour: aucun
****************************************************************************/
PixelBN::PixelBN(bool p) {
	donnee_ = p;
}


/****************************************************************************
* Fonction: ~PixelBN
* Description: Destructeur
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
PixelBN::~PixelBN() {}



/****************************************************************************
* Fonction: convertirPixelCouleur
* Description: retourne un tableau de pointeurs
* Paramètres: aucun
* Retour: unchar* un tableau de pointeurs
****************************************************************************/
unchar* PixelBN::convertirPixelCouleur() const {
    unchar valeur = (unchar)VALEUR_MIN_PIXEL;
    if(donnee_) {
        valeur = (unchar)VALEUR_MAX_PIXEL;
    }

	unchar* ret = new unchar[3];
	ret[0] = ret[1] = ret[2] = valeur;

	return ret;
}


/****************************************************************************
* Fonction: convertirPixelGris
* Description: retourne la valeur de couleur du pixel converti
* Paramètres: aucun
* Retour: valeur du pixel
****************************************************************************/
unchar PixelBN::convertirPixelGris() const {
	return donnee_ ? VALEUR_MAX_PIXEL : VALEUR_MIN_PIXEL;
}

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
* Fonction: mettreEnNegatif
* Description: inverse la valeur des pixels
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void PixelBN::mettreEnNegatif()
{
	donnee_ = 255 - donnee_; 
}

/****************************************************************************
* Fonction: obtenirR
* Description: retourne la valeur de donnee_
* Paramètres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelBN::obtenirR() const {
	if (donnee_)
		return VALEUR_MAX_PIXEL;
	else
		return VALEUR_MIN_PIXEL;
}

/****************************************************************************
* Fonction: obtenirR
* Description: retourne la valeur de donnee_
* Paramètres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelBN::obtenirG() const {
	if (donnee_)
		return VALEUR_MAX_PIXEL;
	else
		return VALEUR_MIN_PIXEL;
}


/****************************************************************************
* Fonction: obtenirR
* Description: retourne la valeur de donnee_
* Paramètres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelBN::obtenirB() const {
	if (donnee_)
		return VALEUR_MAX_PIXEL;
	else
		return VALEUR_MIN_PIXEL;
}


/****************************************************************************
* Fonction: PixelGris ::retournerCopieProfonde
* Description: retourne un pointeur de type pixel
* Paramètres: aucun
* Retour: Pixel* un pointeur de type pixel
****************************************************************************/
Pixel* PixelBN::retournerCopieProfonde() const
{
	Pixel* p = new PixelBN(obtenirDonnee());
	return p;
}

/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la valeur de donnee_ existe
* Paramètres: aucun
* Retour: bool
****************************************************************************/
bool PixelBN::convertirPixelBN() const {
	return donnee_;
}