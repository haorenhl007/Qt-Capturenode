/********************************************************************************
** Form generated from reading UI file 'hismainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISMAINWIN_H
#define UI_HISMAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HisMainWin
{
public:
    QWidget *centralwidget;
    QTableView *tableView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *btnOpen;
    QPushButton *btnClear_his;
    QPushButton *btnPrint_his;
    QPushButton *btnCurve_his;
    QPushButton *btnReturn_his;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HisMainWin)
    {
        if (HisMainWin->objectName().isEmpty())
            HisMainWin->setObjectName(QStringLiteral("HisMainWin"));
        HisMainWin->resize(820, 460);
        centralwidget = new QWidget(HisMainWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(9, 9, 751, 401));
        QFont font;
        font.setFamily(QStringLiteral("Consolas"));
        tableView->setFont(font);
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(765, 9, 46, 401));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        btnOpen = new QPushButton(widget);
        btnOpen->setObjectName(QStringLiteral("btnOpen"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnOpen->sizePolicy().hasHeightForWidth());
        btnOpen->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/open.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnOpen->setIcon(icon);
        btnOpen->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnOpen);

        btnClear_his = new QPushButton(widget);
        btnClear_his->setObjectName(QStringLiteral("btnClear_his"));
        sizePolicy.setHeightForWidth(btnClear_his->sizePolicy().hasHeightForWidth());
        btnClear_his->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/broom.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnClear_his->setIcon(icon1);
        btnClear_his->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnClear_his);

        btnPrint_his = new QPushButton(widget);
        btnPrint_his->setObjectName(QStringLiteral("btnPrint_his"));
        sizePolicy.setHeightForWidth(btnPrint_his->sizePolicy().hasHeightForWidth());
        btnPrint_his->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/excel.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnPrint_his->setIcon(icon2);
        btnPrint_his->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnPrint_his);

        btnCurve_his = new QPushButton(widget);
        btnCurve_his->setObjectName(QStringLiteral("btnCurve_his"));
        sizePolicy.setHeightForWidth(btnCurve_his->sizePolicy().hasHeightForWidth());
        btnCurve_his->setSizePolicy(sizePolicy);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/help.ico"), QSize(), QIcon::Normal, QIcon::Off);
        btnCurve_his->setIcon(icon3);
        btnCurve_his->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnCurve_his);

        btnReturn_his = new QPushButton(widget);
        btnReturn_his->setObjectName(QStringLiteral("btnReturn_his"));
        sizePolicy.setHeightForWidth(btnReturn_his->sizePolicy().hasHeightForWidth());
        btnReturn_his->setSizePolicy(sizePolicy);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/return.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnReturn_his->setIcon(icon4);
        btnReturn_his->setIconSize(QSize(32, 32));

        verticalLayout->addWidget(btnReturn_his);

        HisMainWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HisMainWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 23));
        HisMainWin->setMenuBar(menubar);
        statusbar = new QStatusBar(HisMainWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        HisMainWin->setStatusBar(statusbar);

        retranslateUi(HisMainWin);

        QMetaObject::connectSlotsByName(HisMainWin);
    } // setupUi

    void retranslateUi(QMainWindow *HisMainWin)
    {
        HisMainWin->setWindowTitle(QApplication::translate("HisMainWin", "MainWindow", 0));
        btnOpen->setText(QString());
        btnClear_his->setText(QString());
        btnPrint_his->setText(QString());
        btnCurve_his->setText(QString());
        btnReturn_his->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HisMainWin: public Ui_HisMainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISMAINWIN_H
