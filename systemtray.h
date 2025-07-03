#ifndef SYSTEMTRAY_H
#define SYSTEMTRAY_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QObject>

class SystemTray : public QSystemTrayIcon
{
  Q_OBJECT

public:
  explicit SystemTray(QObject *parent = nullptr);
  ~SystemTray();

private:
  void setTrayMenu();

signals:
  void showTriggered();         // 显示主界面
  void hideTriggered();         // 隐藏主界面
  void selectFileTriggered();   // 选择 txt 文件
  void settingsTriggered();     // 进入设置
  void exitTriggered();         // 退出程序

private:
  QMenu *m_tray_menu;
};

#endif // SYSTEMTRAY_H
