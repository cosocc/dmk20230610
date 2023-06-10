#pragma once

#include <QSystemTrayIcon>
#include <QMenu>
#include <QDialog>
#include <QMouseEvent>
#include <QLabel>
#include<QVBoxLayout>
#include<QLineEdit>
#include<QPushButton>
#include<QCheckBox>
//#include <MouseMovement>
class sytemIcon  : public QSystemTrayIcon
{
	Q_OBJECT
private slots:

public:
	sytemIcon(QObject *parent=nullptr);
	~sytemIcon();
private:
	void createSytemIconMenu();
	void createServerIpDlag();
	void createSyncSettingDlg();
	void signalAndSlot();
	void handleTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

private:
	QIcon iCon;
	//systemicon member
	QMenu* menuRightBtn;
	QAction* actionShow;
	QAction* actionQuit;
	//serverip member
	QDialog* dlgUpdate;
	QLabel* dlgUpLabel;
	QLabel* dlgDownLabel;
	//sync member
	QDialog* dlgSyncSetting;
	QLineEdit* lineEditIP;
	QPushButton* btnOk;
	QCheckBox* checkboxSync;


};
