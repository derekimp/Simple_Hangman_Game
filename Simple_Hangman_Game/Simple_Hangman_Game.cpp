// Simple_Hangman_Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <fstream>
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
    if (curPoint >= 7)
        printMessage("|", false, false);
    if (curPoint == 8)
        printMessage("/  ", false, false);
    if (curPoint >= 9)
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

string loadRandomWords(string path) {
    srand(time(0));
    int lineCount = 0;
    string word;
    vector<string> v;
    ifstream reader(path);
    if (reader.is_open()) {
        while (getline(reader, word))
            v.push_back(word);
        int randomLine = rand() % v.size();

        word = v.at(randomLine);
        reader.close();
    }
    return word;
}

int triesLeft(string word, string guess) {
    int error = 0;
    for (int i = 0; i < guess.size();i++) {
        if (word.find(guess[i]) == word.npos) {
            error++;
        }
    }
    return error;
}

int main()
{
    string guess ;
    string wordToGuess = loadRandomWords("words.txt");
    bool won = false;
    int tries = 0;
    do {
        system("cls");
        printMessage("Hang Man");
        printMan(tries);
        printUsed(guess);
        printMessage("Guess the word!", false, true);
        won = printWordCheckWin(wordToGuess, guess);

        if (won)
            break;

        char x;
        cout << ">";
        cin >> x;
        if (guess.find(x) == guess.npos)
            guess += x;

        tries = triesLeft(wordToGuess, guess);

    } while (tries < 10);
    if (won)
        printMessage("You Won");
    else
        printMessage("Game Over");
    
    system("pause");
    return 0;
}

/*
+---------------------------------+
|             Hang Man            |
+---------------------------------+
|                |                |
+---------------------------------+
|      B C D   F G H I J   L M    |
|    N O P Q R S   U V   X Y Z    |
+---------------------------------+
|         Guess the word!         |
+---------------------------------+
|             K A T E             |
+---------------------------------+
+---------------------------------+
|             You Won             |
+---------------------------------+*/