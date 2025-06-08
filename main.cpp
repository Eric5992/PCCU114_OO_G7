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
        cout << i + 1 << ". " << menu[i].name << " (" << menu[i].price << "元)\n";
    }
}

void displayCart(const vector<Item>& cart) {
    cout << "目前已選餐點：\n";
    if (cart.empty()) {
        cout << "(尚未選擇任何餐點)\n";
    }
    else {
        for (size_t i = 0; i < cart.size(); ++i) {
            cout << i + 1 << ". " << cart[i].name << " - " << cart[i].price << "元\n";
        }
    }
    cout << "\n";
}

void addItemsToCart(const vector<Item>& menu, vector<Item>& cart) {
    displayMenu(menu);
    cout << "請輸入要選擇的品項編號（可多選，用空白分隔，輸入 0 結束）: ";

    while (true) {
        int choice;
        cin >> choice;
        if (choice == 0) break;
        if (choice >= 1 && choice <= static_cast<int>(menu.size())) {
            cart.push_back(menu[choice - 1]);
            cout << "已加入：" << menu[choice - 1].name << "\n";
        }
        else {
            cout << "無效的選擇：" << choice << "\n";
        }
    }
}

void deleteItemsFromCart(vector<Item>& cart) {
    if (cart.empty()) {
        cout << "目前沒有任何已選餐點。\n";
        return;
    }

    displayCart(cart);
    cout << "請輸入要刪除的項目編號（可多選，用空白分隔，輸入 0 結束）: ";
    vector<int> toDelete;
    while (true) {
        int num;
        cin >> num;
        if (num == 0) break;
        if (num >= 1 && num <= static_cast<int>(cart.size())) {
            toDelete.push_back(num - 1);
        }
        else {
            cout << "無效的選擇：" << num << "\n";
        }
    }

    sort(toDelete.rbegin(), toDelete.rend());
    for (int index : toDelete) {
        cout << "已移除：" << cart[index].name << "\n";
        cart.erase(cart.begin() + index);
    }
}

int main() {
    vector<Item> cart;
    int option;

    while (true) {
        clearScreen();

        cout << "==== 歡迎使用自助點餐系統 ====\n";
        displayCart(cart);
        cout << "請選擇操作：\n";
        cout << "1. 主餐\n";
        cout << "2. 飲料\n";
        cout << "3. 結帳\n";
        cout << "4. 刪除已選餐點\n";
        cout << "輸入選項：";
        cin >> option;
        if (cin.fail()) {
            cout << "輸入錯誤，請輸入數字選項！\n";
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
            cout << "\n請按 Enter 鍵結束程式...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();

            return 0; // 結束程式
        case 4:
            clearScreen();
            deleteItemsFromCart(cart);
            break;
        default:
            cout << "請輸入有效選項（1-4）\n";
        }

        cout << "\n請按 Enter 鍵繼續...";
        cin.ignore();
        cin.get(); // 等待使用者按下 Enter
    }

    return 0;
}
