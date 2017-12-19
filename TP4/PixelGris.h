//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXEL_GRIS_H
#define TP3_PIXEL_GRIS_H

#include "Pixel.h"

class PixelGris :
	public Pixel
{
public:
	PixelGris();
	PixelGris(unsigned int);
	~PixelGris();

	bool convertirPixelBN() const;

	unsigned int obtenirDonnee() const;

	virtual void mettreEnNegatif();
	
	//virtual unchar retournerR() const;
	//virtual unchar retournerG() const;
	//virtual unchar retournerB() const;
	virtual unchar obtenirR() const;
	virtual unchar obtenirG() const;
	virtual unchar obtenirB() const;

	virtual Pixel* retournerCopieProfonde() const;
	unchar convertirPixelGris() const;
	unchar* convertirPixelCouleur() const;

private:
	unchar donnee_;
};

#endif // TP3_PIXEL_GRIS_H