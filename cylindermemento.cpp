#include "cylindermemento.h"

const double CylinderMemento::getSavedDiameter() const {return diameter;}

const double CylinderMemento::getSavedHeight() const {return height; }

MementoType CylinderMemento::type() const {return MementoType::Cylinder;}
