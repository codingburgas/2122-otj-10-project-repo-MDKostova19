#include <iostream>
#include <conio.h>
#include <windows.h>
#include "commands.h"
#include "menuDesign.h"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13
#define ESCAPE 27
#define CTRL_KEYPRESS(k) ((k)  & 0x1f) 

#define LINES 75

// Function to choose where the elements of the program will be
void consoleCoordinates(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Function for the main menu
void menuOptionsBorder()
{
    consoleCoordinates(51, 5);
    cout << "________________________________";
    consoleCoordinates(50, 6);
    cout << "/                                \\";
    consoleCoordinates(50, 7);
    cout << "|                                |";
    consoleCoordinates(50, 8);
    cout << "|                                |";
    consoleCoordinates(50, 9);
    cout << "|                                |";
    consoleCoordinates(50, 10);
    cout << "\\________________________________/";
}

// Function for the main menu
void menuOptions(int counter)
{

    switch (counter)
    {
    case 1:
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        consoleCoordinates(57, 8);
        cout << BLUE << "REGISTRATION FORM" << RESET;
    }break;

    }
}

void menu(int counter)
{
    if (counter == 1) {
        menuOptionsBorder();
        menuOptions(counter);
    }
}

void registrationFormBorder()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(30, 5);
    cout << " _____________________________________________";
    for (int i = 6; i < 15; i++) {
        consoleCoordinates(30, i);
        cout << "|";
    }

    for (int i = 6; i < 15; i++) {
        consoleCoordinates(76, i);
        cout << "|";
    }
    consoleCoordinates(30, 15);
    cout << "\\_____________________________________________/";
}

void registrationFormOptions()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(50, 8);
    cout << "LOGIN";
    consoleCoordinates(47, 10);
    cout << "REGISTRATION";
    consoleCoordinates(50, 12);
    cout << "GUEST";
    consoleCoordinates(50, 14);
    cout << "BACK";
}

void adminCommandsBorder() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(36, 3);
    cout << BLUE << "COMMANDS" << RESET;
    consoleCoordinates(18, 4);
    cout << " _____________________________________________";
    for (int i = 5; i < 10; i++) {
        consoleCoordinates(18, i);
        cout << "|";
    }

    for (int i = 5; i < 10; i++) {
        consoleCoordinates(64, i);
        cout << "|";
    }
    consoleCoordinates(18, 10);
    cout << "\\_____________________________________________/";
}
// Function for moving the arrow in the registration form
void registrationFormArrow(int counter)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    consoleCoordinates(40, counter);
    cout << ">";
    consoleCoordinates(64, counter);
    cout << "<";
}

void choosingMenu()
{
    consoleCoordinates(10, 5);
    cout << " ________________________________________________________________\n";
    consoleCoordinates(10, 6);
    cout << "/                      Users Management View                      \\\n";
    for (int i = 7; i < 16; i++) {
        consoleCoordinates(10, i);
        cout << "|" << "                                                                 |" << endl;
    }
    consoleCoordinates(10, 16);
    cout << "|_________________________________________________________________|\n";
}

void choosingMenuOptions(int counter)
{
    switch (counter)
    {
    case 1:
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        consoleCoordinates(36, 9);
        cout << ">";
        consoleCoordinates(49, 9);
        cout << "<";
        consoleCoordinates(40, 9);
        cout << BLUE << "TEAM 1" << RESET;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        consoleCoordinates(40, 11);
        cout << "TEAM 2";
        consoleCoordinates(40, 13);
        cout << "TEAM 3";
    }break;
    case 2:
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        consoleCoordinates(36, 11);
        cout << ">";
        consoleCoordinates(49, 11);
        cout << "<";
        consoleCoordinates(40, 11);
        cout << BLUE << "TEAM 2" << RESET;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        consoleCoordinates(40, 9);
        cout << "TEAM 1";
        consoleCoordinates(40, 13);
        cout << "TEAM 3";
    }break;
    case 3:
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
        consoleCoordinates(36, 13);
        cout << ">";
        consoleCoordinates(49, 13);
        cout << "<";
        consoleCoordinates(40, 13);
        cout << BLUE << "TEAM 3" << RESET;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        consoleCoordinates(40, 9);
        cout << "TEAM 1";
        consoleCoordinates(40, 11);
        cout << "TEAM 2";
    }break;
    }
}

void choosingMenu(int counter)
{
    if (counter == 1) {

        choosingMenu();

        choosingMenuOptions(counter);
    }
    if (counter == 2) {

        choosingMenu();

        choosingMenuOptions(counter);
    }
    if (counter == 3) {

        choosingMenu();

        choosingMenuOptions(counter);
    }
}

void box() {
    consoleCoordinates(25, 3);
    cout << "-----------------------------------";

    consoleCoordinates(25, 10);
    cout << "-----------------------------------";
}
void taskMenuTitle() {
    consoleCoordinates(40, 5);
    cout << "TASKS";
    consoleCoordinates(25, 6);
    cout << "-----------------------------------";
}

void askInput()
{
    consoleCoordinates(25, 25);
    cout << RED << "To view admin commands press ctrl + c" << RESET;
}

// Function for commands if the user is guest
void askInputGuest()
{
    consoleCoordinates(25, 22);
    cout << "If you want to check a task press ctrl + t";
}

// Function for viewing the options for the view information function
void viewInfoMenu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(35, 10);
    cout << "View information about the task by ID";
    consoleCoordinates(35, 12);
    cout << "View information about the task by the task's name";
}

// Function for viewing the options for the insert function
void insertMenu()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(35, 10);
    cout << BLUE "Add a task" << RESET;
}