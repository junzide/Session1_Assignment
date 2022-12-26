//
// Created by junzite on 12/24/2022.
//

#include "TeacherMenu.h"

void Ajunie::TeacherMenu::run() {
    while (true) {
        readData();
        for (const auto& i : m_teachers_) {
            if (m_num == i.getTeacherID()) {
                m_teacher_ = i;
                break;
            }
        }
        auto option{menu()};

        switch (option) {
            case Exit :
                return;
            case ViewStudents :
                viewStudents();
                continue;
            case ViewStudentsFailed :
                viewStudentsFailed();
                continue;
            case SortStudentsGradesByTotal :
                sortStudents();
                continue;
            case AddStudent :
                addStudent();
                continue;
            case DeleteStudent :
                deleteStudent();
                continue;
            case ModifyStudent :
                modifyStudent();
                continue;
            case FindStudent :
                findStudent();
                continue;
            default :
                std::cerr << "Invalid Option!" << std::endl;
                system("pause");
                std::cout << std::endl;
                break;
        }
    }
}

size_t Ajunie::TeacherMenu::menu() {
    system("cls");
    size_t option {};

    m_teacher_.show_info();
    std::cout << std::format("{:#^30}\n", "Teacher Manage Menu");
    std::cout << std::format("{:*<30}\n", "0. Exit");
    std::cout << std::format("{:*<30}\n", "1. View Students' Basic Info");
    std::cout << std::format("{:*<30}\n", "2. View Students Failed");
    std::cout << std::format("{:*<30}\n", "3. Sort Students Grades");
    std::cout << std::format("{:*<30}\n", "4. Add Student");
    std::cout << std::format("{:*<30}\n", "5. Delete Student");
    std::cout << std::format("{:*<30}\n", "6. Modify Student");
    std::cout << std::format("{:*<30}\n", "7. Find a Student");
    std::cout << std::format("{:#<30}\n", '#');
    std::cout << "Choose An Option: ";
    std::cin >> option;
    std::cin.clear();
    std::cin.ignore();

    return option;
}

void Ajunie::TeacherMenu::readData() {
    m_teachers_info_in_.open(m_path_teachers_info_, std::ios::in);
    m_students_info_in_.open(m_path_students_info_, std::ios::in);
    if (!m_teachers_info_in_.is_open()) {
        std::cerr << "Failed to open" << m_path_teachers_info_ << std::endl;
        system("pause");
        std::cout << std::endl;
        exit(-1);
    }

    if (!m_students_info_in_.is_open()) {
        std::cerr << "Failed to open" << m_path_students_info_ << std::endl;
        system("pause");
        std::cout << std::endl;
        exit(-1);
    }
    std::string temp;
    while (std::getline(m_teachers_info_in_, temp)/*!m_teachers_info_in_.eof()*/) {
        Teacher sense;
//        std::getline(m_teachers_info_in_, temp);
        size_t start {0};
        auto end {temp.find_first_of(' ')};
        auto id {temp.substr(start, end - start)};
        start = temp.find_first_not_of(' ', end + 1);
        end = temp.find_first_of(' ', start + 1);
        auto name {temp.substr(start, end - start)};
        start = temp.find_first_not_of(' ', end + 1);
        end = temp.length();
        auto Class {temp.substr(start, end - start)};
        sense.readData(name, id, Class);
        m_teachers_.push_back(sense);
    }

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
    m_teachers_info_in_.close();
}

void Ajunie::TeacherMenu::writeData() {
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

void Ajunie::TeacherMenu::viewStudents() {
    system("cls");
    std::cout << std::format("{:-^12}|{:-^15}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}\n", "ID", "Name", "Class", "Chinese", "Math", "English", "Physics", "Chemistry", "Biology", "Politics", "History", "Geography", "Total");
    for (auto& val : m_Classes_) {
        if (val.getStudentClass() == m_teacher_.getClass()) {
            auto grades {val.getGrades()};
            std::cout << std::format("{:^12}|{:^15}|{:^9}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}\n", val.getStudentID(), val.getName(), val.getStudentClass(), grades[0].second, grades[1].second, grades[2].second, grades[3].second, grades[4].second, grades[5].second, grades[6].second, grades[7].second, grades[8].second, val.getTotalScores());
        }
    }
    system("pause");
}

void Ajunie::TeacherMenu::viewStudentsFailed() const {
    system("cls");
    std::cout << std::format("{:-^12}|{:-^15}|{:-^9}\n", "ID", "Name", "Class");
    for (const auto& val : m_Classes_) {
        if (val.getStudentClass() == m_teacher_.getClass()) {
            if (!val.isFail()) {
                continue;
            }
            std::cout << std::format("{:^12}|{:^15}|{:^9}\n", val.getStudentID(), val.getName(), val.getStudentClass());
        }
    }
    system("pause");
    system("cls");
}

void Ajunie::TeacherMenu::sortStudents() {
    while (true) {
        bool isSorted {false};
        for (size_t i {}; i < m_Classes_.size() - 1; ++i) {
            if (m_Classes_[i].getTotalScores() < m_Classes_[i + 1].getTotalScores()) {
                isSorted = true;
                std::swap(m_Classes_[i], m_Classes_[i + 1]);
            }
        }
        if (!isSorted) {
            break;
        }
    }
    system("cls");
    std::cout << std::format("{:-^12}|{:-^15}|{:-^8}|{:-^15}\n", "ID", "Name", "Class", "Total Points");
    for (auto& val : m_Classes_) {
        std::cout << std::format("{:^12}|{:^15}|{:^8}|{:^15.1f}\n", val.getStudentID(), val.getName(), val.getStudentClass(), val.getTotalScores());
    }
    system("pause");
    system("cls");
}

void Ajunie::TeacherMenu::addStudent() {
    system("cls");
    Student temp;
    temp.setID();
    temp.setName();
    temp.setClass();
    temp.setGrades();
    m_Classes_.push_back(temp);
    writeData();
    system("pause");
    system("cls");
}

void Ajunie::TeacherMenu::deleteStudent() {
    system("cls");
    std::string temp;
    std::cout << std::format("{:#^30}\n: ", "Input the ID");
    std::getline(std::cin, temp);
    auto it {std::find(m_Classes_.begin(), m_Classes_.end(), Student(temp))};
    if (it != m_Classes_.end()) {
        m_Classes_.erase(it);
        writeData();
        system("pause");
        system("cls");
    } else {
        std::cerr << "Not Found!" << std::endl;
        system("pause");
    }
}

void Ajunie::TeacherMenu::modifyStudent() {
    system("cls");
    std::string temp;
    std::cout << std::format("{:#^30}\n: ", "Input the ID");
    std::getline(std::cin, temp);
    auto it {std::find(m_Classes_.begin(), m_Classes_.end(), Student(temp))};
    if (it != m_Classes_.end()) {
        while (true) {
            std::cout << std::endl;
            std::cout << std::format("{:#^30}\n", "What do you want to modify");
            std::cout << std::format("{:-^30}\n", "0. Exit");
            std::cout << std::format("{:-^30}\n", "1. Name");
            std::cout << std::format("{:-^30}\n", "2. ID");
            std::cout << std::format("{:-^30}\n", "3. Class");
            std::cout << std::format("{:-^30}\n", "4. Grades");

            size_t option{};
            std::cout << ": ";
            std::cin >> option;
            std::cin.clear();
            std::cin.ignore();

            switch (option) {
                case 0 :
                    return;
                case 1 :
                    it->setName();
                    writeData();
                    continue;
                case 2 :
                    it->setID();
                    writeData();
                    continue;
                case 3 :
                    it->setClass();
                    writeData();
                    continue;
                case 4 :
                    it->setGrades();
                    writeData();
                    continue;
                default:
                    std::cerr << "Invalid Option!" << std::endl;
                    system("pause");
                    continue;
            }
        }
    } else {
        std::cerr << "Not Found!" << std::endl;
        system("pause");
    }
}

void Ajunie::TeacherMenu::findStudent() {
    system("cls");
    std::string temp;
    std::cout << std::format("{:#^30}\n: ", "Input the ID");
    std::getline(std::cin, temp);
    auto val {std::find(m_Classes_.begin(), m_Classes_.end(), Student(temp))};

    if (val != m_Classes_.end()) {
        std::cout << std::format(
                "{:-^12}|{:-^15}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}|{:-^9}\n", "ID",
                "Name", "Class", "Chinese", "Math", "English", "Physics", "Chemistry", "Biology", "Politics", "History",
                "Geography", "Total");
        auto grades{val->getGrades()};
        std::cout << std::format(
                "{:^12}|{:^15}|{:^9}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}|{:^9.2f}\n",
                val->getStudentID(), val->getName(), val->getStudentClass(), grades[0].second, grades[1].second,
                grades[2].second, grades[3].second, grades[4].second, grades[5].second, grades[6].second,
                grades[7].second, grades[8].second, val->getTotalScores());
        system("pause");
        system("cls");
    } else {
        std::cerr << "Not Found!" << std::endl;
        system("pause");
    }
}

