/* 
 * File:   QuickSort.h
 * Author: Rohan
 *
 * Created on 25 July 2021, 1:03 PM
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include<cmath>
/*Quick Sort Also Called as Partition Sort uses Divide and Conquer Strategy.
 * We Divide our Problem into 2 small Sub problems.
 * Divide:
 * Selecting the Splitting Element (Pivot).
 * Rearrange the array (sequence/list).
 * Result:
 * All elements to the left of the pivot are less than or equal to the pivot.
 * All elements to the right of the pivot are greater than or equal to the pivot.
 * Pivot is in the correct place in sorted array/list.
 * 
 * In the Code Below, we have selected the first element as the Pivot.This won't 
 * be appropriate as it could be one of smallest or largest element in the
 * list.This Will not lead to proper division of the list.
 * 
 * Pivot Selection Strategy :
 * Pivot is median of three Elements: First Element,Last Element and the element
 * which is in the middle of the list/array.
 * 
 * Ideally Pivot should be the median of all elements inside the array.But its 
 * i.e Element in the middle of Sorted array should be our pivot.But It requires 
 * the array to be sorted.So we use Pivot Selection Strategy.
 * 
 * Time Complexity : O(n^2)
 * Space Complexity : O(n) //HEre N recursive calls will take place.
 * It is not a Stable Sorting Algorithm.
 * It is a In-Place Sorting Algorithm.
 *
 * Used in case where array size is small.Performs better than merge sort in this case.
 */
class QuickSort{
    
    
public:
    /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
     * Number of Elements of type int  and 
     * a Boolean value (True if we want the elements to be sorted in Ascending order 
     * or False if we want the elements to be sorted in Descending Order 
     * as a Paramater.
     */
    template <typename T>
    void static sort(T arr[],int size,bool sorting){
        
        std::cout<<std::endl<<"Elements Before Sorting are : "<<std::endl;
        
        printarray(arr,size);
        
        quicksort(arr,lowerbound,size-1);
        
        if(!sorting){
            reversearr(arr,size);
        }
        
        std::cout<<std::endl<<"Elements After Sorting are : "<<std::endl;
        printarray(arr,size);
        
    }
        
        
    
    
    
    
    
    
private:
    const static int lowerbound =0;
        /*Print Array methods takes in Array of any Type T ,
         and No of Elements (type int) as a Parameter  */
        template <typename T>
        static void printarray(T arr[],int no_of_elements){
            std::cout<<"Elements in array are : ";
            for (int i=0;i<no_of_elements;i++){
                std::cout<<" "<< arr[i] <<" ";
            }
        }    
        
        /* Swap methods takes array of type T ,
         * pos1 is index of first element,pos2 is index of second element.
         * It swaps the 2 elements inside the array. 
         */
        template <typename T>
        static void swap(T arr[],int pos1,int pos2){
            T temp=arr[pos1];
            arr[pos1]=arr[pos2];
            arr[pos2]=temp;
        }
        
        /*It reverses the elements of the supplied array.*/
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
        
        /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
         * lowerbound of the array and upperbound of the array on which quicksort
         * is to be performed.
         * 
        */
        template <typename T>
        static void quicksort(T unsorted_arr[],int lowerbound,int upperbound){

            int pivotposition;
            int l;
            int u;
        //Step 1 : We Find the pivot for Quick Sort
        
        if(lowerbound<upperbound){
            pivotposition= lowerbound;
            l=lowerbound+1;
            u=upperbound;
            while(l<=u){
                while((unsorted_arr[pivotposition]>unsorted_arr[l])&&(l<=upperbound)){
                    l++;
                }
                while((unsorted_arr[pivotposition]<unsorted_arr[u])&&(u>=lowerbound)){
                    u--;
                }
            //if u & l have not crossed each other
                if(l<u){
                    swap(unsorted_arr,u,l);
                }
                
            }
            //if u & l have crossed each other
            swap(unsorted_arr,u,pivotposition);
            pivotposition=u;
            quicksort(unsorted_arr,lowerbound,pivotposition-1);
            quicksort(unsorted_arr,pivotposition+1,upperbound);
            
        }
        }
    
    
};

#endif /* QUICKSORT_H */

