#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <cstring>
using namespace std;
class travel
{
public:
int tf;
int rf;
void setTrainfare()
{
    tf = 2500;
}
void setRoadfare()
{
    rf = 1500;
}
};
class tour : public travel
{
public:
//data members
string name;
string gen;
string address;
int age;
double mob_num;

tour *next, *Head;
//useful member functions
friend void heading();
friend void details();
friend void india();
friend void modification();
friend void receipt();
};

// Head pointer with NULL
tour *Head = NULL;
// Tour class pointer
tour *pt;
// Global variable for AMOUNT & NO.OF PEOPLE
int amt = 0, k;
// Global variable for NO.OF PASSENGERS
char str1[100];
char str2[100];
char place[100];
string date;

tour *newptr = Head;
tour *ptr;
int flag = 0;

void add_pass(string n, string g, int a, double mb, string ad)
{
    newptr = new tour();
    newptr->name = n;
    newptr->gen = g;
    newptr->age = a;
    newptr->mob_num = mb;
    newptr->address = ad;
    newptr->next = NULL;
    if(Head == NULL)
    {
        Head = newptr;
        
    }
    else
    {
        ptr=Head;
        while(ptr->next != NULL)
        ptr = ptr->next;
        ptr->next = newptr;
    }   
}

void heading()
{
    cout << "\t\t\t\t\t\t**** WELCOME ****\n";
    cout << "\t\t\t\t\t**** S & S Tours and TRAVELS ****\n";
}
int ch;
int amnt;
// this function show the modes of travel
void mode_of_travel()
{
    system("CLS");
    heading();
    cout << endl;
    cout << "\t\t\t\t\t Select the MODE OF TRAVEL: ";
    cout << endl;
    cout << "\t\t\t\t\t 1.BY TRAIN" << endl;
    cout << "\t\t\t\t\t 2.BY ROAD" << endl;
    cout << "\t\t\t\t\t Enter Choice for Mode Of Travel : ";
    cin >> ch;
    if(ch == 1)
    {
        amnt=2500;
        strcpy(str2,"BY TRAIN");
    }
    else if(ch == 2)
    {
        amnt=1500;
        strcpy(str2,"BY BUS");
    }
    else
    {
        cout<<"\t\t\t\t\tEnter the correct choice: ";
    }
}

void india()
{
    int a;
    heading();
    system("CLS");
    cout << "\t\t\t\t\t\t******* MAIN MENU *******\n"<< endl;
    cout << "\t\t\t\t\t\t******* INDIA TOUR PACKAGES *******\n"<< endl;
    cout << "\t\t\t\t\t\t1.Kerala Tour 6 Days 7 Nights (25,000/person)\n"<< endl;
    cout << "\t\t\t\t\t\t2.Manali Tour 5 Days 6 Nights (20,000/person)\n"<< endl;
    cout << "\t\t\t\t\t\t3.Agra Tour 4 Days 5 Nights (20,000/person)\n"<< endl;
    cout << "\t\t\t\t\t\t4.Goa Tour 3 Days 4 Nights (18,000/person)\n"<< endl;
    cout << "\t\t\t\t\t\t5.Ooty Tour 3 Days 4 Nights (16,000/person)\n"<< endl;
    cout << "\t\t\t\t\tEnter Your Choice : ";
    cin >> a;
    //mode of travel choice variable
    int choice;
    switch(a)
    {
        case 1:
        amt = 25000;
        strcpy(str1, "Kerala Tour 6 Days 7 Nights");
        break;
        case 2:
        amt = 20000;
        strcpy(str1, "Manali Tour 5 Days 6 Nights");
        break;
        case 3:
        amt = 20000;
        strcpy(str1, "Agra Tour 4 Days 5 Nights");
        break;
        case 4:
        amt = 18000;
        strcpy(str1, "Goa Tour 3 Days 4 Nights");
        break;
        case 5:
        amt = 16000;
        strcpy(str1, "Ooty Tour 3 Days 4 Nights");
        break;
        default:
        cout << "\t\t\t\t\tEnter Your Choice:";
        break;
    }
}
//This function used to print the desired output.
void reciept()
{
    system("CLS");
    heading();
    tour *ptr1 = Head;
    cout << endl;
    cout << "\t\t\t\t\t***BOOKING CONFIRMED*****";
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t***PASSENGERS INFORMATION*****" <<endl;
    cout << endl;
    for(int i = 1; i<= k;i++)
    {
        cout << endl;
        cout << "\t\t\t\t\tPassenger "<< i << " Information" << endl;
        cout << endl;
        cout << "\t\t\t\t\t Passenger Name : " << ptr1->name << endl;
        cout << "\t\t\t\t\t Passenger Gender : " << ptr1->gen << endl;
        cout << "\t\t\t\t\t Passenger Age : " << ptr1->age << endl;
        cout << "\t\t\t\t\t Passenger Mobile Number : " << ptr1->mob_num << endl;
        cout << "\t\t\t\t\t Passenger Address : " << ptr1->address << endl;
        ptr1 = ptr1->next;
    } 
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t***************************************" << endl;
    cout << "\t\t\t\t\tSelected Package : " << str1 << endl;
    cout << "\t\t\t\t\tDeparture Date : " << date << endl;
    cout << "\t\t\t\t\tMode of Travel : " << str2 << endl;
    long long x1 = (amt * k);
    long long x2 = (amnt * k);
    long long x3 = x1 + x2;
    cout << "\t\t\t\t\tTourism Amount : " << x1 << endl;
    cout << "\t\t\t\t\tTravelling Amount : " << x2 << endl;
    cout << "\t\t\t\t\tTotal Amount : " << x3 << endl;
    cout << endl;
    cout << "\t\t\t\t****Your Booking details will be sent on the Registered Mobile Number***\n"<< endl;
    cout << "\t\t\t\t\t****Thank You for planning your trip with us***\n";
}

//Details function required to get the passengers details
void details()
{
    string nme, gn, ad;
    int age;
    long long mb;
    system("CLS");
    heading();
    cout << endl;
    cout << "\t\t\t\t\tEnter the Number of Passengers : ";
    cin >> k;
    cout << "t\t\t\t\tEnter Date of Journey (DD/MM/YY) : ";
    cin.ignore();
    getline(cin, date);
    for(int i =1; i <= k; i++)
    {
        system("CLS");
        heading();
        cout << "\t\t\t\t\tEnter the " << i <<" Passenger Name : ";
        fflush(stdin);
        getline(cin, nme);
        cout << "\t\t\t\t\tEnter the Gender of " << i <<" Passenger : ";
        fflush(stdin);
        getline(cin, gn);
        cout << "\t\t\t\t\tEnter the Age of " << i <<" Passenger : ";
        cin >> age;
        cout << "\t\t\t\t\tEnter the Mobile Number of " << i <<" Passenger : ";
        cin >> mb;
        cout << "\t\t\t\t\tEnter the Address of " << i <<" Passenger : ";
        fflush(stdin);
        getline(cin, ad);
        //adding passenger to a list passengers
        add_pass(nme, gn, age, mb, ad);
    }
}
//function for modifying details
void modification()
{
    system("CLS");
    heading();
    int ch1;
    char q;
    cout << "\t\t\t\t\tDo you want to modify your details : (Press y/n to  continue)";
    cin >> q;
    if(q == 'n')
    reciept();
    else
    {
        cout << "\t\t\t\t\tChoose your modification section " << endl;
        cout << "\t\t\t\t\t1.Do you want to add Passenger : " << endl;
        cout << "\t\t\t\t\t2.Do you want to modify Package : " << endl;
        cout << "\t\t\t\t\t3.Do you want to modify Mode of Travel : " << endl;
        cout << "\t\t\t\t\tEnter Your Choice : ";
        cin >> ch1;
        switch(ch1)
        {
            case 1:
            details();
            k++;
            break;
            case 2:
            india();
            break;
            case 3:
            mode_of_travel();
            break;
            default:
            cout << "\t\t\t\t\tPlease choose correct choice";
            break;
        }
        reciept();
    }
}
//Driver code
int main()
{
    int a;
    cout << endl;
    cout << endl;
    cout << "\t\t\t\t\t***** WELCOME *****\n";
    cout << "\t\t\t\t\t*****S & S Tours and TRAVELS ****\n";
    cout << endl;
    int choice;
    do
    {
        cout << "\t\t\t\t\t*****PRESS '1' FOR MAIN MENU******" << endl;
        cout << "\t\t\t\t\t\t";
        cin >> a;
        if(a == 1)
        {
            india();
            mode_of_travel();
            details();
            modification();
        }
        else
        {
            cout << "\t\t\t\t\tEnter Correct choice";
        }
        cout << "\t\t\t\t\tPress '0' to Continue : " << endl;
        cout << "\t\t\t\t\tPress 'Enter' to Exit : " << endl;
        cout << "\t\t\t\t\t\t";
        cin >> choice;
        system("CLS");
        heading();
    } while (choice == 0);
}
