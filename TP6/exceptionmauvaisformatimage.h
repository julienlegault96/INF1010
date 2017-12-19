/****************************************************************************
* Fichier: exceptionmauvaisformatimage.h
* Auteur: Arnaud Lebrun et Julien Legault
* Mise a jour : 4 décembre 2017
* Description: Implémentation de la classe ExceptionMauvaisFormatImage
****************************************************************************/

//
// Classe MauvaisFormatImage
// Cette classe definit l'exception a lancee lorsque
// l'image que l'on tente d'ouvrir n'est pas
// dans un format reconnu par la classe QImage
//
#ifndef EXCEPTIONMAUVAISFORMATIMAGE_H
#define EXCEPTIONMAUVAISFORMATIMAGE_H

#include <QException>
#include <QString>

class ExceptionMauvaisFormatImage : public QException {

  public:

    /****************************************************************************
    * Fonction:		ExceptionMauvaisFormatImage
    * Description:	Constructeur par paramètre
    * Paramètres:	QString  s
    * Retour:		aucun
    ****************************************************************************/
   ExceptionMauvaisFormatImage(QString & s)
   {
       s_ = s;
   }

   /****************************************************************************
   * Fonction:		raise
   * Description:	raise l'erreur
   * Paramètres:	aucun
   * Retour:		aucun
   ****************************************************************************/
   void raise() const
   {
       throw *this;
   }

   /****************************************************************************
   * Fonction:		ExceptionMauvaisFormatImage
   * Description:	Constructeur par paramètre
   * Paramètres:	QString  s
   * Retour:		aucun
   ****************************************************************************/
   ExceptionMauvaisFormatImage *clone() const
   {
       return new ExceptionMauvaisFormatImage(*this);
   }

   /****************************************************************************
   * Fonction:		What
   * Description:	retourne le contenu de l'erreur
   * Paramètres:	aucun
   * Retour:		QString  s
   ****************************************************************************/
  QString what()
  {
      return s_;
  }


 private :
    QString s_;

};

#endif // EXCEPTIONMAUVAISFORMATIMAGE_H
