#include<iostream>
#include<windows.h>
#include <conio.h>
#include"../conio3.h"
using namespace std;
void menu();
void box(int,int ,int ,int, int);
void vaccine_management();
void rapid_covid_test()
{
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    char a, b, c, d, e, f;
    string name;
    string state;
    int i, j = 1, age, x, count = 0, p;
      box(2,30,4,94,MAGENTA);
    gotoxy(45,3);
    textcolor(WHITE);
    cout<<"**** RAPID COVID TEST ****";
    gotoxy(72,4);
    cout<<"~By CGMP";
    box(6,25,6,99,CYAN);
    gotoxy(42,6);
    textcolor(BLACK);
    printf("PLEASE ENTER YOUR BASIC INFORMATION");
    box(8,40,16,84,YELLOW);
    gotoxy(42,9);
    printf("NAME:- ");
    fflush(stdin);
    getline(cin, name);
    gotoxy(42,11);
    printf("AGE:- ");
    scanf("%d", &age);
    if (age <= 13 || age >= 50)
    {
        count += 1;
    }
    gotoxy(42,13);
    printf("STATE:- ");
    fflush(stdin);
  getline(cin, state);
    box(18,30,18,94,LIGHTRED);
    gotoxy(32,18);
    printf("PLEASE ANSWER THE FOLLOWING QUESTION CORRECTLY");
    box(20,25,49,99,LIGHTCYAN);
    gotoxy(27,22);
    printf("Do you have any travel history across INDIA between jan to mar?(y/n)");
    gotoxy(27,23);
    printf("Ans :- ");
    fflush(stdin);
    scanf("%c", &a);
    if (a == 'y' || a == 'Y')
    {
        count += 1;
    }
    gotoxy(27,25);
    printf("Do you came in contact with any covid infected parson?(y/n)");
    gotoxy(27,26);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &b);
    if (b == 'y' || b == 'Y')
    {
        count += 1;
    }
    gotoxy(27,28);
    printf("Is there any covid patient in the range of 1 km?(y/n)");
    gotoxy(27,29);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &c);
    if (c == 'y' || c == 'Y')
    {
        count += 1;
    }
    gotoxy(27,31);
    printf("Are you suffering of any kind of diseases like CANCER,DIABETES?(y/n)");
    gotoxy(27,32);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &d);
    if (d == 'y' || d == 'Y')
    {
        count += 1;
    }
    gotoxy(27,34);
    printf("Please let us know your body temperature(in C)");
    gotoxy(27,35);
    printf("Ans :-");
    scanf("%d", &x);
    if (x >= 38)
    {
        count += 1;
    }
    gotoxy(27,37);
    printf("If you are suffering from any one write (y\n)");
    gotoxy(27,38);
    printf("1) Dry cough");
    gotoxy(27,39);
    printf("2) Shortness of breath");
    gotoxy(27,40);
    printf("3) Headaches");
    gotoxy(27,41);
    printf("4) Aches and Pains");
    gotoxy(27,42);
    printf("5) Sore throat");
    gotoxy(27,43);
    printf("6) fatigue");
    gotoxy(27,44);
    printf("7) Diarrhea ");
    gotoxy(27,45);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &e);
    if (e == 'y' || e == 'Y')
    {
        count += 1;
    }
    gotoxy(27,46);
    printf("Are you suffering from bp or suger problem?(y/n) ");
    gotoxy(27,47);
    printf("Ans :-");
    fflush(stdin);
    scanf("%c", &f);
    if (f == 'y' || f == 'Y')
    {
        count += 1;
    }
    box(51,25,51,99,LIGHTMAGENTA);
    gotoxy(27,51);
    printf("..................PLEASE WAIT WHILE WE ARE ANALYSING DATA ");
    textbackground(BLACK);
    gotoxy(27,58);
    getch();
    while (1)
    {
            system("cls");
            textbackground(BLACK);
            box(3,40,5,84,YELLOW);
            gotoxy(55,4);
            textcolor(BLACK);
            printf(" REPORT");
            textcolor(WHITE);
            box(7,30,13,94,CYAN);
            gotoxy(40,8);
            cout<<"Name : "<<name ;
            gotoxy(40,9);
            cout<<"Age : "<<age;
            gotoxy(40,10);
            cout<<"State : "<<state;
            count = count * 10;
            gotoxy(40,12);
            printf("YOUR RATE OF BEING INFECTED IS %d percent ", count);
            if (count <= 20)
            {
                box(15,45,15,79,GREEN);
                gotoxy(50,15);
                printf("CONGRATS! YOU ARE IN GREEN ZONE ");
                box(17,48,17,76,RED);
                gotoxy(50,17);
                printf("STAY HOME STAY SAFE");
                box(19,30,19,94,BROWN);
                textcolor(WHITE);
                gotoxy(34,19);
                cout<<"CONGRATS YOU ARE ELIGIBLE FOR VACCINATION DRIVE ";
                box(21,34,26,94,RED);
                gotoxy(37,22);
                cout << "1)  FOR VACCINATION   \t  2) MAIN MENU     ";
                int choice;
                gotoxy(37,24);
                cout<< "PLEASE ENETR YOUR CHOICE :- ";
                cin>>choice;
                textbackground(BLACK);
                switch(choice)
                {
                    case 1:
                    vaccine_management();
                    textbackground(BLACK);
                    menu();
                    break;
                    case 2:
                    getch();
                    textbackground(BLACK);
                    menu();
                    break;
                    default:
                        box(26,40,26,84,YELLOW);
                        gotoxy(44,26);
                        textcolor(BLACK);
                    cout<<"Please insert valid choice ! " ;
                          gotoxy(47,32);
                          textbackground(BLACK);
                    getch();
                    menu();
                }
            }

            else if (count >= 20 && count <= 40)
            {
                box(15,45,15,79,BROWN);
                gotoxy(50,15);
                printf("YOU ARE IN ORANGE ZONE ");
                box(17,48,17,76,RED);
                gotoxy(50,17);
                printf("STAY HOME STAY SAFE");
                box(19,30,19,94,BROWN);
                textcolor(WHITE);
                gotoxy(34,19);
                cout<<" CONGRATS YOU ARE ELIGIBLE FOR VACCINATION DRIVE  ";
                box(21,34,26,94,RED);
                gotoxy(37,22);
                cout << "1)  FOR VACCINATION   \t  2) MAIN MENU  ";
             int choice;
             gotoxy(37,24);
             cout<< "PLEASE ENTER YOUR CHOICE :- ";
             cin>>choice;
             textbackground(BLACK);
             switch(choice)
             {
             case 1:
                vaccine_management();
                textbackground(BLACK);
                menu();
                break;
             case 2:
                 getch();
                 textbackground(BLACK);
                menu();
             default:
                        box(26,40,26,84,YELLOW);
                        gotoxy(44,26);
                        textcolor(BLACK);
                    cout<<"Please insert valid choice ! " ;
                          gotoxy(47,32);
                    getch();
                    textbackground(BLACK);
                    menu();
                }
            }

            else
            {
                  box(15,45,15,79,RED);
                gotoxy(50,15);
                printf("ALERT! YOU ARE IN RED ZONE");
                box(17,25,17,99,RED);
                gotoxy(27,17);
                printf("YOU ARE NOT ELIGIBLE FOR VACCINATION BECAUSE YOU ARE IN RED ZONE");
            }
            printf("\n\n\t\t\t STAY HOME STAY SAFE \n");
            printf("\n\n\t\t\t STAY HOME STAY SAFE \n");
            getch();
            textbackground(BLACK);
            menu();
    }

}
