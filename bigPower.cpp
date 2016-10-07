//
// Created by wentingyang on 2016/9/5.
//

#include "bigPower.h"
#include <cmath>

int digitNum( int num)
{
    int ret = 0;
    if ( num < 10 ){
        ret = 1;
    }
    else{
        if ( num < 100 ){
            ret = 2;
        }
        else{
            if ( num < 1000) {
                ret = 3;
            }
            else {
                if (num < 10000) {
                    ret = 4;
                }
                else {
                    ret = 5;
                }
            }
        }
    }
    return ret;
}

int reverse( int num){
    int res = 0;
    while ( num != 0 ){
        res = res * 10 + num % 10;
        num = num / 10;
    }
    return res;
}

bigNum bigNumPow(int base, int power) {
    bigNum secBigVal;
    if ( base < 0 || base > 99999 || power < 0 || power >99999 )
        return secBigVal;

    int baseDigits = digitNum( base );

    if ( baseDigits * power <= MAXDIGITS ){
        //convert to bigNum just to make the process consistent.
        secBigVal = bigNum( ipow(base, power));
    }
    else
    {
        int secPow = MAXDIGITS / baseDigits;
        int secCnt = power/secPow;
        int remPow = power - secCnt * secPow;
        maxInt_t remVal = ipow(base, remPow);

        maxInt_t secVal = ipow(base, secPow);
        bigNum remBigVal( remVal );

        // implicitly constructed a binary tree
        int numOfLoop = (int)log2(secCnt);
        secBigVal = bigNum( secVal );

        if ( numOfLoop )
        {
            vector<bigNum> remList;
            for (int i = 1; i <= numOfLoop; i++){
                //sections fall out of the binary tree should be dealt with separately.
                if ( secCnt%2 == 1 ) remList.push_back( secBigVal );
                secBigVal *= secBigVal;
                secCnt = secCnt/2;
            }

            for ( vector<bigNum>::iterator it = remList.begin(); it != remList.end(); it++){
                secBigVal = secBigVal * (*it);
            }
        }
        secBigVal = secBigVal *remBigVal;
    }

    return secBigVal;
}


