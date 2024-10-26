#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int writeFile(const string& filename) {
    int empN;
    cout << "Enter the number of employees: ";
    cin >> empN;

    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error creating file!" << endl;
        return 0;
    }

    for (int i = 0; i < empN; ++i) {
        int id;
        string name, department;
        double salary;

        cout << "Enter Employee ID: ";
        cin >> id;
        cout << "Enter Employee Name: ";
        cin >> name;
        cout << "Enter Employee Department: ";
        cin >> department;
        cout << "Enter Employee Salary: ";
        cin >> salary;

        outFile << id << " " << name << " " << department << " " << salary << endl;
    }

    outFile.close();
    return empN;
}

int readFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file!" << endl;
        return 0;
    }

    int empN = 0;
    int id;
    string name, department;
    double salary;

    cout << "\nEmployee Information from file:\n";
    while (inFile >> id >> name >> department >> salary) {
        cout << "ID: " << id
             << ", Name: " << name
             << ", Department: " << department
             << ", Salary: " << salary << endl;
        empN++;
    }

    inFile.close();
    return empN;
}