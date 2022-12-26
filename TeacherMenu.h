//
// Created by junzite on 12/24/2022.
//

#ifndef SCHOOLSYSTEM_TEACHERMENU_H
#define SCHOOLSYSTEM_TEACHERMENU_H

#include <iostream>
#include <format>
#include <vector>
#include <fstream>
#include <filesystem>
#include "Teacher.h"
#include "Student.h"

namespace Ajunie {
    class TeacherMenu {
    public:
        explicit TeacherMenu(std::string_view num) : m_num{num} {}
        void run();
        size_t menu();
        void readData();
        void writeData();
        void viewStudents();
        void viewStudentsFailed() const;
        void sortStudents();
        void addStudent();
        void deleteStudent();
        void modifyStudent();
        void findStudent();

        enum menu_id {
            Exit,
            ViewStudents,
            ViewStudentsFailed,
            SortStudentsGradesByTotal,
            AddStudent,
            DeleteStudent,
            ModifyStudent,
            FindStudent
        };

        ~TeacherMenu() {writeData();}


    private:
        std::vector<Teacher> m_teachers_;
        std::vector<Student> m_Classes_;
        Teacher m_teacher_;
        std::ifstream m_teachers_info_in_;
        std::ofstream m_teachers_info_out_;
        std::ifstream m_teachers_account_in_;
        std::ofstream m_teachers_account_out_;
        std::ifstream m_students_info_in_;
        std::ofstream m_students_info_out_;
        std::ifstream m_students_account_in_;
        std::ofstream m_students_account_out_;
        const std::filesystem::path m_path_teachers_info_ {R"(.\assets\teachers_info.ajunie)"};
        const std::filesystem::path m_path_teachers_account_ {R"(.\assets\teachers_account.ajunie)"};
        const std::filesystem::path m_path_students_info_ {R"(.\assets\students_info.ajunie)"};
        const std::filesystem::path m_path_students_account_ {R"(.\assets\students_account.ajunie)"};
        std::string m_num;

    };
}


#endif //SCHOOLSYSTEM_TEACHERMENU_H
