#ifndef COUNT_H
#define COUNT_H

#include "menu.h"
#include "member.h"
#include <vector>
#include <string>

using namespace std;

class Count {
public:
    Count();
    void processCheckout(const vector<Item>& cart); 

private:
    double calculateSubtotal(const vector<Item>& cart); 
    double applyMemberDiscount(double currentTotal, const Member& member); 
    double applyCoupon(double currentTotal); 
    void printBill(const vector<Item>& cart, double subtotal, double finalTotal, const Member& member); 
    bool handlePayment(double finalTotal); 
};

#endif // COUNT_H