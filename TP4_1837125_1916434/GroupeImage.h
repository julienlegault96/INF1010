//
// Created by Gabriel Bernard
//

#ifndef TP3_GROUPEIMAGE_H
#define TP3_GROUPEIMAGE_H

#include <vector>
#include <string>
#include "Image.h"
class GroupeImage {
public:
    GroupeImage();

    ~GroupeImage();

    Image* obtenirImage(unsigned int indiceImage) const;

    // Partie à ajouter et à modifier
    bool ajouterImage(Image* image);
    bool retirerImage(const std::string& nom);

    void afficherImages(std::ostream& os) const; // Partie a modifier

    // Partie à ajouter
    GroupeImage& operator+=(Image* image);
    GroupeImage& operator-=(Image* image);
    friend std::ostream& operator<<(std::ostream& os, const GroupeImage& image);

    Image* operator[](const unsigned int& indice) const;

    unsigned int obtenirNombreImages() const;

    void toutMettreEnNB();
    void toutMettreEnGris();
    void toutMettreEnCouleur();

    void toutEnregistrer();

    // void modifierImagesParIndices(std::vector<unsigned int>& vec, void (Image::*function_handler) ());

	GroupeImage(const GroupeImage& groupeImage);
	GroupeImage& operator=(const GroupeImage& groupeImage);
	void MettreGroupeEnNegatif() const ;


private:
    std::vector<Image*> images_;
};


#endif //TP3_GROUPEIMAGE_H
