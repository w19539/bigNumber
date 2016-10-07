//
// Created by wentingyang on 2016/9/5.
//
#include <iostream>
#include<limits>
#include "bigNum.h"
#include "bigPower.h"

int main(){

    int base;

    while (true) {

        cout << "Enter a number (0-99999):";

        while ( !(cin >> base ) ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (base == -1 ) break;
        if (base >=0 && base <= 99999) {
            int power = reverse( base );
            bigNum res = bigNumPow( base, power);
            cout << endl;
            cout << "Result: " << base << "^" << power << " is " << res.toString() << endl;
        }
    };

    return 0;

}
