#include <fstream>
#include <iostream>
#include <string>
using namespace std;

class hospital {
    int pid;
    string pname;
    string fname;
    string mname;
    string hname;
    string ren;
    string rer;
    string gen;
    float age;
    string mob;
    string status;

public:
    void in() {
        cout << "Please enter the informations respectively : " << endl << endl;
        cout << "Please enter patient's id : " << endl;
        cin >> pid;
        cout << "Please enter patient's name : " << endl;
        cin >> pname;
        cout << "Please enter patient's  age : " << endl;
        cin >> age;
        cout << "Please enter patient's  gender : " << endl;
        cin >> gen;
        cout << "Is patient is married or not ?" << endl;
        cin >> status;
        if (gen == "female") {
            if (status == "yes") {
                cout << "Please enter patient's  husband's name : " << endl;
                cin >> hname;
            } else if (status == "no") {
                cout << "Please enter patient's father name : " << endl;
                cin >> fname;
                cout << "Please enter patient's  mother name : " << endl;
                cin >> mname;
            }
        } else {
            cout << "Please enter patient's father name : " << endl;
            cin >> fname;
            cout << "Please enter the name of person who reffered the patient : " << endl;
            cin >> ren;
            cout << "Please enter the relation of person who reffered the patient : " << endl;
            cin >> rer;
            cout << "Please enter the mobile number : " << endl;
            cin >> mob;
        }
    }

    void out() {
        cout << endl;
        cout << "Patient's id : " << pid << endl;
        cout << "Patient's name : " << pname << endl;
        cout << "Patient's  age : " << age << endl;
        cout << "Patient's  gender : " << gen << endl;
        cout << "Patient's married status : " << status << endl;
        if (gen == "female") {
            if (status == "yes") {
                cout << "Patient's  husband's name : " << hname << endl;
            } else if (status == "no") {
                cout << "Patient's father name : " << fname << endl;
                cout << "Patient's  mother name : " << mname << endl;
            }
        } else {
            cout << "Patient's father name : " << fname << endl;
            cout << "Refferer's name : " << ren << endl;
            cout << "Refferer's relation : " << rer << endl;
            cout << "Mobile number : " << mob << endl;
        }
    }

    int record() {
        return pid;
    }

    void update() {
        string choice1;
        string choice2;
        string pn;
        string hn;
        string fn;
        string mn;
        string phone;
        string state;
        cout << "Do you want to really change the record (YES or NO) : " << endl;
        cin >> choice1;
        if (choice1 == "yes") {
            cout << "What do you want to change(patient's(name,father's name,husband's name,mother's name,age,phone number,status of marriage) : " << endl;
            cin >> choice2;
            cout << endl;
            if (choice2 == "pname") {
                cout << "Enter the new patient's name: " << endl;
                cin >> pn;
                pname = pn;
            } else if (choice2 == "fname") {
                cout << "Enter the new father's name : " << endl;
                cin >> fn;
                fname = fn;
            } else if (choice2 == "hname") {
                cout << "Enter the new husband's name : " << endl;
                cin >> hn;
                hname = hn;
            } else if (choice2 == "mname") {
                cout << "Enter the new mother's name : " << endl;
                cin >> mn;
                mname = mn;
            } else if (choice2 == "phone") {
                cout << "Enter the new phone number : " << endl;
                cin >> phone;
                mob = phone;
            } else if (choice2 == "state") {
                cout << "Enter the new state : " << endl;
                cin >> state;
                status = state;
            }
        } else {
            exit(0);
        }
    }
};

void add() {
    cout << "\nNO SPACES ARE ALLOWED\n";
    fstream file("hospital.dat", ios::binary | ios::out | ios::app);
    hospital h;
    h.in();
    file.write((char*)&h, sizeof(h));
}

void show() {
    fstream file("hospital.dat", ios::binary | ios::in);
    file.seekg(0);
    hospital h;
    while (!file.eof()) {
        file.read((char*)&h, sizeof(h));
        if (file.eof()) {
            break;
        } else {
            h.out();
        }
    }
    file.close();
}

void search() {
    ifstream file("hospital.dat", ios::binary | ios::in | ios::out);
    file.seekg(0);
    hospital h;
    int id;
    cout << "Enter the patient's id you want to search : " << endl;
    cin >> id;
    while (!file.eof()) {
        file.read((char*)&h, sizeof(h));
        if (file.eof()) {
            break;
        } else if (h.record() == id) {
            h.out();
        }
    }
    file.close();
}

void transpose() {
    ofstream ifile("hos.dat", ios::binary | ios::in | ios::out);
    ifstream file("hospital.dat", ios::binary | ios::in | ios::out);
    file.seekg(0);
    hospital h;
    int id1;
    int id2;
    cout << "Enter the patient's id in range you want to transpose : " << endl << endl;
    cout << "Enter the patient's primary id number for range (x-) : " << endl;
    cin >> id1;
    cout << "Enter the patient's secondry id number for range (-x) : " << endl;
    cin >> id2;
    while (!file.eof()) {
        file.read((char*)&h, sizeof(h));
        if (file.eof()) {
            break;
        } else if (h.record() >= id1 && h.record() <= id2) {
            ifile.write((char*)&h, sizeof(h));
        }
    }
    file.close();
    ifile.close();
}

void del() {
    ofstream ifile("hos.dat", ios::binary | ios::in | ios::out);
    ifstream file("hospital.dat", ios::binary | ios::in | ios::out);
    file.seekg(0);
    hospital h;
    int id;
    cout << "Enter the patient's id want to delete : " << endl;
    cin >> id;
    while (!file.eof()) {
        file.read((char*)&h, sizeof(h));
        if (file.eof()) {
            break;
        } else if (h.record() == id) {
            h.out();
        } else {
            ifile.write((char*)&h, sizeof(h));
        }
    }
    file.close();
    ifile.close();
    remove("hospital.dat");
    rename("hos.dat", "hospital.dat");
}

void shot() {
    cout << "The transpose id is : " << endl;
    fstream ifile("hos.dat", ios::binary | ios::in | ios::out);
    hospital h;
    while (!ifile.eof()) {
        ifile.read((char*)&h, sizeof(h));
        if (ifile.eof()) {
            break;
        } else {
            h.out();
        }
    }
    ifile.close();
}

void erase() {
    string choice;
    cout << "Do you really wants to erase all record" << endl;
    cin >> choice;
    if (choice == "yes") {
        fstream file("hospital.dat", ios::binary | ios::out | ios::trunc);
        hospital h;
        file.write((char*)&h, sizeof(h));
        file.close();
    }
    cout << "Your record is erased" << endl;
}

void modify() {
    fstream file("hospital.dat", ios::binary | ios::in | ios::out);
    hospital h;
    int id;
    cout << "Enter the patient's id want to modify/change : " << endl;
    cin >> id;
    int l;
    while (!file.eof()) {
        l = file.tellp();
        file.read((char*)&h, sizeof(h));
        if (h.record() == id) {
            file.seekg(l);
            h.update();
            file.write((char*)&h, sizeof(h));
        }
        file.close();
    }
}

int main() {
    char ch;
    char ch1;
    while (1) {
        cout << "_______________________________________________________________________________" << endl;
        cout << "                                 Press Y to continue : " << endl;
        cout << "_______________________________________________________________________________" << endl;
        cout << " ";
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            cout << "________________________________________" << endl;
            cout << " Press 1 to add the record.            |" << endl;
            cout << " Press 2 to display the records.       |" << endl;
            cout << " Press 3 to search the record.         |" << endl;
            cout << " Press 4 to transpose the record.      |" << endl;
            cout << " Press 5 to show transposed record.    |" << endl;
            cout << " Press 6 to delete the record.         |" << endl;
            cout << " Press 7 to clear the record.          |" << endl;
            cout << " Press 8 to modify the record.         |" << endl;
            cout << " Press 9 for exit.                     |" << endl;
            cout << "_______________________________________|" << endl;
            cout << endl;
            cout << "--------------------------------Enter your choice-------------------------------" << endl;
            cin >> ch1;
            switch (ch1) {
                case '1':
                    add();
                    break;
                case '2':
                    show();
                    break;
                case '3':
                    search();
                    break;
                case '4':
                    transpose();
                    break;
                case '5':
                    shot();
                    break;
                case '6':
                    del();
                    break;
                case '7':
                    erase();
                    break;
                case '8':
                    modify();
                    break;
                case '9':
                    exit(0);
            }
        }
    }
    return 0;
}



