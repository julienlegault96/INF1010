#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
#include <iomanip>

using namespace std;

class Pixel
{
public:
	Pixel();
	~Pixel();

	Pixel(unsigned int tauxRouge,unsigned int tauxVert, unsigned int tauxBleu);

	void modifierTeinteRouge( int incrementRouge);
	void modifierTeinteVert( int incrementVert);
	void modifierTeinteBleu(int incrementBleu);

	unsigned int obtenirTauxRouge() const;
	unsigned int obtenirTauxVert() const;
	unsigned int obtenirTauxBleu() const;
		
    char retournerCouleur() const;

	// Ajouter les opérateurs
	friend ostream& operator<<(ostream& sortie, const Pixel & P);
	bool Pixel::operator==(const Pixel & p2);
	bool Pixel::operator==(char& couleur);
	friend bool operator==(const char& couleur, const Pixel& p);

private:
	unsigned int tauxRouge_ ;
	unsigned int tauxVert_;
	unsigned int tauxBleu_;
};

#endif