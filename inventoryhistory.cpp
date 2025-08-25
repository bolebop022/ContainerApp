#include "inventoryhistory.h"

InventoryHistory& InventoryHistory::getInstance()
{
    static InventoryHistory instance;
    return instance;
}

void InventoryHistory::addMemento(const ContainerMemento& memento)
{
    mementos.push_back(memento);
}

std::optional<ContainerMemento> InventoryHistory::getMemento(int index) const
{
    if (index < 0 || index >= mementos.size())
        return std::nullopt;
    return mementos.at(index);
}
