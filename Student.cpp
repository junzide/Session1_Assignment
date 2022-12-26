//
// Created by junzite on 12/24/2022.
//

#include "Student.h"

#include <utility>

void Ajunie::Student::readData(std::string_view name, std::string_view studentID, std::string_view Class, const std::vector<float>& Grades) {
    Person::readData(name);
    m_student_id_ = studentID;
    m_student_class_ = Class;
    for (size_t i {}; auto &val : Grades) {
        m_grades_[i++].second = val;
    }

}

bool Ajunie::Student::isFail() const {
    for (const auto& i : m_grades_) {
        if (i.first == "Chinese" || i.first == "Math" || i.first == "English") {
            if (i.second < 89.0) {
                return true;
            } else {
                continue;
            }
        }
        if (i.second < 60.0) {
            return true;
        }
    }

    return false;
}

std::string_view Ajunie::Student::getStudentID() const {
    return m_student_id_;
}

std::string_view Ajunie::Student::getStudentClass() const {
    return m_student_class_;
}

double Ajunie::Student::getTotalScores() {
    double total_scores_ {};
    for (const auto& i : m_grades_) {
        total_scores_ += i.second;
    }
    return total_scores_;
}

std::array<std::pair<std::string, float>, 9> Ajunie::Student::getGrades() const {
    return m_grades_;
}

std::string Ajunie::Student::getFormatInfo() {
    m_format_info_ = m_student_id_ + ' ' + getName() + ' ' + m_student_class_ + ' ';
    for (auto& i : m_grades_) {
        m_format_info_ += std::to_string(i.second) + ' ';
    }
    m_format_info_ += '\n';
    //m_format_info_.erase(m_format_info_.length() - 2);
    return m_format_info_;
}

void Ajunie::Student::show_info() const {
    std::cout << std::endl;
    std::cout << std::format("{:#^30}\n", '#');
    std::cout << std::format("Name: {}\n", getName());
    std::cout << std::format("ID: {}\n", m_student_id_);
    std::cout << std::format("Class: {}\n", m_student_class_);
}

void Ajunie::Student::setID() {
    std::cout << std::format("{}{:<30}\n", "Origin ID: ", m_student_id_);
    std::cout << std::format("{:#^30}\n: ", "Input the ID");
    std::getline(std::cin, m_student_id_);
}

void Ajunie::Student::setClass() {
    std::cout << std::format("{}{:<30}\n", "Origin Class: ", m_student_class_);
    std::cout << std::format("{:#^30}\n: ", "Input the class");
    std::getline(std::cin, m_student_class_);
}

void Ajunie::Student::setGrades() {
    std::cout << std::format("{:#^30}\n", "Origin Grades ");
    std::cout << std::format("{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}\n", "Chinese", "Math", "English", "Physics", "Chemistry", "Biology", "Politics", "History", "Geography");
    std::cout << std::format("  {:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}\n", m_grades_[0].second, m_grades_[1].second, m_grades_[2].second, m_grades_[3].second, m_grades_[4].second, m_grades_[5].second, m_grades_[6].second, m_grades_[7].second, m_grades_[8].second);
    std::cout << std::format("{:#^30}\n", "Input the grades");
//    std::cout << "In the order of \"Chinese\", \"Math\", \"English\", \"Physics\", \"Chemistry\", \"Biology\", \"Politics\", \"History\", \"Geography\"\n";
    for (auto& val : m_grades_) {
        std::cout << std::format("{}: ", val.first);
        std::cin >> val.second;
    }
}

Ajunie::Student::Student(std::string ID) {
    m_student_id_ = std::move(ID);
}

bool Ajunie::Student::operator==(const Ajunie::Student &rhs) const {
    return m_student_id_ == rhs.m_student_id_;
}

bool Ajunie::Student::operator>(const Ajunie::Student &rhs) const {
    return m_student_id_ > rhs.m_student_id_;
}

bool Ajunie::Student::operator<(const Ajunie::Student &rhs) const {
    return m_student_id_ < rhs.m_student_id_;
}

Ajunie::Student::Student() {
    m_grades_[0].first = "Chinese";
    m_grades_[1].first = "Math";
    m_grades_[2].first = "English";
    m_grades_[3].first = "Physics";
    m_grades_[4].first = "Chemistry";
    m_grades_[5].first = "Biology";
    m_grades_[6].first = "Politics";
    m_grades_[7].first = "History";
    m_grades_[8].first = "Geography";
}
