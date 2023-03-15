#include <iostream>
#include <map>
#include <string>

using namespace std;

class Student {
private:
  string name;
  string course;
  int id;

public:
  Student(string n, string c, int i) : name(n), course(c), id(i) {}
  string getName() { return name; }
  string getCourse() { return course; }
  int getId() { return id; }
};

class StudentList {
private:
  map<int, Student *> students;

public:
  void addStudent(Student *s) { students[s->getId()] = s; }
  void deleteStudent(int id) { students.erase(id); }
  void editStudent(int id, Student *s) { students[id] = s; }
  void showList() {
    for (auto const &[id, student] : students) {
      cout << "Name: " << student->getName()
           << " | Course: " << student->getCourse() << " | ID: " << id << endl;
    }
  }
  Student *searchByName(string name) {
    for (auto const &[id, student] : students) {
      if (student->getName() == name) {
        return student;
      }
    }
    return nullptr;
  }
  Student *searchByCourse(string course) {
    for (auto const &[id, student] : students) {
      if (student->getCourse() == course) {
        return student;
      }
    }
    return nullptr;
  }
  Student *searchById(int id) { return students[id]; }
};
