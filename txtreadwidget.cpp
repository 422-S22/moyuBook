#include "txtreadwidget.h"

#include <QMimeData>
#include <QTextStream>
#include <QDebug>

TxtReadWidget::TxtReadWidget(QWidget* parent)
  : QPlainTextEdit(parent)
{
  setReadOnly(true);
  setAcceptDrops(true);
  viewport()->setAcceptDrops(true);
  viewport()->installEventFilter(this);
}
TxtReadWidget::~TxtReadWidget() {

}

void TxtReadWidget::dragEnterEvent(QDragEnterEvent* event) {
  qDebug() << "Drag enter";
  if (event->mimeData()->hasUrls()) {
    const QList<QUrl> urls = event->mimeData()->urls();
    if (!urls.isEmpty() && urls.first().toLocalFile().endsWith(".txt")) {
      event->acceptProposedAction();
      qDebug() << "Dragging in:" << urls.first().toLocalFile();
      return;
    }
  }
  event->ignore();
}

void TxtReadWidget::dropEvent(QDropEvent* event)
{
  qDebug() << "Drop!";
  const QList<QUrl> urls = event->mimeData()->urls();
  if (!urls.isEmpty()) {
    QString fileName = urls.first().toLocalFile();
    if (fileName.endsWith(".txt", Qt::CaseInsensitive)) {
      QFile file(fileName);
      if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        setPlainText(in.readAll());
        file.close();
      }
    }
  }
}

bool TxtReadWidget::eventFilter(QObject *obj, QEvent *event)
{
  if (obj == viewport()) {
    if (event->type() == QEvent::DragEnter)
      qDebug() << "[filter] drag enter";
    if (event->type() == QEvent::Drop)
      qDebug() << "[filter] drop";
  }
  return QPlainTextEdit::eventFilter(obj, event);
}

