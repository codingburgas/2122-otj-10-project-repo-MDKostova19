#include<iostream>
#include<fstream>
#include <windows.h>
#include <conio.h>

#include "menuDesign.h"
#include "registration.h"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13
#define ESCAPE 27
#define CTRL_KEYPRESS(k) ((k)  & 0x1f) 

void login()
{
    int counter = 0;
    string user, password, privilege, pass;
    system("CLS");
    box();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(30, 5);
    cout << "Enter your username:";
    consoleCoordinates(30, 6);
    cin >> user;

    consoleCoordinates(30, 7);
    cout << "Enter your password:";
    consoleCoordinates(30, 8);
    cin >> password;

    ifstream input("records.txt");

    while (input >> privilege >> pass)
    {
        if (privilege == user && pass == password)
        {
            counter = 1;
            system("CLS");
        }
    }
    input.close();

    if (counter == 1)
    {
        system("CLS");
        choosingMenuInput(1);
    }
    else
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        box();
        consoleCoordinates(29, 6);
        cout << "Invalid username or password";
        Sleep(700);
        system("CLS");
        registrationFormInput();
    }

    switch (_getch())
    {
    case ESCAPE:
    {
        registrationFormInput();
    }
    }
}

// Function for registration into the system
void registration()
{

    string user, password, privilege, pass;
    system("CLS");
    box();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(30, 5);
    cout << "Enter your username:";
    consoleCoordinates(30, 6);
    cin >> user;

    consoleCoordinates(30, 7);
    cout << "Enter your password:";
    consoleCoordinates(30, 8);
    cin >> password;

    ofstream registration("records.txt", ios::app);
    registration << user << ' ' << password << endl;
    system("CLS");
    box();
    consoleCoordinates(30, 6);
    cout << "Successfully registered";
    Sleep(700);
    system("CLS");
    registrationFormInput();

    switch (_getch())
    {
    case ESCAPE:
    {
        registrationFormInput();
    }
    }
}