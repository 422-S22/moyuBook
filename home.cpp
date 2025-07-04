#include "home.h"

#include <QDebug>
#include <QApplication>
#include <QVBoxLayout>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>


#include "systemtray.h"
#include "txtreadwidget.h"

Home::Home() : m_tray(new SystemTray(this)), m_txt_read_widget(nullptr){
  if(m_tray == nullptr) {
    qDebug() << "Home: create tray failed.";
    traySignalExit();
  }
  m_tray->show();
  connect(m_tray, &SystemTray::showTriggered, this, &Home::traySignalShow);
  connect(m_tray, &SystemTray::hideTriggered, this, &Home::traySignalHide);
  connect(m_tray, &SystemTray::selectFileTriggered, this, &Home::traySignalSelectFile);
  connect(m_tray, &SystemTray::settingsTriggered, this, &Home::traySignalSetting);
  connect(m_tray, &SystemTray::exitTriggered, this, &Home::traySignalExit);
  
  setUI();
}

Home::~Home() {
}

void Home::setUI() {
  if(m_txt_read_widget == nullptr) {
    m_txt_read_widget = new TxtReadWidget(this);
  }
  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->setContentsMargins(0, 0, 0, 0); // 去除边框
  layout->addWidget(m_txt_read_widget);
  this->setLayout(layout);
}

void Home::selectTxtFile() {
  QString file_name = QFileDialog::getOpenFileName(this, "选择 TXT 文件", "", "Text Files (*.txt)");
  if (!file_name.isEmpty()) {
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QTextStream in(&file);
      m_txt_read_widget->setPlainText(in.readAll());
      file.close();
    }
  }
  if(!isVisible()) this->show();
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
  selectTxtFile();
}

void Home::traySignalSetting() {
  qDebug() << "tray signal: setting.";
}

void Home::traySignalExit() {
  qDebug() << "system quit...";
  QApplication::quit();
}
