#ifndef BOX_H
#define BOX_H

#include "container.h"
#include "boxmemento.h"
#include <QString>
#include <QSharedPointer>

class Box : public Container
{
public:
    // Constructor
    Box(QString serialNo, double weight, double length, double height, double width);

    // Getters
    int getVolume() const override;
    double getLength() const;
    double getHeight() const;
    double getWidth() const;

    // Memento functions
    QSharedPointer<ContainerMemento> createMemento() const override;
    void restoreFromMemento(BoxMemento& memento);

private:
    double length;
    double height;
    double width;
};

#endif // BOX_H
