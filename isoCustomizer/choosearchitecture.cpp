#include "choosearchitecture.h"

chooseArchitecture::chooseArchitecture(QWidget *parent)
    : QWidget(parent)
    , m_pLabel(new DLabel)
    , m_pItemModel(new QStandardItemModel)
    , m_pListView(new DListView)
    , m_pPushButton(new DPushButton(tr("下一步")))
{
    QHBoxLayout *p_MainLayout = new QHBoxLayout(this);
    QVBoxLayout *pVBoxLayout = new QVBoxLayout;
    pVBoxLayout->addSpacing(20);

    m_pLabel->setText("选择架构");
    QFont font;
    font.setBold(true);
    m_pLabel->setFont(font);
    DFontSizeManager::instance()->bind(m_pLabel, DFontSizeManager::T3);
    pVBoxLayout->addWidget(m_pLabel);

    QStandardItem *pItemARM = new QStandardItem("RAM");
    pItemARM->setFlags(Qt::ItemIsEnabled);
    m_pItemModel->appendRow(pItemARM);

    QStandardItem *pItemX86 = new QStandardItem("X86");
    pItemX86->setFlags(Qt::ItemIsEnabled);
    m_pItemModel->appendRow(pItemX86);

    QStandardItem *pItemMIPS = new QStandardItem("MIPS");
    pItemMIPS->setFlags(Qt::ItemIsEnabled);
    m_pItemModel->appendRow(pItemMIPS);

    m_pListView->setModel(m_pItemModel);
    connect(m_pListView,&DListView::clicked,this,&chooseArchitecture::listViewItemSlot,Qt::QueuedConnection);

    pVBoxLayout->addSpacing(15);
    pVBoxLayout->addWidget(m_pListView);
    pVBoxLayout->addStretch();

    QHBoxLayout *pHboxLayout = new QHBoxLayout;
    pHboxLayout->addStretch();
    m_pPushButton->setMinimumWidth(260);
    m_pPushButton->setEnabled(false);
    pHboxLayout->addWidget(m_pPushButton);
    pHboxLayout->addStretch();
    pVBoxLayout->addLayout(pHboxLayout);

    p_MainLayout->addLayout(pVBoxLayout);
    connect(m_pPushButton,&DPushButton::clicked,this,&chooseArchitecture::clikedButton,Qt::QueuedConnection);
}

chooseArchitecture::~chooseArchitecture()
{

}

bool chooseArchitecture::changeAllModelItemStatus(QStandardItemModel *model)
{
    int rows = model->rowCount();
    int column = model->columnCount();
    for (int i = 0; i<rows; ++i){
        for (int j = 0; j<column; ++j){
            QStandardItem* item = model->item(i,j);
            item->setCheckState(Qt::Unchecked);
        }
    }
    return true;
}

void chooseArchitecture::listViewItemSlot(const QModelIndex &index)
{
    changeAllModelItemStatus(m_pItemModel);
    QStandardItem *curItem = m_pItemModel->itemFromIndex(index);
    curItem->setCheckState(Qt::Checked);
    m_pPushButton->setEnabled(true);
}

void chooseArchitecture::clikedButton()
{
    emit clikedNext();
}
