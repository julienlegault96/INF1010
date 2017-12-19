/****************************************************************************
* Fichier: mainwindow.cpp
* Auteur: Arnaud Lebrun et Julien Legault
* Mise a jour : 4 décembre 2017
* Description: Implémentation de la classe MainWindow
****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>
#include "exceptionmauvaisformatimage.h"


/****************************************************************************
* Fonction:		MainWindow
* Description:	Constructeur par paramètre Qwidget
* Paramètres:	qwidget
* Retour:		aucun
****************************************************************************/
// Constructeur de la fenetre principale de l'applicatin
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    imageLabel_ = new QLabel;
    ui->setupUi(this);
    creeActions();
    initUI();
    initConnections();
}


/****************************************************************************
* Fonction:		~MainWindow
* Description:	destructeur
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
// Destructeur de la fenetre principale de l'application
MainWindow::~MainWindow()
{
    delete ui;
}


/****************************************************************************
* Fonction:		initConnections
* Description:	Fonction qui gere toutes les connections
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void MainWindow::initConnections() {
    // Connectez Ficher + ouvrir a la fonction ouvrirImage
    connect(Ouvrir,SIGNAL(triggered(bool)),this,SLOT(ouvrirImage()));

    // Connectez Fichier + enregistrer sous avec la fonction appropriée
    connect(EnregistrerSous,SIGNAL(triggered(bool)),this,SLOT(enregistrerImage()));

    // Connectez aide + a propos a la fonction appropriée
    connect(APropos,SIGNAL(triggered(bool)),this,SLOT(about()));

    // Connectez Edition + undo a la fonction appropriée
    connect(Undo, SIGNAL(triggered(bool)), &image_, SLOT(undo()));

    // Connectez Edition + redo a la fonction approprié
    connect(Redo, SIGNAL(triggered(bool)), &image_, SLOT(redo()));

    // Connectez le signal de mise a jour de l'image aux fonctions appropriées
    connect(&image_, SIGNAL(signal_changementImage(QImage)), this, SLOT(updateImage(QImage)));
    connect(&image_, SIGNAL(signal_changementImage(QImage)), this, SLOT(updateTableViewWidget(QImage)));

    // Connectez le click du bouton Noir et Blanc a la fonction appropriée
    connect(boutonNB_, SIGNAL(clicked(bool)), &image_, SLOT(convertirEnNoirEtBlanc()));
    // Connectez le click du bouton Nuance de Gris a la fonction approprié
    connect(boutonGris_, SIGNAL(clicked(bool)), &image_, SLOT(convertirEnNuanceDeGris()));
    // Connectez le click du bouton Negatif a la fonction appropriée
    connect(boutonNegatif_, SIGNAL(clicked(bool)), &image_, SLOT(mettreEnNegatif()));
}


/****************************************************************************
* Fonction:		ouvrirImage
* Description:	Fonction permettant la selection et l'ouverture d'une image
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void MainWindow::ouvrirImage() {
    QFileDialog dialog(this, tr("Ouvrir une image"));
    fileExplorer(dialog, QFileDialog::AcceptOpen);
    // Tant qu'aucune image n'a ete choisie ou que le dialogue
    // ne s'est pas conclu, demande de choisir une image.
    // Attraper l'exception lancee par image_.ouvertureDeImage
    try{
        while(dialog.exec() == QDialog::Accepted && !image_.ouverturDeImage(dialog.selectedFiles().first())) {}

        }
    catch(ExceptionMauvaisFormatImage &e){
        afficherMessage(e.what());
        }
    }


/****************************************************************************
* Fonction:		enregistrerImage
* Description:	Fonction qui permet d'enregistrer une image
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void MainWindow::enregistrerImage() {
    // Enregistrer l'image avec le format jpg par defaut
    QString filename = QFileDialog::getSaveFileName(
                this, tr("Enregistrer l'image"),
                "", tr("JPEG (*.jpg);;All Files (*)")
    );

    // Si le nom du fichier n'est pas vide, enregistre l'image
    if(!filename.isEmpty()) {
        image_.enregistrerImage(filename);
    }
}


/****************************************************************************
* Fonction:		afficherMessage
* Description:	 Fonction qui cree une QMessageBox et affiche le message dans msg
* Paramètres:	qstring
* Retour:		aucun
****************************************************************************/
void MainWindow::afficherMessage(QString msg) {
    // Creez la boite de dialogue avec une QMessageBox.
    // Cette boite doit afficher le message contenu dans msg
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.exec();
}


/****************************************************************************
* Fonction:		about
* Description:	Fonction qui appelle afficherMessage pour afficher une QMessageBox
                // comportant une explication du programme
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void MainWindow::about() {
    QString msg = tr("Poly GIMP est une application QT simple permettant de lire une image et de la transformer en noir et blanc, nuance de gris ou negatif.\n©INF1010 automne 2017");
    afficherMessage(msg);
}


/****************************************************************************
* Fonction:		updateImage
* Description:	Fonction mettant a jour la vue sur l'image
* Paramètres:	qimage
* Retour:		aucun
****************************************************************************/
void MainWindow::updateImage(QImage image){

   static bool first = true;
    // Modifiez la vue sur l'image. Attention, l'image
    // doit garder sa taille d'origine et ne pas etre distortionnee

    QPixmap pixmap = QPixmap::fromImage(image);
    imageLabel_->resize(pixmap.size());
    imageLabel_->setPixmap(pixmap);
    imageLabel_ -> adjustSize();

    // Lorsque ce sera fait, decommentez cette ligne
    const QString message = tr("Image \"%1\", %2x%3, Profondeur: %4")
            .arg(QDir::toNativeSeparators(image_.obtenirNomDuFichier().filePath())).arg(image.width()).arg(image.height()).arg(image.depth());
    ui->statusBar->showMessage(message);

    // Activez les boutons de modification ainsi que
    // la fonction d'enregistrement de l'image.
    if(first){
        activateButtons();
       EnregistrerSous->setEnabled(true);
        first = false;
    }
}


/****************************************************************************
* Fonction:		updateTableViewWidget
* Description:	Fonction qui initialise le QTableWidget avec les informations de l'image
* Paramètres:	qimage
* Retour:		aucun
****************************************************************************/
void MainWindow::updateTableViewWidget(QImage image) {
    // Mettre a jour la table view avec les information de l'image
    tableWidget_->setItem(0,1, new QTableWidgetItem(image_.obtenirNomDuFichier().baseName()));
    tableWidget_->setItem(1,1, new QTableWidgetItem(QString::number(image.width())));
    tableWidget_->setItem(2,1, new QTableWidgetItem(QString::number(image.height())));
}


/****************************************************************************
* Fonction:		activateButtons
* Description:	Fonction permettant d'activer tous les boutons
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void MainWindow::activateButtons() {
    boutonNB_->setDisabled(false);
    boutonGris_->setDisabled(false);
    boutonNegatif_->setDisabled(false);
}


/****************************************************************************
* Fonction:		fileExplorer
* Description:	Dialogue permettant de choisir une image
* Paramètres:	QFileDialog, QFileDialog::AcceptMode
* Retour:		aucun
****************************************************************************/
void MainWindow::fileExplorer(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;
    // S'il s'agit de la premiere fois que cette fenetre est ouverte
    if(firstDialog) {
        firstDialog = false;
        // Determine l'endroit ou se trouve le dossier image sur cet ordinateur
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        if(picturesLocations.isEmpty())
        {   // S'il n'en existe pas, commencer a partir du repertoire courant
            dialog.setDirectory(QDir::currentPath());
        } else {
            dialog.setDirectory(picturesLocations.last());
        }

        // Filtre les types de fichiers afficher dans la fenetre de dialogue
        QStringList mimeTypeFilters;
        const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen ? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();

        foreach(const QByteArray &mimeTypeName, supportedMimeTypes)
            mimeTypeFilters.append(mimeTypeName);

        dialog.setMimeTypeFilters(mimeTypeFilters);
        // Affiche les jpg par defaut
        dialog.selectMimeTypeFilter("image/jpeg");
        if(acceptMode == QFileDialog::AcceptSave)
            dialog.setDefaultSuffix("jpg");
    }
}


/****************************************************************************
* Fonction:		creeActions
* Description:	Cree les actions de la barre de menu
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void MainWindow::creeActions() {
    // Action fichier + ouvrir
    Ouvrir = new QAction(tr("Ouvrir"), this);
    Ouvrir->setShortcut(QKeySequence::Open);

    // Action fichier + enregistrer sous
    EnregistrerSous = new QAction(tr("Enregistrer sous"), this);
    EnregistrerSous->setEnabled(false);
   EnregistrerSous->setShortcut(QKeySequence::SaveAs);

    // Action aide + a propos
    APropos = new QAction(tr("À propos"), this);

    // Action edition + undo
   Undo = new QAction(tr("Undo"), this);
    Undo->setShortcut(QKeySequence::Undo);

    // Action edition + redo
    Redo =new QAction(tr("Redo"), this);
    Redo->setShortcut(QKeySequence::Redo);
}


/****************************************************************************
* Fonction:		initUI
* Description:	Initialisation de la fenetre principale
* Paramètres:	aucun
* Retour:		aucun
****************************************************************************/
void MainWindow::initUI()
{
    // Donne une taille plus approriee a l'interface
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
    // Centre l'interface dans l'ecran
    QSize newSize(this->width(), this->height());
    setGeometry(
            QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    newSize,
                    qApp->desktop()->availableGeometry()
            )
    );

    // Donne acces au QTableWidget
    tableWidget_ = ui->tableWidget;

    // Permet de configurer la portion avec scroll bar de l'interface
    imageScrollArea_ = ui->ImageScrollArea;
    imageScrollArea_->setBackgroundRole(QPalette::Dark);

    // Ajoutes le menu fichier a la barre de menu principale
    QMenu* Fichier = menuBar()->addMenu(tr("&Fichier"));
    Fichier->addAction(Ouvrir);
    Fichier->addAction(EnregistrerSous);

    // Ajoutez le menu Edition a la barre de menu principale
    QMenu* Edition = menuBar()->addMenu(tr("&Edition"));
    Edition->addAction(Undo);
    Edition->addAction(Redo);

    // Ajoutez le menu Aide a la barre de menu principale
    QMenu* Aide = menuBar()->addMenu(tr("&Aide"));
    Aide->addAction(APropos);

    // GroupBox contenant les boutons
    groupBox_ = ui->groupBox;

    // Layout du groupBox (QHboxLayout)
    QLayout *groupBoxLayout = groupBox_->layout();


    boutonNB_ = new QPushButton( tr("Noire et Blanc"));
    boutonNB_->setDisabled(true);

// Ajoutez le bouton Nuances de Gris
    boutonGris_ = new QPushButton( tr("Mettre En Gris"));
    boutonGris_->setDisabled(true);

// Ajoutez le bouton Negatif
    boutonNegatif_ = new QPushButton( tr("Mettre en Negatif"));
    boutonNegatif_->setDisabled(true);


    // Ajoutez les boutons au layout du groupBox
    groupBoxLayout -> addWidget(boutonNB_);
    groupBoxLayout -> addWidget(boutonGris_);
    groupBoxLayout -> addWidget(boutonNegatif_);

    // Ajoutez l'attribut imageLabel_ au widget imageScrollArea_ et configurez le tel que demande

    imageScrollArea_->setWidget(imageLabel_);
}

