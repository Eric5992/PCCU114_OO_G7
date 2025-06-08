#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
using namespace std;

struct Item {
    string name;
    int price;
};

const vector<Item> mainDishes = {
    {"BLT�w�洵���׳�", 127},
    {"�����˥D�p����", 127},
    {"�l�����L��", 78},
    {"�j���J", 78},
    {"���h���צN�Ƴ�", 72},
    {"������", 48},
    {"������", 52},
    {"������(2��)", 126}
};

const vector<Item> drinks = {
    {"�f�c��������", 33},
    {"����", 33},
    {"�i��", 33},
    {"�i��zero", 33},
    {"�L�}���", 33},
    {"���e����", 58},
    {"���e����", 68},
    {"�ɦ̿@��", 45}
};

const vector<Item> sneaks = {
    {"����(4��)", 48},
    {"����(6��)", 68},
    {"����(10��)", 109},
    {"����(�p)", 40},
    {"����(��)", 50},
    {"����(�j)", 66},
    {"�J���B�N�O", 18},
    {"�B����", 59},
};

#endif
