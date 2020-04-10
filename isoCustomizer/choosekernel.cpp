#include "choosekernel.h"

choosekernel::choosekernel(QWidget *parent)
    : QWidget (parent)
    ,m_pTopLabel (new DLabel)
    ,m_pKernalLabel (new DLabel)
    ,m_pInitrdLabel (new DLabel)
    ,m_pFileChooseEditKernel (new DFileChooserEdit)
    ,m_pFileChooseEditInitrd (new DFileChooserEdit)
    ,m_pPushButton (new DPushButton(tr("下一步")))
{
    QVBoxLayout *MainLayout = new QVBoxLayout(this);
    MainLayout->addSpacing(20);
    m_pTopLabel->setText("选择Kernel");
    QFont font;
    font.setBold(true);
    m_pTopLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pTopLabel, DFontSizeManager::T3);
    MainLayout->addWidget(m_pTopLabel);

    m_pKernalLabel->setText(tr("kernel"));
    MainLayout->addWidget(m_pKernalLabel);
    MainLayout->addWidget(m_pFileChooseEditKernel);

    m_pInitrdLabel->setText(tr("initrd"));
    MainLayout->addWidget(m_pInitrdLabel);
    QStringList filter;
    filter.append("initrd(*.lz)");
    m_pFileChooseEditInitrd->setNameFilters(filter);
    MainLayout->addWidget(m_pFileChooseEditInitrd);
    MainLayout->addStretch();

    QHBoxLayout *pHBoxLayout = new QHBoxLayout;
    pHBoxLayout->addStretch();
    m_pPushButton->setMinimumWidth(260);
    m_pPushButton->setEnabled(false);
    pHBoxLayout->addWidget(m_pPushButton);
    pHBoxLayout->addStretch();
    MainLayout->addLayout(pHBoxLayout);

    connect(m_pPushButton,&DPushButton::clicked,this,&choosekernel::clikedButton,Qt::QueuedConnection);
    connect(m_pFileChooseEditKernel,&DFileChooserEdit::fileChoosed,this,&choosekernel::storageKernalPath,Qt::QueuedConnection);
    connect(m_pFileChooseEditInitrd,&DFileChooserEdit::fileChoosed,this,&choosekernel::storageInitrdPath,Qt::QueuedConnection);
    connect(m_pFileChooseEditKernel,&DFileChooserEdit::textChanged,this,&choosekernel::changedIsAret,Qt::QueuedConnection);
    connect(m_pFileChooseEditInitrd,&DFileChooserEdit::textChanged,this,&choosekernel::changedIsAret,Qt::QueuedConnection);
    connect(this,&choosekernel::signalcheckButtonEnable,this,&choosekernel::slotCheckButtonEnable,Qt::QueuedConnection);
}

choosekernel::~choosekernel()
{

}

void choosekernel::clikedButton()
{
    emit clikedNext();
}

void choosekernel::changedIsAret()
{
    if (m_pFileChooseEditKernel->text() != kernalPath){
        m_pFileChooseEditKernel->setAlert(true);
        m_pPushButton->setEnabled(false);
    }else {
        m_pFileChooseEditKernel->setAlert(false);
    }
    if (m_pFileChooseEditInitrd->text() != initrdPath){
        m_pFileChooseEditInitrd->setAlert(true);
        m_pPushButton->setEnabled(false);
    }else {
        m_pFileChooseEditInitrd->setAlert(false);
    }
    emit signalcheckButtonEnable();
}


void choosekernel::slotCheckButtonEnable()
{
    if ((!m_pFileChooseEditKernel->isAlert()) && (m_pFileChooseEditKernel->text() != "") &&
        (!m_pFileChooseEditInitrd->isAlert()) && (m_pFileChooseEditInitrd->text() != "")){
            m_pPushButton->setEnabled(true);
    }
}

void choosekernel::storageKernalPath()
{
    kernalPath = m_pFileChooseEditKernel->text();
    m_pFileChooseEditKernel->setAlert(false);
    emit signalcheckButtonEnable();
}

void choosekernel::storageInitrdPath()
{
    initrdPath = m_pFileChooseEditInitrd->text();
    m_pFileChooseEditInitrd->setAlert(false);
    emit signalcheckButtonEnable();
}
