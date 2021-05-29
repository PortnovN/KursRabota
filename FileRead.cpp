#include "FileRead.h"
#include "Crypt.h"
#include "student.h"
#include "myList.h"
#include <fstream>
#include <sstream>

myList fOpen(string fileName) {
    string line;
    myList people;
    // Crypt encrypt("3igcZhRdWq96m3GUmTAiv9");
    ifstream file;
    file.open(fileName, ios_base::binary);
    if (!file.good()) {
        cout << "Возникла проблема с открытием. Будет создан новый файл.\n";
        return(people);
    }
    string str;
   // istringstream dec(str = encrypt.decrypt(file));
     /* while (!(dec.eof())) {
        getline(dec, line);
        istringstream studLine(line);
        person.read(studLine);
        if (!(dec.eof()))
            people.push_back(person);
    } 
        file.close(); */
    
    while (!(file.eof())) {
        student person;
        getline(file, line);
        istringstream studLine (line);
        person.read(studLine);
        if (!(file.eof()))
            people.push_back(person);
    }
    file.close(); 
    return(people);
}


/* else {
     while (!(file.eof())) {
         person.read(file);
         if (!(file.eof()))
             people.push_back(person);
     }
     file.close();
 }; */
