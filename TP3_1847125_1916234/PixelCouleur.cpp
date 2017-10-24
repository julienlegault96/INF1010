/****************************************************************************
* Fichier: PixelCouleur.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 4 oct 2017
* Mise a jour : 22 oct 2017
* Description: Impl�mentation de la classe PixelCouleur
****************************************************************************/
#include "PixelCouleur.h"

/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par default
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
PixelCouleur::PixelCouleur() {
	donnee_[R] = 0;
	donnee_[G] = 0;
	donnee_[B] = 0;
	type_ = TypePixel::Couleur;
}


/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par param�tres
* Param�tres: - unchar& r: donnee_[R](IN)
			  - unchar& g: donnee_[G](IN)
			  - unchar& b: donnee_[B](IN)
* Retour: aucun
****************************************************************************/
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) {
	donnee_[R] = r;
	donnee_[G] = g;
	donnee_[B] = b;
	type_ = TypePixel::Couleur;
}


/****************************************************************************
* Fonction: retournerR
* Description: retourne la valeur de donnee_[R]
* Param�tres: aucun
* Retour: unchar 
****************************************************************************/
unchar PixelCouleur::retournerR() const {
	return donnee_[R];
}

/****************************************************************************
* Fonction: retournerG
* Description: retourne la valeur de donnee_[G]
* Param�tres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::retournerG() const {
	return donnee_[G];
}


/****************************************************************************
* Fonction: retournerB
* Description: retourne la valeur de donnee_[B]
* Param�tres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::retournerB() const {
	return donnee_[B];
}


/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Param�tres: - aucun
* Retour: aucun
****************************************************************************/
PixelCouleur::~PixelCouleur() {};


/****************************************************************************
* Fonction: modifierTeinteRouge
* Description: modifie la valeur de  valeur de donnee_[R]
* Param�tres: - unchar d : valeur de donnee_[R]
* Retour: aucun
****************************************************************************/
void  PixelCouleur::modifierTeinteRouge(unchar d) 
{
	donnee_[R] = d;
}


/****************************************************************************
* Fonction: modifierTeinteVert
* Description: modifie la valeur de  valeur de donnee_[G]
* Param�tres: - unchar d : valeur de donnee_[G]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteVert(unchar d)
{
	donnee_[G] = d;
}

/****************************************************************************
* Fonction: modifierTeinteBleue
* Description: modifie la valeur de  valeur de donnee_[B]
* Param�tres: - unchar d : valeur de donnee_[B]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteBleue(unchar d)
{
	donnee_[B] = d;
}


/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la moyenne des trois pigmentation sont sup�rieur
* � 127
* Param�tres: aucun
* Retour: bool�en repr�sentant si la moyenne est sup�rieure � 127
****************************************************************************/
bool PixelCouleur::convertirPixelBN() const {
	if (((donnee_[R] + donnee_[G] + donnee_[B]) / 3) <= 127)
		return false;
	else
		return true;
}

/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne  la moyenne des trois pigmentation 
* Param�tres: aucun
* Retour: unchar la valeur de la moyenne despigmentation
****************************************************************************/
unchar PixelCouleur::convertirPixelGris() const
{
	return ((donnee_[R] + donnee_[G] + donnee_[B]) / 3);
}


/****************************************************************************
* Fonction: operator==
* Description: retourne vrai si le pixel est le m�me qu'a l'adresse courante
* Param�tres: pixel : un pixel de la classe PixelCouleur
* Retour: bool�en  repr�sentant si les pixels sont identiques
****************************************************************************/
bool PixelCouleur::operator==(const PixelCouleur& pixel) const
{
	if ((type_ == pixel.type_) && (donnee_[R] == pixel.donnee_[R]) && (donnee_[G] == pixel.donnee_[G]) && (donnee_[B] == pixel.donnee_[B]))
		return true;
	else
		return false;
}
