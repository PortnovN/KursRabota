#include "student.h"
#include "Enter.h"

void student::addStudent() {
    cout << "������� ������ ������ ��������: \n";
    cout << "������� ��������: ";
    cin >> surname;
    cout << "��� ��������: ";
    cin >> name;
    cout << "�������� ��������: ";
    cin >> middleName;
    cout << "���� �������� ��������: ";
    cin >> birthday;
    cout << "��� ������ ��������: ";
    startYear = numEnter(cin);
    cout << "���������: ";
    cin >> faculty;
    cout << "�������: ";
    cin >> cathedra;
    cout << "������: ";
    cin >> group;
    cout << "����� �������� ������: ";
    cin >> studID;
    cout << "���: ";
    cin >> sex;


}