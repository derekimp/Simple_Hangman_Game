// Simple_Hangman_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void printMessage(string msg, bool printTop = true, bool printBot = true) {
    if (printTop) {
        cout << "+---------------------------------+" << endl;
        cout << "|";
    }
    else
        cout << "|";

    bool front = true;
    for (int i = msg.size(); i < 33; i++) {
        if (front)
            msg = " " + msg;
        else
            msg = msg + " ";
        front = !front;
    }

    cout << msg.c_str();

    if (printBot) {
        cout << "|" << endl;
        cout << "+---------------------------------+" << endl;
    }
    else
        cout << "|" << endl;
}

void printMan(int curPoint) {
    if (curPoint >= 1) 
        printMessage("|", false, false);
    if (curPoint >= 2)
        printMessage("|", false, false);
    if (curPoint >= 3)
        printMessage("O", false, false);

    if (curPoint == 4)
        printMessage("/  ", false, false);
    if (curPoint == 5)
        printMessage("/| ", false, false);
    if (curPoint >= 6)
        printMessage("/|\\", false, false);

    if (curPoint == 7)
        printMessage("/  ", false, false);
    if (curPoint >= 8)
        printMessage("/ \\", false, false);

}

void printUsed(string used = "") {
    string s;
    for (char i = 'A'; i <= 'M'; i++) {
        if (used.find(i) != used.npos) {
            s += ' ';
            s += ' ';
        }
        else {
            s += i;
            s += ' ';
        }
    }
    printMessage(s, true, false);

    s = "";
    for (char i = 'N'; i <= 'Z'; i++) {
        if (used.find(i) != used.npos) {
            s += ' ';
            s += ' ';
        }
        else {
            s += i;
            s += ' ';
        }
    }
    printMessage(s, false, true);
}

bool printWordCheckWin(string right, string guess) {
    string s;
    bool won = true;
    for (int i = 0; i < right.size(); i++) {
        if (guess.find(right[i]) == string::npos) {
            s += "_ ";
            won = false;
        }

        else {
            s += right[i];
            s += " ";
        }
    }
    printMessage(s, false);
    return won;
}

int main()
{
    string guess = "ABSKKLL";
    printMessage("Hang Man");
    printMan(5);
    printUsed(guess);
    printMessage("Guess the word!", false, true);
    printWordCheckWin("ALEXK", guess);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
