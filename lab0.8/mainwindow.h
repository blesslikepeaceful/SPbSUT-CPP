#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QTableView>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addButton_clicked();
    void on_deleteButton_clicked();
    void on_viewButton_clicked();
    void on_filterButton_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    void createDatabase();
    void addRecord(const QString &name, const QString &date, double price);
    void deleteRecord(int id);
    void viewRecords();
    void filterRecords(const QString &filter);
};

#endif // MAINWINDOW_H
