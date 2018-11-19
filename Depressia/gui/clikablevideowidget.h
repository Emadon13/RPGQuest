#ifndef CLIKABLEVIDEOWIDGET_H
#define CLIKABLEVIDEOWIDGET_H

#include <QWidget>
#include <QVideoWidget>
#include <Qt>

class ClikableVideoWidget : public QVideoWidget {
    Q_OBJECT

public:
    explicit ClikableVideoWidget(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClikableVideoWidget();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif // CLIKABLEVIDEOWIDGET_H
