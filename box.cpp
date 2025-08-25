#include "box.h"
#include "boxmemento.h"

Box::Box(QString serialNo, double weight, double length, double height, double width):
    Container(serialNo,weight), length(length), height(height), width(width){

};

int Box::getVolume() const
{
    return length * height * width;
}

double Box::getLength() const
{
    return length;
}

double Box::getHeight() const
{
    return height;
}

double Box::getWidth() const
{
    return width;
}

QSharedPointer<BoxMemento> Box::createMemento() const
{
    return QSharedPointer<BoxMemento>::create(this->getserialNo(), this->getWeight(), length, height, width);
}

void Box::restoreFromMemento(BoxMemento& memento)
{
    this->serialNo = memento.getSavedSerialNo();
    this->weight = memento.getSavedWeight();
    this->height = memento.getSavedHeight();
    this->length = memento.getSavedLenght();
    this->width = memento.getSavedWidth();
}












