#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <DApplication>
#include <DMainWindow>
#include <QWidget>
#include <DTitlebar>
#include <DStackedWidget>
#include <DListView>
#include <DGroupBox>
#include <DListWidget>
#include <QString>
#include <QDir>
#include <DMenu>
#include <QHash>

#include <DStandardPaths>
#include <QHBoxLayout>

#include "chooseiso.h"
#include "choosearchitecture.h"
#include "programsettings.h"
#include "previouspreparation.h"
#include "mediuminstall.h"
#include "laterclear.h"
#include "choosekernel.h"
#include "prepareoutput.h"

DWIDGET_USE_NAMESPACE

class MainWindow : public DMainWindow
{
public:
    MainWindow(DMainWindow *parent = nullptr);
    ~MainWindow();

private:
    DGroupBox *m_pGroupbox;
    QStandardItemModel *pItemModel;
    DListWidget *m_pListWidget;
    QWidget *m_pCentralWidget;
    QHash<QString, QWidget*> m_has_ItemName_ItemWiget;
    ChooseISO *m_pChooseISO;
    chooseArchitecture *m_pChooseArchitecture;
    programSettings *m_pProgramSettings;
    previousPreparation *m_pPreviousPreparation;
    mediumInstall *m_pMediumIstall;
    laterClear *m_pLaterClear;
    choosekernel *m_pChooseKernel;
    prepareOutput *m_pPrepareOutput;
    DListView *m_pDlistView;
    DStackedWidget *m_pStackWidget;
    QHBoxLayout *m_pHBoxLayout;
    QString m_strConfDir;
    QString m_strConfPath;

public slots:
    void listViewItemClikedSlots(const QModelIndex &index);
    void signalClikedNextSlots();
private:
    void settingsInit();
};

#endif // MAINWINDOW_H
