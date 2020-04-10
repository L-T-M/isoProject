#ifndef CHOOSEKERNEL_H
#define CHOOSEKERNEL_H

#include <QWidget>
#include <DLabel>
#include <DFontSizeManager>
#include <dfilechooseredit.h>
#include <DPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

DWIDGET_USE_NAMESPACE

class choosekernel : public QWidget
{
    Q_OBJECT
public:
    explicit choosekernel(QWidget *parent = nullptr);
    ~choosekernel();
signals:
    void signalcheckButtonEnable();
    void clikedNext();
public slots:
    void clikedButton();
    void changedIsAret();
    void slotCheckButtonEnable();
    void storageKernalPath();
    void storageInitrdPath();
private:
    DLabel *m_pTopLabel;
    DLabel *m_pKernalLabel;
    DLabel *m_pInitrdLabel;
    DFileChooserEdit *m_pFileChooseEditKernel;
    DFileChooserEdit *m_pFileChooseEditInitrd;
    DPushButton *m_pPushButton;
    QString kernalPath;
    QString initrdPath;
};

#endif // CHOOSEKERNEL_H
