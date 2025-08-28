#include "boxmemento.h"

const double BoxMemento::getSavedLenght() const { return length; };

const double BoxMemento::getSavedHeight() const { return height; };

const double BoxMemento::getSavedWidth() const { return width; };

MementoType BoxMemento::type() const { return MementoType::Box;}
