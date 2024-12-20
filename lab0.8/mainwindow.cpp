#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createDatabase();

    // Связь кнопок с слотами
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::on_addButton_clicked);
    connect(ui->removeButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
    connect(ui->viewAllButton, &QPushButton::clicked, this, &MainWindow::on_viewButton_clicked);
    connect(ui->filterButton, &QPushButton::clicked, this, &MainWindow::on_filterButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("simpledb.sqlite");

    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;
    if (!query.exec("CREATE TABLE IF NOT EXISTS products ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "name TEXT NOT NULL, "
                    "date TEXT NOT NULL, "
                    "price REAL NOT NULL)")) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }
}

void MainWindow::addRecord(const QString &name, const QString &date, double price) {
    if (name.isEmpty() || date.isEmpty() || price <= 0) {
        QMessageBox::warning(this, "Input Error", "Please provide valid input for all fields.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM products WHERE name = :name AND date = :date AND price = :price");
    query.bindValue(":name", name);
    query.bindValue(":date", date);
    query.bindValue(":price", price);

    if (query.exec() && query.next() && query.value(0).toInt() > 0) {
        QMessageBox::warning(this, "Duplicate Error", "This record already exists.");
        return;
    }

    query.prepare("INSERT INTO products (name, date, price) VALUES (:name, :date, :price)");
    query.bindValue(":name", name);
    query.bindValue(":date", date);
    query.bindValue(":price", price);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

    // Обновляем отображение записей после добавления
    viewRecords();
}

void MainWindow::deleteRecord(int id) {
    if (id <= 0) {
        QMessageBox::warning(this, "Input Error", "Please provide a valid ID.");
        return;
    }

    QSqlQuery query;
    query.prepare("DELETE FROM products WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        QMessageBox::critical(this, "Database Error", query.lastError().text());
    }

    // Обновляем отображение записей после удаления
    viewRecords();
}

void MainWindow::viewRecords() {
    // Удаляем старую модель перед созданием новой
    ui->tableView->setModel(nullptr);

    auto *model = new QSqlTableModel(this);
    model->setTable("products");
    model->select();
    ui->tableView->setModel(model);

    // Устанавливаем автоудаление модели при удалении QTableView
    ui->tableView->setProperty("model", QVariant::fromValue(model));

    // Отладочный вывод для проверки данных
    QSqlQuery query("SELECT * FROM products");
    while (query.next()) {
        qDebug() << query.value("id").toInt()
                 << query.value("name").toString()
                 << query.value("date").toString()
                 << query.value("price").toDouble();
    }
}

void MainWindow::filterRecords(const QString &filter) {
    ui->tableView->setModel(nullptr);

    auto *model = new QSqlQueryModel(this);
    model->setQuery("SELECT * FROM products WHERE name LIKE '%" + filter + "%'");
    if (model->lastError().isValid()) {
        QMessageBox::critical(this, "Database Error", model->lastError().text());
    } else {
        ui->tableView->setModel(model);

        // Устанавливаем автоудаление модели при удалении QTableView
        ui->tableView->setProperty("model", QVariant::fromValue(model));
    }
}

// Реализация слотов для кнопок
void MainWindow::on_addButton_clicked() {
    QString name = ui->nameLineEdit->text();
    QString date = ui->dateLineEdit->text();
    double price = ui->priceLineEdit->text().toDouble();
    addRecord(name, date, price);
}

void MainWindow::on_deleteButton_clicked() {
    int id = ui->idLineEdit->text().toInt();
    deleteRecord(id);
}

void MainWindow::on_viewButton_clicked() {
    viewRecords();
}

void MainWindow::on_filterButton_clicked() {
    QString filter = ui->filterLineEdit->text();
    filterRecords(filter);
}
