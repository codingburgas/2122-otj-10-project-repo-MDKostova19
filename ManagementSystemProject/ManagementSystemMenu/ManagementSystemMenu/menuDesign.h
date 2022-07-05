#pragma once
#include "commands.h"

void consoleCoordinates(int x, int y);

// Functions for the main menu
void menuOptionsBorder();
void menuOptions(int counter);
void menu(int counter);

void adminCommandsBorder();
void box();

// Functions for the registration menu
void registrationFormBorder();
void registrationFormOptions();
void registrationFormArrow(int counter);

// Functions for viewing options by privileges
void askInput();
void askInputGuest();

// Functions for the choosing menu
void taskMenuTitle();
void choosingMenu();
void choosingMenuOptions(int counter);
void choosingMenu(int counter);
void viewInfoMenu();
void insertMenu();

#define RED     "\033[1;91m" 
#define BLUE    "\033[1;96m"
#define RESET   "\033[0m"