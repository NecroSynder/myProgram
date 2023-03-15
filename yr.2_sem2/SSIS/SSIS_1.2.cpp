#include <iostream>
#include <string>
#include <map>
using namespace std;

class Student {
    private:
        string name;
        int id;
    public:
        Student(string n, int i) {
            name = n;
            id = i;
        }
        string getName() {
            return name;
        }
        int getId() {
            return id;
        }
};

class StudentList {
    private:
        map<int, Student*> students;
    public:
        void addStudent(Student* s) {
            students[s->getId()] = s;
        }
        void deleteStudent(int id) {
            students.erase(id);
        }
        void editStudent(int id, Student* s) {
            students[id] = s;
        }
        void showList() {
            for (auto const& [id, student] : students) {
                cout << "Name: " << student->getName() << " | ID: " << id << endl;
            }
        }
        Student* searchByName(string name) {
            for (auto const& [id, student] : students) {
                if (student->getName() == name) {
                    return student;
                }
            }
            return NULL;
        }
        Student* searchById(int id) {
            return students[id];
        }
};

int main() {
    StudentList sl;
    int choice, id;
    string name;
    while (true) {
        cout << "Choose an option:" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Delete student" << endl;
        cout << "3. Edit student" << endl;
        cout << "4. Show student list" << endl;
        cout << "5. Search student by name" << endl;
        cout << "6. Search student by ID" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;
        cin.ignore(); // ignore the newline character left in the input stream
        switch(choice) {
            case 1:
                cout << "Enter student name: ";
                getline(cin, name);
                cout << "Enter student ID: ";
                cout << "Only 10 numbers are allowed";
                cin >> id;
                sl.addStudent(new Student(name, id));
                break;
            case 2:
                cout << "Enter student ID to delete: ";
                cin >> id;
                sl.deleteStudent(id);
                break;
            case 3:
                cout << "Enter student ID to edit: ";
                cin >> id;
                cout << "Enter new student name: ";
                getline(cin, name);
                sl.editStudent(id, new Student(name, id));
                break;
            case 4:
                sl.showList();
                break;
            case 5:
                cout << "Enter student name to search: ";
                getline(cin, name);
                if (sl.searchByName(name) == NULL) {
                    cout << "Student not found." << endl;
                } else {
                    cout << "Name: " << sl.searchByName(name)->getName() << " | ID: " << sl.searchByName(name)->getId() << endl;
                }
                break;
            case 6:
                cout << "Enter student ID to search: ";
                cin >> id;
                if (sl.searchById(id) == NULL) {
                    cout << "Student not found." << endl;
                } else {
                    cout << "Name: " << sl.searchById(id)->getName() << " | ID: " << sl.searchById(id)->getId() << endl;
                }
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice." << endl;
        }
        cin.ignore(); // ignore the newline character left in the input stream
    }
    return 0;
}