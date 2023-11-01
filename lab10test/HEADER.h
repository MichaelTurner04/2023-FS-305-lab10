#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>
using namespace std;


//this function takes 2 inputs and swaps them
//pre: 2 inputs of int type
//swaps the inputs
void swap(int& position1, int& position2);

//this function takes the guess and returns true of false based on the range of 0-10
//pre: guess is string
//returns false if Not between 0-10 and returns true if valid
bool validateInput(string guess);

//This function obtains the number of students in the program from 1-10
//must be int data type
//outputs number of student
int getNumberOfStudents();

//This function takes the number of students and for each student obtains user inputed data for each variable
//Pre: Number of students
//Outputs average, score, max score, min score, student names,number of students passed and failed.
void getStudentData(int students, double& avg, double& score, double& max, double& min, string& name, string& minName, string& maxName, int& passed, int& failed, double &sum);

//This function takes the data from getStudentData and outputs in a neat format
//pre: avgerage, score, max, min, name, minName, maxName, passed, failed
//returns class statistincs which include the max and min score with each student that got them, the average score, and how many students passed or failed.
void displayStatistics(double avg, double score, double max, double min, string name, string minName, string maxName, int passed, int failed);

//This function gets the user's name
//Pre: input must be string
//returns name
void getUserName(string& userName);

//This function takes the user password and makes sure it is 5 characters long
//pre: 5 characters long and char type
// returns password
void getUserId(string& pass);

//This function takes the fist 3 inserted characters of the password and sums their char/ASCII value
//Pre: password
//returns the sum of the char/ASCII values
int calculateASCIISum(string& pass, int& sumASCII);

//This function takes the sum of the ascii to determin whether or not to welcome a student or a teacher. Additionall>
//pre: sumASCII and Ctime
// returns greating of teacher or student and displays the current date and time
void greetUser(string& userName, int& sumASCII);

//This function ends the program gracefully
//pre: none
//returns 0
int exitProgram(string userName);

//this function generates a random number 1-10 for the position of the bug
//Pre: none
// returns postion of bug in a number 1-10
int positionOfBug();

//This function gets the user's guess for the position of the bug
//pre: Should be value 1-10, but will reask if not
//returns the guess value
int getUserGuess(int attempts);

//This function compares the guess to the random generated position
//pre: position and guess
// returns weather the guess was  greater than or less thean the position
void catchTheBug(int position, int guess);


#endif
