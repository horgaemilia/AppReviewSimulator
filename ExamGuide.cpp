#include "ExamGuide.h"

ExamGuide::ExamGuide(Service& service,QWidget *parent)
    : QMainWindow(parent), service{service}
{
    ui.setupUi(this);
    std::vector<User> all_users = service.GetUsers();
    for (int i = 0; i < all_users.size(); ++i)
    {
        std::shared_ptr<UserWindow> w = std::make_shared<UserWindow>(service, all_users[i]);
        this->userWindows.push_back(w);
        service.addObserver(w.get());
    }
    this->show_windows();
}

void ExamGuide::show_windows()
{
    for (auto& item : this->userWindows)
        item->show();
        return;
}

void ExamGuide::update()
{
    return;
}
