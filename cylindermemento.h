#ifndef CYLINDERMEMENTO_H
#define CYLINDERMEMENTO_H

#include "containermemento.h"

class CylinderMemento : public ContainerMemento
{
public:
    CylinderMemento(QString serialNo, double weight, double diameter, double height):
        ContainerMemento(serialNo, weight), diameter(diameter), height(height){};
    const double getSavedDiameter() const;
    const double getSavedHeight() const;

private:
    double diameter;
    double height;

};

#endif // CYLINDERMEMENTO_H
