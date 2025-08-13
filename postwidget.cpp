#include "postwidget.h"

PostWidget::PostWidget(QWidget *parent)
    : QWidget(parent),
    buttonPostXML(new QPushButton("Post XML to network")),
    displayPalletXML(new QTextEdit)
{

    postLayout = new QVBoxLayout();

    postLayout->addWidget(buttonPostXML);
    postLayout->addWidget(displayPalletXML);
    setLayout(postLayout);
}
