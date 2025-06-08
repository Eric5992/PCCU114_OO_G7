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
            cout << "請輸入學號登入會員（例如 B1234567），或輸入 0 取消：";
            cin >> studentID;

            if (studentID == "0") {
                cout << "已取消登入。" << endl;
                loggedIn = false;
                studentID = "";
                break;
            }

            if (isValidID(studentID)) {
                loggedIn = true;
                cout << "登入成功！" << endl;
                break;
            }
            else {
                cout << "格式錯誤，學號應為1個英文字母加上7個數字，例如：B1234567" << endl;
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