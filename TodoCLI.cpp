// Author: Mashhood Ali
// To-Do CLI - Day 1 starter
// Add, list, mark done, delete, and save tasks to a file.

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Task {
private:
    string title;
    string status;

public:
    void setValues(string t, string s) {
        title = t;
        status = s;
    }

    string getTitle() {
        return title;
    }

    string getStatus() {
        return status;
    }

    void markDone() {
        status = "done";
    }

    void show(int number) {
        cout << number << ". [" << status << "] " << title << endl;
    }
};

Task tasks[100];
int count = 0;

void saveToFile() {
    ofstream file("tasks.txt");
    for (int i = 0; i < count; i++) {
        file << tasks[i].getTitle() << "|" << tasks[i].getStatus() << endl;
    }
    file.close();
}

void loadFromFile() {
    ifstream file("tasks.txt");
    string line;
    while (getline(file, line)) {
        int cut = line.find("|");
        if (cut == -1) {
            continue;
        }
        string title = line.substr(0, cut);
        string status = line.substr(cut + 1);
        tasks[count].setValues(title, status);
        count++;
    }
    file.close();
}

void showTasks() {
    if (count == 0) {
        cout << "No tasks yet." << endl;
    }
    else {
        for (int i = 0; i < count; i++) {
            tasks[i].show(i + 1);
        }
    }
}

int main() {
    loadFromFile();
    int choice = 0;

    while (choice != 5) {
        cout << endl;
        cout << "1. Add task" << endl;
        cout << "2. List tasks" << endl;
        cout << "3. Mark task done" << endl;
        cout << "4. Delete task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title;
            cout << "Enter task: ";
            getline(cin, title);
            tasks[count].setValues(title, "pending");
            count++;
            saveToFile();
            cout << "Task added." << endl;
        }
        else if (choice == 2) {
            showTasks();
        }
        else if (choice == 3) {
            int number;
            showTasks();
            cout << "Enter task number: ";
            cin >> number;
            if (number >= 1 && number <= count) {
                tasks[number - 1].markDone();
                saveToFile();
                cout << "Task marked done." << endl;
            }
            else {
                cout << "Wrong number." << endl;
            }
        }
        else if (choice == 4) {
            int number;
            showTasks();
            cout << "Enter task number: ";
            cin >> number;
            if (number >= 1 && number <= count) {
                for (int i = number - 1; i < count - 1; i++) {
                    tasks[i] = tasks[i + 1];
                }
                count--;
                saveToFile();
                cout << "Task deleted." << endl;
            }
            else {
                cout << "Wrong number." << endl;
            }
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Wrong choice, try again." << endl;
        }
    }

    return 0;
}
