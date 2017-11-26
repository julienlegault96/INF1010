/****************************************************************************
* Fichier: BaseDeDonnéesGénérique.h
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 1 nov 2017
* Mise a jour : 20 nov 2017
* Description: Implémentation de la classe base de données générique
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
	* Paramètres: aucun
	* Retour: aucun
	****************************************************************************/
	BaseDeDonnesGenerique(){};

	
	/****************************************************************************
	* Fonction: ~BaseDeDonneesGeneriques
	* Description: Desstructeur
	* Paramètres: aucun
	* Retour: aucun
	****************************************************************************/
	~BaseDeDonnesGenerique()
	{
		vider();
	}

	
	/****************************************************************************
	* Fonction: ObtenirListImages
	* Description: accesseur liste images
	* Paramètres: aucun
	* Retour: list
	****************************************************************************/
	list<T*> obtenirListImages() const 
	{
		return listImage_;
	}
	
	
	/****************************************************************************
	* Fonction: ObtenirListGroupeImages
	* Description: accesseur liste groupe images
	* Paramètres: aucun
	* Retour: list
	****************************************************************************/
	list<S*> obtenirListGroupeImages() const 
	{
		return listGroupeImage_;
	}
	
	
	/****************************************************************************
	* Fonction: ajouter
	* Description: ajoute un élément à la liste d'images
	* Paramètres: l'élément
	* Retour: aucun
	****************************************************************************/
	void ajouter(T* t) {
		listImage_.push_back(t);	
	}

	
	/****************************************************************************
	* Fonction: ajouter
	* Description: ajoute un élément à la liste de groupes d'images
	* Paramètres: l'élément
	* Retour: aucun
	****************************************************************************/
	void ajouter(S* s) {
		listGroupeImage_.push_back(s);
	}
	
	
	/****************************************************************************
	* Fonction: supprimer
	* Description: supprime une image de la liste
	* Paramètres: l'élément à retirer
	* Retour: booléen
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
	* Paramètres: l'élément à retirer
	* Retour: booléen
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
	* Paramètres: prédicat
	* Retour: booléen
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
	* Paramètres: prédicat
	* Retour: booléen
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
	* Paramètres: aucun
	* Retour: aucun
	****************************************************************************/
	void vider() {
		listImage_.clear();	
		listGroupeImage_.clear();
	}

	
	/****************************************************************************
	* Fonction: operator+=
	* Description: ajoute un élément à la base de données
	* Paramètres: l'élément
	* Retour: la BDD
	****************************************************************************/
	BaseDeDonnesGenerique& operator+=(T* t) {
		ajouter(t);
		return *this;
	}
	
	
	/****************************************************************************
	* Fonction: operator+=
	* Description: ajoute un élément à la base de données
	* Paramètres: l'élément
	* Retour: la BDD
	****************************************************************************/
	BaseDeDonnesGenerique& operator+=(S* s) {
		ajouter(s);
		return *this;
	}

	
	/****************************************************************************
	* Fonction: operator+=
	* Description: retire un élément à la base de données
	* Paramètres: l'élément
	* Retour: la BDD
	****************************************************************************/
	BaseDeDonnesGenerique& operator-=(T* t) {
		supprimer(t);
		return *this;
	}


	/****************************************************************************
	* Fonction: operator+=
	* Description: retire un élément à la base de données
	* Paramètres: l'élément
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


