//
// Created by wentingyang on 2016/9/5.
//
#include <iostream>
#include <iomanip>
#include <sstream>

#include "bigNum.h"

// Because of the precision issue of cmath.h, we use below ipow instead of pow from math for power calculation
// ipow is from http://
// stackoverflow.com/questions/101439/the-most-efficient-way-to-implement-an-integer-based-power-function-powint-int
maxInt_t ipow(maxInt_t base, int exp)
{
    maxInt_t result(1);
    while (exp != 0)
    {
        if ((exp & 1) == 1)
            result *= base;
        exp >>= 1;
        base *= base;
    }

    return result;
}

bigNum::bigNum(maxInt_t x) {
    maxInt_t rem;
    while (x >= 1) {
        rem = x - (x / SCALE) * SCALE;
        num.push_back(rem);
        x = x / SCALE;
    }
}

bigNum bigNum::operator +(const bigNum& x){
    int xLen = x.num.size();
    int thisLen = num.size();
    int minLen = thisLen > xLen? xLen:thisLen;

    maxInt_t carry = 0;

    for (int i = 0; i < minLen ; i++) {
        num[i] += x.num[i] + carry;
        carry = 0;
        if ( num[i] >= SCALE ) {
            carry = num[i]/SCALE;
            num[i] = num[i]%SCALE;
        }
    }

    if ( minLen < thisLen || xLen == thisLen)
    {
        for (int i = minLen; i <= thisLen; i++){
            if (i == thisLen && carry > 0 ) num.push_back(carry);
            if ( num[i] >= SCALE ){
                carry = num[i]/SCALE;
                num[i] = num[i]%SCALE;
            }
            else break;
        }
    }
    else{
        for (int i = minLen; i <= xLen; i++){
            if (i == thisLen){
                if ( carry > 0 ) num.push_back(carry);
            }
            else
            {
                num.push_back( carry + x.num[i]);
                carry = 0;
                if ( num[i] >= SCALE ){
                    carry = num[i]/SCALE;
                    num[i] = num[i]%SCALE;
                }
            }

        }
    }
    return *this;
}

bigNum bigNum::operator =( const bigNum& x) {
    num = x.num;
    /*
    for (vector<maxInt_t>::iterator it = x.num.begin(); it != x.num.end(); it++)
    {
        num.push_back(*it);
    }*/
    return *this;
}

bigNum bigNum::operator *(const bigNum& x){
    int rows = x.num.size();
    int cols = num.size();

    vector<maxInt_t> res(cols, 0);

    maxInt_t carry = 0;

    for (int i = 0; i < rows; i++ ){
        for ( int j = 0; j < cols ; j++ ){
            if ( i > 0 && j == cols - 1 && res.size() == cols + i - 1)
            {
                res.push_back( num[j] * x.num[i] + carry);
            }
            else
            {
                res[j+i] += num[j] * x.num[i] + carry;
            }

            carry = 0;
            if ( res[j+i] >= SCALE ){
                carry = res[j+i] / SCALE;
                res[j+i] = res[j+i] % SCALE;
            }
        }
        if ( carry > 0 ) res.push_back(carry);
        carry = 0;
    }

    this->num = res;
    return *this;

};

bigNum bigNum::operator *=(const bigNum& x){
    return (*this) * x;
};

string bigNum::toString(){
    string retStr;
    stringstream strstream;

    vector<maxInt_t>::reverse_iterator last = num.rbegin();
    if ( last != num.rend() ) {
        strstream << *last;
        for (vector<maxInt_t>::reverse_iterator it = ++last; it != num.rend(); it++)
        {
            strstream << setfill('0') << setw(LIMDIGITS);
            strstream << *it;
        }
    }

    strstream >> retStr;
    return retStr;
}