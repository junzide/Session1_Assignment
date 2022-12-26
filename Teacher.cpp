//
// Created by junzite on 12/24/2022.
//

#include "Teacher.h"

void Ajunie::Teacher::show_info() const {
    std::cout << std::endl;
    std::cout << std::format("{:#^30}\n", '#');
    std::cout << std::format("Teacher: {}\n", getName());
    std::cout << std::format("Teacher Num: {}\n", getTeacherID());
    std::cout << std::format("Class in charged: {}\n", getClass());
}

void Ajunie::Teacher::readData(std::string_view name, std::string_view teacherID, std::string_view Class) {
    Person::readData(name);
    m_teacher_id = teacherID;
    m_class_ = Class;
}

std::string Ajunie::Teacher::getTeacherID() const {
    return m_teacher_id;
}

std::string Ajunie::Teacher::getClass() const {
    return m_class_;
}

std::string Ajunie::Teacher::getFormatInfo() {
    m_format_info_ = m_teacher_id + ' ' + getName() + ' ' + m_class_;
    return m_format_info_;
}
