#ifndef PREPAREOUTPUT_H
#define PREPAREOUTPUT_H

#include <QWidget>
#include <DLabel>
#include <DWaterProgress>
#include <DPushButton>
#include <DFontSizeManager>
#include <QTimer>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

class prepareOutput : public QWidget
{
    Q_OBJECT
public:
    explicit prepareOutput(QWidget *parent = nullptr);
    ~prepareOutput();
signals:
    void successSignal();
    void fallSignal();
public slots:
    void nextButtonClikedSlot();
    void fallViewSlot();
    void successViewSlot();
    void slotTimerOut();
private:
    QVBoxLayout *MainLayout;
    DLabel *m_pTopLabel;
    DWaterProgress *m_pWaterProgress;
    DLabel *waterProgressStatus;
    DPushButton *m_pNextButton;
    DPushButton *m_pCloseButton;
    DPushButton *m_pFinishButton;
    DPushButton *m_pviewFilesButton;
    QTimer *m_ptimer;
    int m_valus = 0;

};
#endif // PREPAREOUTPUT_H
