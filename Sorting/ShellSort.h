/* 
 * File:   ShellSort.h
 * Author: Rohan
 *
 * Created on 26 July 2021, 10:22 AM
 */

#ifndef SHELLSORT_H
#define SHELLSORT_H
#include<cmath>

/*
 * Shell Sort works by comparing elements that are distant rather than adjacent
 * elements in the list or array.
 * Shellsort makes multiple passes through the list and sorts a number of equally
 * sized sets using the insertion sort.
 * It is also called as Diminishing Increment Sort.
 * 
 * Its only efficient for medium sized list.
 * Time complexity is O(n^2)
 * Fastest of all O(n^2) sorting Algorithm.
 * 5X Faster than Bubble Sort
 * 2X Faster than Insertion Sort.
 * Excellent Choice for smaller lists.
 * 
 * Its not as efficient as merge ,heap and quick Sort.
 *  
 */
class ShellSort{
    
public :
    
    template <typename T>
    void static sort(T unsorted_arr[],int size,bool sorting){
        std::cout<<std::endl<<"Elements Before Sorting are : "<<std::endl;
        printarray(unsorted_arr,size);
        
        int distance_for_comparison=getdistanceforcomparison(size);
        shellsort(unsorted_arr,size,distance_for_comparison);
        
        if(!sorting){
            reversearr(unsorted_arr,size);
        }
        
        std::cout<<std::endl<<"Elements After Sorting are : "<<std::endl;
        printarray(unsorted_arr,size);
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
    Returns the first prime Number nearer to half the size of input dataset/array.*/
 int static getdistanceforcomparison(int size){
     int half=std::ceil(size/2);
     for(int i=half;i<size;i++){
         if(checkprime(i)){
             return i;
         }
         
     }
     return half;
 }  
 /*Checks if the number is prime.
  * Returns true if the number is prime or else false */
 bool static checkprime(int number){
     bool isprime=false;
     if(number==0 || number==1){
         return true;
     }
     for(int i=2;i<number;i++){
         if((number/i)==0){
             isprime=false;
         }
     }
     return isprime;
 }
 /*Methods Takes in array of type T ,size of the array and Distance i.e From what 
  * distance the shell sort should start comparison .As it doesn't compare 
  * adjacent Elements.
  */
 template <typename T>
 void static shellsort(T a[],int size,int distance)
 {
//     while(distance>0){
//         for(int i=0; i+distance<size;i++){
//             if(arr[i] < arr[i+distance]){
//                 swapelements(arr,i,i+distance);
//             }
//         }
//         
//         distance--;
//     }
        int i = 0;
        int temp = 0;
        int shell=distance;
        /* Determine the initial size of the shell*/
       

        while (shell > 0) {
            for (i = 0; (i + shell) < size; i++) {
                if (a[i] < a[shell + i]) {
                    temp = a[i];
                    a[i] = a[shell + i];
                    a[shell + i] = temp;
                }
            }
            /* Reduce the shell size by 1 */
            shell--;
        }
        return;
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


#endif /* SHELLSORT_H */

