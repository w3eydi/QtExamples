#include "widget.h"
#include "ui_widget.h"

#include <QKeyEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // <<<<<<<<<<< COUNTER TIMER
    counter = 1;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(counterTimer()));
    ui->spinBox->setFocusPolicy(Qt::ClickFocus);
    // >>>>>>>>>>> COUNTER TIMER
}

Widget::~Widget()
{
    delete ui;
}

void Widget::counterTimer()
{
    ui->counter_label->setNum(counter);
    counter++;
}

void Widget::keyPressEvent(QKeyEvent *e) {

    switch (e->key()) {
        case Qt::Key_0:
            ui->key_show_label->setText("A");
            break;
        case Qt::Key_1:
            ui->key_show_label->setText("B");
            break;
        case Qt::Key_2:
            ui->key_show_label->setText("C");
            break;
        case Qt::Key_3:
            ui->key_show_label->setText("D");
            break;
        case Qt::Key_4:
            ui->key_show_label->setText("E");
            break;
        case Qt::Key_5:
            ui->key_show_label->setText("F");
            break;
        case Qt::Key_6:
            ui->key_show_label->setText("G");
            break;
        case Qt::Key_7:
            ui->key_show_label->setText("H");
            break;
        case Qt::Key_8:
            ui->key_show_label->setText("I");
            break;
        case Qt::Key_9:
            ui->key_show_label->setText("J");
            break;
        default:
            ui->key_show_label->setText("Err!");
    }
}

void Widget::on_startButton_clicked()
{
    ui->counter_label->setNum(0);
    timer->start(ui->spinBox->value());
    ui->startButton->setEnabled(false);
    ui->stopButton->setEnabled(true);
}


void Widget::on_stopButton_clicked()
{
    timer->stop();
    ui->startButton->setEnabled(true);
    ui->stopButton->setEnabled(false);
    counter = 1;
}


