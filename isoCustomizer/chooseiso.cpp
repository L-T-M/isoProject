#include "chooseiso.h"

ChooseISO::ChooseISO(QWidget *parent)
    : QWidget (parent)
    , m_pLabel (new DLabel)
    , m_pFileChooseEdit (new DFileChooserEdit)
    , m_pButton(new DPushButton)
{
    QVBoxLayout *p_MainLayout = new QVBoxLayout(this);
    p_MainLayout->addSpacing(20);

    m_pLabel->setText("选择ISO");
    QFont font;
    font.setBold(true);
    m_pLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pLabel, DFontSizeManager::T3);
    p_MainLayout->addWidget(m_pLabel);
    p_MainLayout->setSpacing(10);

    QStringList strList;
    strList.append("*.iso");
    m_pFileChooseEdit->setNameFilters(strList);
    p_MainLayout->addWidget(m_pFileChooseEdit);
    p_MainLayout->addStretch();

    QHBoxLayout *pHBoxLayout = new QHBoxLayout;
    pHBoxLayout->addSpacing(147);
    m_pButton->setText("下一步");
    /*QPalette pal = m_pButton->palette();
    pal.setColor(QPalette::Background,Qt::gray);
    m_pButton->setPalette(pal);*/

    /*QPalette pal(m_pButton->palette());
    pal.setColor(QPalette::Background, Qt::gray); //设置背景黑色
    m_pButton->setAutoFillBackground(true);
    m_pButton->setPalette(pal);*/

    m_pButton->setMinimumWidth(260);
    m_pButton->setEnabled(false);
    pHBoxLayout->addWidget(m_pButton);
    pHBoxLayout->addStretch();

    connect(m_pFileChooseEdit,&DFileChooserEdit::cursorPositionChanged,this,&ChooseISO::finishChooseFile,Qt::QueuedConnection);
    connect(m_pButton,&DPushButton::clicked,this,&ChooseISO::clikedButton,Qt::QueuedConnection);

    p_MainLayout->addLayout(pHBoxLayout);

}

ChooseISO::~ChooseISO()
{

}

void ChooseISO::clikedButton()
{
    emit clikedNext();
}

void ChooseISO::finishChooseFile()
{
    m_pButton->setEnabled(true);
}
