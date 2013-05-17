#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QTableWidget>
#include <QScopedPointer>
#include <QTableWidgetItem>
#include <QTableWidget>

#include "URI/RFC2396URIStandardParser.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->breakURIIntoComponents, SIGNAL(released()), this, SLOT(breakURIIntoComponents()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::breakURIIntoComponents()
{
    QScopedPointer<URI::URIParser> parser(new URI::RFC2396URIStandardParser(ui->URI->text().toStdString()));
    URI::URIComponents components = parser->parseURI();

    fillTable(convertComponentsToTableForm(components));
}

QVector<MainWindow::Pair> MainWindow::convertComponentsToTableForm(const URI::URIComponents& components)
{

    QVector<MainWindow::Pair> virtualTable;

#define PUSH_BACK(first,second)    if(!second.isEmpty()) \
                                    {\
                                        virtualTable.push_back(Pair(first, second));\
                                    }

    PUSH_BACK("Schema", QString(components.getSchema().c_str()));
    PUSH_BACK("Authority", QString(components.getAuthority().c_str()));
    PUSH_BACK("Path", QString(components.getPath().c_str()));
    PUSH_BACK("Query", QString(components.getQuery().c_str()));
    PUSH_BACK("Fragment", QString(components.getFragment().c_str()));

#undef PUSH_BACK

    return virtualTable;
}

void MainWindow::fillTable(const QVector<MainWindow::Pair>& virtualTable)
{
    int numOfRows = virtualTable.size();

    if(numOfRows)
    {
        ui->components->setColumnCount(2);
        ui->components->setRowCount(numOfRows);

        fillTableItems(virtualTable);

        ui->components->resizeColumnToContents(0);
        ui->components->horizontalHeader()->setStretchLastSection(true);
    }
    else
    {
        ui->components->setColumnCount(0);
        ui->components->setRowCount(0);
    }
}

void MainWindow::fillTableItems(const QVector<MainWindow::Pair>& virtualTable)
{
    int numOfRows = virtualTable.size();

    for(int idx = 0; idx < numOfRows; ++idx)
    {
        QTableWidgetItem* componentName = new QTableWidgetItem(virtualTable[idx].first);
        componentName->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        QTableWidgetItem* componentValue = new QTableWidgetItem(virtualTable[idx].second);
        componentValue->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);

        ui->components->setItem(idx, 0, componentName);
        ui->components->setItem(idx, 1, componentValue);
    }
}
