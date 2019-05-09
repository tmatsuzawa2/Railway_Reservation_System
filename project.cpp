#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<iostream>
#include<time.h>
#include<fstream>
#include <unistd.h>

using namespace std;
char f[10]="f";
char s[10]="s";
int addr,ad,flag,f1,d,m,i,amt;
int login_ch = 5;
float tamt;

class login {
public:
    char id[100];
    char pass[100];
    char *password;
    void getid() {
        cout << "Enter your id:";
        cin >> id;
        password = getpass("Enter the password:");
        strcpy(pass, password);
    }
};

class detail {
public:
    int tno;
    char tname[100];

    char bp[100];
    char dest[100];
    int c1,c1fare;
    int c2,c2fare;
    int d,m,y;

    void getdetail() {
        cout << "Enter details as following:\n";
        cout << "Train No. (a number): ";
        cin >> tno;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Train No. (a number): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> tno;
        }
        cout << "Train name (words): ";
        cin >> tname;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Train name (words): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> tname;
        }
        cout << "Boarding location (words): ";
        cin >> bp;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Boarding location (words): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> bp;
        }
        cout << "Destination location (words): ";
        cin >> dest;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Destination location (words): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> dest;
        }
        cout << "Number of seats in first class: ";
        cin >> c1;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Number of seats in first class: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> c1;
        }
        cout << "Fare per first class ticket (a number in dollars): ";
        cin >> c1fare;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Fare per first class ticket (a number in dollars): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> c1fare;
        }
        cout << "Number of seats in second class:";
        cin >> c2;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Number of seats in second class:";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> c2;
        }
        cout << "Fare per second class ticket (a number in dollars): ";
        cin >> c2fare;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Fare per second class ticket (a number in dollars): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> c2fare;
        }
        cout << "Date of travel (day):";
        cin >> d;
        while (cin.fail() || d <= 0 || d > 31) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of travel (day):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> d;
        }
        cout << "Date of travel (month):";
        cin >> m;
        while (cin.fail() || m <= 0 || m > 12) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of travel (month):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> m;
        }
        cout << "Date of travel (year):";
        cin >> y;
        while (cin.fail() || y < 2000) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of travel (year):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> y;
        }
    }
    void displaydetail() {
        cout << "\nTrain No.: " << tno << "\nTrain name: " << tname << "\nBoarding Location: "<< bp <<"\nDestination: " << dest;
        cout<< "\nFirst class seats: " << c1 << "\nFirst Class Fare: $" << c1fare <<"\nSecond class seats: "<< c2 << "\nSecond class fare: $" << c2fare;
        cout << "\nDate (date-month-year): " << d << "-" << m << "-" << y << "\n\n" << endl;
    }
};

class reser {
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosr;
    int d,m,y;
    int con;

    float amc;

    void getresdet() {
        cout << "Enter the details as follows\n";
        cout << "Train No. (a number): ";
        cin >> tno;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Train No. (a number): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> tno;
        }
        cout << "Train name (words): ";
        cin >> tname;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Train name (words): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> tname;
        }
        cout << "Boarding location (words): ";
        cin >> bp;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Boarding location (words): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> bp;
        }
        cout << "Destination location (words): ";
        cin >> dest;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Destination location (words): ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> dest;
        }
        cout << "No of seats required:";
        cin >> nosr;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "No of seats required:";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> nosr;
        }
        for(int i = 0; i < nosr; i++) {
            cout << "Passenger name:";
            cin >> pname[i];
            cout<<"Passenger age:";
            cin >> age[i];
            while (cin.fail() || age[i] <= 0) {
                cout << "Wrong format, please try again.\n";
                cout << "Passenger age:";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> age[i];
            }
        }
        cout << "Enter the class f-first class s-second class:";
        cin >> clas;
        cout << "Date of travel (day):";
        cin >> d;
        while (cin.fail() || d <= 0 || d > 31) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of travel (day):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> d;
        }
        cout << "Date of travel (month):";
        cin >> m;
        while (cin.fail() || m <= 0 || m > 12) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of travel (month):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> m;
        }
        cout << "Date of travel (year):";
        cin >> y;
        while (cin.fail() || y < 2000) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of travel (year):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> y;
        }
        cout << "Enter the concession category\n";
        cout << "1.Military\n2.Senior citizen\n";
        cout << "3.Children below 5 yrs\n4.None\n";
        cin >> con;
        while (cin.fail() || con > 4 || con < 1) {
            cout << "Wrong format, please try again.\n";
            cout << "Enter the concession category\n";
            cout << "1.Military\n2.Senior citizen\n";
            cout << "3.Children below 5 yrs\n4.None\n";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> con;
        }
        cout<<"............END OF GETTING DETAILS............\n";
    }
    
    void displayresdet() {
        cout << "...............................................\n";
        cout << "...............................................\n";
        cout << "Passenger Name Record No (PNR):" << pnr;
        cout << "\nTrain no:" << tno;
        cout << "\nTrain name:";
        puts(tname);
        cout << "Boarding location:";
        puts(bp);
        cout << "Destination:";
        puts(dest);
        cout << "No of seats reserved:" << nosr << endl;
        for(int i = 0; i < nosr; i++) {
            cout << "Passenger name:";
            puts(pname[i]);
            cout << "Passenger age:" << age[i];
        }

        cout << "\nYour class:";
        puts(clas);
        cout << "\nDate of reservation:" << d << "-" << m << "-" << y;
        cout << "\nYour concession category:" << con;
        cout << "\nYou must pay:" << amc << endl;
        cout << "***********************************************\n";
        cout << ".........END OF RESERVATION.................\n";
        cout << "***********************************************\n";
    }
};

class canc {
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    int i;
    char clas[10];
    int nosc;
    int d,m,y;
    float amr;
    void getcancdet() {
        cout << "Enter the details as follows\n";
        cout << "Passenger Name Record No:";
        cin >> pnr;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Passenger Name Record No:";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> pnr;
        }
        cout << "Date of cancellation(day):";
        cin >> d;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of cancellation(day):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> d;
        }
        cout << "Date of cancellation(month):";
        cin >> m;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of cancellation(month):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> m;
        }
        cout << "Date of cancellation(year):";
        cin >> y;
        while (cin.fail()) {
            cout << "Wrong format, please try again.\n";
            cout << "Date of cancellation(year):";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> y;
        }
        cout<<"...........END OF GETTING DETAILS...........\n";
    }
    void displaycancdet() {
        cout << "...........................................\n";
        cout << "...........................................\n";
        cout << "Passenger Name Record No: "<<pnr;
        cout << "\nTrain no:"<<tno;
        cout << "\nTrain name:";
        puts(tname);
        cout << "Boarding location:";
        puts(bp);
        cout << "Destination:";
        puts(dest);
        cout << "\nYour class:";
        puts(clas);
        cout << "no of seats to be cancelled:"<<nosc;
        for(int i = 0; i < nosc; i++) {
            cout << "Passenger name:";
            puts(pname[i]);
            cout << "passenger age:"<<age[i];
        }
        cout << "\nDate of cancellation:" << d << "-" << m << "-" << y;
        cout << "\nYou can collect:" << amr << "rs" << endl;
        cout << "*****************************************\n";
        cout << ".........END OF CANCELLATION.............\n";
        cout << "*****************************************\n";
    }
};

/* Failed method
void readData() {
    int tno;
    char tname[100];
    char bp[100];
    char dest[100];
    int c1,c1fare;
    int c2,c2fare;
    int d,m,y;
    int i = 0;

    fstream f; 

    // Open an existing record 
    fin.open("data.csv", ios::in); 
    while (i = 0) {
        getline(f, tno, ',')
        getline(f, tname, ',');
        getline(f, bp, ',');
        getline(f, dest, ',');
        getline(f, c1, ',');
        getline(f, c1fare, ',');
        getline(f, c2, ',');
        getline(f, c2fare, ',');
        getline(f, d, ',');
        getline(f, m, ',');
        getline(f, y, ',');
        //Then call the getdetail() method with the information I get.
        i++;
    }
}
*/

void displaypassdetail() {
    fstream f;
    reser b;
    f.open("p.txt",ios::in|ios::out|ios::binary);
    f.seekg(0);
    while(f.read((char *) & b,sizeof(b))) {
        b.displayresdet();
    }
    f.close();
}

void res() {
    detail a;
    reser b;
    fstream f1,f2;
    time_t t;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
    int ch;
    b.getresdet();
    while (f1.read((char *) &a, sizeof(a))) {
        if (a.tno == b.tno) {
            if (strcmp(b.clas,f) == 0) {
                if (a.c1 >= b.nosr) {
                    amt = a.c1fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c1);
                    f1.seekp(addr-(7*ad));
                    a.c1 = a.c1 - b.nosr;
                    f1.write((char *) & a.c1, sizeof(a.c1));
                    if (b.con == 1) {
                        cout << "Concession category: MILITARY PERSONNEL\n";
                        b.amc = b.nosr*((amt*50)/100);
                    }
                    else if (b.con == 2) {
                        cout << "Concession category: SENIOR CITIZEN\n";
                        b.amc = b.nosr*((amt*60)/100);
                    }
                    else if (b.con == 3) {
                        cout << "Concession category: CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4) {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr*amt;
                    }
                    srand((unsigned) time(&t));
                    b.pnr = rand();
                    f2.write((char *) & b, sizeof(b));
                    b.displayresdet();
                    cout << "------------------------------------------------------\n";
                    cout << "--------------Your ticket is reserved-----------\n";
                    cout << "-----------------End of reservation menu-------\n";
                }
                else {
                    cout << "**********We are sorry, the required seats are not available********\n";
                }
            }
            else if (strcmp(b.clas,s) == 0) {
                if (a.c2 >= b.nosr) {
                    amt = a.c2fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c2);
                    f1.seekp(addr-(5*ad));
                    a.c2 = a.c2 - b.nosr;
                    f1.write((char *) & a.c2, sizeof(a.c2));
                    if (b.con == 1) {
                        cout << "Concession category:MILITARY PRESONNEL\n";
                        b.amc = b.nosr*((amt*50)/100);
                    }
                    else if (b.con == 2) {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr*((amt*60)/100);
                    }
                    else if (b.con == 3) {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4) {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr*amt;
                    }
                    f2.write((char *) & b, sizeof(b));
                    b.displayresdet();
                    cout << "---------------------------------------\n";
                    cout << "--------Your ticket is reserved--------\n";
                    cout << "------------End of reservation---------\n";
                }
                else {
                    cout << "********Sorry required number of seats not available*******\n";
                }
            }
            goto h;
        }
        else {
            flag = 0;
        }
    }
    if (flag == 0) {
        cout << "............Wrong train no......................\n";
        cout << "......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();

h: cout<<"\n\nReturning to the user page:\n\n";
}

void reserve() {
    int ch;
    do {
        cout<<"1.Reserve\n2.Return to the main menu\n";
        cout<<"Enter your choice:";
        cin>>ch;
        cout<<endl;
        switch(ch) {
        case 1:
            res();
            break;
        }
    }
    while (ch == 1);
}

void enquiry() {
    fstream f;
    f.open("t.txt", ios::in|ios::out|ios::binary);
    detail a;
    while (f.read((char *) & a, sizeof(a))) {
        a.displaydetail();
    }
}

void cancell() {
    detail a;
    reser b;
    canc c;
    fstream f1,f2;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    cout << "**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while (f2.read((char *) & b, sizeof(b))) {
        if (b.pnr == c.pnr) {
            c.tno = b.tno;
            strcpy(c.tname,b.tname);
            strcpy(c.bp,b.bp);
            strcpy(c.dest,b.dest);
            c.nosc = b.nosr;
            for (int j = 0; j < c.nosc; j++) {
                strcpy(c.pname[j],b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas,b.clas);
            if (strcmp(c.clas,f) == 0) {
                while (f1.read((char *) & a, sizeof(a))) {
                    if (a.tno == c.tno) {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c1);
                        f1.seekp(addr-(7*ad));
                        f1.write((char *) & a.c1, sizeof(a.c1));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m)) {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt*60)/100);
                        }
                        else if (c.m == m) {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt*50)/100);
                        }
                        else if (m > c.m) {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt*20)/100);
                        }
                        else {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
            else if (strcmp(c.clas,s) == 0) {
                while (f1.read((char *) & a, sizeof(a))) {
                    if (a.tno == c.tno) {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c2);
                        f1.seekp(addr-(5*ad));
                        f1.write((char *) & a.c2, sizeof(a.c2));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m)) {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt*60)/100);
                        }
                        else if (c.m == m) {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt*50)/100);
                        }
                        else if (m > c.m) {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt*20)/100);
                        }
                        else {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
        }
        else {
            flag = 0;
        }
    }
h:
    if (flag == 0) {
        cout << "Entered the wrong pnr no\n";
    }
    f1.close();
    f2.close();
}

void can() {
    int ch;
    do {
        cout << ".................CANCELLATION MENU.........\n";
        cout << "1.Cancell\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch) {
            case 1:
                cancell();
                break;
        }
    }
    while (ch == 1);
}

void manage() {
    int ch;
    fstream f;
    char c;
    login a;
    cout << ".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do {
        cout << "1.Create id data base (Warning: only do it once otherwise precious data will be lost!)\n2.Add another user\n";
        cout << "3.Return to the main menu\n";
        cout << "Enter your choice: ";
        cin >> ch;
        //When the user type in something other number, this while loop will run until the input info is correct
        while (cin.fail()) {
            cout << "\nWrong format, please try again.\n";
            cout << "1.Create id data base (Warning: only do it once otherwise precious data will be lost!)\n2.Add another user\n";
            cout << "3.Display details\n4.Return to the main menu\n";
            cout << "Enter your choice: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> ch;
        }
        cout << endl;

        switch (ch) {
            case 1:
                f.open("id.txt", ios::out|ios::binary);
                do {
                    a.getid();
                    f.write((char *) & a, sizeof(a));
                    cout << "Do you want to add more record\n";
                    cout << "y-Yes\nn-No\n";
                    cin >> c;
                    //you can input in upper or lower letter
                    while (c != 'n' && c != 'N' && c != 'y' && c != 'Y') {
                        cout << "\nWrong format, please try again.\n";
                        cout << "Do you want to add more record?\n";
                        cout << "y-for Yes\nn-for No\n";
                        cin >> c;
                    }
                }
                while(c == 'y' || c == 'Y');
                f.close();
                break;
            case 2:
                f.open("id.txt", ios::in|ios::out|ios::binary|ios::app);
                a.getid();
                f.write((char *) & a, sizeof(a));
                f.close();
                break;
            default: 
                cout << "\nWrong format, please try again.\n";
        }
    }
    while(ch <= 2);
}

//the administrator page
void admin() {
    char *password;
    //the admin password!
    const char *pass = "ILOVECS368";
    password = getpass("Enter the administrator password:");
    detail a;
    fstream f;
    int ch;
    char c;
    //If wrong password, jump to the end
    if (strcmp(pass, password) != 0) {
        cout << "\nYour password is incorrect! \n";
        cout << "You are not permitted to login this mode\n\n";
        login_ch--;
        cout << login_ch << " chances remaining\n";
        if (login_ch == 0) {
            exit(0);
        }
        goto h;
    }
    if(strcmp(pass, password) == 0) {
        char c;
        do {
            cout << "...........ADMINISTRATOR MENU...........\n";
            cout << "1.Create/Recreate a new detail data base (Warning: only do it once otherwise precious data will be lost!)\n2.Add details\n";
            cout << "3.Display details\n4.User management\n";
            cout << "5.Display passenger details\n6.Return to main menu\n";
            cout << "Enter your choice: ";
            cin >> ch;
            //When the user type in something other number, this while loop will run until the input info is correct
            while (cin.fail()) {
                cout << "\nWrong format, please try again.\n";
                cout << "1.Create/Recreate a new detail data base (Warning: only do it once otherwise precious data will be lost!)\n2.Add details\n";
                cout << "3.Display details\n4.User management\n";
                cout << "5.Display passenger details\n6.Return to main menu\n";
                cout << "Enter your choice: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> ch;
            }
            cout << endl;

            //Different subpages according to choices
            switch (ch) {
                case 1:
                    f.open("t.txt", ios::out|ios::binary);
                    do {
                        a.getdetail();
                        f.write((char *) & a, sizeof(a));
                        cout << "Do you want to add more record?\n";
                        cout << "y-for Yes\nn-for No\n";
                        cin >> c;
                        //you can input in upper or lower letter
                        while (c != 'n' && c != 'N' && c != 'y' && c != 'Y') {
                            cout << "\nWrong format, please try again.\n";
                            cout << "Do you want to add more record?\n";
                            cout << "y-for Yes\nn-for No\n";
                            cin >> c;
                        }
                    }
                    while (c == 'y' || c == 'Y');
                    f.close();
                    break;
                case 2:
                    f.open("t.txt", ios::in|ios::out|ios::binary|ios::app);
                    a.getdetail();
                    f.write((char *) & a, sizeof(a));
                    f.close();
                    break;
                case 3:
                    f.open("t.txt", ios::in|ios::out|ios::binary|ios::app);
                    f.seekg(0);
                    while(f.read((char *) & a, sizeof(a))) {
                        a.displaydetail();
                    }
                    f.close();
                    break;
                case 4:
                    manage();
                    break;
                case 5:
                    displaypassdetail();
                    break;
            }
        }
        while(ch <= 5);
        f.close();
    }
//return to the previous page
h: cout << "\nReturning to the main menu...\n";
}

void user() {
    login a;
    int ch;
    int d = 0;
    cout << "*****************************************************\n";
    cout << "***********WELCOME TO THE USER MENU***********\n";
    cout << "****************************************************\n";
    char *password;

    fstream f;
    f.open("id.txt",ios::in|ios::out|ios::binary);
    char id[100];
    puts("Enter your id:");
    cin >> id;
    password=getpass("Enter your password:");
    while (f.read((char *) & a, sizeof(a))) {
        if ((strcmp(a.id,id) == 0) && (strcmp(a.pass,password) == 0)) {
            do {
                cout << "1.Reserve\n2.Cancell\n3.Enquiry\n4.Return to the main menu\n";
                cout << "Enter your choice:";
                cin >> ch;
                cout << endl;
                switch(ch) {
                    case 1:
                        reserve();
                        break;
                    case 2:
                        can();
                        break;
                    case 3:
                        enquiry();
                        break;
                }
            }
            while (ch <= 3);
            goto j;
        }
        else {
            d = 1;
        }
    }
    if (d == 1) {
        cout << "Enter your user id and password correctly\n";
    }
j: cout << "\nReturning to the main menu...\n";
}

//the main method (main menu page)
int main() {
    int ch;
    cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << ".......WELCOME TO TRAIN TICKET RESERVATION SYSTEM..........\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cin.clear();
    do {
        cout << "\n^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
        cout << "1.Admin mode\n2.User mode\n3.Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;
        //When the user type in something other number, this while loop will run until the input info is correct
        while (cin.fail()) {
            cout << "\nWrong format, please try again.\n";
            cout << "1.Admin mode\n2.User mode\n3.Exit\n";
            cout << "Enter your choice: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> ch;
        }
        cout << endl;

        //Different subpages loaded when choice is made
        switch(ch) {
            case 1:
                admin();
                break;
            case 2:
                user();
                break;
            case 3:
                exit(0);
            default: 
                cout << "\nWrong format, please try again.\n";
        }
    }
    while (true);
    
    return 0;
}
