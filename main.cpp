#include <QApplication>

#include "home.h"

int main(int argc, char* argv[]) {
  QApplication app(argc, argv);

  Home home;
  // home.show();

  app.exec();
  return 0;
}