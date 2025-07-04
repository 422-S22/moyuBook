#include "txtreadwidget.h"

TxtReadWidget::TxtReadWidget(QWidget* parent)
  : QPlainTextEdit(parent)
{
  setReadOnly(true);  // 只读
}
TxtReadWidget::~TxtReadWidget() {

}