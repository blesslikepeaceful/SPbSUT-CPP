/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *viewAllButton;
    QPushButton *filterButton;
    QLineEdit *filterLineEdit;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *nameLineEdit;
    QLineEdit *idLineEdit;
    QLineEdit *dateLineEdit;
    QLineEdit *priceLineEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(20, 40, 361, 331));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(680, 80, 100, 26));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(690, 280, 80, 26));
        viewAllButton = new QPushButton(centralwidget);
        viewAllButton->setObjectName("viewAllButton");
        viewAllButton->setGeometry(QRect(610, 330, 100, 26));
        filterButton = new QPushButton(centralwidget);
        filterButton->setObjectName("filterButton");
        filterButton->setGeometry(QRect(420, 290, 100, 26));
        filterLineEdit = new QLineEdit(centralwidget);
        filterLineEdit->setObjectName("filterLineEdit");
        filterLineEdit->setGeometry(QRect(500, 20, 239, 26));
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(420, 60, 241, 200));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        nameLineEdit = new QLineEdit(widget);
        nameLineEdit->setObjectName("nameLineEdit");

        gridLayout->addWidget(nameLineEdit, 1, 0, 1, 1);

        idLineEdit = new QLineEdit(widget);
        idLineEdit->setObjectName("idLineEdit");

        gridLayout->addWidget(idLineEdit, 0, 0, 1, 1);

        dateLineEdit = new QLineEdit(widget);
        dateLineEdit->setObjectName("dateLineEdit");

        gridLayout->addWidget(dateLineEdit, 3, 0, 1, 1);

        priceLineEdit = new QLineEdit(widget);
        priceLineEdit->setObjectName("priceLineEdit");

        gridLayout->addWidget(priceLineEdit, 4, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        viewAllButton->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        filterButton->setText(QCoreApplication::translate("MainWindow", "\321\204\320\270\320\273\321\214\321\202\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        idLineEdit->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
