#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRegExpValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Create a string for regular expression */
    QString ipRange = "(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])";
    /* Create a regex using string as
     * repeating element
     */
    QRegExp ipRegex ("^" + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange
                     + "\\." + ipRange + "$");
    /* Create a regex validator using
     * created regular expression
     */
    QRegExpValidator *ipValidator = new QRegExpValidator(ipRegex, this);
    /* Install the Validator on QLineEdit */
    ui->lineEdit->setValidator(ipValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}
