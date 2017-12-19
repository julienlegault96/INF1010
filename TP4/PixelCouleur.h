//
// Created by Gabriel Bernard
//

#ifndef TP3_PIXEL_COULEUR_H
#define TP3_PIXEL_COULEUR_H

#include "Pixel.h"

enum Couleur { R=0, G=1, B=2 };  // R = 0, G = 1, B = 2
const int LONGUEUR_TABLEAU = 3;  // donnee_[3]

class PixelCouleur :
	public Pixel
{
public:
	PixelCouleur();
	PixelCouleur(const unchar& r, const unchar& g, const unchar& b);
	~PixelCouleur();

	void modifierTeinteRouge(unchar d);
	void modifierTeinteVert(unchar d);
	void modifierTeinteBleue(unchar d);

    // Accesseur
    //unchar retournerR() const;
    //unchar retournerG() const;
    //unchar retournerB() const;
	unchar obtenirR() const;
	unchar obtenirG() const;
	unchar obtenirB() const;

	bool convertirPixelBN() const;
	unchar convertirPixelGris() const;

	//bool operator==(const PixelCouleur& pixel) const;
	virtual Pixel* retournerCopieProfonde() const;

	virtual void mettreEnNegatif();
	virtual unchar* convertirPixelCouleur() const;

private:
	unsigned int somme() const;

	unchar donnee_[LONGUEUR_TABLEAU];
};

#endif // TP3_PIXEL_COULEUR_H