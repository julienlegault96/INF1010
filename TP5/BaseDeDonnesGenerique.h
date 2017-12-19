/****************************************************************************
* Fichier: BaseDeDonn�esG�n�rique.h
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 1 nov 2017
* Mise a jour : 20 nov 2017
* Description: Impl�mentation de la classe base de donn�es g�n�rique
****************************************************************************/

#ifndef BASE_DE_DONNES_GENERIQUE
#define BASE_DE_DONNES_GENERIQUE

#include <list>
#include <algorithm>
#include <iterator>


// Implementer toutes les methodes dans ce fichier

using namespace  std;

template<typename T, typename S> //T = Image, S = GroupeImage
class BaseDeDonnesGenerique

{
public:
	
	/****************************************************************************
	* Fonction: BaseDeDonneesGeneriques
	* Description: Constructeur par defaut
	* Param�tres: aucun
	* Retour: aucun
	****************************************************************************/
	BaseDeDonnesGenerique(){};

	
	/****************************************************************************
	* Fonction: ~BaseDeDonneesGeneriques
	* Description: Desstructeur
	* Param�tres: aucun
	* Retour: aucun
	****************************************************************************/
	~BaseDeDonnesGenerique()
	{
		vider();
	}

	
	/****************************************************************************
	* Fonction: ObtenirListImages
	* Description: accesseur liste images
	* Param�tres: aucun
	* Retour: list
	****************************************************************************/
	list<T*> obtenirListImages() const 
	{
		return listImage_;
	}
	
	
	/****************************************************************************
	* Fonction: ObtenirListGroupeImages
	* Description: accesseur liste groupe images
	* Param�tres: aucun
	* Retour: list
	****************************************************************************/
	list<S*> obtenirListGroupeImages() const 
	{
		return listGroupeImage_;
	}
	
	
	/****************************************************************************
	* Fonction: ajouter
	* Description: ajoute un �l�ment � la liste d'images
	* Param�tres: l'�l�ment
	* Retour: aucun
	****************************************************************************/
	void ajouter(T* t) {
		listImage_.push_back(t);	
	}

	
	/****************************************************************************
	* Fonction: ajouter
	* Description: ajoute un �l�ment � la liste de groupes d'images
	* Param�tres: l'�l�ment
	* Retour: aucun
	****************************************************************************/
	void ajouter(S* s) {
		listGroupeImage_.push_back(s);
	}
	
	
	/****************************************************************************
	* Fonction: supprimer
	* Description: supprime une image de la liste
	* Param�tres: l'�l�ment � retirer
	* Retour: bool�en
	****************************************************************************/
	bool supprimer(const T* t){
		list<Image*>::iterator pos = listImage_.begin();
		list<Image*>::iterator fin = listImage_.end();
		if (!listImage_.empty()) {
			remove(pos, fin, t);
			cout << "L'image a ete retiree" << endl;
			return true;
		}
		return false;
	}

	
	/****************************************************************************
	* Fonction: supprimer
	* Description: supprime un groupe de la liste
	* Param�tres: l'�l�ment � retirer
	* Retour: bool�en
	****************************************************************************/
	bool supprimer(const S* s){
		list<GroupeImage*>::iterator pos = listGroupeImage_.begin();
		list<GroupeImage*>::iterator fin = listGroupeImage_.end();
		if (!listGroupeImage_.empty()) {
			remove(pos, fin, t);
			cout << "La liste a ete retiree" << endl;
			return true;
		}
		return false;
	}


	/****************************************************************************
	* Fonction: supprimerImage
	* Description: supprime une image de la liste
	* Param�tres: pr�dicat
	* Retour: bool�en
	****************************************************************************/
	template<typename Predicate>
	bool supprimerImage(const Predicate& predicate) {
		auto it = remove_if(listImage_.begin(), listImage_.end(), predicate);
		listImage_.erase(it, listImage_.end());
		return true;
	}

	
	/****************************************************************************
	* Fonction: supprimergroupeImage
	* Description: supprime un groupe de la liste
	* Param�tres: pr�dicat
	* Retour: bool�en
	****************************************************************************/
	template<typename Predicate>
	bool supprimerGroupeImage(const Predicate& predicate) {	
		auto it = remove_if(listGroupeImage_.begin(), listGroupeImage_.end(), predicate);
		listGroupeImage_.erase(it, listGroupeImage_.end());
		return true;
	}
	
	
	/****************************************************************************
	* Fonction: clear
	* Description: vide les listes d'images et groupes d'images
	* Param�tres: aucun
	* Retour: aucun
	****************************************************************************/
	void vider() {
		listImage_.clear();	
		listGroupeImage_.clear();
	}

	
	/****************************************************************************
	* Fonction: operator+=
	* Description: ajoute un �l�ment � la base de donn�es
	* Param�tres: l'�l�ment
	* Retour: la BDD
	****************************************************************************/
	BaseDeDonnesGenerique& operator+=(T* t) {
		ajouter(t);
		return *this;
	}
	
	
	/****************************************************************************
	* Fonction: operator+=
	* Description: ajoute un �l�ment � la base de donn�es
	* Param�tres: l'�l�ment
	* Retour: la BDD
	****************************************************************************/
	BaseDeDonnesGenerique& operator+=(S* s) {
		ajouter(s);
		return *this;
	}

	
	/****************************************************************************
	* Fonction: operator+=
	* Description: retire un �l�ment � la base de donn�es
	* Param�tres: l'�l�ment
	* Retour: la BDD
	****************************************************************************/
	BaseDeDonnesGenerique& operator-=(T* t) {
		supprimer(t);
		return *this;
	}


	/****************************************************************************
	* Fonction: operator+=
	* Description: retire un �l�ment � la base de donn�es
	* Param�tres: l'�l�ment
	* Retour: la BDD
	****************************************************************************/
	BaseDeDonnesGenerique& operator-=(S* s) {
		supprimer(s);
		return *this;
	}
	
protected:
	list<T*> listImage_;
	list<S*> listGroupeImage_;
};


#endif


