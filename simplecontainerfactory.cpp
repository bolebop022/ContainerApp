#include "simplecontainerfactory.h"
#include <QDateTime>

SimpleContainerFactory::SimpleContainerFactory():boxCode(1), cylinderCode(1) {}


SimpleContainerFactory& SimpleContainerFactory::getInstance()
{
    static SimpleContainerFactory instance;
    return instance;
}

QSharedPointer<Box> SimpleContainerFactory::createBoxContainer(double weight, double length, double height, double width)
{
    QDateTime* currentDateTime = new QDateTime();
    QString currentStringDate = currentDateTime->currentDateTime().toString("yyyy/MM/");
    QString serialNumber = currentStringDate + "B" + QString::number(boxCode++);
    delete currentDateTime;
    return QSharedPointer<Box>::create(serialNumber, weight, length, height, width);
}

QSharedPointer<Cylinder> SimpleContainerFactory::createCylinderContainer(double weight, double diameter, double height)
{
    QDateTime* currentDateTime = new QDateTime();
    QString currentStringDate = currentDateTime->currentDateTime().toString("yyyy/MM/");
    QString serialNumber = currentStringDate + "C" + QString::number(cylinderCode++);
    delete currentDateTime;
    return QSharedPointer<Cylinder>::create(serialNumber, weight, diameter, height);
}
