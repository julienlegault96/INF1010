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

/****************************************************************************
* Fonction: Image
* Description: Constructeur par défaut
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
Image::Image() {
    pixels_ = nullptr;
    hauteur_ = 0;
    largeur_ = 0;
    taille_ = 0;
    typeImage_ = TypeImage::Couleurs;
}

/****************************************************************************
* Fonction: Image
* Description: Constructeur par copie
* Paramètres: const Image& image : l'image copiée
* Retour: aucun
****************************************************************************/
Image::Image(const Image& image) {

    copieProfonde(image);
}

/****************************************************************************
* Fonction: Image
* Description: Constructeur par copie
* Paramètres: const string& cheminDuFichier : l'emplacement du fichier
			  const TypeImage& type : le type du fichier
* Retour: aucun
****************************************************************************/
Image::Image(const string& cheminDuFichier, const TypeImage& type)
        : typeImage_(type), cheminVersImageOriginale_(cheminDuFichier), pixels_(nullptr) {
    // Retrouver le nom du fichier image a partir du chemin sur disque
    size_t indice = cheminVersImageOriginale_.find_last_of("/\\");
    nomDuFichier_ = cheminVersImageOriginale_.substr(indice+1);
    // Lecture du fichier image sur disque
    lireImage(cheminVersImageOriginale_, typeImage_);
    if(pixels_ == nullptr) {
        cerr << "Erreur lors de la lecture de l'image." << endl;
    }
}

/****************************************************************************
* Fonction: ~Image
* Description: Destructeur
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
Image::~Image() {}

/****************************************************************************
* Fonction: Image
* Description: copieProfonde
* Paramètres: const Image& image : l'image copiée
* Retour: aucun
****************************************************************************/
void Image::copieProfonde(const Image& image) {
	typeImage_ = image.typeImage_;
	hauteur_ = image.hauteur_;
	largeur_ = image.largeur_;
	taille_ = image.taille_;
	cheminVersImageOriginale_ = image.cheminVersImageOriginale_;
	nomDuFichier_ = image.nomDuFichier_;
	pixels_ = new Pixel*[taille_];

	for (unsigned int i = 0; i < taille_; i++) {
		pixels_[i] = image.pixels_[i]->retournerCopieProfonde();
	}
}

/****************************************************************************
* Fonction: operator=
* Description: Opérateur d'affectation
* Paramètres: Image& image : l'image à affecter
* Retour: la nouvelle image
****************************************************************************/
Image& Image::operator=(const Image& image)
{
    if (this != &image)
    {
        typeImage_ = image.typeImage_;
        hauteur_ = image.hauteur_;
        largeur_ = image.largeur_;
        taille_ = image.taille_;
        cheminVersImageOriginale_ = image.cheminVersImageOriginale_;
        nomDuFichier_ = image.nomDuFichier_;
		for (unsigned int i = 0; i < taille_; i++) {
			delete pixels_[i];
			pixels_[i] = nullptr;
		}
        // Copie Profonde
        copieProfonde(image);
    }
    return *this;
}

/****************************************************************************
* Fonction: operator<<
*Description : opérateur d'affichage
* Paramètres : ostream& os, const Image& image
* Retour : ostream& : le flux de sortie à afficher
****************************************************************************/
std::ostream& operator<<(std::ostream& os, const Image& image) {

    os << "Nom de l'image :  " << image.nomDuFichier_ << endl;
    os << "Chemin de l'original : " << image.cheminVersImageOriginale_ << endl;
    os << "Taille de l'image : " << image.taille_ << " pixels"<< endl;
    os << "Resolution en pixels : "  << image.largeur_ << " x " << image.hauteur_ << endl;
    os << "Type de l'image : " << image.obtenirTypeEnString() << endl;
    return os;
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

/****************************************************************************
* Fonction: obtenirTypeEnString
* Description: retourne le type en string 
* Paramètres: aucun
* Retour: string : le type de l'image en string
****************************************************************************/
string Image::obtenirTypeEnString() const {
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

/****************************************************************************
* Fonction: changerNomImage
* Description: modifie le nom de l'image
* Paramètres: aucun
* Retour: string : le type de l'image en string
****************************************************************************/
void Image::changerNomImage(const std::string &nom) {
    nomDuFichier_ = nom;
}

/****************************************************************************
* Fonction: sauvegarderImage
* Description: enregistre l'image sur le disque
* Paramètres: string &nomDuFichier : le nom du fichier
* Retour: string : aucun
****************************************************************************/
void Image::sauvegarderImage(const std::string &nomDuFichier) const {
    // Verification avant tentative d'ecriture du fichier sur disque
    if(pixels_ == nullptr) {
        cerr << "Il n'y a aucune donnee a ecrire sur le disque, pixels_ == nullptr" << endl;
        PAUSE;
        exit(1);
    }

    if(pixels_[taille_ - 1] == nullptr) {
        cerr << "Certains pixels ont la valeur nullptr, impossible d'ecrire l'image" << endl;
        PAUSE;
        exit(2);
    }

    // Ouverture d'un stream de sortie
    ofstream bmpOut(nomDuFichier.c_str(), ios::out | ios::binary);
    if (!bmpOut.is_open()) {
        cerr << "Erreur lors de la tentative d'ecriture du fichier." << endl;
        exit(12);
    }

    unchar *rgb = new unchar[taille_ * 3];
    for (unsigned int i = 0; i < taille_; i++) {
        Pixel* p = pixels_[i];
        if(p == nullptr) {
            cerr << "Pixels " << i << " a la valeur nullptr, impossible d'ecrire l'image sur disque" << endl;
            PAUSE;
            exit(2);
        }
        //rgb[i * 3] = p->retournerR();
        //rgb[i * 3 + 1] = p->retournerG();
        //rgb[i * 3 + 2] = p->retournerB();
		rgb[i * 3] = p->obtenirR();
		rgb[i * 3 + 1] = p->obtenirG();
		rgb[i * 3 + 2] = p->obtenirB();
    }

    unsigned char* output;
    size_t output_size = bitmap_encode_rgb(rgb, largeur_, hauteur_, &output);
    bmpOut.write((char*)output, output_size);
    bmpOut.close();
    delete[] rgb;
    delete[] output;
}

/****************************************************************************
* Fonction: lireImage
* Description: lecture de l'image 
* Paramètres: string &nomDuFichier : le nom du fichier
			   const TypeImage& type:  le type de l'image
* Retour: string : aucun
****************************************************************************/
void Image::lireImage(const string& cheminDuFichier, const TypeImage& type) {
    if(pixels_ != nullptr) {
        unsigned int i;
        for(i = 0; i < taille_; i++) {
            delete pixels_[i];
            pixels_ = nullptr;
        }
        delete[] pixels_;
    }
    // Ouverture du stream entrant
    ifstream bmpIn(cheminDuFichier.c_str(), ios::in | ios::binary);

    // Si l'ouverture a echouee on quitte la fonction
    if(!bmpIn.is_open()) {
        cerr << "Erreur, le fichier " << cheminVersImageOriginale_ << " n'a pas pu etre ouvert." << endl;
        PAUSE;
        exit(9);
    }

    char info[54];

    bmpIn.read(info, 54);

    int offset = *(int*)&info[10];

    largeur_ = *(unsigned int*)&info[18];
    hauteur_ = *(unsigned int*)&info[22];

    short bytes = *(short*)&info[28];

    if (bytes != 24) {
        cerr << "This bmp is a " << bytes << " and this program only supports 24 bytes bmp files" << endl;
        PAUSE;
        exit(10);
    }

    taille_ = largeur_ * hauteur_;

    bmpIn.seekg(offset);

    pixels_ = new Pixel*[taille_];

    if (type == Couleurs) {
        lirePixelsCouleur(bmpIn);
    } else if (type == Gris) {
        lirePixelsGris(bmpIn);
    } else {
        lirePixelsBN(bmpIn);
    }
    bmpIn.close();

}

void Image::lirePixelsCouleur(std::ifstream &bmpIn) {
    unsigned int x, y, pos = 0;
    char tmp[3];
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            int indice = (hauteur_ - 1 - y) * largeur_ + x;
            bmpIn.read(tmp, 3);
            // Creation d'un nouveau pixel couleur pour chaque pixel de l'image
            pixels_[indice] = new PixelCouleur((unchar)tmp[2], (unchar)tmp[1], (unchar)tmp[0]);
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }
}

void Image::lirePixelsGris(std::ifstream &bmpIn) {
    unsigned int x, y, pos = 0;
    char tmp[3];
    int indice;
    unsigned int moyenne;
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            indice = (hauteur_ - 1 - y) * largeur_ + x;
            bmpIn.read(tmp, 3); // Lit le bleu et le positionne a la derniere rangee
            moyenne = (unchar)tmp[0] + (unchar)tmp[1] + (unchar)tmp[2];
            moyenne /= 3;
            // Creation d'un nouveau pixel couleur pour chaque pixel de l'image
            pixels_[indice] = new PixelGris(moyenne);
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }
}

void Image::lirePixelsBN(std::ifstream &bmpIn) {
    unsigned int x, y, pos = 0;
    char tmp[3];
    unsigned int moyenne;
    for (y = 0; y < hauteur_; y++) {
        for (x = 0; x < largeur_; x++) {
            int indice = (hauteur_ - 1 - y) * largeur_ + x;
            bmpIn.read(tmp, 3); // Lit les valeurs bgr
            moyenne = (unchar)tmp[0] + (unchar)tmp[1] + (unchar)tmp[2];
            moyenne /= 3;
            // Creation d'un nouveau pixel couleur pour chaque pixel de l'image
            pixels_[indice] = new PixelBN(moyenne > 127);
            pos += 3;
        }
        while (pos % 4) {
            char tmp;
            bmpIn.read(&tmp, 1);
            pos += 1;
        }
    }
}


/****************************************************************************
* Fonction: convertirBN
* Description: convertit l'image en NB
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Image::convertirNB() {
	if (typeImage_ == TypeImage::NB) {
		cout << "L'image " << nomDuFichier_ << " est deja en noir et blanc, conversion innutile." << endl;
		return;
	}

	else {
		for (unsigned int i = 0; i < taille_; i++) {
			Pixel* pixel = pixels_[i];
			pixels_[i] = new PixelBN(pixels_[i]->convertirPixelBN());
			delete pixel;
		}
	}
	typeImage_ = TypeImage::NB;
	cout << "Conversion de l'image " << nomDuFichier_ << endl;

}


/****************************************************************************
* Fonction: convertirGris
* Description: convertit l'image en teines de gris
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Image::convertirGris() {
    if(typeImage_ == TypeImage::Gris) {
        cout << "L'image " << nomDuFichier_ << " est deja en nuance de gris, conversion innutile" << endl;
        return;
    }

    // Conversion des pixels de l'image en gris

	else {
		for (unsigned int i = 0; i < taille_; i++) {
			Pixel* pixel = pixels_[i];
			pixels_[i] = new PixelGris(pixels_[i]->convertirPixelGris());
			delete pixel;
		}
	}
    typeImage_ = TypeImage::Gris;
    cout << "Conversion de l'image " << nomDuFichier_ << endl;
}

/****************************************************************************
* Fonction: convertirCouleur
* Description: convertit l'image en couleurs
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Image::convertirCouleurs() {
	if (typeImage_ == TypeImage::Couleurs) {
		cout << "L'image " << nomDuFichier_ << " est deja en couleur, conversion innutile." << endl;
		return;
	}

	// Conversion des pixels en couleurs
	else {
		for (unsigned int i = 0; i < taille_; i++) {

			Pixel* pixel = pixels_[i];
			pixels_[i] = new PixelCouleur(pixels_[i]->convertirPixelCouleur()[Couleur::R],
				pixels_[i]->convertirPixelCouleur()[Couleur::G],
				pixels_[i]->convertirPixelCouleur()[Couleur::B]);
			delete pixel;
		}
	}
	typeImage_ = TypeImage::Couleurs;
	cout << "Conversion de l'image " << nomDuFichier_ << endl;
}
/****************************************************************************
* Fonction: MettreImageEnNegatif
* Description: effectue la mutation de la valeur de chaque pixel
* Paramètres: aucun
* Retour: aucun
****************************************************************************/
void Image::MettreImageEnNegatif() 
{
	for (unsigned int i = 0; i < taille_; i++)
	{
		pixels_[i]->mettreEnNegatif();
	}
	cout << "Mise en negatif de l'image " << nomDuFichier_ << endl;
}





