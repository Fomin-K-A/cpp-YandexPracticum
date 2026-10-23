#include "mainwindow.h"
#include "ui_mainwindow.h"

// Функция подгоняет изображение под нужный размер окна.
[[nodiscard("Не игнорируйте результат функции")]] QPixmap ResizeImgToFit(const QPixmap &src, int window_width, int window_height) {
    int img_w = src.width();
    int img_h = src.height();

    double w_ratio = double(img_w) / window_width;
    double h_ratio = double(img_h) / window_height;

    if ( w_ratio <= h_ratio ) {
        return src.scaledToWidth(window_width);
    } else {
        return src.scaledToHeight(window_height);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SetFolder(":/cats/images/");
    FitImage();
    UpdateEnabled();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::FitImage()
{
    Q_ASSERT(!active_pixmap.isNull());

    int win_w = width();
    int win_h = height();

    QPixmap scaled_img = ResizeImgToFit(active_pixmap, win_w, win_h);

    int new_w = scaled_img.width();
    int new_h = scaled_img.height();

    lbl_new_.setPixmap(scaled_img);

    lbl_new_.resize(new_w, new_h);

    int x = (win_w - new_w) / 2;
    int y = (win_h - new_h) / 2;
    lbl_new_.move(x, y);
}

void MainWindow::resizeEvent(QResizeEvent*)
{
    FitImage();
}

void MainWindow::on_btn_left_clicked()
{
    cur_file_index_--;
    UpdateEnabled();
    SetPixmap(GetCurrentFile());
    FitImage();
}


void MainWindow::on_btn_right_clicked()
{
    cur_file_index_++;
    UpdateEnabled();
    SetPixmap(GetCurrentFile());
    FitImage();
}

void MainWindow::UpdateEnabled(){
    int max_images = QDir(current_folder_).entryList().size();

    ui->btn_left->setEnabled(cur_file_index_ > 0);

    ui->btn_right->setEnabled(cur_file_index_ < max_images - 1);
}
