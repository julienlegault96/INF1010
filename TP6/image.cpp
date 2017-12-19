/****************************************************************************
* Fichier: image.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Mise a jour : 4 décembre 2017
* Description: Implémentation de la classe Image
****************************************************************************/


#include <QImageReader>
#include <QMessageBox>
#include <QGuiApplication>
#include <QDir>
#include "image.h"
#include "commandes.h"
#include "exceptionmauvaisformatimage.h"

using namespace std;

/****************************************************************************
* Fonction:		Image::Image
* Description:	Constructeur par defaut (construit une QImage par defaut)
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
Image::Image() {}


/****************************************************************************
* Fonction:		Image::Image
* Description:	Constructeur par parametre string
* Paramètres:	string
* Retour:		aucun
****************************************************************************/
Image::Image(const std::string &cheminVersLeFichier) {
    // Convertit une string en QString avant d'ouvrir l'image
    QString chemin = QString::fromStdString(cheminVersLeFichier);
    ouverturDeImage(chemin);
}


/****************************************************************************
* Fonction:		Image::Image
* Description:	Constructeur par QString
* Paramètres:	QString
* Retour:		aucun
****************************************************************************/
Image::Image(const QString &cheminVersLeFichier) {
    ouverturDeImage(cheminVersLeFichier);
}

/****************************************************************************
* Fonction:		ouverturDeImage
* Description:	Fonction permettant d'ouvrir une image
* Paramètres:	QString
* Retour:		booléen
****************************************************************************/
bool Image::ouverturDeImage(const QString &cheminVersLeFichier) {
    // Cree un QImageReader avec le chemin vers une image
    QImageReader reader(cheminVersLeFichier);
    // Tente de lire l'image
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    // Si l'image est nulle
    if (newImage.isNull()) {
        QString msg = tr("Impossible de lire l'image %1: %2")
                .arg(QDir::toNativeSeparators(cheminVersLeFichier), reader.errorString());
        // Lancer une exception mauvais format image
        ExceptionMauvaisFormatImage description(msg);
        description.raise();
        return false;
    }

    // L'image est enregistree dans l'attribut image_
    image_ = newImage;
    nomDuFichier_ = QFileInfo(cheminVersLeFichier);
    undoRedo_.clear();
    
    // Emettre un signal pour que la vue se mette a jour avec la nouvelle image
    emit signal_changementImage(image_);
    return true;
}


/****************************************************************************
* Fonction:		enregistrerImage
* Description:	Fonction qui enregistre une image a l'emplacement indique
* Paramètres:	QString  s
* Retour:		booléen
****************************************************************************/
bool Image::enregistrerImage(const QString &cheminVersEnregistrement) {
    image_.save(cheminVersEnregistrement);
    return true;
}


/****************************************************************************
* Fonction:		convertirEnNuanceDeGris
* Description:	Fonction qui converti une image en nuance de gris
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void Image::convertirEnNuanceDeGris() {
    shared_ptr<InterfaceCommande> c(new ConvertirEnGris(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);
      // emettre le signal de changement dans l'image
    emit signal_changementImage(image_);
   }


/****************************************************************************
* Fonction:		convertirEnNoirEtBlanc
* Description:	Fonction qui converti une image en noir et blanc
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void Image::convertirEnNoirEtBlanc() {
    shared_ptr<InterfaceCommande> c(new ConvertirEnNoirEtBlanc(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);
      // emettre le signal de changement dans l'image
    emit signal_changementImage(image_);
   }


/****************************************************************************
* Fonction:		mettreEnNegatif
* Description:	Fonction qui converti une image en negatif
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void Image::mettreEnNegatif() {
    shared_ptr<InterfaceCommande> c(new MettreEnNegatif(&image_));
    c->Executer();
    undoRedo_.insererDansUndosRedos(c);
      // emettre le signal de changement dans l'image
    emit signal_changementImage(image_);
   }


/****************************************************************************
* Fonction:		undo
* Description:	Annule la dernière action
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void Image::undo(){
    undoRedo_.undo();
     emit signal_changementImage(image_);
    }


/****************************************************************************
* Fonction:		redo
* Description:	Refait la dernière action
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void Image::redo(){
    undoRedo_.redo();
     emit signal_changementImage(image_);
    }

