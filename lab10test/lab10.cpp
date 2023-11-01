// Programmer: Michael Turner
// Student ID: 18229090
// Section: 305
// Date: 10/27/23
// File: CS1580Lab9.cpp 

#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
#include "HEADER.h"
using namespace std;

int main() {
	int students;
	string name;
	double score;
	double sum = 0;
	double avg;
	int passed = 0;
	int failed = 0;
	double min = 100;
	double max = 0;
	string maxName;
	string minName;
	char again;
	string pass;
	char ch;
	string userName;
	int sumASCII = 0;
	int position1;
	int position2;
	int guess;
	int attempts = 1;
	getUserName(userName);
	getUserId(pass);
	calculateASCIISum(pass, sumASCII);
	greetUser(userName, sumASCII);
	int static guessLimit = 10;
	if (sumASCII >= 150) {
		char choice;
		do {
			cout << "\n1. Calculate student statistics \n2. Display statistics \n3. Exit" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case '1':
				students = getNumberOfStudents();
				getStudentData(students, avg, score, max, min, name, minName, maxName, passed, failed, sum);
				break;
			case '2':
				displayStatistics(avg, score, max, min, name, minName, maxName, failed, passed);
				break;
			case '3':
				break;
			default:
				cout << "invalid input" << endl;
			}
		} while (choice != '3');

	}
	else if (sumASCII < 150) {
		char choice;
		do {
			cout << "\nMenu 1: Play Bug Smash game \nMenu 2: Exit program" << endl;
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
			case '1':
				attempts = 1;
				cout << "On a straight line, there exist 2 bugs laughing at you. Your objective is to smash the bug by guessing which position the bug is. If you guess the exact postion you smash the bug. You have "<< attempts <<" attempts to guess the bugs positions." << endl;
				position1 = positionOfBug();
				position2 = positionOfBug();
				do{
					guess = getUserGuess(attempts);
					catchTheBug(position1, guess);
                                        attempts++;
				}while (guess != position1 && attempts != guessLimit);
				if (guess == position1){
					swap(position1,position2);
					cout << "Congragulations you smashed the 1st bug, now smash the second. The other bug is laughing at you now" <<endl;
					 do{
                                        	guess = getUserGuess(attempts);
                                        	catchTheBug(position1, guess);
                                        	attempts++;
                                	}while (guess != position1 && attempts != guessLimit);
				}else if (attempts == guessLimit){
                                        cout << "You have ran out of attempts. The bugs are still laughing at you!"<< endl;
                                        break;
                                        }
				cout << "Congratulations! You smashed the bugs in " << attempts << " attempts" << endl;
				break;
			case '2':
				break;
			default:
				cout << "Invalid input" << endl;
			}
		} while (choice != '2');
	}
	exitProgram(userName);

}

