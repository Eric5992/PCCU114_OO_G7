#include "count.h"
#include <iostream>
#include <cmath>     
#include <limits>    
#include <ios>       
using namespace std;

Count::Count() {}

void Count::processCheckout(const vector<Item>& cart) {
    if (cart.empty()) {
        cout << "�z���ʪ����O�Ū��A�L�k���b�I\n";
        return;
    }

    Member member;
    char isMemberChoice;
    cout << "�аݱz�O�|���ܡH (y/n): ";
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
            cout << "�P�·|�� " << member.getID() << " �ϥΥ��t�ΡI\n";
        }
        cout << "�P�±z�����{�A���ݦA�����z�A�ȡI\n";
    }
    else {
        // "����w����" ���T���|�� handlePayment �����B�z
    }
}


bool Count::handlePayment(double finalTotal) {
    double paymentAmount = 0.0;
    long roundedFinalTotal = round(finalTotal);

    cout << "\n�̲����I���B���G" << roundedFinalTotal << " ��\n";

    while (true) { 
        cout << "�п�J�z��I�����B (��J 0 �������): ";
        cin >> paymentAmount;

        if (cin.fail()) {
            cout << "���~�G�п�J���Ī��Ʀr�C\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (paymentAmount == 0) {
            cout << "����w�����C\n";
            return false;
        }


        if (paymentAmount < roundedFinalTotal) {
            cout << "���B�����A�Э��s��J�I\n\n";
            continue; 
        }

        long roundedPayment = round(paymentAmount);
        long change = roundedPayment - roundedFinalTotal;

        cout << "------------------------------------\n";
        cout << "���z " << roundedPayment << " ��";
        if (change > 0) {
            cout << "�A��s " << change << " ���C\n";
        }
        else {
            cout << "�A�L�ݧ�s�C\n";
        }

        return true; 
    }
}


void Count::printBill(const vector<Item>& cart, double subtotal, double finalTotal, const Member& member) {
    cout << "\n=========== �z���I�\���� ===========\n";
    for (const auto& item : cart) {
        cout << item.name << " - " << item.price << "��\n";
    }
    cout << "====================================\n";
    cout << "�ӫ~����X�p�G" << subtotal << " ��\n";

    if (round(finalTotal) != round(subtotal)) {
        cout << "�馩����B  �G" << round(finalTotal) << " ��\n";
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
        cout << "\n�|���n�J���\�I�ɨ��|���M�� 9 ���u�f�C\n";
        return currentTotal * 0.9;
    }
    return currentTotal;
}

double Count::applyCoupon(double currentTotal) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) { 
        string code;
        cout << "\n�O�_�������N�X�H(��J�N�X�A�Ϊ����� Enter ���L): ";
        getline(cin, code);

       
        if (code.empty()) {
            break; 
        }

        if (code == "100off" || code == "888") {
            if (currentTotal >= 100) {
                cout << "�ϥ� '100off' �����A���\��� 100 ���I\n";
                currentTotal -= 100; 
                break; 
            }
            else {
                cout << "������餣�A�ΡG�`���B���F 100 ���C�й��ը�L�N�X�A�Ϊ����� Enter ���L�C\n";
            }
        }

        else {
            cout << "�L�Ī������N�X�A�Э��s��J�A�Ϊ����� Enter ���L�C\n";
        }
    }

    return currentTotal; 
}