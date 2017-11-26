/****************************************************************************
* Fichier: Pixel.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 1 nov 2017
* Mise a jour : 20 nov 2017
* Description: Impl�mentation de la classe Pixel
****************************************************************************/

//
// Created by Gabriel Bernard on 17-10-06.
//

#include "Pixel.h"

/****************************************************************************
* Fonction: operatpr==
* Description: op�rateur de comparaison
* Param�tres: Pixel p, le pixel � comparer
* Retour: bool�en
****************************************************************************/
bool Pixel::operator==(const Pixel &p) const {
    return (this->retournerR() == p.retournerR() &&
            this->retournerG() == p.retournerG() &&
            this->retournerB() == p.retournerB());
}