#ifndef SIMPLECONTAINERFACTORY_H
#define SIMPLECONTAINERFACTORY_H

#include "box.h"
#include "cylinder.h"

#include <QSharedPointer>


class SimpleContainerFactory
{
private:
    // Private constructor
    SimpleContainerFactory();
    static SimpleContainerFactory* instance;

    // Delete copy constructor
    SimpleContainerFactory(const SimpleContainerFactory&) = delete;
    SimpleContainerFactory& operator=(const SimpleContainerFactory&) = delete;

    int boxCode;
    int cylinderCode;

public:

    static SimpleContainerFactory& getInstance();

    QSharedPointer<Box> createBoxContainer(double weight, double length, double height, double width);
    QSharedPointer<Cylinder> createCylinderContainer(double weight, double diameter, double height);
};

#endif // SIMPLECONTAINERFACTORY_H
