#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include "menu.h"
#include "count.h"
#include "member.h"


using namespace std;

#ifdef _WIN32
void clearScreen() {
    system("cls");
}
#else
void clearScreen() {
    system("clear");
}
#endif

void displayMenu(const vector<Item>& menu) {
    for (size_t i = 0; i < menu.size(); ++i) {
        cout << i + 1 << ". " << menu[i].name << " (" << menu[i].price << "��)\n";
    }
}

void displayCart(const vector<Item>& cart) {
    cout << "�ثe�w���\�I�G\n";
    if (cart.empty()) {
        cout << "(�|����ܥ����\�I)\n";
    }
    else {
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". " << cart[i].name << " - " << cart[i].price << "��\n";
        }
    }
    cout << "\n";
}

void addItemsToCart(const vector<Item>& menu, vector<Item>& cart) {
    displayMenu(menu);
    cout << "�п�J�n��ܪ��~���s���]�i�h��A�Ϊťդ��j�A��J 0 �����^: ";

    while (true) {
        int choice;
        cin >> choice;
        if (choice == 0) break;
        if (choice >= 1 && choice <= static_cast<int>(menu.size())) {
            cart.push_back(menu[choice - 1]);
            cout << "�w�[�J�G" << menu[choice - 1].name << "\n";
        }
        else {
            cout << "�L�Ī���ܡG" << choice << "\n";
        }
    }
}

void deleteItemsFromCart(vector<Item>& cart) {
    if (cart.empty()) {
        cout << "�ثe�S������w���\�I�C\n";
        return;
    }

    displayCart(cart);
    cout << "�п�J�n�R�������ؽs���]�i�h��A�Ϊťդ��j�A��J 0 �����^: ";
    vector<int> toDelete;
    while (true) {
        int num;
        cin >> num;
        if (num == 0) break;
        if (num >= 1 && num <= static_cast<int>(cart.size())) {
            toDelete.push_back(num - 1);
        }
        else {
            cout << "�L�Ī���ܡG" << num << "\n";
        }
    }

    sort(toDelete.rbegin(), toDelete.rend());
    for (int index : toDelete) {
        cout << "�w�����G" << cart[index].name << "\n";
        cart.erase(cart.begin() + index);
    }
}

int main() {
    vector<Item> cart;
    int option;

    while (true) {
        clearScreen();

        cout << "==== �w��ϥΦۧU�I�\�t�� ====\n";
        displayCart(cart);
        cout << "�п�ܾާ@�G\n";
        cout << "1. �D�\\n";
        cout << "2. ����\n";
        cout << "3. ���b\n";
        cout << "4. �R���w���\�I\n";
        cout << "��J�ﶵ�G";
        cin >> option;
        if (cin.fail()) {
            cout << "��J���~�A�п�J�Ʀr�ﶵ�I\n";
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            option = 0; 
        }
        switch (option) {
        case 1:
            clearScreen();
            displayCart(cart);
            addItemsToCart(mainDishes, cart);
            break;
        case 2:
            clearScreen();
            displayCart(cart);
            addItemsToCart(drinks, cart);
            break;
        case 3:
            clearScreen();
            {
                Count counter;
                counter.processCheckout(cart);
            }
            cout << "\n�Ы� Enter �䵲���{��...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();

            return 0; // �����{��
        case 4:
            clearScreen();
            deleteItemsFromCart(cart);
            break;
        default:
            cout << "�п�J���Ŀﶵ�]1-4�^\n";
        }

        cout << "\n�Ы� Enter ���~��...";
        cin.ignore();
        cin.get(); // ���ݨϥΪ̫��U Enter
    }

    return 0;
}
