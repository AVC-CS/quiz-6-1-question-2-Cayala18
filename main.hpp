#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int writeFile(const string& filename) {
    ofstream ofs(filename);
    if (!ofs) {
        cout << "File Open Error\n";
        exit(0);
    }

    int num;
    cout << "Enter the number of employees: ";
    cin >> num;
    ofs << num << endl;

    for (int i = 0; i < num; i++) {
        int ID;
        string name, department;
        double salary;

        cout << "Enter employee ID: ";
        cin >> ID;
        ofs << ID << "\t";
        cout << "Enter employee name: ";
        cin >> name;
        ofs << name << "\t";
        cout << "Enter employee department: ";
        cin >> department;
        ofs << department << "\t";
        cout << "Enter employee salary: ";
        cin >> salary;
        ofs << salary << endl;
    }

    ofs.close();
    return num;
}

int readFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "File Open Error\n";
        exit(0);
    }

    int num, ID, total = 0;
    double salary;
    string name, department;

    ifs >> num;
    cout << "\nEmployee Information from file:\n";
    for (int i = 0; i < num; i++) {
        ifs >> ID >> name >> department >> salary;
        cout << ID << "\t" << name << "\t" << department << "\t" << salary << endl;
        total += salary;
    }

    int avg = (num > 0) ? total / num : 0;
    cout << "Total combined salary: " << total << "\t" << "Average salary: " << avg << endl;

    ifs.close();
    return num;
}