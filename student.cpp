#include "student.h"
#include "Enter.h"

void student::addStudent() {
    cout << "Введите данные нового студента: \n";
    cout << "Фамилия студента: ";
    cin >> surname;
    cout << "Имя студента: ";
    cin >> name;
    cout << "Отчество студента: ";
    cin >> middleName;
    cout << "Дата рождения студента: ";
    cin >> birthday;
    cout << "Год начала обучения: ";
    startYear = numEnter(cin);
    cout << "Факультет: ";
    cin >> faculty;
    cout << "Кафедра: ";
    cin >> cathedra;
    cout << "Группа: ";
    cin >> group;
    cout << "Номер зачетной книжки: ";
    cin >> studID;
    cout << "Пол: ";
    cin >> sex;


}