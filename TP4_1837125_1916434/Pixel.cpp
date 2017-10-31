//
// Created by Gabriel Bernard
//

#include "Pixel.h"

Pixel::Pixel() {}

// Pixel::Pixel(TypePixel tp) : type_(tp) {}

Pixel::~Pixel() {}

unsigned int Pixel::testPixel(const unsigned int &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

unchar Pixel::testPixel(const unchar &valeur) const {
    if(valeur > VALEUR_MAX_PIXEL) {
        return VALEUR_MAX_PIXEL;
    } else {
        return valeur;
    }
}

// TypePixel Pixel::getType() const { return type_; }

 bool Pixel:: operator==(const Pixel& pixel) const {
	if ((obtenirR() == pixel.obtenirR()) && (obtenirG() == pixel.obtenirG()) && (obtenirB() == pixel.obtenirB()))
		return true;
	else 
		return false;
}

 

