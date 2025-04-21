#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>
#include <vector>

struct Item {
    std::string name;
    int price;
};

class OrderSystem {
public:
    OrderSystem();
    void run();

private:
    std::vector<Item> mainDishes;
    std::vector<Item> drinks;
    std::vector<Item> cart;
    void displayWelcome();
    void displayMenu();
    void displayMainDishes();
    void displayDrinks();
    void addItem(const std::vector<Item>& menu);
    void checkout();
};

#endif
