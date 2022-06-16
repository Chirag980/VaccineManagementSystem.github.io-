#include <iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include"../conio2.h"
using namespace std;
void menu();
void rapid_covid_test();
void vaccine_inventory();
int control();
void get_second_dose();
void search_data();
void showdata();
void box(int row,int col,int endrow,int endcol,int color)
{
    int i,j;
    for( i=row;i<=endrow;i++)
    {
        for(j=col;j<=endcol;j++)
        {
            gotoxy(j,i);
            textbackground(color);
            printf(" ");
        }
    }
}
int main()
{
    system("cls");
    textbackground(BLACK);
    textcolor(WHITE);
    menu();
}
void menu()
{
    system("cls");
    textbackground(BLACK);
    textcolor(WHITE);
    int ch;
    box(3,24,5,100,LIGHTGREEN);
    gotoxy(45,4);
    textcolor(WHITE);
    cout<<"Vaccine management system 2.0 ";
    gotoxy(75,5);
    cout<<"~By CGMP";
    while(1)
    {
        ch=control();
        switch(ch)
        {
        case 17:
            rapid_covid_test();
            break;
        case 34:
            get_second_dose();
            break;
        case 51:
            system("cls");
            textbackground(BLACK);
            textcolor(WHITE);
            box(6,24,8,100,LIGHTGREEN);
            gotoxy(36,7);
            cout<<"Thank You For Using  Vaccine Management System 2.0";
            box(10,20,13,104,YELLOW);
            textcolor(RED);
            gotoxy(54,11);
            cout<<"";
            gotoxy(30,12);
            cout<<" ";
            gotoxy(32,17);
            exit(0);
            break;
        case 68:
            search_data();
            break;
        case 85:
            vaccine_inventory();
            break;
        }
    }
}
int control()
{
    int ch;
    int x=17;
    while(ch!=13)
    {
        textcolor(WHITE);
        box(8,17,19,33,RED);
        gotoxy(19,13);
        cout<<"RAPID COVID";
        gotoxy(22,14);
        cout<<"TEST";
        box(8,34,19,50,YELLOW);
        gotoxy(35,13);
        textcolor(RED);
        cout<<"GET 2nd DOSE ";
        gotoxy(37,14);
        cout<<"OF VACCINE";
        textcolor(RED);
        box(8,51,19,67,WHITE);
        gotoxy(56,13);
        cout<<"EXIT ";
        textcolor(RED);
        box(8,68,19,84,YELLOW);
        gotoxy(71,13);
        cout<<"SEARCH ";
        gotoxy(73,14);
        cout<<"DATA ";
        textcolor(WHITE);
        box(8,85,19,101,RED);
        gotoxy(89,13);
        cout<<"MANAGE ";
        gotoxy(87,14);
        cout<<"VACCINATION ";
        gotoxy(89,15);
        cout<<"RECORDS ";

        box(20,17,20,101,WHITE);
        box(20,x,20,x+16,GREEN);
        box(24,26,26,94,CYAN);
        gotoxy(30,25);
        textcolor(RED);
        if(x==17)
            cout<<"For Rapid Covid Test and first dose of vaccination ";
        else if(x==34)
            cout<<"To Get Second dose of vaccine ";
            else if(x==51)
            cout<<"To Exit the Program ";
            else if(x==68)
                cout<<"Search Records of people who got vaccinated ";
            else if(x==85)
                cout<<"To Manage and Update Records of vaccines ";

        ch=getch();
            switch(ch)
            {
                case 75: //left arrow
                        x=x-17;
                        box(20,x,20,x,GREEN);
                        break;
                case 77: // right arrow
                    x=x+17;
                    box(20,x,20,x,GREEN);
            }
            if(x>101)
                x=17;
            else if(x<17)
                x=85;
                box(20,x,20,x,WHITE);
        }
        textbackground(BLACK);
        return x;
}
