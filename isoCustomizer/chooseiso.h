#ifndef SELECTISO_H
#define SELECTISO_H

#include <QWidget>
#include <DLabel>
#include <QFont>
#include <DLineEdit>
#include <dfilechooseredit.h>
#include <QHBoxLayout>
#include <DPushButton>
#include <DFontSizeManager>

DWIDGET_USE_NAMESPACE

class ChooseISO : public QWidget
{
    Q_OBJECT
public:
    explicit ChooseISO(QWidget *parent = nullptr);
    ~ChooseISO();

signals:
    void clikedNext();

public slots:
    void clikedButton();
    void finishChooseFile();
private:
    DLabel *m_pLabel;
    DFileChooserEdit *m_pFileChooseEdit;
    DPushButton *m_pButton;
};
#endif // SELECTISO_H
