#include "SSIS_Constructor3.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
  StudentList list;
  int choice;
  do {
    cout << "\n\n1. Add student\n";
    cout << "2. Delete student\n";
    cout << "3. Edit student\n";
    cout << "4. Show list\n";
    cout << "5. Search by name\n";
    cout << "6. Search by course\n";
    cout << "7. Search by ID\n";
    cout << "8. Exit\n\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
    case 1: {
      string name, course;
      int id;
      cout << "Enter name: ";
      cin.ignore();
      getline(cin, name);
      cout << "Enter course: ";
      cin >> course;
      cout << "Enter ID: ";
      cin >> id;
      Student *s = new Student(name, course, id);
      list.addStudent(s);
      cout << "Student added successfully\n";
      break;
    }
    case 2: {
      int id;
      cout << "Enter ID: ";
      cin >> id;
      list.deleteStudent(id);
      cout << "Student deleted successfully\n";
      break;
    }
    case 3: {
      int id;
      cout << "Enter ID: ";
      cin >> id;
      Student *s = list.searchById(id);
      if (s == nullptr) {
        cout << "Student not found\n";
      } else {
        string name, course;
        cout << "Enter new name (press enter to keep the old name): ";
        cin.ignore();
        getline(cin, name);
        if (name.empty()) {
          name = s->getName();
        }
        cout << "Enter new course (press enter to keep the old course): ";
        getline(cin, course);
        if (course.empty()) {
          course = s->getCourse();
        }
        Student *new_s = new Student(name, course, id);
        list.editStudent(id, new_s);
        cout << "Student edited successfully\n";
      }
      break;
    }
    case 4: {
      list.showList();
      break;
    }
    case 5: {
      string name;
      cout << "Enter name: ";
      cin >> name;
      Student *s = list.searchByName(name);
      if (s == nullptr) {
        cout << "Student not found\n";
      } else {
        cout << "Name: " << s->getName() << " | Course: " << s->getCourse()
             << " | ID: " << s->getId() << endl;
      }
      break;
    }
    case 6: {
      string course;
      cout << "Enter course: ";
      cin >> course;
      Student *s = list.searchByCourse(course);
      if (s == nullptr) {
        cout << "Student not found\n";
      } else {
        cout << "Name: " << s->getName() << " | Course: " << s->getCourse()
             << " | ID: " << s->getId() << endl;
      }
      break;
    }
    case 7: {
      int id;
      cout << "Enter ID: ";
      cin >> id;
      Student *s = list.searchById(id);
      if (s == nullptr) {
        cout << "Student not found\n";
      } else {
        cout << "Name: " << s->getName() << " | Course: " << s->getCourse()
             << " | ID: " << s->getId() << endl;
      }
      break;
    }
    case 8: {
      cout << "Exiting...\n";
      break;
    }
    }

  } while (choice != 8);
  return 0;
}
