/****************************************************************************
* Fichier: PixelGris.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 1 nov 2017
* Mise a jour : 20 nov 2017
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
}

/****************************************************************************
* Fonction: PixelBN
* Description: Constructeur par param�tres
* Param�tres: bool p : valeur de donnee_(IN)
* Retour: aucun
****************************************************************************/
PixelBN::PixelBN(bool p) {
	donnee_ = p;
}

/****************************************************************************
* Fonction: ~PixelBN
* Description: Destructeur
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelBN::~PixelBN() {}

/****************************************************************************
* Fonction: convertirPixelGris
* Description: retourne la valeur de couleur du pixel converti
* Param�tres: aucun
* Retour: valeur du pixel
****************************************************************************/
unchar PixelBN::convertirPixelGris() {
    if(donnee_) {
        return VALEUR_MAX_PIXEL;
    } else {
        return VALEUR_MIN_PIXEL;
    }
}

/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la valeur de donnee_ existe
* Param�tres: aucun
* Retour: bool
****************************************************************************/
bool PixelBN::convertirPixelBN() {
	return donnee_;
}

/****************************************************************************
* Fonction: PixelGris ::retournerCopieProfonde
* Description: retourne un pointeur de type pixel
* Param�tres: aucun
* Retour: Pixel* un pointeur de type pixel
****************************************************************************/
Pixel* PixelBN::retournerUneCopieProfonde() {
	PixelBN *copie = new PixelBN(donnee_);
	return copie;
}

/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la valeur de donnee_ existe
* Param�tres: aucun
* Retour: bool
****************************************************************************/
bool PixelBN::obtenirDonnee() {
	return donnee_;
}

/****************************************************************************
* Fonction: retournerR
* Description: retourne la valeur de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelBN::retournerR() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

/****************************************************************************
* Fonction: retournerG
* Description: retourne la valeur de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelBN::retournerG() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

/****************************************************************************
* Fonction: retournerB
* Description: retourne la valeur de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelBN::retournerB() const {
    if(donnee_) {
        return (unchar) VALEUR_MAX_PIXEL;
    } else {
        return (unchar) VALEUR_MIN_PIXEL;
    }
}

/****************************************************************************
* Fonction: mettreEnNegatif
* Description: inverse la valeur des pixels
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
void PixelBN::mettreEnNegatif() {
    donnee_ = !donnee_;
}


/****************************************************************************
* Fonction: estMajoriteRouge
* Description: retourner vrai si le pixel est majoritairement rouge
* Param�tres: aucun
* Retour: bool�en
****************************************************************************/
bool PixelBN::estMajoriteRouge() const
{
	return false;
}

/****************************************************************************
* Fonction: estMajoriteVert
* Description: retourner vrai si le pixel est majoritairementvert
* Param�tres: aucun
* Retour: bool�en
****************************************************************************/
bool PixelBN::estMajoriteVert() const
{
	return false;
}

/****************************************************************************
* Fonction: estMajoriteBleu
* Description: retourner vrai si le pixel est majoritairementBleu
* Param�tres: aucun
* Retour: bool�en
****************************************************************************/
bool PixelBN::estMajoriteBleu() const
{
	return false;
}

/****************************************************************************
* Fonction: retournerIntensiteMoyenne
* Description: retourner la valeur de donnee_/ 255
* Param�tres: aucun
* Retour: double la valeur de donnee_ /255
****************************************************************************/
double PixelBN::retournerIntensiteMoyenne() const
{
	return double(donnee_);
}