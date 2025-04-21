#include "system.h"
#include <iostream>

OrderSystem::OrderSystem() {
    mainDishes = {
        {"�l�����L��", 80},
        {"�j���J", 90},
        {"���h�N�Ƴ�", 50},
        {"������", 40}
    };
    drinks = {
        {"����", 30},
        {"����", 25},
        {"�i��", 25},
        {"�ɦ̿@��", 40}
    };
}

void OrderSystem::displayWelcome() {
    std::cout << "�w��ϥΦۧU�I�\�t��\n";
}

void OrderSystem::displayMenu() {
    std::cout << "�п�ܡG\n";
    std::cout << "1. �D�\\n2. ����\n3. ���b\n";
}

void OrderSystem::displayMainDishes() {
    std::cout << "�D�\�ﶵ�G\n";
    for (size_t i = 0; i < mainDishes.size(); ++i) {
        std::cout << i + 1 << ". " << mainDishes[i].name << " (" << mainDishes[i].price << "��)\n";
    }
}

void OrderSystem::displayDrinks() {
    std::cout << "���ƿﶵ�G\n";
    for (size_t i = 0; i < drinks.size(); ++i) {
        std::cout << i + 1 << ". " << drinks[i].name << " (" << drinks[i].price << "��)\n";
    }
}

void OrderSystem::addItem(const std::vector<Item>& menu) {
    int choice;
    std::cout << "�п�J�~���s���G";
    std::cin >> choice;
    if (choice >= 1 && choice <= static_cast<int>(menu.size())) {
        cart.push_back(menu[choice - 1]);
        std::cout << "�w�[�J�G" << menu[choice - 1].name << "\n";
    }
    else {
        std::cout << "��J���~�A�Э��s��ܡC\n";
    }
}

void OrderSystem::checkout() {
    int total = 0;
    std::cout << "\n�z���I�\���e�p�U�G\n";
    for (const auto& item : cart) {
        std::cout << item.name << " - " << item.price << "��\n";
        total += item.price;
    }

    std::string code;
    std::cout << "�O�_�������N�X�H(��J�N�X�Ϊ����� Enter ���L): ";
    std::cin.ignore();
    std::getline(std::cin, code);

    if (code == "100off") {
        if (total >= 100) {
            std::cout << "��� 100 ���I\n";
            total -= 100;
        }
        else {
            std::cout << "������餣�A�ΡA�`���B���F 100 ���C\n";
        }
    }

    std::cout << "�`���B���G" << total << " ���A���¥��{�I\n";
}

void OrderSystem::run() {
    displayWelcome();
    int option;
    while (true) {
        displayMenu();
        std::cout << "�п�ܿﶵ�G";
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
            std::cout << "�ﶵ���~�A�Э��s��J�C\n";
        }
    }
}
