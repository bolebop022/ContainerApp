#ifndef BOXMEMENTO_H
#define BOXMEMENTO_H

#include "containermemento.h"
#include <QString>
#include <QSharedPointer>

class BoxMemento : public ContainerMemento
{
public:
    BoxMemento(QString serialNo, double weight, double length, double height, double width):
        ContainerMemento(serialNo, weight), length(length), height(height), width(width) {};
    const double getSavedLenght() const;
    const double getSavedHeight() const;
    const double getSavedWidth() const;
    MementoType type() const override;

private:
    double length;
    double height;
    double width;
};

#endif // BOXMEMENTO_H
