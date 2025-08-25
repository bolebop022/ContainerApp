#ifndef CONTAINERMEMENTO_H
#define CONTAINERMEMENTO_H

#include <QString>

class ContainerMemento{
private:
    QString serialNo;
    double weight;

public:
    ContainerMemento(QString serialNo, double weight): serialNo(serialNo), weight(weight) {};
    const double getSavedWeight(){ return weight; };
    const QString& getSavedSerialNo() const { return serialNo; };
};

#endif // CONTAINERMEMENTO_H
