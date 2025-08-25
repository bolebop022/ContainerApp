#include "simplecontainerfactory.h"
#include <QDateTime>

SimpleContainerFactory::SimpleContainerFactory():boxCode(1), cylinderCode(1) {}

SimpleContainerFactory* SimpleContainerFactory::instance = nullptr;


SimpleContainerFactory& SimpleContainerFactory::getInstance()
{
    static SimpleContainerFactory instance;
    return instance;
}

QSharedPointer<Box> SimpleContainerFactory::createBoxContainer(double weight, double length, double height, double width)
{
    QDateTime* currentDateTime = new QDateTime();
    int year = currentDateTime->currentDateTime().date().year();
    int month = currentDateTime->currentDateTime().date().month();
    QString serialNumber = QString::number(year) + "/" + QString::number(month)+ "/" + "B" + QString::number(boxCode++);
    delete currentDateTime;
    return QSharedPointer<Box>::create(serialNumber, weight, length, height, width);
}

QSharedPointer<Cylinder> SimpleContainerFactory::createCylinderContainer(double weight, double diameter, double height)
{
    QDateTime* currentDateTime = new QDateTime();
    int year = currentDateTime->currentDateTime().date().year();
    int month = currentDateTime->currentDateTime().date().month();
    QString serialNumber = QString::number(year) + "/" + QString::number(month)+ "/" + "C" + QString::number(boxCode++);
    delete currentDateTime;
    return QSharedPointer<Cylinder>::create(serialNumber, weight, diameter, height);
}
