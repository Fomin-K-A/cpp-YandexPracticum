#include "setting.h"
#include "ui_setting.h"
#include <prac/QInputDialog>

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);

    setWindowFlags(Qt::WindowStaysOnTopHint);

    for (const auto& action : actions_) {
        ui->cb_action->addItem(action.name);
    }
    ui->cb_action->addItem("Открыть URL");
    ui->cb_action->addItem("Открыть папку");
}

Setting::~Setting() {
    delete ui;
}

void Setting::on_pb_save_clicked() {
    auto index = ui->cb_action->currentIndex();
    if (index < 0 || static_cast<size_t>(index) >= actions_.size() + 2) {
        return;
    }

    if (static_cast<size_t>(index) < actions_.size()) {
        emit signalSetAction(current_button_idx_, actions_[index].name, actions_[index].action);
    } else if (static_cast<size_t>(index) == actions_.size()) {
        QString user_input = prac::QInputDialog::getText(this, "Введите URL", "URL:");
        emit signalSetAction(current_button_idx_, QString("Открыть URL %1").arg(user_input),
                             [user_input]() { OpenCustomUrl(user_input); });
    } else {
        QString user_input = prac::QInputDialog::getText(this, "Введите путь к папке", "Путь:");
        emit signalSetAction(current_button_idx_, QString("Открыть папку %1").arg(user_input),
                             [user_input]() { OpenCustomDirectory(user_input); });
    }
    ui->cb_action->setCurrentIndex(0);
    this->close();
}
