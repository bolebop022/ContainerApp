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

QSharedPointer<Cylinder> Cylinder::restoreFromMemento(const CylinderMemento& memento)
{
    return std::move(
        QSharedPointer<Cylinder>::create(
                                    memento.getSavedSerialNo(),
                                    memento.getSavedWeight(),
                                    memento.getSavedDiameter(),
            memento.getSavedHeight()));
}
