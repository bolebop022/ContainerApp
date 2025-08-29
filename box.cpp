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

QSharedPointer<ContainerMemento> Box::createMemento() const
{
    return QSharedPointer<BoxMemento>::create(this->getserialNo(), this->getWeight(), length, height, width);
}

QSharedPointer<Box> Box::restoreFromMemento(const BoxMemento& memento)
{
    return std::move(QSharedPointer<Box>::create(
                memento.getSavedSerialNo(),
                memento.getSavedWeight(),
                memento.getSavedLenght(),
                memento.getSavedHeight(),
                memento.getSavedWidth()));
}












