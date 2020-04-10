#ifndef LATERCLEAR_H
#define LATERCLEAR_H

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

class laterClear : public QWidget
{
    Q_OBJECT
public:
    explicit laterClear(QWidget *parent = nullptr);
    ~laterClear();
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

#endif // LATERCLEAR_H
