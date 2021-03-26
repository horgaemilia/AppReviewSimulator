#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ExamGuide.h"
#include "UserWindow.h"

class ExamGuide : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    ExamGuide(Service& service,QWidget *parent = Q_NULLPTR);

private:
    Ui::ExamGuideClass ui;
    Service& service;
    std::vector < std::shared_ptr<UserWindow>> userWindows;
    void show_windows();
    void update() override;
};
