#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
using namespace std;


class Pixel
{
public:
	Pixel();
	Pixel(unsigned int tauxRouge, unsigned int tauxVert,unsigned int tauxBleu);

	// Methodes d acces
	unsigned int Pixel::getTauxRouge() const;
	unsigned int Pixel::getTauxBleu() const;
	unsigned int Pixel::getTauxVert() const;


	// Methodes de modification

	void modifierTeinteRouge(int incrementRouge);
	void modifierTeinteVert(int incrementVert);
	void modifierTeinteBleu(int incrementBleu);	
		
	void afficherPixel() const;

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif