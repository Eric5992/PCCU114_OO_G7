#include "count.h"
#include <iostream>
#include <cmath>     
#include <limits>    
#include <ios>       
using namespace std;

Count::Count() {}

void Count::processCheckout(const vector<Item>& cart) {
    if (cart.empty()) {
        cout << "您的購物車是空的，無法結帳！\n";
        return;
    }

    Member member;
    char isMemberChoice;
    cout << "請問您是會員嗎？ (y/n): ";
    cin >> isMemberChoice;

    if (isMemberChoice == 'y' || isMemberChoice == 'Y') {
        member.login();
    }

    double subtotal = calculateSubtotal(cart);
    double finalTotal = subtotal;

    finalTotal = applyMemberDiscount(finalTotal, member);
    finalTotal = applyCoupon(finalTotal);

    printBill(cart, subtotal, finalTotal, member);

    bool paymentSuccess = handlePayment(finalTotal);

    cout << "\n------------------------------------\n";
    if (paymentSuccess) {
        if (member.isLoggedIn()) {
            cout << "感謝會員 " << member.getID() << " 使用本系統！\n";
        }
        cout << "感謝您的光臨，期待再次為您服務！\n";
    }
    else {
        // "交易已取消" 的訊息會由 handlePayment 內部處理
    }
}


bool Count::handlePayment(double finalTotal) {
    double paymentAmount = 0.0;
    long roundedFinalTotal = round(finalTotal);

    cout << "\n最終應付金額為：" << roundedFinalTotal << " 元\n";

    while (true) { 
        cout << "請輸入您支付的金額 (輸入 0 取消交易): ";
        cin >> paymentAmount;

        if (cin.fail()) {
            cout << "錯誤：請輸入有效的數字。\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (paymentAmount == 0) {
            cout << "交易已取消。\n";
            return false;
        }


        if (paymentAmount < roundedFinalTotal) {
            cout << "金額不足，請重新輸入！\n\n";
            continue; 
        }

        long roundedPayment = round(paymentAmount);
        long change = roundedPayment - roundedFinalTotal;

        cout << "------------------------------------\n";
        cout << "收您 " << roundedPayment << " 元";
        if (change > 0) {
            cout << "，找零 " << change << " 元。\n";
        }
        else {
            cout << "，無需找零。\n";
        }

        return true; 
    }
}


void Count::printBill(const vector<Item>& cart, double subtotal, double finalTotal, const Member& member) {
    cout << "\n=========== 您的點餐明細 ===========\n";
    for (const auto& item : cart) {
        cout << item.name << " - " << item.price << "元\n";
    }
    cout << "====================================\n";
    cout << "商品原價合計：" << subtotal << " 元\n";

    if (round(finalTotal) != round(subtotal)) {
        cout << "折扣後金額  ：" << round(finalTotal) << " 元\n";
    }
}



double Count::calculateSubtotal(const vector<Item>& cart) {
    double total = 0.0;
    for (const auto& item : cart) {
        total += item.price;
    }
    return total;
}

double Count::applyMemberDiscount(double currentTotal, const Member& member) {
    if (member.isLoggedIn()) {
        cout << "\n會員登入成功！享受會員專屬 9 折優惠。\n";
        return currentTotal * 0.9;
    }
    return currentTotal;
}

double Count::applyCoupon(double currentTotal) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) { 
        string code;
        cout << "\n是否有折價券代碼？(輸入代碼，或直接按 Enter 跳過): ";
        getline(cin, code);

       
        if (code.empty()) {
            break; 
        }

        if (code == "100off" || code == "888") {
            if (currentTotal >= 100) {
                cout << "使用 '100off' 折價券，成功折抵 100 元！\n";
                currentTotal -= 100; 
                break; 
            }
            else {
                cout << "此折價券不適用：總金額未達 100 元。請嘗試其他代碼，或直接按 Enter 跳過。\n";
            }
        }

        else {
            cout << "無效的折價券代碼，請重新輸入，或直接按 Enter 跳過。\n";
        }
    }

    return currentTotal; 
}