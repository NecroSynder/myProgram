
  #include <cstdio>
  #include <fstream>
  #include <iostream>
  #include <map>
  #include <memory>
  #include <sstream>
  #include <string>
  #include <thread>

  using namespace std;

  class Student {
  private:
    string name;
    string course;
    int id;

  public:
    // Constructor
    Student(const string &n, const string &c, int i)
        : name(n), course(c), id(i) {}

    // Accessor functions (defined inline)
    inline string getName() const { return name; }
    inline string getCourse() const { return course; }
    inline int getId() const { return id; }

    // Mutator functions
    inline void setName(const string &n) { name = n; }
    inline void setCourse(const string &c) { course = c; }

  };

  class StudentList {
  private:
    map<int, shared_ptr<Student>> students;

  public:
    void addStudent(const shared_ptr<Student> &s) {
      students.emplace(s->getId(), s);
    }
    void deleteStudent(int id) { students.erase(id); }
    void editStudent(int id, shared_ptr<Student> s) { students[id] = s; }
    void showList(bool loadedFromFile = true) {
      if (!loadedFromFile) {
        cout << "\nAll Students:\n";
      } else {
        cout << "\nLoaded Students:\n";
      }
      for (auto const &[id, student] : students) {
        cout << "Name: " << student->getName() << " | Course: " << student->getCourse() << " | ID: " << id << endl;
      }
    }

    shared_ptr<Student> searchByName(const string &name) {
      for (auto const &[id, student] : students) {
        if (student->getName() == name) {
          return student;
        }
      }
      throw runtime_error("Student not found.");
    }
    shared_ptr<Student> searchByCourse(const string &course) {
      for (auto const &[id, student] : students) {
        if (student->getCourse() == course) {
          return student;
        }
      }
      throw runtime_error("Student not found.");
    }
    shared_ptr<Student> searchById(int id) {
      auto it = students.find(id);
      if (it == students.end()) {
        throw runtime_error("Student not found.");
      }
      return it->second;
    }
    void loadFromFile() {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      ifstream fin(fileName);
      ifstream courseFile("courses.txt");
      if (fin.is_open() && courseFile.is_open()) {
        int id;
        string name, course;
        while (fin >> id && getline(fin.ignore(), name, ',') &&
              getline(courseFile, course)) {
          fin.ignore(std::numeric_limits<std::streamsize>::max(),
                    '\n'); // ignore the newline character

          // remove newline character at the end of the course string
          if (!course.empty() && course.back() == '\r') {
            course = course.substr(0, course.size() - 1);
          }

          auto s = make_shared<Student>(name, course, id);
          addStudent(s);
        }
        fin.close();
        courseFile.close();
        cout << "Data loaded from files.\n";
      } else {
        cout << "Files not found, starting with an empty list.\n";
      }
    }

    void saveToFile() {
      string fileName;
      cout << "Enter file name: ";
      cin >> fileName;
      ofstream studentFile(fileName);
      ofstream courseFile("courses.txt");
      if (studentFile.is_open() && courseFile.is_open()) {
        for (auto const &[id, student] : students) {
          studentFile << student->getId() << "," << student->getName() << endl;
          courseFile << student->getCourse() << endl;
        }
        studentFile.close();
        courseFile.close();
        cout << "Data saved to files.\n";
      } else {
        cout << "Unable to save data to files.\n";
      }
    }
  };

  int main() {
    StudentList list;
    int choice;
    int Choice;
    cout << "Disclaimer:" << endl;
    cout << "\tWhen loading a file, you must input the filename with the file "
            "extension and only txt files."
        << endl;
    cout << "\tExample: trial.txt" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "\nDo you have a File to load? (1: Yes, 2: No): ";
    cin >> Choice;
    if (Choice == 1) {
      list.loadFromFile();
      list.showList(true); // display the loaded students
    }
    cout << "\nChoose an option from 1 to 10." << endl;
    do {
      cout << "1. Add student\n";
      cout << "2. Delete student\n";
      cout << "3. Edit Student Name or Course\n";
      cout << "4. Show list\n";
      cout << "5. Search by name\n";
      cout << "6. Search by course\n";
      cout << "7. Search by ID\n";
      cout << "8. Load from File\n";
      cout << "9. Save to file\n";
      cout << "10. Exit\n";
      cout << "Enter your choice: ";
      cin >> choice;
      switch (choice) {
      case 1: {
        string name, course;
        int id;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter course name: ";
        cin >> course;
        cout << "Enter ID: ";
        cin >> id;
        shared_ptr<Student> s = make_shared<Student>(name, course, id);
        list.addStudent(s);
        cout << "Student added.\n";
        break;
      }
      case 2: {
        int id;
        cout << "Enter student ID to delete: ";
        cin >> id;
        list.deleteStudent(id);
        cout << "Student deleted.\n";
        break;
      }
      case 3: {
        int id;
        cout << "Enter student ID to edit: ";
        cin >> id;
        shared_ptr<Student> s = list.searchById(id);
        if (s != nullptr) {
          cout << "What do you want to edit?" << endl;
          cout << "1. Name" << endl;
          cout << "2. Course" << endl;
          int editOption;
          cin >> editOption;
          if (editOption == 1) {
            string name;
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, name);
            s->setName(name);
          } else if (editOption == 2) {
            string course;
            cout << "Enter new course: ";
            cin.ignore();
            getline(cin, course);
            s->setCourse(course);
          } else {
            cout << "Invalid option. Student not edited.\n";
            break;
          }
          list.editStudent(id, s);
          cout << "Student edited.\n";
        } else {
          cout << "Student not found.\n";
        }
        break;
      }

      case 4:
        list.showList(); // display all students
        break;
      case 5: {
        string name;
        cout << "Enter student name to search: ";
        cin.ignore();
        getline(cin, name);
        shared_ptr<Student> s = list.searchByName(name);
        if (s != nullptr) {
          cout << "Name: " << s->getName() << " | Course: " << s->getCourse()
              << " | ID: " << s->getId() << endl;
        } else {
          cout << "Student not found.\n";
        }
        break;
      }
      case 6: {
        string course;
        cout << "Enter course to search: ";
        cin >> course;
        shared_ptr<Student> s = list.searchByCourse(course);
        if (s != nullptr) {
          cout << "Name: " << s->getName() << " | Course: " << s->getCourse()
              << " | ID: " << s->getId() << endl;
        } else {
          cout << "Student not found.\n";
        }
        break;
      }
      case 7: {
        int id;
        cout << "Enter ID to search: ";
        cin >> id;
        shared_ptr<Student> s = list.searchById(id);
        if (s != nullptr) {
          cout << "Name: " << s->getName() << " | Course: " << s->getCourse()
              << " | ID: " << s->getId() << endl;
        } else {
          cout << "Student not found.\n";
        }
        break;
      }
      case 8: {
        list.loadFromFile();
        break;
      }
      case 9: {
        list.saveToFile();
        break;
      }
      case 10:
        int saveChoice;
        cout << "Do you want to save the data to file again before exiting? (1: "
                "Yes, "
                "2: No): ";
        cin >> saveChoice;
        if (saveChoice == 1) {
          list.saveToFile();
        }
        cout << "Goodbye!\n";
        exit(0);
      }
    } while (choice != 10);
    return 0;
  }
