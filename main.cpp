#include "UserWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repository{};
    Service service{ repository };
    std::vector < std::shared_ptr<UserWindow>> userWindows;
    std::vector<User> all_users = service.GetUsers();
    for (int i = 0; i < all_users.size(); ++i)
    {
        std::shared_ptr<UserWindow> w = std::make_shared<UserWindow>(service, all_users[i]);
        userWindows.push_back(w);
        service.addObserver(w.get());
    }
    for (auto& item : userWindows)
        item->show();
    return a.exec();
}
