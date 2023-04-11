#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sw(new Stopwatch(this))
{
    ui->setupUi(this);
    ui->pushButton_1->setCheckable(true);
    ui->pushButton_3->setEnabled(false);

    connect(sw, &Stopwatch::ctime_changed, this, &MainWindow::on_sw_ctime_changed);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1_clicked()
{
    if (ui->pushButton_1->isChecked()) {
        sw->start();
        ui->pushButton_1->setText("Стоп");
        ui->pushButton_3->setEnabled(true);
    }
    else {
        sw->stop();
        ui->pushButton_1->setText("Старт");
        ui->pushButton_3->setEnabled(false);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    sw->clear();
    ui->textBrowser->clear();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->textBrowser->append(QString("Круг %1 - Время %2с")
        .arg(sw->getRound())
        .arg(sw->getRoundTime()));
    sw->next_round();
}

void MainWindow::on_sw_ctime_changed(float value)
{
    if (value == 0) ui->label->setText("Время");
    else ui->label->setText(QString("%1с").arg(value));
}

