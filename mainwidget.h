#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QSharedPointer>
#include <QVector>

#include "container.h"

class QSpinBox;
class QPushButton;
class QListWidget;
class QTextEdit;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:

private:
    QSpinBox *box_breadth, *box_length, *box_height, *box_weight;
    QSpinBox *cylinder_diameter, *cylinder_height, *cylinder_weight;
    QPushButton *buttonAddBox, *buttonAddCylinder;
    QListWidget *displayUnallocated;
    QSpinBox *palletNumber;
    QPushButton *buttonMoveToPallet, *buttonBackupRestore;
    QPushButton *buttonPostXML;
    QTextEdit *displayPalletXML;
    QWidget *postWidget;

    QVector<QSharedPointer<Container>> unallocatedContainers;

    // Creation methods
    void createBoxContainer();
    void createCylinderContainer();

    void backUpContainers();
};

#endif // MAINWIDGET_H
