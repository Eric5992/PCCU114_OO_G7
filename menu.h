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
    {"BLT¦w®æ´µ¤û¦×³ù", 127},
    {"©¬º¿´Ë¥D¼pÂû³ù", 127},
    {"«l»¶Âû»L³ù", 78},
    {"¤j³Á§J", 78},
    {"Âù¼h¤û¦×¦N¨Æ³ù", 72},
    {"³Á­»Âû", 48},
    {"³Á­»³½", 52},
    {"³Á¯ÜÂû(2¶ô)", 126}
};

const vector<Item> drinks = {
    {"ÂfÂc­·¨ý¬õ¯ù", 33},
    {"³·ºÑ", 33},
    {"¥i¼Ö", 33},
    {"¥i¼Özero", 33},
    {"µL¿}ºñ¯ù", 33},
    {"¸Á»e¬õ¯ù", 58},
    {"¸Á»e¥¤¯ù", 68},
    {"¥É¦Ì¿@´ö", 45}
};

const vector<Item> sneaks = {
    {"Âû¶ô(4¶ô)", 48},
    {"Âû¶ô(6¶ô)", 68},
    {"Âû¶ô(10¶ô)", 109},
    {"Á¦±ø(¤p)", 40},
    {"Á¦±ø(¤¤)", 50},
    {"Á¦±ø(¤j)", 66},
    {"³J±²¦B²N²O", 18},
    {"¦B¬¯­·", 59},
};

#endif
