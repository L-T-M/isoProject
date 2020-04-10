#include "laterclear.h"

laterClear::laterClear(QWidget *parent)
    : QWidget(parent)
    , m_pTopLabel(new DLabel(tr("后期清理")))
    , m_pCentralLabel(new DLabel(tr("请选择后期清理")))
    , m_pButton(new DPushButton(tr("下一步")))
    , m_pCommandEraseButton(new DCommandLinkButton(tr("全部清除")))
    , m_pCommandChooseButton(new DCommandLinkButton(tr("选择脚本")))
    , m_pListView(new DListView)
    , m_pStandardItemModel(new QStandardItemModel)
    , MainLayout(new QVBoxLayout(this))
{
    MainLayout->addSpacing(10);
    QHBoxLayout *pHboxLayout1 = new QHBoxLayout;
    m_pCommandEraseButton->setHidden(true);

    QFont font;
    font.setBold(true);
    m_pTopLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pTopLabel, DFontSizeManager::T3);
    pHboxLayout1->addStretch(1);
    pHboxLayout1->addWidget(m_pTopLabel);
    pHboxLayout1->addStretch(18);
    pHboxLayout1->addWidget(m_pCommandEraseButton);
    pHboxLayout1->addStretch(1);


    QVBoxLayout *pVboxLayout = new QVBoxLayout;
    pVboxLayout->addSpacing(10);
    QHBoxLayout *pHboxLayout2 = new QHBoxLayout;
    pHboxLayout2->addStretch();
    font.setBold(false);
    m_pCentralLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pCentralLabel, DFontSizeManager::T2);
    QPalette pe(m_pCentralLabel->palette());
    pe.setColor(QPalette::WindowText,Qt::gray);
    m_pCentralLabel->setPalette(pe);
    pVboxLayout->addWidget(m_pCentralLabel);
    pHboxLayout2->addLayout(pVboxLayout);
    pHboxLayout2->addStretch();


    QHBoxLayout *pHboxLayout3 = new QHBoxLayout;
    pHboxLayout3->addStretch();
    pHboxLayout3->addWidget(m_pCommandChooseButton);
    pHboxLayout3->addStretch();

    QHBoxLayout *pHboxLayout4 = new QHBoxLayout;
    pHboxLayout4->addStretch();
    m_pButton->setMinimumWidth(260);
    pHboxLayout4->addWidget(m_pButton);
    pHboxLayout4->addStretch();

    MainLayout->addLayout(pHboxLayout1);
    MainLayout->addStretch(5);
    MainLayout->addLayout(pHboxLayout2);
    MainLayout->addStretch(4);
    MainLayout->addLayout(pHboxLayout3);
    MainLayout->addSpacing(1);
    MainLayout->addLayout(pHboxLayout4);

    connect(m_pCommandChooseButton,&DCommandLinkButton::clicked,this,&laterClear::chooseButtonSlots,Qt::QueuedConnection);
    connect(m_pCommandEraseButton,&DCommandLinkButton::clicked,this,&laterClear::eraseButtonSlots,Qt::QueuedConnection);
    connect(m_pButton,&DPushButton::clicked,this,&laterClear::clikedButton,Qt::QueuedConnection);
}

laterClear::~laterClear()
{

}

void laterClear::chooseButtonSlots()
{
    DFileDialog *pFileDialog = new DFileDialog;
    pFileDialog->setDirectory("/home/ming");
    pFileDialog->setAcceptMode(QFileDialog::AcceptOpen);
    pFileDialog->setFileMode(QFileDialog::ExistingFiles);
    pFileDialog->setNameFilter(tr("*.job"));
    pFileDialog->show();
    pFileDialog->exec();

    QStringList fileNames = pFileDialog->selectedFiles();
    if (!fileNames.empty()){
        m_pCommandEraseButton->setHidden(false);
        for (QString strSelectFile : fileNames) {
            QFileIconProvider icon_provider;
            QIcon icon = icon_provider.icon(strSelectFile);
            QStandardItem * pStandardItem = new QStandardItem;
            pStandardItem->setIcon(icon);
            pStandardItem->setText(strSelectFile);
            m_pStandardItemModel->appendRow(pStandardItem);
            m_pListView->setModel(m_pStandardItemModel);
        }
        m_pCentralLabel->setHidden(true);
        m_pListView->setHidden(false);
        QHBoxLayout *pHboxLayout = new QHBoxLayout;
        pHboxLayout->addWidget(m_pListView);
        MainLayout->insertLayout(2,pHboxLayout);
    }
}

void laterClear::eraseButtonSlots()
{
    int rows = m_pListView->model()->rowCount();
    int column = m_pListView->model()->columnCount();
    m_pListView->model()->removeRows(0,rows);
    m_pListView->model()->removeColumns(0,column);

    m_pCommandEraseButton->setHidden(true);
    m_pListView->setHidden(true);
    m_pCentralLabel->setHidden(false);
}

void laterClear::clikedButton()
{
    emit clikedNext();
}
