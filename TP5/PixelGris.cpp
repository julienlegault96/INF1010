/****************************************************************************
* Fichier: PixelGris.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 1 nov 2017
* Mise a jour : 4 nov 2017
* Description: Impl�mentation de la classe PixelGris
****************************************************************************/

#include "PixelGris.h"

/****************************************************************************
* Fonction: PixelGris
* Description: Constructeur par defaut
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelGris::PixelGris() {}


/****************************************************************************
* Fonction: PixelGris
* Description: modifie un unsigned int en unchar
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelGris::PixelGris(unsigned int donnee) {
	donnee_ = testPixel(donnee);
}


/****************************************************************************
* Fonction: PixelGris
* Description: Constructeur par param�tres
* Param�tres: unsigned int donnee_ : valeur de donnee_(IN)
* Retour: aucun
****************************************************************************/
PixelGris::PixelGris(unchar donnee): donnee_(donnee) {}


/****************************************************************************
* Fonction: ~PixelGris
* Description: Destructeur
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelGris::~PixelGris() {}


/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la valeur de donnee_ est plus grande que 127
* Param�tres: aucun
* Retour: bool
****************************************************************************/
bool PixelGris::convertirPixelBN() {
    if (donnee_ > 127) {
        return true;
    } else {
        return false;
    }
}


/****************************************************************************
* Fonction: convertirPixelGris
* Description: retourne donnee_
* Param�tres: aucun
* Retour: unchar une donnee
****************************************************************************/
unchar PixelGris::convertirPixelGris() {
    return donnee_;
}


/****************************************************************************
* Fonction: PixelGris ::retournerCopieProfonde
* Description: retourne un pointeur de type pixel
* Param�tres: aucun
* Retour: Pixel* un pointeur de type pixel
****************************************************************************/

Pixel* PixelGris::retournerUneCopieProfonde() {
    PixelGris* copie = new PixelGris(donnee_);
    return copie;
}


/****************************************************************************
* Fonction: PixelGris ::retournerR
* Description: retourne la valuer de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelGris::retournerR() const {
    return (unchar) donnee_;
}


/****************************************************************************
* Fonction: PixelGris ::retournerG
* Description: retourne la valuer de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelGris::retournerG() const {
    return (unchar) donnee_;
}


/****************************************************************************
* Fonction: PixelGris ::retournerB
* Description: retourne la valuer de donnee_
* Param�tres: aucun
* Retour: unchar la valeur de donnee_
****************************************************************************/
unchar PixelGris::retournerB() const {
    return (unchar) donnee_;
}


/****************************************************************************
* Fonction: PixelGris ::mettreEnNegatif
* Description: retourne l'oppos� de donnee_
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
void PixelGris::mettreEnNegatif() {
    donnee_ = -donnee_;
}


/****************************************************************************
* Fonction: PixelGris ::obtenirDonnee
* Description: retourne donnee_
* Param�tres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
unchar PixelGris::obtenirDonnee() const {
    return donnee_;
}


/****************************************************************************
* Fonction: PixelGris ::estMajoriteRouge
* Description: retourner vrai si le pixel est majoritairement rouge
* Param�tres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
bool PixelGris::estMajoriteRouge() const
{
	return false;
}


/****************************************************************************
* Fonction: PixelGris ::estMajoritaireRouge
* Description: retourner vrai si le pixel est majoritairement rouge
* Param�tres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
bool PixelGris::estMajoriteVert() const
{
	return false;
}


/****************************************************************************
* Fonction: PixelGris ::estMajoritaireBleu
* Description: retourner vrai si le pixel est majoritairement bleu
* Param�tres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
bool PixelGris::estMajoriteBleu() const
{
	return false;
}


/****************************************************************************
* Fonction: retournerIntensiteMoyenne
* Description: retourner la valeur de donnee_/ 255
* Param�tres: aucun
* Retour: double la valeur de donnee_ /255
****************************************************************************/
double PixelGris::retournerIntensiteMoyenne() const
{
	return ( (double)donnee_ / 255);
}