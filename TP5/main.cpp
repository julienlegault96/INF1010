/****************************************************************************
* Fichier:BaseDeDonnesSpecifique.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Date: 18 nov 2017
* Mise a jour : 20 nov 2017
* Description: Implémentation du main
****************************************************************************/

/*
Questions:
1. Il est plus facile d'ajouter et de retirer des éléments à des positions
aléatoires avec la liste qu'avec les vecteurs, puisque cette première permet l'usage
des itérateurs.

2. Les classes génériques sont implémentées dans le .h car lors de la compilation de
ces classes génériques, l'implémentation des méthodes doit rester accessible au compilateur 
qui peut ensuite les instancier en fonction du type utilisé.

*/

#ifndef PAUSE
    #ifdef _WIN32
        #include <Windows.h>
        #define PAUSE system("PAUSE")
    #else
        #include <unistd.h>
        #define PAUSE sleep(0)
    #endif
#endif /* PAUSE */

#include <iostream>
#include <string>

#include "GroupeImage.h"
#include <queue>
#include "BaseDeDonnesSpecifique.h"
#include "Foncteur.h"
#include <functional>

using namespace  std;

int main() {
	
	// Chemin vers les images
	string cheminLoad = "./Ensemble d'images/Originale/";
    // Nom des 6 images dans un tableau de string
	string image[9] = {"Breaking-Bad.bmp", "Couleur.bmp", "Fall.bmp", "RM.bmp", "SolarEclipse.bmp", "Monkey.bmp","WiC.bmp","Sloth.bmp","Green.bmp"};

    // Creer un conteneur de type QUEUE et ajouter les images dans la queue
	cout << "**************************************************" << endl;
	cout << "Creation de la file de travail" << std::endl;
	cout << "**************************************************" << endl << endl;

	
	//Creez 3 GroupeImage
	
	GroupeImage* groupeImage1 = new GroupeImage;
	GroupeImage* groupeImage2 = new GroupeImage;
	GroupeImage* groupeImage3 = new GroupeImage;

	// Creez un objet de type BaseDeDonnesSpecifique et ajoutez les 3 groupes a la base de donnes
	

	BaseDeDonnesSpecifique dataBase;
	
	dataBase += groupeImage1;
	dataBase += groupeImage2;
	dataBase += groupeImage3;
	
	/*Faites repartir les elements de la queue de maniere uniforme et sequentielle dans les groupe
	 Vous devez avoir la composition suivante :
		groupe 1 a les images 0,3,6
		groupe 2 a les images 1,4,7
		groupe 3 a les images 2,5,8
	 ATTENTION : la repartition doit se faire dans une seule boucle ET vous devez utiliser les fonctions de l'objet de base de donnes
	 NB: La methode pop() de queue<> ne retourne pas l'element de la structure
	*/
	
	cout << "**************************************************" << endl;
	cout << "CHARGEMENT DES IMAGES\n\n";

	// TODO : Votre implementation ici
	queue<Image*> queue;
	for (int i = 0; i < 9; i++) {
		string cheminFichier = cheminLoad + image[i];
		queue.push(new Image(cheminFichier, TypeImage::Couleurs));

		if ((i == 0) || (i == 3) || (i == 6)) {
			dataBase.AssocierImage(groupeImage1, queue.front());
			queue.pop();
		}
		else if ((i == 1) || (i == 4) || (i == 7)) {
			dataBase.AssocierImage(groupeImage2, queue.front());
			queue.pop();
		}
		else if ((i == 2) || (i == 5) || (i == 8)) {
			dataBase.AssocierImage(groupeImage3, queue.front());
			queue.pop();
		}

	}

	
	cout << "**************************************************" << endl << endl;
	cout << "AFFICHAGE DE LA BASE DE DONNEES\n" << endl;

	// TODO : Afficher la base de donnes au complet

	cout << dataBase << endl;	

	// Pour chaque groupe, generez un nombre aleatoire. Le nombre aleatoire doit toujours donner un index valide
	// ET appliquez les modifications suivantes aux images obtenues avec le nombre aleatoire
	
	FoncteurGenerateurNombresAlea nombreAlea(RAND_MIN_DEFAUT,RAND_MAX_DEFAUT);

	//GROUPE 1 - Mettre en negatif
	FoncteurMettreEnNegatif mettreNegatif;
	mettreNegatif(groupeImage1->obtenirImageParIndex(nombreAlea()));

	//GROUPE 2 - Mettre en gris

	FoncteurMettreEnGris mettreGris;
	mettreGris(groupeImage2->obtenirImageParIndex(nombreAlea()));

	//GROUPE 3 - Mettre en noir et blanc

	FoncteurMettreEnBN mettreBN;
	mettreBN(groupeImage3->obtenirImageParIndex(nombreAlea()));

	/*
	 *TRAITEMENT DE GROUPE 1
	 *Calculer l'intensite moyenne des images du groupe 1 et l'afficher
	 */

	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA MOYENNE \n\n";
	// TODO : Votre implementation ici

	cout << "Intensité moyenne du groupe 1 : " << groupeImage1->obtenirIntensiteMoyenne() << endl;

	cout << "MOYENNES DES IMAGES DANS LA BASE DE DONNEES: \n";

	for (Image* image : dataBase.obtenirListImages()) {
		if (image->obtenirIntensiteMoyenne() < groupeImage2->obtenirIntensiteMoyenne())
		{
			cout << image->obtenirNomImage() << " a une intensité moyenne de "
			   	<< image->obtenirIntensiteMoyenne() << endl;
		}
	}


	// Trouver toutes les images avec une intensite moyenne plus petite que la valeur trouve et
	// afficher leur nom et leur moyenne
	// ATTENTION : Faire ceci avec une boucle for intelligente de type 
	//																for (Type variable : conteneur)




	cout << "**************************************************" << endl << endl;



	cout << "**************************************************" << endl;
	cout << "CALCUL DE LA TAILLE \n\n";
	// TODO : Votre implementation ici

	/*
	 *TRAITEMENT DE GROUPE 2
	 * Calculer la taille moyenne des images dans le groupe 2 et afficher l'afficher
	 */

	cout << "Taille moyenne : " << groupeImage2->obtenirTailleMoyenne() << endl;


	// Afficher le nombre d'images dans la base de donnes
	cout << "Nombre d'images totales dans la base de donnees " << dataBase.obtenirListImages().size() << endl;	
	
	// Trouver at afficher le nombre d'images qui ont une taille plus grande que la moyenne calculee
	// Utiliser les fonctions std::bind et std::placeholders pour effectuer le travail

	// Decommenter et Remplacer les variables X,Y, Z par les bons elements 
	
	FoncteurObtenirTailleImage foncteurTaille;

	groupeImage2->supprimerElements(
		std::bind(
			greater<int>(),//A COMPLETER générer un opérateur > pour les entiers	
						   //Le bind ci-dessous permet d'appeler la méthode obtenirTaile de la
						   //Image* passée en argument du foncteur lors des appels de ce dernier dans supprimerElements

			std::bind(
				foncteurTaille,
				placeholders::_1 //A COMPLETER utiliser le premier placeholder (attention aux namespace) (reçoit une Image*)
			),

			(int)groupeImage2->obtenirTailleMoyenne() //A COMPLETER comparer à taille Moyenne
		)
	);
	
	cout << "Nombre d'images restant du groupe 1: " << groupeImage1->obtenirNombreImages() << endl;
	cout << "Nombre d'images restant du groupe 2: " << groupeImage2->obtenirNombreImages() << endl;
	cout << "Nombre d'images restant du groupe 3: " << groupeImage3->obtenirNombreImages() << endl;
	// Calculer le nombre d'images avec une taille superieure a la taille moyenne
	// ASTUCE: utilisez la STL et les fonctions de decompte conditionel

	// Afficher le nombre d'images dans la base de donnes avec une taille plus grande que la moyenne //REMPLACEZ CA AVEC LA TAILLE

	FoncteurObtenirTailleImage tailleImage;
	list<Image*>temporaire = dataBase.obtenirListImages();
	int nombreImages = count_if(temporaire.begin(), temporaire.end(),
		std::bind(greater<int>(), std::bind(foncteurTaille, placeholders::_1),
			(int)groupeImage3->obtenirTailleMoyenne()));

	cout << endl<< "Nombre d'images dont la taille est plus grande que la moyenne " << nombreImages << endl;

	
	cout << "**************************************************" << endl << endl;


	/*

	 *TRAITEMENT DU GROUPE 3
	 *
	 *Mettre tout les images du groupe 3 en noir et blanc et sauvegarder
	 *ATTENTION : Vous devez utiliser la fonction generique "appliquerFoncteurUnaire"  demandee dans au TP5 et non une boucle sur les elements
	 */

	cout << "**************************************************" << endl;
	cout << "CONVERSION EN NOIR ET BLANC \n";

	groupeImage3->appliquerFoncteurUnaire<FoncteurMettreEnBN>(mettreBN);

	groupeImage3->toutEnregistrer();
	
	cout << "**************************************************" << endl << endl;



	//delete
	
	while(!queue.empty()) {
		delete queue.front();
		queue.pop();
	}
	
	delete groupeImage1;
	delete groupeImage2;
	delete groupeImage3;
	groupeImage1 = nullptr;
	groupeImage2 = nullptr;
	groupeImage3 = nullptr;

    // Permet d'afficher le contenu de la console
    PAUSE;
	
    // Fin du programme
    return 0;
}