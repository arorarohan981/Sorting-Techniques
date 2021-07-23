
/* 
 * File:   main.cpp
 * Author: Rohan
 *
 * Created on 23 July 2021, 10:09 AM
 */

#include <cstdlib>
#include "BubbleSort.h"
#include "SelectionSort.h"
/*
 * 
 */
int main(int argc, char** argv) {
    /*Bubble Sort*/
    std::cout<<"Testing Bubble Sort \n "<<std::endl;
    int unsorted_int_arr1[5]={10,22,21,1,2};
    BubbleSort::sort<int>(unsorted_int_arr1,5,true);
    std::cout<<std::endl;
    int unsorted_int_arr2[5]={1,2,3,33,9};
    BubbleSort::sort<int>(unsorted_int_arr2,5,false);
    std::cout<<"\n"<<std::endl;
   
    /*Selection Sort*/
    std::cout<<"Testing Selection Sort \n"<<std::endl;
    int arr1[5]={10,22,21,1,2};
    SelectionSort::sort<int>(arr1,5,true);
    std::cout<<std::endl;
    int arr2[5]={1,2,3,33,9};
    SelectionSort::sort<int>(arr2,5,false);
    std::cout<<"\n"<<std::endl;
    return 0;
}

