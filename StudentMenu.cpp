//
// Created by junzite on 12/24/2022.
//

#include "StudentMenu.h"

void Ajunie::StudentMenu::run() {
    while (true) {
        readData();
        for (const auto& val : m_Classes_) {
            if (val.getStudentID() == m_num_) {
                m_self_ = val;
            }
        }
        auto option {menu()};

        switch (option) {
            case Exit :
                return;
            case ModifyName :
                modifyName();
                continue;
            case ViewGrades :
                viewGrades();
                continue;
            default:
                std::cerr << "Invalid Option!" << std::endl;
                system("pause");
                std::cout << std::endl;
                break;
        }
    }
}

size_t Ajunie::StudentMenu::menu() {
    system("cls");
    size_t option {};
    m_self_.show_info();
    std::cout << std::format("{:#^30}\n", "Student Manage Menu");
    std::cout << std::format("{:*<30}\n", "0. Exit");
    std::cout << std::format("{:*<30}\n", "1. Modify name");
    std::cout << std::format("{:*<30}\n", "2. Display grades");
    std::cout << std::format("{:#<30}\n", '#');
    std::cout << "Choose An Option: ";
    std::cin >> option;
    std::cin.clear();
    std::cin.ignore();

    return option;
}

void Ajunie::StudentMenu::readData() {
    m_students_info_in_.open(m_path_students_info_, std::ios::in);
    if (!m_students_info_in_.is_open()) {
        std::cerr << "Failed to open" << m_path_students_info_ << std::endl;
        system("pause");
        std::cout << std::endl;
        exit(-1);
    }

    std::string temp;
    while(std::getline(m_students_info_in_, temp)/*!m_students_info_in_.eof()*/) {
//        std::string temp;
        Student Gakuse;
//        std::getline(m_students_info_in_, temp);
        size_t start {0};
        auto end {temp.find_first_of(' ')};
        auto id {temp.substr(start, end)};
        start = temp.find_first_not_of(' ', end + 1);
        end = temp.find_first_of(' ',start + 1);
        auto name {temp.substr(start, end - start)};
        start = temp.find_first_not_of(' ', end + 1);
        end = temp.find_first_of(' ',start + 1);
        auto Class {temp.substr(start, end - start)};
        start =  temp.find_first_not_of(' ', end + 1);

        std::vector<float> grades {};
        while (start != std::string::npos) {
            end = temp.find_first_of(' ', start + 1);
            if (end == std::string::npos) {
                end = temp.length();
            }
            grades.push_back(std::stof(temp.substr(start, end - start)));
            start = temp.find_first_not_of(' ', end + 1);
        }

        Gakuse.readData(name, id, Class, grades);
        m_Classes_.push_back(Gakuse);
    }
    m_students_info_in_.close();
}

void Ajunie::StudentMenu::writeData() {
    m_students_info_out_.open(m_path_students_info_, std::ios::trunc | std::ios::out);
    if (!m_students_info_out_.is_open()) {
        std::cerr << "Failed to open" << m_path_students_info_ << std::endl;
        system("pause");
        std::cout << std::endl;
        exit(-1);
    }

    for (auto& val : m_Classes_) {
        auto info = val.getFormatInfo();
        m_students_info_out_.write(info.c_str(), info.length());
    }

    m_students_info_out_.close();
}

void Ajunie::StudentMenu::modifyName() {
    system("cls");
    auto it {std::find(m_Classes_.begin(), m_Classes_.end(), m_self_)};
    if (it != m_Classes_.end()) {
        it->setName();
        writeData();
        system("pause");
        system("cls");
    } else {
        std::cerr << "Not Found!" << std::endl;
        system("pause");
    }
}

void Ajunie::StudentMenu::viewGrades() {
    system("cls");
    std::cout << std::format("{:-^12}|{:-^15}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}\n", "ID", "Name", "Class", "Chinese", "Math", "English", "Physics", "Chemistry", "Biology", "Politics", "History", "Geography", "Total");
    auto grades {m_self_.getGrades()};
    std::cout << std::format("{:^12}|{:^15}|{:^9}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}\n", m_self_.getStudentID(), m_self_.getName(), m_self_.getStudentClass(), grades[0].second, grades[1].second, grades[2].second, grades[3].second, grades[4].second, grades[5].second, grades[6].second, grades[7].second, grades[8].second, m_self_.getTotalScores());
    system("pause");
    system("cls");
}
