#include <iostream>
#include "LoginMenu.h"
#include "TeacherMenu.h"
#include "StudentMenu.h"

int main() {
    while (true) {
        Ajunie::LoginMenu login;
        system("cls");
        auto option {login.run()};

        switch (option) {
            case Ajunie::LoginMenu::menu_id::Exit :
                return 0;
            case Ajunie::LoginMenu::menu_id::LoginFailed :
                continue;
            case Ajunie::LoginMenu::menu_id::TLoginSuccessfully : {
                Ajunie::TeacherMenu TMenu(Ajunie::LoginMenu::num);
                system("cls");
                TMenu.run();
                continue;
            }
            case Ajunie::LoginMenu::menu_id::SLoginSuccessfully : {
                Ajunie::StudentMenu SMenu(Ajunie::LoginMenu::num);
                system("cls");
                SMenu.run();
                continue;
            }
            default:
                std::cerr << "Invalid Option!" << std::endl;
                system("pause");
                std::cout << std::endl;
                return 0;
        }
    }
}
