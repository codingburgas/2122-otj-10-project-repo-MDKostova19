#pragma once
#include<string>
#include "menuDesign.h"
#include "registration.h"
using namespace std;

struct Node {
    int privilege;
    int ID;
    string name;
    string information;
    Node* next;
};

void adminCommands(Node* Head);

// Functions for the content in the teams
void contentTeam1(int privilege);
void contentTeam2(int privilege);
void contentTeam3(int privilege);

// Function for printing the tasks
void printTasks(Node* head);

// Functions for viewing information about a task
void viewInformationByID(Node* head);
void viewInformationByName(Node* head);

// Functions for adding a task
void insert(Node** head, int ID, string name, string information);

//Task functions
void insertTask(Node* Head);
void deleteTask(Node** head, int ID);
void editTask(Node* head, int ID);

void choosingEditTask(Node* Head);

// Functions for going around the menus
bool registrationFormInput();
bool menuInput();
bool choosingMenuInput(int privilege);
bool contentMenuInput(Node* Head);
bool contentMenuInputGuest(Node* Head);
bool contentMenuInputGuestMenu(Node* Head);
bool insertChoice(Node* Head);
bool viewInfoChoice(Node* Head, int privilege);