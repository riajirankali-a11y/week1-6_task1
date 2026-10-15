#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    double marks;
    static int studentCount;

public:
    // Parameterized constructor
    Student(int r, const string& n, double m)
        : rollNo(r), name(n), marks(m) {
        ++studentCount;
    }

    // Overloaded display functions
    void display() const {
        cout << "Roll No: " << rollNo
             << ", Name: " << name
             << ", Marks: " << marks << "/100" << '\n';
    }

    void display(const string& heading) const {
        cout << heading << '\n';
        display();
    }

    double getMarks() const {
        return marks;
    }

    // Static member function
    static int getStudentCount() {
        return studentCount;
    }

    // Friend function can access private members
    friend void compareStudents(const Student& s1, const Student& s2);

    // Overloaded > operator compares students by marks
    bool operator>(const Student& other) const {
        return marks > other.marks;
    }
};

// Definition of the static data member
int Student::studentCount = 0;

void compareStudents(const Student& s1, const Student& s2) {
    cout << "\nFriend function comparison:\n";
    if (s1.marks > s2.marks) {
        cout << s1.name << " scored more than " << s2.name << ".\n";
    } else if (s2.marks > s1.marks) {
        cout << s2.name << " scored more than " << s1.name << ".\n";
    } else {
        cout << s1.name << " and " << s2.name << " scored equal marks.\n";
    }
}

int main() {
    // Dynamic memory allocation using new
    Student* s1 = new Student(101, "Aarav", 86.5);
    Student* s2 = new Student(102, "Diya", 92.0);
    Student* s3 = new Student(103, "Kiran", 78.0);

    cout << "STUDENT DETAILS\n";
    s1->display();
    s2->display("Student 2 details:");
    s3->display();

    cout << "\nTotal students created: "
         << Student::getStudentCount() << '\n';

    compareStudents(*s1, *s2);

    cout << "\nOperator > comparison:\n";
    if (*s2 > *s1) {
        cout << s2->getMarks() << " marks are greater than "
             << s1->getMarks() << " marks.\n";
    } else {
        cout << s1->getMarks() << " marks are greater than or equal to "
             << s2->getMarks() << " marks.\n";
    }

    // Release dynamically allocated memory
    delete s1;
    delete s2;
    delete s3;

    return 0;
}
