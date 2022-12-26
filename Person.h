//
// Created by junzite on 12/24/2022.
//

#ifndef SCHOOLSYSTEM_PERSON_H
#define SCHOOLSYSTEM_PERSON_H

#include <iostream>
#include <string>
#include <format>
#include <string_view>

namespace Ajunie {
    class Person {
    public:
        Person() = default;

        virtual void show_info() const = 0;
        void readData(std::string_view name);

        void setName();

        [[nodiscard]] std::string getName() const;

    private:
        std::string m_name_;
    };
}


#endif //SCHOOLSYSTEM_PERSON_H
