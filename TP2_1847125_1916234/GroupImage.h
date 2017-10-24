#ifndef GROUPIMAGE_H
#define GROUPIMAGE_H
#include "Image.h"
#include <vector>


using namespace std;


class GroupImage
{
public:
	GroupImage();
	~GroupImage(); 



	void modifierType(const string &type);
	string obtenirType() const;

	
	Image* obtenirImage(unsigned int indiceImage) const;	
  
	
	void ajouterImage(Image* image);

	void retirerImage(const string & nomImage);

	
	void afficherImages(ostream& sortie) const;

	void doublerTailleImageEnLargeur(unsigned int indiceImage);

	void doublerTailleImageEnHauteur(unsigned int indiceImage);
	
     
    
	GroupImage &  operator += ( Image &image);
	GroupImage & operator-= (Image &image);
	friend ostream& operator << (ostream& sortie, const GroupImage& g);

private:

	string type_;


	vector<Image*> Images_;

};

#endif