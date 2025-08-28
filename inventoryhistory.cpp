#include "inventoryhistory.h"
#include <functional>

InventoryHistory& InventoryHistory::getInstance()
{
    static InventoryHistory instance;
    return instance;
}

void InventoryHistory::addMemento(QSharedPointer<ContainerMemento> memento)
{
    mementos.push_back(memento);
}

std::optional<std::reference_wrapper<const ContainerMemento>>  InventoryHistory::getMemento(int index) const
{
    if (index < 0 || index >= mementos.size())
        return std::nullopt;
    return std::cref(*mementos.at(index));
}

QVector<QSharedPointer<ContainerMemento>> InventoryHistory::getMementos()
{
    return mementos;
}
