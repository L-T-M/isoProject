#include <DApplication>
#include <DWidgetUtil>
#include <DApplicationSettings>
#include <DAboutDialog>
#include "mainwindow.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
    DApplication a(argc, argv);
    a.setOrganizationName("deepin");
    a.setApplicationName("ISO定制工具");
    a.setApplicationVersion("1.0.4");
    a.setProductIcon(QIcon(":/images/iso定制工具-96px.svg"));
    a.setProductName("ISO定制工具");
    a.setApplicationDescription("ISO定制工具是统信提供给装机厂商的一款系统镜像定制工具");

    a.loadTranslator();
    //a.setApplicationDisplayName(QCoreApplication::translate("Main", "DTK Application"));
    a.setWindowIcon(QIcon(":/images/iso定制工具-24px.svg"));

    // 保存程序的窗口主题设置
    DApplicationSettings as;
    Q_UNUSED(as)

    MainWindow w;
    w.setFixedSize(800,600);
    w.show();

    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
