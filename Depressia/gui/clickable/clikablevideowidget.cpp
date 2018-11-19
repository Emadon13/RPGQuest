#include "clikablevideowidget.h"

ClikableVideoWidget::ClikableVideoWidget(QWidget *parent, Qt::WindowFlags f)
    : QVideoWidget(parent) {
}

ClikableVideoWidget::~ClikableVideoWidget() {}

void ClikableVideoWidget::mousePressEvent(QMouseEvent* event) {
    emit clicked();
}
