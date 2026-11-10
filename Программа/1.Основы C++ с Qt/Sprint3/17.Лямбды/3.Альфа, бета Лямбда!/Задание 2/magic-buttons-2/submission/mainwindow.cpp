#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    buttons_ = {ui->pb_button_1, ui->pb_button_2, ui->pb_button_3, ui->pb_button_4};

    actions_.resize(4);

    for (size_t i = 0; i < buttons_.size(); ++i) {
        auto handler = [this, i]() {
            if (i < actions_.size() && actions_[i]) {
                actions_[i]();
            }
        };

        connect(buttons_[i], &QPushButton::clicked, handler);
    }

    connect(setting_, &Setting::signalSetAction, this, &MainWindow::slotShowAction);
    setWindowFlags(Qt::WindowStaysOnTopHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotShowAction(int num, QString action_name, std::function<void()> action) {
    if (num < 0 || static_cast<size_t>(num) >= buttons_.size()) {
        return;
    }

    actions_[num] = action;

    buttons_[num]->setText(action_name);
}

void MainWindow::on_pb_sett_1_clicked()
{
    setting_->show();
    setting_->SetButtonForSetting(0);
}

void MainWindow::on_pb_sett_2_clicked()
{
    setting_->show();
    setting_->SetButtonForSetting(1);
}

void MainWindow::on_pb_sett_3_clicked()
{
    setting_->show();
    setting_->SetButtonForSetting(2);
}

void MainWindow::on_pb_sett_4_clicked()
{
    setting_->show();
    setting_->SetButtonForSetting(3);
}
