//
// Created by junzite on 12/24/2022.
//

#ifndef SCHOOLSYSTEM_STUDENT_H
#define SCHOOLSYSTEM_STUDENT_H

#include <format>
#include <string>
#include <vector>
#include <algorithm>
#include <array>
#include "Person.h"

namespace Ajunie {
    class Student : public Person {
    public:
        Student();

        explicit Student(std::string ID);

        void show_info() const override;
        void readData(std::string_view name, std::string_view studentID, std::string_view Class, const std::vector<float>& Grades);
        [[nodiscard]] bool isFail() const;

        void setID();
        void setClass();
        void setGrades();


        [[nodiscard]] std::string_view getStudentID() const;
        [[nodiscard]] std::string_view getStudentClass() const;
        double getTotalScores();
        [[nodiscard]] std::array<std::pair<std::string, float>, 9> getGrades() const;

        std::string getFormatInfo();

        bool operator==(const Student& rhs) const;
        bool operator>(const Student& rhs) const;
        bool operator<(const Student& rhs) const;

    private:
        std::string m_student_id_;
        std::string m_student_class_;
        std::array<std::pair<std::string, float>, 9> m_grades_ {};
        std::string m_format_info_;

    };
}


#endif //SCHOOLSYSTEM_STUDENT_H
