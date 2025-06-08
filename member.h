#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Member {
private:
    string studentID;
    bool loggedIn = 0;

    bool isValidID(const string& id) const {
        if (id.length() != 8) return false;
        if (!isalpha(id[0])) return false;
        for (int i = 1; i < 8; i++) {
            if (!isdigit(id[i])) return false;
        }
        return true;
    }

public:
    Member() : studentID(""), loggedIn(false) {}

    void login() {
        while (true) {
            cout << "�п�J�Ǹ��n�J�|���]�Ҧp B1234567�^�A�ο�J 0 �����G";
            cin >> studentID;

            if (studentID == "0") {
                cout << "�w�����n�J�C" << endl;
                loggedIn = false;
                studentID = "";
                break;
            }

            if (isValidID(studentID)) {
                loggedIn = true;
                cout << "�n�J���\�I" << endl;
                break;
            }
            else {
                cout << "�榡���~�A�Ǹ�����1�ӭ^��r���[�W7�ӼƦr�A�Ҧp�GB1234567" << endl;
            }
        }
    }

    bool isLoggedIn() const {
        return loggedIn;
    }

    string getID() const {
        return studentID;
    }
};

#endif