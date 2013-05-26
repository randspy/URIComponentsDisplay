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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::breakURIIntoComponents()
{
    ui->compTree->clear();

    BL::URIHandlerBuilder builder;
    boost::shared_ptr<URI::URIHandler> handler = builder.buildChainOfResponsibility();
    DataTypes::Tree<DataTypes::Component>components;

    handler->parse(ui->URI->text().toStdString(), &components);


    addComponentLevelToTreeWidget(components);

}


void MainWindow::addComponentLevelToTreeWidget(DataTypes::Tree<DataTypes::Component>& components)
{
    QList<QTreeWidgetItem *> items;
    unsigned int numberOfComponents = components.numberOfChilds();
    for (unsigned int idx = 0; idx < numberOfComponents; ++idx)
    {
        QString tagName = components.getChild(idx).getTagName().c_str();
        QString value = components.getChild(idx).getValue().getValue().c_str();
        QTreeWidgetItem* item = new QTreeWidgetItem();
        item->setText(0,  tagName + " : " + value);
        items.append(item);

        addSubComponents(item, components.getChild(idx));
    }

    ui->compTree->insertTopLevelItems(0, items);
}

void MainWindow::addSubComponents(QTreeWidgetItem* item, DataTypes::Tree<DataTypes::Component>& components)
{
    unsigned numberOfComponents = components.numberOfChilds();

    for(unsigned int idx = 0; idx < numberOfComponents; ++idx)
    {
        QString tagName = components.getChild(idx).getTagName().c_str();
        QString value = components.getChild(idx).getValue().getValue().c_str();
        QTreeWidgetItem* child = new QTreeWidgetItem();
        child->setText(0,  tagName + " : " + value);
        item->addChild(child);

        addSubComponents(child, components.getChild(idx));
    }
}
