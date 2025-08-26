#include "cylinder.h"

Cylinder::Cylinder(QString serialNo, double weight, double diameter, double height):
    Container(serialNo, weight), diameter(diameter), height(height)
{

}

int Cylinder::getVolume() const
{
    return diameter * diameter * height * 1;
}

double Cylinder::getDiameter() const
{
    return diameter;
}

double Cylinder::getHeight() const
{
    return height;
}

QSharedPointer<ContainerMemento> Cylinder::createMemento() const
{
    return QSharedPointer<CylinderMemento>::create(serialNo, weight, diameter, height);
}

void Cylinder::restoreFromMemento(CylinderMemento& memento)
{
    serialNo = memento.getSavedSerialNo();
    weight = memento.getSavedWeight();
    diameter = memento.getSavedDiameter();
    height = memento.getSavedHeight();
}
