#ifndef CONTAINER_H
#define CONTAINER_H

#include <QString>
#include <QSharedPointer>
#include "containermemento.h"

class Container{
protected:
    QString serialNo;
    double weight;

public:
    Container(QString& serialNo, double weight): serialNo(serialNo), weight(weight){};
    virtual int getVolume() const = 0;
    const double getWeight() const { return weight; };
    QString getserialNo() const{ return serialNo; };
    virtual QSharedPointer<ContainerMemento> createMemento() const = 0;
    virtual void restoreFromMemento(const ContainerMemento& memento) = 0;

};

#endif // CONTAINER_H
