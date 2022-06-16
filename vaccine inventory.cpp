#include <iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include"../conio2.h"
using namespace std;
void add_new();
void show_available_vaccine();
void update_vaccine_quantity();
void first_menu();
int control_first_menu();
void box(int,int ,int ,int, int);
void search();
int search_specific_vaccine(int );
int main();
struct record
{
    int vaccine_code;
    char name_of_vaccine[40];
    long quantity;
    int gap_bw_dose;
};
void vaccine_inventory()
{
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    int ch;
    while(1)
        {
            ch=control_first_menu();
            switch(ch)
            {
              case 14:
                  add_new();
                  break;
              case 15:
                   show_available_vaccine();
                 break;
              case 16:
                  search();
                 break;
              case 17:
                  update_vaccine_quantity();
                  break;
              case 18:
                   main();
                break;
            }
        }
}
void first_menu()
{
     textcolor(WHITE);
    gotoxy(50,14);
    printf("1. Add New Vaccines");
    gotoxy(50,15);
    printf("2. Show Available Vaccines");
    gotoxy(50,16);
    printf("3. Search Vaccine");
    gotoxy(50,17);
    printf("4. Update Vaccine Quantity");
    gotoxy(50,18);
    printf("5. Back to previous menu");
}
int control_first_menu()
{
    textbackground(0);
    system("cls");
     box(3,24,5,100,5);
    gotoxy(50,4);
    textcolor(YELLOW);
    printf(" *** VACCINE INVENTORY SYSTEM *** ");
    gotoxy(78,5);
    cout<<"~By CGMP";
    box(7,24,25,100,RED);
    box(9,28,23,96,CYAN);
     int x=78,y=14;
    box(14,48,18,78,YELLOW);
    box(y,48,y,78,BLACK);
    char ch;
    while(ch!=13)
    {
        first_menu();
        box(27,30,28,94,6);
        gotoxy(33,27);
        textcolor(BLACK);
       if(y==14)
       cout<<"Add new vaccines to this hospital or covid ward .....";
       else if(y==15)
       cout<<"Show All available vaccines ";
       else if(y==16)
       cout<<"Search a specific vaccine by vaccine code";
       else if(y==17)
        cout<<"Update quantity of vaccines (Add more vaccine)";
       else
       cout<<"To Back to previous menu";
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
void add_new()
{
    system("cls");
    textbackground(BLACK);
    textcolor(WHITE);
    box(2,40,4,84,LIGHTGREEN);
    gotoxy(45,3);
    cout<<"ADD NEW VACCINE TO INVENTORY";
    gotoxy(68,4);
    cout<<"~By CGMP";
    FILE *fp;
    record r;
    fp = fopen("vaccine.txt", "a");
    char c;
    A:
    box(6,30,15,94,YELLOW);
    textcolor(BLACK);
    gotoxy(34,7);
    printf("Enter name of the vaccine:  ");
    fflush(stdin);
    gets(r.name_of_vaccine);
    gotoxy(34,9);
    printf("Enter vaccine code:  ");
     scanf("%d",&r.vaccine_code);
     gotoxy(34,11);
    printf("Enter initial quantity of vaccine :  ");
    scanf("%ld",&r.quantity);
    gotoxy(34,13);
    printf("Enter gap between two dose of this vaccine : ");
    scanf("%d",&r.gap_bw_dose);
    fwrite(&r,sizeof(r),1, fp);
    box(17,45,17,79,LIGHTGREEN);
    gotoxy(48,17);
    textcolor(WHITE);
    printf("Your data of vaccine is inserted");
    gotoxy(48,19);
    printf("Do you want to add more Y|N  :    ");
    cin>>c;
    if(c=='Y'|| c=='y')
    goto A;
    fclose(fp);
    getch();
}
void show_available_vaccine()
{
    FILE *fp;
    record r;
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    fp = fopen("vaccine.txt","r");
    box(2,40,4,84,BLUE);
    gotoxy(47,3);
    printf("List of All Vaccines");
    if(fp==NULL)
    {
        box(7,40,7,84,RED);
        gotoxy(50,7);
        printf("Data is not created yet");
    }
    else
    {
        box(6,25,16,99,YELLOW);
        textcolor(RED);
        gotoxy(28,7);
        printf("Vaccine name           Vaccine code        Available quantity");
        gotoxy(28,8);
        printf("---------------------------------------------------------------");
        int i=10;
        while(fread(&r, sizeof(r), 1, fp))
        {
            gotoxy(28,i);
            printf("%-10s                %d   %20ld",r.name_of_vaccine,r.vaccine_code,r.quantity);
            i++;
        }
    }
    fclose(fp);
    getch();
}
void search()
{
    int c;
    int  flag = 0;
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    textcolor(BLACK);
    box(2,40,4,84,LIGHTCYAN);
    gotoxy(45,3);
    cout<<"VIEW VACCINE DETAILS BY VACCINE CODE";
    gotoxy(68,4);
    cout<<"~By CGMP";
    box(6,30,8,94,RED);
    gotoxy(36,7);
    textcolor(WHITE);
    printf("Enter vaccine code to be searched:  ");
    scanf("%d",&c);
    textbackground(BLACK);
    flag = search_specific_vaccine(c);
    if(flag==0)
    {
        box(10,24,10,100,LIGHTGREEN);
        gotoxy(30,10);
       printf("Vaccine code is not found please enter valid vaccine code...");
    }
        getch();

}
int  search_specific_vaccine(int code)
{
    FILE *fp;
    record r;
    textbackground(BLACK);
    fp = fopen("vaccine.txt","r");
    if(fp==NULL)
    {
        box(10,45,10,79,LIGHTRED);
        gotoxy(48,10);
        printf("Data is not created yet");
    }
    else
    {
        while(fread(&r, sizeof(r), 1, fp))
        {
            if(code==r.vaccine_code)
            {
                box(10,30,15,94,YELLOW);
                gotoxy(34,11);
                textcolor(RED);
                cout<<"Vaccine Name : "<<r.name_of_vaccine;
                gotoxy(34,12);
                cout<<"Vaccine Code : "<<r.vaccine_code;
                gotoxy(34,13);
                cout<<"Available Quantity : "<<r.quantity;
                gotoxy(34,14);
                cout<<"Gap between dose : "<<r.gap_bw_dose;
            fclose(fp);
             return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}
void update_vaccine_quantity()
{
    FILE *fp;
    long q;
    int code;
    int flag = 0;
    system("cls");
    textcolor(WHITE);
    textbackground(BLACK);
    fp = fopen("vaccine.txt", "r+");
    record r;
    box(2,40,4,84,LIGHTRED);
    gotoxy(45,3);
    textcolor(WHITE);
    cout<<"UPDATE VACCINE QUANTITY ";
    gotoxy(68,4);
    cout<<"~By CGMP";
    box(6,30,10,94,MAGENTA);
    gotoxy(45,7);
    printf("Enter the vaccine code to update : ");
     scanf("%d",&code);
    while(fread(&r, sizeof(r), 1, fp))
    {
        if(code==r.vaccine_code)
        {
            gotoxy(45,9);
            printf("Enter quantity to be added: ");
            scanf("%ld", &q);
            r.quantity =  q + r.quantity;
            fseek(fp,-(long)sizeof(r),1);
            fwrite(&r,sizeof(r),1, fp);
            flag =1;
            break;
        }

    }
    if(flag==1)
    {
        box(12,45,12,79,GREEN);
        gotoxy(48,12);
        printf("New Quantity added");
    }
    else
    {
        box(11,45,11,79,RED);
        gotoxy(48,11);
        printf("Vaccine code not found");
    }
    fclose(fp);
    getch();
    textbackground(BLACK);
}
