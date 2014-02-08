/********************************************************************************
** Form generated from reading UI file 'desktopsearch.ui'
**
** Created: Thu Oct 11 15:47:03 2012
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DESKTOPSEARCH_H
#define UI_DESKTOPSEARCH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DesktopSearchClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QListView *listView;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *DesktopSearchClass)
    {
        if (DesktopSearchClass->objectName().isEmpty())
            DesktopSearchClass->setObjectName(QString::fromUtf8("DesktopSearchClass"));
        DesktopSearchClass->resize(1115, 772);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/DesktopSearch/Design/Plane.png"), QSize(), QIcon::Normal, QIcon::Off);
        DesktopSearchClass->setWindowIcon(icon);
        DesktopSearchClass->setAnimated(false);
        centralWidget = new QWidget(DesktopSearchClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("#centralWidget\n"
"{\n"
"	background-image: url(:/DesktopSearch/Design/mainBack.png);\n"
"	background-repeat:no-repeat;\n"
"}"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(46, 45, 971, 33));
        lineEdit->setStyleSheet(QString::fromUtf8("#lineEdit {\n"
"	background-image: url(:/DesktopSearch/Design/SearchBarBack.png);\n"
"	border:0px;\n"
"	background-repeat:no-repeat;\n"
"	background-color:transparent;\n"
"	padding:2px 26px 0px;\n"
"}\n"
"#lineEdit:focus {\n"
"    	background-image: url(:/DesktopSearch/Design/SearchBarBack.png);\n"
"}\n"
"\n"
"#lineEdit:edit-focus {\n"
"    \n"
"}\n"
""));
        lineEdit->setCursorMoveStyle(Qt::LogicalMoveStyle);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(923, 48, 92, 28));
        pushButton->setStyleSheet(QString::fromUtf8("#pushButton\n"
"{\n"
"	background-image: url(:/DesktopSearch/Design/SearchBtn.png);\n"
"	background-repeat:no-repeat;\n"
"}"));
        pushButton->setFlat(true);
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(28, 111, 1004, 533));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(8);
        font.setBold(false);
        font.setWeight(50);
        tableWidget->setFont(font);
        tableWidget->setAutoFillBackground(true);
        tableWidget->setStyleSheet(QString::fromUtf8("#tableWidget\n"
"{\n"
"	background:transparent;\n"
"}\n"
"QHeaderView::section\n"
"{\n"
"	background:#e5e5e5;\n"
"	border: 0px;\n"
"	border-right: 1px solid grey;\n"
"	height:26px\n"
"}\n"
"QTableWidget::item\n"
"{\n"
"	text-align: left;\n"
"}\n"
"QTableWidget::item:selected {\n"
"	background-image: url(:/DesktopSearch/Resources/tableSelectRowBackground.png);\n"
"	background-repeat: repeat-x;\n"
"	background-position: top;\n"
"	border:0px dashed #bbb;\n"
"	background-color: #458bff;\n"
"}"));
        tableWidget->setFrameShape(QFrame::NoFrame);
        tableWidget->setFrameShadow(QFrame::Plain);
        tableWidget->setLineWidth(0);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(true);
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setProperty("showDropIndicator", QVariant(false));
        tableWidget->setDragDropOverwriteMode(false);
        tableWidget->setAlternatingRowColors(true);
        tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidget->setShowGrid(false);
        tableWidget->setGridStyle(Qt::DotLine);
        tableWidget->setSortingEnabled(false);
        tableWidget->setWordWrap(false);
        tableWidget->setCornerButtonEnabled(false);
        tableWidget->horizontalHeader()->setCascadingSectionResizes(true);
        tableWidget->horizontalHeader()->setHighlightSections(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        tableWidget->verticalHeader()->setVisible(false);
        tableWidget->verticalHeader()->setHighlightSections(false);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(980, 645, 51, 21));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(930, 645, 41, 21));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        listView->setGeometry(QRect(50, 74, 964, 191));
        listView->setAutoFillBackground(true);
        listView->setStyleSheet(QString::fromUtf8("#listView{\n"
"	background-color: rgba(250, 250, 250, 200);\n"
"}"));
        listView->setFrameShape(QFrame::StyledPanel);
        listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listView->setAlternatingRowColors(true);
        listView->setSelectionBehavior(QAbstractItemView::SelectRows);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1010, 20, 16, 16));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        pushButton_2->setAutoDefault(false);
        pushButton_2->setDefault(false);
        pushButton_2->setFlat(true);
        DesktopSearchClass->setCentralWidget(centralWidget);

        retranslateUi(DesktopSearchClass);
        QObject::connect(pushButton, SIGNAL(clicked()), DesktopSearchClass, SLOT(OnSearchBtnClicked()));
        QObject::connect(lineEdit, SIGNAL(returnPressed()), DesktopSearchClass, SLOT(OnSearchBtnClicked()));
        QObject::connect(lineEdit, SIGNAL(textChanged(QString)), DesktopSearchClass, SLOT(OnEdit(QString)));
        QObject::connect(tableWidget, SIGNAL(cellDoubleClicked(int,int)), DesktopSearchClass, SLOT(OnItemDoubleClicked(int,int)));
        QObject::connect(listView, SIGNAL(doubleClicked(QModelIndex)), DesktopSearchClass, SLOT(OnHistoryItemDoubleClicked(QModelIndex)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), DesktopSearchClass, SLOT(close()));

        QMetaObject::connectSlotsByName(DesktopSearchClass);
    } // setupUi

    void retranslateUi(QMainWindow *DesktopSearchClass)
    {
        DesktopSearchClass->setWindowTitle(QApplication::translate("DesktopSearchClass", "DesktopSearch", 0, QApplication::UnicodeUTF8));
        lineEdit->setPlaceholderText(QApplication::translate("DesktopSearchClass", "What you want here...", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QString());
        label->setText(QApplication::translate("DesktopSearchClass", "Results", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DesktopSearchClass", "0", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("DesktopSearchClass", "x", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DesktopSearchClass: public Ui_DesktopSearchClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DESKTOPSEARCH_H
