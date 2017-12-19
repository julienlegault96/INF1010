#ifndef IMAGE_H
#define IMAGE_H
#include "Pixel.h"

#include<iostream>

using namespace std;

class Image
{
public:
	Image();
	~Image();

	Image(const string& nomImage,unsigned int nombrePixelHauteur, unsigned int nombrePixelLargeur);

	// SI c'est nécessaire ajouter un constructeur par copie
	Image(const Image&  copieImage);

	void doublerTailleEnLargeur();
	void doublerTailleEnHauteur();

	unsigned int obtenirNombrePixelHauteur() const;
	unsigned int obtenirNombrePixelLargeur() const;
	string obtenirNomImage() const;

	
	void modifierNomImage(const string & nomImage);

	// Methode à ignorer pour le TP2
	void afficherImage() const;

	bool ajouterPixel(Pixel & pixel,unsigned int positionLargeur, unsigned int positionHauteur);
	Pixel obtenirPixel(unsigned int positionHauteur, unsigned int positionLargeur) const ;
	void augmenterTeintePixel(unsigned int positionLargeur, unsigned int positionHauteur, int  increment, char couleur);


    // Ajouter les opérateurs
	Image & Image::operator=(const Image & copieImage);
	friend ostream& operator<<(ostream& sortie, const Image & image);
	bool Image::operator==(const Image & image);
	bool Image::operator==(const string & nom);
	friend bool operator==(const string & nom, const Image & Image);

private :
	string nomImage_;
	unsigned int nombrePixelEnHauteur_;
	unsigned int nombrePixelEnLargeur_;
	Pixel** pixels_;

};

#endif