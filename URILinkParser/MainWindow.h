#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPair>
#include <QVector>

#include "URI/URIComponents.h"

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
    typedef QPair<QString, QString> Pair;

    QVector<Pair> convertComponentsToTableForm(const URI::URIComponents& components);
    void fillTable(const QVector<MainWindow::Pair>& virtualTable);
    void fillTableItems(const QVector<MainWindow::Pair>& virtualTable);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
