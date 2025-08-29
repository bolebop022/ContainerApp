#ifndef CYLINDER_H
#define CYLINDER_H

#include "container.h"
#include "cylindermemento.h"
#include <QSharedPointer>

class Cylinder : public Container
{
public:
    Cylinder(QString serialNo, double weight, double diameter, double height);
    double getDiameter() const;
    double getHeight() const;
    int getVolume() const override;
    QSharedPointer<ContainerMemento> createMemento() const override;
    static QSharedPointer<Cylinder> restoreFromMemento(const CylinderMemento& memento);
private:
    double diameter;
    double height;

};

#endif // CYLINDER_H
