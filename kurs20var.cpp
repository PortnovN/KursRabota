#include "FileRead.h"
#include "Crypt.h"
#include "myList.h"
#include "Enter.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <locale.h>
#include <fstream>
#include <sstream>

bool compaire(const student& stud1, const student& stud2) { 
    return stud1.surname < stud2.surname;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string fileName;
    int function;
    student person;
    int i;
    int studEdit;
    int numEdit;
    int studDel;
    int semestr;
    string studFind;
    cout << "Для начала работы с программой введите имя файла:  ";
    cin >> fileName;
    myList people=fOpen(fileName);
    
    do {
        cout << "Рабочий файл: " << fileName << endl;
        cout << " _______________________\n";
        cout << "|                       | \n";
        cout << "|      ГЛАВНОЕ МЕНЮ     |\n";
        cout << "|_______________________|\n";
        cout << "Выбор действия с файлом:\n";
        cout << "1. Добавить нового студента\n";
        cout << "2. Редактировать запись о студенте\n";
        cout << "3. Удалить студента из БД\n";
        cout << "4. Найти студента\n";
        cout << "5. Вывод БД на экран\n";
        cout << "6. Задание\n";
        cout << "7. Выход из программы\n";
        function = numEnter(cin);
        system("cls");
        switch (function) {
        case 1: person.addStudent();
            people.push_back(person);
            break;
        case 2: if (people.size() == 0){
            cout << "Список студентов пуст. Возврат в главное меню...\n";
                break;
        }
            i = 1;
            for (auto write = people.begin(); write != people.end(); write++, i++) {
                cout << i << ". ";
                write->write(cout);
            };
            cout << "Выбери номер записи для редактирования: ";
            studEdit = numEnter(cin);
            i = 1;
            for (auto write = people.begin(); write != people.end(); write++, i++) {
                if (i == studEdit) {
                    cout << "Что вы хотите отредактировать?\n";
                    cout << "1. Фамилия студента \n";
                    cout << "2. Имя студента \n";
                    cout << "3. Отчество студента \n";
                    cout << "4. Дата рождения студента \n";
                    cout << "5. Год начала обучения \n";
                    cout << "6. Факультет \n";
                    cout << "7. Кафедра \n";
                    cout << "8. Группа \n";
                    cout << "9. Номер зачетной книжки \n";
                    cout << "10.Пол \n";
                    cout << "11.Оценки \n";
                    cout << "12.Добавить оценки нового для нового семестра\n";
                    numEdit = numEnter(cin);
                    switch (numEdit) {
                    case 1: cout << "Введите новую информацию >> ";
                        cin >> write->surname;
                        break;
                    case 2: cout << "Введите новую информацию >> ";
                        cin >> write->name;
                        break;
                    case 3: cout << "Введите новую информацию >> ";
                        cin >> write->middleName;
                        break;
                    case 4: cout << "Введите новую информацию >> ";
                        cin >> write->birthday;
                        break;
                    case 5: cout << "Введите новую информацию >> ";
                        write->startYear = numEnter(cin);
                        break;
                    case 6: cout << "Введите новую информацию >> ";
                        cin >> write->faculty;
                        break;
                    case 7: cout << "Введите новую информацию >> ";
                        cin >> write->cathedra;
                        break;
                    case 8: cout << "Введите новую информацию >> ";
                        cin >> write->group;
                        break;
                    case 9: cout << "Введите новую информацию >> ";
                        cin >> write->studID;
                        break;
                    case 10: cout << "Введите новую информацию >> ";
                        cin >> write->sex;
                        break;
                    case 11: cout << "Выберите семестр: \n";
                        semestr = numEnter(cin);
                        cout << "Выберите номер предмета: \n";
                        i = 1;
                        for (auto mark = write->marks[semestr - 1].begin(); mark != write->marks[semestr - 1].end(); mark++, i++)
                            cout << i << ". " << mark->name << " " << mark->mark << endl;
                        numEdit = numEnter(cin);
                        i = 1;
                        for (auto mark = write->marks[semestr - 1].begin(); mark != write->marks[semestr - 1].end(); mark++, i++)
                            if (i == numEdit) {
                                cout << "Введите новую оценку: \n";
                                mark->mark = numEnter(cin);
                                break;
                            };
                        break;
                    case 12: 
                        lessons lesName;
                        for (i = 0; i < 9; i++)
                        if (write->marks[i].size() == 0)
                            break;
                        if (i == 9) {
                            cout << "Свободные семестры отсутствуют!";
                                break;
                        }
                        cout << " ____________________________\n";
                        cout << "|                            | \n";
                        cout << "|      Ввод новых оценок     |\n";
                        cout << "|     Для выхода введите 0   | \n";
                        cout << "|____________________________|\n";
                        while (1) {
                        cout << "Введите название предмета: \n";
                        cin >> lesName.name;
                        if (lesName.name == "0")
                            break;
                        cout << "Введите оценку:  \n";
                        lesName.mark = numEnter(cin);
                        write->marks[i].push_back(lesName);
                        }
                        break;
                    }
                    break;
                }
            }
            break;
        case 3:if (people.size() == 0) {
            cout << "Список студентов пуст. Возврат в главное меню...\n";
            break;}
            i = 1;
            for (auto write = people.begin(); write != people.end(); write++, i++) {
                cout << i << ". ";
                write->write(cout);
            };
            cout << "Выбери номер записи для удаления: ";
            studDel = numEnter(cin);
            i = 1;
            for (auto write = people.begin(); write != people.end(); write++, i++) {
                if (i == studDel) { people.erase(write); break; }
            }
            break;
        case 4:if (people.size() == 0) {
            cout << "Список студентов пуст. Возврат в главное меню...\n";
            break;
        }
            cout << "Введите номер зачетной книжки или фамилию для поиска студента: ";
            cin >> studFind;
            for (auto write = people.begin(); write != people.end(); write++) {
                if (studFind == write->studID) {
                    write->write(cout);
                    break;
                };
                if (studFind == write->surname) {
                    write->write(cout);

                };
            }
            break;
        case 5: if (people.size() == 0) {
            cout << "Список студентов пуст. Возврат в главное меню...\n";
            break;
        }
            i = 1;
            for (auto write = people.begin(); write != people.end(); write++, i++) {
                cout << i << ". ";
                write->write(cout);
            }
            break;
        case 6: if (people.size() == 0) {
            cout << "Список студентов пуст. Возврат в главное меню...\n";
            break;
        }
            cout << "Введите номер семестра от 1 до 9: \n";
            int sortSem;
            while (1) {
                sortSem = numEnter(cin);
                if (sortSem >= 1 && sortSem <= 9) {
                    sortSem--;
                    break;}
                cout << "Диапазон от 1 до 9. Введите еще раз...\n";
            }
            cout << "Отличники: \n";
            myList excellent;
            for (auto write = people.begin(); write != people.end(); write++) {
                bool cancel = true;
                for (auto mark = write->marks[sortSem].begin(); mark != write->marks[sortSem].end(); mark++) {
                    if (mark->mark != 5) {
                        cancel = false;
                        break;
                    }
                }
                if(cancel == true)
                excellent.push_back(*write);
            }
            excellent.sort(compaire);
            for (auto write = excellent.begin(); write != excellent.end(); write++) {
                write->write(cout);
               }
            cout << " \n";
            cout << "Отличники и хорошисты: \n";
            myList between;
            for (auto write = people.begin(); write != people.end(); write++) {
                bool cancel = true;
                for (auto mark = write->marks[sortSem].begin(); mark != write->marks[sortSem].end(); mark++) {
                    if (mark->mark < 4) {
                        cancel = false;
                        break;
                    }
                }
                if (cancel == true)
                    between.push_back(*write);
            }
            between.sort(compaire);
            for (auto write = between.begin(); write != between.end(); write++) {
                write->write(cout);
            }\
            cout << " \n";
            cout << "Хорошисты и троечники: \n";
            myList bad;
            for (auto write = people.begin(); write != people.end(); write++) {
                bool cancel = true;
                for (auto mark = write->marks[sortSem].begin(); mark != write->marks[sortSem].end(); mark++) {
                    if (mark->mark >3 && mark->mark >4) {
                        cancel = false;
                        break;
                    }
                }
                if (cancel == true)
                    bad.push_back(*write);
            }
            bad.sort(compaire);
            for (auto write = bad.begin(); write != bad.end(); write++) {
                write->write(cout);
            }
            break;
       };
    } while (function != 7);
    ofstream fileWrite;
    fileWrite.open(fileName, ios_base::binary);
    ostringstream inFlow;
    for (auto write = people.begin(); write != people.end(); write++)
        write->write(fileWrite);
    /* encrypt.save(inFlow.str(), fileWrite); */
    return 0;
};


    