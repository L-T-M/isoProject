#ifndef PROGRAMSETTINGS_H
#define PROGRAMSETTINGS_H

#include <QWidget>
#include <QIcon>
#include <DLabel>
#include <DListView>
#include <DPushButton>
#include <DCommandLinkButton>
#include <DIconButton>
#include <DFontSizeManager>
#include <DStandardPaths>
#include <DFileDialog>
#include <QFileInfo>
#include <QFileIconProvider>
#include <QHBoxLayout>

DWIDGET_USE_NAMESPACE

class DListViewMouse;

class programSettings : public QWidget
{
    Q_OBJECT
public:
    explicit programSettings(QWidget *parent = nullptr);
    ~programSettings();
signals:
    void clikedNext();
public slots:
    void chooseButtonSlots();
    void eraseButtonSlots();
    void clikedButton();
private:
    DLabel *m_pTopLabel;
    DLabel *m_pCentralLabel;
    DListViewMouse *m_pListView;
    QStandardItemModel *m_pStandardItemModel;
    DCommandLinkButton *m_pCommandEraseButton;
    DCommandLinkButton *m_pCommandChooseButton;
    DPushButton *m_pButton;
    DIconButton *clearButton;
    QVBoxLayout *MainLayout;
};

class DListViewMouse : public DListView
{
    Q_OBJECT
public:
    explicit DListViewMouse(QWidget *parent = nullptr);

private:
    virtual void currentChanged(const QModelIndex &current, const QModelIndex &previous) override;
    virtual void mouseMoveEvent(QMouseEvent *e) override;
//    virtual void mousemove(QMouseEvent *e) ;

signals:
    void currentChange(const QModelIndex &current, const QModelIndex &previous);
    void indexfoucs(QMouseEvent *e);

};

#endif // PROGRAMSETTINGS_H
