/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SelectionSort.h
 * Author: rohan
 *
 * Created on 23 July 2021, 1:32 PM
 */

#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H
#include<iostream>
#include<cmath>

/*
   Selection Sort improves on the Bubble Sort By making only 1 Swap per Pass.
 * Selection Sort Selects the Largest/Smallest Number ( according to the Criteria ) from the list and Compares it
 * with all the elements in the list and places it in the end.(i.e Their Actual Position)
 * In the next Pass ,Selection Sort Does the same with the remaining Elements.
 * 
 * Selection Sort is a in-place Sort.
 * Time Complexity is O(n^2).
 * Space Complexity is O(1).
 * 
 * Pros:
 * It is Better than Bubble Sort as it only has 1 Swap/Exchange per pass.
 * So If the size of list is N.In Worst Case,You may have N Passes.
 */


class SelectionSort{
    
public:
    
    /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
     * Number of Elements of type int  and 
     * a Boolean value (True if we want the elements to be sorted in Ascending order 
     * or False if we want the elements to be sorted in Descending Order 
     * as Paramater.
     */
    template <typename T>
    static void sort ( T arr[],int no_of_elements,bool sorting_order)
    {
        
        std::cout<<std::endl<<"Elements Before Sorting are "<<std::endl;
        printarray(arr,no_of_elements);
         std::cout<<std::endl;
        int j=0;
        for(int i=0;i<no_of_elements;i++){
            int temp=0;
            for(j=0;j<no_of_elements-i;j++){
                //3   5   4 
                //
                if(sorting_order?arr[j]>arr[temp]:arr[j]<arr[temp]){
                    temp=j;
                }
            }
            swapelements(arr,temp,j-1);
            
        }
        
        std::cout<<"Elements After Sorting are "<<std::endl;
        printarray(arr,no_of_elements);
         std::cout<<std::endl;
        
      
    };
    
    
private:
        /*Print Array methods takes in Array of any Type T ,
         and No of Elements (type int) as a Parameter  */
        template <typename T>
        static void printarray(T arr[],int no_of_elements){
            std::cout<<"Elements in array are : ";
            for (int i=0;i<no_of_elements;i++){
                std::cout<<" "<<arr[i]<<" ";
            }
        }
        
        /* Swapelements method swaps 2 elements inside the array .
         * Pos1 is the index of the first element and 
         * Pos2 is the index of second Element.
         */
        template <typename T>
        static void swapelements(T arr[],int pos1,int pos2){
                    T temp;//Temp is a temporary variable which we will use for swapping
                    temp=arr[pos1];
                    arr[pos1]=arr[pos2];
                    arr[pos2]=temp;
        }
    
        
         /*
         * It reverses the elements of the supplied array.
         */
        template <typename T>
        static void reversearr(T arr[],int size){
            
            T temp;
            int half=std::floor(size/2);
            
            for(int i=0;i<half;i++){
                temp=arr[i];
                arr[i]=arr[size-i-1];
                arr[size-i-1]=temp;
            }
            
        }
};


#endif /* SELECTIONSORT_H */

