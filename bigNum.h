//
// Created by wentingyang on 2016/9/5.
//

#ifndef CLION_BIGNUM_H
#define CLION_BIGNUM_H

#include <vector>
#include <string>

/*data type for saving the intermediate values and partial results*/
typedef unsigned long long maxInt_t;

/*maximum allowed number of digits of integer value*/
const int MAXDIGITS = 19;

/*limit of the number of digits allowed in BigNum class, we make sure
 * that the multiplication of 2 digit-limited integers should not exceed the MAXDIGITS*/
const int LIMDIGITS = (MAXDIGITS - 1)/2;

maxInt_t ipow(maxInt_t base, int exp);

const maxInt_t SCALE = ipow(10, LIMDIGITS);  //scale for split a big number into multiple partitions


using namespace std;


/*the class bigNum can be used for big number saving, addition, multiplication and print.
 * it splits a big number into multiple partitions according the SCALE, and saves a big
 * number partitions into a vector in the order from tail to head, i.e. the most significant
 * value is at the end of a vector*/

class bigNum {

public:
    bigNum(){};
    bigNum(maxInt_t x);
    bigNum operator +(const bigNum& x);
    bigNum operator *(const bigNum& x);
    bigNum operator =( const bigNum& x);
    bigNum operator *=(const bigNum& x);
    string toString();
private:
    vector<maxInt_t> num;
};


#endif //CLION_BIGNUM_H
