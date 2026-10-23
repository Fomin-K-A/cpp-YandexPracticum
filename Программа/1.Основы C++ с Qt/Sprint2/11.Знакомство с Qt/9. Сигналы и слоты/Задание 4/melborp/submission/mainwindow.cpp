#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_reverse_clicked()
{
    QString text = ui->le_input->text();
    std::reverse(text.begin(),text.end());
    ui->le_input->setText(text);
}

