/**
 * UI 主页面
 */

/*
1.先注册托盘和托盘菜单{"选择文件", "设置"， "退出"}
2.开发托盘菜单项对应的功能：
  选择文件： 打开文件资源管理器->选择 txt 文本文件 -> 打开 -> 读取到文本编辑器中
  设置： 打开设置菜单 【保留接口】
  退出： 退出程序
*/

#ifndef HOME_H
#define HOME_H

#include <QWidget>
#include <QPlainTextEdit>

class SystemTray;
class TxtReadWidget;
class Home : public QWidget
{
Q_OBJECT

public:
  Home();
  ~Home();

protected:
  void setUI();
  void selectTxtFile();
protected slots:
  void traySignalShow();
  void traySignalHide();
  void traySignalSelectFile();
  void traySignalSetting();
  void traySignalExit();
private:
  SystemTray* m_tray;       // 程序托盘
  TxtReadWidget* m_txt_read_widget; // 文本显示区
};

#endif
