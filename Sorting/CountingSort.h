/* 
 * File:   CountingSort.h
 * Author: Rohan
 *
 * Created on 23 July 2021, 7:44 PM
 */

#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H
#include <cmath>


/**
 * Counting Sort is a variation of Insertion Sort.
 * Counting Sort is used to sort a collection of elements whose keys are small integer
 * values, it is an integer Sorting Algorithm .(mostly)
 * It operates by counting the number of distinct elements in the array and then 
 * performing arithmetic on determine the location of each key in output/sorted array.
 * 
 * It can be used if the variations between the keys are not significantly more than 
 * number of Inputs.
 * 
 * Time Complexity of Counting Sort is O(k+n)
 * where n= Size of Input array
 * k=Difference Between the maximum Value and Minimum Value from the array.
 * It is not an inplace sorting Technique.
 *
 * 
 */
class CountingSort{
    
public:
    /* Sort Method takes in Array of any Type T (which has <,> operator overloaded ),
     * Number of Elements of type int  and 
     * a Boolean value (True if we want the elements to be sorted in Ascending order 
     * or False if we want the elements to be sorted in Descending Order 
     * as a Paramater.
     */
    template <typename T>
    void static sort(T arr[],int size,bool order){
        std::cout<<std::endl<<"Elements Before Sorting are "<<std::endl;
        printarray(arr,size);
        
        // Step 1: Finding the maximum element
        int maximum = -1;
         maximum=getMaxElementinsidearray(arr,size);
        
        // Step 2: Initialize a count array of length = (max + 1) 
        int frequencycountarr[maximum+1];
        memset(frequencycountarr, 0, sizeof(frequencycountarr));
        
        // Step 3: Fill the count array accordingly
        getFreqcountofdistinctele(arr,size,frequencycountarr);
        
         // Step 4: Calculate cumulative frequency in Frequency Count Array
        calculateCummilativeFreq(frequencycountarr,maximum+1);
       
        // Step 5: Fix the values in the sorted array
        T sortedarr[size];
        createSortedArrusingCummilativeFreq(arr,size,frequencycountarr,sortedarr);
        if(!order){
            reversearr(sortedarr,size);
        }
        std::cout<<std::endl<<"Elements After Sorting are "<<std::endl;
        printarray(sortedarr,size);
        
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
        /*Return the maximum Element from the array*/
        template <typename T>
        static int getMaxElementinsidearray(T arr[],int size){
            int max = arr[0];
            for(int i=0;i<size;i++){
                if(max<arr[i]){
                    max=arr[i];
                }
            }
            return max;
        }
        
        
        /*This Method modifies freq array with frequency of  Distinct elements at the distinct positions(index in freq array)*/
        template <typename T>
        static void getFreqcountofdistinctele(T arr[],int size_of_original_array,T freq[]){
            for(int i=0;i<size_of_original_array;i++ ){
                freq[arr[i]]++;
            }
        }
        
        /*
         This Method calculates the cummilative Frequency of the supplied array.
         * formula=cummilative Frequency of current Element + starting position of last element
         */
        template <typename T>
        static void calculateCummilativeFreq (T arr[],int size){
            for(int i=1;i<size;i++){
                arr[i]=arr[i]+arr[i-1];
            }
        }
        
        /**
         * This Method Places the elements according to their sorted position.
         * @param original_array
         * @param size_of_original_array
         * @param cummulative_arr
         * @param sorted_arr
         */
        template <typename T>
        static void createSortedArrusingCummilativeFreq(T original_array[],int size_of_original_array,
        T cummulative_arr[],T sorted_arr[]){
            for(int i=0;i<size_of_original_array;i++){
                sorted_arr[cummulative_arr[original_array[i]]-1] = original_array[i];
                cummulative_arr[original_array[i]]--;
            }
            
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


#endif /* COUNTINGSORT_H */

