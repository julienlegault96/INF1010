/****************************************************************************
* Fichier: PixelCouleur.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 4 oct 2017
* Mise a jour : 20 nov 2017
* Description: Implémentation de la classe PixelCouleur
****************************************************************************/

#include "PixelCouleur.h"


/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par défaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
PixelCouleur::PixelCouleur() {
	assignerValeur(VALEUR_MIN_PIXEL);
}


/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par défaut
* Paramètres: donnee
* Retour: aucun
****************************************************************************/
PixelCouleur::PixelCouleur(const bool& donnee) {
	if(donnee) {
        assignerValeur(VALEUR_MAX_PIXEL);
	}
	else {
        assignerValeur(VALEUR_MIN_PIXEL);
	}
}


/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par paramètres
* Paramètres: - unchar& r: donnee_[R](IN)
- unchar& g: donnee_[G](IN)
- unchar& b: donnee_[B](IN)
- unchar& R: donnee_[R](IN)
* Retour: aucun
****************************************************************************/
PixelCouleur::PixelCouleur(const unchar& R, const unchar& G, const unchar& B) {
    donnee_[Couleur::R] = testPixel(R);
    donnee_[Couleur::G] = testPixel(G);
    donnee_[Couleur::B] = testPixel(B);
}


/****************************************************************************
* Fonction: PixelCouleur :: PixelCouleur
* Description: Constructeur par default
* Paramètres: donnee
* Retour: aucun
****************************************************************************/
PixelCouleur::PixelCouleur(const unsigned int& donnee) {
    assignerValeur(donnee);
}


/****************************************************************************
* Fonction: GroupImage
* Description: Destructeur
* Paramètres: - aucun
* Retour: aucun
****************************************************************************/
PixelCouleur::~PixelCouleur() {}


/****************************************************************************
* Fonction: somme
* Description: retourner la somme de chauqe pigmentation du pixel
* Paramètres: - aucun
* Retour: unsinged int la valeur de somme
****************************************************************************/
unsigned int PixelCouleur::somme() const {
	unsigned int somme = donnee_[Couleur::R] + donnee_[Couleur::G] + donnee_[Couleur::B];
	return somme;
}


/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne vrai si la moyenne des trois pigmentation sont supérieur
* à 127
* Paramètres: aucun
* Retour: booléen représentant si la moyenne est supérieure à 127
****************************************************************************/
bool PixelCouleur::convertirPixelBN() {
	unsigned int moyenne = somme() / 3;
	if (moyenne > 127) {
		return true;
	}
	else {
		return false;
	}
}
/****************************************************************************
* Fonction: convertirPixelBN
* Description: retourne  la moyenne des trois pigmentation
* Paramètres: aucun
* Retour: unchar la valeur de la moyenne despigmentation
****************************************************************************/
unchar PixelCouleur::convertirPixelGris() {
	return (somme() / 3);
}


Pixel* PixelCouleur::retournerUneCopieProfonde() {
    PixelCouleur *copie = new PixelCouleur(donnee_[Couleur::R], donnee_[Couleur::G], donnee_[Couleur::B]);
    return copie;
}

/****************************************************************************
* Fonction: PixelGris ::retournerCopieProfonde
* Description: retourne un pointeur de type pixel
* Paramètres: aucun
* Retour: Pixel* un pointeur de type pixel
****************************************************************************/
void PixelCouleur::assignerValeur(const unsigned int& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}


void PixelCouleur::assignerValeurs(const unchar& valeur) {
    donnee_[Couleur::R] = donnee_[Couleur::G] = donnee_[Couleur::B] = valeur;
}

/****************************************************************************
* Fonction: retournerR
* Description: retourne la valeur de donnee_[R]
* Paramètres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::retournerR() const {
    return donnee_[Couleur::R];
}

/****************************************************************************
* Fonction: retournerG
* Description: retourne la valeur de donnee_[R]
* Paramètres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::retournerG() const {
    return donnee_[Couleur::G];
}

/****************************************************************************
* Fonction: retournerB
* Description: retourne la valeur de donnee_[R]
* Paramètres: aucun
* Retour: unchar
****************************************************************************/
unchar PixelCouleur::retournerB() const {
    return donnee_[Couleur::B];
}

/****************************************************************************
* Fonction: modifierTeinteRouge
* Description: modifie la valeur de  valeur de donnee_[R]
* Paramètres: - unchar d : valeur de donnee_[R]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteRouge(unchar d) {
	donnee_[Couleur::R] = testPixel((unsigned int) d);
}

/****************************************************************************
* Fonction: modifierTeinteVert
* Description: modifie la valeur de  valeur de donnee_[G]
* Paramètres: - unchar d : valeur de donnee_[G]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteVerte(unchar d) {
	donnee_[Couleur::G] = testPixel((unsigned int) d);
}

/****************************************************************************
* Fonction: modifierTeinteBleue
* Description: modifie la valeur de  valeur de donnee_[B]
* Paramètres: - unchar d : valeur de donnee_[B]
* Retour: aucun
****************************************************************************/
void PixelCouleur::modifierTeinteBleue(unchar d) {
	donnee_[Couleur::B] = testPixel((unsigned int) d);
}

/****************************************************************************
* Fonction: mettreEnNegatif
* Description: modifie la valeur de chaque pigment pour son inverse
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void PixelCouleur::mettreEnNegatif() {
	donnee_[Couleur::R] = 255 - donnee_[Couleur::R];
	donnee_[Couleur::G] = 255 - donnee_[Couleur::G];
	donnee_[Couleur::B] = 255 - donnee_[Couleur::B];
}

/****************************************************************************
* Fonction: estMajoriteRouge
* Description: retourne vrai si la pigmentation rouge est majoritaire
* Paramètres: aucun
* Retour: boléen soit si la condition est respectée
****************************************************************************/
bool PixelCouleur::estMajoriteRouge() const
{
	if (donnee_[Couleur::R] > donnee_[Couleur::B] && donnee_[Couleur::R] > donnee_[Couleur::G])
		return true;
	else return false;
}

/****************************************************************************
* Fonction: estMajoriteVert
* Description: retourne vrai si la pigmentation verte est majoritaire
* Paramètres: aucun
* Retour: boléen soit si la condition est respectée
****************************************************************************/
bool PixelCouleur::estMajoriteVert() const
{
	if (donnee_[Couleur::G] > donnee_[Couleur::B] && donnee_[Couleur::G] > donnee_[Couleur::B])
		return true;
	else return false;
}

/****************************************************************************
* Fonction: estMajoriteBleu
* Description: retourne vrai si la pigmentation bleu est majoritaire
* Paramètres: aucun
* Retour: boléen soit si la condition est respectée
****************************************************************************/
bool PixelCouleur::estMajoriteBleu() const
{
	if (donnee_[Couleur::B] > donnee_[Couleur::G] && donnee_[Couleur::B] > donnee_[Couleur::R])
		return true;
	else return false;
}

/****************************************************************************
* Fonction: retournerIntensiteMoyenne
* Description: retourne l'intensité mouyenne du pixel
* Paramètres: aucun
* Retour: double, soit la valeur du calcul
****************************************************************************/
double PixelCouleur::retournerIntensiteMoyenne() const
{
	return ( ((double)donnee_[Couleur::R] + (double)donnee_[Couleur::G] + (double)donnee_[Couleur::B]) / 3 / 255);
}