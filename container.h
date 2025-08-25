#ifndef CONTAINER_H
#define CONTAINER_H

#include <QString>

class Container{
protected:
    QString& serialNo;
    double weight;

public:
    Container(QString& serialNo, double weight): serialNo(serialNo), weight(weight){};
    virtual int getVolume() const = 0;
    const double getWeight() const { return weight; };
    QString& getserialNo() const{ return serialNo; };


};

#endif // CONTAINER_H
