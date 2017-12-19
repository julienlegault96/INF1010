/****************************************************************************
* Fichier: PixelCouleur.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 4 oct 2017
* Mise a jour : 22 oct 2017
* Description: Implémentation de la classe PixelCouleur
****************************************************************************/
#include "PixelCouleur.h"

/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par default
* Paramètres: aucun
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
* Description: Constructeur par paramètres
* Paramètres: - unchar& r: donnee_[R](IN)
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
* Paramètres: aucun
* Retour: unchar 
****************************************************************************/
unchar PixelCouleur::retournerR() const {
	return donnee_[R];
}

/****************************************************************************
* Fonction: retournerG
* Description: retourne la valeur de donnee_[G]
* Paramètres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::retournerG() const {
	return donnee_[G];
}


/****************************************************************************
* Fonction: retournerB
* Description: retourne la valeur de donnee_[B]
* Paramètres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::retournerB() const {
	return donnee_[B];
}


/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
PixelCouleur::~PixelCouleur() {};


/****************************************************************************
* Fonction: modifierTeinteRouge
* Description: modifie la valeur de  valeur de donnee_[R]
* Paramètres: - unchar d : valeur de donnee_[R]
* Retour: aucun
****************************************************************************/
void  PixelCouleur::modifierTeinteRouge(unchar d) 
{
	donnee_[R] = d;
}


/****************************************************************************
* Fonction: modifierTeinteVert
* Description: modifie la valeur de  valeur de donnee_[G]
* Paramètres: - unchar d : valeur de donnee_[G]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteVert(unchar d)
{
	donnee_[G] = d;
}

/****************************************************************************
* Fonction: modifierTeinteBleue
* Description: modifie la valeur de  valeur de donnee_[B]
* Paramètres: - unchar d : valeur de donnee_[B]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteBleue(unchar d)
{
	donnee_[B] = d;
}


/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la moyenne des trois pigmentation sont supérieur
* à 127
* Paramètres: aucun
* Retour: booléen représentant si la moyenne est supérieure à 127
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
* Paramètres: aucun
* Retour: unchar la valeur de la moyenne despigmentation
****************************************************************************/
unchar PixelCouleur::convertirPixelGris() const
{
	return ((donnee_[R] + donnee_[G] + donnee_[B]) / 3);
}


/****************************************************************************
* Fonction: operator==
* Description: retourne vrai si le pixel est le même qu'a l'adresse courante
* Paramètres: pixel : un pixel de la classe PixelCouleur
* Retour: booléen  représentant si les pixels sont identiques
****************************************************************************/
bool PixelCouleur::operator==(const PixelCouleur& pixel) const
{
	if ((type_ == pixel.type_) && (donnee_[R] == pixel.donnee_[R]) && (donnee_[G] == pixel.donnee_[G]) && (donnee_[B] == pixel.donnee_[B]))
		return true;
	else
		return false;
}
