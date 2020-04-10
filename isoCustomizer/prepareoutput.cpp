#include "prepareoutput.h"

prepareOutput::prepareOutput(QWidget *parent)
    : QWidget (parent)
    , MainLayout (new QVBoxLayout(this))
    , m_pTopLabel (new DLabel)
    , m_pWaterProgress (new DWaterProgress)
    , waterProgressStatus (new DLabel)
    , m_pNextButton (new DPushButton(tr("下一步")))
    , m_pFinishButton (new DPushButton(tr("完成")))
    , m_pviewFilesButton (new DPushButton(tr("打开文件")))
{
    m_ptimer = new QTimer();
    m_ptimer->setInterval(100);
    MainLayout->addSpacing(20);
    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout;
    pHBoxLayout1->addStretch();

    m_pTopLabel->setText("准备输出");
    QFont font;
    font.setBold(true);
    m_pTopLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pTopLabel, DFontSizeManager::T3);
    pHBoxLayout1->addWidget(m_pTopLabel);
    pHBoxLayout1->addStretch();
    MainLayout->addLayout(pHBoxLayout1);
    MainLayout->addStretch();

    QHBoxLayout *pHBoxLayout2 = new QHBoxLayout;
    pHBoxLayout2->addStretch();
    m_pWaterProgress->setValue(m_valus);
    pHBoxLayout2->addWidget(m_pWaterProgress);
    pHBoxLayout2->addStretch();
    MainLayout->addLayout(pHBoxLayout2);

    QHBoxLayout *pHBoxLayout3 = new QHBoxLayout;
    pHBoxLayout3->addStretch();
    pHBoxLayout3->addWidget(waterProgressStatus);
    pHBoxLayout3->addStretch();
    MainLayout->addLayout(pHBoxLayout3);
    MainLayout->addStretch();

    QHBoxLayout *pHBoxLayout4 = new QHBoxLayout;
    pHBoxLayout4->addStretch();
    m_pNextButton->setMinimumWidth(260);
    pHBoxLayout4->addWidget(m_pNextButton);
    pHBoxLayout4->addStretch();
    MainLayout->addLayout(pHBoxLayout4);
    MainLayout->addSpacing(20);

    connect(m_pNextButton,&DPushButton::clicked,this,&prepareOutput::nextButtonClikedSlot);
    connect(m_ptimer, &QTimer::timeout, this, &prepareOutput::slotTimerOut);
    connect(this,&prepareOutput::successSignal,this,&prepareOutput::successViewSlot);
    connect(this,&prepareOutput::fallSignal,this,&prepareOutput::fallViewSlot);
}

prepareOutput::~prepareOutput()
{

}

void prepareOutput::successViewSlot()
{
    QHBoxLayout *pHBoxLayout = new QHBoxLayout;
    pHBoxLayout->addSpacing(220);
    QPushButton *pButton = new DPushButton;
    pButton->setStyleSheet("QPushButton{border-image: url(:/images/progress.svg);}");
    pButton->setFixedSize(120,120);
    pHBoxLayout->addWidget(pButton);
    pHBoxLayout->addStretch();

    QHBoxLayout *pHBoxLayout1 = new QHBoxLayout;
    pHBoxLayout->addStretch();
    m_pFinishButton->setMinimumWidth(260);
    pHBoxLayout1->addWidget(m_pFinishButton);
    pHBoxLayout1->addSpacing(10);
    m_pviewFilesButton->setMinimumWidth(260);
    pHBoxLayout1->addWidget(m_pviewFilesButton);
    pHBoxLayout->addStretch();

    m_pTopLabel->setText("输出成功");
    waterProgressStatus->setText("制作成功");
    m_pWaterProgress->hide();
    m_pNextButton->setHidden(true);
    MainLayout->insertLayout(3,pHBoxLayout);
    MainLayout->insertLayout(7,pHBoxLayout1);
}

void prepareOutput::fallViewSlot()
{

}

void prepareOutput::nextButtonClikedSlot()
{
    m_pTopLabel->setText("正在输出");
    m_pNextButton->setEnabled(false);
    m_ptimer->start();
    waterProgressStatus->setText("正在制作，请稍后...");
    m_pWaterProgress->start();
}

void prepareOutput::slotTimerOut()
{
    if (m_valus < 100){
        m_valus += 1;
        m_pWaterProgress->setValue(m_valus);
        update();
    }else {
        m_ptimer->stop();
        m_pWaterProgress->stop();
        emit successSignal();
    }
}
