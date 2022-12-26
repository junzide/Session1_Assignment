//
// Created by junzite on 12/24/2022.
//

#include "Person.h"

std::string Ajunie::Person::getName() const {
    return m_name_;
}

void Ajunie::Person::readData(std::string_view name) {
    m_name_ = name;
}

void Ajunie::Person::setName() {
    std::cout << std::format("{}{:<30}\n", "Origin Name: ", m_name_);
    std::cout << std::format("{:#^30}\n: ", "Input the name");
    std::getline(std::cin, m_name_);
}
