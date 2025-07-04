#ifndef TXTREADWIDGET_H
#define TXTREADWIDGET_H

#include <QPlainTextEdit>

class TxtReadWidget : public QPlainTextEdit {
  Q_OBJECT
public: 
  explicit TxtReadWidget(QWidget* parent = nullptr);
  ~TxtReadWidget();

};

#endif
