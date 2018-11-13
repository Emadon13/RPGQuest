#ifndef GLOBALSPEC_H
#define GLOBALSPEC_H

#include <QObject>
#include <QWidget>

class GlobalSpec : public QObject
{
    Q_OBJECT
public:
    explicit GlobalSpec(QObject *parent = 0);
    QWidget * mainW;

signals:

public slots:
};

#endif // GLOBALSPEC_H
