#ifndef POSTWIDGET_H
#define POSTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

class PostWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PostWidget(QWidget *parent = nullptr);

signals:

private:
    QPushButton *buttonPostXML;
    QTextEdit *displayPalletXML;
    QVBoxLayout *postLayout;
};

#endif // POSTWIDGET_H
