#include "system.h"
#include <iostream>

OrderSystem::OrderSystem() {
    mainDishes = {
        {"勁辣雞腿堡", 80},
        {"大麥克", 90},
        {"雙層吉事堡", 50},
        {"麥香雞", 40}
    };
    drinks = {
        {"紅茶", 30},
        {"雪碧", 25},
        {"可樂", 25},
        {"玉米濃湯", 40}
    };
}

void OrderSystem::displayWelcome() {
    std::cout << "歡迎使用自助點餐系統\n";
}

void OrderSystem::displayMenu() {
    std::cout << "請選擇：\n";
    std::cout << "1. 主餐\n2. 飲料\n3. 結帳\n";
}

void OrderSystem::displayMainDishes() {
    std::cout << "主餐選項：\n";
    for (size_t i = 0; i < mainDishes.size(); ++i) {
        std::cout << i + 1 << ". " << mainDishes[i].name << " (" << mainDishes[i].price << "元)\n";
    }
}

void OrderSystem::displayDrinks() {
    std::cout << "飲料選項：\n";
    for (size_t i = 0; i < drinks.size(); ++i) {
        std::cout << i + 1 << ". " << drinks[i].name << " (" << drinks[i].price << "元)\n";
    }
}

void OrderSystem::addItem(const std::vector<Item>& menu) {
    int choice;
    std::cout << "請輸入品項編號：";
    std::cin >> choice;
    if (choice >= 1 && choice <= static_cast<int>(menu.size())) {
        cart.push_back(menu[choice - 1]);
        std::cout << "已加入：" << menu[choice - 1].name << "\n";
    }
    else {
        std::cout << "輸入錯誤，請重新選擇。\n";
    }
}

void OrderSystem::checkout() {
    int total = 0;
    std::cout << "\n您的點餐內容如下：\n";
    for (const auto& item : cart) {
        std::cout << item.name << " - " << item.price << "元\n";
        total += item.price;
    }

    std::string code;
    std::cout << "是否有折價券代碼？(輸入代碼或直接按 Enter 跳過): ";
    std::cin.ignore();
    std::getline(std::cin, code);

    if (code == "100off") {
        if (total >= 100) {
            std::cout << "折抵 100 元！\n";
            total -= 100;
        }
        else {
            std::cout << "此折價券不適用，總金額未達 100 元。\n";
        }
    }

    std::cout << "總金額為：" << total << " 元，謝謝光臨！\n";
}

void OrderSystem::run() {
    displayWelcome();
    int option;
    while (true) {
        displayMenu();
        std::cout << "請選擇選項：";
        std::cin >> option;

        if (option == 1) {
            displayMainDishes();
            addItem(mainDishes);
        }
        else if (option == 2) {
            displayDrinks();
            addItem(drinks);
        }
        else if (option == 3) {
            checkout();
            break;
        }
        else {
            std::cout << "選項錯誤，請重新輸入。\n";
        }
    }
}
