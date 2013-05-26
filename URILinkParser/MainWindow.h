#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPair>
#include <QVector>
#include <QTreeWidgetItem>

#include "DataTypes/Component.h"
#include "DataTypes/Tree.h"
#include "URI/URIHandler.h"
#include <boost/shared_ptr.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void breakURIIntoComponents();

private:
    void addComponentLevelToTreeWidget(DataTypes::Tree<DataTypes::Component>& components);
    void addSubComponents(QTreeWidgetItem* item, DataTypes::Tree<DataTypes::Component>& components);
    QTreeWidgetItem * setTreeWidgetItem(DataTypes::Tree<DataTypes::Component>& component);


private:
    Ui::MainWindow *ui;
    boost::shared_ptr<URI::URIHandler> _handler;
};

#endif // MAINWINDOW_H
