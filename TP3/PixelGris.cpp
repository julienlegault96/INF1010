/****************************************************************************
* Fichier: PixelGris.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 4 oct 2017
* Mise a jour : 22 oct 2017
* Description: Implémentation de la classe PixelGris
****************************************************************************/

#include "PixelGris.h"


/****************************************************************************
* Fonction: PixelGris
* Description: Constructeur par defaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
PixelGris::PixelGris()
{
	donnee_ = 0;
	type_ = TypePixel::NuanceDeGris;
}


/****************************************************************************
* Fonction: PixelGris
* Description: Constructeur par paramètres
* Paramètres: unsigned int d : valeur de donnee_(IN)
* Retour: aucun
****************************************************************************/
PixelGris::PixelGris(unsigned int d)
{
	donnee_ = d;
	type_ = TypePixel::NuanceDeGris;
}


/****************************************************************************
* Fonction: ~PixelGris
* Description: Destructeur
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
PixelGris::~PixelGris()
{

}


/****************************************************************************
* Fonction: PixelGris ::obtenirDonnee
* Description: retourne donnee_
* Paramètres: aucun
* Retour: unsigned int la valeur de donnee_
****************************************************************************/
unsigned int PixelGris::obtenirDonnee() const
{
	return donnee_;
}


/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la valeur de donnee_ est plus grande que 127
* Paramètres: aucun
* Retour: bool
****************************************************************************/
bool PixelGris::convertirPixelBN() const
{
	if (donnee_ > 127)
		return true;
	else
		return false;
}


/****************************************************************************
* Fonction: convertirPixelCouleur
* Description: retourne un tableau de pointeurs
* Paramètres: aucun
* Retour: unchar* un tableau de pointeurs
****************************************************************************/
unchar* PixelGris::convertirPixelCouleur() const
{
	unsigned char* tab = new unsigned char[3];
	tab[0] = donnee_;
	tab[1] = donnee_;
	tab[2] = donnee_;
	return tab;
}


/****************************************************************************
* Fonction: operator==
* Description: retourne vrai si deux pixels sont identiques
* Paramètres: PixelGris& pixel 
* Retour: booléen
****************************************************************************/
bool PixelGris::operator==(const PixelGris& pixel) const
{
	if ((type_ == pixel.type_) && (donnee_ == pixel.donnee_))
		return true;
	else return false;
}