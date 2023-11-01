#include "HEADER.h"
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;
void swap(int& position1, int& position2) {
        const int temp = position1;
        position1 = position2;
        position2 = temp;
        return;
}
bool validateInput(string guess) {
        const string validString1 = guess;
        for (int i = 0; i < validString1.length(); i++) {
                if ((validString1[i] == '1') || (validString1[i] == '2') || (validString1[i] == '3') ||(validString1[i] == '4') || (validString1[i] == '5') || (validString1[i] == '6') || (validString1[i] == '7') || (validString1[i] == '8') || (validString1[i] == '9') || (validString1[i] == '10')) {
                        return true;
                }
        }
        return false;
}

int getNumberOfStudents() {
        int students;
        cout << "Enter the number of students (1 - 100): ";
        cin >> students;
        while (students < 0 || students > 100) {// getting a valid input
                cout << "Invalid range. Please enter range 0-100:" << endl;
                cin >> students;
        }
        return students;
}
void getStudentData(int students, double& avg, double& score, double& max, double& min, string& name,string& minName, string& maxName, int& passed, int& failed, double& sum) {

        for (int i = students; i > 0; i--) {//for loop to get information about each student
                cout << "Enter name of student " << i << ": ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter score of student " << name << ": ";
                cin >> score;
                while (score < 0 || score > 100) { //entering a valid score
                        cout << "Invalid range. Please enter range 0-100:" << endl;
                        cin >> score;
                }
                if (score > max) {//getting max value
                        max = score;
                        maxName = name;
                }
                if (score < min) {//getting min value
                        min = score;
                        minName = name;
                }
                sum += score; //gathering sum for later use in avg
                cout << name << ": " << score << endl;
                if (score > 60) {
                        passed++;
                }
                else {
                        failed++;
                }
                avg = sum / students; //Equation for avg
        }
}

int positionOfBug() {
        int position;
        position = (rand() % 10 +1);
        return position;
}
int getUserGuess(int attempts) {
        string guessStr;
        do {
                cout << "Enter your guess (1-10) (Attempt "<< attempts<<"):"<< endl;
                cin >> guessStr;
        }while (validateInput(guessStr) == false);
        int guessInt = stoi(guessStr);
        return guessInt;
}

void catchTheBug(int position1, int guess) {
        if (guess > position1) {
                cout << "The bug is to the Left of your guess. Try a lower number." << endl;
        }
        else if (guess < position1) {
                cout << "The bug is to the right of your guess. Try a higher number." << endl;
        }
        return;
}
void displayStatistics(double avg, double score, double max, double min, string name, string minName, string maxName, int passed, int failed) {
	cout << "Class Statistics:\n" << "Max:" << max << " (student: " << maxName << ")\n" << "Min: " << min << " (student: " << minName << ")" << endl;
        cout << "Average Score: " << avg << endl;
        cout << "Number of students failed: " << failed << endl;
        cout << "Number of students passed: " << passed << endl;
}

void getUserName(string& userName) {
        cout << "Enter your name: ";
        cin >> userName;

}

void getUserId(string& pass) {
        do { //do while loop for input validation
                cout << "Enter your 5-character ID:";
                cin >> pass;
                if (pass.size() != 5) { //getting an input of 5 characters
                        cout << "Invalid input. Please enter 5 characters ";
                        cin >> pass;
                }
        } while (pass.size() != 5);
}

int calculateASCIISum(string& pass, int& sumASCII) {
        for (int i = 0; i < 3; i++) { //for loop for each character inserted
                int asciiValue = int(pass[i]);
                sumASCII += asciiValue;
        }
        return sumASCII;

}

void greetUser(string& userName, int& sumASCII) {
        if (sumASCII >= 150) {
                cout << "welcome teacher " << userName << endl;
        }
        else {
                cout << "welcome student " << userName << endl;
        }
        time_t now = time(0);
        char* dt = ctime(&now);
        cout << "you logged in at " << dt << endl;
}

int exitProgram(string userName) {
        cout << "Goodbye " << userName << endl;
        return 0;
}
