#include<stdio.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<time.h>
#include"../conio2.h"
int control_second_menu();
void second_menu();
using namespace std;
void show();
void menu();
int main();
void box(int,int ,int ,int, int);
class vaccine
{
public:
    char name[30];
    char aadhar[12];
    int age;
    char gender;
    char profession[20];
    char address[60];
    char mobile_number[10];
    long long int ref_id;
    char vaccine_name[15];
    char first_dose_status[5];
    int blood_pressure;
    char second_dose_status[8];
    float temperature;
    char first_dose_date[10];
    char date_next[10];

    void user_input();
    void get_next_date(int );
     void showdata(int );
    void search_by_aadhar();
    void search_by_age();
    void search_by_profession();
    void search_by_gender();
    void show_list();
};

void vaccine::search_by_aadhar()
{
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    ifstream in("vaccinationdata.txt");
    int flag =0;
    long long int ref_num;
    box(3,30,5,94,CYAN);
    gotoxy(50,4);
    textcolor(BLACK);
     cout<<"REFFERENCE NUMBER SEARCHING ";
     gotoxy(74,5);
    cout<<"~By CGMP";
     box(6,24,8,100,5);
    gotoxy(28,7);
    cout<<"Enter your Reference Id :  ";
    fflush(stdin);
    cin>>ref_num;
    in.seekg(0);
    in.read((char*)this,sizeof(vaccine));
    int i=9;
    while(!in.eof())
    {
        if(ref_num==ref_id)
        {
            showdata(i);
            flag=1;
            break;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        box(10,40,10,84,RED);
        gotoxy(50,10);
        cout<<"Refference number not found ";
        getch();
    }
    in.close();
    system("cls");
    textbackground(BLACK);
}
void vaccine::search_by_age()
{
   ifstream in("vaccinationdata.txt");
    int flag =0;
    int a,p=0;
    box(3,30,5,94,CYAN);
    gotoxy(50,4);
    textcolor(BLACK);
    cout<<"AGE SEARCHING ";
    gotoxy(74,5);
    cout<<"~By CGMP";
    box(7,24,9,100,LIGHTGREEN);
    gotoxy(28,8);
    cout<<"enter Age by which you want to search : ";
    cin>>a;
    in.seekg(0);
    in.read((char*)this,sizeof(vaccine));
    int i=10;
    while(!in.eof())
    {
        if(a==age)
        {
            showdata(i);
            flag=1;
            p++;
            i=i+27;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        box(11,40,11,84,RED);
        gotoxy(42,11);
        cout<<"Age you entered is not found";
    }
    box(i+3,45,i+3,79,MAGENTA);
    gotoxy(45,i+3);
    textcolor(WHITE);
    cout<<"No of people vaccinated  by this age "<<p;
    getch();
    textbackground(BLACK);
    in.close();
}
void vaccine::search_by_profession()
{
    ifstream in("vaccinationdata.txt");
    int flag =0;
    int p=0;
    char prof[20];
     box(3,30,5,94,CYAN);
    gotoxy(50,4);
    textcolor(BLACK);
    cout<<"SEARCH BY PROFESSSION";
    gotoxy(74,5);
    cout<<"~By CGMP";
    box(7,24,9,100,LIGHTGREEN);
    gotoxy(28,8);
    cout<<"Enter Profession by which you want to search : ";
    fflush(stdin);
    gets(prof);
    in.seekg(0);
    in.read((char*)this,sizeof(vaccine));
    int i=10;
    while(!in.eof())
    {
        if(strcmp(prof,profession)==0)
        {
            showdata(i);
            flag=1;
            p++;
            i=i+27;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        box(11,40,11,84,RED);
        gotoxy(42,11);
        cout<<"The profession you have Enter does not exist";
    }
    box(i+3,45,i+3,79,MAGENTA);
    gotoxy(45,i+3);
    textcolor(WHITE);
    cout<<"NO of people vaccinated by this profession "<<p;
    textbackground(BLACK);
    getch();
    in.close();
}
void vaccine::search_by_gender()
{
    ifstream in("vaccinationdata.txt");
    int flag =0;
    char g;
    int p=0;
     box(3,30,5,94,CYAN);
    gotoxy(50,4);
    textcolor(BLACK);
    cout<<"SEARCH BY GENDER";
    gotoxy(74,5);
    cout<<"~By CGMP";
    box(7,24,9,100,LIGHTGREEN);
    gotoxy(28,8);
    cout<<"Enter gender by which you want to search : ";
    cin>>g;
    in.read((char*)this,sizeof(vaccine));
    in.seekg(0);
    int i=10;
    while(!in.eof())
    {
        if(toupper(g)==toupper(gender))
        {
            showdata(i);
            flag=1;
            p++;
            i=i+27;
        }
    in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        box(11,40,11,84,RED);
        gotoxy(42,11);
    cout<<"There is no person vaccinated from this gender ";
    }
    box(i+3,45,i+3,79,MAGENTA);
    gotoxy(45,i+3);
    textcolor(WHITE);
    cout<<"NO. of people vaccinated by this gender "<<p;
    getch();
    textbackground(BLACK);
    in.close();
}
void vaccine::showdata(int i)
{
    box(i,30,i+26,94,YELLOW);
    gotoxy(34,i+1);
    cout<<"Reference Id : "<<ref_id;
    gotoxy(34,i+3);
   cout<<"Name is: "<<name;
   gotoxy(34,i+5);
   cout<<"Aadhar number is: "<<aadhar;
   gotoxy(34,i+7);
    cout<<"Your age is "<<age;
    gotoxy(34,i+9);
    cout<<"Profession is : "<<profession;
    gotoxy(34,i+11);
    cout<<"Gender is : "<<gender;
    gotoxy(34,i+13);
    cout<<"Address is: "<<address;
    gotoxy(34,i+15);
    cout<<"Mobile number is: "<<mobile_number;
    gotoxy(34,i+17);
    cout<<"Vaccine Name : "<<vaccine_name;
    gotoxy(34,i+19);
    cout<<"First dose status: "<<first_dose_status;
    gotoxy(34,i+21);
    cout<<"First dose date: "<<first_dose_date;
    gotoxy(34,i+23);
    cout<<"Second dose status: "<<second_dose_status;
    gotoxy(34,i+25);
    cout<<"Second dose date: "<<date_next;
    getch();
}
void search_data()
{
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    vaccine i;
    int ch;
    while(1)
    {
        ch=control_second_menu();
        switch(ch)
        {
        case 14:
            system("cls");
            i.search_by_aadhar();
            break;
        case 15:
            system("cls");
            i.search_by_age();
            break;
        case 16:
            system("cls");
            i.search_by_profession();
            break;
        case 17:
            system("cls");
            i.search_by_gender();
            break;
        case 18:
            system("cls");
            main();
            break;
        }
    }
}
void second_menu()
{
     textcolor(WHITE);
    gotoxy(50,14);
    printf("1. Search by Reference Id");
    gotoxy(50,15);
    printf("2. Search by Age");
    gotoxy(50,16);
    printf("3. Search by Profession");
    gotoxy(50,17);
    printf("4. Search by Gender");
    gotoxy(50,18);
    printf("5. Main Menu");
}
int control_second_menu()
{
    textbackground(0);
    system("cls");
     box(3,24,5,100,5);
    gotoxy(50,4);
    textcolor(YELLOW);
    printf(" *** SEARCHING STATISTICS *** ");
    gotoxy(80,5);
    cout<<"~By CGMP";
    box(7,24,25,100,RED);
    box(9,28,23,96,CYAN);
     int x=78,y=14;
    box(14,48,18,78,YELLOW);
    box(y,48,y,78,BLACK);
    char ch;
    while(ch!=13)
    {
        second_menu();
        box(27,30,28,94,6);
        gotoxy(33,27);
        textcolor(BLACK);
       if(y==14)
       cout<<"Search Vaccination Record by Reference id  .....";
       else if(y==15)
       cout<<"Search Vaccination Record by Age ";
       else if(y==16)
       cout<<"Search Vaccination Record by Profession";
       else if(y==17)
        cout<<"Search Vaccination Record by Gender";
        else
            cout<<"To go to Main menu ";
       gotoxy(x,y);
        ch=getch();
        switch(ch)
        {
        case 72:
            y--;
            box(y+1,48,y+1,78,YELLOW);
            break;
        case 80:
            y++;
            box(y-1,48,y-1,78,YELLOW);
            break;
        }
        if(y<14)
            y=18;
      else  if(y>18)
            y=14;
        box(y,48,y,78,BLACK);
    }
    textcolor(WHITE);
    textbackground(BLACK);
    return y;
}
