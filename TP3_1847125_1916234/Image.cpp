/****************************************************************************
* Fichier: Image.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 4 oct 2017
* Mise a jour : 22 oct 2017
* Description: Implémentation de la classe Image
****************************************************************************/
#include "Image.h"
#include "PixelCouleur.h"
#include "PixelBN.h"
#include "PixelGris.h"
#include <iostream>
#include <sstream>


using namespace std;
	
    // Todo : Retrouver le nom du fichier image a partir du chemin sur le disque cheminDuFichier
    // Exemple : C:\Users\NOMUSAGER\images\image.bmp s'ecrit
    //           /Users/NOMUSAGER/images/image.bmp
    // mais vous pouvez aussi utiliser les chemins relatifs. (./Ensemble d'image/originale/image.bmp)

    // Todo : decommenter la fonction qui permet de lire l'image. Cette fonction s'occupe de remplir
    // les attributs taille_, hauteur_, largeur_ ainsi que pixels_.
    // pixels_ est de la grandeur taille_, soit hauteur_ * largeur_.
    // autrement dit, pixels_[i] est un pointeur sur un pixel.

    /* lireImage(cheminVersImageOriginale_, typeImage_);
    if(pixels_ == nullptr) {
        cerr << "Erreur lors de la lecture de l'image." << endl;
    }*/

	
/****************************************************************************
* Fonction: operator=
* Description: Opérateur d'affectation
* Paramètres: Image& image : l'image à affecter
* Retour: la nouvelle image
****************************************************************************/
Image& Image::operator=(const Image& image)
{
	if (this != &image) {
		delete[] pixels_;

		cheminVersImageOriginale_ = image.cheminVersImageOriginale_;
		nomDuFichier_ = cheminVersImageOriginale_.substr(cheminVersImageOriginale_.size(), cheminVersImageOriginale_.find_first_of("/"));
		typeImage_ = image.typeImage_;
		hauteur_ = image.hauteur_;
		largeur_ = image.largeur_;
		taille_ = image.taille_;
		// copieProfonde(image); fonction inexistante

		Pixel* temp = nullptr;
		for (unsigned int i = 0; i < taille_; i++)
		{
			switch (image.typeImage_)
			{
				case NB:
				{
					temp = new PixelBN(static_cast<PixelBN*>(image.pixels_[i])->obtenirDonnee());
					pixels_[i] = temp;
					temp = nullptr;
					break;
				}

				case Gris:
				{
					temp = new PixelGris(static_cast<PixelGris*>(image.pixels_[i])->obtenirDonnee());
					pixels_[i] = temp;
					temp = nullptr;
					break;
				}

				case Couleurs:
				{
					temp = new PixelCouleur(static_cast<PixelCouleur*>(image.pixels_[i])->retournerR(), static_cast<PixelCouleur*>(image.pixels_[i])->retournerG(), static_cast<PixelCouleur*>(image.pixels_[i])->retournerB());
					pixels_[i] = temp;
					temp = nullptr;
					break;
				}
			}
		}
	}
	return *this;
}


/****************************************************************************
* Fonction: operator==
* Description: retourne vrai si deux images sont identiques
* Paramètres: Image& Image
* Retour: booléen
****************************************************************************/
bool Image::operator==(const Image& image) {
    bool retour = true;

    if (image.obtenirNomImage() != nomDuFichier_ ||
        image.obtenirNombrePixelHauteur() != hauteur_ ||
        image.obtenirNombrePixelLargeur() != largeur_) {
        retour = false;
    }
    else {
        for(unsigned int i = 0; i < taille_; i ++) {
            if (image.pixels_[i] != pixels_[i]){
                return false;
            }
        }
    }

    return retour;
}


/****************************************************************************
* Fonction: operator==
* Description: retourne vrai si les deux images ont le même nom
* Paramètres: string& nom
* Retour: booléen
****************************************************************************/
bool Image::operator==(const string& nom) {
    return(nomDuFichier_ == nom);
}


/****************************************************************************
* Fonction: operator==
* Description: retourne vrai si les deux images ont le même nom
* Paramètres: string& nom, Image& image
* Retour: booléen
****************************************************************************/
bool operator==(const string& nom,  Image& image) {
    return image == nom;
}


/****************************************************************************
* Fonction: obtenirCheminFichier
* Description: retourne le chemin de l'image
* Paramètres: aucun
* Retour: string : le chemin
****************************************************************************/
std::string Image::obtenirCheminDuFichier() const {
    return cheminVersImageOriginale_;
}


/****************************************************************************
* Fonction: obtenirNomImage
* Description: retourne le non de l'image
* Paramètres: aucun
* Retour: string : le nom
****************************************************************************/
std::string Image::obtenirNomImage() const {
    return nomDuFichier_;
}


/****************************************************************************
* Fonction: obtenirNombrePixelHauteur
* Description: retourne la hauteur en pixels
* Paramètres: aucun
* Retour: unsigned int : le nombre
****************************************************************************/
unsigned int Image::obtenirNombrePixelHauteur() const {
    return hauteur_;
}


/****************************************************************************
* Fonction: obtenirNombrePixelLargeur
* Description: retourne la largeur en pixels
* Paramètres: aucun
* Retour: unsigned int : le nombre
****************************************************************************/
unsigned int Image::obtenirNombrePixelLargeur() const {
    return largeur_;
}


/****************************************************************************
* Fonction: obtenirTaille
* Description: retourne la taille en pixels
* Paramètres: aucun
* Retour: unsigned int : le nombre
****************************************************************************/
unsigned int Image::obtenirTaille() const {
    return taille_;
}


/****************************************************************************
* Fonction: obtenirType
* Description: retourne le type
* Paramètres: aucun
* Retour: TypeImage : le type
****************************************************************************/
TypeImage Image::obtenirType() const {
    return typeImage_;
}


// Muteateurs
void Image::changerNomImage(const std::string &nom) {
    nomDuFichier_ = nom;
}


// Retourne le type de l'image en string
string Image::obtenirTypeEnString() const {
    /*
     * Retourne:
     *    Couleurs          -> TypeImage::Couleurs
     *    Nuances de Gris   -> TypeImage::Gris
     *    Noir et Blanc     -> TypeImage::NB
     */
    string type_en_string;
    switch(typeImage_) {
        case TypeImage::Couleurs:
            type_en_string = "Couleurs";
            break;
        case TypeImage::Gris:
            type_en_string = "Nuances de Gris";
            break;
        case TypeImage::NB:
            type_en_string = "Noir et Blanc";
            break;
    }
    return type_en_string;
}


// Lit une image .bmp avec encodage 24 bits et la stock dans pixels_
void Image::lireImage(const string& nomDuFichier, const TypeImage& type) {
    // Si pixels_ n'est pas nul, les pixels sont detruits
    if(pixels_ != nullptr) {
        unsigned int i;
        for(i = 0; i < taille_; i++) {
            delete pixels_[i];
            pixels_ = nullptr;
        }
        delete[] pixels_;
    }

    // Ouverture du stream entrant
    ifstream bmpIn(cheminVersImageOriginale_.c_str(), ios::in | ios::binary);

    // Si l'ouverture a echouee on quitte la fonction
    if(!bmpIn.is_open()) {
        cerr << "Erreur, le fichier " << nomDuFichier << " n'a pas pu etre ouvert." << endl;
        exit(9);
    }
    
    // Lecture de l'en-tete du fichier .bmp
    char info[54];

    bmpIn.read(info, 54);

    int offset = *(int*)&info[10];

    // Enregistrement des informations pertinentes
    largeur_ = *(unsigned int*)&info[18];
    hauteur_ = *(unsigned int*)&info[22];

    short bytes = *(short*)&info[28];

    // Verification de l'encodage de l'image
    if (bytes != 24) {
        cerr << "This bmp is a " << bytes << " and this program only supports 24 bytes bmp files" << endl;
        exit(10);
    }

    // Enregistrement de la taille
    taille_ = largeur_ * hauteur_;

    // Envoit du curseur aux donnees RGB
    bmpIn.seekg(offset);

    // Preparation a la lecture
    unsigned int x, y, pos = 0;
    char tmp[3];
    pixels_ = new Pixel*[taille_];
    unsigned int moyenne;
    // Lecture des donnees RGB de l'image
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            int indice = (hauteur_ - 1 - y) * largeur_ + x;
            // Lit les pixels du bmp en ordre b g r
            bmpIn.read(tmp, 3);
            switch(type) {
                case TypeImage::Couleurs:
                    pixels_[indice] = new PixelCouleur((unchar)tmp[2], (unchar)tmp[1], (unchar)tmp[0]);
                    break;
                case TypeImage::Gris:
                    moyenne = (unchar)tmp[Couleur::R] + (unchar)tmp[Couleur::G] + (unchar)tmp[Couleur::B];
                    moyenne /= 3;
                    pixels_[indice] = new PixelGris((unchar)moyenne);
                    break;
                case TypeImage::NB:
                    moyenne = (unchar)tmp[Couleur::R] + (unchar)tmp[Couleur::G] + (unchar)tmp[Couleur::B];
                    moyenne /= 3;
                    pixels_[indice] = new PixelBN(moyenne > 127);
                    break;
            }
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }

    // Fermeture du stream d'entre
    bmpIn.close();
 
}


// Ecriture de l'image sur disque
void Image::sauvegarderImage(const string &nomDuFichier) {

    // Ouverture d'un stream de sortie
    ofstream bmpOut(nomDuFichier.c_str(), ios::out | ios::binary);
    if(!bmpOut.is_open()) {
        cerr << "Erreur lors de la tentative d'ecriture du fichier." << endl;
        exit(12);
    }
    
    // Preparation a l'ecriture
    unsigned char *rgb = new unsigned char[taille_ * 3];
    unchar valeur;
    PixelBN* pbn;
    PixelGris* pg;

    // Creation d'un tableau comportant toutes les donnees de l'image
    for (unsigned int i = 0; i < taille_; i++) {
        switch (pixels_[i]->getType()) {
        case TypePixel::Couleur:
            rgb[i * 3] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerR();
            rgb[i * 3 + 1] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerG();
            rgb[i * 3 + 2] = (static_cast<PixelCouleur*> (pixels_[i]))->retournerB();
            break;
        case TypePixel::NoireBlanc:
            pbn = static_cast<PixelBN*> (pixels_[i]);
            if (pbn->obtenirDonnee()) {
                valeur = (unchar)VALEUR_MAX_PIXEL;
            }
            else {
                valeur = (unchar)VALEUR_MIN_PIXEL;
            }
            rgb[i * 3] = rgb[i * 3 + 1] = rgb[i * 3 + 2] = valeur;
            break;
        case TypePixel::NuanceDeGris:
            pg = static_cast<PixelGris*> (pixels_[i]);
            valeur = (unchar) pg->obtenirDonnee();
            rgb[i * 3] = rgb[i * 3 + 1] = rgb[i * 3 + 2] = valeur;
            break;
        }

    }

    // Ajout de l'en-tete de fichier et rearrangement au format .bmp
    unsigned char* output;
    size_t output_size = bitmap_encode_rgb(rgb, largeur_, hauteur_, &output);
    // Ecriture de l'image sur le disque
    bmpOut.write((char*)output, output_size);
    // Fermeture du descripteur de fichier
    bmpOut.close();
    // Liberation memoire
    delete[] rgb;
    delete[] output;
}


/****************************************************************************
* Fonction: Image
* Description: Constructeur par défaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
Image::Image() {
	cheminVersImageOriginale_ = " ";
	nomDuFichier_ = " ";
	pixels_[1];
	hauteur_ = 1;
	largeur_ = 1;
	typeImage_ = Couleurs;
}


/****************************************************************************
* Fonction: Image
* Description: Constructeur par copie
* Paramètres: const Image& image : l'image copiée
* Retour: aucun
****************************************************************************/
Image::Image(const Image& image)
{
	cheminVersImageOriginale_ = image.cheminVersImageOriginale_;
	nomDuFichier_ = cheminVersImageOriginale_.substr(cheminVersImageOriginale_.size(), cheminVersImageOriginale_.find_first_of("/"));
	typeImage_ = image.typeImage_;
	hauteur_ = image.hauteur_;
	largeur_ = image.largeur_;
	taille_ = image.taille_;
	pixels_ = new Pixel*[taille_];
	//copieProfonde(image); fonction inexistante

	Pixel* temp = nullptr;
	for (unsigned int i = 0; i < taille_; i++)
	{
		switch (image.typeImage_)
		{
		case NB:
			{
			temp = new PixelBN(static_cast<PixelBN*>(image.pixels_[i])->obtenirDonnee());
			pixels_[i] = temp;
			temp = nullptr;
			break;
			}

		case Gris:
			{
				temp = new PixelGris(static_cast<PixelGris*>(image.pixels_[i])->obtenirDonnee());
				pixels_[i] = temp;
				temp = nullptr;
				break;
			}

		case Couleurs:
			{
				temp = new PixelCouleur(static_cast<PixelCouleur*>(image.pixels_[i])->retournerR(), static_cast<PixelCouleur*>(image.pixels_[i])->retournerG(), static_cast<PixelCouleur*>(image.pixels_[i])->retournerB());
				pixels_[i] = temp;
				temp = nullptr;
				break;
			}
		}
	}
}


/****************************************************************************
* Fonction: Image
* Description: Constructeur par paramètres
* Paramètres: const string& cheminDuFichier, const TypeImage& type
* Retour: aucun
****************************************************************************/
Image::Image(const string& cheminDuFichier, const TypeImage& type)
	: typeImage_(type), cheminVersImageOriginale_(cheminDuFichier), pixels_(nullptr) 
{
	cheminVersImageOriginale_ = cheminDuFichier;
	nomDuFichier_ = cheminVersImageOriginale_.substr(cheminVersImageOriginale_.find_last_of("/") + 1);
	typeImage_ = type;
	lireImage(nomDuFichier_, typeImage_);
}


/****************************************************************************
* Fonction: operator<<
* Description: opérateur d'affichage
* Paramètres:ostream& os, const Image& image
* Retour: ostream&  : le flux de sortie à afficher
****************************************************************************/
std::ostream& operator<<(std::ostream& os, const Image& image) {
	os << " Nom de l'image : " << image.nomDuFichier_ << endl;
	os << " Chemin de l'image : " << image.cheminVersImageOriginale_ << endl;
	os << " Taille de l'image : " << image.taille_ << " pixels " << endl;
	os << " Resolution en pixels : " << image.largeur_ << " x " << image.hauteur_ << endl;
	os << " Type de l'image : " << image.obtenirTypeEnString() << endl;
	return os;
}


/****************************************************************************
* Fonction: convertirBN
* Description: convertit l'image en NB
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Image::convertirNB() {
	Pixel* temp = nullptr;
	if (typeImage_ == Gris) {		
		for (unsigned int i = 0; i < taille_; i++) {
			temp = new PixelBN(static_cast<PixelGris*>(pixels_[i])->convertirPixelBN());
			delete pixels_[i];
			pixels_[i] = temp;
			temp = nullptr;
		}
	}
	else if (typeImage_ == Couleurs) {
		for (unsigned int i = 0; i < taille_; i++) {
			temp = new PixelBN(static_cast<PixelCouleur*>(pixels_[i])->convertirPixelBN());
			delete pixels_[i];
			pixels_[i] = temp;
			temp = nullptr;
		}
	}	
	typeImage_ = NB;
}


/****************************************************************************
* Fonction: convertirGris
* Description: convertit l'image en teines de gris
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Image::convertirGris() {
	Pixel* temp = nullptr;
	if (typeImage_ == NB) {
		for (unsigned int i = 0; i < taille_; i++) {
			temp = new PixelGris(static_cast<PixelBN*>(pixels_[i])->convertirPixelGris());
			delete pixels_[i];
			pixels_[i] = temp;
			temp = nullptr;
		}
	}
  
	else if (typeImage_ == Couleurs) {
		for (unsigned int i = 0; i < taille_; i++) {
			temp = new PixelGris(static_cast<PixelCouleur*>(pixels_[i])->convertirPixelGris());
			delete pixels_[i];
			pixels_[i] = temp;
			temp = nullptr;
		}
	}
	typeImage_ = Gris;
}
				   

/****************************************************************************
* Fonction: convertirCouleur
* Description: convertit l'image en couleurs
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Image::convertirCouleur() {
	Pixel* temp = nullptr;
	if (typeImage_ == NB) {
		for (unsigned int i = 0; i < taille_; i++) {
			unchar* obtenirCouleur = static_cast<PixelGris*>(pixels_[i])->convertirPixelCouleur();
			temp = new PixelCouleur(obtenirCouleur[R], obtenirCouleur[G], obtenirCouleur[B]);
			delete pixels_[i];
			pixels_[i] = temp;
			temp = nullptr;
		}																	  
	}
  
	else if (typeImage_ == Gris) {
		for (unsigned int i = 0; i < taille_; i++) {
			unchar* obtenirCouleur = static_cast<PixelBN*>(pixels_[i])->convertirPixelCouleur();
			temp = new PixelCouleur(obtenirCouleur[R], obtenirCouleur[G], obtenirCouleur[B]);
			delete pixels_[i];
			pixels_[i] = temp;
			temp = nullptr;
		}
	}
	typeImage_ = Couleurs;
}


/****************************************************************************
* Fonction: ~Image
* Description: Destructeur
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
Image::~Image() {};