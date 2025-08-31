#include <bits/stdc++.h>
using namespace std;

int c = 1;

class hostel {
    int rooms[10][13][5]; // safer size for 1-based indexing [floor][room][bed]
    string fname, lname, roll_no, place;
    int floor;
    int b1 = 1, b2 = 2, b3 = 3, b4 = 4;

public:
    hostel() { memset(rooms, 0, sizeof(rooms)); loadBookings(); }

    void login();
    void two_sharing();
    void three_sharing();
    void four_sharing();
    void display();
    void display2();
    void display3();
    void display4();

private:
    void loadBookings();  // load data from files into memory
};

void hostel::login() {
    cout << "********** LOGIN PORTAL *********\n";
    cout << "\nLogin your account or else Create Account ";
    cout << "\n1.Create\n2.Login" << endl;
    int k;
    string email, pass, name, mobile, e, p, n, m, em, pas;
    cout << "Enter your choice: ";
    cin >> k;

    if (k == 1) {
        cout << "Enter Name : ";
        cin >> name;
        cout << "Enter Mobile : ";
        cin >> mobile;
        cout << "Enter Email: ";
        cin >> email;
        cout << "Enter Password : ";
        cin >> pass;
        cout << "\nYour account has been created." << endl;
        ofstream myfile("myprg.txt", ios::app);
        myfile << name << " " << mobile << " " << email << " " << pass << endl;
        myfile.close();
    } else if (k == 2) {
        int co = 0; // 
        cout << "Enter Email: ";
        cin >> e;
        cout << "Enter Password : ";
        cin >> p;
        ifstream myfile1("myprg.txt");
        while (myfile1 >> n >> m >> em >> pas) {
            if (em == e && pas == p) {
                cout << "Login successful" << endl;
                co = 1;
            }
        }
        if (co == 0) {
            cout << "\nSorry! incorrect id or password" << endl;
            cout << "\nTry again please" << endl;
            exit(0);
        }
        myfile1.close();
    }
}

void hostel::two_sharing() {
    int room;
    cout << "\nTWO SHARING ROOMS are only AVAILABLE in FLOOR 1, 2 AND 3.\n";
    cout << "\nWhich floor do you prefer: ";
    cin >> floor;
    while (floor > 3 || floor < 1) {
        cout << "\nInvalid option, please choose a valid floor number\n";
        cout << "\nWhich floor do you prefer: ";
        cin >> floor;
    }
    cout << "\nEnter a room number from 1 to 12: ";
    cin >> room;
    while (room < 1 || room > 12) {
        cout << "\nInvalid room no. Please try again \n";
        cin >> room;
    }

    if ((rooms[floor][room][b1] == room + b1) && (rooms[floor][room][b2] == room + b2)) {
        cout << "\nSORRY!, Room is already booked, please book another \n";
    } else {
        c = floor * 100 + room;
        int bed = (rooms[floor][room][b1] != room + b1) ? b1 : b2;
        rooms[floor][room][bed] = room + bed;

        cout << "Please enter your first name: ";
        cin >> fname;
        cout << "\nEnter your last name: ";
        cin >> lname;
        cout << "\nPlease enter your full roll number: ";
        cin >> roll_no;
        cout << "\nEnter your place: ";
        cin >> place;
        cout << "\nTHANK YOU, Your room is booked\n";
        cout << "Your room number is : " << c;

        ofstream myfile("2sharing.txt", ios::app);
        myfile << fname << "   " << lname << "   " << roll_no << "   " << place << "   " << c << endl;
        myfile.close();
    }
}

void hostel::three_sharing() {
    int room;
    cout << "\nTHREE SHARING Rooms are only AVAILABLE in FLOORS 4, 5 and 6" << endl;
    cout << "\nWhich floor do you prefer: ";
    cin >> floor;
    while (floor < 4 || floor > 6) {
        cout << "\nInvalid option, please choose a valid floor number\n";
        cin >> floor;
    }
    cout << "\nEnter a room number from 1 to 12: ";
    cin >> room;
    while (room < 1 || room > 12) {
        cout << "\nInvalid room number, please try again: " << endl;
        cin >> room;
    }

    if ((rooms[floor][room][b1] == room + b1) && (rooms[floor][room][b2] == room + b2) && (rooms[floor][room][b3] == room + b3)) {
        cout << "\nSORRY!, Room is already booked, Please book another room" << endl;
    } else {
        c = floor * 100 + room;
        int bed = (rooms[floor][room][b1] != room + b1) ? b1 :
                  (rooms[floor][room][b2] != room + b2) ? b2 : b3;
        rooms[floor][room][bed] = room + bed;

        cout << "Enter your first name: ";
        cin >> fname;
        cout << "\nEnter your last name: ";
        cin >> lname;
        cout << "\nEnter your full roll no: ";
        cin >> roll_no;
        cout << "\nEnter your place: ";
        cin >> place;
        cout << "\nTHANK YOU, Your room is booked\n";
        cout << "\nYour room number is : " << c;

        ofstream file("3sharing.txt", ios::app);
        file << fname << "   " << lname << "   " << roll_no << "   " << place << "   " << c << endl;
        file.close();
    }
}

void hostel::four_sharing() {
    int room;
    cout << "\nFOUR SHARING rooms are only available in floors 7, 8 and 9." << endl;
    cout << "\nWhich floor do you want to prefer: ";
    cin >> floor;
    while (floor < 7 || floor > 9) {
        cout << "\nInvalid input please enter valid one " << endl;
        cin >> floor;
    }
    cout << "\nEnter a room no from 1 to 12: ";
    cin >> room;
    while (room < 1 || room > 12) {
        cout << "\nInvalid room no, please try again " << endl;
        cin >> room;
    }

    if ((rooms[floor][room][b1] == room + b1) && (rooms[floor][room][b2] == room + b2) &&
        (rooms[floor][room][b3] == room + b3) && (rooms[floor][room][b4] == room + b4)) {
        cout << "\nSORRY! Room is already booked, please book another " << endl;
    } else {
        c = floor * 100 + room;
        int bed = (rooms[floor][room][b1] != room + b1) ? b1 :
                  (rooms[floor][room][b2] != room + b2) ? b2 :
                  (rooms[floor][room][b3] != room + b3) ? b3 : b4;
        rooms[floor][room][bed] = room + bed;

        cout << "\nPlease enter your First Name: ";
        cin >> fname;
        cout << "\nEnter your Last Name: ";
        cin >> lname;
        cout << "\nPlease enter your full Roll Number: ";
        cin >> roll_no;
        cout << "\nEnter your Place: ";
        cin >> place;
        cout << "\nTHANK YOU, Your room is Booked\n";
        cout << "\nYour Room Number is : " << c;

        ofstream fil("4sharing.txt", ios::app);
        fil << fname << "   " << lname << "   " << roll_no << "   " << place << "   " << c << endl;
        fil.close();
    }
}

void hostel::display2() {
    string mu;
    ifstream myfl("2sharing.txt");
    cout << "\nDATA OF STUDENTS IN 2 SHARING ROOMS\n";
    while (getline(myfl, mu)) cout << mu << endl;
}

void hostel::display3() {
    string mun;
    ifstream file3("3sharing.txt");
    cout << "\nDATA OF STUDENTS IN 3 SHARING ROOMS\n";
    while (getline(file3, mun)) cout << mun << endl;
}

void hostel::display4() {
    string munn;
    ifstream file4("4sharing.txt");
    cout << "\nDATA OF STUDENTS IN 4 SHARING ROOMS\n";
    while (getline(file4, munn)) cout << munn << endl;
}

void hostel::display() {
    int sharing2 = 0, sharing3 = 0, sharing4 = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 13; j++) {
            if (i < 4) {
                for (int k = 1; k <= 2; k++) if (rooms[i][j][k] == j + k) sharing2++;
            } else if (i < 7) {
                for (int k = 1; k <= 3; k++) if (rooms[i][j][k] == j + k) sharing3++;
            } else {
                for (int k = 1; k <= 4; k++) if (rooms[i][j][k] == j + k) sharing4++;
            }
        }
    }
    cout << "\nBeds occupied in 2 sharing (out of 72): " << sharing2;
    cout << "\nBeds occupied in 3 sharing (out of 108): " << sharing3;
    cout << "\nBeds occupied in 4 sharing (out of 216): " << sharing4 << endl;
}

void hostel::loadBookings() {
    // Load 2 sharing
    ifstream f2("2sharing.txt");
    string a, b, c, d; int r;
    while (f2 >> a >> b >> c >> d >> r) {
        int fl = r / 100, rm = r % 100;
        for (int k = 1; k <= 2; k++) if (rooms[fl][rm][k] != rm + k) { rooms[fl][rm][k] = rm + k; break; }
    }
    f2.close();

    // Load 3 sharing
    ifstream f3("3sharing.txt");
    while (f3 >> a >> b >> c >> d >> r) {
        int fl = r / 100, rm = r % 100;
        for (int k = 1; k <= 3; k++) if (rooms[fl][rm][k] != rm + k) { rooms[fl][rm][k] = rm + k; break; }
    }
    f3.close();

    // Load 4 sharing
    ifstream f4("4sharing.txt");
    while (f4 >> a >> b >> c >> d >> r) {
        int fl = r / 100, rm = r % 100;
        for (int k = 1; k <= 4; k++) if (rooms[fl][rm][k] != rm + k) { rooms[fl][rm][k] = rm + k; break; }
    }
    f4.close();
}

int main() {
    cout << "\n\n********** HOSTEL BOOKING **********\n\n";
    hostel obj;
    obj.login();

    int choice;
    do {
        cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n";
        cout << "             WELCOME TO HOSTEL BOOKING          \n";
        cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n\n";

        cout << "\n1. Book a room\n2. Show occupied beds\n3. Display 2 sharing students\n4. Display 3 sharing students\n5. Display 4 sharing students\n6. Exit\n";
        cout << "\nEnter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int choice1;
                cout << "\nChoose room type:\n1. Two sharing\n2. Three sharing\n3. Four sharing\n4. Go back\n";
                cin >> choice1;
                if (choice1 == 1) obj.two_sharing();
                else if (choice1 == 2) obj.three_sharing();
                else if (choice1 == 3) obj.four_sharing();
                break;
            }
            case 2: obj.display(); break;
            case 3: obj.display2(); break;
            case 4: obj.display3(); break;
            case 5: obj.display4(); break;
            case 6: cout << "\nTHANK YOU\n"; exit(0);
            default: cout << "\nInvalid choice!\n";
        }
    } while (true);
}

