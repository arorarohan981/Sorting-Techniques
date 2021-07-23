
/* 
 * File:   main.cpp
 * Author: Rohan
 *
 * Created on 23 July 2021, 10:09 AM
 */

#include <cstdlib>
#include "BubbleSort.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int unsorted_int_arr1[5]={10,22,21,1,2};
    BubbleSort::sort<int>(unsorted_int_arr1,5,true);
    int unsorted_int_arr2[5]={1,2,3,33,9};
    BubbleSort::sort<int>(unsorted_int_arr2,5,false);
    return 0;
}

