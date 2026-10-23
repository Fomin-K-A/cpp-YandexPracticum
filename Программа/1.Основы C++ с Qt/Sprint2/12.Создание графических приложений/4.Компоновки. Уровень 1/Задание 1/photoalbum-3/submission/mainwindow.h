#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetPixmap(const QString path) {
        active_pixmap = QPixmap(path);
    }

    void SetFolder(const QString& d){
        current_folder_ = d;
        cur_file_index_ = 0;
        SetPixmap(GetCurrentFile());
    }

    QString GetCurrentFile(){
        QDir dir(current_folder_);
        QStringList list_files = dir.entryList();

        int total = int(list_files.size());

        int file_index = std::min(cur_file_index_, total - 1);
        file_index = std::max(0, file_index);

        return dir.filePath(list_files[file_index]);
    }

    void FitImage();
    void UpdateEnabled();

private slots:
    void on_btn_left_clicked();

    void on_btn_right_clicked();

private:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::MainWindow *ui;
    QPixmap active_pixmap;
    QLabel lbl_new_{this};
    QString current_folder_;
    int cur_file_index_ = 0;
};

#endif // MAINWINDOW_H
