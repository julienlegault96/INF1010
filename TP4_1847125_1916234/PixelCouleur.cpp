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
	donnee_[Couleur::R] = 0;
	donnee_[Couleur::G] = 0;
	donnee_[Couleur::B] = 0;
}
/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par param�tres
* Param�tres: - unchar& r: donnee_[R](IN)
- unchar& g: donnee_[G](IN)
- unchar& b: donnee_[B](IN)
- unchar& R: donnee_[R](IN)
* Retour: aucun
****************************************************************************/
PixelCouleur::PixelCouleur(const unchar& r, const unchar& g, const unchar& b) {
    donnee_[Couleur::R] = testPixel(r);
    donnee_[Couleur::G] = testPixel(g);
    donnee_[Couleur::B] = testPixel(b);
}

/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Param�tres: - aucun
* Retour: aucun
****************************************************************************/
PixelCouleur::~PixelCouleur() {}


/****************************************************************************
* Fonction: obtenirR
* Description: retourne la valeur de donnee_[R]
* Param�tres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::obtenirR() const {
	return donnee_[Couleur::R];
}

/****************************************************************************
* Fonction: obtenirG
* Description: retourne la valeur de donnee_[G]
* Param�tres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::obtenirG() const {
	return donnee_[Couleur::G];
}

/****************************************************************************
* Fonction: obtenirB
* Description: retourne la valeur de donnee_[B]
* Param�tres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::obtenirB() const {
	return donnee_[Couleur::B];
}

/****************************************************************************
* Fonction: somme
* Description: effectue la somme entre les valeurs des donnee_
* Param�tres: aucun
* Retour: unsinged int la valeur de somme
****************************************************************************/
unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}

/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la moyenne des trois pigmentation sont sup�rieur
* � 127
* Param�tres: aucun
* Retour: bool�en repr�sentant si la moyenne est sup�rieure � 127
****************************************************************************/
bool PixelCouleur::convertirPixelBN() const {
	unsigned int moyenne = somme() / 3;
	return moyenne > 127;
}
/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne  la moyenne des trois pigmentation
* Param�tres: aucun
* Retour: unchar la valeur de la moyenne despigmentation
****************************************************************************/
unchar PixelCouleur::convertirPixelGris() const {
	return (somme() / 3);
}


/****************************************************************************
* Fonction: modifierTeinteRouge
* Description: modifie la valeur de  valeur de donnee_[R]
* Param�tres: - unchar d : valeur de donnee_[R]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = d;
}

/****************************************************************************
* Fonction: modifierTeinteVert
* Description: modifie la valeur de  valeur de donnee_[G]
* Param�tres: - unchar d : valeur de donnee_[G]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteVert(unchar d) {
	donnee_[Couleur::G] = d;
}

/****************************************************************************
* Fonction: modifierTeinteBleue
* Description: modifie la valeur de  valeur de donnee_[B]
* Param�tres: - unchar d : valeur de donnee_[B]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = d;
}


/****************************************************************************
* Fonction: PixelGris ::retournerCopieProfonde
* Description: retourne un pointeur de type pixel
* Param�tres: aucun
* Retour: Pixel* un pointeur de type pixel
****************************************************************************/
Pixel* PixelCouleur::retournerCopieProfonde() const
{
	Pixel* p = new PixelCouleur(obtenirR(), obtenirG(), obtenirB());
	return p;
}

/****************************************************************************
* Fonction: mettreEnNegatif
* Description: modifie la valeur de chaque pigment pour son inverse
* Param�tres: aucun
* Retour: aucun
****************************************************************************/
void PixelCouleur::mettreEnNegatif()
{
	modifierTeinteRouge(255 - donnee_[Couleur::R]);
	modifierTeinteVert(255 - donnee_[Couleur::G]);
	modifierTeinteBleue(255 - donnee_[Couleur::B]);
}

/****************************************************************************
* Fonction: convertirPixelCouleur
* Description: retourne  le tableau des valeurs du pixel
* Param�tres: aucun
* Retour: unchar* un pointeur sur le tableau des valeurs du pixels
****************************************************************************/
unchar * PixelCouleur::convertirPixelCouleur() const
{
	unsigned char* tab = new unsigned char[3];
	tab[0] = donnee_[R];
	tab[1] = donnee_[G];
	tab[2] = donnee_[B];
	return tab;
}
