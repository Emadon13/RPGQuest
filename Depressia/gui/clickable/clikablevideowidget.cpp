#include "clikablevideowidget.h"

////////////////////////////////////////////////////////
///                                                  ///
///                   ClikableVideoWidget            ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \class ClikableVideoWidget

    Cette classe est une redéfinition de la classe QVideoWidget, avec l'ajout d'un signal cliked() qui détecte un clic sur ce widget.
*/

////////////////////////////////////////////////////////
///                                                  ///
///                   Constructeur                   ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn ClikableVideoWidget::ClikableVideoWidget(QWidget* parent, Qt::WindowFlags f) : QLabel(parent)

    Construit un QVideoWidget avec le constructeur de la classe parente.
*/
ClikableVideoWidget::ClikableVideoWidget(QWidget *parent, Qt::WindowFlags f)
    : QVideoWidget(parent) {
    Q_UNUSED(f);
}

////////////////////////////////////////////////////////
///                                                  ///
///                   Destructeur                    ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn  ClikableVideoWidget::~ClikableVideoWidget()

    Destructeur
*/
ClikableVideoWidget::~ClikableVideoWidget() {}

////////////////////////////////////////////////////////
///                                                  ///
///                   Fonctions                      ///
///                                                  ///
////////////////////////////////////////////////////////

/*!
    \fn ClikableVideoWidget::mousePressEvent(QMouseEvent* event)

    Emet le signal clicked() lors de la détection d'un clic sur ce widget.
*/
void ClikableVideoWidget::mousePressEvent(QMouseEvent* event) {
    Q_UNUSED(event);
    emit clicked();
}
