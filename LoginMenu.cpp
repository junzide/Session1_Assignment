//
// Created by junzite on 12/22/2022.
//

#include "LoginMenu.h"

size_t Ajunie::LoginMenu::run() {
    while (true) {
        size_t option {menu()};
        switch (option) {
            case Exit :
                return Exit;
            case Teacher :
                if (login_teacher()) {
                    return TLoginSuccessfully;
                } else {
                    return LoginFailed;
                }
            case Student :
                if (login_student()) {
                    return SLoginSuccessfully;
                } else {
                    return LoginFailed;
                }
            default:
                std::cerr << "Invalid Option!" << std::endl;
                system("pause");
                std::cout << std::endl;
                break;
        }

        system("pause"); std::cout << std::endl;
    }
}

size_t Ajunie::LoginMenu::menu() {
    size_t option {};

    std::cout << std::endl;
    std::cout << std::format("{:#^30}\n", "Login Menu");
    std::cout << std::format("{:*<30}\n", "0. Exit");
    std::cout << std::format("{:*<30}\n", "1. Login As a Teacher");
    std::cout << std::format("{:*<30}\n", "2. Login As a Student");
    std::cout << std::format("{:#<30}\n", '#');
    std::cout << "Choose An Option: ";
    std::cin >> option;
    std::cin.clear();
    std::cin.ignore();

    return option;
}

bool Ajunie::LoginMenu::login_teacher() {
    while (true) {
        m_teachers_account_.open(m_teachers_account_path_, std::ios::in);
        if (!m_teachers_account_.is_open()) {
            std::cout << "Failed to open the " << m_teachers_account_path_ << std::endl;
            system("pause");
            std::cout << std::endl;
            exit(-1);
        }
        std::cout << std::endl;
        std::cout << std::format("{:*^30}\n: ", "Input Account");
        std::getline(std::cin, m_account_id_);

        std::cout << std::format("{:*^30}\n: ", "Input Password");
        std::getline(std::cin, m_account_password_);

        std::string temp;

        while (std::getline(m_teachers_account_, temp)/*!m_teachers_account_.eof()*/) {
//            std::getline(m_teachers_account_, temp);
            if (temp.starts_with("[id]") && temp.substr(4, temp.length() - 4) == m_account_id_) {
                std::getline(m_teachers_account_, temp);
                if (temp.starts_with("[password]") && temp.substr(10, temp.length() - 10) == m_account_password_) {
                    std::cout << "Login Successfully!" << std::endl;
                    std::getline(m_teachers_account_, temp);
                    num = temp.substr(5, temp.length() - 5);
                    system("pause");
                    return true;
                } else {
                    break;
                }
            }
        }
        std::cerr << "ID or Password Wrong!" << std::endl;
        system("pause");
        std::cout << std::endl;
        char temp_1 {};
        std::cout << "Try again?(Y/N)\n: ";
        std::cin >> temp_1;
        if (std::toupper(temp_1) == 'Y') {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        std::cin.clear();
        std::cin.ignore();
        m_teachers_account_.close();
        return false;
    }
}

bool Ajunie::LoginMenu::login_student() {
    while (true) {
        m_students_account_.open(m_students_account_path_, std::ios::in);
        if (!m_students_account_.is_open()) {
            std::cout << "Failed to open the " << m_students_account_path_ << std::endl;
            system("pause");
            std::cout << std::endl;
            exit(-1);
        }
        std::cout << std::endl;
        std::cout << std::format("{:*^30}\n: ", "Input Account");
        std::getline(std::cin, m_account_id_);

        std::cout << std::format("{:*^30}\n: ", "Input Password");
        std::getline(std::cin, m_account_password_);

        std::string temp;

        while (std::getline(m_students_account_, temp)/*!m_students_account_.eof()*/) {
//            std::getline(m_students_account_, temp);
            size_t start {};
            auto end {temp.find_first_of(' ')};
            num = {temp.substr(start, end)};
            start = temp.find_first_not_of(' ', end + 1);
            end = temp.find_first_of(' ',start + 1);
            auto id {temp.substr(start, end - start)};
            start = temp.find_first_not_of(' ', end + 1);
            end = temp.length();
            auto password {temp.substr(start, end - start)};
            if (id == m_account_id_ && password == m_account_password_) {
                std::cout << "Login Successfully!" << std::endl;
                system("pause");
                return true;
            }
        }
        std::cerr << "ID or Password Wrong!" << std::endl;
        system("pause");
        std::cout << std::endl;
        char temp_1 {};
        std::cout << "Try again?(Y/N)\n: ";
        std::cin >> temp_1;
        if (std::toupper(temp_1) == 'Y') {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        std::cin.clear();
        std::cin.ignore();
        m_students_account_.close();
        return false;
    }
}

