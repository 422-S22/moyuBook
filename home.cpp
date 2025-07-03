#include "home.h"

#include <QDebug>
#include <QApplication>

#include "systemtray.h"

Home::Home() : m_tray(new SystemTray()){
  if(m_tray) {
    m_tray->show();
    connect(m_tray, &SystemTray::showTriggered, this, &Home::traySignalShow);
    connect(m_tray, &SystemTray::hideTriggered, this, &Home::traySignalHide);
    connect(m_tray, &SystemTray::selectFileTriggered, this, &Home::traySignalSelectFile);
    connect(m_tray, &SystemTray::settingsTriggered, this, &Home::traySignalSetting);
    connect(m_tray, &SystemTray::exitTriggered, this, &Home::traySignalExit);
  }
}

Home::~Home() {
  if(m_tray) delete m_tray;
}

void Home::traySignalShow() {
  qDebug() << "tray signal: show.";
  this->show();
}

void Home::traySignalHide() {
  qDebug() << "tray signal: hide.";
  this->hide();
}

void Home::traySignalSelectFile() {
  qDebug() << "tray signal: select file.";
}

void Home::traySignalSetting() {
  qDebug() << "tray signal: setting.";
}

void Home::traySignalExit() {
  qDebug() << "system quit...";
  QApplication::quit();
}
