#include "Student.h"
#include <vector>
#include <algorithm>

//funktioiden alustaminen
Student::Student(std::string name, int age) : Name(name), Age(age) {}

void Student::setName(std::string name) { Name = name; }
void Student::setAge(int age) { Age = age; }

std::string Student::getName() const { return Name; }
int Student::getAge() const { return Age; }

void Student::printStudentInfo() const {
    std::cout << "Nimi:" << Name << " Ikä:" << Age << std::endl;
}

int main() {
    int selection = 0;
    std::vector<Student> studentList;

    do {
        std::cout << "\nSelect" << std::endl; //Jos ei ole rivivaihtoa tulostus on hankala lukea.
        std::cout << "Add students = 0" << std::endl;
        std::cout << "Print all students = 1" << std::endl;
        std::cout << "Sort and print students according to Name = 2" << std::endl;
        std::cout << "Sort and print students according to Age = 3" << std::endl;
        std::cout << "Find and print student = 4" << std::endl;
        std::cin >> selection;

        switch (selection) {
        case 0: {
            std::string name;
            int age;
            std::cout << "Opiskelijan nimi: ";
            std::cin >> name;
            std::cout << "Opiskelijan ikä: ";
            std::cin >> age;

            studentList.push_back(Student(name, age));
            break;
        }
        case 1:
            std::cout << "Opiskelija lista: \n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 2:
            std::sort(studentList.begin(), studentList.end(),
                [](const Student& a, const Student& b) {
                    return a.getName() < b.getName();
                });
            std::cout << "Opiskelijat järjestetty nimen mukaan:\n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 3:
            std::sort(studentList.begin(), studentList.end(),
                [](const Student& a, const Student& b) {
                    return a.getAge() < b.getAge();
                });
            std::cout << "Opiskelijat järjestetty iän mukaan:\n";
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 4: {
            std::string searchName;
            std::cout << "Anna etsittävä opiskelijan nimi: ";
            std::cin >> searchName;

            auto it = std::find_if(studentList.begin(), studentList.end(),
                [&searchName](const Student& student) {
                    return student.getName() == searchName;
                });

            if (it != studentList.end()) {
                std::cout << "Opiskelija löytyi:\n";
                it->printStudentInfo();
            }
            else {
                std::cout << "Opiskelijaa ei löytynyt.\n";
            }
            break;
        }
        default:
            std::cout << "Wrong selection, stopping...\n";
            break;
        }
    } while (selection < 5);

    return 0;
}
