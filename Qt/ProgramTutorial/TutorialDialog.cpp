#include "TutorialDialog.h"
#include "ui_TutorialDialog.h"

#include <QDebug>

TutorialDialog::TutorialDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TutorialDialog)
{
    ui->setupUi(this);
    setModal(true);                 // this dialog should be modal
    setWindowFlags(Qt::Window);     // but it doesn`t create shadow on mainwindow

    connect(ui->closeButton, &QPushButton::clicked, this, &TutorialDialog::close);
    connect(ui->previousButton, &QPushButton::clicked, this, &TutorialDialog::onPreviousButtonClicked);
    connect(ui->nextButton, &QPushButton::clicked, this, &TutorialDialog::onNextButtonClicked);

    updateButtonsEnabled();
}

TutorialDialog::~TutorialDialog()
{
    // When dialog was destrcucted, we should set up old style to current widget
    returnOldStyle();
    delete ui;
}

void TutorialDialog::addWidgetToTutorial(QWidget* widget, const QString& text)
{
    if (m_infoItems.empty())
    {
        m_currentTutorialInfoIndex = 0;
    }

    m_infoItems.push_back({widget, text});
    updateButtonsEnabled();

    if (m_infoItems.size() == 1)
    {
        setTextAndStyle();
    }
}

void TutorialDialog::onPreviousButtonClicked()
{
    returnOldStyle();
    --m_currentTutorialInfoIndex;
    setTextAndStyle();
    updateButtonsEnabled();
}

void TutorialDialog::onNextButtonClicked()
{
    returnOldStyle();
    ++m_currentTutorialInfoIndex;
    setTextAndStyle();
    updateButtonsEnabled();
}

void TutorialDialog::updateButtonsEnabled()
{
    ui->previousButton->setEnabled(m_currentTutorialInfoIndex != -1 && m_currentTutorialInfoIndex > 0);
    ui->nextButton->setEnabled(m_currentTutorialInfoIndex != -1 && m_currentTutorialInfoIndex < m_infoItems.size() - 1);
}

void TutorialDialog::returnOldStyle()
{
    if (m_currentTutorialInfoIndex != -1)
    {
        m_infoItems[m_currentTutorialInfoIndex].widget->setStyleSheet(m_oldStyleOfWidget);
    }
}

void TutorialDialog::setTextAndStyle()
{
    ui->textBrowser->setText(m_infoItems[m_currentTutorialInfoIndex].text);
    m_oldStyleOfWidget = m_infoItems[m_currentTutorialInfoIndex].widget->styleSheet();
    m_infoItems[m_currentTutorialInfoIndex].widget->setStyleSheet(HIGHLIGHT_STYLE);
}
