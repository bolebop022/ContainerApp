#ifndef CONTAINERMEMENTO_H
#define CONTAINERMEMENTO_H

#include <QString>

enum class MementoType { Box, Cylinder };

class ContainerMemento{
private:
    QString serialNo;
    double weight;

public:
    ContainerMemento(QString serialNo, double weight): serialNo(serialNo), weight(weight) {};
    const double getSavedWeight() const { return weight; };
    const QString& getSavedSerialNo() const { return serialNo; };
    virtual MementoType type() const = 0;
};

#endif // CONTAINERMEMENTO_H
