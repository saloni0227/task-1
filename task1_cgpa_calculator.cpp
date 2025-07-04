#include <iostream>
#include <map>
using namespace std;

int main() {
    int numCourses;
    float totalCredits = 0, totalGradePoints = 0;

    // Grade to point mapping
    map<char, int> gradeMap;
    gradeMap['A'] = 10;
    gradeMap['B'] = 9;
    gradeMap['C'] = 8;
    gradeMap['D'] = 7;
    gradeMap['E'] = 6;
    gradeMap['F'] = 0;

    cout << "Enter the number of courses: ";
    cin >> numCourses;

    for (int i = 1; i <= numCourses; i++) {
        char grade;
        float credit;

        cout << "\nCourse " << i << ":\n";
        cout << "Enter grade (A/B/C/D/E/F): ";
        cin >> grade;
        cout << "Enter credit hours: ";
        cin >> credit;

        // Check for valid grade
        if (gradeMap.find(grade) == gradeMap.end()) {
            cout << "Invalid grade entered. Try again.\n";
            i--; // redo this course
            continue;
        }

        totalGradePoints += gradeMap[grade] * credit;
        totalCredits += credit;
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\nTotal Credits: " << totalCredits << endl;
    cout << "Total Grade Points: " << totalGradePoints << endl;
    cout << "Your CGPA is: " << cgpa << endl;

    return 0;
}