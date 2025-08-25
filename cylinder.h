#ifndef CYLINDER_H
#define CYLINDER_H

#include "container.h"
#include "cylindermemento.h"

class Cylinder : public Container
{
public:
    Cylinder(QString serialNo, double weight, double diameter, double height);
    double getDiameter() const;
    double getHeight() const;
    int getVolume() const override;
    std::unique_ptr<CylinderMemento> createMemento() const;
    void restoreFromMemento(CylinderMemento& memento);
private:
    double diameter;
    double height;

};

#endif // CYLINDER_H
