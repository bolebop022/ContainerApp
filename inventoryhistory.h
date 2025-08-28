#ifndef INVENTORYHISTORY_H
#define INVENTORYHISTORY_H

#include <QVector>
#include <QSharedPointer>
#include <optional>
#include "containermemento.h"

class InventoryHistory
{
public:
    static InventoryHistory& getInstance();
    void addMemento(QSharedPointer<ContainerMemento> memento);
    std::optional<std::reference_wrapper<const ContainerMemento>> getMemento(int index) const;
    QVector<QSharedPointer<ContainerMemento>> getMementos();

private:
    QVector<QSharedPointer<ContainerMemento>> mementos;

    // Private constructor
    InventoryHistory() = default;

    InventoryHistory(const InventoryHistory&) = delete;
    InventoryHistory& operator=(const InventoryHistory&) = delete;
};

#endif // INVENTORYHISTORY_H
