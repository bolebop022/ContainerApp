#ifndef SIMPLECONTAINERFACTORY_H
#define SIMPLECONTAINERFACTORY_H

#include "box.h"
#include "cylinder.h"


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

    std::unique_ptr<Box> createBoxContainer(double weight, double length, double height, double width);
    std::unique_ptr<Cylinder> createCylinderContainer(double weight, double diameter, double height);
};

#endif // SIMPLECONTAINERFACTORY_H
