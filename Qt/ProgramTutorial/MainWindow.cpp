#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TutorialDialog.h"
#include "TutorialDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->startTutorialButton, &QPushButton::clicked, this, &MainWindow::onStartTutorialButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartTutorialButtonClicked()
{
    TutorialDialog tutorialDialog;  // Create tutorial dialog

    // Add widgets to tutorial dialog
    tutorialDialog.addWidgetToTutorial(ui->projectStructureTreeView, tr("This is project structure"));
    tutorialDialog.addWidgetToTutorial(ui->createProjectButton, tr("Create new project using this button"));
    tutorialDialog.addWidgetToTutorial(ui->openProjectButton, tr("Open your project using this button"));
    tutorialDialog.addWidgetToTutorial(ui->infoWidget, tr("Here You will see some information about objects in your project"));

    // Start tutorial dialog
    tutorialDialog.exec();
}
