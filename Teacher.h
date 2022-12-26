//
// Created by junzite on 12/24/2022.
//

#ifndef SCHOOLSYSTEM_TEACHER_H
#define SCHOOLSYSTEM_TEACHER_H

#include <format>
#include <vector>
#include "Person.h"
#include "Student.h"

namespace Ajunie{
    class Teacher : public Person {
    public:
        Teacher() = default;

        void show_info() const override;
        void readData(std::string_view name, std::string_view teacherID, std::string_view Class);

        [[nodiscard]] std::string getTeacherID() const;
        [[nodiscard]] std::string getClass() const;

        std::string getFormatInfo();

    private:
        std::string m_teacher_id;
        std::string m_class_;
        std::string m_format_info_;
    };
}


#endif //SCHOOLSYSTEM_TEACHER_H
