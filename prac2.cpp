#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:
    // Default constructor
    Student() : rollNumber(0), division('A') {}

    // Parameterized constructor
    Student(string n, int r, string c, char d, string dob, string bg, string ca, string tn, string dl)
        : name(n), rollNumber(r), studentClass(c), division(d), dateOfBirth(dob),
          bloodGroup(bg), contactAddress(ca), telephoneNumber(tn), drivingLicenseNo(dl) {}

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        studentClass = other.studentClass;
        division = other.division;
        dateOfBirth = other.dateOfBirth;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
    }

    // Destructor
    ~Student() {}

    // Static member function to display student count (just for demonstration)
    static void displayStudentCount(int count) {
        cout << "Total students: " << count << endl;
    }

    // Friend function to display student information
    friend void displayStudentInfo(const Student& s);

    // Member function to set student information
    void setStudentInfo(string n, int r, string c, char d, string dob, string bg, string ca, string tn, string dl) {
        name = n;
        rollNumber = r;
        studentClass = c;
        division = d;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = ca;
        telephoneNumber = tn;
        drivingLicenseNo = dl;
    }

    // Member function to get the student name
    string getName() const {
        return name;
    }
};

// Friend function implementation
void displayStudentInfo(const Student& s) {
    cout << "Name: " << s.name << endl;
    cout << "Roll Number: " << s.rollNumber << endl;
    cout << "Class: " << s.studentClass << endl;
    cout << "Division: " << s.division << endl;
    cout << "Date of Birth: " << s.dateOfBirth << endl;
    cout << "Blood Group: " << s.bloodGroup << endl;
    cout << "Contact Address: " << s.contactAddress << endl;
    cout << "Telephone Number: " << s.telephoneNumber << endl;
    cout << "Driving License No: " << s.drivingLicenseNo << endl;
}

class StudentDatabase {
private:
    Student* students;
    int size;
    int capacity;

public:
    // Constructor
    StudentDatabase(int cap) : size(0), capacity(cap) {
        students = new Student[capacity];
    }

    // Destructor
    ~StudentDatabase() {
        delete[] students;
    }

    // Function to add a student
    void addStudent(const Student& s) {
        if (size < capacity) {
            students[size++] = s;
        } else {
            throw overflow_error("Database is full. Cannot add more students.");
        }
    }

    // Function to display all students
    void displayAllStudents() {
        for (int i = 0; i < size; ++i) {
            displayStudentInfo(students[i]);
            cout << "-----------------------" << endl;
        }
        Student::displayStudentCount(size);
    }
};

int main() {
    try {
        StudentDatabase db(5); // Create a database with capacity for 5 students

        // Adding students
        db.addStudent(Student("Alice Johnson", 101, "10th", 'A', "2005-05-15", "O+", "123 Maple St", "1234567890", "DL12345"));
        db.addStudent(Student("Bob Smith", 102, "10th", 'A', "2005-06-20", "A+", "456 Oak St", "0987654321", "DL12346"));
        
        // Displaying all students
        db.displayAllStudents();

    } catch (const exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}

