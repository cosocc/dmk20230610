#include <QApplication>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QMainWindow>
#include "sytemIcon.h"
#include <Shlwapi.h>
int main(int argc, char* argv[])
{    
    QApplication app(argc, argv);       
    QIcon icon(":/icons/m.ico");
    app.setWindowIcon(icon);
    HANDLE hMutex = CreateMutex(NULL, false, L"***OPK***");
    if (hMutex != NULL)
    {
        if (GetLastError() == ERROR_ALREADY_EXISTS)
        {
            CloseHandle(hMutex);
            ::MessageBox(NULL, L"The program is already running!", L"Tips", MB_OK | MB_ICONWARNING);
            return EXIT_SUCCESS;
        }

         sytemIcon*iconSytem = new sytemIcon();
         iconSytem->show();
    }
    else
    {
        // 创建互斥量失败的错误处理
        ::MessageBox(NULL, L"Failed to create mutex!", L"Error", MB_OK | MB_ICONERROR);
        return EXIT_FAILURE;
    }

    return app.exec();
}
