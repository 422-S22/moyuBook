#include "systemtray.h"
#include <QAction>
#include <QIcon>

SystemTray::SystemTray(QObject *parent)
  : QSystemTrayIcon(parent)
{
  setIcon(QIcon::fromTheme("text-x-generic")); // 可自定义图标
  setTrayMenu();
  show();
}

SystemTray::~SystemTray()
{
  hide();
}

void SystemTray::setTrayMenu() {
  m_tray_menu = new QMenu();

  QAction *showAction = new QAction("显示", m_tray_menu);
  QAction *hideAction = new QAction("隐藏", m_tray_menu);
  QAction *selectFileAction = new QAction("选择文件", m_tray_menu);
  QAction *settingsAction = new QAction("设置", m_tray_menu);
  QAction *exitAction = new QAction("退出", m_tray_menu);

  m_tray_menu->addAction(showAction);
  m_tray_menu->addAction(hideAction);
  m_tray_menu->addAction(selectFileAction);
  m_tray_menu->addAction(settingsAction);
  m_tray_menu->addSeparator();
  m_tray_menu->addAction(exitAction);

  connect(showAction, &QAction::triggered, this, &SystemTray::showTriggered);
  connect(hideAction, &QAction::triggered, this, &SystemTray::hideTriggered);
  connect(selectFileAction, &QAction::triggered, this, &SystemTray::selectFileTriggered);
  connect(settingsAction, &QAction::triggered, this, &SystemTray::settingsTriggered);
  connect(exitAction, &QAction::triggered, this, &SystemTray::exitTriggered);

  setContextMenu(m_tray_menu);
}
