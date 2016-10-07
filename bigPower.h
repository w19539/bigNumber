//
// Created by wentingyang on 2016/9/5.
//

#ifndef CLION_BIGPOWER_H
#define CLION_BIGPOWER_H

#include "bigNum.h"

//get the number of digit in a number
int digitNum( int num);

//reverse a number
int reverse( int num);

/*bigNumPow is to calculate the power operator whose result might exceed the maximum value that
 * a PC can represent. It is based on following facts:
 * 1. The number of digits of the multiplication result of two integers do not exceed the addition
 * of the digits of the two integers
 * 2. the addition and multiplication operations in cmath library are the most optimised, and
 * should be used as many as possible
 *
 * Below optimization have been done to improve the calculation speed:
 * 1. if the predicted maximum digits of the result can be fit into the predefined the type maxInt_t
 * , use the pow function (ipow) directly.
 * 2. Otherwise, the power operation is split into a multiplication of multiple sections, and
 * each section is a multiplication of multiple base numbers (called element). Make sure that the
 * multiplication of all the elements of a section can fit into the type maxInt_t.
 * 3. When splitting into sections, each of the section should contain the same number of elements,
 * and the remaining base numbers have to be handled with separately.
 * 4. When doing the multiplication of sections, a binary tree is constructed implicitly to avoid
 * calculate the same multiplication multiple times*/
bigNum bigNumPow(int base, int power);


#endif //CLION_BIGPOWER_H
