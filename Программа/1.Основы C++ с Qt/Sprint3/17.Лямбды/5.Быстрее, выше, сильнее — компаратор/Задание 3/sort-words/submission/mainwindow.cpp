#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <algorithm>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sensitivity = Qt::CaseSensitivity();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rb_asc_clicked()
{
    is_ascending = true;
    on_le_unsorted_textChanged(ui->le_unsorted->text());
}

void MainWindow::on_rb_desc_clicked()
{
    is_ascending = false;
    on_le_unsorted_textChanged(ui->le_unsorted->text());
}

void MainWindow::on_cb_case_clicked()
{
    sensitivity = ui->cb_case->isChecked() ? Qt::CaseSensitive : Qt::CaseInsensitive;
    on_le_unsorted_textChanged(ui->le_unsorted->text());
}

void MainWindow::on_le_unsorted_textChanged(const QString& arg1)
{
    if (arg1.isEmpty()) {
        ui->le_sorted->clear();
        return;
    }

    QStringList word_list = arg1.split(' ');

    std::sort(word_list.begin(), word_list.end(),
              [this](const QString& a, const QString& b) {
                  if (is_ascending) {
                      return QString::compare(a, b, sensitivity) < 0;
                  } else {
                      return QString::compare(a, b, sensitivity) > 0;
                  }
              });

    QString result_text;
    for (int i = 0; i < word_list.size(); ++i) {
        result_text += word_list[i];
        if (i < word_list.size() - 1) {
            result_text += " ";
        }
    }

    ui->le_sorted->setText(result_text);
}
