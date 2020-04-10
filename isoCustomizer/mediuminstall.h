#ifndef MEDIUMINSTALL_H
#define MEDIUMINSTALL_H

#include <QWidget>
#include <DLabel>
#include <DListView>
#include <DPushButton>
#include <DCommandLinkButton>
#include <DFontSizeManager>
#include <DStandardPaths>
#include <DFileDialog>
#include <QFileInfo>
#include <QFileIconProvider>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

class mediumInstall : public QWidget
{
    Q_OBJECT
public:
    explicit mediumInstall(QWidget *parent = nullptr);
    ~mediumInstall();
signals:
    void clikedNext();
public slots:
    void chooseButtonSlots();
    void eraseButtonSlots();
    void clikedButton();
private:
    DLabel *m_pTopLabel;
    DLabel *m_pCentralLabel;
    DListView *m_pListView;
    QStandardItemModel *m_pStandardItemModel;
    DCommandLinkButton *m_pCommandEraseButton;
    DCommandLinkButton *m_pCommandChooseButton;
    DPushButton *m_pButton;
    QVBoxLayout *MainLayout;
};

#endif // MEDIUMINSTALL_H
