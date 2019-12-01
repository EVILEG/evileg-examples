#ifndef TUTORIALDIALOG_H
#define TUTORIALDIALOG_H

#include <QDialog>

namespace Ui {
class TutorialDialog;
}

class TutorialDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TutorialDialog(QWidget *parent = nullptr);
    ~TutorialDialog();

    // add widget and text information about this widget to tutorial dialog
    void addWidgetToTutorial(QWidget* widget, const QString& text);

private:
    void onPreviousButtonClicked(); // slot which reacts on click of previous button
    void onNextButtonClicked();     // slot which reacts on click of next button
    void updateButtonsEnabled();    // update actual enabled status of buttons
    void returnOldStyle();          // return old style to widget, which was highlighted
    void setTextAndStyle();         // set text information to tutorial dialog and set highlight style to widget

    Ui::TutorialDialog *ui;

    // This structure contains text information aboout some widget
    struct TutorialInfo
    {
        QWidget* widget;
        QString text;
    };

    // highlight style
    const QString HIGHLIGHT_STYLE {"border: 1px solid red"};
    QVector<TutorialInfo> m_infoItems;      // vector of widgets in tutorial
    int m_currentTutorialInfoIndex {-1};    // index of current highlighted widget
    QString m_oldStyleOfWidget;             // old widget style
};

#endif // TUTORIALDIALOG_H
