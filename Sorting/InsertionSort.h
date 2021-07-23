/* 
 * File:   InsertionSort.h
 * Author: Rohan
 *
 * Created on 23 July 2021, 4:25 PM
 */

#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <iostream>


/*
 * Insertion Sort: In this Technique we insert the element at the right position
 *  (Depending on the Criteria ) and move all other Elements towards the right .
 * Running Time of Insertion Sort depends upon the initial Order of the Elements 
 * inside it.
 * 
 * Insertion Sort is a in-place Sorting Technique.
 * Insertion Sort is a Stable Sort.(As the order of Elements with same value is retained)
 * 
 * 
 * Time Complexity of Insertion Sort in O(n^2).
 * Space Complexity of Insertion Sort is O(1).
 * Best Case Time Complexity is O(n) .We can refer technique 2 for this.Technique 2
 * below has better implementation.
 * ************************
 * Maximum Number of Comparisons for Insertion Sort is Sum of First N-1 Integers.
 * ************************
 */
class InsertionSort{
public :
    
    /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
     * Number of Elements of type int  and 
     * a Boolean value (True if we want the elements to be sorted in Ascending order 
     * or False if we want the elements to be sorted in Descending Order 
     * as a Paramater.
     */
    template<typename T>
    void static sort(T arr[],int no_of_elements,bool sorting_order){
        std::cout<<std::endl<<"Elements Before Sorting are : "<<std::endl;
        printarray(arr,no_of_elements);
        T temp;
        //4 5 3
        for(int i=1;i<no_of_elements;i++){
            for(int j=0;j<=i;j++){
                if(sorting_order?arr[i]<arr[j]:arr[i]>arr[j]){
                    temp=arr[i];
                    movearrayelementsby1toright(arr,j,i);
                    arr[j]=temp;
                }
            }
        }
        std::cout<<std::endl<<"Elements After Sorting are : "<<std::endl;
        printarray(arr,no_of_elements);
    }
    
    
    
    //Way 2
     /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
     * Number of Elements i.e Size of type int  and 
     * a Boolean value (True if we want the elements to be sorted in Ascending order 
     * or False if we want the elements to be sorted in Descending Order 
     * as a Paramater.
     */
    template <typename T>
    void static sort_technique2(T arr[], int size, bool sorting_order) {
        std::cout<<std::endl<<"Elements Before Sorting are : "<<std::endl;
        printarray(arr,size);
     
    int position;
    T currentvalue;
    int index;
    for (index = 1; index < size; index++) {   
        currentvalue = arr[index];
        position = index;
        while (position > 0 && (sorting_order?arr[position - 1] > currentvalue:arr[position - 1] < currentvalue)) {
            arr[position] = arr[position - 1];
            position = position - 1;
        }
        arr[position] = currentvalue;

    }
        std::cout<<std::endl<<"Elements After Sorting are : "<<std::endl;
        printarray(arr,size);
    }

    
    
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
        
        
        /*
         This Method Takes in 2 parameters i.e From and Till
         these are indexes of array from which element we want to move all elements to the right by 1*/
        template <typename T>
        static void movearrayelementsby1toright(T arr[],int from,int till){
            for(int i=till-1;i>=from;i--){
                arr[i+1]=arr[i];
            }
        }
        
        
    
};


#endif /* INSERTIONSORT_H */

