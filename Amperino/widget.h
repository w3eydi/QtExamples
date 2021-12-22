#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void counterTimer();

protected:
    void keyPressEvent(QKeyEvent*);

private slots:
    void on_startButton_clicked();
    void on_stopButton_clicked();

private:
    qint32 counter;

    Ui::Widget *ui;
    QTimer* timer;
};
#endif // WIDGET_H
