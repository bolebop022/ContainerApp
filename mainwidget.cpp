#include "mainwidget.h"
#include "simplecontainerfactory.h"
#include "inventoryhistory.h"
#include "boxmemento.h"
#include <QSpinBox>
#include <QPushButton>
#include <QListWidget>
#include <QTextEdit>
#include <QGroupBox>
#include <QGridLayout>
#include <QLabel>
#include <QSharedPointer>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    box_breadth(new QSpinBox()),
    box_length(new QSpinBox()),
    box_height(new QSpinBox()),
    box_weight(new QSpinBox()),
    cylinder_diameter(new QSpinBox()),
    cylinder_height(new QSpinBox()),
    cylinder_weight(new QSpinBox()),
    buttonAddBox(new QPushButton("Add box")),
    buttonAddCylinder(new QPushButton("Add cylinder")),
    displayUnallocated (new QListWidget),
    palletNumber(new QSpinBox()),
    buttonMoveToPallet(new QPushButton("Move to pallet")),
    buttonBackup(new QPushButton("Backup")),
    buttonRestore(new QPushButton("Restore")),
    buttonPostXML(new QPushButton("Post XML to network")),
    displayPalletXML(new QTextEdit)
{
    // Tab 1 - Containers
    QGroupBox *boxGroup(new QGroupBox("Box"));
    QGridLayout *boxlayout(new QGridLayout);
    boxGroup->setLayout(boxlayout);
    QLabel *labelBBreadth(new QLabel("Breadth"));
    boxlayout->addWidget(labelBBreadth, 0, 0);
    boxlayout->addWidget(box_breadth, 0, 1);
    QLabel *labelBLength(new QLabel("Length"));
    boxlayout->addWidget(labelBLength, 1, 0);
    boxlayout->addWidget(box_length, 1, 1);
    QLabel *labelBHeight(new QLabel("Height"));
    boxlayout->addWidget(labelBHeight, 2, 0);
    boxlayout->addWidget(box_height, 2, 1);
    QLabel *labelBWeight(new QLabel("Weight"));
    boxlayout->addWidget(labelBWeight, 3, 0);
    boxlayout->addWidget(box_weight, 3, 1);
    boxlayout->addWidget(buttonAddBox, 4, 0, 1, 2);
    buttonAddBox->setObjectName("BoxButton");

    QGroupBox *cylinderGroup(new QGroupBox("Cylinder"));
    QGridLayout *cylinderlayout(new QGridLayout);
    cylinderGroup->setLayout(cylinderlayout);
    QLabel *labelCDiameter(new QLabel("Diameter"));
    cylinderlayout->addWidget(labelCDiameter, 0, 0);
    cylinderlayout->addWidget(cylinder_diameter, 0, 1);
    QLabel *labelCHeight(new QLabel("Height"));
    cylinderlayout->addWidget(labelCHeight, 1, 0);
    cylinderlayout->addWidget(cylinder_height, 1, 1);
    QLabel *labelCWeight(new QLabel("Weight"));
    cylinderlayout->addWidget(labelCWeight, 2, 0);
    cylinderlayout->addWidget(cylinder_weight, 2, 1);
    QLabel *labelBlank1(new QLabel);
    cylinderlayout->addWidget(labelBlank1, 3, 0);
    cylinderlayout->addWidget(buttonAddCylinder, 4, 0, 1, 2);
    buttonAddCylinder->setObjectName("CylinderButton");

    QWidget *bottomWidget(new QWidget);
    QGridLayout *bottomLayout(new QGridLayout);
    bottomWidget->setLayout(bottomLayout);
    QLabel *labelListOf(new QLabel("List of unallocated containers"));
    bottomLayout->addWidget(labelListOf, 0, 0);
    QLabel *labelClickOn(new QLabel("Click on item in list, choose a pallet number, and Move the container to that pallet"));
    labelClickOn->setWordWrap(true);
    bottomLayout->addWidget(displayUnallocated, 1, 0, 5, 1);
    bottomLayout->addWidget(labelClickOn, 0, 1);
    bottomLayout->addWidget(palletNumber, 1, 1);
    palletNumber->setMinimum(1);
    bottomLayout->addWidget(buttonMoveToPallet, 3, 1);
    QLabel *labelBlank2(new QLabel);
    cylinderlayout->addWidget(labelBlank2, 4, 1);
    bottomLayout->addWidget(buttonBackup, 4, 1);
    bottomLayout->addWidget(buttonRestore, 5, 1);

    QWidget *containerWidget(new QWidget);
    QGridLayout *tabLayoutContainer(new QGridLayout);
    tabLayoutContainer->addWidget(boxGroup, 0, 0);
    tabLayoutContainer->addWidget(cylinderGroup, 0, 1);
    tabLayoutContainer->addWidget(bottomWidget, 1, 0, 1, 2);
    containerWidget->setLayout(tabLayoutContainer);

    // // Tab 2 - Post XML
    // QWidget *postWidget(new QWidget);
    // QVBoxLayout *postLayout(new QVBoxLayout);
    // postWidget->setLayout(postLayout);
    // postLayout->addWidget(buttonPostXML);
    // postLayout->addWidget(displayPalletXML);

    // Connect slots
    // Box container creation slot
    connect(buttonAddBox, &QPushButton::clicked, this, &MainWidget::createBoxContainer);
    // Cylinder container creation slot
    connect(buttonAddCylinder, &QPushButton::clicked, this, &MainWidget::createCylinderContainer);
    // Backup unnallocated containers
    connect(buttonBackup, &QPushButton::clicked, this, &MainWidget::backUpContainers);
    // Restore backed up unnallocated containers
    connect(buttonRestore, &QPushButton::clicked, this, &MainWidget::restoreContainers);
    // Move unallocated containers
    connect(buttonMoveToPallet, &QPushButton::clicked, this, &MainWidget::moveToPellet);

    // setting main widget
    QVBoxLayout *vertical(new QVBoxLayout);
    vertical->addWidget(containerWidget);
    // vertical->addWidget(postWidget);
    setLayout(vertical);
}

void MainWidget::createBoxContainer()
{
    SimpleContainerFactory& factory = SimpleContainerFactory::getInstance();


    // Create box item
    QSharedPointer<Box> newBox = factory.createBoxContainer(box_weight->value(), box_length->value(), box_height->value(), box_breadth->value());

    // Add containter to unallocated container list
    unallocatedContainers.push_back(newBox);

    qDebug() << newBox->getserialNo();
    displayUnallocated->addItem(newBox->getserialNo());
}

void MainWidget::createCylinderContainer()
{
    SimpleContainerFactory& factory = SimpleContainerFactory::getInstance();


    // Create a cylinder item
    QSharedPointer<Cylinder> newContainer = factory.createCylinderContainer(cylinder_weight->value(), cylinder_diameter->value(), cylinder_height->value());

    // Add containter to unallocated container list
    unallocatedContainers.push_back(newContainer);

    // // Backup box item
    // history.addMemento(newContainer->createMemento());

    qDebug() << newContainer->getserialNo();
    displayUnallocated->addItem(newContainer->getserialNo());
}

void MainWidget::backUpContainers()
{
    InventoryHistory& history = InventoryHistory::getInstance();

    for(auto& container: unallocatedContainers)
    {
        history.addMemento(container->createMemento());
        qDebug() << "Backed up: " + container->getserialNo();
    }

    // Debugging purposes
    qDebug() << "First item in list: " + history.getMemento(0)->get().getSavedSerialNo();

    // Clear the list and view after backing up the containers
    unallocatedContainers.clear();
    displayUnallocated->clear();
    qDebug() << "List cleared.";
}

void MainWidget::restoreContainers()
{
    InventoryHistory& history = InventoryHistory::getInstance();

    for(int i = 0; i < history.getMementos().size(); ++i)
    {
        // Assumptions are that these are parrallel arrays.
        QSharedPointer<ContainerMemento> containerMemento = history.getMementos().at(i);

        switch(containerMemento->type())
        {
            case MementoType::Box:
            {
                auto boxMemento = containerMemento.dynamicCast<BoxMemento>();
                // Restore the containers to list and view
                unallocatedContainers.append(Box::restoreFromMemento(*boxMemento));
                displayUnallocated->addItem(boxMemento->getSavedSerialNo());
                break;
            }
            case MementoType::Cylinder:
            {
                auto cylinderMemento = containerMemento.dynamicCast<CylinderMemento>();
                // Restore the containers to list and view
                unallocatedContainers.append(Cylinder::restoreFromMemento(*cylinderMemento));
                displayUnallocated->addItem(cylinderMemento->getSavedSerialNo());
                break;
            }
        }

        qDebug() << "Restored: " + containerMemento->getSavedSerialNo();

    }
}

void MainWidget::moveToPellet()
{
    // Check if the user has selected a container from the displayed list
    if(displayUnallocated->selectedItems().isEmpty())
    {
        qDebug() << "Select an unallocated container or containers.";
        return;
    }

    // Find the container selected by the user
    QString serialNo = displayUnallocated->currentItem()->text();
    auto container = getUnallocatedContainer(serialNo);
    if(container)
    {
        qDebug() << container->getserialNo();
    }
    else
    {
        qDebug() <<  "Container does not exist or has been allocated.";
        return;
    }

    QString serialNoBefore = container->getserialNo();

    // Move the container to the selected pallet.
    if(pallets.contains(palletNumber->value()))
    {

        pallets[palletNumber->value()].append(std::move(container));

        // Remove unallocated containers
        unallocatedContainers.removeIf([&](const QSharedPointer<Container>& c) {
            return c->getserialNo() == serialNo;
        });

        // Inform the user the container has been moved
        qDebug() << serialNoBefore + " has been added to pallet " + QString::number(palletNumber->value());
    }
    else
    {
        QVector<QSharedPointer<Container>> newVector;
        newVector.append(std::move(container));
        pallets.insert(palletNumber->value(), newVector);

        // Remove unallocated containers
        unallocatedContainers.removeIf([&](const QSharedPointer<Container>& c) {
            return c->getserialNo() == serialNo;
        });

        // Inform the user the container has been moved
        qDebug() << serialNoBefore + " has been added to pallet " + QString::number(palletNumber->value());
    }
    // Redraw the list of updated objects
    drawUnallocatedContainers();
}

void MainWidget::drawUnallocatedContainers()
{
    displayUnallocated->clear();
    for(auto& container: unallocatedContainers)
    {
        qDebug() << container->getserialNo();
        displayUnallocated->addItem(container->getserialNo());
    }
}

QSharedPointer<Container> MainWidget::getUnallocatedContainer(const QString& text) const
{
    for(auto& container: unallocatedContainers)
    {
        if (container->getserialNo() == text)
            return container;
    }
    return nullptr;
}

MainWidget::~MainWidget()
{
};

