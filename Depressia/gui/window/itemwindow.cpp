#include "itemwindow.h"
#include "logic/game.h"
#include <QLabel>

ItemWindow::ItemWindow(Map *m, QWidget *parent) :
    QMainWindow(parent)
{

    this->map=m;
    this->mapElement=map->getCurrentPosition();

    int WindowWidth(640);
    int WindowHeight(360);

    int BoutonWidth(100);
    int BoutonHeight(60);

    int TitreWidth(300);
    int TitreHeight(100);

    int InfoWidth(300);
    int InfoHeight(100);

    int ImageWidth(250);
    int ImageHeight(250);

    int espacement=30;

    setWindowTitle("Item Found");
    setWindowIcon(QIcon("../ressources/images/icone.png"));
    setFixedSize(WindowWidth,WindowHeight);

    QPalette p( palette() );
    p.setBrush(QPalette::Window, QBrush(QPixmap("../ressources/images/itemBackground.png")));
    setPalette(p);

    ok = new QPushButton("OK !", this);
    ok->setFixedSize(BoutonWidth,BoutonHeight);
    ok->setCursor(QCursor(QPixmap("../ressources/images/cursor.png"), 0, 0));
    ok->move((WindowWidth-BoutonWidth)/2,(WindowHeight-espacement-BoutonHeight));
    ok->show();

    QLabel *image = new QLabel(this);
    image->setPixmap(QPixmap(QString::fromStdString(mapElement.getEvent().getItem().getImage())));
    image->setFixedSize(ImageWidth,ImageHeight);
    image->move(espacement,(WindowHeight-ImageHeight)/2);
    image->show();

    QLabel *titre = new QLabel(this);
    titre->setText(QString::fromStdString(mapElement.getEvent().getItem().getName()));
    titre->setFixedSize(TitreWidth,TitreHeight);
    titre->setAlignment(Qt::AlignCenter);
    titre->move(espacement*2+ImageWidth,espacement);
    titre->show();

    QLabel *info = new QLabel(this);
    info->setText(QString::fromStdString(mapElement.getEvent().getItem().getText()));
    info->setFixedSize(InfoWidth,InfoHeight);
    info->setAlignment(Qt::AlignCenter);
    info->move(espacement*2+ImageWidth,espacement*2+TitreHeight);
    info->show();

std::cout<<mapElement.getEvent().getItem().getImage();

    QObject::connect(ok, SIGNAL(clicked()), this, SLOT(close()));

}
