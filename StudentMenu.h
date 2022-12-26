//
// Created by junzite on 12/24/2022.
//

#ifndef SCHOOLSYSTEM_STUDENTMENU_H
#define SCHOOLSYSTEM_STUDENTMENU_H

#include <iostream>
#include <vector>
#include <string_view>
#include <fstream>
#include <filesystem>
#include "Student.h"

namespace Ajunie {
    class StudentMenu {
    public:
        StudentMenu() = default;
        explicit StudentMenu(std::string_view num) : m_num_{num} {}
        ~StudentMenu() {writeData();}

        enum menu_id {
            Exit,
            ModifyName,
            ViewGrades
        };

        void run();
        size_t menu();
        void modifyName();
        void viewGrades();
        void readData();
        void writeData();


    private:
        std::string m_num_;
        Student m_self_;
        std::vector<Student> m_Classes_;
        std::ifstream m_students_info_in_;
        std::ofstream m_students_info_out_;
        const std::filesystem::path m_path_students_info_ {R"(.\assets\students_info.ajunie)"};

    };
}


#endif //SCHOOLSYSTEM_STUDENTMENU_H
