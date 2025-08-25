#ifndef INVENTORYHISTORY_H
#define INVENTORYHISTORY_H

#include <QVector>
#include <optional>
#include "containermemento.h"

class InventoryHistory
{
public:
    static InventoryHistory& getInstance();
    void addMemento(const ContainerMemento& memento);
    std::optional<ContainerMemento> getMemento(int index) const;

private:
    QVector<ContainerMemento> mementos;

    // Private constructor
    InventoryHistory() = default;

    InventoryHistory(const InventoryHistory&) = delete;
    InventoryHistory& operator=(const InventoryHistory&) = delete;
};

#endif // INVENTORYHISTORY_H
