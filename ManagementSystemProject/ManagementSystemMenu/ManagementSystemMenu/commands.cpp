#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "menuDesign.h"
#include "commands.h"
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define ENTER 13
#define ESCAPE 27
#define CTRL_KEYPRESS(k) ((k)  & 0x1f) 

// Global variable for nodes 'y' coordinates
int counterPrint = 11;

void printTasks(Node* head)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    while (head != NULL)
    {
        consoleCoordinates(35, counterPrint);
        cout << head->ID << ". " << head->name << endl;
        head = head->next;
        counterPrint += 2;
    }
}

void viewInformationByID(Node* head)
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(35, 10);
    cout << "Enter task's id to view information";
    consoleCoordinates(35, 11);
    int ID;
    cin >> ID;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->ID == ID) {
            system("CLS");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            consoleCoordinates(42, 10);
            string name = temp->name;
            for (size_t i = 0; i < name.length(); i++)
            {
                char letter = toupper(name[i]);
                cout << letter;
            }

            consoleCoordinates(25, 13);
            cout << temp->information; break;
        }
        temp = temp->next;
    }
}

void viewInformationByName(Node* head)
{
    system("CLS");

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(35, 10);
    cout << "Enter the task's name to view information";
    consoleCoordinates(35, 11);
    string name;
    getline(cin, name);
    Node* temp = head;
    while (temp != NULL) {
        if (temp->name == name) {
            system("CLS");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            consoleCoordinates(42, 10);
            string name = temp->name;
            for (size_t i = 0; i < name.length(); i++)
            {
                char letter = toupper(name[i]);
                cout << letter;
            }
            consoleCoordinates(25, 13);
            cout << temp->information; break;
        }
        temp = temp->next;
    }
}

// Function for inserting a task
void insert(Node** head, int ID, string name, string information)
{
    Node* newNode = new Node();
    Node* last = *head;
    newNode->ID = ID;

    newNode->name = name;
    newNode->information = information;

    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}

// Function for deleting an element in the linked list
void deleteTask(Node** head, int ID)
{
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->ID == ID)
    {
        *head = temp->next;
        delete temp;
        return;
    }

    else
    {
        while (temp != NULL && temp->ID != ID)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL)
            return;

        prev->next = temp->next;

        delete temp;
    }
}

// Function for editing an element in the linked list
void editTask(Node* head, int ID)
{
    Node* temp = head;
    while (temp != NULL) {
        if (temp->ID == ID) {
            system("CLS");

            cin.ignore();
            consoleCoordinates(35, 14);
            cout << "Edit task's name";
            consoleCoordinates(35, 15);
            string name;
            getline(cin, name);
            consoleCoordinates(35, 16);
            cout << "Edit information";
            consoleCoordinates(35, 17);
            string information;
            getline(cin, information);
            temp->ID = ID;

            temp->name = name;
            temp->information = information;
        }
        temp = temp->next;
    }
    return;
}

void insertTask(Node* Head)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(35, 10);
    cout << "Enter ID\n";
    consoleCoordinates(35, 11);
    int ID;
    cin >> ID;

    cin.ignore();
    consoleCoordinates(35, 13);
    cout << "Enter task's name\n";
    string name;
    consoleCoordinates(35, 14);
    getline(cin, name);
    consoleCoordinates(35, 16);
    cout << "Write information about the task and its participant\n";
    string information;
    consoleCoordinates(35, 17);
    getline(cin, information);
    system("CLS");
    insert(&Head, ID, name, information);
    counterPrint = 11;
    printTasks(Head);
    contentMenuInput(Head);
}

void choosingEditTask(Node* Head)
{
    system("CLS");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(35, 10);
    cout << "Enter the id of the task";
    consoleCoordinates(35, 11);
    int id;
    cin >> id;
    editTask(Head, id);
}


// Function for tasks' content
void contentTeam1(int privilege)
{
    Node* Head = new Node;
    Node* Second = new Node;
    Node* Third = new Node;
    Node* Fourth = new Node;
    Node* Fifth = new Node;

    Head->ID = 1;

    Head->name = "Create a menu";
    Head->information = "The task is assigned to Susie Oliver - 05.07.2022";
    Head->next = Second;

    Second->ID = 2;

    Second->name = "Make a website";
    Second->information = "The task is assigned to Tomas Mccabe - 03.04.2022";
    Second->next = Third;

    Third->ID = 3;

    Third->name = "Create a documentation";
    Third->information = "The task is assigned to Ellesse Wilde - 04.05.2022 ";
    Third->next = Fourth;

    Fourth->ID = 4;

    Fourth->name = "Create the design";
    Fourth->information = "The task is assigned to Amira Stone - 02.08.2022 ";
    Fourth->next = Fifth;

    Fifth->ID = 5;

    Fifth->name = "Make a presentation";
    Fifth->information = "The task is assigned to Shona Delgado - 02.07.2022 ";
    Fifth->next = NULL;


    if (privilege == 1)contentMenuInput(Head);
    if (privilege == 2)contentMenuInputGuest(Head);
}

// Function for linked list's content
void contentTeam2(int privilege)
{
    Node* Head = new Node;
    Node* Second = new Node;
    Node* Third = new Node;

    Head->ID = 1;

    Head->name = "Make the presentation";
    Head->information = "The task is assigned to Kaira Lopez - 02.04.2022 ";
    Head->next = Second;

    Second->ID = 2;

    Second->name = "Create the database";
    Second->information = "The task is assigned to Sannah Carr - 04.03.2022 ";
    Second->next = Third;

    Third->ID = 3;

    Third->name = "Seach for information";
    Third->information = "The task is assigned to Derek Hackett - 08.01.2022 ";
    Third->next = NULL;

    printTasks(Head);
    if (privilege == 1)contentMenuInput(Head);
    if (privilege == 2)contentMenuInputGuest(Head);
}

// Function for linked list's content
void contentTeam3(int privilege)
{
    Node* Head = new Node;
    Node* Second = new Node;
    Node* Third = new Node;

    Head->ID = 1;

    Head->name = "Help with the code";
    Head->information = "The task is assigned to Derek Hackett - 02.07.2022 ";
    Head->next = Second;

    Second->ID = 2;

    Second->name = "Draw the logo";
    Second->information = "The task isn't assigned to anyone yet";
    Second->next = Third;

    Third->ID = 3;

    Third->name = "Make the QA tests";
    Third->information = "The task isn't assigned to anyone yet";
    Third->next = NULL;

    if (privilege == 1)contentMenuInput(Head);
    if (privilege == 2)contentMenuInputGuest(Head);
}

// Function for going around the registration form menu
bool registrationFormInput()
{
    int counter = 8;
    registrationFormBorder();
    registrationFormOptions();
    registrationFormArrow(counter);

    do
    {
        switch (_getch())
        {

        case KEY_UP:
        {
            if (counter == 8) counter = 14;
            counter -= 2;
            system("CLS");
            registrationFormBorder();
            registrationFormOptions();
            registrationFormArrow(counter);
        } break;

        case KEY_DOWN:
        {
            if (counter == 14) counter = 8;
            counter += 2;
            system("CLS");
            system("CLS");
            registrationFormBorder();
            registrationFormOptions();
            registrationFormArrow(counter);
        } break;

        case ENTER:
        {
            switch (counter) {
            case 8:
            {
                system("CLS");
                login();
                break;
            }

            case 10:
            {
                system("CLS");
                registration();
                break;
            }

            case 12:
            {
                system("CLS");
                choosingMenuInput(2);
                break;
            }

            case 14:
            {
                system("CLS");
                menuInput();
                break;
            }
            }
        } break;
        }
    } while (true);
    return 1;
}

// Function for going around the main menu
bool menuInput()
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r); //console's current dimensions
    int counter = 1;
    menu(counter);

    do
    {
        switch (_getch())
        {

        case ENTER:
        {
            switch (counter) {
            case 1:
            {
                system("CLS");
                registrationFormInput();
                break;
            }

            }
        } break;
        }
    } while (true);
    return 1;
}

// Function for going around the choosing menu
bool choosingMenuInput(int privilege)
{
    int counter = 1;
    choosingMenu(counter);

    do
    {
        switch (_getch())
        {

        case KEY_UP:
        {
            if (counter == 1) counter = 4;
            counter--;
            system("CLS");
            choosingMenu(counter);
        } break;

        case KEY_DOWN:
        {
            if (counter == 3) {
                counter = 0;
            }
            counter++;
            system("CLS");
            choosingMenu(counter);
        } break;

        case ENTER:
        {
            switch (counter) {
            case 1:
            {
                system("CLS");
                contentTeam1(privilege);
            }break;

            case 2:
            {
                system("CLS");
                contentTeam2(privilege);
            }break;

            case 3:
            {
                system("CLS");
                contentTeam3(privilege);
            }break;

            }
        } break;

        case ESCAPE:
        {
            system("CLS");
            menuInput();
        }
        }
    } while (true);
    return 1;
}

bool contentMenuInput(Node* Head)
{
    system("CLS");
    taskMenuTitle();
    int counter = 11;

    counterPrint = 11;
    printTasks(Head);
    askInput();
    do
    {
        switch (_getch())
        {

        case KEY_UP:
        {
            if (counter == 11) counter = counterPrint;
            counter -= 2;
            system("CLS");

            counterPrint = 11;
            printTasks(Head);
            askInput();
            taskMenuTitle();
        } break;

        case KEY_DOWN:
        {
            if (counter == counterPrint - 2) {
                counter = 9;
            }
            counter += 2;
            system("CLS");

            counterPrint = 11;
            printTasks(Head);
            askInput();
            taskMenuTitle();
        } break;

        case CTRL_KEYPRESS('c'):
        {
            system("CLS");
            adminCommands(Head);
        }break;

        case CTRL_KEYPRESS('t'):
        {
            system("CLS");
            viewInfoChoice(Head, 1);
        }break;

        case ESCAPE:
        {
            system("CLS");
            choosingMenuInput(1);
        }break;
        }
    } while (true);
    return 1;
}

bool contentMenuInputGuest(Node* Head) {
    system("CLS");
    int counter = 11;

    counterPrint = 11;
    printTasks(Head);
    taskMenuTitle();
    askInputGuest();
    do
    {
        switch (_getch())
        {

        case KEY_UP:
        {
            if (counter == 11) counter = counterPrint;
            counter -= 2;
            system("CLS");

            counterPrint = 11;
            printTasks(Head);
            askInputGuest();
            taskMenuTitle();
        } break;

        case KEY_DOWN:
        {
            if (counter == counterPrint - 2) {
                counter = 9;
            }
            counter += 2;
            system("CLS");

            counterPrint = 11;
            printTasks(Head);
            askInputGuest();
            taskMenuTitle();
        } break;

        case CTRL_KEYPRESS('t'):
        {
            system("CLS");
            viewInfoChoice(Head, 2);
        }break;

        case ESCAPE:
        {
            system("CLS");
            choosingMenuInput(2);
        }break;
        }
    } while (true);
    return 1;

}

bool contentMenuInputGuestMenu(Node* Head)
{
    system("CLS");
    int counter = 11;
    counterPrint = 11;
    printTasks(Head);
    askInputGuest();
    do
    {
        switch (_getch())
        {
        case CTRL_KEYPRESS('t'):
        {
            system("CLS");
            viewInfoChoice(Head, 2);
        }break;

        case ESCAPE:
        {
            system("CLS");
            choosingMenuInput(2);
        }break;
        }
    } while (true);
    return 1;
}

void adminCommands(Node* Head)
{
    system("CLS");
    adminCommandsBorder();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    consoleCoordinates(20, 6);
    cout << "To add a task press ctrl + a";
    consoleCoordinates(20, 7);
    cout << "To delete a task press ctrl + d";
    consoleCoordinates(20, 8);
    cout << "To edit a task press ctrl + e";
    consoleCoordinates(20, 9);
    cout << "To check a task + t";
    switch (_getch())
    {
    case CTRL_KEYPRESS('a'):
    {
        system("CLS");
        insertChoice(Head);
    }break;


    case CTRL_KEYPRESS('d'):
    {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        consoleCoordinates(35, 10);
        cout << "Enter the task's id to remove it";
        consoleCoordinates(35, 11);
        int id;
        cin >> id;
        deleteTask(&Head, id);
        system("CLS");
        contentMenuInput(Head);
    }break;

    case CTRL_KEYPRESS('e'):
    {
        choosingEditTask(Head);
        system("CLS");
        contentMenuInput(Head);
    }break;

    case CTRL_KEYPRESS('t'):
    {
        system("CLS");
        viewInfoChoice(Head, 1);
    }break;

    case ESCAPE:
    {
        system("CLS");
        contentMenuInput(Head);
    }break;
    }
}

// Function for going around the insert menu
bool insertChoice(Node* Head)
{
    insertMenu();
    consoleCoordinates(31, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "> ";
    do
    {
        switch (_getch())
        {

        case ENTER:
        {

            system("CLS");
            insertTask(Head);

        }break;

        case ESCAPE:
        {
            system("CLS");
            contentMenuInput(Head);
        }break;
        }
    } while (true);
    return 1;
}

// Function for going around the information menu
bool viewInfoChoice(Node* Head, int privilege)
{
    int counter = 10;
    viewInfoMenu();

    consoleCoordinates(31, 10);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout << "> ";
    do
    {
        switch (_getch())
        {
        case KEY_UP:
        {
            if (counter == 10)counter = 14;
            counter -= 2;
            system("CLS");
            consoleCoordinates(31, counter);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << "> ";
            viewInfoMenu();

        }break;

        case KEY_DOWN:
        {
            if (counter == 12)counter = 8;
            counter += 2;
            system("CLS");
            consoleCoordinates(31, counter);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            cout << "> ";
            viewInfoMenu();
        }break;

        case ENTER:
        {
            if (counter == 10)
            {
                system("CLS");
                viewInformationByID(Head);
            }
            else if (counter == 12)
            {
                system("CLS");
                viewInformationByName(Head);
            }
        }break;

        case ESCAPE:
        {
            system("CLS");
            if (privilege == 1)contentMenuInput(Head);
            else contentMenuInputGuestMenu(Head);
        }break;
        }
    } while (true);
    return 1;
}