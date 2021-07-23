/* 
 * File:   BubbleSort.h
 * Author: Rohan
 *
 * Created on 23 July 2021, 9:56 AM
 */

#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include<iostream>

/*
 * In Bubble,Adjacent Elements are compared and element which are out of order are Swapped.
 * In Every pass,The largest/smallest element(Depending upon the Criteria Ascending or Descending) 
 * Reaches its position in the Array. 
 * Cons:
 * It is most inefficient Sorting Technique as Swapping of elements happen even before knowing their final position.
 * This swapping leads to increase in step counts i.e Time Complexity.
 * Pros:
 * Only in this Technique we can stop the Sorting if there are no swaps in the first pass.This technique is good when 
 * we have less no of unsorted Elements or when the array size is small.
 *
 * BubbleSort is in-place Sorting technique.
 * BubbleSort is a stable Sorting Technique.
 * 
 * Time Complexity of Bubble Sort is O(n^2).
 * Space Complexity of Bubble Sort is O(1).
 */
class BubbleSort{
    
public:
    /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
     * Number of Elements of type int  and 
     * a Boolean value (True if we want the elements to be sorted in Ascending order 
     * or False if we want the elements to be sorted in Descending Order 
     * as Paramater.
     */
    template <typename T>
    static void sort (T arr[] ,int no_of_elements ,bool ascending){
        
        std::cout<<std::endl<<"Elements Before Sorting : "<<std::endl;
        printarray(arr,no_of_elements);
        std::cout<<std::endl;
        for(int i=0;i<no_of_elements;i++){
            bool is_arr_already_sorted =true;
            for(int j=0;j<no_of_elements-i;j++){
              
                if(ascending ? arr[j]>arr[j+1]:arr[j]<arr[j+1]){
                    is_arr_already_sorted =false;
                    swapelements(arr,j,j+1);
                }
            }
            if(is_arr_already_sorted == true){
                break;
            }
        }
        
        std::cout<<"Elements After Sorting : "<<std::endl;
        printarray(arr,no_of_elements);
        
        
       
    }
    
    
    
    private :
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



};


#endif /* BUBBLESORT_H */

