/********************************************************************************
** Form generated from reading UI file 'mainframe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainFrame
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *buttonOpen;
    QToolButton *toolButton_2;
    QToolButton *toolButton_3;
    QToolButton *buttonDeleteContents;
    QSpacerItem *horizontalSpacer;
    QToolButton *buttonShowList;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QLabel *label_5;
    QSpinBox *spinHue;
    QLabel *label_6;
    QDoubleSpinBox *spinSaturation;
    QPushButton *buttonSepiaTone;
    QLabel *label_FromMax;
    QLabel *label_FromMin;
    QSpinBox *spinFromMin;
    QPushButton *buttonContrast;
    QSpinBox *spinFromMax;
    QSpinBox *spinToMin;
    QLabel *label_ToMin;
    QLabel *label_ToMax;
    QSpinBox *spinToMax;
    QWidget *tab_3;
    QPushButton *buttonOtsuBetween;
    QPushButton *buttonLabeling;
    QPushButton *buttonHistoEqualization;
    QPushButton *buttonHistoMatching;
    QWidget *tab_4;
    QPushButton *buttonGenerateNoise;
    QPushButton *buttonGaussianFilter;
    QPushButton *buttonMedianFilter;
    QSpinBox *spinSigma;
    QLabel *label_Sigma;
    QLabel *label_Mean;
    QSpinBox *spinMean;
    QLabel *label_SaltPepperPercent;
    QSpinBox *spinPercent;
    QLabel *label_kernelsize;
    QSpinBox *spinKernelSize;
    QLabel *label_GaussianFIlterSigma;
    QDoubleSpinBox *spinGaussianFIlterSigma;
    QPushButton *buttonFastGaussianFilter;
    QPushButton *buttonCanny;
    QLabel *label_LowThreshold;
    QSpinBox *spinLowThreshold;
    QLabel *label_HighThreshold;
    QSpinBox *spinHighThreshold;
    QWidget *tab;
    QPushButton *buttonHoughCircle;
    QLabel *label_CircleRadius;
    QSpinBox *spinCircleRadius;
    QPushButton *buttonReadModel;
    QPushButton *buttonGeneralizedHough;
    QListWidget *listWidget;

    void setupUi(QDialog *MainFrame)
    {
        if (MainFrame->objectName().isEmpty())
            MainFrame->setObjectName(QString::fromUtf8("MainFrame"));
        MainFrame->resize(622, 461);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainFrame->sizePolicy().hasHeightForWidth());
        MainFrame->setSizePolicy(sizePolicy);
        MainFrame->setMinimumSize(QSize(0, 461));
        MainFrame->setModal(false);
        verticalLayout = new QVBoxLayout(MainFrame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        frame = new QFrame(MainFrame);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(0, 41));
        frame->setMaximumSize(QSize(16777215, 41));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        buttonOpen = new QToolButton(frame);
        buttonOpen->setObjectName(QString::fromUtf8("buttonOpen"));
        buttonOpen->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonOpen->sizePolicy().hasHeightForWidth());
        buttonOpen->setSizePolicy(sizePolicy2);
        buttonOpen->setMinimumSize(QSize(41, 41));
        buttonOpen->setMaximumSize(QSize(41, 41));
        buttonOpen->setLayoutDirection(Qt::LeftToRight);
        buttonOpen->setAutoFillBackground(false);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonOpen->setIcon(icon);
        buttonOpen->setIconSize(QSize(41, 41));
        buttonOpen->setCheckable(false);
        buttonOpen->setAutoRepeat(false);
        buttonOpen->setAutoExclusive(false);
        buttonOpen->setPopupMode(QToolButton::DelayedPopup);
        buttonOpen->setToolButtonStyle(Qt::ToolButtonIconOnly);
        buttonOpen->setAutoRaise(false);

        horizontalLayout_3->addWidget(buttonOpen);

        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        toolButton_2->setMinimumSize(QSize(41, 41));
        toolButton_2->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_2);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        sizePolicy2.setHeightForWidth(toolButton_3->sizePolicy().hasHeightForWidth());
        toolButton_3->setSizePolicy(sizePolicy2);
        toolButton_3->setMinimumSize(QSize(41, 41));
        toolButton_3->setMaximumSize(QSize(41, 41));

        horizontalLayout_3->addWidget(toolButton_3);

        buttonDeleteContents = new QToolButton(frame);
        buttonDeleteContents->setObjectName(QString::fromUtf8("buttonDeleteContents"));
        sizePolicy2.setHeightForWidth(buttonDeleteContents->sizePolicy().hasHeightForWidth());
        buttonDeleteContents->setSizePolicy(sizePolicy2);
        buttonDeleteContents->setMinimumSize(QSize(41, 41));
        buttonDeleteContents->setMaximumSize(QSize(41, 41));
        buttonDeleteContents->setAutoFillBackground(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/1-21.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDeleteContents->setIcon(icon1);
        buttonDeleteContents->setIconSize(QSize(41, 41));

        horizontalLayout_3->addWidget(buttonDeleteContents);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonShowList = new QToolButton(frame);
        buttonShowList->setObjectName(QString::fromUtf8("buttonShowList"));
        sizePolicy2.setHeightForWidth(buttonShowList->sizePolicy().hasHeightForWidth());
        buttonShowList->setSizePolicy(sizePolicy2);
        buttonShowList->setMinimumSize(QSize(41, 41));
        buttonShowList->setMaximumSize(QSize(41, 41));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/2-3.png"), QSize(), QIcon::Normal, QIcon::Off);
        buttonShowList->setIcon(icon2);
        buttonShowList->setIconSize(QSize(82, 41));

        horizontalLayout_3->addWidget(buttonShowList);


        verticalLayout->addWidget(frame);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, -1, -1, -1);
        tabWidget = new QTabWidget(MainFrame);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(299, 394));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        QBrush brush1(QColor(255, 85, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush1);
        tabWidget->setPalette(palette);
        tabWidget->setCursor(QCursor(Qt::ArrowCursor));
        tabWidget->setAutoFillBackground(false);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(31, 31));
        tabWidget->setElideMode(Qt::ElideMiddle);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(50, 90, 31, 16));
        spinHue = new QSpinBox(tab_2);
        spinHue->setObjectName(QString::fromUtf8("spinHue"));
        spinHue->setGeometry(QRect(75, 87, 61, 22));
        spinHue->setAlignment(Qt::AlignCenter);
        spinHue->setMaximum(360);
        spinHue->setSingleStep(20);
        spinHue->setValue(250);
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 90, 31, 16));
        spinSaturation = new QDoubleSpinBox(tab_2);
        spinSaturation->setObjectName(QString::fromUtf8("spinSaturation"));
        spinSaturation->setGeometry(QRect(173, 87, 62, 22));
        spinSaturation->setAlignment(Qt::AlignCenter);
        spinSaturation->setMaximum(1.000000000000000);
        spinSaturation->setSingleStep(0.100000000000000);
        spinSaturation->setValue(0.300000000000000);
        buttonSepiaTone = new QPushButton(tab_2);
        buttonSepiaTone->setObjectName(QString::fromUtf8("buttonSepiaTone"));
        buttonSepiaTone->setGeometry(QRect(40, 37, 201, 41));
        buttonSepiaTone->setAutoFillBackground(false);
        buttonSepiaTone->setIconSize(QSize(41, 41));
        buttonSepiaTone->setCheckable(false);
        buttonSepiaTone->setAutoRepeat(false);
        buttonSepiaTone->setAutoExclusive(false);
        buttonSepiaTone->setAutoDefault(true);
        buttonSepiaTone->setFlat(false);
        label_FromMax = new QLabel(tab_2);
        label_FromMax->setObjectName(QString::fromUtf8("label_FromMax"));
        label_FromMax->setGeometry(QRect(140, 240, 61, 20));
        label_FromMin = new QLabel(tab_2);
        label_FromMin->setObjectName(QString::fromUtf8("label_FromMin"));
        label_FromMin->setGeometry(QRect(10, 240, 61, 20));
        spinFromMin = new QSpinBox(tab_2);
        spinFromMin->setObjectName(QString::fromUtf8("spinFromMin"));
        spinFromMin->setGeometry(QRect(70, 240, 61, 22));
        spinFromMin->setAlignment(Qt::AlignCenter);
        spinFromMin->setMaximum(255);
        spinFromMin->setSingleStep(10);
        spinFromMin->setValue(100);
        buttonContrast = new QPushButton(tab_2);
        buttonContrast->setObjectName(QString::fromUtf8("buttonContrast"));
        buttonContrast->setGeometry(QRect(40, 180, 201, 41));
        buttonContrast->setAutoFillBackground(false);
        buttonContrast->setIconSize(QSize(41, 41));
        buttonContrast->setCheckable(false);
        buttonContrast->setAutoRepeat(false);
        buttonContrast->setAutoExclusive(false);
        buttonContrast->setAutoDefault(true);
        buttonContrast->setFlat(false);
        spinFromMax = new QSpinBox(tab_2);
        spinFromMax->setObjectName(QString::fromUtf8("spinFromMax"));
        spinFromMax->setGeometry(QRect(200, 240, 61, 22));
        spinFromMax->setAlignment(Qt::AlignCenter);
        spinFromMax->setMaximum(255);
        spinFromMax->setSingleStep(10);
        spinFromMax->setValue(200);
        spinToMin = new QSpinBox(tab_2);
        spinToMin->setObjectName(QString::fromUtf8("spinToMin"));
        spinToMin->setGeometry(QRect(70, 280, 61, 22));
        spinToMin->setAlignment(Qt::AlignCenter);
        spinToMin->setMaximum(255);
        spinToMin->setSingleStep(10);
        spinToMin->setValue(0);
        label_ToMin = new QLabel(tab_2);
        label_ToMin->setObjectName(QString::fromUtf8("label_ToMin"));
        label_ToMin->setGeometry(QRect(20, 280, 51, 20));
        label_ToMax = new QLabel(tab_2);
        label_ToMax->setObjectName(QString::fromUtf8("label_ToMax"));
        label_ToMax->setGeometry(QRect(140, 280, 51, 20));
        spinToMax = new QSpinBox(tab_2);
        spinToMax->setObjectName(QString::fromUtf8("spinToMax"));
        spinToMax->setGeometry(QRect(200, 280, 61, 22));
        spinToMax->setAlignment(Qt::AlignCenter);
        spinToMax->setMaximum(255);
        spinToMax->setSingleStep(10);
        spinToMax->setValue(255);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        buttonOtsuBetween = new QPushButton(tab_3);
        buttonOtsuBetween->setObjectName(QString::fromUtf8("buttonOtsuBetween"));
        buttonOtsuBetween->setGeometry(QRect(30, 40, 231, 41));
        buttonLabeling = new QPushButton(tab_3);
        buttonLabeling->setObjectName(QString::fromUtf8("buttonLabeling"));
        buttonLabeling->setGeometry(QRect(30, 90, 231, 41));
        buttonHistoEqualization = new QPushButton(tab_3);
        buttonHistoEqualization->setObjectName(QString::fromUtf8("buttonHistoEqualization"));
        buttonHistoEqualization->setGeometry(QRect(30, 220, 231, 41));
        buttonHistoMatching = new QPushButton(tab_3);
        buttonHistoMatching->setObjectName(QString::fromUtf8("buttonHistoMatching"));
        buttonHistoMatching->setGeometry(QRect(30, 270, 231, 41));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        buttonGenerateNoise = new QPushButton(tab_4);
        buttonGenerateNoise->setObjectName(QString::fromUtf8("buttonGenerateNoise"));
        buttonGenerateNoise->setGeometry(QRect(40, 70, 211, 41));
        buttonGaussianFilter = new QPushButton(tab_4);
        buttonGaussianFilter->setObjectName(QString::fromUtf8("buttonGaussianFilter"));
        buttonGaussianFilter->setGeometry(QRect(0, 150, 151, 21));
        buttonMedianFilter = new QPushButton(tab_4);
        buttonMedianFilter->setObjectName(QString::fromUtf8("buttonMedianFilter"));
        buttonMedianFilter->setGeometry(QRect(150, 150, 141, 41));
        spinSigma = new QSpinBox(tab_4);
        spinSigma->setObjectName(QString::fromUtf8("spinSigma"));
        spinSigma->setGeometry(QRect(220, 10, 42, 22));
        spinSigma->setMinimum(1);
        spinSigma->setMaximum(10);
        spinSigma->setValue(3);
        label_Sigma = new QLabel(tab_4);
        label_Sigma->setObjectName(QString::fromUtf8("label_Sigma"));
        label_Sigma->setGeometry(QRect(160, 10, 51, 20));
        label_Mean = new QLabel(tab_4);
        label_Mean->setObjectName(QString::fromUtf8("label_Mean"));
        label_Mean->setGeometry(QRect(50, 10, 51, 20));
        spinMean = new QSpinBox(tab_4);
        spinMean->setObjectName(QString::fromUtf8("spinMean"));
        spinMean->setGeometry(QRect(100, 10, 42, 22));
        spinMean->setMinimum(0);
        spinMean->setMaximum(255);
        spinMean->setValue(50);
        label_SaltPepperPercent = new QLabel(tab_4);
        label_SaltPepperPercent->setObjectName(QString::fromUtf8("label_SaltPepperPercent"));
        label_SaltPepperPercent->setGeometry(QRect(30, 40, 101, 20));
        spinPercent = new QSpinBox(tab_4);
        spinPercent->setObjectName(QString::fromUtf8("spinPercent"));
        spinPercent->setGeometry(QRect(150, 40, 81, 22));
        spinPercent->setMinimum(0);
        spinPercent->setMaximum(100);
        spinPercent->setSingleStep(10);
        spinPercent->setValue(10);
        label_kernelsize = new QLabel(tab_4);
        label_kernelsize->setObjectName(QString::fromUtf8("label_kernelsize"));
        label_kernelsize->setGeometry(QRect(160, 120, 61, 20));
        spinKernelSize = new QSpinBox(tab_4);
        spinKernelSize->setObjectName(QString::fromUtf8("spinKernelSize"));
        spinKernelSize->setGeometry(QRect(230, 120, 42, 22));
        spinKernelSize->setMinimum(3);
        spinKernelSize->setMaximum(7);
        spinKernelSize->setSingleStep(2);
        spinKernelSize->setValue(5);
        label_GaussianFIlterSigma = new QLabel(tab_4);
        label_GaussianFIlterSigma->setObjectName(QString::fromUtf8("label_GaussianFIlterSigma"));
        label_GaussianFIlterSigma->setGeometry(QRect(10, 120, 41, 20));
        spinGaussianFIlterSigma = new QDoubleSpinBox(tab_4);
        spinGaussianFIlterSigma->setObjectName(QString::fromUtf8("spinGaussianFIlterSigma"));
        spinGaussianFIlterSigma->setGeometry(QRect(70, 120, 62, 22));
        spinGaussianFIlterSigma->setMinimum(0.100000000000000);
        spinGaussianFIlterSigma->setMaximum(5.000000000000000);
        spinGaussianFIlterSigma->setSingleStep(0.100000000000000);
        spinGaussianFIlterSigma->setValue(0.700000000000000);
        buttonFastGaussianFilter = new QPushButton(tab_4);
        buttonFastGaussianFilter->setObjectName(QString::fromUtf8("buttonFastGaussianFilter"));
        buttonFastGaussianFilter->setGeometry(QRect(0, 170, 151, 21));
        buttonCanny = new QPushButton(tab_4);
        buttonCanny->setObjectName(QString::fromUtf8("buttonCanny"));
        buttonCanny->setGeometry(QRect(10, 250, 271, 51));
        label_LowThreshold = new QLabel(tab_4);
        label_LowThreshold->setObjectName(QString::fromUtf8("label_LowThreshold"));
        label_LowThreshold->setGeometry(QRect(10, 310, 91, 20));
        spinLowThreshold = new QSpinBox(tab_4);
        spinLowThreshold->setObjectName(QString::fromUtf8("spinLowThreshold"));
        spinLowThreshold->setGeometry(QRect(100, 310, 42, 22));
        spinLowThreshold->setMinimum(0);
        spinLowThreshold->setMaximum(255);
        spinLowThreshold->setValue(50);
        label_HighThreshold = new QLabel(tab_4);
        label_HighThreshold->setObjectName(QString::fromUtf8("label_HighThreshold"));
        label_HighThreshold->setGeometry(QRect(150, 310, 91, 20));
        spinHighThreshold = new QSpinBox(tab_4);
        spinHighThreshold->setObjectName(QString::fromUtf8("spinHighThreshold"));
        spinHighThreshold->setGeometry(QRect(240, 310, 42, 22));
        spinHighThreshold->setMinimum(0);
        spinHighThreshold->setMaximum(255);
        spinHighThreshold->setValue(50);
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        buttonHoughCircle = new QPushButton(tab);
        buttonHoughCircle->setObjectName(QString::fromUtf8("buttonHoughCircle"));
        buttonHoughCircle->setGeometry(QRect(50, 50, 191, 51));
        label_CircleRadius = new QLabel(tab);
        label_CircleRadius->setObjectName(QString::fromUtf8("label_CircleRadius"));
        label_CircleRadius->setGeometry(QRect(70, 110, 101, 20));
        spinCircleRadius = new QSpinBox(tab);
        spinCircleRadius->setObjectName(QString::fromUtf8("spinCircleRadius"));
        spinCircleRadius->setGeometry(QRect(170, 110, 51, 22));
        spinCircleRadius->setMinimum(0);
        spinCircleRadius->setMaximum(1000);
        spinCircleRadius->setValue(51);
        buttonReadModel = new QPushButton(tab);
        buttonReadModel->setObjectName(QString::fromUtf8("buttonReadModel"));
        buttonReadModel->setGeometry(QRect(50, 220, 191, 31));
        buttonGeneralizedHough = new QPushButton(tab);
        buttonGeneralizedHough->setObjectName(QString::fromUtf8("buttonGeneralizedHough"));
        buttonGeneralizedHough->setGeometry(QRect(40, 250, 211, 31));
        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);

        listWidget = new QListWidget(MainFrame);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);
        listWidget->setMinimumSize(QSize(0, 394));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 0, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush3(QColor(0, 0, 127, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush3);
        QBrush brush4(QColor(255, 255, 255, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush3);
        QBrush brush5(QColor(255, 255, 255, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush5);
#endif
        QBrush brush6(QColor(120, 120, 120, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        QBrush brush7(QColor(240, 240, 240, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush7);
        QBrush brush8(QColor(255, 255, 255, 128));
        brush8.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush8);
#endif
        listWidget->setPalette(palette1);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        listWidget->setFont(font);

        horizontalLayout->addWidget(listWidget);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(MainFrame);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainFrame);
    } // setupUi

    void retranslateUi(QDialog *MainFrame)
    {
        MainFrame->setWindowTitle(QCoreApplication::translate("MainFrame", "Homeworks", nullptr));
#if QT_CONFIG(tooltip)
        buttonOpen->setToolTip(QCoreApplication::translate("MainFrame", "open an image file", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonOpen->setText(QString());
        toolButton_2->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainFrame", "...", nullptr));
#if QT_CONFIG(tooltip)
        buttonDeleteContents->setToolTip(QCoreApplication::translate("MainFrame", "close all forms", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonDeleteContents->setText(QString());
#if QT_CONFIG(tooltip)
        buttonShowList->setToolTip(QCoreApplication::translate("MainFrame", "show the list view", nullptr));
#endif // QT_CONFIG(tooltip)
        buttonShowList->setText(QString());
        label_5->setText(QCoreApplication::translate("MainFrame", "Hue", nullptr));
        label_6->setText(QCoreApplication::translate("MainFrame", "Sat.", nullptr));
        buttonSepiaTone->setText(QCoreApplication::translate("MainFrame", "Sepia Tone", nullptr));
        label_FromMax->setText(QCoreApplication::translate("MainFrame", "FromMax", nullptr));
        label_FromMin->setText(QCoreApplication::translate("MainFrame", "FromMin", nullptr));
        buttonContrast->setText(QCoreApplication::translate("MainFrame", "Luminance Contrast", nullptr));
        label_ToMin->setText(QCoreApplication::translate("MainFrame", "ToMin", nullptr));
        label_ToMax->setText(QCoreApplication::translate("MainFrame", "ToMax", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainFrame", " cv 1 ", nullptr));
        buttonOtsuBetween->setText(QCoreApplication::translate("MainFrame", "Otsu Thresholding", nullptr));
        buttonLabeling->setText(QCoreApplication::translate("MainFrame", "Otsu Thresholding + Labeling", nullptr));
        buttonHistoEqualization->setText(QCoreApplication::translate("MainFrame", "Histogram Equalization", nullptr));
        buttonHistoMatching->setText(QCoreApplication::translate("MainFrame", "Histogram Matching", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainFrame", " cv 2 ", nullptr));
        buttonGenerateNoise->setText(QCoreApplication::translate("MainFrame", "Generate Noise Image", nullptr));
        buttonGaussianFilter->setText(QCoreApplication::translate("MainFrame", "Gaussian Filter", nullptr));
        buttonMedianFilter->setText(QCoreApplication::translate("MainFrame", "Median Filtering", nullptr));
        label_Sigma->setText(QCoreApplication::translate("MainFrame", "Sigma", nullptr));
        label_Mean->setText(QCoreApplication::translate("MainFrame", "Mean", nullptr));
        label_SaltPepperPercent->setText(QCoreApplication::translate("MainFrame", "SaltPepper%", nullptr));
        label_kernelsize->setText(QCoreApplication::translate("MainFrame", "kernel size", nullptr));
        label_GaussianFIlterSigma->setText(QCoreApplication::translate("MainFrame", "Sigma", nullptr));
        buttonFastGaussianFilter->setText(QCoreApplication::translate("MainFrame", "Fast Gaussian Filter", nullptr));
        buttonCanny->setText(QCoreApplication::translate("MainFrame", "Canny Edge Detection", nullptr));
        label_LowThreshold->setText(QCoreApplication::translate("MainFrame", "Low Threshold", nullptr));
        label_HighThreshold->setText(QCoreApplication::translate("MainFrame", "high Threshold", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainFrame", " cv 3 ", nullptr));
        buttonHoughCircle->setText(QCoreApplication::translate("MainFrame", "Hough Transform Circle", nullptr));
        label_CircleRadius->setText(QCoreApplication::translate("MainFrame", "Circle radius : ", nullptr));
        buttonReadModel->setText(QCoreApplication::translate("MainFrame", "Read Model", nullptr));
        buttonGeneralizedHough->setText(QCoreApplication::translate("MainFrame", "Generalized Hough Transform", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainFrame", " cv 4 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainFrame: public Ui_MainFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
