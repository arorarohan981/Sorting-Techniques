
/* 
 * File:   main.cpp
 * Author: Rohan
 *
 * Created on 23 July 2021, 10:09 AM
 */

#include <cstdlib>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "CountingSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
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
    
    
    
    /*Insertion Sort*/
    std::cout<<"Testing Insertion Sort \n"<<std::endl;
    int arr3[5]={99,88,33,44,66};
    InsertionSort::sort<int>(arr3,5,true);
    int arr4[5]={33,1,3,87,55};
    InsertionSort::sort_technique2<int>(arr4,5,false);
    std::cout<<"\n"<<std::endl;
    
    /*Counting Sort*/
    std::cout<<"Testing Counting Sort \n"<<std::endl;
    int arr5[5] = {5,4,3,2,1};
    CountingSort::sort<int>(arr5,5,true);
    int arr6[5]={1,9,8,1,4};
    CountingSort::sort<int>(arr6,5,false);
    std::cout<<"\n"<<std::endl;
    
    std::cout<<"Testing QuickSort/Partition Sort \n"<<std::endl;
    int arr7[5]={88,32,11,83,21};
    QuickSort::sort<int>(arr7,5,true);
    int arr8[5]={77,35,21,42,1};
    QuickSort::sort<int>(arr8,5,false);
    std::cout<<"\n"<<std::endl;
    
    
    /*Merge Sort*/
    std::cout<<"Testing Merge Sort \n"<<std::endl;
    int arr9[5]={99,87,32,12,3};
    MergeSort::sort<int>(arr9,5,true);
    int arr10[5]={1,2,3,4,5};
    MergeSort::sort<int>(arr10,5,false);
    return EXIT_SUCCESS;
}

