#include "sytemIcon.h"
#include<QMessageBox>
#include <QApplication>

sytemIcon::sytemIcon(QObject *parent)
	: QSystemTrayIcon(parent)
{
	iCon =  QIcon(".\\img\\m.ico");

	createSytemIconMenu();
	createServerIpDlag();
	createSyncSettingDlg();
	signalAndSlot();
}

sytemIcon::~sytemIcon()
{


}

void sytemIcon::createSytemIconMenu()
{		
	setIcon(iCon);	
	menuRightBtn = new	QMenu();
	actionShow = new QAction("Sync Setting", menuRightBtn);
	actionQuit = new QAction("quit", menuRightBtn);
	menuRightBtn->addAction(actionShow);
	menuRightBtn->addAction(actionQuit);
	setContextMenu(menuRightBtn);
}

void sytemIcon::createServerIpDlag()
{
	dlgUpdate = new QDialog();
	dlgUpdate->setWindowIcon(iCon);
	dlgUpdate->setFixedSize(460, 320);
	dlgUpdate->setWindowTitle("Server IP");
	dlgUpdate->setAttribute(Qt::WA_QuitOnClose, false);
	dlgUpLabel = new QLabel(QString::fromLocal8Bit("127.0.0.1"));
	QFont f_m_titleLabel;
	f_m_titleLabel.setPointSize(15);
	f_m_titleLabel.setBold(true);
	f_m_titleLabel.setWeight(75);
	dlgUpLabel->setStyleSheet("color:#000");
	dlgUpLabel->setFont(f_m_titleLabel);
	dlgUpLabel->setAlignment(Qt::AlignBottom | Qt::AlignHCenter);
	dlgDownLabel = new QLabel(QString::fromLocal8Bit("127.0.0.1"));
	QFont f_m_detailLabel;
	f_m_detailLabel.setWeight(50);
	dlgDownLabel->setStyleSheet("color:#000");
	dlgDownLabel->setFont(f_m_detailLabel);
	dlgDownLabel->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
	dlgDownLabel->setWordWrap(true);
	QVBoxLayout* btnFrameVlayout = new QVBoxLayout(dlgUpdate);
	btnFrameVlayout->setContentsMargins(0, 0, 0, 0);
	btnFrameVlayout->addWidget(dlgUpLabel);
	btnFrameVlayout->addWidget(dlgDownLabel);
}

void sytemIcon::createSyncSettingDlg()
{
	dlgSyncSetting = new QDialog(dlgUpdate);
	dlgSyncSetting->setModal(true);
	dlgSyncSetting->setWindowIcon(iCon);
	dlgSyncSetting->setWindowTitle("Sync Setting");
	dlgSyncSetting->setFixedSize(475, 72);
	dlgSyncSetting->setAttribute(Qt::WA_QuitOnClose, false);
	QLabel* anotheripLabel = new QLabel(QString::fromLocal8Bit("Another IP:"));
	lineEditIP = new QLineEdit(QString::fromLocal8Bit("127.0.0.1"));
	btnOk = new QPushButton(QString::fromLocal8Bit("OK"));
	checkboxSync = new QCheckBox(QString::fromLocal8Bit("Enable Sync"));
	QGridLayout* syncLayout = new QGridLayout(dlgSyncSetting);
	syncLayout->addWidget(anotheripLabel, 0, 0);
	syncLayout->addWidget(lineEditIP, 0, 1);
	syncLayout->addWidget(btnOk, 0, 2);
	syncLayout->addWidget(checkboxSync, 1, 1);
	syncLayout->setAlignment(Qt::AlignTop);
}

void sytemIcon::signalAndSlot()
{
	connect(actionShow, &QAction::triggered, dlgSyncSetting, &QDialog::show);
	connect(actionQuit, &QAction::triggered, qApp, &QApplication::quit);
	connect(this, &sytemIcon::activated, this, &sytemIcon::handleTrayIconActivated);
}

void sytemIcon::handleTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{

	if (reason == QSystemTrayIcon::DoubleClick)
	{
		if (dlgUpdate->isVisible())
		{
			dlgUpdate->hide();
		}
		else
		{
			dlgUpdate->show();

		}
	}
	//else if (reason == QSystemTrayIcon::Trigger)
	//{
	//	showMessage(QString::fromLocal8Bit("气泡提示标题"), QString::fromLocal8Bit("气泡提示内容"), QSystemTrayIcon::NoIcon, 5000);  // 显示气泡提示，持续5秒
	//}


}

