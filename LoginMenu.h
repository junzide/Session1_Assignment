//
// Created by junzite on 12/22/2022.
//

#ifndef SCHOOLSYSTEM_LOGINMENU_H
#define SCHOOLSYSTEM_LOGINMENU_H


#include <string>
#include <fstream>
#include <iostream>
#include <format>
#include <filesystem>
#include <cctype>
#include <limits>


namespace Ajunie {

    class LoginMenu {
    public:
        size_t run();
        static inline std::string num {};
        static size_t menu();
        bool login_teacher();
        bool login_student();

        enum menu_id{
            Exit,
            Teacher,
            Student,
            TLoginSuccessfully,
            SLoginSuccessfully,
            LoginFailed
        };

    private:
        std::string m_account_id_;
        std::string m_account_password_;
        std::ifstream m_teachers_account_;
        std::ifstream m_students_account_;

        const std::filesystem::path m_teachers_account_path_ {R"(.\assets\teachers_account.ajunie)"};
        const std::filesystem::path m_students_account_path_ {R"(.\assets\students_account.ajunie)"};

    };

}


#endif //SCHOOLSYSTEM_LOGINMENU_H
