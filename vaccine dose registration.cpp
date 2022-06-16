#include <iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<time.h>
#include"../conio2.h"
using namespace std;
void show_available_vaccine();
void box(int,int ,int ,int, int);
void get_second_dose();
int main();
int convertToInt(char a[]);
struct record
{
    int vaccine_code;
    char name_of_vaccine[40];
    long quantity;
    int gap_bw_dose;
};
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
    void second_dose();
};
void vaccine::get_next_date(int ne)
{
            int month,year,day;
            int d,m,y;

                 time_t ttime = time(0);
                 tm *local_time = localtime(&ttime);

                 y=1900 + local_time->tm_year;
                 m=1 + local_time->tm_mon;
                 d=local_time->tm_mday ;
                  string strid = to_string(d);
        string strim = to_string(m);
        string strio = to_string(y);
        string symbol("/");
        string currentdate=strid+symbol+strim+symbol+strio;
        char temp_date1[10];
        for(int i=0;i<currentdate.length();i++)
        {
            temp_date1[i]=currentdate[i];
        }
        strcpy(first_dose_date,temp_date1);
         int m2[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
         int i,k=0,p,a;
         for(i=0;i<m;i++)
          k=k+m2[i];
         k=k+d+ne;
         if(k<=365)
         {
          for(i=0;i<13;i++)
          {
           p=k-m2[i];
           if(p<=m2[i+1])
           {
            a=i+1;
            break;
           }
           else
            k=p;
          }
          string strip = to_string(p);
        string stria = to_string(a);
        string striy = to_string(y);
        string symbol("/");
        string newdate=strip+symbol+stria+symbol+striy;
        char temp_date2[10];
        for(int i=0;i<newdate.length();i++)
        {
            temp_date2[i]=newdate[i];
        }
        strcpy(date_next,temp_date2);
         }
         else
         {
          k=k-365;
           for(i=0;i<13;i++)
            {
             p=k-m2[i];
             if(p<=m2[i+1])
             {
               a=i+1;
               break;
             }
             else
              k=p;
            }
        string strip = to_string(p);
        string stria = to_string(a);
        string striy = to_string(y+1);
        string symbol("/");
        string newdate=strip+symbol+stria+symbol+striy;
        char temp_date2[10];
        for(int i=0;i<newdate.length();i++)
        {
            temp_date2[i]=newdate[i];
        }
        strcpy(date_next,temp_date2);
         getch();
         }
}
void vaccine::user_input()
{
    ofstream fout("vaccinationdata.txt",ios::app);
    fflush(stdin);
    box(3,40,5,84,YELLOW);
    textcolor(RED);
    gotoxy(55,4);
    cout<<"Vaccine Dose Registration ";
    gotoxy(60,5);
    cout<<"~By CGMP";
    getch();
    box(7,30,34,94,LIGHTCYAN);
    gotoxy(35,9);
        cout<<"Enter your name :-  ";
        gets(name);
        gotoxy(35,11);
        cout<<"Enter your aadhar :-  ";
        gets(aadhar);
        fflush(stdin);
        gotoxy(35,13);
        cout<<"Enter your gender (M|F) :-  ";
        cin>>gender;
        gotoxy(35,15);
        cout<<"Enter your age:- ";
        cin>>age;
        fflush(stdin);
        gotoxy(35,17);
        cout<<"Enter your profession :-  ";
        gets(profession);
        fflush(stdin);
        gotoxy(35,19);
        cout<<"Enter your B.P. :-  ";
        cin>>blood_pressure;
        gotoxy(35,21);
        cout<<"Enter your Body temperature:-  ";
        cin>>temperature;
        fflush(stdin);
        gotoxy(35,23);
        cout<<"Enter your permanent address :-  ";
        gets(address);
        gotoxy(35,25);
        cout<<"Enter your Mobile number :- ";
        gets(mobile_number);
        ref_id=convertToInt(aadhar)+convertToInt(mobile_number);
        if(ref_id < 0)
            ref_id =  0 - ref_id ;
            gotoxy(35,27);
        cout<<"Your ref id is : "<<ref_id;
        getch();
        gotoxy(45,29);
        textbackground(BLACK);
        show_available_vaccine();
        int v_code,gap,flag=0;
        gotoxy(35,19);
        cout<<"Enter the vaccine code which you want to take : ";
        cin>>v_code;
        FILE *fp;
        fp = fopen("vaccine.txt","r+");
        struct record r;
        while(fread(&r, sizeof(r), 1, fp))
        {
            if(v_code==r.vaccine_code)
            {
                if(r.quantity>0)
                    {
                         strcpy(vaccine_name,r.name_of_vaccine);
                         strcpy(first_dose_status,"DONE");
                         strcpy(second_dose_status,"Pending");
                         gap=r.gap_bw_dose;
                         r.quantity = r.quantity-1;
                         fseek(fp,-(long)sizeof(r),1);
                         fwrite(&r,sizeof(r),1, fp);
                         get_next_date(gap);
                         fout.write((char *)this,sizeof(vaccine));
                         box(21,40,21,84,GREEN);
                         gotoxy(42,21);
                         cout<<"You have successfully registered for your first dose of vaccine ";
                         textcolor(WHITE);
                         box(23,30,31,94,CYAN);
                        gotoxy(34,24);
                        cout<<"Name : "<<name;
                        gotoxy(34,25);
                        cout<<"Your Reference id : "<<ref_id;
                        gotoxy(34,26);
                        cout<<"Aadhar number : "<<aadhar;
                        gotoxy(34,27);
                        cout<<"Mobile_number : "<<mobile_number;
                        gotoxy(34,28);
                        cout<<"Vaccine Name : "<<vaccine_name;
                        gotoxy(34,29);
                        cout<<"2nd Dose Date : "<<date_next;
                        box(30,34,30,90,RED);
                        gotoxy(34,30);
                        cout<<"Please Remember this reference id for 2nd dose registration";
                        gotoxy(38,40);
                         getch();
                }
                else
                    {
                        box(21,40,21,84,RED);
                         gotoxy(42,21);
                        cout<<"You don't have sufficient quantity of "<<r.name_of_vaccine;
                        getch();
                    }
                flag=1;
                        break;
            }
        }
        if(flag==0)
        {
            box(21,40,21,84,RED);
            gotoxy(42,21);
            textcolor(WHITE);
            cout<<"wrong vaccine code";
            getch();
        }
        fclose(fp);
        fout.close();
}
void vaccine_management()
{
    system("cls");
    textcolor(WHITE);
    textbackground(WHITE);
    vaccine v;
    v.user_input();
}
int convertToInt(char a[])
{
    int i = 0;
    int num = 0;
    while (a[i] != 0)
    {
        num =  (a[i] - '0')  + (num * 10);
        i++;
    }
    return num;;
}
void showdata()
{
    vaccine v1;
    ifstream fin("vaccinationdata.txt");
    while(fin.read((char*)&v1,sizeof((v1))))
    {
        cout<<"Reference id : "<<v1.ref_id<<endl;
        cout<<"name: "<<v1.name<<endl;
        cout<<"Aadhar number "<<v1.aadhar<<endl;
        cout<<"Gender : "<<v1.gender<<endl;
        cout<<"Age: "<<v1.age<<endl;
        cout<<"Profession : "<<v1.profession<<endl;
        cout<<"Blood Pressure : "<<v1.blood_pressure<<endl;
        cout<<"Temperature : "<<v1.temperature<<endl;
        cout<<"Address : "<<v1.address<<endl;
        cout<<"Mobile number : "<<v1.mobile_number<<endl;
        cout<<"Vaccine name : "<<v1.vaccine_name<<endl;
        cout<<"first dose status "<<v1.first_dose_status<<endl;
        cout<<"second dose status : "<<v1.second_dose_status<<endl;
        cout<<"first dose date : "<<v1.first_dose_date<<endl;
        cout<<"second dose date : "<<v1.date_next<<endl;
    }
    fin.close();
}
void get_second_dose()
{
    vaccine v;
    v.second_dose();
}
void vaccine::second_dose()
{
    system("cls");
    textbackground(BLACK);
    textcolor(WHITE);
    box(2,30,4,94,RED);
    gotoxy(45,3);
    cout<<"Second dose status";
    long long int ref_num;
    int flag=0;
    box(6,36,8,88,CYAN);
    gotoxy(45,7);
    cout<<"Enter reference number: ";
    cin>>ref_num;
    fstream fin("vaccinationdata.txt",ios::in|ios::ate|ios::out);
    fin.seekg(0);
    fin.read((char*)this,sizeof(vaccine));
    while(!fin.eof())
    {
        if(ref_id==ref_num)
        {
                    strcpy(second_dose_status," DONE ");
                    flag=1;
                    fin.seekp(fin.tellp()- sizeof(vaccine));
                    fin.write((char *)this,sizeof(vaccine));
                    box(10,30,10,94,GREEN);
                    gotoxy(33,10);
                    cout<<"Congratulations ! You have successfully done your second dose of vaccination";
                    box(12,24,18,100,YELLOW);
                    gotoxy(26,13);
                    textcolor(RED);
                    cout<<"But still you have to follow these rules and regulations : ";
                    gotoxy(26,14);
                    cout<<"1. Wear mask properly ";
                    gotoxy(26,15);
                    cout<<"2. Maintain social distancing of at least 1 meter";
                    gotoxy(26,16);
                    cout<<"3.  Stay away from crowded areas ";
                    getch();
                    break;
        }
        fin.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        box(10,40,10,84,RED);
        gotoxy(50,10);
        cout<<"Incorrect refference id";
        box(12,45,12,79,YELLOW);
        gotoxy(52,12);
        textcolor(BLACK);
        cout<<"Please enter again ";
        getch();
    }
    fin.close();
    textbackground(BLACK);
    system("cls");
}


