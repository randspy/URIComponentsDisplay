#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QTableWidget>
#include <QScopedPointer>
#include <QTreeWidget>

#include "Builder/URIHandlerBuilder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->compTree->setHeaderHidden(true);
    connect(ui->breakURIIntoComponents, SIGNAL(released()), this, SLOT(breakURIIntoComponents()));
    connect(ui->URI, SIGNAL(returnPressed()), this, SLOT(breakURIIntoComponents()));

    BL::URIHandlerBuilder builder;
    _handler = builder.buildChainOfResponsibility();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::breakURIIntoComponents()
{
    DataTypes::Tree<DataTypes::Component>components;
    _handler->parse(ui->URI->text().toStdString(), &components);
    addComponentLevelToTreeWidget(components);
}

void MainWindow::addComponentLevelToTreeWidget(DataTypes::Tree<DataTypes::Component>& components)
{
    QList<QTreeWidgetItem *> items;
    unsigned int numberOfComponents = components.numberOfChilds();
    for (unsigned int idx = 0; idx < numberOfComponents; ++idx)
    {
        QTreeWidgetItem* item = setTreeWidgetItem(components.getChild(idx));
        items.append(item);
        addSubComponents(item, components.getChild(idx));
    }

    ui->compTree->clear();
    ui->compTree->insertTopLevelItems(0, items);
    ui->compTree->expandAll();
}

void MainWindow::addSubComponents(QTreeWidgetItem* item, DataTypes::Tree<DataTypes::Component>& components)
{
    unsigned numberOfComponents = components.numberOfChilds();

    for(unsigned int idx = 0; idx < numberOfComponents; ++idx)
    {
        QTreeWidgetItem* child = setTreeWidgetItem(components.getChild(idx));
        item->addChild(child);
        addSubComponents(child, components.getChild(idx));
    }
}

QTreeWidgetItem * MainWindow::setTreeWidgetItem(DataTypes::Tree<DataTypes::Component>& component)
{
    QString tagName = component.getTagName().c_str();
    QString value = component.getValue().getValue().c_str();

    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0,  tagName + " : " + value);
    item->setExpanded(true);
    if(!component.getValue().isValid())
    {
        item->setTextColor(0,Qt::red);
    }

    return item;
}

