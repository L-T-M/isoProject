#include "mainwindow.h"
#include <QString>
#include <DTabBar>
#include <QStatusBar>

MainWindow::MainWindow(DMainWindow *parent)
    : DMainWindow (parent)
    , pItemModel (new QStandardItemModel)
    , m_pGroupbox (new DGroupBox)
    , m_pListWidget (new DListWidget)
    , m_pDlistView (new DListView)
    , m_pStackWidget (new DStackedWidget)
    , m_pChooseISO (new ChooseISO)
    , m_pChooseArchitecture (new chooseArchitecture)
    , m_pProgramSettings (new programSettings)
    , m_pPreviousPreparation (new previousPreparation)
    , m_pMediumIstall (new mediumInstall)
    , m_pLaterClear (new laterClear)
    , m_pChooseKernel (new choosekernel)
    , m_pPrepareOutput (new prepareOutput)
    , m_pCentralWidget (new QWidget)
{
    QVBoxLayout * MainLayout = new QVBoxLayout;
    settingsInit();
    titlebar()->setIcon(QIcon::fromTheme("iso定制工具-16px",QIcon(":/images/iso定制工具-24px.svg")));
    const QString str = "ISO定制工具";
    titlebar()->setTitle(str);
    this->statusBar()->setSizeGripEnabled(true);

    DWidget *pListView = new DWidget;
    //DWidget *pStackWidget = new DWidget;

    pListView->setStyleSheet("QWidget{background-color:White;border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px;}");
    m_pStackWidget->setStyleSheet("QStackedWidget{background-color:White;border-top-left-radius:10px;border-top-right-radius:10px;border-bottom-left-radius:10px;border-bottom-right-radius:10px;}");

    QVBoxLayout *pVLayoutListView = new QVBoxLayout;
    pVLayoutListView->addSpacing(16);
    pVLayoutListView->addWidget(m_pDlistView);
    pListView->setLayout(pVLayoutListView);

    /*QPalette pal(m_pStackWidget->palette());
    pal.setColor(QPalette::Background, Qt::white); //设置背景白色
    m_pStackWidget->setAutoFillBackground(true);
    m_pStackWidget->setPalette(pal);*/

    /*QVBoxLayout *pVLayoutStackWideget = new QVBoxLayout;
    pVLayoutStackWideget->addSpacing(16);
    pVLayoutStackWideget->addWidget(m_pStackWidget);
    pStackWidget->setLayout(pVLayoutStackWideget);*/

    m_pHBoxLayout = new QHBoxLayout;
    m_pHBoxLayout->addWidget(pListView,3);
    m_pHBoxLayout->addWidget(m_pStackWidget,8);
    MainLayout->addLayout(m_pHBoxLayout);

    /*QPalette pal(m_pDlistView->palette());
    pal.setColor(QPalette::Background, Qt::white);
    m_pDlistView->setAutoFillBackground(true);
    m_pDlistView->setPalette(pal);*/

    QStandardItem *pItemChooseISO = new QStandardItem(tr("选择ISO"));
    pItemChooseISO->setIcon(QIcon(":/images/NO_inactive1.svg"));
    m_pStackWidget->addWidget(m_pChooseISO);
    m_has_ItemName_ItemWiget.insert("选择ISO",m_pChooseISO);
    pItemModel->appendRow(pItemChooseISO);

    QStandardItem *pItemChooseArchitecture = new QStandardItem("选择架构");
    pItemChooseArchitecture->setIcon(QIcon(":/images/NO_inactive2.svg"));
    pItemChooseArchitecture->setEnabled(false);
    m_pStackWidget->addWidget(m_pChooseArchitecture);
    m_has_ItemName_ItemWiget.insert("选择架构",m_pChooseArchitecture);
    pItemModel->appendRow(pItemChooseArchitecture);

    QStandardItem *pItemProgramSettings = new QStandardItem("程序配置");
    pItemProgramSettings->setIcon(QIcon(":/images/NO_inactive3.svg"));
    pItemProgramSettings->setEnabled(false);
    m_pStackWidget->addWidget(m_pProgramSettings);
    m_has_ItemName_ItemWiget.insert("程序配置",m_pProgramSettings);
    pItemModel->appendRow(pItemProgramSettings);

    QStandardItem *pItemPreviousPreparation = new QStandardItem("前期准备");
    pItemPreviousPreparation->setIcon(QIcon(":/images/NO_inactive4.svg"));
    pItemPreviousPreparation->setEnabled(false);
    m_pStackWidget->addWidget(m_pPreviousPreparation);
    m_has_ItemName_ItemWiget.insert("前期准备",m_pPreviousPreparation);
    pItemModel->appendRow(pItemPreviousPreparation);

    QStandardItem *pItemMediumInstall = new QStandardItem("中期安装");
    pItemMediumInstall->setIcon(QIcon(":/images/NO_inactive5.svg"));
    pItemMediumInstall->setEnabled(false);
    m_pStackWidget->addWidget(m_pMediumIstall);
    m_has_ItemName_ItemWiget.insert("中期安装",m_pMediumIstall);
    pItemModel->appendRow(pItemMediumInstall);

    QStandardItem *pItemLaterClear = new QStandardItem("后期清理");
    pItemLaterClear->setIcon(QIcon(":/images/NO_inactive6.svg"));
    pItemLaterClear->setEnabled(false);
    m_pStackWidget->addWidget(m_pLaterClear);
    m_has_ItemName_ItemWiget.insert("后期清理",m_pLaterClear);
    pItemModel->appendRow(pItemLaterClear);

    QStandardItem *pItemChooseKernel = new QStandardItem("选择Kernel");
    pItemChooseKernel->setIcon(QIcon(":/images/NO_inactive7.svg"));
    pItemChooseKernel->setEnabled(false);
    m_pStackWidget->addWidget(m_pChooseKernel);
    m_has_ItemName_ItemWiget.insert("选择Kernel",m_pChooseKernel);
    pItemModel->appendRow(pItemChooseKernel);

    QStandardItem *pItemPrepareOutput = new QStandardItem("输出");
    pItemPrepareOutput->setIcon(QIcon(":/images/NO_inactive8.svg"));
    pItemPrepareOutput->setEnabled(false);
    m_pStackWidget->addWidget(m_pPrepareOutput);
    m_has_ItemName_ItemWiget.insert("输出",m_pPrepareOutput);
    pItemModel->appendRow(pItemPrepareOutput);

    m_pDlistView->setModel(pItemModel);
    m_pDlistView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QModelIndex index = pItemModel->index(0,0);
    m_pDlistView->setCurrentIndex(index);
    m_pStackWidget->setCurrentWidget(m_pChooseISO);
    connect(m_pDlistView,&DListView::clicked,this,&MainWindow::listViewItemClikedSlots,Qt::QueuedConnection);
    m_pCentralWidget->setLayout(MainLayout);


    connect(m_pChooseISO,&ChooseISO::clikedNext,this,&MainWindow::signalClikedNextSlots,Qt::QueuedConnection);
    connect(m_pChooseArchitecture,&chooseArchitecture::clikedNext,this,&MainWindow::signalClikedNextSlots,Qt::QueuedConnection);
    connect(m_pProgramSettings,&programSettings::clikedNext,this,&MainWindow::signalClikedNextSlots,Qt::QueuedConnection);
    connect(m_pPreviousPreparation,&previousPreparation::clikedNext,this,&MainWindow::signalClikedNextSlots,Qt::QueuedConnection);
    connect(m_pChooseKernel,&choosekernel::clikedNext,this,&MainWindow::signalClikedNextSlots,Qt::QueuedConnection);
    connect(m_pLaterClear,&laterClear::clikedNext,this,&MainWindow::signalClikedNextSlots,Qt::QueuedConnection);
    connect(m_pMediumIstall,&mediumInstall::clikedNext,this,&MainWindow::signalClikedNextSlots,Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{

}

void MainWindow::listViewItemClikedSlots(const QModelIndex &index)
{
    int i = index.row();
    if (i == 0 ){
        QString strItemName = index.data().toString();
        m_pStackWidget->setCurrentWidget(m_has_ItemName_ItemWiget.value(strItemName));
    }else {
        i--;
        QModelIndex lastindex = m_pDlistView->model()->index(i,0);
        QStandardItem *lastitem = pItemModel->itemFromIndex(lastindex);
        if (lastitem->checkState()){
            QString strItemName = index.data().toString();
            m_pStackWidget->setCurrentWidget(m_has_ItemName_ItemWiget.value(strItemName));
        }
    }
}

void MainWindow::signalClikedNextSlots()
{
    int i = m_pDlistView->currentIndex().row();
    QModelIndex lastindex = m_pDlistView->model()->index(i,0);
    QStandardItem *lastitem =  pItemModel->itemFromIndex(lastindex);
    if (!lastitem->checkState()){
        lastitem->setCheckState(Qt::Checked);
    }

    i++;
    QModelIndex indexFromList = m_pDlistView->model()->index(i,0);
    QStandardItem *item =  pItemModel->itemFromIndex(indexFromList);
    item->setEnabled(true);
    m_pDlistView->setCurrentIndex(indexFromList);
    m_pDlistView->clicked(indexFromList);
}

void MainWindow::settingsInit()
{
    m_strConfDir =DStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    m_strConfPath = m_strConfDir + QDir::separator() + "iso-customizer";
}
