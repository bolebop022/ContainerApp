#include "simplecontainerfactory.h"
#include <QDateTime>

SimpleContainerFactory::SimpleContainerFactory():boxCode(1), cylinderCode(1) {}

SimpleContainerFactory* SimpleContainerFactory::instance = nullptr;


SimpleContainerFactory& SimpleContainerFactory::getInstance()
{
    static SimpleContainerFactory instance;
    return instance;
}

std::unique_ptr<Box> SimpleContainerFactory::createBoxContainer(double weight, double length, double height, double width)
{
    QDateTime* currentDateTime = new QDateTime();
    int year = currentDateTime->currentDateTime().date().year();
    int month = currentDateTime->currentDateTime().date().month();
    QString serialNumber = QString::number(year) + "/" + QString::number(month)+ "/" + "B" + QString::number(boxCode++);
    delete currentDateTime;
    return std::make_unique<Box>(serialNumber, weight, length, height, width);
}

std::unique_ptr<Cylinder> SimpleContainerFactory::createCylinderContainer(double weight, double diameter, double height)
{
    QDateTime* currentDateTime = new QDateTime();
    int year = currentDateTime->currentDateTime().date().year();
    int month = currentDateTime->currentDateTime().date().month();
    QString serialNumber = QString::number(year) + "/" + QString::number(month)+ "/" + "C" + QString::number(boxCode++);
    delete currentDateTime;
    return std::make_unique<Cylinder>(serialNumber, weight, diameter, height);
}
