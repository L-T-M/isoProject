#ifndef CHOOSEARCHITECTURE_H
#define CHOOSEARCHITECTURE_H

#include <QWidget>
#include <DLabel>
#include <QHBoxLayout>
#include <DFontSizeManager>
#include <DPushButton>
#include <DListView>
#include <DStandardPaths>

DWIDGET_USE_NAMESPACE

class chooseArchitecture : public QWidget
{
    Q_OBJECT
public:
    explicit chooseArchitecture(QWidget *parent = nullptr);
    ~chooseArchitecture();
    bool changeAllModelItemStatus(QStandardItemModel* model);
signals:
    void clikedNext();

public slots:
    void listViewItemSlot(const QModelIndex &index);
    void clikedButton();

private:
    DLabel *m_pLabel;
    QStandardItemModel *m_pItemModel;
    DListView *m_pListView;
    DPushButton *m_pPushButton;
};

#endif // CHOOSEARCHITECTURE_H
