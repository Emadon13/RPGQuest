#include "clickablelabel.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   ClickableLabel                 ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class ClickaebleLabel

    Cette classe est une redéfinition de la classe QT QLabel, avec l'ajout d'un signal cliked() qui détecte un clic sur ce label.
*/

////////////////////////////////////////////////////////
///                                                  ///
///                   Constructeur                   ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f) : QLabel(parent)

    Construit un QLabel avec le constructeur de la classe parente.
*/
ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent) {
    Q_UNUSED(f);
}

////////////////////////////////////////////////////////
///                                                  ///
///                   Destructeur                    ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn  ClickableLabel::~ClickableLabel()

    Destructeur
*/
ClickableLabel::~ClickableLabel() {}

////////////////////////////////////////////////////////
///                                                  ///
///                   Fonctions                      ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn ClickableLabel::mousePressEvent(QMouseEvent* event)

    Emet le signal clicked() lors de la détection d'un clic sur ce label.
*/
void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    emit clicked();
}
