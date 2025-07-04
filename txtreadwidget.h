#ifndef TXTREADWIDGET_H
#define TXTREADWIDGET_H

#include <QPlainTextEdit>

class TxtReadWidget : public QPlainTextEdit {
  Q_OBJECT
public: 
  explicit TxtReadWidget(QWidget* parent = nullptr);
  ~TxtReadWidget();
protected:
  void dragEnterEvent(QDragEnterEvent* event) override;
  void dropEvent(QDropEvent* event) override;
  bool eventFilter(QObject *obj, QEvent *event) override;

};

#endif
